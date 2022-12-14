/*
 * Copyright (C) 2015 Martin Willi
 *
 * Copyright (C) secunet Security Networks AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * From RFC 7539
 */
aead_test_vector_t chacha20poly1305_1 = {
	.alg = ENCR_CHACHA20_POLY1305, .key_size = 32, .salt_size = 4,
	.len = 114, .alen = 12,
	.key	= "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f"
			  "\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f"
			  "\x07\x00\x00\x00",
	.iv		= "\x40\x41\x42\x43\x44\x45\x46\x47",
	.adata	= "\x50\x51\x52\x53\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7",
	.plain	= "\x4c\x61\x64\x69\x65\x73\x20\x61\x6e\x64\x20\x47\x65\x6e\x74\x6c"
			  "\x65\x6d\x65\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x63\x6c\x61\x73"
			  "\x73\x20\x6f\x66\x20\x27\x39\x39\x3a\x20\x49\x66\x20\x49\x20\x63"
			  "\x6f\x75\x6c\x64\x20\x6f\x66\x66\x65\x72\x20\x79\x6f\x75\x20\x6f"
			  "\x6e\x6c\x79\x20\x6f\x6e\x65\x20\x74\x69\x70\x20\x66\x6f\x72\x20"
			  "\x74\x68\x65\x20\x66\x75\x74\x75\x72\x65\x2c\x20\x73\x75\x6e\x73"
			  "\x63\x72\x65\x65\x6e\x20\x77\x6f\x75\x6c\x64\x20\x62\x65\x20\x69"
			  "\x74\x2e",
	.cipher	= "\xd3\x1a\x8d\x34\x64\x8e\x60\xdb\x7b\x86\xaf\xbc\x53\xef\x7e\xc2"
			  "\xa4\xad\xed\x51\x29\x6e\x08\xfe\xa9\xe2\xb5\xa7\x36\xee\x62\xd6"
			  "\x3d\xbe\xa4\x5e\x8c\xa9\x67\x12\x82\xfa\xfb\x69\xda\x92\x72\x8b"
			  "\x1a\x71\xde\x0a\x9e\x06\x0b\x29\x05\xd6\xa5\xb6\x7e\xcd\x3b\x36"
			  "\x92\xdd\xbd\x7f\x2d\x77\x8b\x8c\x98\x03\xae\xe3\x28\x09\x1b\x58"
			  "\xfa\xb3\x24\xe4\xfa\xd6\x75\x94\x55\x85\x80\x8b\x48\x31\xd7\xbc"
			  "\x3f\xf4\xde\xf0\x8e\x4b\x7a\x9d\xe5\x76\xd2\x65\x86\xce\xc6\x4b"
			  "\x61\x16\x1a\xe1\x0b\x59\x4f\x09\xe2\x6a\x7e\x90\x2e\xcb\xd0\x60"
			  "\x06\x91",
};

/**
 * Additional test vector from RFC 7539
 */
aead_test_vector_t chacha20poly1305_2 = {
	.alg = ENCR_CHACHA20_POLY1305, .key_size = 32, .salt_size = 4,
	.len = 265, .alen = 12,
	.key	= "\x1c\x92\x40\xa5\xeb\x55\xd3\x8a\xf3\x33\x88\x86\x04\xf6\xb5\xf0"
			  "\x47\x39\x17\xc1\x40\x2b\x80\x09\x9d\xca\x5c\xbc\x20\x70\x75\xc0"
			  "\x00\x00\x00\x00",
	.iv		= "\x01\x02\x03\x04\x05\x06\x07\x08",
	.adata	= "\xf3\x33\x88\x86\x00\x00\x00\x00\x00\x00\x4e\x91",
	.plain	= "\x49\x6e\x74\x65\x72\x6e\x65\x74\x2d\x44\x72\x61\x66\x74\x73\x20"
			  "\x61\x72\x65\x20\x64\x72\x61\x66\x74\x20\x64\x6f\x63\x75\x6d\x65"
			  "\x6e\x74\x73\x20\x76\x61\x6c\x69\x64\x20\x66\x6f\x72\x20\x61\x20"
			  "\x6d\x61\x78\x69\x6d\x75\x6d\x20\x6f\x66\x20\x73\x69\x78\x20\x6d"
			  "\x6f\x6e\x74\x68\x73\x20\x61\x6e\x64\x20\x6d\x61\x79\x20\x62\x65"
			  "\x20\x75\x70\x64\x61\x74\x65\x64\x2c\x20\x72\x65\x70\x6c\x61\x63"
			  "\x65\x64\x2c\x20\x6f\x72\x20\x6f\x62\x73\x6f\x6c\x65\x74\x65\x64"
			  "\x20\x62\x79\x20\x6f\x74\x68\x65\x72\x20\x64\x6f\x63\x75\x6d\x65"
			  "\x6e\x74\x73\x20\x61\x74\x20\x61\x6e\x79\x20\x74\x69\x6d\x65\x2e"
			  "\x20\x49\x74\x20\x69\x73\x20\x69\x6e\x61\x70\x70\x72\x6f\x70\x72"
			  "\x69\x61\x74\x65\x20\x74\x6f\x20\x75\x73\x65\x20\x49\x6e\x74\x65"
			  "\x72\x6e\x65\x74\x2d\x44\x72\x61\x66\x74\x73\x20\x61\x73\x20\x72"
			  "\x65\x66\x65\x72\x65\x6e\x63\x65\x20\x6d\x61\x74\x65\x72\x69\x61"
			  "\x6c\x20\x6f\x72\x20\x74\x6f\x20\x63\x69\x74\x65\x20\x74\x68\x65"
			  "\x6d\x20\x6f\x74\x68\x65\x72\x20\x74\x68\x61\x6e\x20\x61\x73\x20"
			  "\x2f\xe2\x80\x9c\x77\x6f\x72\x6b\x20\x69\x6e\x20\x70\x72\x6f\x67"
			  "\x72\x65\x73\x73\x2e\x2f\xe2\x80\x9d",
	.cipher	= "\x64\xa0\x86\x15\x75\x86\x1a\xf4\x60\xf0\x62\xc7\x9b\xe6\x43\xbd"
			  "\x5e\x80\x5c\xfd\x34\x5c\xf3\x89\xf1\x08\x67\x0a\xc7\x6c\x8c\xb2"
			  "\x4c\x6c\xfc\x18\x75\x5d\x43\xee\xa0\x9e\xe9\x4e\x38\x2d\x26\xb0"
			  "\xbd\xb7\xb7\x3c\x32\x1b\x01\x00\xd4\xf0\x3b\x7f\x35\x58\x94\xcf"
			  "\x33\x2f\x83\x0e\x71\x0b\x97\xce\x98\xc8\xa8\x4a\xbd\x0b\x94\x81"
			  "\x14\xad\x17\x6e\x00\x8d\x33\xbd\x60\xf9\x82\xb1\xff\x37\xc8\x55"
			  "\x97\x97\xa0\x6e\xf4\xf0\xef\x61\xc1\x86\x32\x4e\x2b\x35\x06\x38"
			  "\x36\x06\x90\x7b\x6a\x7c\x02\xb0\xf9\xf6\x15\x7b\x53\xc8\x67\xe4"
			  "\xb9\x16\x6c\x76\x7b\x80\x4d\x46\xa5\x9b\x52\x16\xcd\xe7\xa4\xe9"
			  "\x90\x40\xc5\xa4\x04\x33\x22\x5e\xe2\x82\xa1\xb0\xa0\x6c\x52\x3e"
			  "\xaf\x45\x34\xd7\xf8\x3f\xa1\x15\x5b\x00\x47\x71\x8c\xbc\x54\x6a"
			  "\x0d\x07\x2b\x04\xb3\x56\x4e\xea\x1b\x42\x22\x73\xf5\x48\x27\x1a"
			  "\x0b\xb2\x31\x60\x53\xfa\x76\x99\x19\x55\xeb\xd6\x31\x59\x43\x4e"
			  "\xce\xbb\x4e\x46\x6d\xae\x5a\x10\x73\xa6\x72\x76\x27\x09\x7a\x10"
			  "\x49\xe6\x17\xd9\x1d\x36\x10\x94\xfa\x68\xf0\xff\x77\x98\x71\x30"
			  "\x30\x5b\xea\xba\x2e\xda\x04\xdf\x99\x7b\x71\x4d\x6c\x6f\x2c\x29"
			  "\xa6\xad\x5c\xb4\x02\x2b\x02\x70\x9b\xee\xad\x9d\x67\x89\x0c\xbb"
			  "\x22\x39\x23\x36\xfe\xa1\x85\x1f\x38",
};

/**
 * ESP example from RFC 7634
 */
aead_test_vector_t chacha20poly1305_3 = {
	.alg = ENCR_CHACHA20_POLY1305, .key_size = 32, .salt_size = 4,
	.len = 88, .alen = 8,
	.key	= "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f"
			  "\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f"
			  "\xa0\xa1\xa2\xa3",
	.iv		= "\x10\x11\x12\x13\x14\x15\x16\x17",
	.adata	= "\x01\x02\x03\x04\x00\x00\x00\x05",
	.plain	= "\x45\x00\x00\x54\xa6\xf2\x00\x00\x40\x01\xe7\x78\xc6\x33\x64\x05"
			  "\xc0\x00\x02\x05\x08\x00\x5b\x7a\x3a\x08\x00\x00\x55\x3b\xec\x10"
			  "\x00\x07\x36\x27\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13"
			  "\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x20\x21\x22\x23"
			  "\x24\x25\x26\x27\x28\x29\x2a\x2b\x2c\x2d\x2e\x2f\x30\x31\x32\x33"
			  "\x34\x35\x36\x37\x01\x02\x02\x04",
	.cipher	= "\x24\x03\x94\x28\xb9\x7f\x41\x7e\x3c\x13\x75\x3a\x4f\x05\x08\x7b"
			  "\x67\xc3\x52\xe6\xa7\xfa\xb1\xb9\x82\xd4\x66\xef\x40\x7a\xe5\xc6"
			  "\x14\xee\x80\x99\xd5\x28\x44\xeb\x61\xaa\x95\xdf\xab\x4c\x02\xf7"
			  "\x2a\xa7\x1e\x7c\x4c\x4f\x64\xc9\xbe\xfe\x2f\xac\xc6\x38\xe8\xf3"
			  "\xcb\xec\x16\x3f\xac\x46\x9b\x50\x27\x73\xf6\xfb\x94\xe6\x64\xda"
			  "\x91\x65\xb8\x28\x29\xf6\x41\xe0\x76\xaa\xa8\x26\x6b\x7f\xb0\xf7"
			  "\xb1\x1b\x36\x99\x07\xe1\xad\x43",
};

/**
 * IKEv2 example from RFC 7634
 */
aead_test_vector_t chacha20poly1305_4 = {
	.alg = ENCR_CHACHA20_POLY1305, .key_size = 32, .salt_size = 4,
	.len = 13, .alen = 32,
	.key	= "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f"
			  "\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f"
			  "\xa0\xa1\xa2\xa3",
	.iv		= "\x10\x11\x12\x13\x14\x15\x16\x17",
	.adata	= "\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7"
			  "\x2e\x20\x25\x00\x00\x00\x00\x09\x00\x00\x00\x45\x29\x00\x00\x29",
	.plain	= "\x00\x00\x00\x0c\x00\x00\x40\x01\x00\x00\x00\x0a\x00",
	.cipher	= "\x61\x03\x94\x70\x1f\x8d\x01\x7f\x7c\x12\x92\x48\x89\x6b\x71\xbf"
			  "\xe2\x52\x36\xef\xd7\xcd\xc6\x70\x66\x90\x63\x15\xb2",
};
