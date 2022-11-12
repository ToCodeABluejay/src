/* $OpenBSD: pkcs7.h,v 1.1 2022/11/12 12:11:14 beck Exp $ */
/*
 * Copyright (c) 2022 Bob Beck <beck@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LIBCRYPTO_PKCS7_H
#define _LIBCRYPTO_PKCS7_H

#include_next <openssl/pkcs7.h>
#include "crypto_namespace.h"

LCRYPTO_USED(PKCS7_ISSUER_AND_SERIAL_new);
LCRYPTO_USED(PKCS7_ISSUER_AND_SERIAL_free);
LCRYPTO_USED(d2i_PKCS7_ISSUER_AND_SERIAL);
LCRYPTO_USED(i2d_PKCS7_ISSUER_AND_SERIAL);
LCRYPTO_USED(PKCS7_ISSUER_AND_SERIAL_digest);
LCRYPTO_USED(d2i_PKCS7_fp);
LCRYPTO_USED(i2d_PKCS7_fp);
LCRYPTO_USED(PKCS7_dup);
LCRYPTO_USED(d2i_PKCS7_bio);
LCRYPTO_USED(i2d_PKCS7_bio);
LCRYPTO_USED(i2d_PKCS7_bio_stream);
LCRYPTO_USED(PEM_write_bio_PKCS7_stream);
LCRYPTO_USED(PKCS7_SIGNER_INFO_new);
LCRYPTO_USED(PKCS7_SIGNER_INFO_free);
LCRYPTO_USED(d2i_PKCS7_SIGNER_INFO);
LCRYPTO_USED(i2d_PKCS7_SIGNER_INFO);
LCRYPTO_USED(PKCS7_RECIP_INFO_new);
LCRYPTO_USED(PKCS7_RECIP_INFO_free);
LCRYPTO_USED(d2i_PKCS7_RECIP_INFO);
LCRYPTO_USED(i2d_PKCS7_RECIP_INFO);
LCRYPTO_USED(PKCS7_SIGNED_new);
LCRYPTO_USED(PKCS7_SIGNED_free);
LCRYPTO_USED(d2i_PKCS7_SIGNED);
LCRYPTO_USED(i2d_PKCS7_SIGNED);
LCRYPTO_USED(PKCS7_ENC_CONTENT_new);
LCRYPTO_USED(PKCS7_ENC_CONTENT_free);
LCRYPTO_USED(d2i_PKCS7_ENC_CONTENT);
LCRYPTO_USED(i2d_PKCS7_ENC_CONTENT);
LCRYPTO_USED(PKCS7_ENVELOPE_new);
LCRYPTO_USED(PKCS7_ENVELOPE_free);
LCRYPTO_USED(d2i_PKCS7_ENVELOPE);
LCRYPTO_USED(i2d_PKCS7_ENVELOPE);
LCRYPTO_USED(PKCS7_SIGN_ENVELOPE_new);
LCRYPTO_USED(PKCS7_SIGN_ENVELOPE_free);
LCRYPTO_USED(d2i_PKCS7_SIGN_ENVELOPE);
LCRYPTO_USED(i2d_PKCS7_SIGN_ENVELOPE);
LCRYPTO_USED(PKCS7_DIGEST_new);
LCRYPTO_USED(PKCS7_DIGEST_free);
LCRYPTO_USED(d2i_PKCS7_DIGEST);
LCRYPTO_USED(i2d_PKCS7_DIGEST);
LCRYPTO_USED(PKCS7_ENCRYPT_new);
LCRYPTO_USED(PKCS7_ENCRYPT_free);
LCRYPTO_USED(d2i_PKCS7_ENCRYPT);
LCRYPTO_USED(i2d_PKCS7_ENCRYPT);
LCRYPTO_USED(PKCS7_new);
LCRYPTO_USED(PKCS7_free);
LCRYPTO_USED(d2i_PKCS7);
LCRYPTO_USED(i2d_PKCS7);
LCRYPTO_USED(i2d_PKCS7_NDEF);
LCRYPTO_USED(PKCS7_print_ctx);
LCRYPTO_USED(PKCS7_ctrl);
LCRYPTO_USED(PKCS7_set_type);
LCRYPTO_USED(PKCS7_set0_type_other);
LCRYPTO_USED(PKCS7_set_content);
LCRYPTO_USED(PKCS7_SIGNER_INFO_set);
LCRYPTO_USED(PKCS7_SIGNER_INFO_sign);
LCRYPTO_USED(PKCS7_add_signer);
LCRYPTO_USED(PKCS7_add_certificate);
LCRYPTO_USED(PKCS7_add_crl);
LCRYPTO_USED(PKCS7_content_new);
LCRYPTO_USED(PKCS7_dataVerify);
LCRYPTO_USED(PKCS7_signatureVerify);
LCRYPTO_USED(PKCS7_dataInit);
LCRYPTO_USED(PKCS7_dataFinal);
LCRYPTO_USED(PKCS7_dataDecode);
LCRYPTO_USED(PKCS7_add_signature);
LCRYPTO_USED(PKCS7_cert_from_signer_info);
LCRYPTO_USED(PKCS7_set_digest);
LCRYPTO_USED(PKCS7_get_signer_info);
LCRYPTO_USED(PKCS7_add_recipient);
LCRYPTO_USED(PKCS7_SIGNER_INFO_get0_algs);
LCRYPTO_USED(PKCS7_RECIP_INFO_get0_alg);
LCRYPTO_USED(PKCS7_add_recipient_info);
LCRYPTO_USED(PKCS7_RECIP_INFO_set);
LCRYPTO_USED(PKCS7_set_cipher);
LCRYPTO_USED(PKCS7_stream);
LCRYPTO_USED(PKCS7_get_issuer_and_serial);
LCRYPTO_USED(PKCS7_digest_from_attributes);
LCRYPTO_USED(PKCS7_add_signed_attribute);
LCRYPTO_USED(PKCS7_add_attribute);
LCRYPTO_USED(PKCS7_get_attribute);
LCRYPTO_USED(PKCS7_get_signed_attribute);
LCRYPTO_USED(PKCS7_set_signed_attributes);
LCRYPTO_USED(PKCS7_set_attributes);
LCRYPTO_USED(PKCS7_sign);
LCRYPTO_USED(PKCS7_sign_add_signer);
LCRYPTO_USED(PKCS7_final);
LCRYPTO_USED(PKCS7_verify);
LCRYPTO_USED(PKCS7_get0_signers);
LCRYPTO_USED(PKCS7_encrypt);
LCRYPTO_USED(PKCS7_decrypt);
LCRYPTO_USED(PKCS7_add_attrib_smimecap);
LCRYPTO_USED(PKCS7_get_smimecap);
LCRYPTO_USED(PKCS7_simple_smimecap);
LCRYPTO_USED(PKCS7_add_attrib_content_type);
LCRYPTO_USED(PKCS7_add0_attrib_signing_time);
LCRYPTO_USED(PKCS7_add1_attrib_digest);
LCRYPTO_USED(SMIME_write_PKCS7);
LCRYPTO_USED(SMIME_read_PKCS7);
LCRYPTO_USED(BIO_new_PKCS7);
LCRYPTO_USED(ERR_load_PKCS7_strings);

#endif /* _LIBCRYPTO_PKCS7_H */
