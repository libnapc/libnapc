#include <module/dns/_private/_dns.h>

bool PV_libnapc_DNS_parseAnswerSection(
	libnapc__DNSAnswer *out,
	libnapc__Reader *reader
) {
	// Read name
	int name_length = PV_libnapc_DNS_dn_expand(
		// start of buffer
		reader->data,
		// end of buffer
		libnapc_Reader_getEndAddress(reader),
		// pointer to compressed domain name
		libnapc_Reader_getCurrentAddress(reader),
		PV_libnapc_DNS_tmp_name,
		sizeof(PV_libnapc_DNS_tmp_name)
	);

	if (0 >= name_length) {
		return false;
	}

	// Advance reader by name_length bytes
	if (!libnapc_Reader_readU8Array(reader, name_length, NULL)) {
		return false;
	}

	libnapc_u16 qtype = 0;

	// QTYPE
	if (!libnapc_Reader_readU16BE(reader, &qtype)) return false;
	// QCLASS
	if (!libnapc_Reader_readU16BE(reader, NULL)) return false;

	libnapc_u32 ttl = 0;
	libnapc_u16 rd_length = 0;

	// TTL
	if (!libnapc_Reader_readU32BE(reader, &ttl)) return false;
	// RD-Length
	if (!libnapc_Reader_readU16BE(reader, &rd_length)) return false;

	// Reject rd_length > 16
	if (rd_length > sizeof(out->rd_data)) {
		PV_NAPC_DNS_ERROR(
			"RD-Data (length=%d) is larger than %d bytes.",
			rd_length,
			(int)sizeof(out->rd_data)
		);

		return false;
	}

	libnapc_u8 rd_data[sizeof(out->rd_data)];

	if (!libnapc_Reader_readU8Array(reader, rd_length, rd_data)) return false;

	if (out) {
		out->ttl = ttl;

		out->rd_length = rd_length;
		memcpy(out->rd_data, rd_data, sizeof(out->rd_data));
	}

	return true;
}
