const char *napc_version(void) {
	return "%BC_RELEASE_VERSION%";
}


const char *napc_getFullVersion(void) {
	return "%BC_BUILD_DATE% %BC_GIT_HEAD_HASH%";
}
