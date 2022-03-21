#include <napc-utils/_private/_napc-utils.h>

void napc_mzero(void *data, napc_size data_size) {
	memset(data, 0, data_size);
}
