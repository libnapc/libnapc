#include <napc-utils/_private/_napc-utils.h>

bool napc_streql(const char *str1, const char *str2) {
	return strcmp(str1, str2) == 0;
}
