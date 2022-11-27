#include <module/dns/_private/_dns.h>

bool libnapc_DNS_parseHeader(
	libnapc__DNSHeader *out,
	const void *buffer, libnapc_size buffer_size
) {
	libnapc__Reader reader;
	libnapc_Reader_init(&reader, buffer, buffer_size);

	libnapc_u16 request_identifier = 0;
	libnapc_u16 flags = 0;
	libnapc_u16 question_count = 0;
	libnapc_u16 answer_count = 0;

	// Read request identifier
	if (!libnapc_Reader_readU16BE(&reader, &request_identifier)) return false;
	// Read flags (16bit)
	if (!libnapc_Reader_readU16BE(&reader, &flags)) return false;
	// Read question count
	if (!libnapc_Reader_readU16BE(&reader, &question_count)) return false;
	// Read answer count
	if (!libnapc_Reader_readU16BE(&reader, &answer_count)) return false;

	// Next two 16 bit fields
	// (Authority count, Additional count)
	// are irrelevant for our purposes
	if (!libnapc_Reader_readU16BE(&reader, NULL)) return false;
	if (!libnapc_Reader_readU16BE(&reader, NULL)) return false;

	if (out) {
		out->raw_flags            = flags;
		out->opcode               = (flags & LIBNAPC_U16_LITERAL(0x7800)) >> 11u;

		out->authoritative_answer = !!(flags & LIBNAPC_U16_LITERAL(0x0400));
		out->truncated            = !!(flags & LIBNAPC_U16_LITERAL(0x0200));
//		out->recursion_desired    = 0;
//		out->recursion_available  = 0;
		out->response_code        = flags & LIBNAPC_U16_LITERAL(0x000F);

		out->answer_count         = answer_count;
		out->question_count       = question_count;
		out->request_identifier   = request_identifier;
	}

	return true;
}
