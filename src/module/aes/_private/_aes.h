#if !defined(PV_LIBNAPC_MODULE_AES_h)
	#define PV_LIBNAPC_MODULE_AES_h

	#include <module/aes/aes.h>
	#include <libnapc-magic/libnapc-magic.h>

	#include <module/aes/_private/_tinyaes.h>
	#include <libnapc-panic/libnapc-panic.h> // LIBNAPC_PANIC()
	#include <libnapc-utils/libnapc-utils.h> // libnapc_mzero()
	#include <module/parser/parser.h> // libnapc_parser__parseHexString()

#endif
