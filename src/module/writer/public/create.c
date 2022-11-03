#include <module/writer/_private/_writer.h>

napc__Writer napc_Writer_create(void *data, napc_size data_size, napc__WriterMode mode) {
	napc__Writer writer;

	napc_Writer_init(&writer, data, data_size, mode);

	return writer;
}
