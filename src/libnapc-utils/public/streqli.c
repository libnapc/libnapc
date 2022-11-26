#include <libnapc-utils/_private/_libnapc-utils.h>

bool libnapc_streqli(const char *str1, const char *str2) {
	return strcasecmp(str1, str2) == 0;
}
