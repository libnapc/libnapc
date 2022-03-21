#if !defined(PV_NAPC_HW_MODULE_FILE_h)
	#define PV_NAPC_HW_MODULE_FILE_h

	#include <hw.module/file/file.h>
	#include <hw.module/file/_private/_log.h>
	#include <hw.module/file/HAL/HAL.h>

	#include <module/pool/pool.h> // napc_pool_
	#include <napc-utils/napc-utils.h> // napc_streql()
	#include <napc-panic/napc-panic.h>

	extern bool PV_napc_fs_initialized; // @global
	extern napc__Pool PV_napc_fs_handles_pool; // @global
#endif
