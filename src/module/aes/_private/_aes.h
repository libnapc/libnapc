#if !defined(PV_NAPC_MODULE_AES_h)
	#define PV_NAPC_MODULE_AES_h

	#include <module/aes/aes.h>
	#include <libnapc-magic/libnapc-magic.h>

	#include <module/aes/_private/_tinyaes.h>
	#include <libnapc-utils/libnapc-utils.h> // libnapc_mzero()
	#include <module/parser/parser.h> // napc_parser__parseHexString()

#endif
