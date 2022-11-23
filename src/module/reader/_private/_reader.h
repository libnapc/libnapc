#if !defined(PV_NAPC_MODULE_READER_h)
	#define PV_NAPC_MODULE_READER_h

	#include <module/reader/reader.h>
	#include <module/reader/_private/_log.h>

	#include <napc-utils/napc-utils.h> // napc_mzero()

	bool PV_napc_Reader_checkAccess(
		napc__Reader *ctx, libnapc_size type_size, const char *type
	);
#endif
