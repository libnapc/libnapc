#include <module/writer/_private/_writer.h>

napc__Writer napc_Writer_create(void *data, libnapc_size data_size) {
	napc__Writer writer;

	napc_Writer_init(&writer, data, data_size);

	return writer;
}
