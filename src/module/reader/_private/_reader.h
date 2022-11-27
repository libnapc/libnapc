#if !defined(PV_LIBNAPC_MODULE_READER_h)
	#define PV_LIBNAPC_MODULE_READER_h

	#include <module/reader/reader.h>
	#include <module/reader/_private/_log.h>

	#include <libnapc-utils/libnapc-utils.h> // libnapc_mzero()

	bool PV_libnapc_Reader_checkAccess(
		libnapc__Reader *ctx, libnapc_size type_size, const char *type
	);
#endif
