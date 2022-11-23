#include <module/dns/_private/_dns.h>

bool napc_DNS_parseHeader(
	napc__DNSHeader *out,
	const void *buffer, libnapc_size buffer_size
) {
	napc__Reader reader;
	napc_Reader_init(&reader, buffer, buffer_size);

	libnapc_u16 request_identifier = 0;
	libnapc_u16 flags = 0;
	libnapc_u16 question_count = 0;
	libnapc_u16 answer_count = 0;

	// Read request identifier
	if (!napc_Reader_readU16BE(&reader, &request_identifier)) return false;
	// Read flags (16bit)
	if (!napc_Reader_readU16BE(&reader, &flags)) return false;
	// Read question count
	if (!napc_Reader_readU16BE(&reader, &question_count)) return false;
	// Read answer count
	if (!napc_Reader_readU16BE(&reader, &answer_count)) return false;

	// Next two 16 bit fields
	// (Authority count, Additional count)
	// are irrelevant for our purposes
	if (!napc_Reader_readU16BE(&reader, NULL)) return false;
	if (!napc_Reader_readU16BE(&reader, NULL)) return false;

	if (out) {
		out->raw_flags            = flags;
		out->opcode               = (flags & NAPC_U16_LITERAL(0x7800)) >> 11u;

		out->authoritative_answer = !!(flags & NAPC_U16_LITERAL(0x0400));
		out->truncated            = !!(flags & NAPC_U16_LITERAL(0x0200));
//		out->recursion_desired    = 0;
//		out->recursion_available  = 0;
		out->response_code        = flags & NAPC_U16_LITERAL(0x000F);

		out->answer_count         = answer_count;
		out->question_count       = question_count;
		out->request_identifier   = request_identifier;
	}

	return true;
}
