#include <napc-utils/_private/_napc-utils.h>

bool libnapc_streql(const char *str1, const char *str2) {
	return strcmp(str1, str2) == 0;
}
