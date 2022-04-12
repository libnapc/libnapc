#include <module/nf-writer/_private/_nf-writer.h>

napc__NFWriter napc_NFWriter_create(void *data, napc_size data_size) {
	napc__NFWriter writer;

	napc_NFWriter_init(&writer, data, data_size);

	return writer;
}
