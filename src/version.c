#include <libnapc-internal.h>

const char *libnapc_version(void) {
	#if defined(LIBNAPC_DEBUG)
		return "%BC_RELEASE_VERSION%-debug";
	#else
		return "%BC_RELEASE_VERSION%";
	#endif
}

const char *libnapc_getFullVersion(void) {
	#if defined(LIBNAPC_DEBUG)
		return "%BC_RELEASE_VERSION% (git commit '%BC_GIT_HEAD_HASH%', with debug enabled)";
	#else
		return "%BC_RELEASE_VERSION% (git commit '%BC_GIT_HEAD_HASH%')";
	#endif
}
