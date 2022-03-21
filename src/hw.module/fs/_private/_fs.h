#if !defined(PV_NAPC_HW_MODULE_FS_h)
	#define PV_NAPC_HW_MODULE_FS_h

	#include <hw.module/fs/fs.h>
	#include <hw.module/fs/_private/_log.h>

	#include <hw.module/file/file.h>
	#include <module/misc/misc.h>
	#include <napc-magic/napc-magic.h>
	#include <napc-utils/napc-utils.h>

	napc_ssize PV_nap_fs_readFileChunk(
		const void *data, napc_size data_size, void *context
	);

	napc_ssize PV_nap_fs_writeFileChunk(
		const void *data, napc_size data_size, void *context
	);
#endif
