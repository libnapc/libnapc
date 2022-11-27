#include <module/writer/_private/_writer.h>

libnapc__Writer libnapc_Writer_create(void *data, libnapc_size data_size) {
	libnapc__Writer writer;

	libnapc_Writer_init(&writer, data, data_size);

	return writer;
}
