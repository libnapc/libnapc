#if !defined(PV_LIBNAPC_MODULE_WRITER_h)
	#define PV_LIBNAPC_MODULE_WRITER_h

	#include <module/writer/writer.h>
	#include <module/writer/_private/_log.h>

	#include <libnapc-utils/libnapc-utils.h>

	bool PV_libnapc_Writer_checkAccess(
		libnapc__Writer *ctx, libnapc_size type_size, const char *type
	);
#endif
