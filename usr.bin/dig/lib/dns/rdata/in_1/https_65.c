/*
 * Copyright (C) 2022 Florian Obser <florian@openbsd.org>
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

/* $Id: https_65.c,v 1.1 2022/07/03 12:07:52 florian Exp $ */

/* draft-ietf-dnsop-svcb-https-10 */

#ifndef RDATA_IN_1_HTTPS_65_C
#define RDATA_IN_1_HTTPS_65_C

static inline isc_result_t
totext_in_https(ARGS_TOTEXT) {
	REQUIRE(rdata->type == dns_rdatatype_https);
	REQUIRE(rdata->rdclass == dns_rdataclass_in);
	REQUIRE(rdata->length != 0);

	return (totext_in_svcb_https(rdata, tctx, target));
}

static inline isc_result_t
fromwire_in_https(ARGS_FROMWIRE) {
	REQUIRE(type == dns_rdatatype_https);
	REQUIRE(rdclass == dns_rdataclass_in);
	return (fromwire_in_svcb_https(rdclass, type, source, dctx, options,
	    target));
}

static inline isc_result_t
towire_in_https(ARGS_TOWIRE) {
	REQUIRE(rdata->type == dns_rdatatype_https);
	REQUIRE(rdata->length != 0);

	return (towire_in_svcb_https(rdata, cctx, target));
}


#endif	/* RDATA_IN_1_HTTPS_65_C */
