const char *libnapc_version(void) {
	return "%BC_RELEASE_VERSION%";
}


const char *napc_getFullVersion(void) {
	return "%BC_RELEASE_VERSION% (git commit '%BC_GIT_HEAD_HASH%')";
}
