/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* $Id: socket.h,v 1.8 2022/12/26 19:24:11 jmc Exp $ */

#ifndef ISC_SOCKET_H
#define ISC_SOCKET_H 1

/*****
 ***** Module Info
 *****/

/*! \file isc/socket.h
 * \brief Provides TCP and UDP sockets for network I/O.  The sockets are event
 * sources in the task system.
 *
 * When I/O completes, a completion event for the socket is posted to the
 * event queue of the task which requested the I/O.
 *
 * \li MP:
 *	The module ensures appropriate synchronization of data structures it
 *	creates and manipulates.
 *	Clients of this module must not be holding a socket's task's lock when
 *	making a call that affects that socket.  Failure to follow this rule
 *	can result in deadlock.
 *	The caller must ensure that isc_socketmgr_destroy() is called only
 *	once for a given manager.
 *
 * \li Reliability:
 *	No anticipated impact.
 *
 * \li Resources:
 *	TBS
 *
 * \li Security:
 *	No anticipated impact.
 *
 * \li Standards:
 *	None.
 */

/***
 *** Imports
 ***/

#include <time.h>

#include <isc/event.h>
#include <isc/eventclass.h>

#include <isc/region.h>
#include <isc/sockaddr.h>
#include <isc/types.h>

/***
 *** Constants
 ***/

/*%
 * Maximum number of buffers in a scatter/gather read/write.  The operating
 * system in use must support at least this number (plus one on some.)
 */
#define ISC_SOCKET_MAXSCATTERGATHER	8

/*%
 * In isc_socket_bind() set socket option SO_REUSEADDR prior to calling
 * bind() if a non zero port is specified (AF_INET and AF_INET6).
 */
#define ISC_SOCKET_REUSEADDRESS		0x01U

/***
 *** Types
 ***/

struct isc_socketevent {
	ISC_EVENT_COMMON(isc_socketevent_t);
	isc_result_t		result;		/*%< OK, EOF, whatever else */
	unsigned int		minimum;	/*%< minimum i/o for event */
	unsigned int		n;		/*%< bytes read or written */
	unsigned int		offset;		/*%< offset into buffer list */
	isc_region_t		region;		/*%< for single-buffer i/o */
	isc_bufferlist_t	bufferlist;	/*%< list of buffers */
	struct sockaddr_storage		address;	/*%< source address */
	struct timespec		timestamp;	/*%< timestamp of packet recv */
	struct in6_pktinfo	pktinfo;	/*%< ipv6 pktinfo */
	uint32_t		attributes;	/*%< see below */
	isc_eventdestructor_t   destroy;	/*%< original destructor */
	unsigned int		dscp;		/*%< UDP dscp value */
};

typedef struct isc_socket_newconnev isc_socket_newconnev_t;
struct isc_socket_newconnev {
	ISC_EVENT_COMMON(isc_socket_newconnev_t);
	isc_socket_t *		newsocket;
	isc_result_t		result;		/*%< OK, EOF, whatever else */
	struct sockaddr_storage		address;	/*%< source address */
};

typedef struct isc_socket_connev isc_socket_connev_t;
struct isc_socket_connev {
	ISC_EVENT_COMMON(isc_socket_connev_t);
	isc_result_t		result;		/*%< OK, EOF, whatever else */
};

/*@{*/
/*!
 * _ATTACHED:	Internal use only.
 * _TRUNC:	Packet was truncated on receive.
 * _CTRUNC:	Packet control information was truncated.  This can
 *		indicate that the packet is not complete, even though
 *		all the data is valid.
 * _TIMESTAMP:	The timestamp member is valid.
 * _PKTINFO:	The pktinfo member is valid.
 * _MULTICAST:	The UDP packet was received via a multicast transmission.
 * _DSCP:	The UDP DSCP value is valid.
 * _USEMINMTU:	Set the per packet IPV6_USE_MIN_MTU flag.
 */
#define ISC_SOCKEVENTATTR_ATTACHED		0x80000000U /* internal */
#define ISC_SOCKEVENTATTR_TRUNC			0x00800000U /* public */
#define ISC_SOCKEVENTATTR_CTRUNC		0x00400000U /* public */
#define ISC_SOCKEVENTATTR_TIMESTAMP		0x00200000U /* public */
#define ISC_SOCKEVENTATTR_PKTINFO		0x00100000U /* public */
#define ISC_SOCKEVENTATTR_MULTICAST		0x00080000U /* public */
#define ISC_SOCKEVENTATTR_DSCP			0x00040000U /* public */
#define ISC_SOCKEVENTATTR_USEMINMTU		0x00020000U /* public */
/*@}*/

#define ISC_SOCKEVENT_ANYEVENT  (0)
#define ISC_SOCKEVENT_RECVDONE	(ISC_EVENTCLASS_SOCKET + 1)
#define ISC_SOCKEVENT_SENDDONE	(ISC_EVENTCLASS_SOCKET + 2)
#define ISC_SOCKEVENT_NEWCONN	(ISC_EVENTCLASS_SOCKET + 3)
#define ISC_SOCKEVENT_CONNECT	(ISC_EVENTCLASS_SOCKET + 4)

/*
 * Internal events.
 */
#define ISC_SOCKEVENT_INTR	(ISC_EVENTCLASS_SOCKET + 256)
#define ISC_SOCKEVENT_INTW	(ISC_EVENTCLASS_SOCKET + 257)

typedef enum {
	isc_sockettype_udp = 1,
	isc_sockettype_tcp = 2,
} isc_sockettype_t;

/*@{*/
/*!
 * How a socket should be shutdown in isc_socket_shutdown() calls.
 */
#define ISC_SOCKSHUT_RECV	0x00000001	/*%< close read side */
#define ISC_SOCKSHUT_SEND	0x00000002	/*%< close write side */
#define ISC_SOCKSHUT_ALL	0x00000003	/*%< close them all */
/*@}*/

/*@{*/
/*!
 * What I/O events to cancel in isc_socket_cancel() calls.
 */
#define ISC_SOCKCANCEL_RECV	0x00000001	/*%< cancel recv */
#define ISC_SOCKCANCEL_SEND	0x00000002	/*%< cancel send */
#define ISC_SOCKCANCEL_ACCEPT	0x00000004	/*%< cancel accept */
#define ISC_SOCKCANCEL_CONNECT	0x00000008	/*%< cancel connect */
#define ISC_SOCKCANCEL_ALL	0x0000000f	/*%< cancel everything */
/*@}*/

/*@{*/
/*!
 * Flags for isc_socket_send() and isc_socket_recv() calls.
 */
#define ISC_SOCKFLAG_IMMEDIATE	0x00000001	/*%< send event only if needed */
#define ISC_SOCKFLAG_NORETRY	0x00000002	/*%< drop failed UDP sends */
/*@}*/

/*@{*/
/*!
 * Flags for fdwatchcreate.
 */
#define ISC_SOCKFDWATCH_READ	0x00000001	/*%< watch for readable */
#define ISC_SOCKFDWATCH_WRITE	0x00000002	/*%< watch for writable */
/*@}*/

/***
 *** Socket and Socket Manager Functions
 ***
 *** Note: all Ensures conditions apply only if the result is success for
 *** those functions which return an isc_result.
 ***/

isc_result_t
isc_socket_create(isc_socketmgr_t *manager,
		  int pf,
		  isc_sockettype_t type,
		  isc_socket_t **socketp);
/*%<
 * Create a new 'type' socket managed by 'manager'.
 *
 * For isc_sockettype_fdwatch sockets you should use isc_socket_fdwatchcreate()
 * rather than isc_socket_create().
 *
 * Note:
 *
 *\li	'pf' is the desired protocol family, e.g. PF_INET or PF_INET6.
 *
 * Requires:
 *
 *\li	'manager' is a valid manager
 *
 *\li	'socketp' is a valid pointer, and *socketp == NULL
 *
 *\li	'type' is not isc_sockettype_fdwatch
 *
 * Ensures:
 *
 *	'*socketp' is attached to the newly created socket
 *
 * Returns:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_NOMEMORY
 *\li	#ISC_R_NORESOURCES
 *\li	#ISC_R_UNEXPECTED
 */

void
isc_socket_cancel(isc_socket_t *sock, isc_task_t *task,
		  unsigned int how);
/*%<
 * Cancel pending I/O of the type specified by "how".
 *
 * Note: if "task" is NULL, then the cancel applies to all tasks using the
 * socket.
 *
 * Requires:
 *
 * \li	"socket" is a valid socket
 *
 * \li	"task" is NULL or a valid task
 *
 * "how" is a bitmask describing the type of cancellation to perform.
 * The type ISC_SOCKCANCEL_ALL will cancel all pending I/O on this
 * socket.
 *
 * \li ISC_SOCKCANCEL_RECV:
 *	Cancel pending isc_socket_recv() calls.
 *
 * \li ISC_SOCKCANCEL_SEND:
 *	Cancel pending isc_socket_send() and isc_socket_sendto() calls.
 *
 * \li ISC_SOCKCANCEL_ACCEPT:
 *	Cancel pending isc_socket_accept() calls.
 *
 * \li ISC_SOCKCANCEL_CONNECT:
 *	Cancel pending isc_socket_connect() call.
 */

void
isc_socket_attach(isc_socket_t *sock, isc_socket_t **socketp);
/*%<
 * Attach *socketp to socket.
 *
 * Requires:
 *
 * \li	'socket' is a valid socket.
 *
 * \li	'socketp' points to a NULL socket.
 *
 * Ensures:
 *
 * \li	*socketp is attached to socket.
 */

void
isc_socket_detach(isc_socket_t **socketp);
/*%<
 * Detach *socketp from its socket.
 *
 * Requires:
 *
 * \li	'socketp' points to a valid socket.
 *
 * \li	If '*socketp' is the last reference to the socket,
 *	then:
 *
 *		There must be no pending I/O requests.
 *
 * Ensures:
 *
 * \li	*socketp is NULL.
 *
 * \li	If '*socketp' is the last reference to the socket,
 *	then:
 *
 *		The socket will be shutdown (both reading and writing)
 *		for all tasks.
 *
 *		All resources used by the socket have been freed
 */

isc_result_t
isc_socket_bind(isc_socket_t *sock, struct sockaddr_storage *addressp,
		unsigned int options);
/*%<
 * Bind 'socket' to '*addressp'.
 *
 * Requires:
 *
 * \li	'socket' is a valid socket
 *
 * \li	'addressp' points to a valid isc_sockaddr.
 *
 * Returns:
 *
 * \li	ISC_R_SUCCESS
 * \li	ISC_R_NOPERM
 * \li	ISC_R_ADDRNOTAVAIL
 * \li	ISC_R_ADDRINUSE
 * \li	ISC_R_BOUND
 * \li	ISC_R_UNEXPECTED
 */

isc_result_t
isc_socket_connect(isc_socket_t *sock, struct sockaddr_storage *addressp,
		   isc_task_t *task, isc_taskaction_t action,
		   void *arg);
/*%<
 * Connect 'socket' to peer with address *saddr.  When the connection
 * succeeds, or when an error occurs, a CONNECT event with action 'action'
 * and arg 'arg' will be posted to the event queue for 'task'.
 *
 * Requires:
 *
 * \li	'socket' is a valid TCP socket
 *
 * \li	'addressp' points to a valid isc_sockaddr
 *
 * \li	'task' is a valid task
 *
 * \li	'action' is a valid action
 *
 * Returns:
 *
 * \li	ISC_R_SUCCESS
 * \li	ISC_R_NOMEMORY
 * \li	ISC_R_UNEXPECTED
 *
 * Posted event's result code:
 *
 * \li	ISC_R_SUCCESS
 * \li	ISC_R_TIMEDOUT
 * \li	ISC_R_CONNREFUSED
 * \li	ISC_R_NETUNREACH
 * \li	ISC_R_UNEXPECTED
 */

/*@{*/
isc_result_t
isc_socket_recvv(isc_socket_t *sock, isc_bufferlist_t *buflist,
		 unsigned int minimum,
		 isc_task_t *task, isc_taskaction_t action, void *arg);
/*!
 * Receive from 'socket', storing the results in region.
 *
 * Notes:
 *
 *\li	Let 'length' refer to the length of 'region' or to the sum of all
 *	available regions in the list of buffers '*buflist'.
 *
 *\li	If 'minimum' is non-zero and at least that many bytes are read,
 *	the completion event will be posted to the task 'task.'  If minimum
 *	is zero, the exact number of bytes requested in the region must
 * 	be read for an event to be posted.  This only makes sense for TCP
 *	connections, and is always set to 1 byte for UDP.
 *
 *\li	The read will complete when the desired number of bytes have been
 *	read, if end-of-input occurs, or if an error occurs.  A read done
 *	event with the given 'action' and 'arg' will be posted to the
 *	event queue of 'task'.
 *
 *\li	The caller may not modify 'region', the buffers which are passed
 *	into this function, or any data they refer to until the completion
 *	event is received.
 *
 *\li	For isc_socket_recvv():
 *	On successful completion, '*buflist' will be empty, and the list of
 *	all buffers will be returned in the done event's 'bufferlist'
 *	member.  On error return, '*buflist' will be unchanged.
 *
 *\li	For isc_socket_recv2():
 *	'event' is not NULL, and the non-socket specific fields are
 *	expected to be initialized.
 *
 *\li	For isc_socket_recv2():
 *	The only defined value for 'flags' is ISC_SOCKFLAG_IMMEDIATE.  If
 *	set and the operation completes, the return value will be
 *	ISC_R_SUCCESS and the event will be filled in and not sent.  If the
 *	operation does not complete, the return value will be
 *	ISC_R_INPROGRESS and the event will be sent when the operation
 *	completes.
 *
 * Requires:
 *
 *\li	'socket' is a valid, bound socket.
 *
 *\li	For isc_socket_recv():
 *	'region' is a valid region
 *
 *\li	For isc_socket_recvv():
 *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.
 *
 *\li	'task' is a valid task
 *
 *\li	For isc_socket_recv() and isc_socket_recvv():
 *	action != NULL and is a valid action
 *
 *\li	For isc_socket_recv2():
 *	event != NULL
 *
 * Returns:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_INPROGRESS
 *\li	#ISC_R_NOMEMORY
 *\li	#ISC_R_UNEXPECTED
 *
 * Event results:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_UNEXPECTED
 *\li	XXX needs other net-type errors
 */
/*@}*/

/*@{*/
isc_result_t
isc_socket_sendv(isc_socket_t *sock, isc_bufferlist_t *buflist,
		 isc_task_t *task, isc_taskaction_t action, void *arg);
isc_result_t
isc_socket_sendtov2(isc_socket_t *sock, isc_bufferlist_t *buflist,
		    isc_task_t *task, isc_taskaction_t action, void *arg,
		    struct sockaddr_storage *address, struct in6_pktinfo *pktinfo,
		    unsigned int flags);
/*!
 * Send the contents of 'region' to the socket's peer.
 *
 * Notes:
 *
 *\li	Shutting down the requestor's task *may* result in any
 *	still pending writes being dropped or completed, depending on the
 *	underlying OS implementation.
 *
 *\li	If 'action' is NULL, then no completion event will be posted.
 *
 *\li	The caller may not modify 'region', the buffers which are passed
 *	into this function, or any data they refer to until the completion
 *	event is received.
 *
 *\li	For isc_socket_sendv() and isc_socket_sendtov():
 *	On successful completion, '*buflist' will be empty, and the list of
 *	all buffers will be returned in the done event's 'bufferlist'
 *	member.  On error return, '*buflist' will be unchanged.
 *
 *\li	For isc_socket_sendto2():
 *	'event' is not NULL, and the non-socket specific fields are
 *	expected to be initialized.
 *
 *\li	For isc_socket_sendto2():
 *	The only defined values for 'flags' are ISC_SOCKFLAG_IMMEDIATE
 *	and ISC_SOCKFLAG_NORETRY.
 *
 *\li	If ISC_SOCKFLAG_IMMEDIATE is set and the operation completes, the
 *	return value will be ISC_R_SUCCESS and the event will be filled
 *	in and not sent.  If the operation does not complete, the return
 *	value will be ISC_R_INPROGRESS and the event will be sent when
 *	the operation completes.
 *
 *\li	ISC_SOCKFLAG_NORETRY can only be set for UDP sockets.  If set
 *	and the send operation fails due to a transient error, the send
 *	will not be retried and the error will be indicated in the event.
 *	Using this option along with ISC_SOCKFLAG_IMMEDIATE allows the caller
 *	to specify a region that is allocated on the stack.
 *
 * Requires:
 *
 *\li	'socket' is a valid, bound socket.
 *
 *\li	For isc_socket_send():
 *	'region' is a valid region
 *
 *\li	For isc_socket_sendv() and isc_socket_sendtov():
 *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.
 *
 *\li	'task' is a valid task
 *
 *\li	For isc_socket_sendv(), isc_socket_sendtov(), isc_socket_send(), and
 *	isc_socket_sendto():
 *	action == NULL or is a valid action
 *
 *\li	For isc_socket_sendto2():
 *	event != NULL
 *
 * Returns:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_INPROGRESS
 *\li	#ISC_R_NOMEMORY
 *\li	#ISC_R_UNEXPECTED
 *
 * Event results:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_UNEXPECTED
 *\li	XXX needs other net-type errors
 */
/*@}*/

isc_result_t
isc_socketmgr_create(isc_socketmgr_t **managerp);

/*%<
 * Create a socket manager.  If "maxsocks" is non-zero, it specifies the
 * maximum number of sockets that the created manager should handle.
 *
 * Notes:
 *
 * Requires:
 *
 *\li	'managerp' points to a NULL isc_socketmgr_t.
 *
 * Ensures:
 *
 *\li	'*managerp' is a valid isc_socketmgr_t.
 *
 * Returns:
 *
 *\li	#ISC_R_SUCCESS
 *\li	#ISC_R_NOMEMORY
 *\li	#ISC_R_UNEXPECTED
 *\li	#ISC_R_NOTIMPLEMENTED
 */

void
isc_socketmgr_destroy(isc_socketmgr_t **managerp);
/*%<
 * Destroy a socket manager.
 *
 * Notes:
 *
 *\li	This routine blocks until there are no sockets left in the manager,
 *	so if the caller holds any socket references using the manager, it
 *	must detach them before calling isc_socketmgr_destroy() or it will
 *	block forever.
 *
 * Requires:
 *
 *\li	'*managerp' is a valid isc_socketmgr_t.
 *
 *\li	All sockets managed by this manager are fully detached.
 *
 * Ensures:
 *
 *\li	*managerp == NULL
 *
 *\li	All resources used by the manager have been freed.
 */

#endif /* ISC_SOCKET_H */
