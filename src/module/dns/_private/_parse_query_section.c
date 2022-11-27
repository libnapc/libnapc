#include <module/dns/_private/_dns.h>

bool PV_libnapc_DNS_parseQuerySection(
	libnapc__DNSQuery *out,
	libnapc__Reader *reader
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, reader);

	// Read question name (QNAME)
	int name_length = PV_libnapc_DNS_dn_expand(
		// start of buffer
		reader->data,
		// end of buffer
		libnapc_Reader_getEndAddress(reader),
		// pointer to ''compressed'' domain name
		libnapc_Reader_getCurrentAddress(reader),
		PV_libnapc_DNS_tmp_name,
		sizeof(PV_libnapc_DNS_tmp_name)
	);

	if (0 >= name_length) {
		PV_NAPC_DNS_ERROR("Invalid name_length %d.", name_length);

		return false;
	}

	// Advance reader by name_length bytes
	if (!libnapc_Reader_readU8Array(reader, name_length, NULL)) {
		return false;
	}

	libnapc_u16 qtype = 0;
	libnapc_u16 qclass = 0;

	// Read QType
	if (!libnapc_Reader_readU16BE(reader, &qtype)) {
		return false;
	}
	// Read QClass
	if (!libnapc_Reader_readU16BE(reader, &qclass)) {
		return false;
	}

	if (qclass != 1) {
		PV_NAPC_DNS_WARNING("Invalid QClass %d. (expected 1)", qclass);

		return false;
	}

	if (out) {
		out->qtype = qtype;
		libnapc_strncpy(out->name, PV_libnapc_DNS_tmp_name, sizeof(out->name));
	}

	return true;
}
