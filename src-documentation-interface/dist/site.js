window.napcdoc = {"lib":{},"definitions":{"napc__Pool":{"name":"napc__Pool","_associated_module":"Pool","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Represenation of a fixed memory pool."},"type":"type","kind":"opaque"},"napc__OSTimer":{"name":"napc__OSTimer","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Representation of a single shot timer."},"type":"type","kind":"opaque"},"napc__Timer":{"name":"napc__Timer","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Representation of a timer."},"type":"type","kind":"opaque"},"napc__Reader":{"name":"napc__Reader","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a reader."},"type":"type","kind":"opaque"},"napc__Writer":{"name":"napc__Writer","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a writer."},"type":"type","kind":"opaque"},"napc__NFWriter":{"name":"napc__NFWriter","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Representation of a no-fail writer."},"type":"type","kind":"opaque"},"napc__IPv4Participant":{"name":"napc__IPv4Participant","_associated_module":"IPv4Participant","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation a network device.","description":"Representation of a participant in the internet protocol version 4 (IPv4)."},"type":"type","kind":"struct","fields":[{"name":"_init_magic","type":"napc_init_magic","description":"error=2"},{"name":"addr","type":"char [64]","description":"IPv4-Address as string in format `a.b.c.d`."},{"name":"port","type":"napc_u16","description":"Port number."}]},"napc__DNSHeader":{"name":"napc__DNSHeader","_associated_module":"DNS","general_info":{"version":"2.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"},{"version":"2.0.0","date":"12.04.2022","change":"added `raw_flags` member"}],"brief":"Representation of a DNS header."},"type":"type","kind":"struct","fields":[{"name":"raw_flags","type":"napc_u16","description":"Contains the raw dns header flags (16 bit)"},{"name":"opcode","type":"napc__DNSOPCode","description":"DNS operation code. See `napc__DNSOPCode`."},{"name":"authoritative_answer","type":"bool","description":"Authoritative answer flag."},{"name":"truncated","type":"bool","description":"Truncated flag."},{"name":"request_identifier","type":"napc_u16","description":"DNS request identifier."},{"name":"response_code","type":"napc_u16","description":"DNS-Server response code."},{"name":"question_count","type":"napc_u16","description":"Number of DNS queries."},{"name":"answer_count","type":"napc_u16","description":"Number of DNS answers."}]},"napc__DNSQuery":{"name":"napc__DNSQuery","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a DNS query."},"type":"type","kind":"struct","fields":[{"name":"name","type":"char [64]","description":"Name to lookup."},{"name":"qtype","type":"napc__DNSQType","description":"Query type, see `napc__DNSQType`."}]},"napc__DNSAnswer":{"name":"napc__DNSAnswer","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a DNS answer."},"type":"type","kind":"struct","fields":[{"name":"ttl","type":"napc_u32","description":"Time to live (in seconds)."},{"name":"rd_length","type":"napc_u16","description":"Response data size in bytes."},{"name":"rd_data","type":"napc_u8 [16]","description":"Response data."}]},"napc__DNSRequest":{"name":"napc__DNSRequest","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a DNS request."},"type":"type","kind":"struct","fields":[{"name":"header","type":"napc__DNSHeader","description":"DNS-Header, see `napc__DNSHeader`."},{"name":"query","type":"napc__DNSQuery","description":"DNS-Query, see `napc__DNSQuery`."}]},"napc__DNSResponse":{"name":"napc__DNSResponse","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a DNS response."},"type":"type","kind":"struct","fields":[{"name":"header","type":"napc__DNSHeader","description":"DNS-Header, see `napc__DNSHeader`."},{"name":"num_answers","type":"napc_size","description":"Represents number of elements in `answers` array."},{"name":"answers","type":"napc__DNSAnswer [4]","description":"DNS-Answers, see `napc__DNSAnswer`."}]},"napc__Buffer":{"name":"napc__Buffer","_associated_module":"Buffer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a memory buffer."},"type":"type","kind":"struct","fields":[{"name":"_init_magic","type":"napc_init_magic","description":"error=2"},{"name":"size","type":"napc_size","description":"Size of data."},{"name":"data","type":"void *","description":"Pointer to data."}]},"napc__DNSOPCode":{"name":"napc__DNSOPCode","_associated_module":"DNS","general_info":{"version":"1.0.0","brief":"Representation of a DNS operation code."},"type":"type","kind":"enum","values":[{"name":"NAPC_DNS_OPCODE_QUERY","value":false,"description":"Standard DNS-Query."},{"name":"NAPC_DNS_OPCODE_IQUERY","value":false,"description":"Inverse DNS-Query."},{"name":"NAPC_DNS_OPCODE_STATUS","value":false,"description":"Status query."},{"name":"NAPC_DNS_OPCODE_NOTIFY","value":false,"description":""},{"name":"NAPC_DNS_OPCODE_UPDATE","value":false,"description":""}]},"napc__DNSQType":{"name":"napc__DNSQType","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"},{"version":"2.0.0","date":"14.04.2022","change":"added CNAME,MX and TXT types"}],"brief":"Representation of DNS query type."},"type":"type","kind":"enum","values":[{"name":"NAPC_DNS_QTYPE_A","value":1,"description":"A-Record query"},{"name":"NAPC_DNS_QTYPE_CNAME","value":5,"description":"CNAME-Record query"},{"name":"NAPC_DNS_QTYPE_MX","value":15,"description":"MX-Record query"},{"name":"NAPC_DNS_QTYPE_TXT","value":16,"description":"TXT-Record query"},{"name":"NAPC_DNS_QTYPE_AAAA","value":28,"description":"AAAA-Record query"}]},"napc_u8":{"name":"napc_u8","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"8 bit wide unsigned integer","description":"Type for unsigned integers with 8 bits width."},"type":"type","kind":"alias","alias_of":"uint8_t"},"napc_i8":{"name":"napc_i8","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"8 bit wide signed integer","description":"Type for signed integers with 8 bits width."},"type":"type","kind":"alias","alias_of":"int8_t"},"napc_u16":{"name":"napc_u16","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"16 bit wide unsigned integer","description":"Type for unsigned integers with 16 bits width."},"type":"type","kind":"alias","alias_of":"uint16_t"},"napc_i16":{"name":"napc_i16","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"16 bit wide signed integer","description":"Type for signed integers with 16 bits width."},"type":"type","kind":"alias","alias_of":"int16_t"},"napc_u32":{"name":"napc_u32","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"32 bit wide unsigned integer","description":"Type for unsigned integers with 32 bits width."},"type":"type","kind":"alias","alias_of":"uint32_t"},"napc_i32":{"name":"napc_i32","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"32 bit wide signed integer","description":"Type for signed integers with 32 bits width."},"type":"type","kind":"alias","alias_of":"int32_t"},"napc_size":{"name":"napc_size","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Memory size type.","description":"Unsigned integer type for holding object sizes.","rationale":"Used because Arduino lacks `ssize_t` in `<stddef.h>`.\nFor some reason it is defined in `<stdio.h>` but\nI don't want to pollute my headers with unnecessary\nincludes. Also this way, I'm sure what printf specifiers\nto use when printing `size_t` resp. `ssize_t`.\n(`%zu` is not supported in arduino's libc)"},"type":"type","kind":"alias","alias_of":"unsigned long"},"napc_ssize":{"name":"napc_ssize","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Signed memory size type.","description":"Signed integer type for holding object sizes.","rationale":"Used because Arduino lacks `ssize_t` in `<stddef.h>`.\nFor some reason it is defined in `<stdio.h>` but\nI don't want to pollute my headers with unnecessary\nincludes. Also this way, I'm sure what printf specifiers\nto use when printing `size_t` resp. `ssize_t`.\n(`%zu` is not supported in arduino's libc)"},"type":"type","kind":"alias","alias_of":"long"},"napc_time":{"name":"napc_time","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Unsigned timestamp int type.","description":"Unsigned integer type for holding timestamps."},"type":"type","kind":"alias","alias_of":"napc_u32"},"napc__UDPSocket":{"name":"napc__UDPSocket","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a UDP-Socket."},"type":"type","kind":"alias","alias_of":"napc_ssize"},"napc__File":{"name":"napc__File","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Representation of a file.","description":"Representation of a file."},"type":"type","kind":"alias","alias_of":"napc_ssize"},"napc_version":{"name":"napc_version","_associated_module":"Core","general_info":{"version":"1.2.0","changelog":[{"version":"1.2.0","date":"20.03.2022","change":"initial version"}],"brief":"Get the version of libnapc.","description":"Returns the version of the current libnapc implementation.","example":"napc_printf(\"Using libnapc version: %s\\n\", napc_version());"},"type":"fn","params":[],"return":{"type":"const char *","description":""}},"napc_getFullVersion":{"name":"napc_getFullVersion","_associated_module":"Core","general_info":{"version":"1.3.0","changelog":[{"version":"1.3.0","date":"21.03.2022","change":"initial version"}],"brief":"Get the full version of libnapc.","description":"Returns the full version of the current libnapc implementation.","example":"napc_printf(\"Using libnapc version: %s\\n\", napc_getFullVersion());"},"type":"fn","params":[],"return":{"type":"const char *","description":""}},"napc_puts":{"name":"napc_puts","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Print a string to console\/serial.","description":"Output a string via console or serial.","example":"napc_puts(\"Hello World!\");"},"type":"fn","params":[{"type":"const char *","name":"str","description":"The string to be printed."}],"return":{"type":"void","description":""}},"napc_putc":{"name":"napc_putc","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Print a character to console\/serial.","description":"Output a single character via console or serial.","example":"napc_putc('H');\nnapc_putc('e');\nnapc_putc('l');\nnapc_putc('l');\nnapc_putc('o');\nnapc_putc('!');"},"type":"fn","params":[{"type":"char","name":"ch","description":"The character to be printed."}],"return":{"type":"void","description":""}},"napc_printf":{"name":"napc_printf","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Print a printf()-like formatted string.","description":"Provides a convient way to print out information without having the need to call `snprintf()` first.","example":"int my_var = 13;\n\nnapc_printf(\"Value of my_var is %d\", my_var);"},"type":"fn","params":[{"type":"const char *","name":"fmt","description":"printf()-like format string."},{"type":"...","name":"...","description":"Values to incorporate into string."}],"return":{"type":"void","description":""}},"napc_mute":{"name":"napc_mute","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Disable console\/serial output.","description":"Temporarily disable output of `napc_puts`, `napc_putc` and `napc_printf`.","rationale":"When running unit tests we are not particularly interested in the output\nthe code generated. We much rather have a single output that says\ntest passed or failed.","example":"napc_printf(\"Hello\"); \/\/ prints Hello\n\nnapc_mute();\n\nnapc_printf(\" World!\"); \/\/ this will not be printed\n\nnapc_unmute();\n\nnapc_printf(\" Earth!\"); \/\/ prints Earth!"},"type":"fn","params":[],"return":{"type":"void","description":""}},"napc_unmute":{"name":"napc_unmute","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Enable console\/serial output.","description":"Re-enable output of `napc_puts`, `napc_putc` and `napc_printf` after a call to `napc_mute`.","example":"napc_printf(\"Hello\"); \/\/ prints Hello\n\nnapc_mute();\n\nnapc_printf(\" World!\"); \/\/ this will not be printed\n\nnapc_unmute();\n\nnapc_printf(\" Earth!\"); \/\/ prints Earth!"},"type":"fn","params":[],"return":{"type":"void","description":""}},"napc_getTimeSinceBoot":{"name":"napc_getTimeSinceBoot","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get time since boot.","description":"Returns the number of milliseconds that have passed since boot.","warning":"The value returned by this function will overflow at some point in time."},"type":"fn","params":[],"return":{"type":"napc_time","description":""}},"napc_delay":{"name":"napc_delay","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Delay program execution.","description":"Delay program execution.","example":"napc_printf(\"Hello \");\n\nnapc_delay(1000); \/\/ wait for 1 second\n\nnapc_printf(\"World!\");"},"type":"fn","params":[{"type":"napc_time","name":"amount","description":"The amount in milliseconds."}],"return":{"type":"void","description":""}},"napc_delayUs":{"name":"napc_delayUs","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Delay program execution.","description":"Delay program execution.","example":"napc_printf(\"Hello \");\n\nnapc_delayUs(250000); \/\/ wait for 250 milliseconds\n\nnapc_printf(\"World!\");"},"type":"fn","params":[{"type":"napc_time","name":"amount","description":"The amount in microseconds."}],"return":{"type":"void","description":""}},"napc_snprintf":{"name":"napc_snprintf","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Format printf()-like string.","rationale":"The `snprintf()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.\nThis function ensures the resulting string is always NUL-terminated.","example":"char buffer[512];\n\nnapc_snprintf(buffer, sizeof(buffer), \"Hello %s!\", \"World!\");\n\n\/\/ buffer now contains 'Hello World!'"},"type":"fn","params":[{"type":"char *","name":"buffer","description":"The buffer to write the formatted string to."},{"type":"napc_size","name":"buffer_size","description":"The size of the buffer."},{"type":"const char *","name":"fmt","description":"printf()-like format string."},{"type":"...","name":"...","description":"Values to incorporate into string."}],"return":{"type":"void","description":""}},"napc_vsnprintf":{"name":"napc_vsnprintf","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Format printf()-like string.","description":"Same as `napc_snprintf()` except it takes a `va_args` list instead of variadic arguments."},"type":"fn","params":[{"type":"char *","name":"buffer","description":"The buffer to write the formatted string to."},{"type":"napc_size","name":"buffer_size","description":"The size of the buffer."},{"type":"const char *","name":"fmt","description":"printf()-like format string."},{"type":"va_list","name":"args","description":"error=2"}],"return":{"type":"void","description":""}},"napc_strncpy":{"name":"napc_strncpy","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Copy a string.","description":"Copy a string to another location.","rationale":"The `strncpy()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.\nThis function ensures the resulting string is always NUL-terminated."},"type":"fn","params":[{"type":"char *","name":"dest","description":"Destination memory location."},{"type":"const char *","name":"source","description":"String to be copied to dest."},{"type":"napc_size","name":"dest_size","description":"Size of destination."}],"return":{"type":"void","description":""}},"napc_strlen":{"name":"napc_strlen","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get length of string.","description":"Count the number of characters in a string.","notes":"This is just an alias for `strlen()`.","example":"napc_size str_length = napc_strlen(\"Hello World!\");\n\nnapc_printf(\"String's length is %\" NAPC_SIZE_PRINTF \"\\n\", str_length);"},"type":"fn","params":[{"type":"const char *","name":"str","description":"The string to be measured."}],"return":{"type":"napc_size","description":"Returns the length of the string."}},"napc_streql":{"name":"napc_streql","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Compare two strings.","description":"Perform case sensitive string comparsion.","rationale":"It's cumbersome to write `strcmp(str1, str2) == 0` to compare strings.","example":"napc_streql(\"my_string\", \"my_string\"); \/\/ returns true\n\nnapc_streql(\"my_string\", \"mY_sTring\"); \/\/ returns false\n\nnapc_streql(\"my_string\", \"my_second_string\"); \/\/ returns false"},"type":"fn","params":[{"type":"const char *","name":"str1","description":"First string."},{"type":"const char *","name":"str2","description":"Second string."}],"return":{"type":"bool","description":"Returns `true` if `str1` and `str2` are equal in contents."}},"napc_streqli":{"name":"napc_streqli","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Compare two strings.","description":"Perform case insensitive string comparsion.","rationale":"It's cumbersome to write `strcasecmp(str1, str2) == 0` to compare strings.","example":"napc_streqli(\"my_string\", \"mY_sTring\"); \/\/ returns true\n\nnapc_streqli(\"my_string\", \"my_second_string\"); \/\/ returns false"},"type":"fn","params":[{"type":"const char *","name":"str1","description":"First string."},{"type":"const char *","name":"str2","description":"Second string."}],"return":{"type":"bool","description":"Returns `true` if `str1` and `str2` are equal in contents."}},"napc_memeql":{"name":"napc_memeql","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Compare two memory regions.","description":"Compare two memory regions.","notes":"The two memory regions need to be of the same size.","rationale":"It's cumbersome to write `memcmp(data1, data2, data_size) == 0` to compare memory blocks.","example":"char data1[3] = {0, 0, 7};\nchar data2[3] = {0, 0, 7};\n\nif (napc_memeql(data1, data2, 3)) {\n    napc_printf(\"data1 and data2 have the same content\");\n}"},"type":"fn","params":[{"type":"const void *","name":"data1","description":"Pointer to first memory location."},{"type":"const void *","name":"data2","description":"Pointer to second memory location."},{"type":"napc_size","name":"data_size","description":"Size of `data1` and `data2` in bytes."}],"return":{"type":"bool","description":"Returns `true` if `data1` and `data2` have the same content."}},"napc_mzero":{"name":"napc_mzero","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Zero out memory region.","description":"Clear memory section.","rationale":"It's cumbersome to write `memset(data, 0, data_size)`.","example":"char buffer[512];\n\n\/\/ clear data buffer\nnapc_mzero(buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"void *","name":"data","description":"Buffer to be zero'd out."},{"type":"napc_size","name":"data_size","description":"Size of `data` buffer."}],"return":{"type":"void","description":""}},"napc_getUptime":{"name":"napc_getUptime","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get uptime in seconds.","description":"Get the uptime in seconds.","example":"napc_time uptime = napc_getUptime();\n\nnapc_printf(\"I'm up since %\" NAPC_TIME_PRINTF \" seconds\", uptime);"},"type":"fn","params":[],"return":{"type":"napc_time","description":"Returns the number of seconds that have passed since boot."}},"napc_getFreeMemory":{"name":"napc_getFreeMemory","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get free memory.","description":"Returns the number of free bytes (on the stack) available."},"type":"fn","params":[],"return":{"type":"napc_size","description":""}},"napc_addLogHandlerFunction":{"name":"napc_addLogHandlerFunction","_associated_module":"Core","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Add log handler function"},"type":"fn","params":[{"type":"napc_logHandlerFunction","name":"handler","description":"The log handler function"},{"type":"void *","name":"context","description":"Context to be passed to function"}],"return":{"type":"napc_ssize","description":"On success a number that can be passed to `napc_removeLogHandlerFunction`.\nOtherwise a negative number is returned."}},"napc_removeLogHandlerFunction":{"name":"napc_removeLogHandlerFunction","_associated_module":"Core","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Remove a log handler function"},"type":"fn","params":[{"type":"napc_size","name":"log_handler_index","description":"Handler index returned by `napc_addLogHandlerFunction`"}],"return":{"type":"void","description":""}},"napc_getRandomBitSources":{"name":"napc_getRandomBitSources","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get source ids for randomness.","description":"Returns a list of all available sources of randomness.\nThe end of the list is indicated with `-1` (which is not a valid source identifier).","notes":"Since this function is hardware dependent, its output also is dependent on the target hardware.","example":"const int *sources = napc_getRandomBitSources();\n\nfor (int i = 0; sources[i] >= 0; ++i) {\n    napc_printf(\"Source identifier %d\\n\", sources[i]);\n}"},"type":"fn","params":[],"return":{"type":"const int *","description":"Returns a list of integers that can be passed as a second parameter to `napc_getRandomBit`."}},"napc_getRandomBit":{"name":"napc_getRandomBit","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a random bit value.","description":"Creates a random bit value (true or false).","warning":["It's not advised to call this function directly, use `napc_getRandomByte` for generating a random byte instead.","`out` remains UNMODIFIED if function returned `false`."],"example":"napc_u8 out;\n\nif (napc_getRandomBit(&out)) {\n    \/\/ do something with `out`\n}"},"type":"fn","params":[{"type":"bool *","name":"out","description":"Location to put random bit into."},{"type":"int","name":"source","description":"Source to get the randomness from. See `napc_getRandomBitSources`."}],"return":{"type":"bool","description":"Returns `true` if `out` contains a new randomly generated bit."}},"napc_getRandomByte":{"name":"napc_getRandomByte","_associated_module":"Core","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a random byte.","description":"Create a random byte.","warning":"`out` remains UNMODIFIED if function returned `false`.","example":"napc_u8 out;\n\nif (napc_getRandomByte(&out)) {\n    \/\/ do something with `out`\n}"},"type":"fn","params":[{"type":"napc_u8 *","name":"out","description":"Location to put random byte into."}],"return":{"type":"bool","description":"Returns `true` if `out` contains a new randomly generated byte."}},"napc_Pool_init":{"name":"napc_Pool_init","_associated_module":"Pool","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Initialize a static pool.","description":"Initializes a static (fixed sized) pool.","example":"int buffer[5];\nnapc_Pool pool;\n\nnapc_Pool_init(&pool, \"int pool\", buffer, 5, sizeof(int));\n\nnapc_ssize id = napc_Pool_allocate(&pool);\n\nint *first_element = napc_Pool_getAddress(&pool, id);"},"type":"fn","params":[{"type":"napc__Pool *","name":"pool","description":"Pointer to the instance."},{"type":"const char *","name":"pool_label","description":"Label for pool. (must be a constant)"},{"type":"void *","name":"array_start","description":"Start address of array (to be used by the pool)"},{"type":"napc_size","name":"num_elements","description":"Number of elements in array."},{"type":"napc_size","name":"element_size","description":"Size (in bytes) of a single element in the array."}],"return":{"type":"void","description":""}},"napc_Pool_claimElement":{"name":"napc_Pool_claimElement","_associated_module":"Pool","general_info":{"version":"1.0.1","changelog":[{"version":"1.0.1","date":"17.03.2022","change":"initial version"}],"brief":"Claim an element of a pool.","description":"Allocates an element from the pool `pool`.","warning":"If the pool is exhausted program execution is halted."},"type":"fn","params":[{"type":"napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."}],"return":{"type":"napc_ssize","description":""}},"napc_Pool_allocate":{"name":"napc_Pool_allocate","_associated_module":"Pool","general_info":{"version":"1.0.1","deprecated":true,"deprecated_replacement":"napc_Pool_claimElement","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"},{"version":"1.0.1","date":"17.03.2022","change":"added deprecation warning"}],"brief":"Allocate an element of a pool.","description":"Allocates an element from the pool `pool`.","warning":"If the pool is exhausted program execution is halted."},"type":"fn","params":[{"type":"napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."}],"return":{"type":"napc_ssize","description":""}},"napc_Pool_isClaimed":{"name":"napc_Pool_isClaimed","_associated_module":"Pool","general_info":{"version":"1.0.1","changelog":[{"version":"1.0.1","date":"17.03.2022","change":"initial version"}],"brief":"Check if element is claimed.","description":"Checks if a particular element is allocated (in use) or not."},"type":"fn","params":[{"type":"const napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."},{"type":"napc_size","name":"element_index","description":"Index of element to check."}],"return":{"type":"bool","description":""}},"napc_Pool_isAllocated":{"name":"napc_Pool_isAllocated","_associated_module":"Pool","general_info":{"version":"1.0.1","deprecated":true,"deprecated_replacement":"napc_Pool_isClaimed","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"},{"version":"1.0.1","date":"17.03.2022","change":"added deprecation warning"}],"brief":"Check if element is allocated.","description":"Checks if a particular element is allocated (in use) or not."},"type":"fn","params":[{"type":"const napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."},{"type":"napc_size","name":"element_index","description":"Index of element to check."}],"return":{"type":"bool","description":""}},"napc_Pool_getAvailable":{"name":"napc_Pool_getAvailable","_associated_module":"Pool","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get available elements.","description":"Get the number of available elements in the pool."},"type":"fn","params":[{"type":"const napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."}],"return":{"type":"napc_size","description":"Returns the number of available elements in the pool."}},"napc_Pool_getAddress":{"name":"napc_Pool_getAddress","_associated_module":"Pool","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get address of an element.","description":"Gets the address of an allocated element in the pool.","warning":"This function can only be used to get the address of allocated elements in the pool.","example":"int buffer[5];\nnapc_Pool pool;\n\nnapc_Pool_init(&pool, \"int pool\", buffer, 5, sizeof(int));\n\nnapc_ssize id = napc_Pool_allocate(&pool);\n\nint *first_element = napc_Pool_getAddress(&pool, id);"},"type":"fn","params":[{"type":"const napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."},{"type":"napc_size","name":"element_index","description":"Index of element."}],"return":{"type":"void *","description":"The element's address."}},"napc_Pool_releaseElement":{"name":"napc_Pool_releaseElement","_associated_module":"Pool","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.1","date":"17.03.2022","change":"initial version"}],"brief":"Release an element.","description":"Releases an element from the pool."},"type":"fn","params":[{"type":"napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."},{"type":"napc_size","name":"element_index","description":"Index of element."}],"return":{"type":"void","description":""}},"napc_Pool_release":{"name":"napc_Pool_release","_associated_module":"Pool","general_info":{"version":"1.0.1","deprecated":true,"deprecated_replacement":"napc_Pool_releaseElement","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"},{"version":"1.0.1","date":"17.03.2022","change":"added deprecation warning"}],"brief":"Release an element.","description":"Releases an element from the pool."},"type":"fn","params":[{"type":"napc__Pool *","name":"pool","description":"Pointer to napc__Pool instance."},{"type":"napc_size","name":"element_index","description":"Index of element."}],"return":{"type":"void","description":""}},"napc_OSTimer_init":{"name":"napc_OSTimer_init","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Initialize a timer.","description":"Initializes a timer with a duration of `duration` milliseconds.","example":"napc__OSTimer timer;\n\nnapc_OSTimer_init(&timer, 1000); \/\/ 1000ms = 1s"},"type":"fn","params":[{"type":"napc__OSTimer *","name":"timer","description":"One shot timer to be initialized."},{"type":"napc_time","name":"duration","description":"Timer duration in milliseconds."}],"return":{"type":"void","description":""}},"napc_OSTimer_create":{"name":"napc_OSTimer_create","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Create a timer object.","description":"Creates a timer with a duration of `duration` milliseconds.","example":"napc__OSTimer timer = napc_OSTimer_create(1000); \/\/ 1000ms = 1s"},"type":"fn","params":[{"type":"napc_time","name":"duration","description":"Timer duration in milliseconds."}],"return":{"type":"napc__OSTimer","description":""}},"napc_OSTimer_start":{"name":"napc_OSTimer_start","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Start a single shot timer.","description":"Starts the single shot timer `timer`.","example":"napc__OSTimer timer = napc_OSTimer_create(1000);\n\nnapc_OSTimer_start(&timer);"},"type":"fn","params":[{"type":"napc__OSTimer *","name":"timer","description":"Timer to start."}],"return":{"type":"void","description":""}},"napc_OSTimer_expired":{"name":"napc_OSTimer_expired","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Check if a timer has expired.","notes":"This function will return `true` only once per started timer.\nSubsequent calls on the same timer will return `false`."},"type":"fn","params":[{"type":"napc__OSTimer *","name":"timer","description":"Timer to check."}],"return":{"type":"bool","description":"Returns `true` if timer expired, `false` otherwise."}},"napc_OSTimer_restart":{"name":"napc_OSTimer_restart","_associated_module":"OSTimer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Restart a timer.","example":"if (napc_OSTimer_expired(&timer)) {\n    napc_OSTimer_restart(&timer);\n}"},"type":"fn","params":[{"type":"napc__OSTimer *","name":"timer","description":"Timer to be restarted."}],"return":{"type":"void","description":""}},"napc_Timer_init":{"name":"napc_Timer_init","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Initialize a timer.","description":"Initializes a timer with a duration of `duration` milliseconds.","example":"napc__Timer timer;\n\nnapc_Timer_init(&timer, 1000); \/\/ 1000ms = 1s"},"type":"fn","params":[{"type":"napc__Timer *","name":"timer","description":"Timer to be initialized."},{"type":"napc_time","name":"duration","description":"Timer duration in milliseconds."}],"return":{"type":"void","description":""}},"napc_Timer_create":{"name":"napc_Timer_create","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Create a timer object.","description":"Creates a timer with a duration of `duration` milliseconds.","example":"napc__Timer timer = napc_Timer_create(1000); \/\/ 1000ms = 1s"},"type":"fn","params":[{"type":"napc_time","name":"duration","description":"Timer duration in milliseconds."}],"return":{"type":"napc__Timer","description":""}},"napc_Timer_start":{"name":"napc_Timer_start","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Start a timer.","description":"Starts the timer `timer`.","example":"napc__Timer timer = napc_Timer_create(1000);\n\nnapc_Timer_start(&timer);"},"type":"fn","params":[{"type":"napc__Timer *","name":"timer","description":"Timer to start."}],"return":{"type":"void","description":""}},"napc_Timer_expired":{"name":"napc_Timer_expired","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Check if a timer has expired.","notes":"After the timer expired this function will always return `true`\nuntil timer is restarted with `napc_Timer_restart`."},"type":"fn","params":[{"type":"napc__Timer *","name":"timer","description":"Timer to check."}],"return":{"type":"bool","description":"Returns `true` if timer expired, `false` otherwise."}},"napc_Timer_restart":{"name":"napc_Timer_restart","_associated_module":"Timer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"25.03.2022","change":"initial version"}],"brief":"Restart a timer.","example":"if (napc_Timer_expired(&timer)) {\n    napc_Timer_restart(&timer);\n}"},"type":"fn","params":[{"type":"napc__Timer *","name":"timer","description":"Timer to be restarted."}],"return":{"type":"void","description":""}},"napc_random_collectBytes":{"name":"napc_random_collectBytes","_associated_module":"random","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Collect random bits from various sources.","notes":"This function must be called periodically for `napc_random_getRandomBytes` to work."},"type":"fn","params":[],"return":{"type":"void","description":""}},"napc_random_getAvailableBytes":{"name":"napc_random_getAvailableBytes","_associated_module":"random","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get number of available random bytes.","description":"Get number of immediately available random bytes."},"type":"fn","params":[],"return":{"type":"napc_size","description":"Returns the number of available random bytes."}},"napc_random_getRandomBytes":{"name":"napc_random_getRandomBytes","_associated_module":"random","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create random bytes.","description":"Creates `n_bytes` random bytes.","notes":"`napc_random_collectBytes` must be called periodically for this function to work.","warning":"`out` remains UNMODIFIED if function returned `false`.","example":"napc_u8 random_bytes[32];\n\nif (napc_random_getRandomBytes(random_bytes, sizeof(random_bytes))) {\n    \/\/ random_bytes now contains 32 random bytes\n}"},"type":"fn","params":[{"type":"napc_size","name":"n_bytes","description":"Number of bytes to be generated."},{"type":"napc_u8 *","name":"out","description":"Array to store collected bytes."}],"return":{"type":"bool","description":"Returns `true` if array `out` was filled with `n_bytes` bytes of random data."}},"napc_random_getRandomBytesSync":{"name":"napc_random_getRandomBytesSync","_associated_module":"random","general_info":{"version":"1.5.0","changelog":[{"version":"1.5.0","date":"25.03.2022","change":"initial version"}],"brief":"Create random bytes.","description":"Creates `n_bytes` random bytes.","warning":"Since this function blocks until enough random data is collected, it is better to use `napc_random_getRandomBytes`.","example":"napc_u8 random_bytes[32];\n\nnapc_random_getRandomBytesSync(random_bytes, sizeof(random_bytes));\n\n\/\/ random_bytes now contains 32 random bytes"},"type":"fn","params":[{"type":"napc_size","name":"n_bytes","description":"Number of bytes to be generated."},{"type":"napc_u8 *","name":"out","description":"Array to store collected bytes."}],"return":{"type":"void","description":""}},"napc_parser_parseDecimalNumberU8":{"name":"napc_parser_parseDecimalNumberU8","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a hexadecimal number from string.","description":"Parse a string containing a decimal number.","example":"napc_u8 out;\n\nif (napc_parser_parseDecimalNumberU8(\"123\", &out)) {\n    napc_printf(\"Value is %d\", out); \/\/ \"Value is 123\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u8 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseDecimalNumberU16":{"name":"napc_parser_parseDecimalNumberU16","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a hexadecimal number from string.","description":"Parse a string containing a decimal number.","example":"napc_u16 out;\n\nif (napc_parser_parseDecimalNumberU16(\"1024\", &out)) {\n    napc_printf(\"Value is %d\", out); \/\/ \"Value is 1024\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u16 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseDecimalNumberU32":{"name":"napc_parser_parseDecimalNumberU32","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a hexadecimal number from string.","description":"Parse a string containing a decimal number.","example":"napc_u32 out;\n\nif (napc_parser_parseDecimalNumberU32(\"123456\", &out)) {\n    napc_printf(\"Value is %ld\", out); \/\/ \"Value is 123456\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u32 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseHexadecimalNumberU8":{"name":"napc_parser_parseHexadecimalNumberU8","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a decimal number from string.","description":"Parse a string containing a hexadecimal number.","example":"napc_u8 out;\n\nif (napc_parser_parseHexadecimalNumberU8(\"ef\", &out)) {\n    napc_printf(\"Value is %ld\", out); \/\/ \"Value is 239\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u8 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseHexadecimalNumberU16":{"name":"napc_parser_parseHexadecimalNumberU16","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a decimal number from string.","description":"Parse a string containing a hexadecimal number.","example":"napc_u16 out;\n\nif (napc_parser_parseHexadecimalNumberU16(\"beef\", &out)) {\n    napc_printf(\"Value is %ld\", out); \/\/ \"Value is 48879\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u16 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseHexadecimalNumberU32":{"name":"napc_parser_parseHexadecimalNumberU32","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a decimal number from string.","description":"Parse a string containing a hexadecimal number.","example":"napc_u32 out;\n\nif (napc_parser_parseHexadecimalNumberU32(\"deadbeef\", &out)) {\n    napc_printf(\"Value is %ld\", out); \/\/ \"Value is 3735928559\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u32 *","name":"out","description":"Pointer to store the parsed number. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseBoolean":{"name":"napc_parser_parseBoolean","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a boolean from string.","description":"Attempts to parse a boolean from a string.\n\nThis function recognizes the following formats:\n - `\"yes\"`, `\"true\"`, `\"1\"` for `true`\n - `\"no\"`, `\"false\"`, `\"0\"` for `false`","notes":"The casing of the string formats does not matter. (for example `yeS` is recognized as `true`)","example":"bool out;\n\nif (napc_parser_parseBoolean(\"yes\", &out)) {\n    \/\/ parsing sucessfull!\n    \/\/ `out` now has the value `true`\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"The string to be parsed."},{"type":"bool *","name":"out","description":"Pointer to a variable to store the result. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseHexString":{"name":"napc_parser_parseHexString","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a string containing hexadecimal characters.","description":"Parse a string of hexadecimal characters.","warning":"The string's length must exactly be double `n_bytes`.","example":"const char *hex_str = \"deadbeefabcdefaa123b\";\nnapc_u8 bytes[10];\n\nif (napc_parser_parseHexString(hex_str, 10, bytes)) {\n    napc_printf(\"The hex value is: \");\n\n    for (int i = 0; i < 10; ++i) {\n        napc_printf(\"%2.2x\", bytes[i]);\n    }\n\n    napc_printf(\"\\n\");\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"The string to be parsed."},{"type":"napc_size","name":"n_bytes","description":"Number of bytes to be parsed."},{"type":"napc_u8 *","name":"out","description":"Array to store result. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseMACAddress":{"name":"napc_parser_parseMACAddress","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a MAC-Address.","description":"Parse a MAC-Address (in the format of `aa:bb:cc:dd:ee:ff`) from string.","warning":"The output array must have at least 6 elements (6 bytes).","example":"napc_u8 addr[6];\n\nif (napc_parser_parseMACAddress(\"ab:de:ef:11:22:33\", addr)) {\n    \/\/ addr[0] now contains 171 (0xab)\n    \/\/ addr[1] now contains 222 (0xde)\n    \/\/ addr[2] now contains 239 (0xef)\n    \/\/ addr[3] now contains 17  (0x11)\n    \/\/ addr[4] now contains 34  (0x22)\n    \/\/ addr[5] now contains 51  (0x33)\n} else {\n    napc_printf(\"Failed to parse MAC-Address!\\n\");\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"String to be parsed."},{"type":"napc_u8 *","name":"out","description":"Array to store result. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseIPv4Address":{"name":"napc_parser_parseIPv4Address","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse an IPv4-Address.","description":"Parse an IPv4-Address (in the format of `a.b.c.d`) from string.","warning":"The output array must have at least 4 elements (4 bytes).","example":"napc_u8 addr[4];\n\nif (napc_parser_parseIPv4Address(\"1.2.3.4\", addr)) {\n    \/\/ addr[0] now contains 1\n    \/\/ addr[1] now contains 2\n    \/\/ addr[2] now contains 3\n    \/\/ addr[3] now contains 4\n} else {\n    napc_printf(\"Failed to parse IP-Address!\\n\");\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"The string to be parsed."},{"type":"napc_u8 *","name":"out","description":"Array to store result. (optional)"}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_parser_parseKeyValue":{"name":"napc_parser_parseKeyValue","_associated_module":"parser","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a key,value pair.","description":"Parse a string in `key,value` format.","example":"char key[32];\nchar value[32];\n\nbool result = napc_parser_parseKeyValue(\n    \"test,1234\",\n     key, sizeof(key),\n     value, sizeof(value)\n);\n\nif (result) {\n    \/\/ key is \"test\"\n    \/\/ value is \"1234\"\n}"},"type":"fn","params":[{"type":"const char *","name":"string","description":"The string to be parsed."},{"type":"char *","name":"key","description":"Buffer to place parsed key string."},{"type":"napc_size","name":"key_len","description":"Size of `key` buffer."},{"type":"char *","name":"value","description":"Buffer to place parsed value string."},{"type":"napc_size","name":"value_len","description":"Size of `value` buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_aes_encrypt":{"name":"napc_aes_encrypt","_associated_module":"aes","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Encrypt a message with AES-256.","description":"Encrypt a message with AES-256 in CBC mode.","warning":"The input buffer must always be aligned to 16 bytes.","example":"char message[32];\nnapc_u8 iv[16];\nconst char *key = \"secret\";\nchar key_hashed[65];\n\n\/\/ initialize IV with random bytes\n\/\/ note that napc_random_getRandomBytesSync() is used here for simplicity\n\/\/ it is better to use napc_random_getRandomBytes().\nnapc_random_getRandomBytesSync(sizeof(iv), iv);\n\n\/\/ since napc_aes_encrypt() expects a HEX formatted key string\n\/\/ we simply calculate the SHA256 hash of the key\n\/\/ which is guaranteed to be a 32 byte hex formatted string.\nif (napc_sha_calculate(key, napc_strlen(key), key_hashed, sizeof(key_hashed))) {\n    \/\/ set all bytes in message to zero\n    \/\/ napc_aes_encrypt() always needs the input buffer's size to be\n    \/\/ a multiple of 16. This way unused bytes are always zero.\n    napc_mzero(message, sizeof(message));\n\n    \/\/ copy a message\n    napc_strncpy(message, \"Hello, World!\", sizeof(message));\n\n    \/\/ do the encryption\n    if (napc_aes_encrypt(iv, key_hashed, message, sizeof(message))) {\n        \/\/ message is now encrypted\n        napc_printf(\"Message encrypted!\\n\");\n\n        napc_printf(\"Key: %s\\n\", key_hashed);\n\n        napc_printf(\"IV: \");\n        napc_misc_printHexArray(iv, sizeof(iv));\n        napc_printf(\"\\n\");\n\n        napc_printf(\"Ciphertext: \");\n        napc_misc_printHexArray(message, sizeof(message));\n        napc_printf(\"\\n\");\n    }\n}"},"type":"fn","params":[{"type":"const napc_u8 *","name":"iv","description":"Initialization vector (16 bytes)"},{"type":"const char *","name":"key","description":"Key in HEX format (32 bytes)"},{"type":"void *","name":"buffer","description":"Buffer to encrypt."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":""}},"napc_aes_decrypt":{"name":"napc_aes_decrypt","_associated_module":"aes","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Decrypt a message with AES-256.","description":"Decrypt a message with AES-256 in CBC mode.","warning":"The input buffer must always be aligned to 16 bytes."},"type":"fn","params":[{"type":"const napc_u8 *","name":"iv","description":"Initialization vector (16 bytes)"},{"type":"const char *","name":"key","description":"Key in HEX format (32 bytes)"},{"type":"void *","name":"buffer","description":"Buffer to encrypt."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_hmac_calculate":{"name":"napc_hmac_calculate","_associated_module":"hmac","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Calculate HMAC of a message.","description":"Calculate the SHA-256 HMAC signature of a message."},"type":"fn","params":[{"type":"napc_u8 *","name":"out","description":"Pointer to store resulting HMAC (32 bytes)"},{"type":"const char *","name":"key","description":"Key to be used."},{"type":"const void *","name":"buffer","description":"Buffer containing the message."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"void","description":""}},"napc_hmac_verify":{"name":"napc_hmac_verify","_associated_module":"hmac","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Verify a message with HMAC.","description":"Verify a message."},"type":"fn","params":[{"type":"const char *","name":"key","description":"Key to be used."},{"type":"const napc_u8 *","name":"hmac","description":"Pointer to HMAC (32 bytes)"},{"type":"const void *","name":"buffer","description":"Buffer containing the message."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` if the message matches the `hmac` signature."}},"napc_misc_printHexArray":{"name":"napc_misc_printHexArray","_associated_module":"misc","general_info":{"version":"1.5.0","changelog":[{"version":"1.5.0","date":"25.03.2022","change":"initial version"}],"brief":"Print an array of integers","rationale":"It's cumbersome to write a loop for printing out hex arrays.","example":"napc_u8 array[4] = {0xde, 0xad, 0xbe, 0xef};\n\n\/\/ prints deadbeef\nnapc_misc_printHexArray(array, sizeof(array));"},"type":"fn","params":[{"type":"const void *","name":"bytes","description":"Bytes array."},{"type":"napc_size","name":"n_bytes","description":"Size of bytes array."}],"return":{"type":"void","description":""}},"napc_misc_shiftArrayRight":{"name":"napc_misc_shiftArrayRight","_associated_module":"misc","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Shift elements in an array.","description":"Shift elements in `array` one element to the right discarding the last\nelement in the array.","notes":"The contents of the first element in `array` will be undefined after this operation.","example":"int data[5] = {1, 2, 3, 4, 5};\n\nnapc_misc_shiftArrayRight(data, 5, sizeof(int));\n\n\/\/ data[0] is now undefined\n\/\/ data[1] is now 1\n\/\/ data[2] is now 2\n\/\/ data[3] is now 3\n\/\/ data[4] is now 4"},"type":"fn","params":[{"type":"void *","name":"array","description":"The array to be shifted."},{"type":"napc_size","name":"n_elements","description":"The number of elements in `array`."},{"type":"napc_size","name":"element_size","description":"The size (in bytes) of one element in `array`."}],"return":{"type":"void","description":""}},"napc_misc_chunkedOperation":{"name":"napc_misc_chunkedOperation","_associated_module":"misc","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Perform an operation in chunks.","description":"Performs an operation in chunks.","notes":"`fn` is a function with the following prototype:\n\n`napc_ssize (const void *data, napc_size data_size, void *context)`"},"type":"fn","params":[{"type":"const void *","name":"data","description":"Data to process."},{"type":"napc_size","name":"data_size","description":"Size of data to process."},{"type":"napc_size","name":"chunk_size","description":"Size of one chunk."},{"type":"napc_misc_ChunkedOperationCallback","name":"fn","description":"Callback for processing one chunk."},{"type":"void *","name":"fn_context","description":"Optional context for `fn` callback."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_init":{"name":"napc_Reader_init","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Initialize a reader.","description":"Initialize a reader.","example":"napc__Reader reader;\nchar buffer[512];\n\nnapc_Reader_init(&reader, buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to the napc__Reader instance."},{"type":"const void *","name":"data","description":"Pointer to the buffer to be read."},{"type":"napc_size","name":"data_size","description":"Size of buffer."}],"return":{"type":"void","description":""}},"napc_Reader_create":{"name":"napc_Reader_create","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a reader object.","description":"Create a reader.","example":"char buffer[512];\n\nnapc__Reader reader = napc_Reader_create(buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"const void *","name":"data","description":"Pointer to the buffer to be read."},{"type":"napc_size","name":"data_size","description":"Size of `data`."}],"return":{"type":"napc__Reader","description":""}},"napc_Reader_readU8":{"name":"napc_Reader_readU8","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read an unsigned integer (8 bits).","description":"Read an unsigned integer (8 bit) from buffer.","example":"napc_u8 buffer[] = {4, 3, 2, 1};\nnapc__Reader reader;\n\nnapc_Reader_init(&reader, buffer, sizeof(buffer));\n\nnapc_u8 out;\n\nif (napc_Reader_readU8(&reader, &out)) {\n    \/\/ out has the value '4'\n}"},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"napc_u8 *","name":"out","description":"Pointer to store result."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readU8Array":{"name":"napc_Reader_readU8Array","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read an array of unsigned integers (8 bits).","description":"Read an array of unsigned integers (8 bit) from buffer."},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"napc_size","name":"n_elements","description":"Number of elements to read."},{"type":"napc_u8 *","name":"out","description":"Array to store bytes."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readU16BE":{"name":"napc_Reader_readU16BE","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read an unsigned integer (16 bits).","description":"Read an unsigned integer (16 bit) in big endian order from buffer.","example":"napc_u8 buffer[] = {4, 3, 2, 1};\nnapc__Reader reader;\n\nnapc_Reader_init(&reader, buffer, sizeof(buffer));\n\nnapc_u16 out;\n\nif (napc_Reader_readU16BE(&reader, &out)) {\n    \/\/ out has the value 772 (0x0403)\n}"},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"napc_u16 *","name":"out","description":"Pointer to store result."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readU32BE":{"name":"napc_Reader_readU32BE","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read an unsigned integer (32 bits).","description":"Read an unsigned integer (32 bit) in big endian order from buffer.","example":"napc_u8 buffer[] = {4, 3, 2, 1};\nnapc__Reader reader;\n\nnapc_Reader_init(&reader, buffer, sizeof(buffer));\n\nnapc_u32 out;\n\nif (napc_Reader_readU32BE(&reader, &out)) {\n    \/\/ out has the value 67305985 (0x04030201)\n}"},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"napc_u32 *","name":"out","description":"Pointer to store result."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readChar":{"name":"napc_Reader_readChar","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read a single character.","description":"Read a character (8 bit) from buffer."},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"char *","name":"out","description":"Pointer to store result."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readString":{"name":"napc_Reader_readString","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read a string.","description":"Read a string from buffer.","notes":"Resulting string (that is placed in `out`) is always NUL-terminated."},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"napc_size","name":"str_len","description":"Length of string to be read."},{"type":"char *","name":"out","description":"Pointer to store result."},{"type":"napc_size","name":"out_size","description":"Size of `out`."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_Reader_readLine":{"name":"napc_Reader_readLine","_associated_module":"Reader","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read a line.","description":"Read a line from buffer.","notes":"The resulting string in `line_buffer` will always be NUL-terminated.","example":"char line_buffer[128];\nnapc__Reader reader;\nconst char *str = \"First line\\nSecond line\\nThird line\";\n\nnapc_Reader_init(&reader, str, napc_strlen(str));\n\nwhile (true) {\n    const char *current_line = napc_Reader_readLine(&reader, line_buffer, sizeof(line_buffer));\n\n    if (!current_line) break;\n\n    napc_printf(\"Read line: %s\", current_line);\n}"},"type":"fn","params":[{"type":"napc__Reader *","name":"ctx","description":"Pointer to napc__Reader instance."},{"type":"char *","name":"line_buffer","description":"Buffer to place line into."},{"type":"napc_size","name":"line_buffer_size","description":"Size of the line buffer."}],"return":{"type":"const char *","description":"Returns `line_buffer` if a line was parsed, `NULL` otherwise."}},"napc_Reader_getCurrentOffset":{"name":"napc_Reader_getCurrentOffset","_associated_module":"Reader","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"10.04.2022","change":"initial version"}],"brief":"Get current offset.","description":"Returns the current offset the reader is at."},"type":"fn","params":[{"type":"const napc__Reader *","name":"ctx","description":"error=1"}],"return":{"type":"napc_size","description":""}},"napc_Reader_getCurrentAddress":{"name":"napc_Reader_getCurrentAddress","_associated_module":"Reader","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"10.04.2022","change":"initial version"}],"brief":"Get current address.","description":"Returns the current address the reader is at `(data + offset)`."},"type":"fn","params":[{"type":"const napc__Reader *","name":"ctx","description":"error=1"}],"return":{"type":"const void *","description":""}},"napc_Reader_getStartAddress":{"name":"napc_Reader_getStartAddress","_associated_module":"Reader","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"10.04.2022","change":"initial version"}],"brief":"Get the start address.","description":"Returns the start address."},"type":"fn","params":[{"type":"const napc__Reader *","name":"ctx","description":"error=1"}],"return":{"type":"const void *","description":""}},"napc_Reader_getEndAddress":{"name":"napc_Reader_getEndAddress","_associated_module":"Reader","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"10.04.2022","change":"initial version"}],"brief":"Get the last address.","description":"Returns the end address `(data + (size - 1))`."},"type":"fn","params":[{"type":"const napc__Reader *","name":"ctx","description":"error=1"}],"return":{"type":"const void *","description":""}},"napc_Writer_init":{"name":"napc_Writer_init","_associated_module":"Writer","general_info":{"version":"1.0.0.","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Initialize a writer.","description":"Initialize a writer.","example":"napc__Writer writer;\nchar buffer[512];\n\nnapc_Writer_init(&writer, buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance to be initialized."},{"type":"void *","name":"data","description":"Pointer to the buffer that we want to write to."},{"type":"napc_size","name":"data_size","description":"Size of `data`."}],"return":{"type":"void","description":""}},"napc_Writer_create":{"name":"napc_Writer_create","_associated_module":"Writer","general_info":{"version":"1.0.0.","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a writer object.","description":"Create a writer.","example":"char buffer[512];\n\nnapc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"void *","name":"data","description":"Pointer to the buffer that we want to write to."},{"type":"napc_size","name":"data_size","description":"Size of `data`."}],"return":{"type":"napc__Writer","description":""}},"napc_Writer_moveCurrentOffsetByAmount":{"name":"napc_Writer_moveCurrentOffsetByAmount","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Move internal offset.","description":"Move offset by `amount` of bytes.\nA negative `offset` is permitted."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"napc_ssize","name":"amount","description":"The amount."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_resetCurrentOffset":{"name":"napc_Writer_resetCurrentOffset","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Reset internal offset.","description":"Reset offset back to zero."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."}],"return":{"type":"void","description":""}},"napc_Writer_writeU8":{"name":"napc_Writer_writeU8","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write an unsigned integer (8 bits).","description":"Write the unsigned integer value `value`.","example":"napc__Writer writer;\nchar buffer[512];\n\nnapc_Writer_init(&writer, buffer, sizeof(buffer));\n\nnapc_Writer_writeU8(&writer, 0xAA);\nnapc_Writer_writeU8(&writer, 0xBB);\n\n\/\/ buffer[0] is now 0xAA\n\/\/ buffer[1] is now 0xBB"},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"napc_u8","name":"value","description":"Value to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeU8Array":{"name":"napc_Writer_writeU8Array","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write an array unsigned integers (8 bits).","description":"Write an array of unsigned integer values."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"napc_size","name":"n_elements","description":"The number of elements in `array`."},{"type":"const napc_u8 *","name":"array","description":"The array to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeU16BE":{"name":"napc_Writer_writeU16BE","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write an unsigned integer (16 bits).","description":"Write the 16 bit unsigned integer value `value` in big endian order."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"napc_u16","name":"value","description":"Value to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeU32BE":{"name":"napc_Writer_writeU32BE","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write an unsigned integer (32 bits).","description":"Write the 32 bit unsigned integer value `value` in big endian order."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"napc_u32","name":"value","description":"Value to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeChar":{"name":"napc_Writer_writeChar","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write a single character.","description":"Attempts to write the character `value`."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"char","name":"value","description":"Character to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeString":{"name":"napc_Writer_writeString","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write a string.","description":"Write a string.","notes":"No NUL-termination will be placed in the underlying buffer."},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"const char *","name":"value","description":"String to be written."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_writeStringFormat":{"name":"napc_Writer_writeStringFormat","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write a string format.","description":"Write a printf-like formatted string.","notes":"No NUL-termination will be placed in the underlying buffer.","example":"napc__Writer writer;\nchar buffer[512];\n\nnapc_Writer_init(&writer, buffer, sizeof(buffer));\n\nnapc_Writer_writeStringFormat(&writer, \"Hello %s!\", \"World!\");\n\n\/\/ the first 12 bytes of `buffer`\n\/\/ now contain \"Hello World!\""},"type":"fn","params":[{"type":"napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."},{"type":"const char *","name":"fmt","description":"printf()-like format string."},{"type":"...","name":"...","description":"Values to incorporate into string."}],"return":{"type":"bool","description":"Returns `true` on success, otherwise `false`."}},"napc_Writer_getCurrentOffset":{"name":"napc_Writer_getCurrentOffset","_associated_module":"Writer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get internal offset.","description":"Get buffer offset from the writer instance."},"type":"fn","params":[{"type":"const napc__Writer *","name":"ctx","description":"Pointer to the napc__Writer instance."}],"return":{"type":"napc_size","description":"Returns the current buffer offset from the writer instance."}},"napc_Writer_getCurrentAddress":{"name":"napc_Writer_getCurrentAddress","_associated_module":"Writer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get current address.","description":"Returns the current address the writer is at `(data + offset)`."},"type":"fn","params":[{"type":"const napc__Writer *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_Writer_getStartAddress":{"name":"napc_Writer_getStartAddress","_associated_module":"Writer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get the start address.","description":"Returns the start address."},"type":"fn","params":[{"type":"const napc__Writer *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_Writer_getEndAddress":{"name":"napc_Writer_getEndAddress","_associated_module":"Writer","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get the last address.","description":"Returns the end address `(data + (size - 1))`."},"type":"fn","params":[{"type":"const napc__Writer *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_NFWriter_init":{"name":"napc_NFWriter_init","_associated_module":"NFWriter","general_info":{"version":"2.0.0.","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Initialize a no-fail writer.","description":"Initialize a no-fail writer.","example":"napc__NFWriter writer;\nchar buffer[512];\n\nnapc_NFWriter_init(&writer, buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance to be initialized."},{"type":"void *","name":"data","description":"Pointer to the buffer that we want to write to."},{"type":"napc_size","name":"data_size","description":"Size of `data`."}],"return":{"type":"void","description":""}},"napc_NFWriter_create":{"name":"napc_NFWriter_create","_associated_module":"NFWriter","general_info":{"version":"2.0.0.","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Create a no-fail writer object.","description":"Create a no-fail writer.","example":"char buffer[512];\n\nnapc__NFWriter writer = napc_NFWriter_create(buffer, sizeof(buffer));"},"type":"fn","params":[{"type":"void *","name":"data","description":"Pointer to the buffer that we want to write to."},{"type":"napc_size","name":"data_size","description":"Size of `data`."}],"return":{"type":"napc__NFWriter","description":""}},"napc_NFWriter_moveCurrentOffsetByAmount":{"name":"napc_NFWriter_moveCurrentOffsetByAmount","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Move internal offset.","description":"Move offset by `amount` of bytes.\nA negative `offset` is permitted."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"napc_ssize","name":"amount","description":"The amount."}],"return":{"type":"void","description":""}},"napc_NFWriter_resetCurrentOffset":{"name":"napc_NFWriter_resetCurrentOffset","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Reset internal offset.","description":"Reset offset back to zero."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeU8":{"name":"napc_NFWriter_writeU8","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write an unsigned integer (8 bits).","description":"Writes the unsigned integer value `value`.","example":"napc__NFWriter writer;\nchar buffer[512];\n\nnapc_NFWriter_init(&writer, buffer, sizeof(buffer));\n\nnapc_NFWriter_writeU8(&writer, 0xAA);\nnapc_NFWriter_writeU8(&writer, 0xBB);\n\n\/\/ buffer[0] is now 0xAA\n\/\/ buffer[1] is now 0xBB"},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"napc_u8","name":"value","description":"Value to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeU8Array":{"name":"napc_NFWriter_writeU8Array","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write an array unsigned integers (8 bits).","description":"Writes an array of unsigned integer values."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"napc_size","name":"n_elements","description":"The number of elements in `array`."},{"type":"const napc_u8 *","name":"array","description":"The array to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeU16BE":{"name":"napc_NFWriter_writeU16BE","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write an unsigned integer (16 bits).","description":"Write the 16 bit unsigned integer value `value` in big endian order."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"napc_u16","name":"value","description":"Value to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeU32BE":{"name":"napc_NFWriter_writeU32BE","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write an unsigned integer (32 bits).","description":"Write the 32 bit unsigned integer value `value` in big endian order."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"napc_u32","name":"value","description":"Value to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeChar":{"name":"napc_NFWriter_writeChar","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write a single character.","description":"Attempts to write the character `value`."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"char","name":"value","description":"Character to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeString":{"name":"napc_NFWriter_writeString","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write a string.","description":"Write a string.","notes":"No NUL-termination will be placed in the underlying buffer."},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"const char *","name":"value","description":"String to be written."}],"return":{"type":"void","description":""}},"napc_NFWriter_writeStringFormat":{"name":"napc_NFWriter_writeStringFormat","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Write a string format.","description":"Write a printf-like formatted string.","notes":"No NUL-termination will be placed in the underlying buffer.","example":"napc__NFWriter writer;\nchar buffer[512];\n\nnapc_NFWriter_init(&writer, buffer, sizeof(buffer));\n\nnapc_NFWriter_writeStringFormat(&writer, \"Hello %s!\", \"World!\");\n\n\/\/ the first 12 bytes of `buffer`\n\/\/ now contain \"Hello World!\""},"type":"fn","params":[{"type":"napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."},{"type":"const char *","name":"fmt","description":"printf()-like format string."},{"type":"...","name":"...","description":"Values to incorporate into string."}],"return":{"type":"void","description":""}},"napc_NFWriter_getCurrentOffset":{"name":"napc_NFWriter_getCurrentOffset","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get internal offset.","description":"Get buffer offset from the writer instance."},"type":"fn","params":[{"type":"const napc__NFWriter *","name":"ctx","description":"Pointer to the napc__NFWriter instance."}],"return":{"type":"napc_size","description":"Returns the current buffer offset from the writer instance."}},"napc_NFWriter_getCurrentAddress":{"name":"napc_NFWriter_getCurrentAddress","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get current address.","description":"Returns the current address the writer is at `(data + offset)`."},"type":"fn","params":[{"type":"const napc__NFWriter *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_NFWriter_getStartAddress":{"name":"napc_NFWriter_getStartAddress","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get the start address.","description":"Returns the start address."},"type":"fn","params":[{"type":"const napc__NFWriter *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_NFWriter_getEndAddress":{"name":"napc_NFWriter_getEndAddress","_associated_module":"NFWriter","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Get the last address.","description":"Returns the end address `(data + (size - 1))`."},"type":"fn","params":[{"type":"const napc__NFWriter *","name":"ctx","description":"error=1"}],"return":{"type":"void *","description":""}},"napc_IPv4Participant_init":{"name":"napc_IPv4Participant_init","_associated_module":"IPv4Participant","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Initialize a participant.","description":"Initialize a participant.","notes":"Input address (`addr`) will be copied into `participant`."},"type":"fn","params":[{"type":"napc__IPv4Participant *","name":"participant","description":"Pointer to instance to initialize."},{"type":"const char *","name":"addr","description":"IPv4-Address of participant in format `a.b.c.d`."},{"type":"napc_u16","name":"port","description":"Port of participant."}],"return":{"type":"void","description":""}},"napc_IPv4Participant_create":{"name":"napc_IPv4Participant_create","_associated_module":"IPv4Participant","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a participant object.","description":"Create a participant.","notes":"Input address (`addr`) will be copied into `participant`.","example":"napc__IPv4Participant google_dns = napc_IPv4Participant_create(\"8.8.8.8\", 53);"},"type":"fn","params":[{"type":"const char *","name":"addr","description":"IPv4-Address of participant in format `a.b.c.d`."},{"type":"napc_u16","name":"port","description":"Port of participant."}],"return":{"type":"napc__IPv4Participant","description":"Returns an initialized participant."}},"napc_IPv4Participant_copy":{"name":"napc_IPv4Participant_copy","_associated_module":"IPv4Participant","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Copy a participant.","description":"Create a copy of a participant."},"type":"fn","params":[{"type":"napc__IPv4Participant *","name":"dest","description":"Pointer to destination."},{"type":"napc__IPv4Participant","name":"source","description":"Source."}],"return":{"type":"void","description":""}},"napc_DNS_parseHeader":{"name":"napc_DNS_parseHeader","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a DNS-Header from a buffer."},"type":"fn","params":[{"type":"napc__DNSHeader *","name":"out","description":"Pointer to a `napc__DNSHeader` to store result."},{"type":"const void *","name":"buffer","description":"Buffer to be parsed."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_DNS_parseRequest":{"name":"napc_DNS_parseRequest","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a DNS-Request from a buffer."},"type":"fn","params":[{"type":"napc__DNSRequest *","name":"out","description":"Pointer to a `napc__DNSRequest` to store result."},{"type":"const void *","name":"buffer","description":"Buffer to be parsed."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_DNS_parseResponse":{"name":"napc_DNS_parseResponse","_associated_module":"DNS","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Parse a DNS-Response from a buffer.","description":"Parse a DNS-Response from a buffer."},"type":"fn","params":[{"type":"napc__DNSResponse *","name":"out","description":"Pointer to a `napc__DNSResponse` to store result."},{"type":"const void *","name":"buffer","description":"Buffer to be parsed."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_sha_calculate":{"name":"napc_sha_calculate","_associated_module":"sha","general_info":{"version":"1.5.0","changelog":[{"version":"1.5.0","date":"25.03.2022","change":"initial version"}],"brief":"Calculate SHA256 hash.","description":"Calculates the SHA-256 hash of a message.","warning":"The output array must have at least 65 elements.","example":"char out[65];\nconst char *str = \"secret\";\n\nnapc_sha_calculate(str, napc_strlen(str), out, sizeof(out));\n\nnapc_printf(\"SHA256-hash of '%s' is '%s'\\n\");"},"type":"fn","params":[{"type":"const void *","name":"buffer","description":"Buffer to calculate hash of."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."},{"type":"char *","name":"out","description":"Array to store output in HEX format (32 bytes)."},{"type":"napc_size","name":"out_size","description":"Size of output array."}],"return":{"type":"bool","description":""}},"napc_eth_getLinkStatus":{"name":"napc_eth_getLinkStatus","_associated_module":"eth","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get the link status of network adapter.","example":"if (napc_eth_getLinkStatus()) {\n    napc_printf(\"Ethernet link established.\\n\");\n}"},"type":"fn","params":[],"return":{"type":"bool","description":"Returns `true` if ethernet link is established, `false` otherwise."}},"napc_eth_setMACAddress":{"name":"napc_eth_setMACAddress","_associated_module":"eth","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Set mac address of network adapter.","example":"napc_eth_setMACAddress(\"88:24:D3:27:9A:2F\");"},"type":"fn","params":[{"type":"const char *","name":"mac","description":"MAC-Address in format `aa:bb:cc:dd:ee:ff`."}],"return":{"type":"void","description":""}},"napc_eth_setIPAddress":{"name":"napc_eth_setIPAddress","_associated_module":"eth","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Set ip address of network adapter.","example":"napc_eth_setIPAddress(\"192.168.1.50\");"},"type":"fn","params":[{"type":"const char *","name":"ip","description":"IPv4-Address in format `a.b.c.d`."}],"return":{"type":"void","description":""}},"napc_eth_setSubnetMask":{"name":"napc_eth_setSubnetMask","_associated_module":"eth","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Set subnetmask of network adapter.","example":"napc_eth_setSubnetMask(\"255.255.255.0\");"},"type":"fn","params":[{"type":"const char *","name":"submask","description":"Subnetmask in format `a.b.c.d`."}],"return":{"type":"void","description":""}},"napc_eth_setGatewayAddress":{"name":"napc_eth_setGatewayAddress","_associated_module":"eth","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Set the gateway address of network adapter.","example":"napc_eth_setGatewayAddress(\"192.168.1.1\");"},"type":"fn","params":[{"type":"const char *","name":"ip","description":"IPv4-Address in format `a.b.c.d`."}],"return":{"type":"void","description":""}},"napc_eth_calculateBroadcastAddress":{"name":"napc_eth_calculateBroadcastAddress","_associated_module":"eth","general_info":{"version":"2.0.0","changelog":[{"version":"2.0.0","date":"12.04.2022","change":"initial version"}],"brief":"Calulcate broadcast address of IP-address.","example":"char broadcast_addr[32];\n\nbool result = napc_eth_calculateBroadcastAddress(\n    \"10.1.2.5\",\n    \"255.255.255.0\",\n    broadcast_addr, sizeof(broadcast_addr)\n);\n\nif (result) {\n    napc_printf(\"Broadcast address of 10.1.2.5 is %s\\n\", broadcast_addr);\n}"},"type":"fn","params":[{"type":"const char *","name":"ip","description":"IPv4-Address in format `a.b.c.d`."},{"type":"const char *","name":"submask","description":"IPv4-Subnetmask in format `a.b.c.d`."},{"type":"char *","name":"out","description":"Output array."},{"type":"napc_size","name":"out_size","description":"Size of output array."}],"return":{"type":"bool","description":""}},"napc_Buffer_init":{"name":"napc_Buffer_init","_associated_module":"Buffer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Initialize a buffer.","description":"Initialize a buffer.","example":"char message[512];\nnapc__Buffer buffer;\n\nnapc_Buffer_init(&buffer, message, sizeof(message));"},"type":"fn","params":[{"type":"napc__Buffer *","name":"buffer","description":"Pointer to napc__Buffer instance to be initialized."},{"type":"void *","name":"data","description":"Pointer to data."},{"type":"napc_size","name":"data_size","description":"Size of data."}],"return":{"type":"void","description":""}},"napc_Buffer_create":{"name":"napc_Buffer_create","_associated_module":"Buffer","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Create a buffer.","description":"Create a buffer.","example":"char message[512];\n\nnapc__Buffer buffer = napc_Buffer_create(message, sizeof(message));"},"type":"fn","params":[{"type":"void *","name":"data","description":"Pointer to data."},{"type":"napc_size","name":"data_size","description":"Size of data."}],"return":{"type":"napc__Buffer","description":"Returns an initialized buffer."}},"napc_UDP_createSocket":{"name":"napc_UDP_createSocket","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Open an UDP-Socket.","description":"Open an UDP-socket on port `port` for receiving and sending messages.","example":"napc__UDPSocket udp_sock = napc_UDP_createSocket(2020);\n\nif (0 > udp_sock) {\n    NAPC_PANIC(\"Failed to create UDP-socket.\");\n}"},"type":"fn","params":[{"type":"napc_u16","name":"port","description":"IPv4 port number."}],"return":{"type":"napc__UDPSocket","description":"Returns a negative number if socket could not be created."}},"napc_UDP_receive":{"name":"napc_UDP_receive","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Receive an UDP-message.","description":"Receive a message on a UDP socket.","warning":"It's not possible to receive a UDP packet with a size greater than `1500` bytes (MTU limit).","example":"char message_buffer[512];\nnapc__Buffer buf;\n\nnapc__UDPSocket udp_socket = napc_UDP_createSocket(2020);\n\nnapc_Buffer_init(&buf, message_buffer, sizeof(message_buffer));\n\nif (napc_UDP_receive(&udp_socket, NULL, &buf)) {\n    napc_printf(\"Received %\" NAPC_SIZE_PRINTF \" bytes\\n\", buf.size);\n}"},"type":"fn","params":[{"type":"napc__UDPSocket","name":"udp_socket","description":"The UDP socket to receive from."},{"type":"napc__IPv4Participant *","name":"source","description":"Source of received message (optional)."},{"type":"napc__Buffer *","name":"out","description":"Pointer to a buffer to place received message."}],"return":{"type":"bool","description":"Returns `false` if no message was received."}},"napc_UDP_send":{"name":"napc_UDP_send","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Send an UPD-message.","description":"Send a UDP message to `destination`.","warning":"It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit)."},"type":"fn","params":[{"type":"napc__UDPSocket","name":"udp_socket","description":"The UDP socket to write the message to."},{"type":"napc__IPv4Participant","name":"destination","description":"IPv4 destination (ip & port)."},{"type":"const void *","name":"buffer","description":"Message to be sent."},{"type":"napc_size","name":"buffer_size","description":"Size of the message."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_UDP_sendSilent":{"name":"napc_UDP_sendSilent","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Send an UDP-message.","description":"Same as `napc_UDP_send()` but does not log anything.\nUsed to send log over the network to another device.","warning":"It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit)."},"type":"fn","params":[{"type":"napc__UDPSocket","name":"udp_socket","description":"The UDP socket to write the message to."},{"type":"napc__IPv4Participant","name":"destination","description":"IPv4 destination (ip & port)."},{"type":"const void *","name":"buffer","description":"Message to be sent."},{"type":"napc_size","name":"buffer_size","description":"Size of the message."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_UDP_closeSocket":{"name":"napc_UDP_closeSocket","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Close an open UDP-socket.","description":"Close an open UDP-socket."},"type":"fn","params":[{"type":"napc__UDPSocket","name":"udp_socket","description":"The UDP-socket to be closed."}],"return":{"type":"void","description":""}},"napc_UDP_getNumOpenSockets":{"name":"napc_UDP_getNumOpenSockets","_associated_module":"UDP","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get the number of open UDP sockets.","description":"Gets the number of currently open UDP sockets."},"type":"fn","params":[],"return":{"type":"napc_size","description":"Returns the number of open UDP sockets."}},"napc_File_open":{"name":"napc_File_open","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Open a file.","description":"Open a file for reading or writing.","notes":"On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.","warning":"Opening a file in write mode (`\"w\"`) will always clear the previous contents of the file.","example":"napc__File fd = napc_File_open(\"TEST.TXT\", \"r\");\n\nif (0 > fd) {\n    NAPC_PANIC(\"Failed to open TEST.TXT!\");\n}"},"type":"fn","params":[{"type":"const char *","name":"path","description":"Path to the file."},{"type":"const char *","name":"mode","description":"Mode (`\"r\"` for reading, `\"w\"` for writing)."}],"return":{"type":"napc__File","description":"Returns a negative number if file could not be opened."}},"napc_File_write":{"name":"napc_File_write","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write to a file.","description":"Write data to an open file."},"type":"fn","params":[{"type":"napc__File","name":"file","description":"File to write to."},{"type":"const void *","name":"data","description":"Buffer to write."},{"type":"napc_size","name":"data_size","description":"Size of buffer."}],"return":{"type":"napc_ssize","description":"Returns the number of bytes written or `-1` on error."}},"napc_File_read":{"name":"napc_File_read","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read from a file.","description":"Reads data from an open file."},"type":"fn","params":[{"type":"napc__File","name":"file","description":"File to read from."},{"type":"void *","name":"buffer","description":"Buffer to write data to."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"napc_ssize","description":"Returns the number of bytes read or `-1` on error."}},"napc_File_getSize":{"name":"napc_File_getSize","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Get size of file.","description":"Get the size of an open file."},"type":"fn","params":[{"type":"napc__File","name":"file","description":"File to be measured."}],"return":{"type":"napc_size","description":"Returns the file size in bytes."}},"napc_File_close":{"name":"napc_File_close","_associated_module":"File","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Close open file.","description":"Close an open file."},"type":"fn","params":[{"type":"napc__File","name":"file","description":"File to be closed."}],"return":{"type":"void","description":""}},"napc_fs_writeFile":{"name":"napc_fs_writeFile","_associated_module":"fs","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write data to a file.","description":"Writes data to a file overwriting its previous contents.","notes":"On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.","warning":"This function will always overwrite the previous contents of the file."},"type":"fn","params":[{"type":"const char *","name":"path","description":"File path."},{"type":"const void *","name":"buffer","description":"Buffer to write."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_fs_writeFileCString":{"name":"napc_fs_writeFileCString","_associated_module":"fs","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Write a string to a file.","description":"Writes a string to a file overwriting its previous contents.","notes":"On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.","warning":"This function will always overwrite the previous contents of the file."},"type":"fn","params":[{"type":"const char *","name":"path","description":"File path."},{"type":"const char *","name":"string","description":"String to write to file."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_fs_readFile":{"name":"napc_fs_readFile","_associated_module":"fs","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read a file in its entirety.","description":"Reads the entire content of a file into a buffer.","notes":"On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`."},"type":"fn","params":[{"type":"const char *","name":"path","description":"File path."},{"type":"napc__Buffer *","name":"buffer","description":"Buffer to write to."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_fs_readFileCString":{"name":"napc_fs_readFileCString","_associated_module":"fs","general_info":{"version":"1.0.0","changelog":[{"version":"1.0.0","date":"17.02.2022","change":"initial version"}],"brief":"Read a file in its entirety.","description":"Reads the entire content of a file into a NUL-terminated string.","notes":"On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`."},"type":"fn","params":[{"type":"const char *","name":"path","description":"File path."},{"type":"char *","name":"buffer","description":"Buffer to write to."},{"type":"napc_size","name":"buffer_size","description":"Size of buffer."}],"return":{"type":"bool","description":"Returns `true` on success, `false` otherwise."}},"napc_env_isFileSystemAvailable":{"name":"napc_env_isFileSystemAvailable","_associated_module":"env","general_info":{"version":"1.1.0","changelog":[{"version":"1.1.0","date":"18.03.2022","change":"initial version"}],"brief":"Check file system availability.","example":"if (napc_env_isFileSystemAvailable()) {\n    napc_printf(\"File System is available.\\n\");\n}"},"type":"fn","params":[],"return":{"type":"bool","description":"Returns `true` if file system functionality is available."}},"napc_env_isEthernetAvailable":{"name":"napc_env_isEthernetAvailable","_associated_module":"env","general_info":{"version":"1.1.0","changelog":[{"version":"1.1.0","date":"18.03.2022","change":"initial version"}],"brief":"Check ethernet availability.","example":"if (napc_env_isEthernetAvailable()) {\n    napc_printf(\"Ethernet is available.\\n\");\n}"},"type":"fn","params":[],"return":{"type":"bool","description":"Returns `true` if ethernet functionality is available."}}},"modules_intro":{"Pool":{"@name":"Pool:intro","@brief":"Static memory allocation"},"OSTimer":{"@name":"OSTimer:intro","@brief":"One-Shot timer"},"random":{"@name":"random:intro","@brief":"Random number generation","@description":"This module provides random number generation suitable for cryptographic purposes.\n\nA typical application looks like this:\n\n```c\n#include <napc.h>\n\nnapc_u8 random_bytes[16];\n\nvoid napc_app_setup(const char *platform) {}\n\nbool napc_app_loop(napc_time uptime) {\n\t\/\/ request of 16 random bytes\n\tif (napc_random_getRandomBytes(16, random_bytes)) {\n\t\t\/\/ do something with random_bytes\n\n\t\tnapc_printf(\"Here are your random numbers: \");\n\n\t\tfor (int i = 0; i < 16; ++i) {\n\t\t\tnapc_printf(\"%2.2x\", random_bytes[i]);\n\t\t}\n\n\t\tnapc_printf(\"\\n\");\n\n\t\treturn false;\n\t}\n\n\t\/\/ collect new random data\n\tnapc_random_collectBytes();\n\n\treturn true;\n}\n```\n\nThis program will output something similar to:\n\n```\nHere are your random numbers: 162109b28bba5eabb17b69d83aeffd84\n```"},"parser":{"@name":"parser:intro","@brief":"String parsing","@description":"This module contains all functions that parse strings.\n\nAll functions in this module follow the same rules<sup>*<\/sup>:\n\n- The first parameter is always the string to be parsed.\n- Every function returns a boolean indicating success or failure.\n- It is allowed to pass `NULL` as output. This is useful for checking the format of a string:\n\n```c\nif (napc_parser_parseIPv4Address(ip_str, NULL)) {\n\t\/\/ ip_str is a valid IPv4Address\n}\n```\n\n> If a function returned `false` the contents of the parsed output is _undefined_."},"aes":{"@name":"aes:intro","@brief":"Encrypt & decrypt messages"},"hmac":{"@name":"hmac:intro","@brief":"Sign & verify messages"},"Reader":{"@name":"Reader:intro","@brief":"Binary buffer reader"},"Writer":{"@name":"Writer:intro","@brief":"Binary buffer writer"},"NFWriter":{"@name":"NFWriter:intro","@brief":"No fail binary buffer writer"},"IPv4Participant":{"@name":"IPv4Participant:intro","@description":"To reduce parameter count this module is used to combine an IPv4-Address and a port number:\n\n```c\n\/\/ Holds address for google's DNS server 8.8.8.8:53\nnapc__IPv4Participant google_dns;\n\n\/\/ Initialize google_dns variable\nnapc_IPv4Participant_init(&google_dns, \"8.8.8.8\", 53);\n```"},"UDP":{"@name":"UDP:intro","@brief":"Send & receive network packets","@description":"Used to send and\/or receive IP packets over the UDP protocol.","@example":"#include <napc.h>\n\nnapc__UDPSocket sock;\nint counter = 0;\n\nvoid napc_setup(const char *p) {\n\tif (!napc_env_isEthernetAvailable()) {\n\t\tNAPC_PANIC(\"Sorry, ethernet is not available :(\\n\");\n\t}\n\n\t\/\/ initialize ethernet\n\tnapc_eth_setIPAddress(\"192.168.0.20\");\n\tnapc_eth_setMACAddress(\"aa:bb:cc:dd:ee:ff\");\n\n\t\/\/ open udp socket on port 2020\n\tsock = napc_UDP_createSocket(2020);\n\n\tnapc_printf(\"Opened UDP socket on port 2020\\n\");\n}\n\nbool napc_loop(napc_time uptime) {\n\tchar packet_buffer[512];\n\n\tnapc__Buffer buffer = napc_Buffer_create(packet_buffer, sizeof(packet_buffer));\n\tnapc__IPv4Participant source_ip;\n\n\tif (napc_UDP_receive(sock, &source_ip, &buffer)) {\n\t\tnapc_printf(\n\t\t\t\"Received %\" NAPC_SIZE_PRINTF \" bytes from %s:%u\\n\",\n\t\t\tbuffer.size,\n\t\t\tsource_ip.addr,\n\t\t\tsource_ip.port\n\t\t);\n\n\t\tnapc_UDP_send(sock, source_ip, buffer.data, buffer.size);\n\t}\n\n\treturn true;\n}"},"Buffer":{"@name":"Buffer:intro","@description":"To reduce parameter count this module is used to pass a buffer with its size to a function:\n\n```c\nchar data[512];\nnapc__Buffer buffer;\n\nnapc_Buffer_init(&buffer, data, sizeof(data));\n```"},"fs":{"@name":"fs:intro","@brief":"Write & read files"}},"modules":{"Core":["f:napc_version","f:napc_getFullVersion","f:napc_puts","f:napc_putc","f:napc_printf","f:napc_mute","f:napc_unmute","f:napc_getTimeSinceBoot","f:napc_delay","f:napc_delayUs","f:napc_snprintf","f:napc_vsnprintf","f:napc_strncpy","f:napc_strlen","f:napc_streql","f:napc_streqli","f:napc_memeql","f:napc_mzero","f:napc_getUptime","f:napc_getFreeMemory","f:napc_addLogHandlerFunction","f:napc_removeLogHandlerFunction","f:napc_getRandomBitSources","f:napc_getRandomBit","f:napc_getRandomByte","t:napc_u8","t:napc_i8","t:napc_u16","t:napc_i16","t:napc_u32","t:napc_i32","t:napc_size","t:napc_ssize","t:napc_time"],"Buffer":["f:napc_Buffer_init","f:napc_Buffer_create","t:napc__Buffer"],"DNS":["f:napc_DNS_parseHeader","f:napc_DNS_parseRequest","f:napc_DNS_parseResponse","t:napc__DNSHeader","t:napc__DNSQuery","t:napc__DNSAnswer","t:napc__DNSRequest","t:napc__DNSResponse","t:napc__DNSOPCode","t:napc__DNSQType"],"File":["f:napc_File_open","f:napc_File_write","f:napc_File_read","f:napc_File_getSize","f:napc_File_close","t:napc__File"],"IPv4Participant":["f:napc_IPv4Participant_init","f:napc_IPv4Participant_create","f:napc_IPv4Participant_copy","t:napc__IPv4Participant"],"NFWriter":["f:napc_NFWriter_init","f:napc_NFWriter_create","f:napc_NFWriter_moveCurrentOffsetByAmount","f:napc_NFWriter_resetCurrentOffset","f:napc_NFWriter_writeU8","f:napc_NFWriter_writeU8Array","f:napc_NFWriter_writeU16BE","f:napc_NFWriter_writeU32BE","f:napc_NFWriter_writeChar","f:napc_NFWriter_writeString","f:napc_NFWriter_writeStringFormat","f:napc_NFWriter_getCurrentOffset","f:napc_NFWriter_getCurrentAddress","f:napc_NFWriter_getStartAddress","f:napc_NFWriter_getEndAddress","t:napc__NFWriter"],"OSTimer":["f:napc_OSTimer_init","f:napc_OSTimer_create","f:napc_OSTimer_start","f:napc_OSTimer_expired","f:napc_OSTimer_restart","t:napc__OSTimer"],"Pool":["f:napc_Pool_init","f:napc_Pool_claimElement","f:napc_Pool_allocate","f:napc_Pool_isClaimed","f:napc_Pool_isAllocated","f:napc_Pool_getAvailable","f:napc_Pool_getAddress","f:napc_Pool_releaseElement","f:napc_Pool_release","t:napc__Pool"],"Reader":["f:napc_Reader_init","f:napc_Reader_create","f:napc_Reader_readU8","f:napc_Reader_readU8Array","f:napc_Reader_readU16BE","f:napc_Reader_readU32BE","f:napc_Reader_readChar","f:napc_Reader_readString","f:napc_Reader_readLine","f:napc_Reader_getCurrentOffset","f:napc_Reader_getCurrentAddress","f:napc_Reader_getStartAddress","f:napc_Reader_getEndAddress","t:napc__Reader"],"Timer":["f:napc_Timer_init","f:napc_Timer_create","f:napc_Timer_start","f:napc_Timer_expired","f:napc_Timer_restart","t:napc__Timer"],"UDP":["f:napc_UDP_createSocket","f:napc_UDP_receive","f:napc_UDP_send","f:napc_UDP_sendSilent","f:napc_UDP_closeSocket","f:napc_UDP_getNumOpenSockets","t:napc__UDPSocket"],"Writer":["f:napc_Writer_init","f:napc_Writer_create","f:napc_Writer_moveCurrentOffsetByAmount","f:napc_Writer_resetCurrentOffset","f:napc_Writer_writeU8","f:napc_Writer_writeU8Array","f:napc_Writer_writeU16BE","f:napc_Writer_writeU32BE","f:napc_Writer_writeChar","f:napc_Writer_writeString","f:napc_Writer_writeStringFormat","f:napc_Writer_getCurrentOffset","f:napc_Writer_getCurrentAddress","f:napc_Writer_getStartAddress","f:napc_Writer_getEndAddress","t:napc__Writer"],"aes":["f:napc_aes_encrypt","f:napc_aes_decrypt"],"env":["f:napc_env_isFileSystemAvailable","f:napc_env_isEthernetAvailable"],"eth":["f:napc_eth_getLinkStatus","f:napc_eth_setMACAddress","f:napc_eth_setIPAddress","f:napc_eth_setSubnetMask","f:napc_eth_setGatewayAddress","f:napc_eth_calculateBroadcastAddress"],"fs":["f:napc_fs_writeFile","f:napc_fs_writeFileCString","f:napc_fs_readFile","f:napc_fs_readFileCString"],"hmac":["f:napc_hmac_calculate","f:napc_hmac_verify"],"misc":["f:napc_misc_printHexArray","f:napc_misc_shiftArrayRight","f:napc_misc_chunkedOperation"],"parser":["f:napc_parser_parseDecimalNumberU8","f:napc_parser_parseDecimalNumberU16","f:napc_parser_parseDecimalNumberU32","f:napc_parser_parseHexadecimalNumberU8","f:napc_parser_parseHexadecimalNumberU16","f:napc_parser_parseHexadecimalNumberU32","f:napc_parser_parseBoolean","f:napc_parser_parseHexString","f:napc_parser_parseMACAddress","f:napc_parser_parseIPv4Address","f:napc_parser_parseKeyValue"],"random":["f:napc_random_collectBytes","f:napc_random_getAvailableBytes","f:napc_random_getRandomBytes","f:napc_random_getRandomBytesSync"],"sha":["f:napc_sha_calculate"]},"assets":{"svg":{"alert-circle.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M13,13H11V7H13M13,17H11V15H13M12,2A10,10 0 0,0 2,12A10,10 0 0,0 12,22A10,10 0 0,0 22,12A10,10 0 0,0 12,2Z\" \/><\/svg>","alert.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M11,15H13V17H11V15M11,7H13V13H11V7M12,2C6.47,2 2,6.5 2,12A10,10 0 0,0 12,22A10,10 0 0,0 22,12A10,10 0 0,0 12,2M12,20A8,8 0 0,1 4,12A8,8 0 0,1 12,4A8,8 0 0,1 20,12A8,8 0 0,1 12,20Z\" \/><\/svg>","book-open.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M13,12H20V13.5H13M13,9.5H20V11H13M13,14.5H20V16H13M21,4H3A2,2 0 0,0 1,6V19A2,2 0 0,0 3,21H21A2,2 0 0,0 23,19V6A2,2 0 0,0 21,4M21,19H12V6H21\" \/><\/svg>","check-decagram.svg":"<svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" viewBox=\"0 0 24 24\"><path d=\"M23,12L20.56,9.22L20.9,5.54L17.29,4.72L15.4,1.54L12,3L8.6,1.54L6.71,4.72L3.1,5.53L3.44,9.21L1,12L3.44,14.78L3.1,18.47L6.71,19.29L8.6,22.47L12,21L15.4,22.46L17.29,19.28L20.9,18.46L20.56,14.78L23,12M10,17L6,13L7.41,11.59L10,14.17L16.59,7.58L18,9L10,17Z\" \/><\/svg>","chevron-right.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M8.59,16.58L13.17,12L8.59,7.41L10,6L16,12L10,18L8.59,16.58Z\" \/><\/svg>","close-circle-outline.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12,20C7.59,20 4,16.41 4,12C4,7.59 7.59,4 12,4C16.41,4 20,7.59 20,12C20,16.41 16.41,20 12,20M12,2C6.47,2 2,6.47 2,12C2,17.53 6.47,22 12,22C17.53,22 22,17.53 22,12C22,6.47 17.53,2 12,2M14.59,8L12,10.59L9.41,8L8,9.41L10.59,12L8,14.59L9.41,16L12,13.41L14.59,16L16,14.59L13.41,12L16,9.41L14.59,8Z\" \/><\/svg>","close.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M19,6.41L17.59,5L12,10.59L6.41,5L5,6.41L10.59,12L5,17.59L6.41,19L12,13.41L17.59,19L19,17.59L13.41,12L19,6.41Z\" \/><\/svg>","cog.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12,15.5A3.5,3.5 0 0,1 8.5,12A3.5,3.5 0 0,1 12,8.5A3.5,3.5 0 0,1 15.5,12A3.5,3.5 0 0,1 12,15.5M19.43,12.97C19.47,12.65 19.5,12.33 19.5,12C19.5,11.67 19.47,11.34 19.43,11L21.54,9.37C21.73,9.22 21.78,8.95 21.66,8.73L19.66,5.27C19.54,5.05 19.27,4.96 19.05,5.05L16.56,6.05C16.04,5.66 15.5,5.32 14.87,5.07L14.5,2.42C14.46,2.18 14.25,2 14,2H10C9.75,2 9.54,2.18 9.5,2.42L9.13,5.07C8.5,5.32 7.96,5.66 7.44,6.05L4.95,5.05C4.73,4.96 4.46,5.05 4.34,5.27L2.34,8.73C2.21,8.95 2.27,9.22 2.46,9.37L4.57,11C4.53,11.34 4.5,11.67 4.5,12C4.5,12.33 4.53,12.65 4.57,12.97L2.46,14.63C2.27,14.78 2.21,15.05 2.34,15.27L4.34,18.73C4.46,18.95 4.73,19.03 4.95,18.95L7.44,17.94C7.96,18.34 8.5,18.68 9.13,18.93L9.5,21.58C9.54,21.82 9.75,22 10,22H14C14.25,22 14.46,21.82 14.5,21.58L14.87,18.93C15.5,18.67 16.04,18.34 16.56,17.94L19.05,18.95C19.27,19.03 19.54,18.95 19.66,18.73L21.66,15.27C21.78,15.05 21.73,14.78 21.54,14.63L19.43,12.97Z\" \/><\/svg>","dark-mode.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12 2A9.91 9.91 0 0 0 9 2.46A10 10 0 0 1 9 21.54A10 10 0 1 0 12 2Z\" \/><\/svg>","download.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M13,5V11H14.17L12,13.17L9.83,11H11V5H13M15,3H9V9H5L12,16L19,9H15V3M19,18H5V20H19V18Z\" \/><\/svg>","home.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M21,5C19.89,4.65 18.67,4.5 17.5,4.5C15.55,4.5 13.45,4.9 12,6C10.55,4.9 8.45,4.5 6.5,4.5C4.55,4.5 2.45,4.9 1,6V20.65C1,20.9 1.25,21.15 1.5,21.15C1.6,21.15 1.65,21.1 1.75,21.1C3.1,20.45 5.05,20 6.5,20C8.45,20 10.55,20.4 12,21.5C13.35,20.65 15.8,20 17.5,20C19.15,20 20.85,20.3 22.25,21.05C22.35,21.1 22.4,21.1 22.5,21.1C22.75,21.1 23,20.85 23,20.6V6C22.4,5.55 21.75,5.25 21,5M21,18.5C19.9,18.15 18.7,18 17.5,18C15.8,18 13.35,18.65 12,19.5V8C13.35,7.15 15.8,6.5 17.5,6.5C18.7,6.5 19.9,6.65 21,7V18.5Z\" \/><\/svg>","info.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M13.5,4A1.5,1.5 0 0,0 12,5.5A1.5,1.5 0 0,0 13.5,7A1.5,1.5 0 0,0 15,5.5A1.5,1.5 0 0,0 13.5,4M13.14,8.77C11.95,8.87 8.7,11.46 8.7,11.46C8.5,11.61 8.56,11.6 8.72,11.88C8.88,12.15 8.86,12.17 9.05,12.04C9.25,11.91 9.58,11.7 10.13,11.36C12.25,10 10.47,13.14 9.56,18.43C9.2,21.05 11.56,19.7 12.17,19.3C12.77,18.91 14.38,17.8 14.54,17.69C14.76,17.54 14.6,17.42 14.43,17.17C14.31,17 14.19,17.12 14.19,17.12C13.54,17.55 12.35,18.45 12.19,17.88C12,17.31 13.22,13.4 13.89,10.71C14,10.07 14.3,8.67 13.14,8.77Z\" \/><\/svg>","layers-triple.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12 0L3 7L4.63 8.27L12 14L19.36 8.27L21 7L12 0M19.37 10.73L12 16.47L4.62 10.74L3 12L12 19L21 12L19.37 10.73M19.37 15.73L12 21.47L4.62 15.74L3 17L12 24L21 17L19.37 15.73Z\" \/><\/svg>","light-mode.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M3.55,18.54L4.96,19.95L6.76,18.16L5.34,16.74M11,22.45C11.32,22.45 13,22.45 13,22.45V19.5H11M12,5.5A6,6 0 0,0 6,11.5A6,6 0 0,0 12,17.5A6,6 0 0,0 18,11.5C18,8.18 15.31,5.5 12,5.5M20,12.5H23V10.5H20M17.24,18.16L19.04,19.95L20.45,18.54L18.66,16.74M20.45,4.46L19.04,3.05L17.24,4.84L18.66,6.26M13,0.55H11V3.5H13M4,10.5H1V12.5H4M6.76,4.84L4.96,3.05L3.55,4.46L5.34,6.26L6.76,4.84Z\" \/><\/svg>","menu.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M3,6H21V8H3V6M3,11H21V13H3V11M3,16H21V18H3V16Z\" \/><\/svg>","module_icon\/Buffer.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M21,16.5C21,16.88 20.79,17.21 20.47,17.38L12.57,21.82C12.41,21.94 12.21,22 12,22C11.79,22 11.59,21.94 11.43,21.82L3.53,17.38C3.21,17.21 3,16.88 3,16.5V7.5C3,7.12 3.21,6.79 3.53,6.62L11.43,2.18C11.59,2.06 11.79,2 12,2C12.21,2 12.41,2.06 12.57,2.18L20.47,6.62C20.79,6.79 21,7.12 21,7.5V16.5M12,4.15L6.04,7.5L12,10.85L17.96,7.5L12,4.15M5,15.91L11,19.29V12.58L5,9.21V15.91M19,15.91V9.21L13,12.58V19.29L19,15.91Z\" \/><\/svg>","module_icon\/Core.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M14,13A1,1 0 0,0 13,14A1,1 0 0,0 14,15A1,1 0 0,0 15,14A1,1 0 0,0 14,13M14,16.5A0.5,0.5 0 0,0 13.5,17A0.5,0.5 0 0,0 14,17.5A0.5,0.5 0 0,0 14.5,17A0.5,0.5 0 0,0 14,16.5M12,20A8,8 0 0,1 4,12A8,8 0 0,1 12,4A8,8 0 0,1 20,12A8,8 0 0,1 12,20M12,2A10,10 0 0,0 2,12A10,10 0 0,0 12,22A10,10 0 0,0 22,12A10,10 0 0,0 12,2M17,9.5A0.5,0.5 0 0,0 16.5,10A0.5,0.5 0 0,0 17,10.5A0.5,0.5 0 0,0 17.5,10A0.5,0.5 0 0,0 17,9.5M17,13.5A0.5,0.5 0 0,0 16.5,14A0.5,0.5 0 0,0 17,14.5A0.5,0.5 0 0,0 17.5,14A0.5,0.5 0 0,0 17,13.5M14,7.5A0.5,0.5 0 0,0 14.5,7A0.5,0.5 0 0,0 14,6.5A0.5,0.5 0 0,0 13.5,7A0.5,0.5 0 0,0 14,7.5M14,9A1,1 0 0,0 13,10A1,1 0 0,0 14,11A1,1 0 0,0 15,10A1,1 0 0,0 14,9M10,7.5A0.5,0.5 0 0,0 10.5,7A0.5,0.5 0 0,0 10,6.5A0.5,0.5 0 0,0 9.5,7A0.5,0.5 0 0,0 10,7.5M7,13.5A0.5,0.5 0 0,0 6.5,14A0.5,0.5 0 0,0 7,14.5A0.5,0.5 0 0,0 7.5,14A0.5,0.5 0 0,0 7,13.5M10,16.5A0.5,0.5 0 0,0 9.5,17A0.5,0.5 0 0,0 10,17.5A0.5,0.5 0 0,0 10.5,17A0.5,0.5 0 0,0 10,16.5M7,9.5A0.5,0.5 0 0,0 6.5,10A0.5,0.5 0 0,0 7,10.5A0.5,0.5 0 0,0 7.5,10A0.5,0.5 0 0,0 7,9.5M10,13A1,1 0 0,0 9,14A1,1 0 0,0 10,15A1,1 0 0,0 11,14A1,1 0 0,0 10,13M10,9A1,1 0 0,0 9,10A1,1 0 0,0 10,11A1,1 0 0,0 11,10A1,1 0 0,0 10,9Z\" \/><\/svg>","module_icon\/DNS.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M16.36,14C16.44,13.34 16.5,12.68 16.5,12C16.5,11.32 16.44,10.66 16.36,10H19.74C19.9,10.64 20,11.31 20,12C20,12.69 19.9,13.36 19.74,14M14.59,19.56C15.19,18.45 15.65,17.25 15.97,16H18.92C17.96,17.65 16.43,18.93 14.59,19.56M14.34,14H9.66C9.56,13.34 9.5,12.68 9.5,12C9.5,11.32 9.56,10.65 9.66,10H14.34C14.43,10.65 14.5,11.32 14.5,12C14.5,12.68 14.43,13.34 14.34,14M12,19.96C11.17,18.76 10.5,17.43 10.09,16H13.91C13.5,17.43 12.83,18.76 12,19.96M8,8H5.08C6.03,6.34 7.57,5.06 9.4,4.44C8.8,5.55 8.35,6.75 8,8M5.08,16H8C8.35,17.25 8.8,18.45 9.4,19.56C7.57,18.93 6.03,17.65 5.08,16M4.26,14C4.1,13.36 4,12.69 4,12C4,11.31 4.1,10.64 4.26,10H7.64C7.56,10.66 7.5,11.32 7.5,12C7.5,12.68 7.56,13.34 7.64,14M12,4.03C12.83,5.23 13.5,6.57 13.91,8H10.09C10.5,6.57 11.17,5.23 12,4.03M18.92,8H15.97C15.65,6.75 15.19,5.55 14.59,4.44C16.43,5.07 17.96,6.34 18.92,8M12,2C6.47,2 2,6.5 2,12A10,10 0 0,0 12,22A10,10 0 0,0 22,12A10,10 0 0,0 12,2Z\" \/><\/svg>","module_icon\/File.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M6,2A2,2 0 0,0 4,4V20A2,2 0 0,0 6,22H18A2,2 0 0,0 20,20V8L14,2H6M6,4H13V9H18V20H6V4M8,12V14H16V12H8M8,16V18H13V16H8Z\" \/><\/svg>","module_icon\/IPv4Participant.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M16,11H14V9H16V11M3,5A2,2 0 0,1 5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5C3.89,21 3,20.1 3,19V5M10,7H8V17H10V7M12,17H14V13H16A2,2 0 0,0 18,11V9A2,2 0 0,0 16,7H12V17Z\" \/><\/svg>","module_icon\/NFWriter.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M15.54,3.5L20.5,8.47L19.07,9.88L14.12,4.93L15.54,3.5M3.5,19.78L10,13.31C9.9,13 9.97,12.61 10.23,12.35C10.62,11.96 11.26,11.96 11.65,12.35C12.04,12.75 12.04,13.38 11.65,13.77C11.39,14.03 11,14.1 10.69,14L4.22,20.5L14.83,16.95L18.36,10.59L13.42,5.64L7.05,9.17L3.5,19.78Z\" \/><\/svg>","module_icon\/OSTimer.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12,20A7,7 0 0,1 5,13A7,7 0 0,1 12,6A7,7 0 0,1 19,13A7,7 0 0,1 12,20M12,4A9,9 0 0,0 3,13A9,9 0 0,0 12,22A9,9 0 0,0 21,13A9,9 0 0,0 12,4M12.5,8H11V14L15.75,16.85L16.5,15.62L12.5,13.25V8M7.88,3.39L6.6,1.86L2,5.71L3.29,7.24L7.88,3.39M22,5.72L17.4,1.86L16.11,3.39L20.71,7.25L22,5.72Z\" \/><\/svg>","module_icon\/Pool.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M2,15C3.67,14.25 5.33,13.5 7,13.17V5A3,3 0 0,1 10,2C11.31,2 12.42,2.83 12.83,4H10A1,1 0 0,0 9,5V6H14V5A3,3 0 0,1 17,2C18.31,2 19.42,2.83 19.83,4H17A1,1 0 0,0 16,5V14.94C18,14.62 20,13 22,13V15C19.78,15 17.56,17 15.33,17C13.11,17 10.89,15 8.67,15C6.44,15 4.22,16 2,17V15M14,8H9V10H14V8M14,12H9V13C10.67,13.16 12.33,14.31 14,14.79V12M2,19C4.22,18 6.44,17 8.67,17C10.89,17 13.11,19 15.33,19C17.56,19 19.78,17 22,17V19C19.78,19 17.56,21 15.33,21C13.11,21 10.89,19 8.67,19C6.44,19 4.22,20 2,21V19Z\" \/><\/svg>","module_icon\/Reader.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M3,10C2.76,10 2.55,10.09 2.41,10.25C2.27,10.4 2.21,10.62 2.24,10.86L2.74,13.85C2.82,14.5 3.4,15 4,15H7C7.64,15 8.36,14.44 8.5,13.82L9.56,10.63C9.6,10.5 9.57,10.31 9.5,10.19C9.39,10.07 9.22,10 9,10H3M7,17H4C2.38,17 0.96,15.74 0.76,14.14L0.26,11.15C0.15,10.3 0.39,9.5 0.91,8.92C1.43,8.34 2.19,8 3,8H9C9.83,8 10.58,8.35 11.06,8.96C11.17,9.11 11.27,9.27 11.35,9.45C11.78,9.36 12.22,9.36 12.64,9.45C12.72,9.27 12.82,9.11 12.94,8.96C13.41,8.35 14.16,8 15,8H21C21.81,8 22.57,8.34 23.09,8.92C23.6,9.5 23.84,10.3 23.74,11.11L23.23,14.18C23.04,15.74 21.61,17 20,17H17C15.44,17 13.92,15.81 13.54,14.3L12.64,11.59C12.26,11.31 11.73,11.31 11.35,11.59L10.43,14.37C10.07,15.82 8.56,17 7,17M15,10C14.78,10 14.61,10.07 14.5,10.19C14.42,10.31 14.4,10.5 14.45,10.7L15.46,13.75C15.64,14.44 16.36,15 17,15H20C20.59,15 21.18,14.5 21.25,13.89L21.76,10.82C21.79,10.62 21.73,10.4 21.59,10.25C21.45,10.09 21.24,10 21,10H15Z\" \/><\/svg>","module_icon\/Timer.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M6,2H18V8H18V8L14,12L18,16V16H18V22H6V16H6V16L10,12L6,8V8H6V2M16,16.5L12,12.5L8,16.5V20H16V16.5M12,11.5L16,7.5V4H8V7.5L12,11.5M10,6H14V6.75L12,8.75L10,6.75V6Z\" \/><\/svg>","module_icon\/UDP.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M16,4L9,8.04V15.96L16,20L23,15.96V8.04M16,6.31L19.8,8.5L16,10.69L12.21,8.5M0,7V9H7V7M11,10.11L15,12.42V17.11L11,14.81M21,10.11V14.81L17,17.11V12.42M2,11V13H7V11M4,15V17H7V15\" \/><\/svg>","module_icon\/Writer.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M14.06,9L15,9.94L5.92,19H5V18.08L14.06,9M17.66,3C17.41,3 17.15,3.1 16.96,3.29L15.13,5.12L18.88,8.87L20.71,7.04C21.1,6.65 21.1,6 20.71,5.63L18.37,3.29C18.17,3.09 17.92,3 17.66,3M14.06,6.19L3,17.25V21H6.75L17.81,9.94L14.06,6.19Z\" \/><\/svg>","module_icon\/aes.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M12,17A2,2 0 0,0 14,15C14,13.89 13.1,13 12,13A2,2 0 0,0 10,15A2,2 0 0,0 12,17M18,8A2,2 0 0,1 20,10V20A2,2 0 0,1 18,22H6A2,2 0 0,1 4,20V10C4,8.89 4.9,8 6,8H7V6A5,5 0 0,1 12,1A5,5 0 0,1 17,6V8H18M12,3A3,3 0 0,0 9,6V8H15V6A3,3 0 0,0 12,3Z\" \/><\/svg>","module_icon\/env.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M17.9,17.39C17.64,16.59 16.89,16 16,16H15V13A1,1 0 0,0 14,12H8V10H10A1,1 0 0,0 11,9V7H13A2,2 0 0,0 15,5V4.59C17.93,5.77 20,8.64 20,12C20,14.08 19.2,15.97 17.9,17.39M11,19.93C7.05,19.44 4,16.08 4,12C4,11.38 4.08,10.78 4.21,10.21L9,15V16A2,2 0 0,0 11,18M12,2A10,10 0 0,0 2,12A10,10 0 0,0 12,22A10,10 0 0,0 22,12A10,10 0 0,0 12,2Z\" \/><\/svg>","module_icon\/eth.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M7,15H9V18H11V15H13V18H15V15H17V18H19V9H15V6H9V9H5V18H7V15M4.38,3H19.63C20.94,3 22,4.06 22,5.38V19.63A2.37,2.37 0 0,1 19.63,22H4.38C3.06,22 2,20.94 2,19.63V5.38C2,4.06 3.06,3 4.38,3Z\" \/><\/svg>","module_icon\/fs.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M6,2H18A2,2 0 0,1 20,4V20A2,2 0 0,1 18,22H6A2,2 0 0,1 4,20V4A2,2 0 0,1 6,2M12,4A6,6 0 0,0 6,10C6,13.31 8.69,16 12.1,16L11.22,13.77C10.95,13.29 11.11,12.68 11.59,12.4L12.45,11.9C12.93,11.63 13.54,11.79 13.82,12.27L15.74,14.69C17.12,13.59 18,11.9 18,10A6,6 0 0,0 12,4M12,9A1,1 0 0,1 13,10A1,1 0 0,1 12,11A1,1 0 0,1 11,10A1,1 0 0,1 12,9M7,18A1,1 0 0,0 6,19A1,1 0 0,0 7,20A1,1 0 0,0 8,19A1,1 0 0,0 7,18M12.09,13.27L14.58,19.58L17.17,18.08L12.95,12.77L12.09,13.27Z\" \/><\/svg>","module_icon\/hmac.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M7 14C5.9 14 5 13.1 5 12S5.9 10 7 10 9 10.9 9 12 8.1 14 7 14M12.6 10C11.8 7.7 9.6 6 7 6C3.7 6 1 8.7 1 12S3.7 18 7 18C9.6 18 11.8 16.3 12.6 14H16V18H20V14H23V10H12.6Z\" \/><\/svg>","module_icon\/mem.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M17,17H7V7H17M21,11V9H19V7C19,5.89 18.1,5 17,5H15V3H13V5H11V3H9V5H7C5.89,5 5,5.89 5,7V9H3V11H5V13H3V15H5V17A2,2 0 0,0 7,19H9V21H11V19H13V21H15V19H17A2,2 0 0,0 19,17V15H21V13H19V11M13,13H11V11H13M15,9H9V15H15V9Z\" \/><\/svg>","module_icon\/misc.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M21,16.5C21,16.88 20.79,17.21 20.47,17.38L12.57,21.82C12.41,21.94 12.21,22 12,22C11.79,22 11.59,21.94 11.43,21.82L3.53,17.38C3.21,17.21 3,16.88 3,16.5V7.5C3,7.12 3.21,6.79 3.53,6.62L11.43,2.18C11.59,2.06 11.79,2 12,2C12.21,2 12.41,2.06 12.57,2.18L20.47,6.62C20.79,6.79 21,7.12 21,7.5V16.5M12,4.15L10.11,5.22L16,8.61L17.96,7.5L12,4.15M6.04,7.5L12,10.85L13.96,9.75L8.08,6.35L6.04,7.5M5,15.91L11,19.29V12.58L5,9.21V15.91M19,15.91V9.21L13,12.58V19.29L19,15.91Z\" \/><\/svg>","module_icon\/parser.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M16,16.92C15.67,16.97 15.34,17 15,17C14.66,17 14.33,16.97 14,16.92V13.41L11.5,15.89C11,15.5 10.5,15 10.11,14.5L12.59,12H9.08C9.03,11.67 9,11.34 9,11C9,10.66 9.03,10.33 9.08,10H12.59L10.11,7.5C10.3,7.25 10.5,7 10.76,6.76V6.76C11,6.5 11.25,6.3 11.5,6.11L14,8.59V5.08C14.33,5.03 14.66,5 15,5C15.34,5 15.67,5.03 16,5.08V8.59L18.5,6.11C19,6.5 19.5,7 19.89,7.5L17.41,10H20.92C20.97,10.33 21,10.66 21,11C21,11.34 20.97,11.67 20.92,12H17.41L19.89,14.5C19.7,14.75 19.5,15 19.24,15.24V15.24C19,15.5 18.75,15.7 18.5,15.89L16,13.41V16.92H16V16.92M5,19A2,2 0 0,1 7,17A2,2 0 0,1 9,19A2,2 0 0,1 7,21A2,2 0 0,1 5,19H5Z\" \/><\/svg>","module_icon\/random.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M19 5V19H5V5H19M19 3H5C3.9 3 3 3.9 3 5V19C3 20.1 3.9 21 5 21H19C20.1 21 21 20.1 21 19V5C21 3.9 20.1 3 19 3M7.5 6C6.7 6 6 6.7 6 7.5S6.7 9 7.5 9 9 8.3 9 7.5 8.3 6 7.5 6M16.5 15C15.7 15 15 15.7 15 16.5C15 17.3 15.7 18 16.5 18C17.3 18 18 17.3 18 16.5C18 15.7 17.3 15 16.5 15M16.5 6C15.7 6 15 6.7 15 7.5S15.7 9 16.5 9C17.3 9 18 8.3 18 7.5S17.3 6 16.5 6M12 10.5C11.2 10.5 10.5 11.2 10.5 12S11.2 13.5 12 13.5 13.5 12.8 13.5 12 12.8 10.5 12 10.5M7.5 15C6.7 15 6 15.7 6 16.5C6 17.3 6.7 18 7.5 18S9 17.3 9 16.5C9 15.7 8.3 15 7.5 15Z\" \/><\/svg>","module_icon\/sha.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M5.41,21L6.12,17H2.12L2.47,15H6.47L7.53,9H3.53L3.88,7H7.88L8.59,3H10.59L9.88,7H15.88L16.59,3H18.59L17.88,7H21.88L21.53,9H17.53L16.47,15H20.47L20.12,17H16.12L15.41,21H13.41L14.12,17H8.12L7.41,21H5.41M9.53,9L8.47,15H14.47L15.53,9H9.53Z\" \/><\/svg>","trash-can.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,3V4H4V6H5V19A2,2 0 0,0 7,21H17A2,2 0 0,0 19,19V6H20V4H15V3H9M9,8H11V17H9V8M13,8H15V17H13V8Z\" \/><\/svg>","type_icon\/filled\/macro.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,7A2,2 0 0,0 7,9V17H9V9H11V16H13V9H15V17H17V9A2,2 0 0,0 15,7H9M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3Z\" \/><\/svg>","type_icon\/filled\/struct.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M11,7A2,2 0 0,0 9,9V11A2,2 0 0,0 11,13H13V15H9V17H13A2,2 0 0,0 15,15V13A2,2 0 0,0 13,11H11V9H15V7H11M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3Z\" \/><\/svg>","type_icon\/filled\/type.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,7V9H11V17H13V9H15V7H9M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3Z\" \/><\/svg>","type_icon\/fn.svg":"<svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" width=\"400\" height=\"400\" viewBox=\"0, 0, 400,400\"><g><path d=\"M268.810 9.762 C 268.810 9.893,268.217 10.000,267.493 10.000 C 266.542 10.000,266.137 10.099,266.038 10.357 C 265.938 10.618,265.527 10.714,264.510 10.714 C 263.596 10.714,263.054 10.824,262.928 11.035 C 262.824 11.212,262.310 11.424,261.788 11.506 C 261.265 11.588,260.801 11.765,260.756 11.899 C 260.711 12.033,260.359 12.143,259.973 12.143 C 259.568 12.143,259.213 12.294,259.134 12.500 C 259.058 12.696,258.737 12.857,258.419 12.857 C 258.102 12.857,257.781 13.018,257.705 13.214 C 257.627 13.418,257.272 13.571,256.879 13.571 C 256.500 13.571,255.976 13.786,255.714 14.048 C 255.452 14.310,255.077 14.524,254.881 14.524 C 254.685 14.524,254.524 14.685,254.524 14.881 C 254.524 15.104,254.298 15.238,253.921 15.238 C 253.590 15.238,253.260 15.389,253.190 15.574 C 253.119 15.758,252.801 15.975,252.483 16.054 C 252.165 16.134,251.905 16.305,251.905 16.433 C 251.905 16.562,251.690 16.667,251.429 16.667 C 251.164 16.667,250.952 16.825,250.952 17.024 C 250.952 17.237,250.733 17.381,250.410 17.381 C 250.112 17.381,249.701 17.568,249.497 17.798 C 249.294 18.027,248.680 18.582,248.135 19.030 C 247.589 19.479,247.143 19.977,247.143 20.136 C 247.143 20.295,246.875 20.492,246.548 20.574 C 246.220 20.656,245.952 20.828,245.952 20.957 C 245.952 21.085,245.788 21.190,245.588 21.190 C 245.387 21.190,245.161 21.351,245.086 21.548 C 245.011 21.744,244.800 21.905,244.617 21.905 C 244.435 21.905,244.286 22.065,244.286 22.262 C 244.286 22.458,244.169 22.619,244.026 22.619 C 243.884 22.619,243.028 23.396,242.124 24.345 C 241.220 25.295,240.158 26.404,239.764 26.811 C 239.370 27.218,239.048 27.674,239.048 27.823 C 239.048 27.973,238.943 28.095,238.814 28.095 C 238.686 28.095,238.513 28.363,238.431 28.690 C 238.349 29.018,238.159 29.288,238.010 29.290 C 237.722 29.294,236.667 30.312,236.667 30.586 C 236.667 30.675,236.506 30.909,236.310 31.105 C 236.113 31.302,235.952 31.669,235.952 31.922 C 235.952 32.174,235.792 32.381,235.595 32.381 C 235.399 32.381,235.238 32.542,235.238 32.738 C 235.238 32.935,235.077 33.095,234.881 33.095 C 234.685 33.095,234.524 33.244,234.524 33.427 C 234.524 33.609,234.363 33.820,234.167 33.896 C 233.970 33.971,233.810 34.304,233.810 34.635 C 233.810 35.012,233.676 35.238,233.452 35.238 C 233.254 35.238,233.095 35.450,233.095 35.714 C 233.095 35.979,232.937 36.190,232.738 36.190 C 232.542 36.190,232.381 36.393,232.381 36.641 C 232.381 36.890,232.058 37.438,231.664 37.860 C 231.270 38.282,230.885 38.875,230.809 39.177 C 230.733 39.480,230.520 39.785,230.336 39.856 C 230.151 39.927,230.000 40.256,230.000 40.588 C 230.000 40.965,229.866 41.190,229.643 41.190 C 229.421 41.190,229.286 41.415,229.286 41.786 C 229.286 42.113,229.181 42.381,229.052 42.381 C 228.924 42.381,228.753 42.641,228.674 42.959 C 228.594 43.277,228.377 43.595,228.193 43.666 C 228.008 43.737,227.857 44.066,227.857 44.397 C 227.857 44.774,227.723 45.000,227.500 45.000 C 227.262 45.000,227.143 45.238,227.143 45.714 C 227.143 46.190,227.024 46.429,226.786 46.429 C 226.549 46.429,226.429 46.665,226.429 47.127 C 226.429 47.616,226.286 47.870,225.952 47.976 C 225.657 48.070,225.476 48.336,225.476 48.677 C 225.476 48.980,225.315 49.361,225.119 49.524 C 224.923 49.687,224.762 50.063,224.762 50.361 C 224.762 50.658,224.601 50.963,224.405 51.038 C 224.208 51.114,224.048 51.435,224.048 51.753 C 224.048 52.070,223.887 52.392,223.690 52.467 C 223.494 52.542,223.333 52.883,223.333 53.224 C 223.333 53.565,223.173 54.004,222.976 54.201 C 222.780 54.397,222.619 54.925,222.619 55.374 C 222.619 55.941,222.510 56.190,222.262 56.190 C 222.027 56.190,221.905 56.426,221.905 56.879 C 221.905 57.272,221.751 57.627,221.548 57.705 C 221.314 57.795,221.190 58.166,221.190 58.777 C 221.190 59.387,221.067 59.758,220.833 59.848 C 220.637 59.923,220.476 60.203,220.476 60.469 C 220.476 60.735,220.262 61.167,220.000 61.429 C 219.711 61.718,219.524 62.222,219.524 62.713 C 219.524 63.211,219.387 63.573,219.167 63.658 C 218.970 63.733,218.810 64.020,218.810 64.295 C 218.810 64.571,218.649 64.957,218.452 65.153 C 218.256 65.349,218.095 65.866,218.095 66.301 C 218.095 66.784,217.956 67.145,217.738 67.229 C 217.495 67.322,217.381 67.703,217.381 68.419 C 217.381 69.136,217.267 69.517,217.024 69.610 C 216.818 69.689,216.667 70.045,216.667 70.449 C 216.667 70.835,216.553 71.189,216.413 71.235 C 216.274 71.282,216.096 71.798,216.017 72.382 C 215.939 72.967,215.731 73.588,215.556 73.763 C 215.381 73.938,215.238 74.438,215.238 74.872 C 215.238 75.356,215.099 75.717,214.881 75.800 C 214.657 75.886,214.524 76.250,214.524 76.778 C 214.524 77.302,214.344 77.799,214.048 78.095 C 213.763 78.380,213.571 78.889,213.571 79.359 C 213.571 79.793,213.414 80.355,213.222 80.609 C 213.030 80.863,212.869 81.427,212.865 81.862 C 212.861 82.297,212.696 82.814,212.500 83.010 C 212.304 83.207,212.143 83.777,212.143 84.277 C 212.143 84.866,212.017 85.235,211.786 85.324 C 211.542 85.418,211.429 85.799,211.429 86.520 C 211.429 87.103,211.311 87.619,211.167 87.667 C 211.023 87.714,210.847 88.286,210.776 88.936 C 210.705 89.587,210.501 90.205,210.324 90.309 C 210.130 90.423,210.000 90.915,210.000 91.534 C 210.000 92.234,209.884 92.612,209.643 92.705 C 209.386 92.804,209.286 93.205,209.286 94.134 C 209.286 95.062,209.185 95.464,208.929 95.562 C 208.667 95.663,208.571 96.075,208.571 97.108 C 208.571 98.316,208.504 98.534,208.095 98.640 C 207.692 98.746,207.619 98.965,207.619 100.071 C 207.619 101.013,207.519 101.416,207.262 101.515 C 207.011 101.611,206.905 102.002,206.905 102.830 C 206.905 103.492,206.787 104.047,206.636 104.097 C 206.489 104.147,206.312 104.768,206.244 105.479 C 206.176 106.190,205.975 106.916,205.798 107.093 C 205.617 107.275,205.476 107.916,205.476 108.563 C 205.476 109.364,205.368 109.752,205.119 109.848 C 204.866 109.945,204.762 110.340,204.762 111.200 C 204.762 111.963,204.629 112.548,204.405 112.772 C 204.175 113.002,204.048 113.590,204.048 114.422 C 204.048 115.412,203.964 115.714,203.690 115.714 C 203.413 115.714,203.333 116.029,203.333 117.117 C 203.333 118.145,203.238 118.557,202.976 118.658 C 202.714 118.758,202.619 119.171,202.619 120.203 C 202.619 121.411,202.551 121.629,202.143 121.736 C 201.758 121.836,201.667 122.060,201.667 122.908 C 201.667 123.485,201.509 124.165,201.317 124.419 C 201.125 124.673,200.964 125.344,200.960 125.910 C 200.956 126.498,200.799 127.092,200.595 127.296 C 200.384 127.508,200.238 128.090,200.238 128.724 C 200.238 129.359,200.093 129.941,199.881 130.153 C 199.662 130.372,199.524 130.955,199.524 131.658 C 199.524 132.459,199.416 132.848,199.167 132.943 C 198.910 133.042,198.810 133.443,198.810 134.372 C 198.810 135.300,198.709 135.702,198.452 135.800 C 198.256 135.876,198.095 136.209,198.095 136.540 L 198.095 137.143 167.731 137.143 C 140.959 137.143,137.350 137.185,137.229 137.500 C 137.136 137.743,136.755 137.857,136.038 137.857 C 135.322 137.857,134.941 137.971,134.848 138.214 C 134.773 138.411,134.462 138.571,134.157 138.571 C 133.813 138.571,133.546 138.751,133.452 139.048 C 133.355 139.354,133.092 139.524,132.715 139.524 C 132.392 139.524,132.066 139.685,131.991 139.881 C 131.915 140.077,131.705 140.238,131.522 140.238 C 131.340 140.238,131.190 140.399,131.190 140.595 C 131.190 140.792,131.072 140.952,130.927 140.952 C 130.598 140.952,128.095 143.432,128.095 143.758 C 128.095 143.889,127.935 144.058,127.738 144.134 C 127.542 144.209,127.381 144.531,127.381 144.848 C 127.381 145.165,127.220 145.487,127.024 145.562 C 126.827 145.638,126.667 145.971,126.667 146.302 C 126.667 146.679,126.533 146.905,126.310 146.905 C 126.046 146.905,125.952 147.180,125.952 147.951 C 125.952 148.661,125.838 149.041,125.595 149.134 C 125.295 149.249,125.238 150.007,125.238 153.921 C 125.238 157.896,125.290 158.571,125.595 158.571 C 125.860 158.571,125.952 158.850,125.952 159.650 C 125.952 160.390,126.065 160.772,126.310 160.866 C 126.506 160.942,126.667 161.263,126.667 161.581 C 126.667 161.898,126.827 162.219,127.024 162.295 C 127.220 162.370,127.381 162.692,127.381 163.009 C 127.381 163.327,127.542 163.648,127.738 163.723 C 127.935 163.799,128.095 164.010,128.095 164.192 C 128.095 164.375,128.256 164.524,128.452 164.524 C 128.649 164.524,128.810 164.685,128.810 164.881 C 128.810 165.077,128.970 165.238,129.167 165.238 C 129.363 165.238,129.526 165.372,129.528 165.536 C 129.532 165.862,130.539 166.899,130.867 166.915 C 130.979 166.920,131.334 167.242,131.655 167.629 C 131.977 168.017,132.474 168.333,132.761 168.333 C 133.048 168.333,133.344 168.494,133.419 168.690 C 133.495 168.887,133.816 169.048,134.134 169.048 C 134.451 169.048,134.773 169.208,134.848 169.405 C 134.942 169.650,135.325 169.762,136.064 169.762 C 136.864 169.762,137.143 169.854,137.143 170.119 C 137.143 170.434,140.225 170.476,163.452 170.476 L 189.762 170.476 189.762 171.052 C 189.762 171.368,189.634 171.670,189.478 171.721 C 189.310 171.778,189.153 172.484,189.093 173.468 C 189.027 174.530,188.873 175.187,188.662 175.309 C 188.447 175.434,188.333 175.941,188.333 176.772 C 188.333 177.683,188.232 178.083,187.976 178.181 C 187.714 178.282,187.619 178.695,187.619 179.729 C 187.619 180.763,187.524 181.176,187.262 181.277 C 187.005 181.375,186.905 181.777,186.905 182.705 C 186.905 183.634,186.804 184.035,186.548 184.134 C 186.285 184.235,186.190 184.650,186.190 185.707 C 186.190 186.825,186.111 187.143,185.833 187.143 C 185.556 187.143,185.476 187.457,185.476 188.546 C 185.476 189.574,185.381 189.986,185.119 190.086 C 184.861 190.185,184.762 190.589,184.762 191.540 C 184.762 192.540,184.647 192.972,184.286 193.333 C 183.939 193.680,183.810 194.127,183.810 194.980 C 183.810 195.651,183.693 196.190,183.535 196.242 C 183.385 196.292,183.210 196.971,183.146 197.750 C 183.083 198.529,182.924 199.236,182.793 199.320 C 182.661 199.404,182.500 200.047,182.434 200.748 C 182.369 201.450,182.200 202.098,182.059 202.188 C 181.918 202.279,181.760 203.109,181.708 204.034 C 181.638 205.262,181.524 205.714,181.283 205.714 C 181.038 205.714,180.952 206.080,180.952 207.117 C 180.952 208.145,180.857 208.557,180.595 208.658 C 180.332 208.758,180.238 209.174,180.238 210.231 C 180.238 211.348,180.159 211.667,179.881 211.667 C 179.604 211.667,179.524 211.981,179.524 213.070 C 179.524 214.097,179.428 214.510,179.167 214.610 C 178.909 214.709,178.810 215.113,178.810 216.064 C 178.810 217.063,178.695 217.496,178.333 217.857 C 177.986 218.204,177.857 218.651,177.857 219.504 C 177.857 220.148,177.739 220.714,177.596 220.762 C 177.452 220.810,177.282 221.381,177.217 222.032 C 177.153 222.682,176.949 223.552,176.765 223.965 C 176.580 224.377,176.429 225.145,176.429 225.671 C 176.429 226.197,176.305 226.668,176.154 226.718 C 176.004 226.769,175.829 227.447,175.765 228.226 C 175.702 229.005,175.538 229.715,175.401 229.803 C 175.264 229.890,175.105 230.640,175.046 231.469 C 174.981 232.401,174.815 233.049,174.613 233.167 C 174.393 233.294,174.286 233.823,174.286 234.774 C 174.286 235.874,174.206 236.190,173.929 236.190 C 173.652 236.190,173.571 236.505,173.571 237.594 C 173.571 238.621,173.476 239.033,173.214 239.134 C 172.952 239.234,172.857 239.648,172.857 240.691 C 172.857 241.902,172.787 242.133,172.381 242.262 C 171.987 242.387,171.903 242.626,171.897 243.647 C 171.893 244.352,171.740 245.079,171.540 245.343 C 171.348 245.597,171.187 246.294,171.183 246.891 C 171.179 247.488,171.018 248.184,170.826 248.438 C 170.633 248.693,170.476 249.370,170.476 249.943 C 170.476 250.553,170.328 251.135,170.119 251.344 C 169.897 251.566,169.762 252.150,169.762 252.891 C 169.762 253.632,169.627 254.217,169.405 254.439 C 169.186 254.658,169.048 255.242,169.048 255.950 C 169.048 256.608,168.930 257.142,168.774 257.195 C 168.623 257.245,168.447 257.919,168.383 258.694 C 168.318 259.468,168.120 260.247,167.943 260.425 C 167.744 260.623,167.619 261.284,167.619 262.134 C 167.619 263.147,167.523 263.557,167.262 263.658 C 167.000 263.758,166.905 264.172,166.905 265.215 C 166.905 266.425,166.835 266.657,166.429 266.786 C 166.031 266.912,165.952 267.146,165.952 268.201 C 165.952 269.035,165.831 269.567,165.595 269.762 C 165.366 269.952,165.238 270.480,165.238 271.237 C 165.238 271.967,165.102 272.551,164.881 272.772 C 164.653 273.000,164.524 273.587,164.524 274.396 C 164.524 275.303,164.422 275.702,164.167 275.800 C 163.910 275.899,163.810 276.301,163.810 277.229 C 163.810 278.157,163.709 278.559,163.452 278.658 C 163.190 278.758,163.095 279.172,163.095 280.211 C 163.095 281.067,162.987 281.663,162.821 281.718 C 162.670 281.769,162.496 282.447,162.433 283.226 C 162.365 284.069,162.187 284.720,161.993 284.833 C 161.779 284.958,161.667 285.477,161.667 286.338 C 161.667 287.190,161.541 287.779,161.310 288.010 C 161.074 288.246,160.952 288.839,160.952 289.751 C 160.952 290.935,160.883 291.153,160.476 291.259 C 160.067 291.366,160.000 291.584,160.000 292.809 C 160.000 293.857,159.905 294.271,159.643 294.372 C 159.390 294.469,159.286 294.864,159.286 295.724 C 159.286 296.486,159.153 297.072,158.929 297.296 C 158.701 297.524,158.571 298.111,158.571 298.920 C 158.571 299.827,158.470 300.226,158.214 300.324 C 157.958 300.423,157.857 300.824,157.857 301.753 C 157.857 302.681,157.757 303.083,157.500 303.181 C 157.238 303.282,157.143 303.695,157.143 304.729 C 157.143 305.763,157.048 306.176,156.786 306.277 C 156.529 306.375,156.429 306.777,156.429 307.705 C 156.429 308.634,156.328 309.035,156.071 309.134 C 155.810 309.234,155.714 309.647,155.714 310.681 C 155.714 311.716,155.619 312.128,155.357 312.229 C 155.099 312.328,155.000 312.733,155.000 313.693 C 155.000 314.691,154.882 315.147,154.524 315.531 C 154.190 315.889,154.048 316.371,154.048 317.142 C 154.048 317.747,153.890 318.450,153.698 318.704 C 153.499 318.968,153.345 319.694,153.341 320.391 C 153.336 321.255,153.228 321.656,152.976 321.753 C 152.714 321.853,152.619 322.266,152.619 323.300 C 152.619 324.335,152.524 324.748,152.262 324.848 C 152.005 324.947,151.905 325.348,151.905 326.277 C 151.905 327.205,151.804 327.607,151.548 327.705 C 151.286 327.806,151.190 328.219,151.190 329.253 C 151.190 330.287,151.095 330.700,150.833 330.800 C 150.570 330.901,150.476 331.317,150.476 332.373 C 150.476 333.491,150.397 333.810,150.119 333.810 C 149.841 333.810,149.762 334.127,149.762 335.238 C 149.762 336.349,149.683 336.667,149.405 336.667 C 149.142 336.667,149.048 336.941,149.048 337.710 C 149.048 338.554,148.956 338.778,148.571 338.879 C 148.257 338.961,148.095 339.203,148.095 339.591 C 148.095 339.915,147.935 340.313,147.738 340.476 C 147.542 340.639,147.381 341.016,147.381 341.313 C 147.381 341.611,147.220 341.915,147.024 341.991 C 146.827 342.066,146.667 342.388,146.667 342.705 C 146.667 343.023,146.506 343.344,146.310 343.419 C 146.113 343.495,145.952 343.816,145.952 344.134 C 145.952 344.451,145.792 344.773,145.595 344.848 C 145.399 344.923,145.238 345.149,145.238 345.350 C 145.238 345.550,145.133 345.714,145.005 345.714 C 144.876 345.714,144.706 345.974,144.626 346.292 C 144.546 346.610,144.330 346.928,144.145 346.999 C 143.961 347.070,143.810 347.346,143.810 347.612 C 143.810 347.878,143.704 348.095,143.576 348.095 C 143.448 348.095,143.275 348.363,143.193 348.690 C 143.111 349.018,142.937 349.286,142.808 349.286 C 142.484 349.286,138.571 353.222,138.571 353.548 C 138.571 353.692,138.411 353.810,138.214 353.810 C 138.018 353.810,137.857 353.970,137.857 354.167 C 137.857 354.406,137.618 354.524,137.135 354.524 C 136.713 354.524,136.357 354.672,136.277 354.881 C 136.201 355.077,135.880 355.238,135.562 355.238 C 135.245 355.238,134.923 355.399,134.848 355.595 C 134.773 355.792,134.451 355.952,134.134 355.952 C 133.816 355.952,133.495 356.113,133.419 356.310 C 133.328 356.549,132.952 356.667,132.282 356.667 C 131.732 356.667,131.074 356.824,130.819 357.016 C 130.258 357.441,127.229 357.521,127.094 357.115 C 127.044 356.966,126.221 356.794,125.229 356.724 C 124.252 356.656,123.390 356.504,123.314 356.387 C 123.238 356.270,122.756 356.108,122.243 356.027 C 121.729 355.946,121.224 355.736,121.119 355.559 C 121.014 355.383,120.613 355.238,120.226 355.238 C 119.761 355.238,119.524 355.118,119.524 354.881 C 119.524 354.663,119.302 354.524,118.954 354.524 C 118.641 354.524,118.323 354.363,118.247 354.167 C 118.172 353.970,117.846 353.810,117.524 353.810 C 117.171 353.810,116.883 353.641,116.803 353.387 C 116.729 353.155,116.187 352.753,115.599 352.494 C 115.010 352.236,114.527 351.890,114.526 351.726 C 114.525 351.563,114.363 351.429,114.167 351.429 C 113.970 351.429,113.810 351.268,113.810 351.071 C 113.810 350.875,113.707 350.714,113.583 350.714 C 113.287 350.714,110.952 348.379,110.952 348.084 C 110.952 347.959,110.792 347.857,110.595 347.857 C 110.399 347.857,110.238 347.697,110.238 347.502 C 110.238 347.307,110.024 347.013,109.762 346.850 C 109.500 346.686,109.286 346.360,109.286 346.126 C 109.286 345.891,109.125 345.638,108.929 345.562 C 108.732 345.487,108.571 345.276,108.571 345.094 C 108.571 344.911,108.411 344.762,108.214 344.762 C 108.018 344.762,107.857 344.601,107.857 344.405 C 107.857 344.208,107.696 344.048,107.500 344.048 C 107.304 344.048,107.143 343.841,107.143 343.588 C 107.143 343.336,106.982 342.969,106.786 342.772 C 106.589 342.576,106.429 342.300,106.429 342.160 C 106.429 342.020,106.268 341.905,106.071 341.905 C 105.835 341.905,105.714 341.668,105.714 341.202 C 105.714 340.816,105.580 340.414,105.417 340.309 C 105.253 340.205,104.906 339.700,104.645 339.189 C 104.384 338.677,103.982 338.209,103.752 338.149 C 103.475 338.077,103.333 337.808,103.333 337.353 C 103.333 336.902,103.211 336.667,102.976 336.667 C 102.726 336.667,102.619 336.415,102.619 335.826 C 102.619 335.298,102.486 334.934,102.262 334.848 C 102.065 334.773,101.905 334.462,101.905 334.158 C 101.905 333.854,101.744 333.445,101.548 333.248 C 101.351 333.052,101.190 332.621,101.190 332.291 C 101.190 331.961,101.046 331.605,100.869 331.500 C 100.693 331.395,100.481 330.882,100.399 330.359 C 100.317 329.836,100.140 329.372,100.006 329.327 C 99.872 329.283,99.762 328.930,99.762 328.544 C 99.762 328.140,99.610 327.784,99.405 327.705 C 99.208 327.630,99.048 327.321,99.048 327.018 C 99.048 326.358,97.926 324.048,97.607 324.048 C 97.482 324.048,97.381 323.833,97.381 323.571 C 97.381 323.307,97.222 323.095,97.024 323.095 C 96.802 323.095,96.667 322.870,96.667 322.500 C 96.667 322.130,96.532 321.905,96.310 321.905 C 96.113 321.905,95.952 321.807,95.952 321.687 C 95.952 321.221,94.120 319.524,93.617 319.524 C 93.312 319.524,93.095 319.376,93.095 319.167 C 93.095 318.970,92.946 318.810,92.764 318.810 C 92.581 318.810,92.370 318.649,92.295 318.452 C 92.216 318.248,91.861 318.095,91.464 318.095 C 90.970 318.095,90.734 317.958,90.645 317.619 C 90.556 317.276,90.321 317.143,89.804 317.143 C 89.410 317.143,89.044 317.014,88.992 316.855 C 88.933 316.679,88.233 316.531,87.186 316.471 C 86.246 316.418,85.476 316.289,85.476 316.184 C 85.476 315.760,81.911 315.635,81.460 316.043 C 81.156 316.318,80.575 316.429,79.438 316.429 C 78.239 316.429,77.808 316.517,77.705 316.786 C 77.627 316.989,77.272 317.143,76.881 317.143 C 76.452 317.143,76.083 317.322,75.897 317.619 C 75.734 317.881,75.358 318.095,75.062 318.095 C 74.742 318.095,74.524 318.240,74.524 318.452 C 74.524 318.676,74.298 318.810,73.921 318.810 C 73.590 318.810,73.257 318.970,73.181 319.167 C 73.106 319.363,72.895 319.524,72.713 319.524 C 72.530 319.524,72.381 319.685,72.381 319.881 C 72.381 320.077,72.220 320.238,72.024 320.238 C 71.827 320.238,71.667 320.399,71.667 320.595 C 71.667 320.792,71.547 320.952,71.401 320.952 C 71.054 320.952,69.286 322.721,69.286 323.067 C 69.286 323.214,69.187 323.333,69.067 323.333 C 68.946 323.333,68.777 323.655,68.690 324.048 C 68.604 324.440,68.381 324.762,68.195 324.762 C 67.981 324.762,67.857 325.014,67.857 325.451 C 67.857 325.843,67.704 326.198,67.500 326.277 C 67.255 326.370,67.143 326.753,67.143 327.493 C 67.143 328.086,67.036 328.571,66.905 328.571 C 66.755 328.571,66.667 330.159,66.667 332.857 C 66.667 335.556,66.755 337.143,66.905 337.143 C 67.036 337.143,67.143 337.628,67.143 338.222 C 67.143 338.961,67.255 339.344,67.500 339.438 C 67.734 339.527,67.857 339.898,67.857 340.509 C 67.857 341.120,67.981 341.491,68.214 341.581 C 68.448 341.670,68.571 342.041,68.571 342.652 C 68.571 343.263,68.695 343.634,68.929 343.723 C 69.143 343.806,69.286 344.165,69.286 344.623 C 69.286 345.042,69.443 345.593,69.635 345.847 C 69.828 346.102,69.988 346.554,69.992 346.853 C 69.997 347.151,70.161 347.458,70.357 347.533 C 70.554 347.608,70.714 347.936,70.714 348.262 C 70.714 348.654,70.875 348.896,71.190 348.979 C 71.529 349.067,71.667 349.303,71.667 349.797 C 71.667 350.194,71.819 350.550,72.024 350.628 C 72.220 350.704,72.381 351.025,72.381 351.342 C 72.381 351.660,72.542 351.981,72.738 352.057 C 72.939 352.134,73.095 352.488,73.095 352.866 C 73.095 353.235,73.256 353.698,73.452 353.895 C 73.649 354.091,73.810 354.420,73.810 354.626 C 73.810 354.832,73.970 355.000,74.167 355.000 C 74.383 355.000,74.524 355.221,74.524 355.559 C 74.524 355.866,74.738 356.365,75.000 356.667 C 75.262 356.969,75.476 357.360,75.476 357.536 C 75.476 357.713,75.583 357.857,75.714 357.857 C 75.845 357.857,75.952 358.021,75.952 358.222 C 75.952 358.422,76.113 358.648,76.310 358.723 C 76.506 358.799,76.667 359.062,76.667 359.309 C 76.667 359.556,76.881 359.892,77.143 360.055 C 77.405 360.219,77.619 360.488,77.619 360.653 C 77.619 360.817,77.780 360.952,77.976 360.952 C 78.215 360.952,78.333 361.191,78.333 361.674 C 78.333 362.076,78.482 362.453,78.669 362.525 C 78.854 362.596,79.070 362.914,79.150 363.232 C 79.230 363.549,79.400 363.810,79.528 363.810 C 79.657 363.810,79.762 363.974,79.762 364.174 C 79.762 364.375,79.923 364.600,80.119 364.676 C 80.315 364.751,80.476 364.962,80.476 365.145 C 80.476 365.327,80.625 365.476,80.808 365.476 C 80.990 365.476,81.204 365.737,81.284 366.055 C 81.364 366.373,81.911 367.136,82.500 367.751 C 83.089 368.366,83.571 368.963,83.571 369.077 C 83.571 369.192,83.732 369.286,83.929 369.286 C 84.125 369.286,84.286 369.446,84.286 369.643 C 84.286 369.839,84.435 370.000,84.617 370.000 C 84.799 370.000,85.016 370.268,85.098 370.595 C 85.180 370.923,85.352 371.190,85.481 371.190 C 85.609 371.190,85.714 371.309,85.714 371.455 C 85.714 371.820,86.720 372.848,87.083 372.853 C 87.247 372.855,87.381 373.018,87.381 373.214 C 87.381 373.411,87.542 373.571,87.738 373.571 C 87.935 373.571,88.095 373.679,88.095 373.810 C 88.095 374.118,88.977 375.000,89.286 375.000 C 89.417 375.000,89.524 375.161,89.524 375.357 C 89.524 375.554,89.631 375.714,89.762 375.714 C 89.893 375.714,90.214 375.929,90.476 376.190 C 90.738 376.452,91.113 376.667,91.310 376.667 C 91.506 376.667,91.667 376.827,91.667 377.024 C 91.667 377.220,91.827 377.381,92.024 377.381 C 92.220 377.381,92.381 377.542,92.381 377.738 C 92.381 377.935,92.515 378.100,92.679 378.105 C 92.842 378.111,93.239 378.432,93.560 378.820 C 93.881 379.207,94.313 379.524,94.520 379.524 C 94.726 379.524,95.049 379.738,95.238 380.000 C 95.427 380.262,95.707 380.476,95.860 380.476 C 96.014 380.476,96.201 380.637,96.277 380.833 C 96.352 381.030,96.578 381.190,96.778 381.190 C 96.979 381.190,97.143 381.296,97.143 381.424 C 97.143 381.552,97.403 381.723,97.721 381.803 C 98.039 381.882,98.357 382.099,98.428 382.283 C 98.499 382.468,98.721 382.619,98.921 382.619 C 99.122 382.619,99.286 382.726,99.286 382.857 C 99.286 382.988,99.432 383.095,99.611 383.095 C 99.790 383.095,100.208 383.310,100.541 383.571 C 100.874 383.833,101.371 384.048,101.645 384.048 C 101.929 384.048,102.143 384.201,102.143 384.405 C 102.143 384.643,102.381 384.762,102.857 384.762 C 103.333 384.762,103.571 384.881,103.571 385.119 C 103.571 385.355,103.808 385.476,104.270 385.476 C 104.759 385.476,105.013 385.619,105.119 385.952 C 105.225 386.286,105.479 386.429,105.968 386.429 C 106.352 386.429,106.667 386.531,106.667 386.656 C 106.667 386.781,107.042 386.954,107.500 387.040 C 107.958 387.126,108.333 387.290,108.333 387.405 C 108.333 387.519,108.771 387.683,109.306 387.769 C 109.841 387.855,110.335 388.070,110.403 388.248 C 110.482 388.454,110.914 388.571,111.590 388.571 C 112.217 388.571,112.799 388.718,113.010 388.929 C 113.217 389.136,113.799 389.286,114.396 389.286 C 115.091 389.286,115.470 389.402,115.562 389.643 C 115.668 389.919,116.131 390.000,117.612 390.000 C 118.728 390.000,119.524 390.099,119.524 390.238 C 119.524 390.393,122.659 390.476,128.452 390.476 C 133.516 390.476,137.381 390.384,137.381 390.264 C 137.381 390.147,138.203 390.011,139.209 389.960 C 140.365 389.901,141.072 389.761,141.133 389.577 C 141.190 389.406,141.667 389.286,142.289 389.286 C 143.011 389.286,143.392 389.172,143.485 388.929 C 143.579 388.686,143.959 388.571,144.676 388.571 C 145.353 388.571,145.774 388.454,145.856 388.242 C 145.925 388.061,146.404 387.846,146.919 387.763 C 147.435 387.681,147.857 387.508,147.857 387.378 C 147.857 387.249,148.182 387.143,148.579 387.143 C 149.001 387.143,149.358 386.994,149.438 386.786 C 149.513 386.589,149.841 386.429,150.167 386.429 C 150.559 386.429,150.801 386.268,150.883 385.952 C 150.972 385.614,151.208 385.476,151.702 385.476 C 152.099 385.476,152.454 385.323,152.533 385.119 C 152.608 384.923,152.930 384.762,153.247 384.762 C 153.565 384.762,153.886 384.601,153.962 384.405 C 154.037 384.208,154.248 384.048,154.430 384.048 C 154.613 384.048,154.762 383.887,154.762 383.690 C 154.762 383.467,154.988 383.333,155.365 383.333 C 155.696 383.333,156.029 383.173,156.104 382.976 C 156.180 382.780,156.391 382.619,156.573 382.619 C 156.756 382.619,156.905 382.458,156.905 382.262 C 156.905 382.050,157.123 381.905,157.440 381.904 C 158.005 381.904,160.000 380.296,160.000 379.841 C 160.000 379.695,160.268 379.508,160.595 379.426 C 160.923 379.344,161.190 379.172,161.190 379.043 C 161.190 378.915,161.405 378.810,161.667 378.810 C 161.929 378.810,162.148 378.676,162.154 378.512 C 162.160 378.348,162.438 378.000,162.772 377.738 C 163.977 376.794,165.952 374.838,165.952 374.590 C 165.952 374.451,166.113 374.275,166.310 374.200 C 166.506 374.124,166.667 373.898,166.667 373.698 C 166.667 373.497,166.772 373.333,166.900 373.333 C 167.029 373.333,167.201 373.065,167.283 372.738 C 167.365 372.411,167.582 372.143,167.764 372.143 C 167.946 372.143,168.095 371.982,168.095 371.786 C 168.095 371.589,168.256 371.429,168.452 371.429 C 168.649 371.429,168.810 371.331,168.810 371.211 C 168.810 371.091,169.158 370.621,169.583 370.166 C 170.684 368.989,171.190 368.284,171.190 367.928 C 171.190 367.758,171.351 367.619,171.548 367.619 C 171.744 367.619,171.905 367.458,171.905 367.262 C 171.905 367.065,172.003 366.905,172.124 366.905 C 172.244 366.905,172.412 366.592,172.496 366.210 C 172.580 365.828,172.802 365.457,172.991 365.385 C 173.179 365.312,173.333 365.089,173.333 364.888 C 173.333 364.688,173.438 364.524,173.567 364.524 C 173.695 364.524,173.866 364.264,173.946 363.946 C 174.025 363.628,174.242 363.310,174.426 363.239 C 174.613 363.167,174.762 362.790,174.762 362.388 C 174.762 361.825,174.867 361.667,175.238 361.667 C 175.503 361.667,175.714 361.508,175.714 361.310 C 175.714 361.113,175.813 360.952,175.933 360.952 C 176.054 360.952,176.223 360.631,176.310 360.238 C 176.396 359.845,176.557 359.524,176.667 359.524 C 176.777 359.524,176.942 359.182,177.034 358.763 C 177.126 358.345,177.349 357.856,177.529 357.675 C 177.709 357.495,177.857 357.140,177.857 356.888 C 177.857 356.635,177.956 356.429,178.076 356.429 C 178.197 356.429,178.371 356.086,178.462 355.668 C 178.554 355.250,178.777 354.760,178.958 354.580 C 179.138 354.399,179.286 353.938,179.286 353.554 C 179.286 353.093,179.407 352.857,179.643 352.857 C 179.883 352.857,180.000 352.617,180.000 352.126 C 180.000 351.724,180.161 351.234,180.357 351.037 C 180.554 350.841,180.714 350.366,180.714 349.983 C 180.714 349.599,180.929 349.071,181.190 348.810 C 181.452 348.548,181.667 348.021,181.667 347.639 C 181.667 347.257,181.790 346.903,181.941 346.853 C 182.092 346.803,182.266 346.124,182.329 345.345 C 182.397 344.502,182.575 343.852,182.769 343.738 C 182.981 343.615,183.095 343.101,183.095 342.276 C 183.095 341.364,183.197 340.964,183.452 340.866 C 183.714 340.766,183.810 340.353,183.810 339.319 C 183.810 338.284,183.905 337.872,184.167 337.771 C 184.425 337.672,184.524 337.266,184.524 336.300 C 184.524 335.432,184.648 334.841,184.881 334.609 C 185.100 334.390,185.238 333.807,185.238 333.104 C 185.238 332.303,185.346 331.914,185.595 331.819 C 185.854 331.719,185.952 331.314,185.952 330.348 C 185.952 329.479,186.077 328.889,186.310 328.656 C 186.531 328.435,186.667 327.850,186.667 327.116 C 186.667 326.262,186.799 325.790,187.143 325.421 C 187.493 325.046,187.619 324.581,187.619 323.671 C 187.619 322.789,187.722 322.392,187.976 322.295 C 188.238 322.194,188.333 321.781,188.333 320.747 C 188.333 319.713,188.429 319.300,188.690 319.200 C 188.947 319.101,189.048 318.699,189.048 317.771 C 189.048 316.843,189.148 316.441,189.405 316.342 C 189.667 316.242,189.762 315.829,189.762 314.795 C 189.762 313.761,189.857 313.348,190.119 313.247 C 190.381 313.147,190.476 312.734,190.476 311.700 C 190.476 310.665,190.571 310.252,190.833 310.152 C 191.090 310.053,191.190 309.652,191.190 308.723 C 191.190 307.795,191.291 307.393,191.548 307.295 C 191.809 307.194,191.905 306.781,191.905 305.747 C 191.905 304.713,192.000 304.300,192.262 304.200 C 192.520 304.100,192.619 303.695,192.619 302.736 C 192.619 301.738,192.737 301.282,193.095 300.898 C 193.412 300.558,193.571 300.057,193.571 299.405 C 193.571 298.866,193.729 298.216,193.921 297.962 C 194.130 297.686,194.274 296.958,194.278 296.156 C 194.284 295.187,194.385 294.775,194.643 294.676 C 194.900 294.577,195.000 294.176,195.000 293.247 C 195.000 292.319,195.100 291.917,195.357 291.819 C 195.619 291.718,195.714 291.305,195.714 290.271 C 195.714 289.237,195.810 288.824,196.071 288.723 C 196.328 288.625,196.429 288.223,196.429 287.295 C 196.429 286.366,196.529 285.965,196.786 285.866 C 197.048 285.766,197.143 285.353,197.143 284.319 C 197.143 283.284,197.238 282.872,197.500 282.771 C 197.763 282.670,197.857 282.255,197.857 281.198 C 197.857 280.080,197.936 279.762,198.214 279.762 C 198.490 279.762,198.571 279.454,198.571 278.419 C 198.571 277.452,198.680 276.997,198.960 276.792 C 199.202 276.615,199.393 276.024,199.469 275.219 C 199.536 274.509,199.699 273.858,199.833 273.772 C 199.967 273.686,200.127 272.989,200.189 272.224 C 200.251 271.459,200.412 270.763,200.546 270.677 C 200.681 270.591,200.842 269.898,200.905 269.138 C 200.968 268.378,201.165 267.610,201.343 267.432 C 201.542 267.234,201.667 266.573,201.667 265.723 C 201.667 264.710,201.763 264.300,202.024 264.200 C 202.277 264.103,202.381 263.708,202.381 262.848 C 202.381 262.085,202.514 261.500,202.738 261.276 C 202.966 261.048,203.095 260.460,203.095 259.651 C 203.095 258.745,203.197 258.345,203.452 258.247 C 203.709 258.149,203.810 257.747,203.810 256.819 C 203.810 255.890,203.910 255.489,204.167 255.390 C 204.425 255.291,204.524 254.887,204.524 253.936 C 204.524 252.937,204.639 252.504,205.000 252.143 C 205.347 251.796,205.476 251.349,205.476 250.496 C 205.476 249.825,205.593 249.286,205.750 249.234 C 205.901 249.184,206.076 248.505,206.139 247.726 C 206.203 246.947,206.362 246.241,206.493 246.156 C 206.624 246.072,206.786 245.429,206.851 244.728 C 206.917 244.026,207.080 243.382,207.214 243.296 C 207.348 243.210,207.509 242.517,207.572 241.757 C 207.635 240.997,207.832 240.229,208.010 240.051 C 208.215 239.846,208.333 239.170,208.333 238.197 C 208.333 236.995,208.410 236.667,208.690 236.667 C 208.968 236.667,209.048 236.349,209.048 235.238 C 209.048 234.127,209.127 233.810,209.405 233.810 C 209.686 233.810,209.762 233.479,209.762 232.262 C 209.762 231.045,209.838 230.714,210.119 230.714 C 210.395 230.714,210.476 230.403,210.476 229.343 C 210.476 228.230,210.566 227.916,210.952 227.674 C 211.327 227.441,211.429 227.119,211.429 226.171 C 211.429 225.417,211.562 224.832,211.786 224.609 C 212.005 224.390,212.143 223.806,212.143 223.098 C 212.143 222.440,212.261 221.905,212.417 221.853 C 212.568 221.803,212.742 221.124,212.805 220.345 C 212.873 219.502,213.051 218.852,213.245 218.738 C 213.459 218.613,213.571 218.095,213.571 217.233 C 213.571 216.382,213.697 215.792,213.929 215.561 C 214.151 215.339,214.286 214.754,214.286 214.014 C 214.286 213.273,214.421 212.688,214.643 212.466 C 214.862 212.247,215.000 211.663,215.000 210.955 C 215.000 210.266,215.116 209.763,215.287 209.706 C 215.463 209.647,215.612 208.947,215.671 207.900 C 215.742 206.647,215.856 206.190,216.098 206.190 C 216.343 206.190,216.429 205.824,216.429 204.778 C 216.429 203.575,216.499 203.343,216.905 203.214 C 217.309 203.086,217.381 202.854,217.381 201.676 C 217.381 200.663,217.477 200.252,217.738 200.152 C 217.991 200.055,218.095 199.660,218.095 198.800 C 218.095 198.037,218.228 197.452,218.452 197.228 C 218.680 197.000,218.810 196.413,218.810 195.604 C 218.810 194.697,218.911 194.298,219.167 194.200 C 219.429 194.099,219.524 193.686,219.524 192.652 C 219.524 191.618,219.619 191.205,219.881 191.104 C 220.138 191.006,220.238 190.604,220.238 189.670 C 220.238 188.903,220.350 188.336,220.512 188.282 C 220.663 188.231,220.838 187.553,220.900 186.774 C 220.968 185.931,221.146 185.280,221.341 185.167 C 221.554 185.042,221.667 184.523,221.667 183.662 C 221.667 182.810,221.793 182.221,222.024 181.990 C 222.245 181.769,222.381 181.185,222.381 180.459 C 222.381 179.814,222.488 179.286,222.619 179.286 C 222.750 179.286,222.857 179.125,222.857 178.929 C 222.857 178.732,222.964 178.571,223.095 178.571 C 223.227 178.571,223.333 177.945,223.333 177.168 C 223.333 176.141,223.429 175.729,223.690 175.628 C 223.943 175.531,224.048 175.136,224.048 174.276 C 224.048 173.514,224.181 172.928,224.405 172.704 C 224.601 172.508,224.762 171.926,224.762 171.412 L 224.762 170.476 250.722 170.476 C 273.578 170.476,276.698 170.433,276.819 170.119 C 276.908 169.886,277.279 169.762,277.890 169.762 C 278.501 169.762,278.872 169.638,278.962 169.405 C 279.037 169.208,279.358 169.048,279.676 169.048 C 279.993 169.048,280.315 168.887,280.390 168.690 C 280.465 168.494,280.760 168.333,281.044 168.333 C 281.328 168.333,281.738 168.146,281.955 167.917 C 282.171 167.688,282.784 167.126,283.317 166.669 C 283.850 166.211,284.286 165.703,284.286 165.538 C 284.286 165.373,284.446 165.238,284.643 165.238 C 284.839 165.238,285.000 165.077,285.000 164.881 C 285.000 164.685,285.161 164.524,285.357 164.524 C 285.554 164.524,285.714 164.375,285.714 164.192 C 285.714 164.010,285.875 163.799,286.071 163.723 C 286.268 163.648,286.429 163.315,286.429 162.984 C 286.429 162.607,286.562 162.381,286.786 162.381 C 287.021 162.381,287.143 162.146,287.143 161.692 C 287.143 161.300,287.296 160.944,287.500 160.866 C 287.743 160.773,287.857 160.393,287.857 159.678 C 287.857 158.827,287.948 158.603,288.333 158.502 C 288.788 158.384,288.810 158.178,288.810 153.953 C 288.810 149.786,288.782 149.511,288.333 149.230 C 287.978 149.009,287.857 148.675,287.857 147.919 C 287.857 147.176,287.762 146.905,287.500 146.905 C 287.262 146.905,287.143 146.667,287.143 146.190 C 287.143 145.714,287.024 145.476,286.786 145.476 C 286.562 145.476,286.429 145.250,286.429 144.873 C 286.429 144.542,286.268 144.209,286.071 144.134 C 285.875 144.058,285.714 143.844,285.714 143.658 C 285.714 143.471,285.554 143.257,285.357 143.181 C 285.161 143.106,285.000 142.895,285.000 142.713 C 285.000 142.530,284.891 142.381,284.758 142.381 C 284.625 142.381,284.054 141.899,283.489 141.310 C 282.925 140.720,282.349 140.238,282.209 140.238 C 282.070 140.238,281.894 140.077,281.819 139.881 C 281.743 139.685,281.418 139.524,281.095 139.524 C 280.717 139.524,280.454 139.354,280.357 139.048 C 280.263 138.751,279.997 138.571,279.652 138.571 C 279.348 138.571,279.037 138.411,278.962 138.214 C 278.872 137.981,278.501 137.857,277.894 137.857 C 277.357 137.857,276.838 137.706,276.667 137.500 C 276.407 137.188,273.633 137.139,254.554 137.115 C 242.555 137.100,232.926 137.039,233.155 136.979 C 233.491 136.891,233.571 136.604,233.571 135.484 C 233.571 134.472,233.668 134.062,233.929 133.962 C 234.186 133.863,234.286 133.460,234.286 132.524 C 234.286 131.432,234.362 131.198,234.762 131.071 C 235.166 130.943,235.238 130.711,235.238 129.533 C 235.238 128.520,235.334 128.109,235.595 128.009 C 235.839 127.916,235.952 127.535,235.952 126.813 C 235.952 126.231,236.073 125.714,236.221 125.665 C 236.368 125.615,236.544 124.990,236.611 124.276 C 236.678 123.561,236.842 122.906,236.976 122.820 C 237.110 122.733,237.269 122.037,237.331 121.272 C 237.397 120.449,237.576 119.803,237.769 119.691 C 237.981 119.567,238.095 119.054,238.095 118.228 C 238.095 117.317,238.197 116.917,238.452 116.819 C 238.709 116.720,238.810 116.318,238.810 115.390 C 238.810 114.462,238.910 114.060,239.167 113.962 C 239.430 113.861,239.524 113.445,239.524 112.388 C 239.524 111.271,239.603 110.952,239.881 110.952 C 240.151 110.952,240.238 110.661,240.238 109.762 C 240.238 109.107,240.345 108.571,240.476 108.571 C 240.607 108.571,240.714 108.411,240.714 108.214 C 240.714 108.018,240.821 107.857,240.952 107.857 C 241.083 107.857,241.190 107.367,241.190 106.769 C 241.190 106.119,241.334 105.536,241.548 105.323 C 241.746 105.125,241.905 104.543,241.905 104.014 C 241.905 103.485,242.063 102.902,242.262 102.704 C 242.458 102.508,242.619 101.935,242.619 101.431 C 242.619 100.928,242.733 100.478,242.873 100.431 C 243.012 100.385,243.190 99.869,243.268 99.284 C 243.347 98.700,243.554 98.078,243.729 97.903 C 243.904 97.728,244.048 97.122,244.048 96.556 C 244.048 95.861,244.164 95.483,244.405 95.390 C 244.650 95.296,244.762 94.914,244.762 94.174 C 244.762 93.374,244.854 93.095,245.119 93.095 C 245.382 93.095,245.476 92.820,245.476 92.049 C 245.476 91.339,245.591 90.959,245.833 90.866 C 246.069 90.776,246.190 90.403,246.190 89.769 C 246.190 89.127,246.348 88.652,246.667 88.333 C 246.998 88.002,247.143 87.540,247.143 86.811 C 247.143 86.101,247.258 85.721,247.500 85.628 C 247.734 85.539,247.857 85.168,247.857 84.557 C 247.857 83.946,247.981 83.575,248.214 83.485 C 248.426 83.404,248.571 83.047,248.571 82.610 C 248.571 82.203,248.732 81.710,248.929 81.514 C 249.125 81.317,249.286 80.889,249.286 80.561 C 249.286 80.234,249.446 79.805,249.643 79.609 C 249.839 79.412,250.000 78.896,250.000 78.461 C 250.000 77.978,250.139 77.617,250.357 77.533 C 250.602 77.439,250.714 77.056,250.714 76.317 C 250.714 75.517,250.807 75.238,251.071 75.238 C 251.307 75.238,251.429 75.003,251.429 74.549 C 251.429 74.157,251.582 73.802,251.786 73.723 C 252.019 73.634,252.143 73.263,252.143 72.654 C 252.143 71.922,252.245 71.695,252.619 71.598 C 252.961 71.508,253.095 71.273,253.095 70.762 C 253.095 70.350,253.245 69.993,253.452 69.914 C 253.649 69.839,253.810 69.506,253.810 69.174 C 253.810 68.843,253.912 68.571,254.037 68.571 C 254.162 68.571,254.334 68.196,254.420 67.738 C 254.506 67.280,254.671 66.905,254.786 66.905 C 254.900 66.905,255.062 66.483,255.144 65.967 C 255.227 65.451,255.442 64.973,255.623 64.903 C 255.804 64.834,255.952 64.452,255.952 64.055 C 255.952 63.572,256.071 63.333,256.310 63.333 C 256.508 63.333,256.667 63.122,256.667 62.857 C 256.667 62.595,256.772 62.381,256.900 62.381 C 257.029 62.381,257.199 62.121,257.279 61.803 C 257.359 61.485,257.575 61.167,257.760 61.096 C 257.944 61.025,258.095 60.722,258.095 60.422 C 258.095 60.122,258.310 59.743,258.571 59.579 C 258.833 59.416,259.048 59.026,259.048 58.714 C 259.048 58.402,259.208 58.085,259.405 58.009 C 259.601 57.934,259.762 57.612,259.762 57.295 C 259.762 56.977,259.923 56.656,260.119 56.581 C 260.315 56.505,260.476 56.279,260.476 56.079 C 260.476 55.878,260.581 55.714,260.710 55.714 C 260.838 55.714,261.009 55.454,261.088 55.136 C 261.168 54.818,261.384 54.500,261.569 54.429 C 261.754 54.359,261.905 54.183,261.905 54.038 C 261.905 53.894,262.065 53.615,262.262 53.418 C 262.458 53.222,262.619 52.855,262.619 52.602 C 262.619 52.349,262.780 52.143,262.976 52.143 C 263.173 52.143,263.333 51.982,263.333 51.786 C 263.333 51.589,263.494 51.429,263.690 51.429 C 263.887 51.429,264.048 51.275,264.048 51.087 C 264.048 50.900,264.262 50.678,264.524 50.595 C 264.786 50.512,265.000 50.330,265.000 50.190 C 265.000 50.050,265.268 49.687,265.595 49.384 C 265.923 49.081,266.190 48.720,266.190 48.583 C 266.190 48.446,266.300 48.333,266.435 48.333 C 266.569 48.333,267.161 47.851,267.751 47.262 C 268.340 46.673,268.926 46.190,269.054 46.190 C 269.181 46.190,269.286 46.030,269.286 45.833 C 269.286 45.610,269.511 45.476,269.888 45.476 C 270.220 45.476,270.553 45.315,270.628 45.119 C 270.704 44.923,270.918 44.762,271.104 44.762 C 271.291 44.762,271.505 44.601,271.581 44.405 C 271.658 44.204,272.012 44.048,272.389 44.048 C 272.759 44.048,273.207 43.902,273.385 43.724 C 273.563 43.546,274.342 43.348,275.116 43.284 C 275.890 43.220,276.565 43.044,276.615 42.893 C 276.735 42.532,278.742 42.536,278.863 42.898 C 278.916 43.057,279.617 43.224,280.490 43.285 C 281.443 43.352,282.096 43.517,282.214 43.720 C 282.319 43.900,282.656 44.048,282.963 44.048 C 283.269 44.048,283.582 44.208,283.658 44.405 C 283.733 44.601,284.066 44.762,284.397 44.762 C 284.774 44.762,285.000 44.896,285.000 45.119 C 285.000 45.317,285.212 45.476,285.476 45.476 C 285.741 45.476,285.952 45.635,285.952 45.833 C 285.952 46.030,286.060 46.190,286.190 46.190 C 286.474 46.190,287.381 47.061,287.381 47.333 C 287.381 47.437,287.698 47.785,288.085 48.106 C 288.472 48.428,288.794 48.824,288.799 48.988 C 288.805 49.152,288.959 49.286,289.141 49.286 C 289.323 49.286,289.539 49.554,289.622 49.881 C 289.704 50.208,289.876 50.476,290.005 50.476 C 290.133 50.476,290.238 50.640,290.238 50.841 C 290.238 51.041,290.399 51.267,290.595 51.342 C 290.792 51.418,290.952 51.735,290.952 52.047 C 290.952 52.360,291.167 52.749,291.429 52.912 C 291.690 53.076,291.905 53.455,291.905 53.755 C 291.905 54.055,292.065 54.362,292.262 54.438 C 292.458 54.513,292.619 54.835,292.619 55.152 C 292.619 55.469,292.780 55.791,292.976 55.866 C 293.210 55.956,293.333 56.327,293.333 56.938 C 293.333 57.549,293.457 57.920,293.690 58.009 C 293.924 58.099,294.048 58.470,294.048 59.081 C 294.048 59.691,294.171 60.062,294.405 60.152 C 294.654 60.248,294.762 60.636,294.762 61.437 C 294.762 62.140,294.900 62.723,295.119 62.942 C 295.355 63.178,295.476 63.772,295.476 64.692 C 295.476 65.494,295.616 66.284,295.807 66.556 C 296.008 66.843,296.171 67.857,296.224 69.149 C 296.282 70.566,296.410 71.303,296.608 71.369 C 296.785 71.428,296.905 71.892,296.905 72.520 C 296.905 73.254,297.049 73.715,297.381 74.048 C 297.646 74.312,297.857 74.841,297.857 75.238 C 297.857 75.714,297.976 75.952,298.214 75.952 C 298.452 75.952,298.571 76.190,298.571 76.667 C 298.571 77.143,298.690 77.381,298.929 77.381 C 299.125 77.381,299.286 77.545,299.286 77.746 C 299.286 77.946,299.446 78.172,299.643 78.247 C 299.839 78.323,300.000 78.516,300.000 78.678 C 300.000 79.121,302.040 81.190,302.476 81.190 C 302.686 81.190,302.857 81.351,302.857 81.548 C 302.857 81.744,303.059 81.905,303.306 81.905 C 303.554 81.905,303.810 82.117,303.879 82.381 C 303.961 82.696,304.203 82.857,304.595 82.857 C 304.921 82.857,305.249 83.018,305.324 83.214 C 305.400 83.411,305.721 83.571,306.038 83.571 C 306.356 83.571,306.677 83.732,306.753 83.929 C 306.846 84.172,307.227 84.286,307.943 84.286 C 308.660 84.286,309.040 84.400,309.134 84.643 C 309.330 85.154,316.406 85.166,317.344 84.657 C 317.692 84.469,318.378 84.249,318.869 84.170 C 319.360 84.091,319.762 83.924,319.762 83.799 C 319.762 83.674,320.078 83.571,320.464 83.571 C 320.851 83.571,321.252 83.435,321.357 83.269 C 321.462 83.102,321.842 82.837,322.202 82.679 C 322.563 82.521,322.857 82.282,322.857 82.148 C 322.857 82.014,323.018 81.905,323.214 81.905 C 323.411 81.905,323.571 81.744,323.571 81.548 C 323.571 81.349,323.783 81.190,324.048 81.190 C 324.312 81.190,324.524 81.032,324.524 80.833 C 324.524 80.637,324.685 80.476,324.881 80.476 C 325.077 80.476,325.238 80.315,325.238 80.119 C 325.238 79.923,325.399 79.762,325.595 79.762 C 325.792 79.762,325.952 79.601,325.952 79.405 C 325.952 79.208,326.113 79.048,326.310 79.048 C 326.506 79.048,326.667 78.898,326.667 78.716 C 326.667 78.534,326.827 78.323,327.024 78.247 C 327.220 78.172,327.381 77.992,327.381 77.848 C 327.381 77.703,327.542 77.424,327.738 77.228 C 327.935 77.031,328.095 76.676,328.095 76.437 C 328.095 76.198,328.256 75.942,328.452 75.866 C 328.649 75.791,328.810 75.450,328.810 75.110 C 328.810 74.769,328.970 74.329,329.167 74.133 C 329.396 73.903,329.524 73.314,329.524 72.483 C 329.524 71.493,329.607 71.190,329.881 71.190 C 330.180 71.190,330.238 70.688,330.238 68.095 C 330.238 65.503,330.180 65.000,329.881 65.000 C 329.586 65.000,329.524 64.563,329.524 62.493 C 329.524 60.483,329.453 59.958,329.167 59.848 C 328.894 59.743,328.810 59.296,328.810 57.951 C 328.810 56.545,328.738 56.190,328.452 56.190 C 328.174 56.190,328.095 55.872,328.095 54.754 C 328.095 53.698,328.001 53.282,327.738 53.181 C 327.481 53.083,327.381 52.681,327.381 51.753 C 327.381 50.824,327.281 50.423,327.024 50.324 C 326.781 50.231,326.667 49.850,326.667 49.134 C 326.667 48.457,326.549 48.035,326.338 47.954 C 326.157 47.885,325.941 47.406,325.859 46.890 C 325.776 46.374,325.603 45.952,325.473 45.952 C 325.344 45.952,325.238 45.628,325.238 45.231 C 325.238 44.809,325.090 44.452,324.881 44.372 C 324.685 44.296,324.522 44.005,324.521 43.725 C 324.515 42.839,324.242 42.143,323.901 42.143 C 323.683 42.143,323.571 41.860,323.571 41.310 C 323.571 40.728,323.464 40.476,323.214 40.476 C 322.978 40.476,322.857 40.240,322.857 39.779 C 322.857 39.395,322.696 38.921,322.500 38.724 C 322.304 38.528,322.143 38.196,322.143 37.986 C 322.143 37.776,321.982 37.542,321.786 37.467 C 321.589 37.392,321.429 37.070,321.429 36.753 C 321.429 36.435,321.268 36.114,321.071 36.038 C 320.875 35.963,320.714 35.642,320.714 35.324 C 320.714 35.007,320.554 34.685,320.357 34.610 C 320.161 34.535,320.000 34.278,320.000 34.039 C 320.000 33.801,319.839 33.445,319.643 33.248 C 319.446 33.052,319.286 32.776,319.286 32.636 C 319.286 32.496,319.125 32.381,318.929 32.381 C 318.692 32.381,318.571 32.145,318.571 31.683 C 318.571 31.206,318.428 30.939,318.119 30.841 C 317.870 30.762,317.600 30.433,317.519 30.111 C 317.438 29.788,317.267 29.524,317.138 29.524 C 317.010 29.524,316.905 29.385,316.905 29.215 C 316.905 29.045,316.588 28.643,316.201 28.322 C 315.813 28.001,315.492 27.604,315.486 27.440 C 315.481 27.277,315.315 27.143,315.119 27.143 C 314.902 27.143,314.762 26.922,314.762 26.580 C 314.762 25.987,312.460 23.333,311.945 23.333 C 311.792 23.333,311.667 23.173,311.667 22.976 C 311.667 22.780,311.506 22.619,311.310 22.619 C 311.113 22.619,310.952 22.458,310.952 22.262 C 310.952 22.065,310.792 21.905,310.595 21.905 C 310.399 21.905,310.238 21.744,310.238 21.548 C 310.238 21.351,310.077 21.190,309.881 21.190 C 309.685 21.190,309.524 21.030,309.524 20.833 C 309.524 20.637,309.370 20.476,309.183 20.476 C 308.995 20.476,308.774 20.262,308.690 20.000 C 308.607 19.738,308.386 19.524,308.198 19.524 C 308.011 19.524,307.857 19.417,307.857 19.286 C 307.857 19.155,307.750 19.048,307.619 19.048 C 307.488 19.048,307.167 18.833,306.905 18.571 C 306.643 18.310,306.268 18.095,306.071 18.095 C 305.875 18.095,305.714 17.935,305.714 17.738 C 305.714 17.542,305.565 17.381,305.383 17.381 C 305.200 17.381,304.989 17.220,304.914 17.024 C 304.839 16.827,304.532 16.662,304.234 16.657 C 303.931 16.651,303.432 16.335,303.106 15.942 C 302.785 15.554,302.288 15.238,302.001 15.238 C 301.714 15.238,301.418 15.077,301.342 14.881 C 301.264 14.677,300.909 14.524,300.511 14.524 C 300.018 14.524,299.782 14.386,299.693 14.048 C 299.611 13.732,299.368 13.571,298.976 13.571 C 298.651 13.571,298.323 13.411,298.247 13.214 C 298.172 13.018,297.850 12.857,297.533 12.857 C 297.215 12.857,296.894 12.696,296.819 12.500 C 296.729 12.266,296.358 12.143,295.747 12.143 C 295.136 12.143,294.765 12.019,294.676 11.786 C 294.583 11.543,294.202 11.429,293.485 11.429 C 292.769 11.429,292.388 11.314,292.295 11.071 C 292.201 10.827,291.818 10.714,291.079 10.714 C 290.279 10.714,290.000 10.622,290.000 10.357 C 290.000 10.071,289.643 10.000,288.214 10.000 C 287.183 10.000,286.429 9.899,286.429 9.762 C 286.429 9.607,283.333 9.524,277.619 9.524 C 271.905 9.524,268.810 9.607,268.810 9.762 \" stroke=\"none\" fill=\"#000000\" fill-rule=\"evenodd\"><\/path><\/g><\/svg>\n","type_icon\/outline\/enum.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,7H15V9H11V11H15V13H11V15H15V17H9V7M3,5A2,2 0 0,1 5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5C3.89,21 3,20.1 3,19V5M5,5V19H19V5H5Z\" \/><\/svg>","type_icon\/outline\/macro.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,7H15A2,2 0 0,1 17,9V17H15V9H13V16H11V9H9V17H7V9A2,2 0 0,1 9,7M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3M5,5V19H19V5H5Z\" \/><\/svg>","type_icon\/outline\/struct.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M11,7H15V9H11V11H13A2,2 0 0,1 15,13V15A2,2 0 0,1 13,17H9V15H13V13H11A2,2 0 0,1 9,11V9A2,2 0 0,1 11,7M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3M5,5V19H19V5H5Z\" \/><\/svg>","type_icon\/outline\/type.svg":"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE svg PUBLIC \"-\/\/W3C\/\/DTD SVG 1.1\/\/EN\" \"http:\/\/www.w3.org\/Graphics\/SVG\/1.1\/DTD\/svg11.dtd\"><svg xmlns=\"http:\/\/www.w3.org\/2000\/svg\" xmlns:xlink=\"http:\/\/www.w3.org\/1999\/xlink\" version=\"1.1\" width=\"24\" height=\"24\" viewBox=\"0 0 24 24\"><path d=\"M9,7H15V9H13V17H11V9H9V7M5,3H19A2,2 0 0,1 21,5V19A2,2 0 0,1 19,21H5A2,2 0 0,1 3,19V5A2,2 0 0,1 5,3M5,5V19H19V5H5Z\" \/><\/svg>"}}};
(function() {
try{/*!
  Highlight.js v11.4.0 (git: 2d0e7c1094)
  (c) 2006-2022 Ivan Sagalaev and other contributors
  License: BSD-3-Clause
 */
var hljs=function(){"use strict";var e={exports:{}};function n(e){
return e instanceof Map?e.clear=e.delete=e.set=()=>{
throw Error("map is read-only")}:e instanceof Set&&(e.add=e.clear=e.delete=()=>{
throw Error("set is read-only")
}),Object.freeze(e),Object.getOwnPropertyNames(e).forEach((t=>{var a=e[t]
;"object"!=typeof a||Object.isFrozen(a)||n(a)})),e}
e.exports=n,e.exports.default=n;var t=e.exports;class a{constructor(e){
void 0===e.data&&(e.data={}),this.data=e.data,this.isMatchIgnored=!1}
ignoreMatch(){this.isMatchIgnored=!0}}function i(e){
return e.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/"/g,"&quot;").replace(/'/g,"&#x27;")
}function r(e,...n){const t=Object.create(null);for(const n in e)t[n]=e[n]
;return n.forEach((e=>{for(const n in e)t[n]=e[n]})),t}const s=e=>!!e.kind
;class o{constructor(e,n){
this.buffer="",this.classPrefix=n.classPrefix,e.walk(this)}addText(e){
this.buffer+=i(e)}openNode(e){if(!s(e))return;let n=e.kind
;n=e.sublanguage?"language-"+n:((e,{prefix:n})=>{if(e.includes(".")){
const t=e.split(".")
;return[`${n}${t.shift()}`,...t.map(((e,n)=>`${e}${"_".repeat(n+1)}`))].join(" ")
}return`${n}${e}`})(n,{prefix:this.classPrefix}),this.span(n)}closeNode(e){
s(e)&&(this.buffer+="</span>")}value(){return this.buffer}span(e){
this.buffer+=`<span class="${e}">`}}class l{constructor(){this.rootNode={
children:[]},this.stack=[this.rootNode]}get top(){
return this.stack[this.stack.length-1]}get root(){return this.rootNode}add(e){
this.top.children.push(e)}openNode(e){const n={kind:e,children:[]}
;this.add(n),this.stack.push(n)}closeNode(){
if(this.stack.length>1)return this.stack.pop()}closeAllNodes(){
for(;this.closeNode(););}toJSON(){return JSON.stringify(this.rootNode,null,4)}
walk(e){return this.constructor._walk(e,this.rootNode)}static _walk(e,n){
return"string"==typeof n?e.addText(n):n.children&&(e.openNode(n),
n.children.forEach((n=>this._walk(e,n))),e.closeNode(n)),e}static _collapse(e){
"string"!=typeof e&&e.children&&(e.children.every((e=>"string"==typeof e))?e.children=[e.children.join("")]:e.children.forEach((e=>{
l._collapse(e)})))}}class c extends l{constructor(e){super(),this.options=e}
addKeyword(e,n){""!==e&&(this.openNode(n),this.addText(e),this.closeNode())}
addText(e){""!==e&&this.add(e)}addSublanguage(e,n){const t=e.root
;t.kind=n,t.sublanguage=!0,this.add(t)}toHTML(){
return new o(this,this.options).value()}finalize(){return!0}}function d(e){
return e?"string"==typeof e?e:e.source:null}function g(e){return m("(?=",e,")")}
function u(e){return m("(?:",e,")*")}function b(e){return m("(?:",e,")?")}
function m(...e){return e.map((e=>d(e))).join("")}function p(...e){const n=(e=>{
const n=e[e.length-1]
;return"object"==typeof n&&n.constructor===Object?(e.splice(e.length-1,1),n):{}
})(e);return"("+(n.capture?"":"?:")+e.map((e=>d(e))).join("|")+")"}
function _(e){return RegExp(e.toString()+"|").exec("").length-1}
const h=/\[(?:[^\\\]]|\\.)*\]|\(\??|\\([1-9][0-9]*)|\\./
;function f(e,{joinWith:n}){let t=0;return e.map((e=>{t+=1;const n=t
;let a=d(e),i="";for(;a.length>0;){const e=h.exec(a);if(!e){i+=a;break}
i+=a.substring(0,e.index),
a=a.substring(e.index+e[0].length),"\\"===e[0][0]&&e[1]?i+="\\"+(Number(e[1])+n):(i+=e[0],
"("===e[0]&&t++)}return i})).map((e=>`(${e})`)).join(n)}
const E="[a-zA-Z]\\w*",y="[a-zA-Z_]\\w*",N="\\b\\d+(\\.\\d+)?",w="(-?)(\\b0[xX][a-fA-F0-9]+|(\\b\\d+(\\.\\d*)?|\\.\\d+)([eE][-+]?\\d+)?)",v="\\b(0b[01]+)",O={
begin:"\\\\[\\s\\S]",relevance:0},x={scope:"string",begin:"'",end:"'",
illegal:"\\n",contains:[O]},M={scope:"string",begin:'"',end:'"',illegal:"\\n",
contains:[O]},k=(e,n,t={})=>{const a=r({scope:"comment",begin:e,end:n,
contains:[]},t);a.contains.push({scope:"doctag",
begin:"[ ]*(?=(TODO|FIXME|NOTE|BUG|OPTIMIZE|HACK|XXX):)",
end:/(TODO|FIXME|NOTE|BUG|OPTIMIZE|HACK|XXX):/,excludeBegin:!0,relevance:0})
;const i=p("I","a","is","so","us","to","at","if","in","it","on",/[A-Za-z]+['](d|ve|re|ll|t|s|n)/,/[A-Za-z]+[-][a-z]+/,/[A-Za-z][a-z]{2,}/)
;return a.contains.push({begin:m(/[ ]+/,"(",i,/[.]?[:]?([.][ ]|[ ])/,"){3}")}),a
},S=k("//","$"),A=k("/\\*","\\*/"),C=k("#","$");var T=Object.freeze({
__proto__:null,MATCH_NOTHING_RE:/\b\B/,IDENT_RE:E,UNDERSCORE_IDENT_RE:y,
NUMBER_RE:N,C_NUMBER_RE:w,BINARY_NUMBER_RE:v,
RE_STARTERS_RE:"!|!=|!==|%|%=|&|&&|&=|\\*|\\*=|\\+|\\+=|,|-|-=|/=|/|:|;|<<|<<=|<=|<|===|==|=|>>>=|>>=|>=|>>>|>>|>|\\?|\\[|\\{|\\(|\\^|\\^=|\\||\\|=|\\|\\||~",
SHEBANG:(e={})=>{const n=/^#![ ]*\//
;return e.binary&&(e.begin=m(n,/.*\b/,e.binary,/\b.*/)),r({scope:"meta",begin:n,
end:/$/,relevance:0,"on:begin":(e,n)=>{0!==e.index&&n.ignoreMatch()}},e)},
BACKSLASH_ESCAPE:O,APOS_STRING_MODE:x,QUOTE_STRING_MODE:M,PHRASAL_WORDS_MODE:{
begin:/\b(a|an|the|are|I'm|isn't|don't|doesn't|won't|but|just|should|pretty|simply|enough|gonna|going|wtf|so|such|will|you|your|they|like|more)\b/
},COMMENT:k,C_LINE_COMMENT_MODE:S,C_BLOCK_COMMENT_MODE:A,HASH_COMMENT_MODE:C,
NUMBER_MODE:{scope:"number",begin:N,relevance:0},C_NUMBER_MODE:{scope:"number",
begin:w,relevance:0},BINARY_NUMBER_MODE:{scope:"number",begin:v,relevance:0},
REGEXP_MODE:{begin:/(?=\/[^/\n]*\/)/,contains:[{scope:"regexp",begin:/\//,
end:/\/[gimuy]*/,illegal:/\n/,contains:[O,{begin:/\[/,end:/\]/,relevance:0,
contains:[O]}]}]},TITLE_MODE:{scope:"title",begin:E,relevance:0},
UNDERSCORE_TITLE_MODE:{scope:"title",begin:y,relevance:0},METHOD_GUARD:{
begin:"\\.\\s*[a-zA-Z_]\\w*",relevance:0},END_SAME_AS_BEGIN:e=>Object.assign(e,{
"on:begin":(e,n)=>{n.data._beginMatch=e[1]},"on:end":(e,n)=>{
n.data._beginMatch!==e[1]&&n.ignoreMatch()}})});function R(e,n){
"."===e.input[e.index-1]&&n.ignoreMatch()}function D(e,n){
void 0!==e.className&&(e.scope=e.className,delete e.className)}function I(e,n){
n&&e.beginKeywords&&(e.begin="\\b("+e.beginKeywords.split(" ").join("|")+")(?!\\.)(?=\\b|\\s)",
e.__beforeBegin=R,e.keywords=e.keywords||e.beginKeywords,delete e.beginKeywords,
void 0===e.relevance&&(e.relevance=0))}function L(e,n){
Array.isArray(e.illegal)&&(e.illegal=p(...e.illegal))}function B(e,n){
if(e.match){
if(e.begin||e.end)throw Error("begin & end are not supported with match")
;e.begin=e.match,delete e.match}}function $(e,n){
void 0===e.relevance&&(e.relevance=1)}const F=(e,n)=>{if(!e.beforeMatch)return
;if(e.starts)throw Error("beforeMatch cannot be used with starts")
;const t=Object.assign({},e);Object.keys(e).forEach((n=>{delete e[n]
})),e.keywords=t.keywords,e.begin=m(t.beforeMatch,g(t.begin)),e.starts={
relevance:0,contains:[Object.assign(t,{endsParent:!0})]
},e.relevance=0,delete t.beforeMatch
},z=["of","and","for","in","not","or","if","then","parent","list","value"]
;function U(e,n,t="keyword"){const a=Object.create(null)
;return"string"==typeof e?i(t,e.split(" ")):Array.isArray(e)?i(t,e):Object.keys(e).forEach((t=>{
Object.assign(a,U(e[t],n,t))})),a;function i(e,t){
n&&(t=t.map((e=>e.toLowerCase()))),t.forEach((n=>{const t=n.split("|")
;a[t[0]]=[e,j(t[0],t[1])]}))}}function j(e,n){
return n?Number(n):(e=>z.includes(e.toLowerCase()))(e)?0:1}const P={},K=e=>{
console.error(e)},q=(e,...n)=>{console.log("WARN: "+e,...n)},H=(e,n)=>{
P[`${e}/${n}`]||(console.log(`Deprecated as of ${e}. ${n}`),P[`${e}/${n}`]=!0)
},Z=Error();function G(e,n,{key:t}){let a=0;const i=e[t],r={},s={}
;for(let e=1;e<=n.length;e++)s[e+a]=i[e],r[e+a]=!0,a+=_(n[e-1])
;e[t]=s,e[t]._emit=r,e[t]._multi=!0}function W(e){(e=>{
e.scope&&"object"==typeof e.scope&&null!==e.scope&&(e.beginScope=e.scope,
delete e.scope)})(e),"string"==typeof e.beginScope&&(e.beginScope={
_wrap:e.beginScope}),"string"==typeof e.endScope&&(e.endScope={_wrap:e.endScope
}),(e=>{if(Array.isArray(e.begin)){
if(e.skip||e.excludeBegin||e.returnBegin)throw K("skip, excludeBegin, returnBegin not compatible with beginScope: {}"),
Z
;if("object"!=typeof e.beginScope||null===e.beginScope)throw K("beginScope must be object"),
Z;G(e,e.begin,{key:"beginScope"}),e.begin=f(e.begin,{joinWith:""})}})(e),(e=>{
if(Array.isArray(e.end)){
if(e.skip||e.excludeEnd||e.returnEnd)throw K("skip, excludeEnd, returnEnd not compatible with endScope: {}"),
Z
;if("object"!=typeof e.endScope||null===e.endScope)throw K("endScope must be object"),
Z;G(e,e.end,{key:"endScope"}),e.end=f(e.end,{joinWith:""})}})(e)}function Q(e){
function n(n,t){
return RegExp(d(n),"m"+(e.case_insensitive?"i":"")+(e.unicodeRegex?"u":"")+(t?"g":""))
}class t{constructor(){
this.matchIndexes={},this.regexes=[],this.matchAt=1,this.position=0}
addRule(e,n){
n.position=this.position++,this.matchIndexes[this.matchAt]=n,this.regexes.push([n,e]),
this.matchAt+=_(e)+1}compile(){0===this.regexes.length&&(this.exec=()=>null)
;const e=this.regexes.map((e=>e[1]));this.matcherRe=n(f(e,{joinWith:"|"
}),!0),this.lastIndex=0}exec(e){this.matcherRe.lastIndex=this.lastIndex
;const n=this.matcherRe.exec(e);if(!n)return null
;const t=n.findIndex(((e,n)=>n>0&&void 0!==e)),a=this.matchIndexes[t]
;return n.splice(0,t),Object.assign(n,a)}}class a{constructor(){
this.rules=[],this.multiRegexes=[],
this.count=0,this.lastIndex=0,this.regexIndex=0}getMatcher(e){
if(this.multiRegexes[e])return this.multiRegexes[e];const n=new t
;return this.rules.slice(e).forEach((([e,t])=>n.addRule(e,t))),
n.compile(),this.multiRegexes[e]=n,n}resumingScanAtSamePosition(){
return 0!==this.regexIndex}considerAll(){this.regexIndex=0}addRule(e,n){
this.rules.push([e,n]),"begin"===n.type&&this.count++}exec(e){
const n=this.getMatcher(this.regexIndex);n.lastIndex=this.lastIndex
;let t=n.exec(e)
;if(this.resumingScanAtSamePosition())if(t&&t.index===this.lastIndex);else{
const n=this.getMatcher(0);n.lastIndex=this.lastIndex+1,t=n.exec(e)}
return t&&(this.regexIndex+=t.position+1,
this.regexIndex===this.count&&this.considerAll()),t}}
if(e.compilerExtensions||(e.compilerExtensions=[]),
e.contains&&e.contains.includes("self"))throw Error("ERR: contains `self` is not supported at the top-level of a language.  See documentation.")
;return e.classNameAliases=r(e.classNameAliases||{}),function t(i,s){const o=i
;if(i.isCompiled)return o
;[D,B,W,F].forEach((e=>e(i,s))),e.compilerExtensions.forEach((e=>e(i,s))),
i.__beforeBegin=null,[I,L,$].forEach((e=>e(i,s))),i.isCompiled=!0;let l=null
;return"object"==typeof i.keywords&&i.keywords.$pattern&&(i.keywords=Object.assign({},i.keywords),
l=i.keywords.$pattern,
delete i.keywords.$pattern),l=l||/\w+/,i.keywords&&(i.keywords=U(i.keywords,e.case_insensitive)),
o.keywordPatternRe=n(l,!0),
s&&(i.begin||(i.begin=/\B|\b/),o.beginRe=n(o.begin),i.end||i.endsWithParent||(i.end=/\B|\b/),
i.end&&(o.endRe=n(o.end)),
o.terminatorEnd=d(o.end)||"",i.endsWithParent&&s.terminatorEnd&&(o.terminatorEnd+=(i.end?"|":"")+s.terminatorEnd)),
i.illegal&&(o.illegalRe=n(i.illegal)),
i.contains||(i.contains=[]),i.contains=[].concat(...i.contains.map((e=>(e=>(e.variants&&!e.cachedVariants&&(e.cachedVariants=e.variants.map((n=>r(e,{
variants:null},n)))),e.cachedVariants?e.cachedVariants:X(e)?r(e,{
starts:e.starts?r(e.starts):null
}):Object.isFrozen(e)?r(e):e))("self"===e?i:e)))),i.contains.forEach((e=>{t(e,o)
})),i.starts&&t(i.starts,s),o.matcher=(e=>{const n=new a
;return e.contains.forEach((e=>n.addRule(e.begin,{rule:e,type:"begin"
}))),e.terminatorEnd&&n.addRule(e.terminatorEnd,{type:"end"
}),e.illegal&&n.addRule(e.illegal,{type:"illegal"}),n})(o),o}(e)}function X(e){
return!!e&&(e.endsWithParent||X(e.starts))}class V extends Error{
constructor(e,n){super(e),this.name="HTMLInjectionError",this.html=n}}
const J=i,Y=r,ee=Symbol("nomatch");var ne=(e=>{
const n=Object.create(null),i=Object.create(null),r=[];let s=!0
;const o="Could not find the language '{}', did you forget to load/include a language module?",l={
disableAutodetect:!0,name:"Plain text",contains:[]};let d={
ignoreUnescapedHTML:!1,throwUnescapedHTML:!1,noHighlightRe:/^(no-?highlight)$/i,
languageDetectRe:/\blang(?:uage)?-([\w-]+)\b/i,classPrefix:"hljs-",
cssSelector:"pre code",languages:null,__emitter:c};function _(e){
return d.noHighlightRe.test(e)}function h(e,n,t){let a="",i=""
;"object"==typeof n?(a=e,
t=n.ignoreIllegals,i=n.language):(H("10.7.0","highlight(lang, code, ...args) has been deprecated."),
H("10.7.0","Please use highlight(code, options) instead.\nhttps://github.com/highlightjs/highlight.js/issues/2277"),
i=e,a=n),void 0===t&&(t=!0);const r={code:a,language:i};M("before:highlight",r)
;const s=r.result?r.result:f(r.language,r.code,t)
;return s.code=r.code,M("after:highlight",s),s}function f(e,t,i,r){
const l=Object.create(null);function c(){if(!x.keywords)return void k.addText(S)
;let e=0;x.keywordPatternRe.lastIndex=0;let n=x.keywordPatternRe.exec(S),t=""
;for(;n;){t+=S.substring(e,n.index)
;const i=N.case_insensitive?n[0].toLowerCase():n[0],r=(a=i,x.keywords[a]);if(r){
const[e,a]=r
;if(k.addText(t),t="",l[i]=(l[i]||0)+1,l[i]<=7&&(A+=a),e.startsWith("_"))t+=n[0];else{
const t=N.classNameAliases[e]||e;k.addKeyword(n[0],t)}}else t+=n[0]
;e=x.keywordPatternRe.lastIndex,n=x.keywordPatternRe.exec(S)}var a
;t+=S.substr(e),k.addText(t)}function g(){null!=x.subLanguage?(()=>{
if(""===S)return;let e=null;if("string"==typeof x.subLanguage){
if(!n[x.subLanguage])return void k.addText(S)
;e=f(x.subLanguage,S,!0,M[x.subLanguage]),M[x.subLanguage]=e._top
}else e=E(S,x.subLanguage.length?x.subLanguage:null)
;x.relevance>0&&(A+=e.relevance),k.addSublanguage(e._emitter,e.language)
})():c(),S=""}function u(e,n){let t=1;for(;void 0!==n[t];){if(!e._emit[t]){t++
;continue}const a=N.classNameAliases[e[t]]||e[t],i=n[t]
;a?k.addKeyword(i,a):(S=i,c(),S=""),t++}}function b(e,n){
return e.scope&&"string"==typeof e.scope&&k.openNode(N.classNameAliases[e.scope]||e.scope),
e.beginScope&&(e.beginScope._wrap?(k.addKeyword(S,N.classNameAliases[e.beginScope._wrap]||e.beginScope._wrap),
S=""):e.beginScope._multi&&(u(e.beginScope,n),S="")),x=Object.create(e,{parent:{
value:x}}),x}function m(e,n,t){let i=((e,n)=>{const t=e&&e.exec(n)
;return t&&0===t.index})(e.endRe,t);if(i){if(e["on:end"]){const t=new a(e)
;e["on:end"](n,t),t.isMatchIgnored&&(i=!1)}if(i){
for(;e.endsParent&&e.parent;)e=e.parent;return e}}
if(e.endsWithParent)return m(e.parent,n,t)}function p(e){
return 0===x.matcher.regexIndex?(S+=e[0],1):(R=!0,0)}function _(e){
const n=e[0],a=t.substr(e.index),i=m(x,e,a);if(!i)return ee;const r=x
;x.endScope&&x.endScope._wrap?(g(),
k.addKeyword(n,x.endScope._wrap)):x.endScope&&x.endScope._multi?(g(),
u(x.endScope,e)):r.skip?S+=n:(r.returnEnd||r.excludeEnd||(S+=n),
g(),r.excludeEnd&&(S=n));do{
x.scope&&k.closeNode(),x.skip||x.subLanguage||(A+=x.relevance),x=x.parent
}while(x!==i.parent);return i.starts&&b(i.starts,e),r.returnEnd?0:n.length}
let h={};function y(n,r){const o=r&&r[0];if(S+=n,null==o)return g(),0
;if("begin"===h.type&&"end"===r.type&&h.index===r.index&&""===o){
if(S+=t.slice(r.index,r.index+1),!s){const n=Error(`0 width match regex (${e})`)
;throw n.languageName=e,n.badRule=h.rule,n}return 1}
if(h=r,"begin"===r.type)return(e=>{
const n=e[0],t=e.rule,i=new a(t),r=[t.__beforeBegin,t["on:begin"]]
;for(const t of r)if(t&&(t(e,i),i.isMatchIgnored))return p(n)
;return t.skip?S+=n:(t.excludeBegin&&(S+=n),
g(),t.returnBegin||t.excludeBegin||(S=n)),b(t,e),t.returnBegin?0:n.length})(r)
;if("illegal"===r.type&&!i){
const e=Error('Illegal lexeme "'+o+'" for mode "'+(x.scope||"<unnamed>")+'"')
;throw e.mode=x,e}if("end"===r.type){const e=_(r);if(e!==ee)return e}
if("illegal"===r.type&&""===o)return 1
;if(T>1e5&&T>3*r.index)throw Error("potential infinite loop, way more iterations than matches")
;return S+=o,o.length}const N=v(e)
;if(!N)throw K(o.replace("{}",e)),Error('Unknown language: "'+e+'"')
;const w=Q(N);let O="",x=r||w;const M={},k=new d.__emitter(d);(()=>{const e=[]
;for(let n=x;n!==N;n=n.parent)n.scope&&e.unshift(n.scope)
;e.forEach((e=>k.openNode(e)))})();let S="",A=0,C=0,T=0,R=!1;try{
for(x.matcher.considerAll();;){
T++,R?R=!1:x.matcher.considerAll(),x.matcher.lastIndex=C
;const e=x.matcher.exec(t);if(!e)break;const n=y(t.substring(C,e.index),e)
;C=e.index+n}return y(t.substr(C)),k.closeAllNodes(),k.finalize(),O=k.toHTML(),{
language:e,value:O,relevance:A,illegal:!1,_emitter:k,_top:x}}catch(n){
if(n.message&&n.message.includes("Illegal"))return{language:e,value:J(t),
illegal:!0,relevance:0,_illegalBy:{message:n.message,index:C,
context:t.slice(C-100,C+100),mode:n.mode,resultSoFar:O},_emitter:k};if(s)return{
language:e,value:J(t),illegal:!1,relevance:0,errorRaised:n,_emitter:k,_top:x}
;throw n}}function E(e,t){t=t||d.languages||Object.keys(n);const a=(e=>{
const n={value:J(e),illegal:!1,relevance:0,_top:l,_emitter:new d.__emitter(d)}
;return n._emitter.addText(e),n})(e),i=t.filter(v).filter(x).map((n=>f(n,e,!1)))
;i.unshift(a);const r=i.sort(((e,n)=>{
if(e.relevance!==n.relevance)return n.relevance-e.relevance
;if(e.language&&n.language){if(v(e.language).supersetOf===n.language)return 1
;if(v(n.language).supersetOf===e.language)return-1}return 0})),[s,o]=r,c=s
;return c.secondBest=o,c}function y(e){let n=null;const t=(e=>{
let n=e.className+" ";n+=e.parentNode?e.parentNode.className:""
;const t=d.languageDetectRe.exec(n);if(t){const n=v(t[1])
;return n||(q(o.replace("{}",t[1])),
q("Falling back to no-highlight mode for this block.",e)),n?t[1]:"no-highlight"}
return n.split(/\s+/).find((e=>_(e)||v(e)))})(e);if(_(t))return
;if(M("before:highlightElement",{el:e,language:t
}),e.children.length>0&&(d.ignoreUnescapedHTML||(console.warn("One of your code blocks includes unescaped HTML. This is a potentially serious security risk."),
console.warn("https://github.com/highlightjs/highlight.js/wiki/security"),
console.warn("The element with unescaped HTML:"),
console.warn(e)),d.throwUnescapedHTML))throw new V("One of your code blocks includes unescaped HTML.",e.innerHTML)
;n=e;const a=n.textContent,r=t?h(a,{language:t,ignoreIllegals:!0}):E(a)
;e.innerHTML=r.value,((e,n,t)=>{const a=n&&i[n]||t
;e.classList.add("hljs"),e.classList.add("language-"+a)
})(e,t,r.language),e.result={language:r.language,re:r.relevance,
relevance:r.relevance},r.secondBest&&(e.secondBest={
language:r.secondBest.language,relevance:r.secondBest.relevance
}),M("after:highlightElement",{el:e,result:r,text:a})}let N=!1;function w(){
"loading"!==document.readyState?document.querySelectorAll(d.cssSelector).forEach(y):N=!0
}function v(e){return e=(e||"").toLowerCase(),n[e]||n[i[e]]}
function O(e,{languageName:n}){"string"==typeof e&&(e=[e]),e.forEach((e=>{
i[e.toLowerCase()]=n}))}function x(e){const n=v(e)
;return n&&!n.disableAutodetect}function M(e,n){const t=e;r.forEach((e=>{
e[t]&&e[t](n)}))}
"undefined"!=typeof window&&window.addEventListener&&window.addEventListener("DOMContentLoaded",(()=>{
N&&w()}),!1),Object.assign(e,{highlight:h,highlightAuto:E,highlightAll:w,
highlightElement:y,
highlightBlock:e=>(H("10.7.0","highlightBlock will be removed entirely in v12.0"),
H("10.7.0","Please use highlightElement now."),y(e)),configure:e=>{d=Y(d,e)},
initHighlighting:()=>{
w(),H("10.6.0","initHighlighting() deprecated.  Use highlightAll() now.")},
initHighlightingOnLoad:()=>{
w(),H("10.6.0","initHighlightingOnLoad() deprecated.  Use highlightAll() now.")
},registerLanguage:(t,a)=>{let i=null;try{i=a(e)}catch(e){
if(K("Language definition for '{}' could not be registered.".replace("{}",t)),
!s)throw e;K(e),i=l}
i.name||(i.name=t),n[t]=i,i.rawDefinition=a.bind(null,e),i.aliases&&O(i.aliases,{
languageName:t})},unregisterLanguage:e=>{delete n[e]
;for(const n of Object.keys(i))i[n]===e&&delete i[n]},
listLanguages:()=>Object.keys(n),getLanguage:v,registerAliases:O,
autoDetection:x,inherit:Y,addPlugin:e=>{(e=>{
e["before:highlightBlock"]&&!e["before:highlightElement"]&&(e["before:highlightElement"]=n=>{
e["before:highlightBlock"](Object.assign({block:n.el},n))
}),e["after:highlightBlock"]&&!e["after:highlightElement"]&&(e["after:highlightElement"]=n=>{
e["after:highlightBlock"](Object.assign({block:n.el},n))})})(e),r.push(e)}
}),e.debugMode=()=>{s=!1},e.safeMode=()=>{s=!0
},e.versionString="11.4.0",e.regex={concat:m,lookahead:g,either:p,optional:b,
anyNumberOfTimes:u};for(const e in T)"object"==typeof T[e]&&t(T[e])
;return Object.assign(e,T),e})({});const te=e=>({IMPORTANT:{scope:"meta",
begin:"!important"},BLOCK_COMMENT:e.C_BLOCK_COMMENT_MODE,HEXCOLOR:{
scope:"number",begin:/#(([0-9a-fA-F]{3,4})|(([0-9a-fA-F]{2}){3,4}))\b/},
FUNCTION_DISPATCH:{className:"built_in",begin:/[\w-]+(?=\()/},
ATTRIBUTE_SELECTOR_MODE:{scope:"selector-attr",begin:/\[/,end:/\]/,illegal:"$",
contains:[e.APOS_STRING_MODE,e.QUOTE_STRING_MODE]},CSS_NUMBER_MODE:{
scope:"number",
begin:e.NUMBER_RE+"(%|em|ex|ch|rem|vw|vh|vmin|vmax|cm|mm|in|pt|pc|px|deg|grad|rad|turn|s|ms|Hz|kHz|dpi|dpcm|dppx)?",
relevance:0},CSS_VARIABLE:{className:"attr",begin:/--[A-Za-z][A-Za-z0-9_-]*/}
}),ae=["a","abbr","address","article","aside","audio","b","blockquote","body","button","canvas","caption","cite","code","dd","del","details","dfn","div","dl","dt","em","fieldset","figcaption","figure","footer","form","h1","h2","h3","h4","h5","h6","header","hgroup","html","i","iframe","img","input","ins","kbd","label","legend","li","main","mark","menu","nav","object","ol","p","q","quote","samp","section","span","strong","summary","sup","table","tbody","td","textarea","tfoot","th","thead","time","tr","ul","var","video"],ie=["any-hover","any-pointer","aspect-ratio","color","color-gamut","color-index","device-aspect-ratio","device-height","device-width","display-mode","forced-colors","grid","height","hover","inverted-colors","monochrome","orientation","overflow-block","overflow-inline","pointer","prefers-color-scheme","prefers-contrast","prefers-reduced-motion","prefers-reduced-transparency","resolution","scan","scripting","update","width","min-width","max-width","min-height","max-height"],re=["active","any-link","blank","checked","current","default","defined","dir","disabled","drop","empty","enabled","first","first-child","first-of-type","fullscreen","future","focus","focus-visible","focus-within","has","host","host-context","hover","indeterminate","in-range","invalid","is","lang","last-child","last-of-type","left","link","local-link","not","nth-child","nth-col","nth-last-child","nth-last-col","nth-last-of-type","nth-of-type","only-child","only-of-type","optional","out-of-range","past","placeholder-shown","read-only","read-write","required","right","root","scope","target","target-within","user-invalid","valid","visited","where"],se=["after","backdrop","before","cue","cue-region","first-letter","first-line","grammar-error","marker","part","placeholder","selection","slotted","spelling-error"],oe=["align-content","align-items","align-self","all","animation","animation-delay","animation-direction","animation-duration","animation-fill-mode","animation-iteration-count","animation-name","animation-play-state","animation-timing-function","backface-visibility","background","background-attachment","background-clip","background-color","background-image","background-origin","background-position","background-repeat","background-size","border","border-bottom","border-bottom-color","border-bottom-left-radius","border-bottom-right-radius","border-bottom-style","border-bottom-width","border-collapse","border-color","border-image","border-image-outset","border-image-repeat","border-image-slice","border-image-source","border-image-width","border-left","border-left-color","border-left-style","border-left-width","border-radius","border-right","border-right-color","border-right-style","border-right-width","border-spacing","border-style","border-top","border-top-color","border-top-left-radius","border-top-right-radius","border-top-style","border-top-width","border-width","bottom","box-decoration-break","box-shadow","box-sizing","break-after","break-before","break-inside","caption-side","caret-color","clear","clip","clip-path","clip-rule","color","column-count","column-fill","column-gap","column-rule","column-rule-color","column-rule-style","column-rule-width","column-span","column-width","columns","contain","content","content-visibility","counter-increment","counter-reset","cue","cue-after","cue-before","cursor","direction","display","empty-cells","filter","flex","flex-basis","flex-direction","flex-flow","flex-grow","flex-shrink","flex-wrap","float","flow","font","font-display","font-family","font-feature-settings","font-kerning","font-language-override","font-size","font-size-adjust","font-smoothing","font-stretch","font-style","font-synthesis","font-variant","font-variant-caps","font-variant-east-asian","font-variant-ligatures","font-variant-numeric","font-variant-position","font-variation-settings","font-weight","gap","glyph-orientation-vertical","grid","grid-area","grid-auto-columns","grid-auto-flow","grid-auto-rows","grid-column","grid-column-end","grid-column-start","grid-gap","grid-row","grid-row-end","grid-row-start","grid-template","grid-template-areas","grid-template-columns","grid-template-rows","hanging-punctuation","height","hyphens","icon","image-orientation","image-rendering","image-resolution","ime-mode","isolation","justify-content","left","letter-spacing","line-break","line-height","list-style","list-style-image","list-style-position","list-style-type","margin","margin-bottom","margin-left","margin-right","margin-top","marks","mask","mask-border","mask-border-mode","mask-border-outset","mask-border-repeat","mask-border-slice","mask-border-source","mask-border-width","mask-clip","mask-composite","mask-image","mask-mode","mask-origin","mask-position","mask-repeat","mask-size","mask-type","max-height","max-width","min-height","min-width","mix-blend-mode","nav-down","nav-index","nav-left","nav-right","nav-up","none","normal","object-fit","object-position","opacity","order","orphans","outline","outline-color","outline-offset","outline-style","outline-width","overflow","overflow-wrap","overflow-x","overflow-y","padding","padding-bottom","padding-left","padding-right","padding-top","page-break-after","page-break-before","page-break-inside","pause","pause-after","pause-before","perspective","perspective-origin","pointer-events","position","quotes","resize","rest","rest-after","rest-before","right","row-gap","scroll-margin","scroll-margin-block","scroll-margin-block-end","scroll-margin-block-start","scroll-margin-bottom","scroll-margin-inline","scroll-margin-inline-end","scroll-margin-inline-start","scroll-margin-left","scroll-margin-right","scroll-margin-top","scroll-padding","scroll-padding-block","scroll-padding-block-end","scroll-padding-block-start","scroll-padding-bottom","scroll-padding-inline","scroll-padding-inline-end","scroll-padding-inline-start","scroll-padding-left","scroll-padding-right","scroll-padding-top","scroll-snap-align","scroll-snap-stop","scroll-snap-type","shape-image-threshold","shape-margin","shape-outside","speak","speak-as","src","tab-size","table-layout","text-align","text-align-all","text-align-last","text-combine-upright","text-decoration","text-decoration-color","text-decoration-line","text-decoration-style","text-emphasis","text-emphasis-color","text-emphasis-position","text-emphasis-style","text-indent","text-justify","text-orientation","text-overflow","text-rendering","text-shadow","text-transform","text-underline-position","top","transform","transform-box","transform-origin","transform-style","transition","transition-delay","transition-duration","transition-property","transition-timing-function","unicode-bidi","vertical-align","visibility","voice-balance","voice-duration","voice-family","voice-pitch","voice-range","voice-rate","voice-stress","voice-volume","white-space","widows","width","will-change","word-break","word-spacing","word-wrap","writing-mode","z-index"].reverse(),le=re.concat(se)
;var ce="\\.([0-9](_*[0-9])*)",de="[0-9a-fA-F](_*[0-9a-fA-F])*",ge={
className:"number",variants:[{
begin:`(\\b([0-9](_*[0-9])*)((${ce})|\\.)?|(${ce}))[eE][+-]?([0-9](_*[0-9])*)[fFdD]?\\b`
},{begin:`\\b([0-9](_*[0-9])*)((${ce})[fFdD]?\\b|\\.([fFdD]\\b)?)`},{
begin:`(${ce})[fFdD]?\\b`},{begin:"\\b([0-9](_*[0-9])*)[fFdD]\\b"},{
begin:`\\b0[xX]((${de})\\.?|(${de})?\\.(${de}))[pP][+-]?([0-9](_*[0-9])*)[fFdD]?\\b`
},{begin:"\\b(0|[1-9](_*[0-9])*)[lL]?\\b"},{begin:`\\b0[xX](${de})[lL]?\\b`},{
begin:"\\b0(_*[0-7])*[lL]?\\b"},{begin:"\\b0[bB][01](_*[01])*[lL]?\\b"}],
relevance:0};function ue(e,n,t){return-1===t?"":e.replace(n,(a=>ue(e,n,t-1)))}
const be="[A-Za-z$_][0-9A-Za-z$_]*",me=["as","in","of","if","for","while","finally","var","new","function","do","return","void","else","break","catch","instanceof","with","throw","case","default","try","switch","continue","typeof","delete","let","yield","const","class","debugger","async","await","static","import","from","export","extends"],pe=["true","false","null","undefined","NaN","Infinity"],_e=["Object","Function","Boolean","Symbol","Math","Date","Number","BigInt","String","RegExp","Array","Float32Array","Float64Array","Int8Array","Uint8Array","Uint8ClampedArray","Int16Array","Int32Array","Uint16Array","Uint32Array","BigInt64Array","BigUint64Array","Set","Map","WeakSet","WeakMap","ArrayBuffer","SharedArrayBuffer","Atomics","DataView","JSON","Promise","Generator","GeneratorFunction","AsyncFunction","Reflect","Proxy","Intl","WebAssembly"],he=["Error","EvalError","InternalError","RangeError","ReferenceError","SyntaxError","TypeError","URIError"],fe=["setInterval","setTimeout","clearInterval","clearTimeout","require","exports","eval","isFinite","isNaN","parseFloat","parseInt","decodeURI","decodeURIComponent","encodeURI","encodeURIComponent","escape","unescape"],Ee=["arguments","this","super","console","window","document","localStorage","module","global"],ye=[].concat(fe,_e,he)
;function Ne(e){const n=e.regex,t=be,a={begin:/<[A-Za-z0-9\\._:-]+/,
end:/\/[A-Za-z0-9\\._:-]+>|\/>/,isTrulyOpeningTag:(e,n)=>{
const t=e[0].length+e.index,a=e.input[t]
;if("<"===a||","===a)return void n.ignoreMatch();let i
;">"===a&&(((e,{after:n})=>{const t="</"+e[0].slice(1)
;return-1!==e.input.indexOf(t,n)})(e,{after:t
})||n.ignoreMatch()),(i=e.input.substr(t).match(/^\s+extends\s+/))&&0===i.index&&n.ignoreMatch()
}},i={$pattern:be,keyword:me,literal:pe,built_in:ye,"variable.language":Ee
},r="\\.([0-9](_?[0-9])*)",s="0|[1-9](_?[0-9])*|0[0-7]*[89][0-9]*",o={
className:"number",variants:[{
begin:`(\\b(${s})((${r})|\\.)?|(${r}))[eE][+-]?([0-9](_?[0-9])*)\\b`},{
begin:`\\b(${s})\\b((${r})\\b|\\.)?|(${r})\\b`},{
begin:"\\b(0|[1-9](_?[0-9])*)n\\b"},{
begin:"\\b0[xX][0-9a-fA-F](_?[0-9a-fA-F])*n?\\b"},{
begin:"\\b0[bB][0-1](_?[0-1])*n?\\b"},{begin:"\\b0[oO][0-7](_?[0-7])*n?\\b"},{
begin:"\\b0[0-7]+n?\\b"}],relevance:0},l={className:"subst",begin:"\\$\\{",
end:"\\}",keywords:i,contains:[]},c={begin:"html`",end:"",starts:{end:"`",
returnEnd:!1,contains:[e.BACKSLASH_ESCAPE,l],subLanguage:"xml"}},d={
begin:"css`",end:"",starts:{end:"`",returnEnd:!1,
contains:[e.BACKSLASH_ESCAPE,l],subLanguage:"css"}},g={className:"string",
begin:"`",end:"`",contains:[e.BACKSLASH_ESCAPE,l]},u={className:"comment",
variants:[e.COMMENT(/\/\*\*(?!\/)/,"\\*/",{relevance:0,contains:[{
begin:"(?=@[A-Za-z]+)",relevance:0,contains:[{className:"doctag",
begin:"@[A-Za-z]+"},{className:"type",begin:"\\{",end:"\\}",excludeEnd:!0,
excludeBegin:!0,relevance:0},{className:"variable",begin:t+"(?=\\s*(-)|$)",
endsParent:!0,relevance:0},{begin:/(?=[^\n])\s/,relevance:0}]}]
}),e.C_BLOCK_COMMENT_MODE,e.C_LINE_COMMENT_MODE]
},b=[e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,c,d,g,o];l.contains=b.concat({
begin:/\{/,end:/\}/,keywords:i,contains:["self"].concat(b)})
;const m=[].concat(u,l.contains),p=m.concat([{begin:/\(/,end:/\)/,keywords:i,
contains:["self"].concat(m)}]),_={className:"params",begin:/\(/,end:/\)/,
excludeBegin:!0,excludeEnd:!0,keywords:i,contains:p},h={variants:[{
match:[/class/,/\s+/,t,/\s+/,/extends/,/\s+/,n.concat(t,"(",n.concat(/\./,t),")*")],
scope:{1:"keyword",3:"title.class",5:"keyword",7:"title.class.inherited"}},{
match:[/class/,/\s+/,t],scope:{1:"keyword",3:"title.class"}}]},f={relevance:0,
match:n.either(/\bJSON/,/\b[A-Z][a-z]+([A-Z][a-z]*|\d)*/,/\b[A-Z]{2,}([A-Z][a-z]+|\d)+([A-Z][a-z]*)*/,/\b[A-Z]{2,}[a-z]+([A-Z][a-z]+|\d)*([A-Z][a-z]*)*/),
className:"title.class",keywords:{_:[..._e,...he]}},E={variants:[{
match:[/function/,/\s+/,t,/(?=\s*\()/]},{match:[/function/,/\s*(?=\()/]}],
className:{1:"keyword",3:"title.function"},label:"func.def",contains:[_],
illegal:/%/},y={
match:n.concat(/\b/,(N=[...fe,"super"],n.concat("(?!",N.join("|"),")")),t,n.lookahead(/\(/)),
className:"title.function",relevance:0};var N;const w={
begin:n.concat(/\./,n.lookahead(n.concat(t,/(?![0-9A-Za-z$_(])/))),end:t,
excludeBegin:!0,keywords:"prototype",className:"property",relevance:0},v={
match:[/get|set/,/\s+/,t,/(?=\()/],className:{1:"keyword",3:"title.function"},
contains:[{begin:/\(\)/},_]
},O="(\\([^()]*(\\([^()]*(\\([^()]*\\)[^()]*)*\\)[^()]*)*\\)|"+e.UNDERSCORE_IDENT_RE+")\\s*=>",x={
match:[/const|var|let/,/\s+/,t,/\s*/,/=\s*/,/(async\s*)?/,n.lookahead(O)],
keywords:"async",className:{1:"keyword",3:"title.function"},contains:[_]}
;return{name:"Javascript",aliases:["js","jsx","mjs","cjs"],keywords:i,exports:{
PARAMS_CONTAINS:p,CLASS_REFERENCE:f},illegal:/#(?![$_A-z])/,
contains:[e.SHEBANG({label:"shebang",binary:"node",relevance:5}),{
label:"use_strict",className:"meta",relevance:10,
begin:/^\s*['"]use (strict|asm)['"]/
},e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,c,d,g,u,o,f,{className:"attr",
begin:t+n.lookahead(":"),relevance:0},x,{
begin:"("+e.RE_STARTERS_RE+"|\\b(case|return|throw)\\b)\\s*",
keywords:"return throw case",relevance:0,contains:[u,e.REGEXP_MODE,{
className:"function",begin:O,returnBegin:!0,end:"\\s*=>",contains:[{
className:"params",variants:[{begin:e.UNDERSCORE_IDENT_RE,relevance:0},{
className:null,begin:/\(\s*\)/,skip:!0},{begin:/\(/,end:/\)/,excludeBegin:!0,
excludeEnd:!0,keywords:i,contains:p}]}]},{begin:/,/,relevance:0},{match:/\s+/,
relevance:0},{variants:[{begin:"<>",end:"</>"},{
match:/<[A-Za-z0-9\\._:-]+\s*\/>/},{begin:a.begin,
"on:begin":a.isTrulyOpeningTag,end:a.end}],subLanguage:"xml",contains:[{
begin:a.begin,end:a.end,skip:!0,contains:["self"]}]}]},E,{
beginKeywords:"while if switch catch for"},{
begin:"\\b(?!function)"+e.UNDERSCORE_IDENT_RE+"\\([^()]*(\\([^()]*(\\([^()]*\\)[^()]*)*\\)[^()]*)*\\)\\s*\\{",
returnBegin:!0,label:"func.def",contains:[_,e.inherit(e.TITLE_MODE,{begin:t,
className:"title.function"})]},{match:/\.\.\./,relevance:0},w,{match:"\\$"+t,
relevance:0},{match:[/\bconstructor(?=\s*\()/],className:{1:"title.function"},
contains:[_]},y,{relevance:0,match:/\b[A-Z][A-Z_0-9]+\b/,
className:"variable.constant"},h,v,{match:/\$[(.]/}]}}
const we=e=>m(/\b/,e,/\w$/.test(e)?/\b/:/\B/),ve=["Protocol","Type"].map(we),Oe=["init","self"].map(we),xe=["Any","Self"],Me=["actor","associatedtype","async","await",/as\?/,/as!/,"as","break","case","catch","class","continue","convenience","default","defer","deinit","didSet","do","dynamic","else","enum","extension","fallthrough",/fileprivate\(set\)/,"fileprivate","final","for","func","get","guard","if","import","indirect","infix",/init\?/,/init!/,"inout",/internal\(set\)/,"internal","in","is","isolated","nonisolated","lazy","let","mutating","nonmutating",/open\(set\)/,"open","operator","optional","override","postfix","precedencegroup","prefix",/private\(set\)/,"private","protocol",/public\(set\)/,"public","repeat","required","rethrows","return","set","some","static","struct","subscript","super","switch","throws","throw",/try\?/,/try!/,"try","typealias",/unowned\(safe\)/,/unowned\(unsafe\)/,"unowned","var","weak","where","while","willSet"],ke=["false","nil","true"],Se=["assignment","associativity","higherThan","left","lowerThan","none","right"],Ae=["#colorLiteral","#column","#dsohandle","#else","#elseif","#endif","#error","#file","#fileID","#fileLiteral","#filePath","#function","#if","#imageLiteral","#keyPath","#line","#selector","#sourceLocation","#warn_unqualified_access","#warning"],Ce=["abs","all","any","assert","assertionFailure","debugPrint","dump","fatalError","getVaList","isKnownUniquelyReferenced","max","min","numericCast","pointwiseMax","pointwiseMin","precondition","preconditionFailure","print","readLine","repeatElement","sequence","stride","swap","swift_unboxFromSwiftValueWithType","transcode","type","unsafeBitCast","unsafeDowncast","withExtendedLifetime","withUnsafeMutablePointer","withUnsafePointer","withVaList","withoutActuallyEscaping","zip"],Te=p(/[/=\-+!*%<>&|^~?]/,/[\u00A1-\u00A7]/,/[\u00A9\u00AB]/,/[\u00AC\u00AE]/,/[\u00B0\u00B1]/,/[\u00B6\u00BB\u00BF\u00D7\u00F7]/,/[\u2016-\u2017]/,/[\u2020-\u2027]/,/[\u2030-\u203E]/,/[\u2041-\u2053]/,/[\u2055-\u205E]/,/[\u2190-\u23FF]/,/[\u2500-\u2775]/,/[\u2794-\u2BFF]/,/[\u2E00-\u2E7F]/,/[\u3001-\u3003]/,/[\u3008-\u3020]/,/[\u3030]/),Re=p(Te,/[\u0300-\u036F]/,/[\u1DC0-\u1DFF]/,/[\u20D0-\u20FF]/,/[\uFE00-\uFE0F]/,/[\uFE20-\uFE2F]/),De=m(Te,Re,"*"),Ie=p(/[a-zA-Z_]/,/[\u00A8\u00AA\u00AD\u00AF\u00B2-\u00B5\u00B7-\u00BA]/,/[\u00BC-\u00BE\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u00FF]/,/[\u0100-\u02FF\u0370-\u167F\u1681-\u180D\u180F-\u1DBF]/,/[\u1E00-\u1FFF]/,/[\u200B-\u200D\u202A-\u202E\u203F-\u2040\u2054\u2060-\u206F]/,/[\u2070-\u20CF\u2100-\u218F\u2460-\u24FF\u2776-\u2793]/,/[\u2C00-\u2DFF\u2E80-\u2FFF]/,/[\u3004-\u3007\u3021-\u302F\u3031-\u303F\u3040-\uD7FF]/,/[\uF900-\uFD3D\uFD40-\uFDCF\uFDF0-\uFE1F\uFE30-\uFE44]/,/[\uFE47-\uFEFE\uFF00-\uFFFD]/),Le=p(Ie,/\d/,/[\u0300-\u036F\u1DC0-\u1DFF\u20D0-\u20FF\uFE20-\uFE2F]/),Be=m(Ie,Le,"*"),$e=m(/[A-Z]/,Le,"*"),Fe=["autoclosure",m(/convention\(/,p("swift","block","c"),/\)/),"discardableResult","dynamicCallable","dynamicMemberLookup","escaping","frozen","GKInspectable","IBAction","IBDesignable","IBInspectable","IBOutlet","IBSegueAction","inlinable","main","nonobjc","NSApplicationMain","NSCopying","NSManaged",m(/objc\(/,Be,/\)/),"objc","objcMembers","propertyWrapper","requires_stored_property_inits","resultBuilder","testable","UIApplicationMain","unknown","usableFromInline"],ze=["iOS","iOSApplicationExtension","macOS","macOSApplicationExtension","macCatalyst","macCatalystApplicationExtension","watchOS","watchOSApplicationExtension","tvOS","tvOSApplicationExtension","swift"]
;var Ue=Object.freeze({__proto__:null,grmr_bash:e=>{const n=e.regex,t={},a={
begin:/\$\{/,end:/\}/,contains:["self",{begin:/:-/,contains:[t]}]}
;Object.assign(t,{className:"variable",variants:[{
begin:n.concat(/\$[\w\d#@][\w\d_]*/,"(?![\\w\\d])(?![$])")},a]});const i={
className:"subst",begin:/\$\(/,end:/\)/,contains:[e.BACKSLASH_ESCAPE]},r={
begin:/<<-?\s*(?=\w+)/,starts:{contains:[e.END_SAME_AS_BEGIN({begin:/(\w+)/,
end:/(\w+)/,className:"string"})]}},s={className:"string",begin:/"/,end:/"/,
contains:[e.BACKSLASH_ESCAPE,t,i]};i.contains.push(s);const o={begin:/\$\(\(/,
end:/\)\)/,contains:[{begin:/\d+#[0-9a-f]+/,className:"number"},e.NUMBER_MODE,t]
},l=e.SHEBANG({binary:"(fish|bash|zsh|sh|csh|ksh|tcsh|dash|scsh)",relevance:10
}),c={className:"function",begin:/\w[\w\d_]*\s*\(\s*\)\s*\{/,returnBegin:!0,
contains:[e.inherit(e.TITLE_MODE,{begin:/\w[\w\d_]*/})],relevance:0};return{
name:"Bash",aliases:["sh"],keywords:{$pattern:/\b[a-z._-]+\b/,
keyword:["if","then","else","elif","fi","for","while","in","do","done","case","esac","function"],
literal:["true","false"],
built_in:["break","cd","continue","eval","exec","exit","export","getopts","hash","pwd","readonly","return","shift","test","times","trap","umask","unset","alias","bind","builtin","caller","command","declare","echo","enable","help","let","local","logout","mapfile","printf","read","readarray","source","type","typeset","ulimit","unalias","set","shopt","autoload","bg","bindkey","bye","cap","chdir","clone","comparguments","compcall","compctl","compdescribe","compfiles","compgroups","compquote","comptags","comptry","compvalues","dirs","disable","disown","echotc","echoti","emulate","fc","fg","float","functions","getcap","getln","history","integer","jobs","kill","limit","log","noglob","popd","print","pushd","pushln","rehash","sched","setcap","setopt","stat","suspend","ttyctl","unfunction","unhash","unlimit","unsetopt","vared","wait","whence","where","which","zcompile","zformat","zftp","zle","zmodload","zparseopts","zprof","zpty","zregexparse","zsocket","zstyle","ztcp","chcon","chgrp","chown","chmod","cp","dd","df","dir","dircolors","ln","ls","mkdir","mkfifo","mknod","mktemp","mv","realpath","rm","rmdir","shred","sync","touch","truncate","vdir","b2sum","base32","base64","cat","cksum","comm","csplit","cut","expand","fmt","fold","head","join","md5sum","nl","numfmt","od","paste","ptx","pr","sha1sum","sha224sum","sha256sum","sha384sum","sha512sum","shuf","sort","split","sum","tac","tail","tr","tsort","unexpand","uniq","wc","arch","basename","chroot","date","dirname","du","echo","env","expr","factor","groups","hostid","id","link","logname","nice","nohup","nproc","pathchk","pinky","printenv","printf","pwd","readlink","runcon","seq","sleep","stat","stdbuf","stty","tee","test","timeout","tty","uname","unlink","uptime","users","who","whoami","yes"]
},contains:[l,e.SHEBANG(),c,o,e.HASH_COMMENT_MODE,r,{match:/(\/[a-z._-]+)+/},s,{
className:"",begin:/\\"/},{className:"string",begin:/'/,end:/'/},t]}},
grmr_c:e=>{const n=e.regex,t=e.COMMENT("//","$",{contains:[{begin:/\\\n/}]
}),a="[a-zA-Z_]\\w*::",i="(decltype\\(auto\\)|"+n.optional(a)+"[a-zA-Z_]\\w*"+n.optional("<[^<>]+>")+")",r={
className:"type",variants:[{begin:"\\b[a-z\\d_]*_t\\b"},{
match:/\batomic_[a-z]{3,6}\b/}]},s={className:"string",variants:[{
begin:'(u8?|U|L)?"',end:'"',illegal:"\\n",contains:[e.BACKSLASH_ESCAPE]},{
begin:"(u8?|U|L)?'(\\\\(x[0-9A-Fa-f]{2}|u[0-9A-Fa-f]{4,8}|[0-7]{3}|\\S)|.)",
end:"'",illegal:"."},e.END_SAME_AS_BEGIN({
begin:/(?:u8?|U|L)?R"([^()\\ ]{0,16})\(/,end:/\)([^()\\ ]{0,16})"/})]},o={
className:"number",variants:[{begin:"\\b(0b[01']+)"},{
begin:"(-?)\\b([\\d']+(\\.[\\d']*)?|\\.[\\d']+)((ll|LL|l|L)(u|U)?|(u|U)(ll|LL|l|L)?|f|F|b|B)"
},{
begin:"(-?)(\\b0[xX][a-fA-F0-9']+|(\\b[\\d']+(\\.[\\d']*)?|\\.[\\d']+)([eE][-+]?[\\d']+)?)"
}],relevance:0},l={className:"meta",begin:/#\s*[a-z]+\b/,end:/$/,keywords:{
keyword:"if else elif endif define undef warning error line pragma _Pragma ifdef ifndef include"
},contains:[{begin:/\\\n/,relevance:0},e.inherit(s,{className:"string"}),{
className:"string",begin:/<.*?>/},t,e.C_BLOCK_COMMENT_MODE]},c={
className:"title",begin:n.optional(a)+e.IDENT_RE,relevance:0
},d=n.optional(a)+e.IDENT_RE+"\\s*\\(",g={
keyword:["asm","auto","break","case","continue","default","do","else","enum","extern","for","fortran","goto","if","inline","register","restrict","return","sizeof","struct","switch","typedef","union","volatile","while","_Alignas","_Alignof","_Atomic","_Generic","_Noreturn","_Static_assert","_Thread_local","alignas","alignof","noreturn","static_assert","thread_local","_Pragma"],
type:["float","double","signed","unsigned","int","short","long","char","void","_Bool","_Complex","_Imaginary","_Decimal32","_Decimal64","_Decimal128","const","static","complex","bool","imaginary"],
literal:"true false NULL",
built_in:"std string wstring cin cout cerr clog stdin stdout stderr stringstream istringstream ostringstream auto_ptr deque list queue stack vector map set pair bitset multiset multimap unordered_set unordered_map unordered_multiset unordered_multimap priority_queue make_pair array shared_ptr abort terminate abs acos asin atan2 atan calloc ceil cosh cos exit exp fabs floor fmod fprintf fputs free frexp fscanf future isalnum isalpha iscntrl isdigit isgraph islower isprint ispunct isspace isupper isxdigit tolower toupper labs ldexp log10 log malloc realloc memchr memcmp memcpy memset modf pow printf putchar puts scanf sinh sin snprintf sprintf sqrt sscanf strcat strchr strcmp strcpy strcspn strlen strncat strncmp strncpy strpbrk strrchr strspn strstr tanh tan vfprintf vprintf vsprintf endl initializer_list unique_ptr"
},u=[l,r,t,e.C_BLOCK_COMMENT_MODE,o,s],b={variants:[{begin:/=/,end:/;/},{
begin:/\(/,end:/\)/},{beginKeywords:"new throw return else",end:/;/}],
keywords:g,contains:u.concat([{begin:/\(/,end:/\)/,keywords:g,
contains:u.concat(["self"]),relevance:0}]),relevance:0},m={
begin:"("+i+"[\\*&\\s]+)+"+d,returnBegin:!0,end:/[{;=]/,excludeEnd:!0,
keywords:g,illegal:/[^\w\s\*&:<>.]/,contains:[{begin:"decltype\\(auto\\)",
keywords:g,relevance:0},{begin:d,returnBegin:!0,contains:[e.inherit(c,{
className:"title.function"})],relevance:0},{relevance:0,match:/,/},{
className:"params",begin:/\(/,end:/\)/,keywords:g,relevance:0,
contains:[t,e.C_BLOCK_COMMENT_MODE,s,o,r,{begin:/\(/,end:/\)/,keywords:g,
relevance:0,contains:["self",t,e.C_BLOCK_COMMENT_MODE,s,o,r]}]
},r,t,e.C_BLOCK_COMMENT_MODE,l]};return{name:"C",aliases:["h"],keywords:g,
disableAutodetect:!0,illegal:"</",contains:[].concat(b,m,u,[l,{
begin:e.IDENT_RE+"::",keywords:g},{className:"class",
beginKeywords:"enum class struct union",end:/[{;:<>=]/,contains:[{
beginKeywords:"final class struct"},e.TITLE_MODE]}]),exports:{preprocessor:l,
strings:s,keywords:g}}},grmr_cpp:e=>{const n=e.regex,t=e.COMMENT("//","$",{
contains:[{begin:/\\\n/}]
}),a="[a-zA-Z_]\\w*::",i="(?!struct)(decltype\\(auto\\)|"+n.optional(a)+"[a-zA-Z_]\\w*"+n.optional("<[^<>]+>")+")",r={
className:"type",begin:"\\b[a-z\\d_]*_t\\b"},s={className:"string",variants:[{
begin:'(u8?|U|L)?"',end:'"',illegal:"\\n",contains:[e.BACKSLASH_ESCAPE]},{
begin:"(u8?|U|L)?'(\\\\(x[0-9A-Fa-f]{2}|u[0-9A-Fa-f]{4,8}|[0-7]{3}|\\S)|.)",
end:"'",illegal:"."},e.END_SAME_AS_BEGIN({
begin:/(?:u8?|U|L)?R"([^()\\ ]{0,16})\(/,end:/\)([^()\\ ]{0,16})"/})]},o={
className:"number",variants:[{begin:"\\b(0b[01']+)"},{
begin:"(-?)\\b([\\d']+(\\.[\\d']*)?|\\.[\\d']+)((ll|LL|l|L)(u|U)?|(u|U)(ll|LL|l|L)?|f|F|b|B)"
},{
begin:"(-?)(\\b0[xX][a-fA-F0-9']+|(\\b[\\d']+(\\.[\\d']*)?|\\.[\\d']+)([eE][-+]?[\\d']+)?)"
}],relevance:0},l={className:"meta",begin:/#\s*[a-z]+\b/,end:/$/,keywords:{
keyword:"if else elif endif define undef warning error line pragma _Pragma ifdef ifndef include"
},contains:[{begin:/\\\n/,relevance:0},e.inherit(s,{className:"string"}),{
className:"string",begin:/<.*?>/},t,e.C_BLOCK_COMMENT_MODE]},c={
className:"title",begin:n.optional(a)+e.IDENT_RE,relevance:0
},d=n.optional(a)+e.IDENT_RE+"\\s*\\(",g={
type:["bool","char","char16_t","char32_t","char8_t","double","float","int","long","short","void","wchar_t","unsigned","signed","const","static"],
keyword:["alignas","alignof","and","and_eq","asm","atomic_cancel","atomic_commit","atomic_noexcept","auto","bitand","bitor","break","case","catch","class","co_await","co_return","co_yield","compl","concept","const_cast|10","consteval","constexpr","constinit","continue","decltype","default","delete","do","dynamic_cast|10","else","enum","explicit","export","extern","false","final","for","friend","goto","if","import","inline","module","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","override","private","protected","public","reflexpr","register","reinterpret_cast|10","requires","return","sizeof","static_assert","static_cast|10","struct","switch","synchronized","template","this","thread_local","throw","transaction_safe","transaction_safe_dynamic","true","try","typedef","typeid","typename","union","using","virtual","volatile","while","xor","xor_eq"],
literal:["NULL","false","nullopt","nullptr","true"],built_in:["_Pragma"],
_type_hints:["any","auto_ptr","barrier","binary_semaphore","bitset","complex","condition_variable","condition_variable_any","counting_semaphore","deque","false_type","future","imaginary","initializer_list","istringstream","jthread","latch","lock_guard","multimap","multiset","mutex","optional","ostringstream","packaged_task","pair","promise","priority_queue","queue","recursive_mutex","recursive_timed_mutex","scoped_lock","set","shared_future","shared_lock","shared_mutex","shared_timed_mutex","shared_ptr","stack","string_view","stringstream","timed_mutex","thread","true_type","tuple","unique_lock","unique_ptr","unordered_map","unordered_multimap","unordered_multiset","unordered_set","variant","vector","weak_ptr","wstring","wstring_view"]
},u={className:"function.dispatch",relevance:0,keywords:{
_hint:["abort","abs","acos","apply","as_const","asin","atan","atan2","calloc","ceil","cerr","cin","clog","cos","cosh","cout","declval","endl","exchange","exit","exp","fabs","floor","fmod","forward","fprintf","fputs","free","frexp","fscanf","future","invoke","isalnum","isalpha","iscntrl","isdigit","isgraph","islower","isprint","ispunct","isspace","isupper","isxdigit","labs","launder","ldexp","log","log10","make_pair","make_shared","make_shared_for_overwrite","make_tuple","make_unique","malloc","memchr","memcmp","memcpy","memset","modf","move","pow","printf","putchar","puts","realloc","scanf","sin","sinh","snprintf","sprintf","sqrt","sscanf","std","stderr","stdin","stdout","strcat","strchr","strcmp","strcpy","strcspn","strlen","strncat","strncmp","strncpy","strpbrk","strrchr","strspn","strstr","swap","tan","tanh","terminate","to_underlying","tolower","toupper","vfprintf","visit","vprintf","vsprintf"]
},
begin:n.concat(/\b/,/(?!decltype)/,/(?!if)/,/(?!for)/,/(?!switch)/,/(?!while)/,e.IDENT_RE,n.lookahead(/(<[^<>]+>|)\s*\(/))
},b=[u,l,r,t,e.C_BLOCK_COMMENT_MODE,o,s],m={variants:[{begin:/=/,end:/;/},{
begin:/\(/,end:/\)/},{beginKeywords:"new throw return else",end:/;/}],
keywords:g,contains:b.concat([{begin:/\(/,end:/\)/,keywords:g,
contains:b.concat(["self"]),relevance:0}]),relevance:0},p={className:"function",
begin:"("+i+"[\\*&\\s]+)+"+d,returnBegin:!0,end:/[{;=]/,excludeEnd:!0,
keywords:g,illegal:/[^\w\s\*&:<>.]/,contains:[{begin:"decltype\\(auto\\)",
keywords:g,relevance:0},{begin:d,returnBegin:!0,contains:[c],relevance:0},{
begin:/::/,relevance:0},{begin:/:/,endsWithParent:!0,contains:[s,o]},{
relevance:0,match:/,/},{className:"params",begin:/\(/,end:/\)/,keywords:g,
relevance:0,contains:[t,e.C_BLOCK_COMMENT_MODE,s,o,r,{begin:/\(/,end:/\)/,
keywords:g,relevance:0,contains:["self",t,e.C_BLOCK_COMMENT_MODE,s,o,r]}]
},r,t,e.C_BLOCK_COMMENT_MODE,l]};return{name:"C++",
aliases:["cc","c++","h++","hpp","hh","hxx","cxx"],keywords:g,illegal:"</",
classNameAliases:{"function.dispatch":"built_in"},
contains:[].concat(m,p,u,b,[l,{
begin:"\\b(deque|list|queue|priority_queue|pair|stack|vector|map|set|bitset|multiset|multimap|unordered_map|unordered_set|unordered_multiset|unordered_multimap|array|tuple|optional|variant|function)\\s*<(?!<)",
end:">",keywords:g,contains:["self",r]},{begin:e.IDENT_RE+"::",keywords:g},{
match:[/\b(?:enum(?:\s+(?:class|struct))?|class|struct|union)/,/\s+/,/\w+/],
className:{1:"keyword",3:"title.class"}}])}},grmr_csharp:e=>{const n={
keyword:["abstract","as","base","break","case","catch","class","const","continue","do","else","event","explicit","extern","finally","fixed","for","foreach","goto","if","implicit","in","interface","internal","is","lock","namespace","new","operator","out","override","params","private","protected","public","readonly","record","ref","return","sealed","sizeof","stackalloc","static","struct","switch","this","throw","try","typeof","unchecked","unsafe","using","virtual","void","volatile","while"].concat(["add","alias","and","ascending","async","await","by","descending","equals","from","get","global","group","init","into","join","let","nameof","not","notnull","on","or","orderby","partial","remove","select","set","unmanaged","value|0","var","when","where","with","yield"]),
built_in:["bool","byte","char","decimal","delegate","double","dynamic","enum","float","int","long","nint","nuint","object","sbyte","short","string","ulong","uint","ushort"],
literal:["default","false","null","true"]},t=e.inherit(e.TITLE_MODE,{
begin:"[a-zA-Z](\\.?\\w)*"}),a={className:"number",variants:[{
begin:"\\b(0b[01']+)"},{
begin:"(-?)\\b([\\d']+(\\.[\\d']*)?|\\.[\\d']+)(u|U|l|L|ul|UL|f|F|b|B)"},{
begin:"(-?)(\\b0[xX][a-fA-F0-9']+|(\\b[\\d']+(\\.[\\d']*)?|\\.[\\d']+)([eE][-+]?[\\d']+)?)"
}],relevance:0},i={className:"string",begin:'@"',end:'"',contains:[{begin:'""'}]
},r=e.inherit(i,{illegal:/\n/}),s={className:"subst",begin:/\{/,end:/\}/,
keywords:n},o=e.inherit(s,{illegal:/\n/}),l={className:"string",begin:/\$"/,
end:'"',illegal:/\n/,contains:[{begin:/\{\{/},{begin:/\}\}/
},e.BACKSLASH_ESCAPE,o]},c={className:"string",begin:/\$@"/,end:'"',contains:[{
begin:/\{\{/},{begin:/\}\}/},{begin:'""'},s]},d=e.inherit(c,{illegal:/\n/,
contains:[{begin:/\{\{/},{begin:/\}\}/},{begin:'""'},o]})
;s.contains=[c,l,i,e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,a,e.C_BLOCK_COMMENT_MODE],
o.contains=[d,l,r,e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,a,e.inherit(e.C_BLOCK_COMMENT_MODE,{
illegal:/\n/})];const g={variants:[c,l,i,e.APOS_STRING_MODE,e.QUOTE_STRING_MODE]
},u={begin:"<",end:">",contains:[{beginKeywords:"in out"},t]
},b=e.IDENT_RE+"(<"+e.IDENT_RE+"(\\s*,\\s*"+e.IDENT_RE+")*>)?(\\[\\])?",m={
begin:"@"+e.IDENT_RE,relevance:0};return{name:"C#",aliases:["cs","c#"],
keywords:n,illegal:/::/,contains:[e.COMMENT("///","$",{returnBegin:!0,
contains:[{className:"doctag",variants:[{begin:"///",relevance:0},{
begin:"\x3c!--|--\x3e"},{begin:"</?",end:">"}]}]
}),e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,{className:"meta",begin:"#",
end:"$",keywords:{
keyword:"if else elif endif define undef warning error line region endregion pragma checksum"
}},g,a,{beginKeywords:"class interface",relevance:0,end:/[{;=]/,
illegal:/[^\s:,]/,contains:[{beginKeywords:"where class"
},t,u,e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},{beginKeywords:"namespace",
relevance:0,end:/[{;=]/,illegal:/[^\s:]/,
contains:[t,e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},{
beginKeywords:"record",relevance:0,end:/[{;=]/,illegal:/[^\s:]/,
contains:[t,u,e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},{className:"meta",
begin:"^\\s*\\[(?=[\\w])",excludeBegin:!0,end:"\\]",excludeEnd:!0,contains:[{
className:"string",begin:/"/,end:/"/}]},{
beginKeywords:"new return throw await else",relevance:0},{className:"function",
begin:"("+b+"\\s+)+"+e.IDENT_RE+"\\s*(<[^=]+>\\s*)?\\(",returnBegin:!0,
end:/\s*[{;=]/,excludeEnd:!0,keywords:n,contains:[{
beginKeywords:"public private protected static internal protected abstract async extern override unsafe virtual new sealed partial",
relevance:0},{begin:e.IDENT_RE+"\\s*(<[^=]+>\\s*)?\\(",returnBegin:!0,
contains:[e.TITLE_MODE,u],relevance:0},{match:/\(\)/},{className:"params",
begin:/\(/,end:/\)/,excludeBegin:!0,excludeEnd:!0,keywords:n,relevance:0,
contains:[g,a,e.C_BLOCK_COMMENT_MODE]
},e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},m]}},grmr_css:e=>{
const n=e.regex,t=te(e),a=[e.APOS_STRING_MODE,e.QUOTE_STRING_MODE];return{
name:"CSS",case_insensitive:!0,illegal:/[=|'\$]/,keywords:{
keyframePosition:"from to"},classNameAliases:{keyframePosition:"selector-tag"},
contains:[t.BLOCK_COMMENT,{begin:/-(webkit|moz|ms|o)-(?=[a-z])/
},t.CSS_NUMBER_MODE,{className:"selector-id",begin:/#[A-Za-z0-9_-]+/,relevance:0
},{className:"selector-class",begin:"\\.[a-zA-Z-][a-zA-Z0-9_-]*",relevance:0
},t.ATTRIBUTE_SELECTOR_MODE,{className:"selector-pseudo",variants:[{
begin:":("+re.join("|")+")"},{begin:":(:)?("+se.join("|")+")"}]
},t.CSS_VARIABLE,{className:"attribute",begin:"\\b("+oe.join("|")+")\\b"},{
begin:/:/,end:/[;}{]/,
contains:[t.BLOCK_COMMENT,t.HEXCOLOR,t.IMPORTANT,t.CSS_NUMBER_MODE,...a,{
begin:/(url|data-uri)\(/,end:/\)/,relevance:0,keywords:{built_in:"url data-uri"
},contains:[{className:"string",begin:/[^)]/,endsWithParent:!0,excludeEnd:!0}]
},t.FUNCTION_DISPATCH]},{begin:n.lookahead(/@/),end:"[{;]",relevance:0,
illegal:/:/,contains:[{className:"keyword",begin:/@-?\w[\w]*(-\w+)*/},{
begin:/\s/,endsWithParent:!0,excludeEnd:!0,relevance:0,keywords:{
$pattern:/[a-z-]+/,keyword:"and or not only",attribute:ie.join(" ")},contains:[{
begin:/[a-z-]+(?=:)/,className:"attribute"},...a,t.CSS_NUMBER_MODE]}]},{
className:"selector-tag",begin:"\\b("+ae.join("|")+")\\b"}]}},grmr_diff:e=>{
const n=e.regex;return{name:"Diff",aliases:["patch"],contains:[{
className:"meta",relevance:10,
match:n.either(/^@@ +-\d+,\d+ +\+\d+,\d+ +@@/,/^\*\*\* +\d+,\d+ +\*\*\*\*$/,/^--- +\d+,\d+ +----$/)
},{className:"comment",variants:[{
begin:n.either(/Index: /,/^index/,/={3,}/,/^-{3}/,/^\*{3} /,/^\+{3}/,/^diff --git/),
end:/$/},{match:/^\*{15}$/}]},{className:"addition",begin:/^\+/,end:/$/},{
className:"deletion",begin:/^-/,end:/$/},{className:"addition",begin:/^!/,
end:/$/}]}},grmr_go:e=>{const n={
keyword:["break","case","chan","const","continue","default","defer","else","fallthrough","for","func","go","goto","if","import","interface","map","package","range","return","select","struct","switch","type","var"],
type:["bool","byte","complex64","complex128","error","float32","float64","int8","int16","int32","int64","string","uint8","uint16","uint32","uint64","int","uint","uintptr","rune"],
literal:["true","false","iota","nil"],
built_in:["append","cap","close","complex","copy","imag","len","make","new","panic","print","println","real","recover","delete"]
};return{name:"Go",aliases:["golang"],keywords:n,illegal:"</",
contains:[e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,{className:"string",
variants:[e.QUOTE_STRING_MODE,e.APOS_STRING_MODE,{begin:"`",end:"`"}]},{
className:"number",variants:[{begin:e.C_NUMBER_RE+"[i]",relevance:1
},e.C_NUMBER_MODE]},{begin:/:=/},{className:"function",beginKeywords:"func",
end:"\\s*(\\{|$)",excludeEnd:!0,contains:[e.TITLE_MODE,{className:"params",
begin:/\(/,end:/\)/,endsParent:!0,keywords:n,illegal:/["']/}]}]}},grmr_ini:e=>{
const n=e.regex,t={className:"number",relevance:0,variants:[{
begin:/([+-]+)?[\d]+_[\d_]+/},{begin:e.NUMBER_RE}]},a=e.COMMENT();a.variants=[{
begin:/;/,end:/$/},{begin:/#/,end:/$/}];const i={className:"variable",
variants:[{begin:/\$[\w\d"][\w\d_]*/},{begin:/\$\{(.*?)\}/}]},r={
className:"literal",begin:/\bon|off|true|false|yes|no\b/},s={className:"string",
contains:[e.BACKSLASH_ESCAPE],variants:[{begin:"'''",end:"'''",relevance:10},{
begin:'"""',end:'"""',relevance:10},{begin:'"',end:'"'},{begin:"'",end:"'"}]
},o={begin:/\[/,end:/\]/,contains:[a,r,i,s,t,"self"],relevance:0
},l=n.either(/[A-Za-z0-9_-]+/,/"(\\"|[^"])*"/,/'[^']*'/);return{
name:"TOML, also INI",aliases:["toml"],case_insensitive:!0,illegal:/\S/,
contains:[a,{className:"section",begin:/\[+/,end:/\]+/},{
begin:n.concat(l,"(\\s*\\.\\s*",l,")*",n.lookahead(/\s*=\s*[^#\s]/)),
className:"attr",starts:{end:/$/,contains:[a,o,r,i,s,t]}}]}},grmr_java:e=>{
e.regex
;const n="[\xc0-\u02b8a-zA-Z_$][\xc0-\u02b8a-zA-Z_$0-9]*",t=n+ue("(?:<"+n+"~~~(?:\\s*,\\s*"+n+"~~~)*>)?",/~~~/g,2),a={
keyword:["synchronized","abstract","private","var","static","if","const ","for","while","strictfp","finally","protected","import","native","final","void","enum","else","break","transient","catch","instanceof","volatile","case","assert","package","default","public","try","switch","continue","throws","protected","public","private","module","requires","exports","do","sealed"],
literal:["false","true","null"],
type:["char","boolean","long","float","int","byte","short","double"],
built_in:["super","this"]},i={className:"meta",begin:"@"+n,contains:[{
begin:/\(/,end:/\)/,contains:["self"]}]},r={className:"params",begin:/\(/,
end:/\)/,keywords:a,relevance:0,contains:[e.C_BLOCK_COMMENT_MODE],endsParent:!0}
;return{name:"Java",aliases:["jsp"],keywords:a,illegal:/<\/|#/,
contains:[e.COMMENT("/\\*\\*","\\*/",{relevance:0,contains:[{begin:/\w+@/,
relevance:0},{className:"doctag",begin:"@[A-Za-z]+"}]}),{
begin:/import java\.[a-z]+\./,keywords:"import",relevance:2
},e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,{begin:/"""/,end:/"""/,
className:"string",contains:[e.BACKSLASH_ESCAPE]
},e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,{
match:[/\b(?:class|interface|enum|extends|implements|new)/,/\s+/,n],className:{
1:"keyword",3:"title.class"}},{match:/non-sealed/,scope:"keyword"},{
begin:[n,/\s+/,n,/\s+/,/=/],className:{1:"type",3:"variable",5:"operator"}},{
begin:[/record/,/\s+/,n],className:{1:"keyword",3:"title.class"},
contains:[r,e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},{
beginKeywords:"new throw return else",relevance:0},{
begin:["(?:"+t+"\\s+)",e.UNDERSCORE_IDENT_RE,/\s*(?=\()/],className:{
2:"title.function"},keywords:a,contains:[{className:"params",begin:/\(/,
end:/\)/,keywords:a,relevance:0,
contains:[i,e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,ge,e.C_BLOCK_COMMENT_MODE]
},e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},ge,i]}},grmr_javascript:Ne,
grmr_json:e=>({name:"JSON",contains:[{className:"attr",
begin:/"(\\.|[^\\"\r\n])*"(?=\s*:)/,relevance:1.01},{match:/[{}[\],:]/,
className:"punctuation",relevance:0},e.QUOTE_STRING_MODE,{
beginKeywords:"true false null"
},e.C_NUMBER_MODE,e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE],illegal:"\\S"}),
grmr_kotlin:e=>{const n={
keyword:"abstract as val var vararg get set class object open private protected public noinline crossinline dynamic final enum if else do while for when throw try catch finally import package is in fun override companion reified inline lateinit init interface annotation data sealed internal infix operator out by constructor super tailrec where const inner suspend typealias external expect actual",
built_in:"Byte Short Char Int Long Boolean Float Double Void Unit Nothing",
literal:"true false null"},t={className:"symbol",begin:e.UNDERSCORE_IDENT_RE+"@"
},a={className:"subst",begin:/\$\{/,end:/\}/,contains:[e.C_NUMBER_MODE]},i={
className:"variable",begin:"\\$"+e.UNDERSCORE_IDENT_RE},r={className:"string",
variants:[{begin:'"""',end:'"""(?=[^"])',contains:[i,a]},{begin:"'",end:"'",
illegal:/\n/,contains:[e.BACKSLASH_ESCAPE]},{begin:'"',end:'"',illegal:/\n/,
contains:[e.BACKSLASH_ESCAPE,i,a]}]};a.contains.push(r);const s={
className:"meta",
begin:"@(?:file|property|field|get|set|receiver|param|setparam|delegate)\\s*:(?:\\s*"+e.UNDERSCORE_IDENT_RE+")?"
},o={className:"meta",begin:"@"+e.UNDERSCORE_IDENT_RE,contains:[{begin:/\(/,
end:/\)/,contains:[e.inherit(r,{className:"string"})]}]
},l=ge,c=e.COMMENT("/\\*","\\*/",{contains:[e.C_BLOCK_COMMENT_MODE]}),d={
variants:[{className:"type",begin:e.UNDERSCORE_IDENT_RE},{begin:/\(/,end:/\)/,
contains:[]}]},g=d;return g.variants[1].contains=[d],d.variants[1].contains=[g],
{name:"Kotlin",aliases:["kt","kts"],keywords:n,
contains:[e.COMMENT("/\\*\\*","\\*/",{relevance:0,contains:[{className:"doctag",
begin:"@[A-Za-z]+"}]}),e.C_LINE_COMMENT_MODE,c,{className:"keyword",
begin:/\b(break|continue|return|this)\b/,starts:{contains:[{className:"symbol",
begin:/@\w+/}]}},t,s,o,{className:"function",beginKeywords:"fun",end:"[(]|$",
returnBegin:!0,excludeEnd:!0,keywords:n,relevance:5,contains:[{
begin:e.UNDERSCORE_IDENT_RE+"\\s*\\(",returnBegin:!0,relevance:0,
contains:[e.UNDERSCORE_TITLE_MODE]},{className:"type",begin:/</,end:/>/,
keywords:"reified",relevance:0},{className:"params",begin:/\(/,end:/\)/,
endsParent:!0,keywords:n,relevance:0,contains:[{begin:/:/,end:/[=,\/]/,
endsWithParent:!0,contains:[d,e.C_LINE_COMMENT_MODE,c],relevance:0
},e.C_LINE_COMMENT_MODE,c,s,o,r,e.C_NUMBER_MODE]},c]},{className:"class",
beginKeywords:"class interface trait",end:/[:\{(]|$/,excludeEnd:!0,
illegal:"extends implements",contains:[{
beginKeywords:"public protected internal private constructor"
},e.UNDERSCORE_TITLE_MODE,{className:"type",begin:/</,end:/>/,excludeBegin:!0,
excludeEnd:!0,relevance:0},{className:"type",begin:/[,:]\s*/,end:/[<\(,]|$/,
excludeBegin:!0,returnEnd:!0},s,o]},r,{className:"meta",begin:"^#!/usr/bin/env",
end:"$",illegal:"\n"},l]}},grmr_less:e=>{
const n=te(e),t=le,a="([\\w-]+|@\\{[\\w-]+\\})",i=[],r=[],s=e=>({
className:"string",begin:"~?"+e+".*?"+e}),o=(e,n,t)=>({className:e,begin:n,
relevance:t}),l={$pattern:/[a-z-]+/,keyword:"and or not only",
attribute:ie.join(" ")},c={begin:"\\(",end:"\\)",contains:r,keywords:l,
relevance:0}
;r.push(e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,s("'"),s('"'),n.CSS_NUMBER_MODE,{
begin:"(url|data-uri)\\(",starts:{className:"string",end:"[\\)\\n]",
excludeEnd:!0}
},n.HEXCOLOR,c,o("variable","@@?[\\w-]+",10),o("variable","@\\{[\\w-]+\\}"),o("built_in","~?`[^`]*?`"),{
className:"attribute",begin:"[\\w-]+\\s*:",end:":",returnBegin:!0,excludeEnd:!0
},n.IMPORTANT);const d=r.concat({begin:/\{/,end:/\}/,contains:i}),g={
beginKeywords:"when",endsWithParent:!0,contains:[{beginKeywords:"and not"
}].concat(r)},u={begin:a+"\\s*:",returnBegin:!0,end:/[;}]/,relevance:0,
contains:[{begin:/-(webkit|moz|ms|o)-/},n.CSS_VARIABLE,{className:"attribute",
begin:"\\b("+oe.join("|")+")\\b",end:/(?=:)/,starts:{endsWithParent:!0,
illegal:"[<=$]",relevance:0,contains:r}}]},b={className:"keyword",
begin:"@(import|media|charset|font-face|(-[a-z]+-)?keyframes|supports|document|namespace|page|viewport|host)\\b",
starts:{end:"[;{}]",keywords:l,returnEnd:!0,contains:r,relevance:0}},m={
className:"variable",variants:[{begin:"@[\\w-]+\\s*:",relevance:15},{
begin:"@[\\w-]+"}],starts:{end:"[;}]",returnEnd:!0,contains:d}},p={variants:[{
begin:"[\\.#:&\\[>]",end:"[;{}]"},{begin:a,end:/\{/}],returnBegin:!0,
returnEnd:!0,illegal:"[<='$\"]",relevance:0,
contains:[e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,g,o("keyword","all\\b"),o("variable","@\\{[\\w-]+\\}"),{
begin:"\\b("+ae.join("|")+")\\b",className:"selector-tag"
},n.CSS_NUMBER_MODE,o("selector-tag",a,0),o("selector-id","#"+a),o("selector-class","\\."+a,0),o("selector-tag","&",0),n.ATTRIBUTE_SELECTOR_MODE,{
className:"selector-pseudo",begin:":("+re.join("|")+")"},{
className:"selector-pseudo",begin:":(:)?("+se.join("|")+")"},{begin:/\(/,
end:/\)/,relevance:0,contains:d},{begin:"!important"},n.FUNCTION_DISPATCH]},_={
begin:`[\\w-]+:(:)?(${t.join("|")})`,returnBegin:!0,contains:[p]}
;return i.push(e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,b,m,_,u,p),{
name:"Less",case_insensitive:!0,illegal:"[=>'/<($\"]",contains:i}},grmr_lua:e=>{
const n="\\[=*\\[",t="\\]=*\\]",a={begin:n,end:t,contains:["self"]
},i=[e.COMMENT("--(?!\\[=*\\[)","$"),e.COMMENT("--\\[=*\\[",t,{contains:[a],
relevance:10})];return{name:"Lua",keywords:{$pattern:e.UNDERSCORE_IDENT_RE,
literal:"true false nil",
keyword:"and break do else elseif end for goto if in local not or repeat return then until while",
built_in:"_G _ENV _VERSION __index __newindex __mode __call __metatable __tostring __len __gc __add __sub __mul __div __mod __pow __concat __unm __eq __lt __le assert collectgarbage dofile error getfenv getmetatable ipairs load loadfile loadstring module next pairs pcall print rawequal rawget rawset require select setfenv setmetatable tonumber tostring type unpack xpcall arg self coroutine resume yield status wrap create running debug getupvalue debug sethook getmetatable gethook setmetatable setlocal traceback setfenv getinfo setupvalue getlocal getregistry getfenv io lines write close flush open output type read stderr stdin input stdout popen tmpfile math log max acos huge ldexp pi cos tanh pow deg tan cosh sinh random randomseed frexp ceil floor rad abs sqrt modf asin min mod fmod log10 atan2 exp sin atan os exit setlocale date getenv difftime remove time clock tmpname rename execute package preload loadlib loaded loaders cpath config path seeall string sub upper len gfind rep find match char dump gmatch reverse byte format gsub lower table setn insert getn foreachi maxn foreach concat sort remove"
},contains:i.concat([{className:"function",beginKeywords:"function",end:"\\)",
contains:[e.inherit(e.TITLE_MODE,{
begin:"([_a-zA-Z]\\w*\\.)*([_a-zA-Z]\\w*:)?[_a-zA-Z]\\w*"}),{className:"params",
begin:"\\(",endsWithParent:!0,contains:i}].concat(i)
},e.C_NUMBER_MODE,e.APOS_STRING_MODE,e.QUOTE_STRING_MODE,{className:"string",
begin:n,end:t,contains:[a],relevance:5}])}},grmr_makefile:e=>{const n={
className:"variable",variants:[{begin:"\\$\\("+e.UNDERSCORE_IDENT_RE+"\\)",
contains:[e.BACKSLASH_ESCAPE]},{begin:/\$[@%<?\^\+\*]/}]},t={className:"string",
begin:/"/,end:/"/,contains:[e.BACKSLASH_ESCAPE,n]},a={className:"variable",
begin:/\$\([\w-]+\s/,end:/\)/,keywords:{
built_in:"subst patsubst strip findstring filter filter-out sort word wordlist firstword lastword dir notdir suffix basename addsuffix addprefix join wildcard realpath abspath error warning shell origin flavor foreach if or and call eval file value"
},contains:[n]},i={begin:"^"+e.UNDERSCORE_IDENT_RE+"\\s*(?=[:+?]?=)"},r={
className:"section",begin:/^[^\s]+:/,end:/$/,contains:[n]};return{
name:"Makefile",aliases:["mk","mak","make"],keywords:{$pattern:/[\w-]+/,
keyword:"define endef undefine ifdef ifndef ifeq ifneq else endif include -include sinclude override export unexport private vpath"
},contains:[e.HASH_COMMENT_MODE,n,t,a,i,{className:"meta",begin:/^\.PHONY:/,
end:/$/,keywords:{$pattern:/[\.\w]+/,keyword:".PHONY"}},r]}},grmr_xml:e=>{
const n=e.regex,t=n.concat(/[A-Z_]/,n.optional(/[A-Z0-9_.-]*:/),/[A-Z0-9_.-]*/),a={
className:"symbol",begin:/&[a-z]+;|&#[0-9]+;|&#x[a-f0-9]+;/},i={begin:/\s/,
contains:[{className:"keyword",begin:/#?[a-z_][a-z1-9_-]+/,illegal:/\n/}]
},r=e.inherit(i,{begin:/\(/,end:/\)/}),s=e.inherit(e.APOS_STRING_MODE,{
className:"string"}),o=e.inherit(e.QUOTE_STRING_MODE,{className:"string"}),l={
endsWithParent:!0,illegal:/</,relevance:0,contains:[{className:"attr",
begin:/[A-Za-z0-9._:-]+/,relevance:0},{begin:/=\s*/,relevance:0,contains:[{
className:"string",endsParent:!0,variants:[{begin:/"/,end:/"/,contains:[a]},{
begin:/'/,end:/'/,contains:[a]},{begin:/[^\s"'=<>`]+/}]}]}]};return{
name:"HTML, XML",
aliases:["html","xhtml","rss","atom","xjb","xsd","xsl","plist","wsf","svg"],
case_insensitive:!0,contains:[{className:"meta",begin:/<![a-z]/,end:/>/,
relevance:10,contains:[i,o,s,r,{begin:/\[/,end:/\]/,contains:[{className:"meta",
begin:/<![a-z]/,end:/>/,contains:[i,r,o,s]}]}]},e.COMMENT(/<!--/,/-->/,{
relevance:10}),{begin:/<!\[CDATA\[/,end:/\]\]>/,relevance:10},a,{
className:"meta",begin:/<\?xml/,end:/\?>/,relevance:10},{className:"tag",
begin:/<style(?=\s|>)/,end:/>/,keywords:{name:"style"},contains:[l],starts:{
end:/<\/style>/,returnEnd:!0,subLanguage:["css","xml"]}},{className:"tag",
begin:/<script(?=\s|>)/,end:/>/,keywords:{name:"script"},contains:[l],starts:{
end:/<\/script>/,returnEnd:!0,subLanguage:["javascript","handlebars","xml"]}},{
className:"tag",begin:/<>|<\/>/},{className:"tag",
begin:n.concat(/</,n.lookahead(n.concat(t,n.either(/\/>/,/>/,/\s/)))),
end:/\/?>/,contains:[{className:"name",begin:t,relevance:0,starts:l}]},{
className:"tag",begin:n.concat(/<\//,n.lookahead(n.concat(t,/>/))),contains:[{
className:"name",begin:t,relevance:0},{begin:/>/,relevance:0,endsParent:!0}]}]}
},grmr_markdown:e=>{const n={begin:/<\/?[A-Za-z_]/,end:">",subLanguage:"xml",
relevance:0},t={variants:[{begin:/\[.+?\]\[.*?\]/,relevance:0},{
begin:/\[.+?\]\(((data|javascript|mailto):|(?:http|ftp)s?:\/\/).*?\)/,
relevance:2},{
begin:e.regex.concat(/\[.+?\]\(/,/[A-Za-z][A-Za-z0-9+.-]*/,/:\/\/.*?\)/),
relevance:2},{begin:/\[.+?\]\([./?&#].*?\)/,relevance:1},{
begin:/\[.*?\]\(.*?\)/,relevance:0}],returnBegin:!0,contains:[{match:/\[(?=\])/
},{className:"string",relevance:0,begin:"\\[",end:"\\]",excludeBegin:!0,
returnEnd:!0},{className:"link",relevance:0,begin:"\\]\\(",end:"\\)",
excludeBegin:!0,excludeEnd:!0},{className:"symbol",relevance:0,begin:"\\]\\[",
end:"\\]",excludeBegin:!0,excludeEnd:!0}]},a={className:"strong",contains:[],
variants:[{begin:/_{2}/,end:/_{2}/},{begin:/\*{2}/,end:/\*{2}/}]},i={
className:"emphasis",contains:[],variants:[{begin:/\*(?!\*)/,end:/\*/},{
begin:/_(?!_)/,end:/_/,relevance:0}]};a.contains.push(i),i.contains.push(a)
;let r=[n,t]
;return a.contains=a.contains.concat(r),i.contains=i.contains.concat(r),
r=r.concat(a,i),{name:"Markdown",aliases:["md","mkdown","mkd"],contains:[{
className:"section",variants:[{begin:"^#{1,6}",end:"$",contains:r},{
begin:"(?=^.+?\\n[=-]{2,}$)",contains:[{begin:"^[=-]*$"},{begin:"^",end:"\\n",
contains:r}]}]},n,{className:"bullet",begin:"^[ \t]*([*+-]|(\\d+\\.))(?=\\s+)",
end:"\\s+",excludeEnd:!0},a,i,{className:"quote",begin:"^>\\s+",contains:r,
end:"$"},{className:"code",variants:[{begin:"(`{3,})[^`](.|\\n)*?\\1`*[ ]*"},{
begin:"(~{3,})[^~](.|\\n)*?\\1~*[ ]*"},{begin:"```",end:"```+[ ]*$"},{
begin:"~~~",end:"~~~+[ ]*$"},{begin:"`.+?`"},{begin:"(?=^( {4}|\\t))",
contains:[{begin:"^( {4}|\\t)",end:"(\\n)$"}],relevance:0}]},{
begin:"^[-\\*]{3,}",end:"$"},t,{begin:/^\[[^\n]+\]:/,returnBegin:!0,contains:[{
className:"symbol",begin:/\[/,end:/\]/,excludeBegin:!0,excludeEnd:!0},{
className:"link",begin:/:\s*/,end:/$/,excludeBegin:!0}]}]}},grmr_objectivec:e=>{
const n=/[a-zA-Z@][a-zA-Z0-9_]*/,t={$pattern:n,
keyword:["@interface","@class","@protocol","@implementation"]};return{
name:"Objective-C",aliases:["mm","objc","obj-c","obj-c++","objective-c++"],
keywords:{$pattern:n,
keyword:["int","float","while","char","export","sizeof","typedef","const","struct","for","union","unsigned","long","volatile","static","bool","mutable","if","do","return","goto","void","enum","else","break","extern","asm","case","short","default","double","register","explicit","signed","typename","this","switch","continue","wchar_t","inline","readonly","assign","readwrite","self","@synchronized","id","typeof","nonatomic","super","unichar","IBOutlet","IBAction","strong","weak","copy","in","out","inout","bycopy","byref","oneway","__strong","__weak","__block","__autoreleasing","@private","@protected","@public","@try","@property","@end","@throw","@catch","@finally","@autoreleasepool","@synthesize","@dynamic","@selector","@optional","@required","@encode","@package","@import","@defs","@compatibility_alias","__bridge","__bridge_transfer","__bridge_retained","__bridge_retain","__covariant","__contravariant","__kindof","_Nonnull","_Nullable","_Null_unspecified","__FUNCTION__","__PRETTY_FUNCTION__","__attribute__","getter","setter","retain","unsafe_unretained","nonnull","nullable","null_unspecified","null_resettable","class","instancetype","NS_DESIGNATED_INITIALIZER","NS_UNAVAILABLE","NS_REQUIRES_SUPER","NS_RETURNS_INNER_POINTER","NS_INLINE","NS_AVAILABLE","NS_DEPRECATED","NS_ENUM","NS_OPTIONS","NS_SWIFT_UNAVAILABLE","NS_ASSUME_NONNULL_BEGIN","NS_ASSUME_NONNULL_END","NS_REFINED_FOR_SWIFT","NS_SWIFT_NAME","NS_SWIFT_NOTHROW","NS_DURING","NS_HANDLER","NS_ENDHANDLER","NS_VALUERETURN","NS_VOIDRETURN"],
literal:["false","true","FALSE","TRUE","nil","YES","NO","NULL"],
built_in:["BOOL","dispatch_once_t","dispatch_queue_t","dispatch_sync","dispatch_async","dispatch_once"]
},illegal:"</",contains:[{className:"built_in",
begin:"\\b(AV|CA|CF|CG|CI|CL|CM|CN|CT|MK|MP|MTK|MTL|NS|SCN|SK|UI|WK|XC)\\w+"
},e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,e.C_NUMBER_MODE,e.QUOTE_STRING_MODE,e.APOS_STRING_MODE,{
className:"string",variants:[{begin:'@"',end:'"',illegal:"\\n",
contains:[e.BACKSLASH_ESCAPE]}]},{className:"meta",begin:/#\s*[a-z]+\b/,end:/$/,
keywords:{
keyword:"if else elif endif define undef warning error line pragma ifdef ifndef include"
},contains:[{begin:/\\\n/,relevance:0},e.inherit(e.QUOTE_STRING_MODE,{
className:"string"}),{className:"string",begin:/<.*?>/,end:/$/,illegal:"\\n"
},e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE]},{className:"class",
begin:"("+t.keyword.join("|")+")\\b",end:/(\{|$)/,excludeEnd:!0,keywords:t,
contains:[e.UNDERSCORE_TITLE_MODE]},{begin:"\\."+e.UNDERSCORE_IDENT_RE,
relevance:0}]}},grmr_perl:e=>{const n=e.regex,t=/[dualxmsipngr]{0,12}/,a={
$pattern:/[\w.]+/,
keyword:"abs accept alarm and atan2 bind binmode bless break caller chdir chmod chomp chop chown chr chroot close closedir connect continue cos crypt dbmclose dbmopen defined delete die do dump each else elsif endgrent endhostent endnetent endprotoent endpwent endservent eof eval exec exists exit exp fcntl fileno flock for foreach fork format formline getc getgrent getgrgid getgrnam gethostbyaddr gethostbyname gethostent getlogin getnetbyaddr getnetbyname getnetent getpeername getpgrp getpriority getprotobyname getprotobynumber getprotoent getpwent getpwnam getpwuid getservbyname getservbyport getservent getsockname getsockopt given glob gmtime goto grep gt hex if index int ioctl join keys kill last lc lcfirst length link listen local localtime log lstat lt ma map mkdir msgctl msgget msgrcv msgsnd my ne next no not oct open opendir or ord our pack package pipe pop pos print printf prototype push q|0 qq quotemeta qw qx rand read readdir readline readlink readpipe recv redo ref rename require reset return reverse rewinddir rindex rmdir say scalar seek seekdir select semctl semget semop send setgrent sethostent setnetent setpgrp setpriority setprotoent setpwent setservent setsockopt shift shmctl shmget shmread shmwrite shutdown sin sleep socket socketpair sort splice split sprintf sqrt srand stat state study sub substr symlink syscall sysopen sysread sysseek system syswrite tell telldir tie tied time times tr truncate uc ucfirst umask undef unless unlink unpack unshift untie until use utime values vec wait waitpid wantarray warn when while write x|0 xor y|0"
},i={className:"subst",begin:"[$@]\\{",end:"\\}",keywords:a},r={begin:/->\{/,
end:/\}/},s={variants:[{begin:/\$\d/},{
begin:n.concat(/[$%@](\^\w\b|#\w+(::\w+)*|\{\w+\}|\w+(::\w*)*)/,"(?![A-Za-z])(?![@$%])")
},{begin:/[$%@][^\s\w{]/,relevance:0}]
},o=[e.BACKSLASH_ESCAPE,i,s],l=[/!/,/\//,/\|/,/\?/,/'/,/"/,/#/],c=(e,a,i="\\1")=>{
const r="\\1"===i?i:n.concat(i,a)
;return n.concat(n.concat("(?:",e,")"),a,/(?:\\.|[^\\\/])*?/,r,/(?:\\.|[^\\\/])*?/,i,t)
},d=(e,a,i)=>n.concat(n.concat("(?:",e,")"),a,/(?:\\.|[^\\\/])*?/,i,t),g=[s,e.HASH_COMMENT_MODE,e.COMMENT(/^=\w/,/=cut/,{
endsWithParent:!0}),r,{className:"string",contains:o,variants:[{
begin:"q[qwxr]?\\s*\\(",end:"\\)",relevance:5},{begin:"q[qwxr]?\\s*\\[",
end:"\\]",relevance:5},{begin:"q[qwxr]?\\s*\\{",end:"\\}",relevance:5},{
begin:"q[qwxr]?\\s*\\|",end:"\\|",relevance:5},{begin:"q[qwxr]?\\s*<",end:">",
relevance:5},{begin:"qw\\s+q",end:"q",relevance:5},{begin:"'",end:"'",
contains:[e.BACKSLASH_ESCAPE]},{begin:'"',end:'"'},{begin:"`",end:"`",
contains:[e.BACKSLASH_ESCAPE]},{begin:/\{\w+\}/,relevance:0},{
begin:"-?\\w+\\s*=>",relevance:0}]},{className:"number",
begin:"(\\b0[0-7_]+)|(\\b0x[0-9a-fA-F_]+)|(\\b[1-9][0-9_]*(\\.[0-9_]+)?)|[0_]\\b",
relevance:0},{
begin:"(\\/\\/|"+e.RE_STARTERS_RE+"|\\b(split|return|print|reverse|grep)\\b)\\s*",
keywords:"split return print reverse grep",relevance:0,
contains:[e.HASH_COMMENT_MODE,{className:"regexp",variants:[{
begin:c("s|tr|y",n.either(...l,{capture:!0}))},{begin:c("s|tr|y","\\(","\\)")},{
begin:c("s|tr|y","\\[","\\]")},{begin:c("s|tr|y","\\{","\\}")}],relevance:2},{
className:"regexp",variants:[{begin:/(m|qr)\/\//,relevance:0},{
begin:d("(?:m|qr)?",/\//,/\//)},{begin:d("m|qr",n.either(...l,{capture:!0
}),/\1/)},{begin:d("m|qr",/\(/,/\)/)},{begin:d("m|qr",/\[/,/\]/)},{
begin:d("m|qr",/\{/,/\}/)}]}]},{className:"function",beginKeywords:"sub",
end:"(\\s*\\(.*?\\))?[;{]",excludeEnd:!0,relevance:5,contains:[e.TITLE_MODE]},{
begin:"-\\w\\b",relevance:0},{begin:"^__DATA__$",end:"^__END__$",
subLanguage:"mojolicious",contains:[{begin:"^@@.*",end:"$",className:"comment"}]
}];return i.contains=g,r.contains=g,{name:"Perl",aliases:["pl","pm"],keywords:a,
contains:g}},grmr_php:e=>{
const n=e.regex,t="[a-zA-Z0-9_\x7f-\xff]*(?![A-Za-z0-9])(?![$]))",a=n.concat("([a-zA-Z_\\x7f-\\xff]",t),i=n.concat("([A-Z]",t),r={
scope:"variable",match:"\\$+"+a},s={scope:"subst",variants:[{begin:/\$\w+/},{
begin:/\{\$/,end:/\}/}]},o=e.inherit(e.APOS_STRING_MODE,{illegal:null
}),l="[ \t\n]",c={scope:"string",variants:[e.inherit(e.QUOTE_STRING_MODE,{
illegal:null,contains:e.QUOTE_STRING_MODE.contains.concat(s)
}),o,e.END_SAME_AS_BEGIN({begin:/<<<[ \t]*(\w+)\n/,end:/[ \t]*(\w+)\b/,
contains:e.QUOTE_STRING_MODE.contains.concat(s)})]},d={scope:"number",
variants:[{begin:"\\b0[bB][01]+(?:_[01]+)*\\b"},{
begin:"\\b0[oO][0-7]+(?:_[0-7]+)*\\b"},{
begin:"\\b0[xX][\\da-fA-F]+(?:_[\\da-fA-F]+)*\\b"},{
begin:"(?:\\b\\d+(?:_\\d+)*(\\.(?:\\d+(?:_\\d+)*))?|\\B\\.\\d+)(?:[eE][+-]?\\d+)?"
}],relevance:0
},g=["__CLASS__","__DIR__","__FILE__","__FUNCTION__","__COMPILER_HALT_OFFSET__","__LINE__","__METHOD__","__NAMESPACE__","__TRAIT__","die","echo","exit","include","include_once","print","require","require_once","array","abstract","and","as","binary","bool","boolean","break","callable","case","catch","class","clone","const","continue","declare","default","do","double","else","elseif","empty","enddeclare","endfor","endforeach","endif","endswitch","endwhile","enum","eval","extends","final","finally","float","for","foreach","from","global","goto","if","implements","instanceof","insteadof","int","integer","interface","isset","iterable","list","match|0","mixed","new","never","object","or","private","protected","public","readonly","real","return","string","switch","throw","trait","try","unset","use","var","void","while","xor","yield"],u=["Error|0","AppendIterator","ArgumentCountError","ArithmeticError","ArrayIterator","ArrayObject","AssertionError","BadFunctionCallException","BadMethodCallException","CachingIterator","CallbackFilterIterator","CompileError","Countable","DirectoryIterator","DivisionByZeroError","DomainException","EmptyIterator","ErrorException","Exception","FilesystemIterator","FilterIterator","GlobIterator","InfiniteIterator","InvalidArgumentException","IteratorIterator","LengthException","LimitIterator","LogicException","MultipleIterator","NoRewindIterator","OutOfBoundsException","OutOfRangeException","OuterIterator","OverflowException","ParentIterator","ParseError","RangeException","RecursiveArrayIterator","RecursiveCachingIterator","RecursiveCallbackFilterIterator","RecursiveDirectoryIterator","RecursiveFilterIterator","RecursiveIterator","RecursiveIteratorIterator","RecursiveRegexIterator","RecursiveTreeIterator","RegexIterator","RuntimeException","SeekableIterator","SplDoublyLinkedList","SplFileInfo","SplFileObject","SplFixedArray","SplHeap","SplMaxHeap","SplMinHeap","SplObjectStorage","SplObserver","SplPriorityQueue","SplQueue","SplStack","SplSubject","SplTempFileObject","TypeError","UnderflowException","UnexpectedValueException","UnhandledMatchError","ArrayAccess","BackedEnum","Closure","Fiber","Generator","Iterator","IteratorAggregate","Serializable","Stringable","Throwable","Traversable","UnitEnum","WeakReference","WeakMap","Directory","__PHP_Incomplete_Class","parent","php_user_filter","self","static","stdClass"],b={
keyword:g,literal:(e=>{const n=[];return["false","null","true"].forEach((e=>{
n.push(e),e.toLowerCase()===e?n.push(e.toUpperCase()):n.push(e.toLowerCase())
})),n})(),built_in:u},m=e=>e.map((e=>e.replace(/\|\d+$/,""))),p={variants:[{
match:[/new/,n.concat(l,"+"),n.concat("(?!",m(u).join("\\b|"),"\\b)"),n.concat(/\\?/,a),n.concat(l,"*",/\(/)],
scope:{1:"keyword",4:"title.class"}}]},_={relevance:0,
match:[/\b/,n.concat("(?!fn\\b|function\\b|",m(g).join("\\b|"),"|",m(u).join("\\b|"),"\\b)"),a,n.concat(l,"*"),n.lookahead(/(?=\()/)],
scope:{3:"title.function.invoke"}},h=n.concat(a,"\\b(?!\\()"),f={variants:[{
match:[n.concat(/::/,n.lookahead(/(?!class\b)/)),h],scope:{2:"variable.constant"
}},{match:[/::/,/class/],scope:{2:"variable.language"}},{
match:[i,n.concat("::",n.lookahead(/(?!class\b)/))],scope:{1:"title.class"}},{
match:[i,/::/,/class/],scope:{1:"title.class",3:"variable.language"}}]};return{
case_insensitive:!1,keywords:b,
contains:[e.HASH_COMMENT_MODE,e.COMMENT("//","$"),e.COMMENT("/\\*","\\*/",{
contains:[{scope:"doctag",match:"@[A-Za-z]+"}]}),{match:/__halt_compiler\(\);/,
keywords:"__halt_compiler",starts:{scope:"comment",end:e.MATCH_NOTHING_RE,
contains:[{match:/\?>/,scope:"meta",endsParent:!0}]}},{scope:"meta",variants:[{
begin:/<\?php/,relevance:10},{begin:/<\?[=]?/},{begin:/\?>/}]},{
scope:"variable.language",match:/\$this\b/},r,_,f,{
match:[/const/,/\s/,a,/\s*=/],scope:{1:"keyword",3:"variable.constant"}},p,{
scope:"function",relevance:0,beginKeywords:"fn function",end:/[;{]/,
excludeEnd:!0,illegal:"[$%\\[]",contains:[{beginKeywords:"use"
},e.UNDERSCORE_TITLE_MODE,{begin:"=>",endsParent:!0},{scope:"params",
begin:"\\(",end:"\\)",excludeBegin:!0,excludeEnd:!0,keywords:b,
contains:["self",r,f,e.C_BLOCK_COMMENT_MODE,c,d]}]},{scope:"class",variants:[{
beginKeywords:"enum",illegal:/[($"]/},{beginKeywords:"class interface trait",
illegal:/[:($"]/}],relevance:0,end:/\{/,excludeEnd:!0,contains:[{
beginKeywords:"extends implements"},e.UNDERSCORE_TITLE_MODE]},{
beginKeywords:"namespace",relevance:0,end:";",illegal:/[.']/,
contains:[e.inherit(e.UNDERSCORE_TITLE_MODE,{scope:"title.class"})]},{
beginKeywords:"use",relevance:0,end:";",contains:[{
match:/\b(as|const|function)\b/,scope:"keyword"},e.UNDERSCORE_TITLE_MODE]},c,d]}
},grmr_php_template:e=>({name:"PHP template",subLanguage:"xml",contains:[{
begin:/<\?(php|=)?/,end:/\?>/,subLanguage:"php",contains:[{begin:"/\\*",
end:"\\*/",skip:!0},{begin:'b"',end:'"',skip:!0},{begin:"b'",end:"'",skip:!0
},e.inherit(e.APOS_STRING_MODE,{illegal:null,className:null,contains:null,
skip:!0}),e.inherit(e.QUOTE_STRING_MODE,{illegal:null,className:null,
contains:null,skip:!0})]}]}),grmr_plaintext:e=>({name:"Plain text",
aliases:["text","txt"],disableAutodetect:!0}),grmr_python:e=>{
const n=e.regex,t=/[\p{XID_Start}_]\p{XID_Continue}*/u,a=["and","as","assert","async","await","break","class","continue","def","del","elif","else","except","finally","for","from","global","if","import","in","is","lambda","nonlocal|10","not","or","pass","raise","return","try","while","with","yield"],i={
$pattern:/[A-Za-z]\w+|__\w+__/,keyword:a,
built_in:["__import__","abs","all","any","ascii","bin","bool","breakpoint","bytearray","bytes","callable","chr","classmethod","compile","complex","delattr","dict","dir","divmod","enumerate","eval","exec","filter","float","format","frozenset","getattr","globals","hasattr","hash","help","hex","id","input","int","isinstance","issubclass","iter","len","list","locals","map","max","memoryview","min","next","object","oct","open","ord","pow","print","property","range","repr","reversed","round","set","setattr","slice","sorted","staticmethod","str","sum","super","tuple","type","vars","zip"],
literal:["__debug__","Ellipsis","False","None","NotImplemented","True"],
type:["Any","Callable","Coroutine","Dict","List","Literal","Generic","Optional","Sequence","Set","Tuple","Type","Union"]
},r={className:"meta",begin:/^(>>>|\.\.\.) /},s={className:"subst",begin:/\{/,
end:/\}/,keywords:i,illegal:/#/},o={begin:/\{\{/,relevance:0},l={
className:"string",contains:[e.BACKSLASH_ESCAPE],variants:[{
begin:/([uU]|[bB]|[rR]|[bB][rR]|[rR][bB])?'''/,end:/'''/,
contains:[e.BACKSLASH_ESCAPE,r],relevance:10},{
begin:/([uU]|[bB]|[rR]|[bB][rR]|[rR][bB])?"""/,end:/"""/,
contains:[e.BACKSLASH_ESCAPE,r],relevance:10},{
begin:/([fF][rR]|[rR][fF]|[fF])'''/,end:/'''/,
contains:[e.BACKSLASH_ESCAPE,r,o,s]},{begin:/([fF][rR]|[rR][fF]|[fF])"""/,
end:/"""/,contains:[e.BACKSLASH_ESCAPE,r,o,s]},{begin:/([uU]|[rR])'/,end:/'/,
relevance:10},{begin:/([uU]|[rR])"/,end:/"/,relevance:10},{
begin:/([bB]|[bB][rR]|[rR][bB])'/,end:/'/},{begin:/([bB]|[bB][rR]|[rR][bB])"/,
end:/"/},{begin:/([fF][rR]|[rR][fF]|[fF])'/,end:/'/,
contains:[e.BACKSLASH_ESCAPE,o,s]},{begin:/([fF][rR]|[rR][fF]|[fF])"/,end:/"/,
contains:[e.BACKSLASH_ESCAPE,o,s]},e.APOS_STRING_MODE,e.QUOTE_STRING_MODE]
},c="[0-9](_?[0-9])*",d=`(\\b(${c}))?\\.(${c})|\\b(${c})\\.`,g="\\b|"+a.join("|"),u={
className:"number",relevance:0,variants:[{
begin:`(\\b(${c})|(${d}))[eE][+-]?(${c})[jJ]?(?=${g})`},{begin:`(${d})[jJ]?`},{
begin:`\\b([1-9](_?[0-9])*|0+(_?0)*)[lLjJ]?(?=${g})`},{
begin:`\\b0[bB](_?[01])+[lL]?(?=${g})`},{begin:`\\b0[oO](_?[0-7])+[lL]?(?=${g})`
},{begin:`\\b0[xX](_?[0-9a-fA-F])+[lL]?(?=${g})`},{begin:`\\b(${c})[jJ](?=${g})`
}]},b={className:"comment",begin:n.lookahead(/# type:/),end:/$/,keywords:i,
contains:[{begin:/# type:/},{begin:/#/,end:/\b\B/,endsWithParent:!0}]},m={
className:"params",variants:[{className:"",begin:/\(\s*\)/,skip:!0},{begin:/\(/,
end:/\)/,excludeBegin:!0,excludeEnd:!0,keywords:i,
contains:["self",r,u,l,e.HASH_COMMENT_MODE]}]};return s.contains=[l,u,r],{
name:"Python",aliases:["py","gyp","ipython"],unicodeRegex:!0,keywords:i,
illegal:/(<\/|->|\?)|=>/,contains:[r,u,{begin:/\bself\b/},{beginKeywords:"if",
relevance:0},l,b,e.HASH_COMMENT_MODE,{match:[/\bdef/,/\s+/,t],scope:{
1:"keyword",3:"title.function"},contains:[m]},{variants:[{
match:[/\bclass/,/\s+/,t,/\s*/,/\(\s*/,t,/\s*\)/]},{match:[/\bclass/,/\s+/,t]}],
scope:{1:"keyword",3:"title.class",6:"title.class.inherited"}},{
className:"meta",begin:/^[\t ]*@/,end:/(?=#)|$/,contains:[u,m,l]}]}},
grmr_python_repl:e=>({aliases:["pycon"],contains:[{className:"meta",starts:{
end:/ |$/,starts:{end:"$",subLanguage:"python"}},variants:[{
begin:/^>>>(?=[ ]|$)/},{begin:/^\.\.\.(?=[ ]|$)/}]}]}),grmr_r:e=>{
const n=e.regex,t=/(?:(?:[a-zA-Z]|\.[._a-zA-Z])[._a-zA-Z0-9]*)|\.(?!\d)/,a=n.either(/0[xX][0-9a-fA-F]+\.[0-9a-fA-F]*[pP][+-]?\d+i?/,/0[xX][0-9a-fA-F]+(?:[pP][+-]?\d+)?[Li]?/,/(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?[Li]?/),i=/[=!<>:]=|\|\||&&|:::?|<-|<<-|->>|->|\|>|[-+*\/?!$&|:<=>@^~]|\*\*/,r=n.either(/[()]/,/[{}]/,/\[\[/,/[[\]]/,/\\/,/,/)
;return{name:"R",keywords:{$pattern:t,
keyword:"function if in break next repeat else for while",
literal:"NULL NA TRUE FALSE Inf NaN NA_integer_|10 NA_real_|10 NA_character_|10 NA_complex_|10",
built_in:"LETTERS letters month.abb month.name pi T F abs acos acosh all any anyNA Arg as.call as.character as.complex as.double as.environment as.integer as.logical as.null.default as.numeric as.raw asin asinh atan atanh attr attributes baseenv browser c call ceiling class Conj cos cosh cospi cummax cummin cumprod cumsum digamma dim dimnames emptyenv exp expression floor forceAndCall gamma gc.time globalenv Im interactive invisible is.array is.atomic is.call is.character is.complex is.double is.environment is.expression is.finite is.function is.infinite is.integer is.language is.list is.logical is.matrix is.na is.name is.nan is.null is.numeric is.object is.pairlist is.raw is.recursive is.single is.symbol lazyLoadDBfetch length lgamma list log max min missing Mod names nargs nzchar oldClass on.exit pos.to.env proc.time prod quote range Re rep retracemem return round seq_along seq_len seq.int sign signif sin sinh sinpi sqrt standardGeneric substitute sum switch tan tanh tanpi tracemem trigamma trunc unclass untracemem UseMethod xtfrm"
},contains:[e.COMMENT(/#'/,/$/,{contains:[{scope:"doctag",match:/@examples/,
starts:{end:n.lookahead(n.either(/\n^#'\s*(?=@[a-zA-Z]+)/,/\n^(?!#')/)),
endsParent:!0}},{scope:"doctag",begin:"@param",end:/$/,contains:[{
scope:"variable",variants:[{match:t},{match:/`(?:\\.|[^`\\])+`/}],endsParent:!0
}]},{scope:"doctag",match:/@[a-zA-Z]+/},{scope:"keyword",match:/\\[a-zA-Z]+/}]
}),e.HASH_COMMENT_MODE,{scope:"string",contains:[e.BACKSLASH_ESCAPE],
variants:[e.END_SAME_AS_BEGIN({begin:/[rR]"(-*)\(/,end:/\)(-*)"/
}),e.END_SAME_AS_BEGIN({begin:/[rR]"(-*)\{/,end:/\}(-*)"/
}),e.END_SAME_AS_BEGIN({begin:/[rR]"(-*)\[/,end:/\](-*)"/
}),e.END_SAME_AS_BEGIN({begin:/[rR]'(-*)\(/,end:/\)(-*)'/
}),e.END_SAME_AS_BEGIN({begin:/[rR]'(-*)\{/,end:/\}(-*)'/
}),e.END_SAME_AS_BEGIN({begin:/[rR]'(-*)\[/,end:/\](-*)'/}),{begin:'"',end:'"',
relevance:0},{begin:"'",end:"'",relevance:0}]},{relevance:0,variants:[{scope:{
1:"operator",2:"number"},match:[i,a]},{scope:{1:"operator",2:"number"},
match:[/%[^%]*%/,a]},{scope:{1:"punctuation",2:"number"},match:[r,a]},{scope:{
2:"number"},match:[/[^a-zA-Z0-9._]|^/,a]}]},{scope:{3:"operator"},
match:[t,/\s+/,/<-/,/\s+/]},{scope:"operator",relevance:0,variants:[{match:i},{
match:/%[^%]*%/}]},{scope:"punctuation",relevance:0,match:r},{begin:"`",end:"`",
contains:[{begin:/\\./}]}]}},grmr_ruby:e=>{
const n=e.regex,t="([a-zA-Z_]\\w*[!?=]?|[-+~]@|<<|>>|=~|===?|<=>|[<>]=?|\\*\\*|[-/+%^&*~`|]|\\[\\]=?)",a={
keyword:"and then defined module in return redo if BEGIN retry end for self when next until do begin unless END rescue else break undef not super class case require yield alias while ensure elsif or include attr_reader attr_writer attr_accessor __FILE__",
built_in:"proc lambda",literal:"true false nil"},i={className:"doctag",
begin:"@[A-Za-z]+"},r={begin:"#<",end:">"},s=[e.COMMENT("#","$",{contains:[i]
}),e.COMMENT("^=begin","^=end",{contains:[i],relevance:10
}),e.COMMENT("^__END__","\\n$")],o={className:"subst",begin:/#\{/,end:/\}/,
keywords:a},l={className:"string",contains:[e.BACKSLASH_ESCAPE,o],variants:[{
begin:/'/,end:/'/},{begin:/"/,end:/"/},{begin:/`/,end:/`/},{begin:/%[qQwWx]?\(/,
end:/\)/},{begin:/%[qQwWx]?\[/,end:/\]/},{begin:/%[qQwWx]?\{/,end:/\}/},{
begin:/%[qQwWx]?</,end:/>/},{begin:/%[qQwWx]?\//,end:/\//},{begin:/%[qQwWx]?%/,
end:/%/},{begin:/%[qQwWx]?-/,end:/-/},{begin:/%[qQwWx]?\|/,end:/\|/},{
begin:/\B\?(\\\d{1,3})/},{begin:/\B\?(\\x[A-Fa-f0-9]{1,2})/},{
begin:/\B\?(\\u\{?[A-Fa-f0-9]{1,6}\}?)/},{
begin:/\B\?(\\M-\\C-|\\M-\\c|\\c\\M-|\\M-|\\C-\\M-)[\x20-\x7e]/},{
begin:/\B\?\\(c|C-)[\x20-\x7e]/},{begin:/\B\?\\?\S/},{
begin:n.concat(/<<[-~]?'?/,n.lookahead(/(\w+)(?=\W)[^\n]*\n(?:[^\n]*\n)*?\s*\1\b/)),
contains:[e.END_SAME_AS_BEGIN({begin:/(\w+)/,end:/(\w+)/,
contains:[e.BACKSLASH_ESCAPE,o]})]}]},c="[0-9](_?[0-9])*",d={className:"number",
relevance:0,variants:[{
begin:`\\b([1-9](_?[0-9])*|0)(\\.(${c}))?([eE][+-]?(${c})|r)?i?\\b`},{
begin:"\\b0[dD][0-9](_?[0-9])*r?i?\\b"},{begin:"\\b0[bB][0-1](_?[0-1])*r?i?\\b"
},{begin:"\\b0[oO][0-7](_?[0-7])*r?i?\\b"},{
begin:"\\b0[xX][0-9a-fA-F](_?[0-9a-fA-F])*r?i?\\b"},{
begin:"\\b0(_?[0-7])+r?i?\\b"}]},g={className:"params",begin:"\\(",end:"\\)",
endsParent:!0,keywords:a},u=[l,{className:"class",beginKeywords:"class module",
end:"$|;",illegal:/=/,contains:[e.inherit(e.TITLE_MODE,{
begin:"[A-Za-z_]\\w*(::\\w+)*(\\?|!)?"}),{begin:"<\\s*",contains:[{
begin:"("+e.IDENT_RE+"::)?"+e.IDENT_RE,relevance:0}]}].concat(s)},{
className:"function",begin:n.concat(/def\s+/,n.lookahead(t+"\\s*(\\(|;|$)")),
relevance:0,keywords:"def",end:"$|;",contains:[e.inherit(e.TITLE_MODE,{begin:t
}),g].concat(s)},{begin:e.IDENT_RE+"::"},{className:"symbol",
begin:e.UNDERSCORE_IDENT_RE+"(!|\\?)?:",relevance:0},{className:"symbol",
begin:":(?!\\s)",contains:[l,{begin:t}],relevance:0},d,{className:"variable",
begin:"(\\$\\W)|((\\$|@@?)(\\w+))(?=[^@$?])(?![A-Za-z])(?![@$?'])"},{
className:"params",begin:/\|/,end:/\|/,relevance:0,keywords:a},{
begin:"("+e.RE_STARTERS_RE+"|unless)\\s*",keywords:"unless",contains:[{
className:"regexp",contains:[e.BACKSLASH_ESCAPE,o],illegal:/\n/,variants:[{
begin:"/",end:"/[a-z]*"},{begin:/%r\{/,end:/\}[a-z]*/},{begin:"%r\\(",
end:"\\)[a-z]*"},{begin:"%r!",end:"![a-z]*"},{begin:"%r\\[",end:"\\][a-z]*"}]
}].concat(r,s),relevance:0}].concat(r,s);o.contains=u,g.contains=u;const b=[{
begin:/^\s*=>/,starts:{end:"$",contains:u}},{className:"meta",
begin:"^([>?]>|[\\w#]+\\(\\w+\\):\\d+:\\d+>|(\\w+-)?\\d+\\.\\d+\\.\\d+(p\\d+)?[^\\d][^>]+>)(?=[ ])",
starts:{end:"$",contains:u}}];return s.unshift(r),{name:"Ruby",
aliases:["rb","gemspec","podspec","thor","irb"],keywords:a,illegal:/\/\*/,
contains:[e.SHEBANG({binary:"ruby"})].concat(b).concat(s).concat(u)}},
grmr_rust:e=>{const n=e.regex,t={className:"title.function.invoke",relevance:0,
begin:n.concat(/\b/,/(?!let\b)/,e.IDENT_RE,n.lookahead(/\s*\(/))
},a="([ui](8|16|32|64|128|size)|f(32|64))?",i=["drop ","Copy","Send","Sized","Sync","Drop","Fn","FnMut","FnOnce","ToOwned","Clone","Debug","PartialEq","PartialOrd","Eq","Ord","AsRef","AsMut","Into","From","Default","Iterator","Extend","IntoIterator","DoubleEndedIterator","ExactSizeIterator","SliceConcatExt","ToString","assert!","assert_eq!","bitflags!","bytes!","cfg!","col!","concat!","concat_idents!","debug_assert!","debug_assert_eq!","env!","panic!","file!","format!","format_args!","include_bin!","include_str!","line!","local_data_key!","module_path!","option_env!","print!","println!","select!","stringify!","try!","unimplemented!","unreachable!","vec!","write!","writeln!","macro_rules!","assert_ne!","debug_assert_ne!"]
;return{name:"Rust",aliases:["rs"],keywords:{$pattern:e.IDENT_RE+"!?",
type:["i8","i16","i32","i64","i128","isize","u8","u16","u32","u64","u128","usize","f32","f64","str","char","bool","Box","Option","Result","String","Vec"],
keyword:["abstract","as","async","await","become","box","break","const","continue","crate","do","dyn","else","enum","extern","false","final","fn","for","if","impl","in","let","loop","macro","match","mod","move","mut","override","priv","pub","ref","return","self","Self","static","struct","super","trait","true","try","type","typeof","unsafe","unsized","use","virtual","where","while","yield"],
literal:["true","false","Some","None","Ok","Err"],built_in:i},illegal:"</",
contains:[e.C_LINE_COMMENT_MODE,e.COMMENT("/\\*","\\*/",{contains:["self"]
}),e.inherit(e.QUOTE_STRING_MODE,{begin:/b?"/,illegal:null}),{
className:"string",variants:[{begin:/b?r(#*)"(.|\n)*?"\1(?!#)/},{
begin:/b?'\\?(x\w{2}|u\w{4}|U\w{8}|.)'/}]},{className:"symbol",
begin:/'[a-zA-Z_][a-zA-Z0-9_]*/},{className:"number",variants:[{
begin:"\\b0b([01_]+)"+a},{begin:"\\b0o([0-7_]+)"+a},{
begin:"\\b0x([A-Fa-f0-9_]+)"+a},{
begin:"\\b(\\d[\\d_]*(\\.[0-9_]+)?([eE][+-]?[0-9_]+)?)"+a}],relevance:0},{
begin:[/fn/,/\s+/,e.UNDERSCORE_IDENT_RE],className:{1:"keyword",
3:"title.function"}},{className:"meta",begin:"#!?\\[",end:"\\]",contains:[{
className:"string",begin:/"/,end:/"/}]},{
begin:[/let/,/\s+/,/(?:mut\s+)?/,e.UNDERSCORE_IDENT_RE],className:{1:"keyword",
3:"keyword",4:"variable"}},{
begin:[/for/,/\s+/,e.UNDERSCORE_IDENT_RE,/\s+/,/in/],className:{1:"keyword",
3:"variable",5:"keyword"}},{begin:[/type/,/\s+/,e.UNDERSCORE_IDENT_RE],
className:{1:"keyword",3:"title.class"}},{
begin:[/(?:trait|enum|struct|union|impl|for)/,/\s+/,e.UNDERSCORE_IDENT_RE],
className:{1:"keyword",3:"title.class"}},{begin:e.IDENT_RE+"::",keywords:{
keyword:"Self",built_in:i}},{className:"punctuation",begin:"->"},t]}},
grmr_scss:e=>{const n=te(e),t=se,a=re,i="@[a-z-]+",r={className:"variable",
begin:"(\\$[a-zA-Z-][a-zA-Z0-9_-]*)\\b"};return{name:"SCSS",case_insensitive:!0,
illegal:"[=/|']",
contains:[e.C_LINE_COMMENT_MODE,e.C_BLOCK_COMMENT_MODE,n.CSS_NUMBER_MODE,{
className:"selector-id",begin:"#[A-Za-z0-9_-]+",relevance:0},{
className:"selector-class",begin:"\\.[A-Za-z0-9_-]+",relevance:0
},n.ATTRIBUTE_SELECTOR_MODE,{className:"selector-tag",
begin:"\\b("+ae.join("|")+")\\b",relevance:0},{className:"selector-pseudo",
begin:":("+a.join("|")+")"},{className:"selector-pseudo",
begin:":(:)?("+t.join("|")+")"},r,{begin:/\(/,end:/\)/,
contains:[n.CSS_NUMBER_MODE]},n.CSS_VARIABLE,{className:"attribute",
begin:"\\b("+oe.join("|")+")\\b"},{
begin:"\\b(whitespace|wait|w-resize|visible|vertical-text|vertical-ideographic|uppercase|upper-roman|upper-alpha|underline|transparent|top|thin|thick|text|text-top|text-bottom|tb-rl|table-header-group|table-footer-group|sw-resize|super|strict|static|square|solid|small-caps|separate|se-resize|scroll|s-resize|rtl|row-resize|ridge|right|repeat|repeat-y|repeat-x|relative|progress|pointer|overline|outside|outset|oblique|nowrap|not-allowed|normal|none|nw-resize|no-repeat|no-drop|newspaper|ne-resize|n-resize|move|middle|medium|ltr|lr-tb|lowercase|lower-roman|lower-alpha|loose|list-item|line|line-through|line-edge|lighter|left|keep-all|justify|italic|inter-word|inter-ideograph|inside|inset|inline|inline-block|inherit|inactive|ideograph-space|ideograph-parenthesis|ideograph-numeric|ideograph-alpha|horizontal|hidden|help|hand|groove|fixed|ellipsis|e-resize|double|dotted|distribute|distribute-space|distribute-letter|distribute-all-lines|disc|disabled|default|decimal|dashed|crosshair|collapse|col-resize|circle|char|center|capitalize|break-word|break-all|bottom|both|bolder|bold|block|bidi-override|below|baseline|auto|always|all-scroll|absolute|table|table-cell)\\b"
},{begin:/:/,end:/[;}{]/,
contains:[n.BLOCK_COMMENT,r,n.HEXCOLOR,n.CSS_NUMBER_MODE,e.QUOTE_STRING_MODE,e.APOS_STRING_MODE,n.IMPORTANT]
},{begin:"@(page|font-face)",keywords:{$pattern:i,keyword:"@page @font-face"}},{
begin:"@",end:"[{;]",returnBegin:!0,keywords:{$pattern:/[a-z-]+/,
keyword:"and or not only",attribute:ie.join(" ")},contains:[{begin:i,
className:"keyword"},{begin:/[a-z-]+(?=:)/,className:"attribute"
},r,e.QUOTE_STRING_MODE,e.APOS_STRING_MODE,n.HEXCOLOR,n.CSS_NUMBER_MODE]
},n.FUNCTION_DISPATCH]}},grmr_shell:e=>({name:"Shell Session",
aliases:["console","shellsession"],contains:[{className:"meta",
begin:/^\s{0,3}[/~\w\d[\]()@-]*[>%$#][ ]?/,starts:{end:/[^\\](?=\s*$)/,
subLanguage:"bash"}}]}),grmr_sql:e=>{
const n=e.regex,t=e.COMMENT("--","$"),a=["true","false","unknown"],i=["bigint","binary","blob","boolean","char","character","clob","date","dec","decfloat","decimal","float","int","integer","interval","nchar","nclob","national","numeric","real","row","smallint","time","timestamp","varchar","varying","varbinary"],r=["abs","acos","array_agg","asin","atan","avg","cast","ceil","ceiling","coalesce","corr","cos","cosh","count","covar_pop","covar_samp","cume_dist","dense_rank","deref","element","exp","extract","first_value","floor","json_array","json_arrayagg","json_exists","json_object","json_objectagg","json_query","json_table","json_table_primitive","json_value","lag","last_value","lead","listagg","ln","log","log10","lower","max","min","mod","nth_value","ntile","nullif","percent_rank","percentile_cont","percentile_disc","position","position_regex","power","rank","regr_avgx","regr_avgy","regr_count","regr_intercept","regr_r2","regr_slope","regr_sxx","regr_sxy","regr_syy","row_number","sin","sinh","sqrt","stddev_pop","stddev_samp","substring","substring_regex","sum","tan","tanh","translate","translate_regex","treat","trim","trim_array","unnest","upper","value_of","var_pop","var_samp","width_bucket"],s=["create table","insert into","primary key","foreign key","not null","alter table","add constraint","grouping sets","on overflow","character set","respect nulls","ignore nulls","nulls first","nulls last","depth first","breadth first"],o=r,l=["abs","acos","all","allocate","alter","and","any","are","array","array_agg","array_max_cardinality","as","asensitive","asin","asymmetric","at","atan","atomic","authorization","avg","begin","begin_frame","begin_partition","between","bigint","binary","blob","boolean","both","by","call","called","cardinality","cascaded","case","cast","ceil","ceiling","char","char_length","character","character_length","check","classifier","clob","close","coalesce","collate","collect","column","commit","condition","connect","constraint","contains","convert","copy","corr","corresponding","cos","cosh","count","covar_pop","covar_samp","create","cross","cube","cume_dist","current","current_catalog","current_date","current_default_transform_group","current_path","current_role","current_row","current_schema","current_time","current_timestamp","current_path","current_role","current_transform_group_for_type","current_user","cursor","cycle","date","day","deallocate","dec","decimal","decfloat","declare","default","define","delete","dense_rank","deref","describe","deterministic","disconnect","distinct","double","drop","dynamic","each","element","else","empty","end","end_frame","end_partition","end-exec","equals","escape","every","except","exec","execute","exists","exp","external","extract","false","fetch","filter","first_value","float","floor","for","foreign","frame_row","free","from","full","function","fusion","get","global","grant","group","grouping","groups","having","hold","hour","identity","in","indicator","initial","inner","inout","insensitive","insert","int","integer","intersect","intersection","interval","into","is","join","json_array","json_arrayagg","json_exists","json_object","json_objectagg","json_query","json_table","json_table_primitive","json_value","lag","language","large","last_value","lateral","lead","leading","left","like","like_regex","listagg","ln","local","localtime","localtimestamp","log","log10","lower","match","match_number","match_recognize","matches","max","member","merge","method","min","minute","mod","modifies","module","month","multiset","national","natural","nchar","nclob","new","no","none","normalize","not","nth_value","ntile","null","nullif","numeric","octet_length","occurrences_regex","of","offset","old","omit","on","one","only","open","or","order","out","outer","over","overlaps","overlay","parameter","partition","pattern","per","percent","percent_rank","percentile_cont","percentile_disc","period","portion","position","position_regex","power","precedes","precision","prepare","primary","procedure","ptf","range","rank","reads","real","recursive","ref","references","referencing","regr_avgx","regr_avgy","regr_count","regr_intercept","regr_r2","regr_slope","regr_sxx","regr_sxy","regr_syy","release","result","return","returns","revoke","right","rollback","rollup","row","row_number","rows","running","savepoint","scope","scroll","search","second","seek","select","sensitive","session_user","set","show","similar","sin","sinh","skip","smallint","some","specific","specifictype","sql","sqlexception","sqlstate","sqlwarning","sqrt","start","static","stddev_pop","stddev_samp","submultiset","subset","substring","substring_regex","succeeds","sum","symmetric","system","system_time","system_user","table","tablesample","tan","tanh","then","time","timestamp","timezone_hour","timezone_minute","to","trailing","translate","translate_regex","translation","treat","trigger","trim","trim_array","true","truncate","uescape","union","unique","unknown","unnest","update","upper","user","using","value","values","value_of","var_pop","var_samp","varbinary","varchar","varying","versioning","when","whenever","where","width_bucket","window","with","within","without","year","add","asc","collation","desc","final","first","last","view"].filter((e=>!r.includes(e))),c={
begin:n.concat(/\b/,n.either(...o),/\s*\(/),relevance:0,keywords:{built_in:o}}
;return{name:"SQL",case_insensitive:!0,illegal:/[{}]|<\//,keywords:{
$pattern:/\b[\w\.]+/,keyword:((e,{exceptions:n,when:t}={})=>{const a=t
;return n=n||[],e.map((e=>e.match(/\|\d+$/)||n.includes(e)?e:a(e)?e+"|0":e))
})(l,{when:e=>e.length<3}),literal:a,type:i,
built_in:["current_catalog","current_date","current_default_transform_group","current_path","current_role","current_schema","current_transform_group_for_type","current_user","session_user","system_time","system_user","current_time","localtime","current_timestamp","localtimestamp"]
},contains:[{begin:n.either(...s),relevance:0,keywords:{$pattern:/[\w\.]+/,
keyword:l.concat(s),literal:a,type:i}},{className:"type",
begin:n.either("double precision","large object","with timezone","without timezone")
},c,{className:"variable",begin:/@[a-z0-9]+/},{className:"string",variants:[{
begin:/'/,end:/'/,contains:[{begin:/''/}]}]},{begin:/"/,end:/"/,contains:[{
begin:/""/}]},e.C_NUMBER_MODE,e.C_BLOCK_COMMENT_MODE,t,{className:"operator",
begin:/[-+*/=%^~]|&&?|\|\|?|!=?|<(?:=>?|<|>)?|>[>=]?/,relevance:0}]}},
grmr_swift:e=>{const n={match:/\s+/,relevance:0},t=e.COMMENT("/\\*","\\*/",{
contains:["self"]}),a=[e.C_LINE_COMMENT_MODE,t],i={match:[/\./,p(...ve,...Oe)],
className:{2:"keyword"}},r={match:m(/\./,p(...Me)),relevance:0
},s=Me.filter((e=>"string"==typeof e)).concat(["_|0"]),o={variants:[{
className:"keyword",
match:p(...Me.filter((e=>"string"!=typeof e)).concat(xe).map(we),...Oe)}]},l={
$pattern:p(/\b\w+/,/#\w+/),keyword:s.concat(Ae),literal:ke},c=[i,r,o],d=[{
match:m(/\./,p(...Ce)),relevance:0},{className:"built_in",
match:m(/\b/,p(...Ce),/(?=\()/)}],u={match:/->/,relevance:0},b=[u,{
className:"operator",relevance:0,variants:[{match:De},{match:`\\.(\\.|${Re})+`}]
}],_="([0-9a-fA-F]_*)+",h={className:"number",relevance:0,variants:[{
match:"\\b(([0-9]_*)+)(\\.(([0-9]_*)+))?([eE][+-]?(([0-9]_*)+))?\\b"},{
match:`\\b0x(${_})(\\.(${_}))?([pP][+-]?(([0-9]_*)+))?\\b`},{
match:/\b0o([0-7]_*)+\b/},{match:/\b0b([01]_*)+\b/}]},f=(e="")=>({
className:"subst",variants:[{match:m(/\\/,e,/[0\\tnr"']/)},{
match:m(/\\/,e,/u\{[0-9a-fA-F]{1,8}\}/)}]}),E=(e="")=>({className:"subst",
match:m(/\\/,e,/[\t ]*(?:[\r\n]|\r\n)/)}),y=(e="")=>({className:"subst",
label:"interpol",begin:m(/\\/,e,/\(/),end:/\)/}),N=(e="")=>({begin:m(e,/"""/),
end:m(/"""/,e),contains:[f(e),E(e),y(e)]}),w=(e="")=>({begin:m(e,/"/),
end:m(/"/,e),contains:[f(e),y(e)]}),v={className:"string",
variants:[N(),N("#"),N("##"),N("###"),w(),w("#"),w("##"),w("###")]},O={
match:m(/`/,Be,/`/)},x=[O,{className:"variable",match:/\$\d+/},{
className:"variable",match:`\\$${Le}+`}],M=[{match:/(@|#(un)?)available/,
className:"keyword",starts:{contains:[{begin:/\(/,end:/\)/,keywords:ze,
contains:[...b,h,v]}]}},{className:"keyword",match:m(/@/,p(...Fe))},{
className:"meta",match:m(/@/,Be)}],k={match:g(/\b[A-Z]/),relevance:0,contains:[{
className:"type",
match:m(/(AV|CA|CF|CG|CI|CL|CM|CN|CT|MK|MP|MTK|MTL|NS|SCN|SK|UI|WK|XC)/,Le,"+")
},{className:"type",match:$e,relevance:0},{match:/[?!]+/,relevance:0},{
match:/\.\.\./,relevance:0},{match:m(/\s+&\s+/,g($e)),relevance:0}]},S={
begin:/</,end:/>/,keywords:l,contains:[...a,...c,...M,u,k]};k.contains.push(S)
;const A={begin:/\(/,end:/\)/,relevance:0,keywords:l,contains:["self",{
match:m(Be,/\s*:/),keywords:"_|0",relevance:0
},...a,...c,...d,...b,h,v,...x,...M,k]},C={begin:/</,end:/>/,contains:[...a,k]
},T={begin:/\(/,end:/\)/,keywords:l,contains:[{
begin:p(g(m(Be,/\s*:/)),g(m(Be,/\s+/,Be,/\s*:/))),end:/:/,relevance:0,
contains:[{className:"keyword",match:/\b_\b/},{className:"params",match:Be}]
},...a,...c,...b,h,v,...M,k,A],endsParent:!0,illegal:/["']/},R={
match:[/func/,/\s+/,p(O.match,Be,De)],className:{1:"keyword",3:"title.function"
},contains:[C,T,n],illegal:[/\[/,/%/]},D={
match:[/\b(?:subscript|init[?!]?)/,/\s*(?=[<(])/],className:{1:"keyword"},
contains:[C,T,n],illegal:/\[|%/},I={match:[/operator/,/\s+/,De],className:{
1:"keyword",3:"title"}},L={begin:[/precedencegroup/,/\s+/,$e],className:{
1:"keyword",3:"title"},contains:[k],keywords:[...Se,...ke],end:/}/}
;for(const e of v.variants){const n=e.contains.find((e=>"interpol"===e.label))
;n.keywords=l;const t=[...c,...d,...b,h,v,...x];n.contains=[...t,{begin:/\(/,
end:/\)/,contains:["self",...t]}]}return{name:"Swift",keywords:l,
contains:[...a,R,D,{beginKeywords:"struct protocol class extension enum actor",
end:"\\{",excludeEnd:!0,keywords:l,contains:[e.inherit(e.TITLE_MODE,{
className:"title.class",begin:/[A-Za-z$_][\u00C0-\u02B80-9A-Za-z$_]*/}),...c]
},I,L,{beginKeywords:"import",end:/$/,contains:[...a],relevance:0
},...c,...d,...b,h,v,...x,...M,k,A]}},grmr_typescript:e=>{
const n=Ne(e),t=["any","void","number","boolean","string","object","never","enum"],a={
beginKeywords:"namespace",end:/\{/,excludeEnd:!0,
contains:[n.exports.CLASS_REFERENCE]},i={beginKeywords:"interface",end:/\{/,
excludeEnd:!0,keywords:{keyword:"interface extends",built_in:t},
contains:[n.exports.CLASS_REFERENCE]},r={$pattern:be,
keyword:me.concat(["type","namespace","typedef","interface","public","private","protected","implements","declare","abstract","readonly"]),
literal:pe,built_in:ye.concat(t),"variable.language":Ee},s={className:"meta",
begin:"@[A-Za-z$_][0-9A-Za-z$_]*"},o=(e,n,t)=>{
const a=e.contains.findIndex((e=>e.label===n))
;if(-1===a)throw Error("can not find mode to replace");e.contains.splice(a,1,t)}
;return Object.assign(n.keywords,r),
n.exports.PARAMS_CONTAINS.push(s),n.contains=n.contains.concat([s,a,i]),
o(n,"shebang",e.SHEBANG()),o(n,"use_strict",{className:"meta",relevance:10,
begin:/^\s*['"]use strict['"]/
}),n.contains.find((e=>"func.def"===e.label)).relevance=0,Object.assign(n,{
name:"TypeScript",aliases:["ts","tsx"]}),n},grmr_vbnet:e=>{
const n=e.regex,t=/\d{1,2}\/\d{1,2}\/\d{4}/,a=/\d{4}-\d{1,2}-\d{1,2}/,i=/(\d|1[012])(:\d+){0,2} *(AM|PM)/,r=/\d{1,2}(:\d{1,2}){1,2}/,s={
className:"literal",variants:[{begin:n.concat(/# */,n.either(a,t),/ *#/)},{
begin:n.concat(/# */,r,/ *#/)},{begin:n.concat(/# */,i,/ *#/)},{
begin:n.concat(/# */,n.either(a,t),/ +/,n.either(i,r),/ *#/)}]
},o=e.COMMENT(/'''/,/$/,{contains:[{className:"doctag",begin:/<\/?/,end:/>/}]
}),l=e.COMMENT(null,/$/,{variants:[{begin:/'/},{begin:/([\t ]|^)REM(?=\s)/}]})
;return{name:"Visual Basic .NET",aliases:["vb"],case_insensitive:!0,
classNameAliases:{label:"symbol"},keywords:{
keyword:"addhandler alias aggregate ansi as async assembly auto binary by byref byval call case catch class compare const continue custom declare default delegate dim distinct do each equals else elseif end enum erase error event exit explicit finally for friend from function get global goto group handles if implements imports in inherits interface into iterator join key let lib loop me mid module mustinherit mustoverride mybase myclass namespace narrowing new next notinheritable notoverridable of off on operator option optional order overloads overridable overrides paramarray partial preserve private property protected public raiseevent readonly redim removehandler resume return select set shadows shared skip static step stop structure strict sub synclock take text then throw to try unicode until using when where while widening with withevents writeonly yield",
built_in:"addressof and andalso await directcast gettype getxmlnamespace is isfalse isnot istrue like mod nameof new not or orelse trycast typeof xor cbool cbyte cchar cdate cdbl cdec cint clng cobj csbyte cshort csng cstr cuint culng cushort",
type:"boolean byte char date decimal double integer long object sbyte short single string uinteger ulong ushort",
literal:"true false nothing"},
illegal:"//|\\{|\\}|endif|gosub|variant|wend|^\\$ ",contains:[{
className:"string",begin:/"(""|[^/n])"C\b/},{className:"string",begin:/"/,
end:/"/,illegal:/\n/,contains:[{begin:/""/}]},s,{className:"number",relevance:0,
variants:[{begin:/\b\d[\d_]*((\.[\d_]+(E[+-]?[\d_]+)?)|(E[+-]?[\d_]+))[RFD@!#]?/
},{begin:/\b\d[\d_]*((U?[SIL])|[%&])?/},{begin:/&H[\dA-F_]+((U?[SIL])|[%&])?/},{
begin:/&O[0-7_]+((U?[SIL])|[%&])?/},{begin:/&B[01_]+((U?[SIL])|[%&])?/}]},{
className:"label",begin:/^\w+:/},o,l,{className:"meta",
begin:/[\t ]*#(const|disable|else|elseif|enable|end|externalsource|if|region)\b/,
end:/$/,keywords:{
keyword:"const disable else elseif enable end externalsource if region then"},
contains:[l]}]}},grmr_yaml:e=>{
const n="true false yes no null",t="[\\w#;/?:@&=+$,.~*'()[\\]]+",a={
className:"string",relevance:0,variants:[{begin:/'/,end:/'/},{begin:/"/,end:/"/
},{begin:/\S+/}],contains:[e.BACKSLASH_ESCAPE,{className:"template-variable",
variants:[{begin:/\{\{/,end:/\}\}/},{begin:/%\{/,end:/\}/}]}]},i=e.inherit(a,{
variants:[{begin:/'/,end:/'/},{begin:/"/,end:/"/},{begin:/[^\s,{}[\]]+/}]}),r={
end:",",endsWithParent:!0,excludeEnd:!0,keywords:n,relevance:0},s={begin:/\{/,
end:/\}/,contains:[r],illegal:"\\n",relevance:0},o={begin:"\\[",end:"\\]",
contains:[r],illegal:"\\n",relevance:0},l=[{className:"attr",variants:[{
begin:"\\w[\\w :\\/.-]*:(?=[ \t]|$)"},{begin:'"\\w[\\w :\\/.-]*":(?=[ \t]|$)'},{
begin:"'\\w[\\w :\\/.-]*':(?=[ \t]|$)"}]},{className:"meta",begin:"^---\\s*$",
relevance:10},{className:"string",
begin:"[\\|>]([1-9]?[+-])?[ ]*\\n( +)[^ ][^\\n]*\\n(\\2[^\\n]+\\n?)*"},{
begin:"<%[%=-]?",end:"[%-]?%>",subLanguage:"ruby",excludeBegin:!0,excludeEnd:!0,
relevance:0},{className:"type",begin:"!\\w+!"+t},{className:"type",
begin:"!<"+t+">"},{className:"type",begin:"!"+t},{className:"type",begin:"!!"+t
},{className:"meta",begin:"&"+e.UNDERSCORE_IDENT_RE+"$"},{className:"meta",
begin:"\\*"+e.UNDERSCORE_IDENT_RE+"$"},{className:"bullet",begin:"-(?=[ ]|$)",
relevance:0},e.HASH_COMMENT_MODE,{beginKeywords:n,keywords:{literal:n}},{
className:"number",
begin:"\\b[0-9]{4}(-[0-9][0-9]){0,2}([Tt \\t][0-9][0-9]?(:[0-9][0-9]){2})?(\\.[0-9]*)?([ \\t])*(Z|[-+][0-9][0-9]?(:[0-9][0-9])?)?\\b"
},{className:"number",begin:e.C_NUMBER_RE+"\\b",relevance:0},s,o,a],c=[...l]
;return c.pop(),c.push(i),r.contains=c,{name:"YAML",case_insensitive:!0,
aliases:["yml"],contains:l}}});const je=ne;for(const e of Object.keys(Ue)){
const n=e.replace("grmr_","").replace("_","-");je.registerLanguage(n,Ue[e])}
return je}()
;"object"==typeof exports&&"undefined"!=typeof module&&(module.exports=hljs);
window.hljs = hljs;
console.log("Loaded file highlightjs.js");} catch (e) {
console.error("Error in file highlightjs.js", e);}
})();

(function() {
try{/**
 * Fixes links for local use.
 */
window.napcdoc.lib.fixLink = function(link) {
	let pieces = window.napcdoc_request_uri.split("/").filter(piece => {
		return piece.length > 0
	})

	if (pieces.length === 1) {
		return `./${link}`
	}

	return `./../`.repeat(pieces.length - 1) + link
}
console.log("Loaded file fixLink.js");} catch (e) {
console.error("Error in file fixLink.js", e);}
})();

(function() {
try{window.napcdoc.lib.getIconOfDefinition = function(definition_name, width, height) {
	const definition  = window.napcdoc.definitions[definition_name]
	let icon = "type_icon/fn"

	switch (definition.type) {
		case "fn": {
			icon = "type_icon/fn"
		} break;

		case "type": {
			if (definition.kind === "struct") {
				icon = "type_icon/outline/struct"
			} else if (definition.kind === "opaque") {
				icon = "type_icon/filled/struct"
			} else if (definition.kind === "enum") {
				icon = "type_icon/outline/enum"
			} else {
				icon = "type_icon/outline/type"
			}
		} break;

		case "macro":
			icon = "type_icon/filled/macro"
	}

	return window.napcdoc.lib.getSVGMarkup(icon, width, height)
}
console.log("Loaded file getIconOfDefinition.js");} catch (e) {
console.error("Error in file getIconOfDefinition.js", e);}
})();

(function() {
try{window.napcdoc.lib.getIconOfModule = function(module_name, width, height) {
	return window.napcdoc.lib.getSVGMarkup(`module_icon/${module_name}`, width, height)
}
console.log("Loaded file getIconOfModule.js");} catch (e) {
console.error("Error in file getIconOfModule.js", e);}
})();

(function() {
try{/**
 * Returns the module that definition_name is a part of
 */
window.napcdoc.lib.getModuleOfDefinition = function(definition_name) {
	for (const module_name in window.napcdoc.modules) {
		for (const module_definition of window.napcdoc.modules[module_name]) {
			let a = module_definition.slice(2)

			if (a === definition_name) {
				return module_name
			}
		}
	}
}
console.log("Loaded file getModuleOfDefinition.js");} catch (e) {
console.error("Error in file getModuleOfDefinition.js", e);}
})();

(function() {
try{window.napcdoc.lib.getProtoOfDefinition = function(definition_name) {
	for (const element of document.querySelectorAll("[data-code-definition]")) {
		const a = element.getAttribute("data-code-definition")

		if (a === definition_name) {
			return element.innerHTML
		}
	}

	return "???"
}
console.log("Loaded file getProtoOfDefinition.js");} catch (e) {
console.error("Error in file getProtoOfDefinition.js", e);}
})();

(function() {
try{window.napcdoc.lib.replaceBackticks = function(text) {
	let out = ""
	let open = false

	for (let i = 0; i < text.length; ++i) {
		let ch = text[i]

		if (ch === "`") {
			if (!open) {
				out += `<span class="bt-pill text">`
			} else {
				out += `</span>`
			}

			open = !open
		} else {
			out += ch
		}
	}

	return out
}
console.log("Loaded file replaceBackticks.js");} catch (e) {
console.error("Error in file replaceBackticks.js", e);}
})();

(function() {
try{window.napcdoc.lib.createGlobalSearchSpace = function() {
	let ret = []

	// search space is order sensitive
	const modules = Object.keys(window.napcdoc.modules).filter(module_name => {
		return module_name !== "app"
	})

	for (const module_name of modules) {
		// add module definitions after module
		const definitions = window.napcdoc.modules[module_name]

		for (const definition of definitions) {
			let definition_name = definition.slice(2)
			let label = definition_name
			const definition_meta = window.napcdoc.definitions[definition_name]

			// ignore undocumented definitions
			if (!definition_meta || !("general_info" in definition_meta)) {
				console.log("skip", definition_name)

				continue
			}

			// always shorten non-core function names
			if (definition.slice(0, 2) === "f:" && module_name !== "Core") {
				label = definition_name.slice(`napc_`.length)
			}

			ret.push({
				definition: definition_name,
				module_name,
				label
			})
		}
	}

	return ret
}
console.log("Loaded file createGlobalSearchSpace.js");} catch (e) {
console.error("Error in file createGlobalSearchSpace.js", e);}
})();

(function() {
try{const input_element = document.querySelector("#nd-global-search-input")
const results_div = document.querySelector("#nd-global-search-results").querySelector("div.wrapper")

function createEntry(label, brief, icon) {
	const a_element = document.createElement("a")
	let brief_markup = ""

	if (brief.length) {
		brief_markup = `<span class="brief">${brief}</span>`
	}

	a_element.innerHTML = `
	${icon}
	<div class="label-and-brief">
		<span class="label">${label}</span>
		${brief_markup}
	</div>
	`

	return a_element
}

function createModuleHeader(module_name) {
	const module_header = document.createElement("a")
	module_header.classList.add("module-header")

	const module_icon = window.napcdoc.lib.getIconOfModule(
		module_name, 18, 18
	)

	let brief = ""

	if (module_name in window.napcdoc.modules_intro) {
		let module_meta = window.napcdoc.modules_intro[module_name]

		if ("@brief" in module_meta) {
			//brief = `<span class="brief">${module_meta["@brief"]}</span>`
		}
	}

	module_header.innerHTML = `
	${module_icon}

	<div class="label-and-brief">
		<span class="label">${module_name}</span>
		${brief}
	</div>
	`

	return module_header
}

function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "b")
	results_div.innerHTML = ""

	let last_module_name = ""

	for (const result of results) {
		if (!result.show) continue

		const definition_meta = window.napcdoc.definitions[result.definition]
		let brief = ""

		if ("brief" in definition_meta.general_info) {
			brief = definition_meta.general_info.brief
		}

		let icon = window.napcdoc.lib.getIconOfDefinition(result.definition, 18, 18)

		const a_element = createEntry(
			result.html, brief, icon
		)

		// show module name at the beginning
		if (last_module_name !== result.module_name) {
			results_div.appendChild(
				createModuleHeader(result.module_name)
			)

			last_module_name = result.module_name
		}

		a_element.setAttribute("data-definition-type", definition_meta.type)

		a_element.href = window.napcdoc.lib.fixLink(
			`definition/${result.module_name}/${result.definition}.html#${result.definition}`
		)

		results_div.appendChild(a_element)
	}
}

function getCurrentSelection() {
	const rendered_results = [...results_div.querySelectorAll("a")].filter(element => {
		return !element.classList.contains("module-header")
	})

	let current_position = -1
	let current = null

	for (let i = 0; i < rendered_results.length; ++i) {
		const elm = rendered_results[i]

		if (elm.classList.contains("selected")) {
			current_position = i;
			current = rendered_results[i]
			break;
		}
	}

	let first = rendered_results.length ? rendered_results[0] : null
	let prev = null
	let next = null

	if (current_position !== -1 && rendered_results.length) {
		if (current_position > 0) {
			prev = rendered_results[current_position - 1]
		}

		if ((rendered_results.length - 1) > current_position) {
			next = rendered_results[current_position + 1]
		}
	}

	return {
		first,
		next, current, prev
	}
}

function showSearchResults() {
	if (results_div.parentNode.style.display === "flex") {
		return
	}

	results_div.parentNode.style.display = "flex"
	results_div.parentNode.classList.add("visible")
	window.napcdoc.lib.blurContent()
}

function hideSearchResults() {
	if (results_div.parentNode.style.display !== "flex") {
		return
	}

	results_div.parentNode.style.display = "none"
	results_div.parentNode.classList.remove("visible")
	window.napcdoc.lib.unblurContent()
}

window.napcdoc.lib.hideGlobalSearchResults = hideSearchResults

window.napcdoc.lib.initGlobalSearch = function() {
	let search_space = window.napcdoc.lib.createGlobalSearchSpace()
	const module_name = window.napcdoc_requested_module_name

	input_element.placeholder = "Search a definition"
	input_element.addEventListener("input", (e) => {
		window.napcdoc.lib.localStorageSet("global_search_term", e.currentTarget.value)

		renderSearchResults(e.currentTarget.value, search_space)
	})

	input_element.addEventListener("focus", (e) => {
		showSearchResults()
	})

	input_element.addEventListener("keydown", (e) => {
		if (e.keyCode === 27) {
			hideSearchResults()
			input_element.blur()

			return
		}

		let selection = getCurrentSelection()

		if (!selection.first) return

		if (!selection.next && !selection.prev) {
			selection.first.classList.add("selected")
			return
		}

		if (!selection.current) return

		let target = null

		// arrow down
		if (e.keyCode === 40 && selection.next) {
			target = selection.next
		}
		// arrow up
		else if (e.keyCode === 38 && selection.prev) {
			target = selection.prev
		}

		if (!target) return

		target.classList.add("selected")
		selection.current.classList.remove("selected")

		let elementTop = results_div.offsetTop;
		let divTop = target.offsetTop;
		let elementRelativeTop = divTop - elementTop;

		if (target === selection.first) {
			results_div.scrollTop = 0
		} else {
			results_div.scrollTop = elementRelativeTop
		}

		/**
		 * Prevent the global keydown event
		 */
		e.stopPropagation()
	})

	input_element.addEventListener("keypress", (e) => {
		if (e.keyCode !== 13) return

		const selection = getCurrentSelection()

		if (selection.current) {
			window.location.href = selection.current.href
		}
	})

	/** init results **/
	{
		const initial_search_term = window.napcdoc.lib.localStorageGet("global_search_term", "")

		renderSearchResults(
			initial_search_term,
			search_space
		)

		input_element.value = initial_search_term
	}

	document.body.addEventListener("click", e => {
		let current_node = e.target
		let hide = true

		while (current_node) {
			if (
				current_node === input_element ||
				current_node === results_div.parentNode) {
				hide = false
				break;
			}

			current_node = current_node.parentNode
		}

		if (hide) {
			hideSearchResults()
		}
	})
}
console.log("Loaded file init.js");} catch (e) {
console.error("Error in file init.js", e);}
})();

(function() {
try{function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "u")

	for (const result of results) {
		const target_element = document.querySelector(`a[name="${result.definition}"]`)

		console.log(result, result.definition, target_element)

		target_element.classList.remove("search-hidden")
		target_element.classList.remove("search-visible")

		if (result.show) {
			target_element.classList.add("search-visible")
		} else {
			target_element.classList.add("search-hidden")
		}

		target_element.querySelector(".label").innerHTML = result.html
	}
}

window.napcdoc.lib.initLocalSearch = function() {
	const elements = document.querySelectorAll("#nd-left-navigation a")
	let search_space = []

	for (const element of elements) {
		search_space.push({
			label: element.querySelector(".label").innerText,
			definition: element.getAttribute("name")
		})
	}

	const module_name = window.napcdoc_requested_module_name

	if (module_name) {
		document.querySelector("#nd-local-search-input").placeholder = `Search a definition of ${module_name}`
	} else {
		document.querySelector("#nd-local-search-input").placeholder = "Search a module"
	}

	document.querySelector("#nd-local-search-input").addEventListener("input", (e) => {
		renderSearchResults(e.currentTarget.value, search_space)
	})
}
console.log("Loaded file init.js");} catch (e) {
console.error("Error in file init.js", e);}
})();

(function() {
try{const mobile_nav = document.querySelector("#nd-mobile-navigation")
const style = document.createElement("style")

style.type = "text/css"

function measureAndSetup() {
	let saved_display = mobile_nav.style.display

	mobile_nav.style.maxHeight = "none"
	mobile_nav.style.display = "block"

	const height = mobile_nav.getBoundingClientRect().height

	mobile_nav.style.transition = "all .1s linear"
	mobile_nav.style.maxHeight = "0px"
	mobile_nav.style.display = saved_display

	return height
}

style.innerHTML = `
body.mobile-navigation-open #nd-mobile-navigation {
	max-height: ${measureAndSetup()}px !important;
}
`
document.getElementsByTagName("head")[0].appendChild(style)

document.querySelector("#toggle-mobile-menu").addEventListener("click", (e) => {
	if (e.currentTarget.classList.contains("empty")) {
		return
	}

	if (document.body.classList.contains("mobile-navigation-open")) {
		document.body.classList.remove("mobile-navigation-open")
	} else {
		document.body.classList.add("mobile-navigation-open")

		mobile_nav.style.maxHeight = "none"

		const height = mobile_nav.getBoundingClientRect().height

		mobile_nav.style.transition = "all .1s linear"
		mobile_nav.style.maxHeight = "0px"

		setTimeout(() => {
			mobile_nav.style.maxHeight = `${height}px`
		})
	}

})
console.log("Loaded file mobile-navigation.js");} catch (e) {
console.error("Error in file mobile-navigation.js", e);}
})();

(function() {
try{function popoverContentSection(definition, section) {
	let ret = ``
	let label = "???"

	switch (section) {
		case "params":
			label = "Parameter"
		break;

		case "fields":
			label = "Members"
		break;

		case "values":
			label = "Values"
		break;
	}

	ret += `<h2>${label}</h2><hr>`
	ret += `<div class="flex-table">`

	for (const value of definition[section]) {
		ret += `<div class="flex-table-row">`
		ret += `	<div class="flex-table-row-cell" style="font-size:14px">`
		ret += `		${value.name}`
		ret += `	</div>`
		ret += `</div>`
		ret += `<div class="flex-table-row">`
		ret += `	<div class="flex-table-row-cell" style="color: #7C7B7C;">`
		ret += `		${window.napcdoc.lib.replaceBackticks(value.description)}`
		ret += `	</div>`
		ret += `</div>`
	}

	ret += `</div>`

	return ret
}

window.napcdoc.lib.getPopoverContent = function(definition_name, definition) {
	let ret = ``

	ret += `
	<div class="popover-content-top">
		${window.napcdoc.lib.getIconOfDefinition(definition_name, 18, 18)}
		<h1>${definition_name}</h1>
	</div>
	`

	if (!("brief" in definition.general_info)) {
		//alert("oops")
		definition.general_info.brief = "NO BRIEF FOUND"
	}

	let style = ""

	if (definition.type === "type" && (definition.kind === "alias" || definition.kind === "opaque")) {
		style = `style="margin-bottom:0px"`
	}

	ret += `<span class="brief" ${style}>${
		window.napcdoc.lib.replaceBackticks(definition.general_info.brief)
	}</span>`

	if (definition.type === "fn") {
		ret += window.napcdoc.lib.getProtoOfDefinition(definition_name)
		ret += popoverContentSection(definition, "params")

		if (!definition.params.length) {
			ret += `<i>This function does not take any parameter.</i>`
		}

		ret += `<div style="height:10px;"></div>`

		ret += `<h2>Returns</h2><hr>`

		if (definition.return.type === "void") {
			ret += `<i>This function does not return anything.</i>`
		} else {
			ret += window.napcdoc.lib.replaceBackticks(definition.return.description)
		}
	} else if (definition.type === "type") {
		if (definition.kind !== "opaque") {
			ret += window.napcdoc.lib.getProtoOfDefinition(definition_name)
		}

		if (definition.kind === "enum" || definition.kind === "struct") {
			ret += popoverContentSection(
				definition, definition.kind === "enum" ? "values" : "fields"
			)
		}
	}

	return ret
}
console.log("Loaded file getPopoverContent.js");} catch (e) {
console.error("Error in file getPopoverContent.js", e);}
})();

(function() {
try{const POPOVER_WIDTH = 400

function getContentScrollPosition() {
	return document.querySelector("#napcdoc-layout-content").scrollTop
}

function setContentHeight({min_height, content_height}) {
	const height = min_height - content_height

	document.querySelector("#popover_padding_div").style.height = `${height}px`
}

function restoreContentHeight() {
	document.querySelector("#popover_padding_div").style.height = `0px`
}

/**
 * Get the content's height (independent of window size)
 */
function getContentHeight() {
	return document.querySelector("#napcdoc-layout-content").scrollHeight
}

/**
 * Holds the reference element (element that received mouseenter)
 * and the cloned element that was created on mouseenter
 */
let current_context = {
	reference_element: null,
	cloned_element: null,
	popover_element: null
}

/**
 * Function to adjust the content's height to prevent
 * popover content from being cut-off the container.
 */
function adjustContentHeight() {
	const ref = current_context.reference_element
	const popover = current_context.popover_element

	// number of pixels scrolled of #napcdoc-layout-content div 
	let scroll_top = getContentScrollPosition(0)
	// relative position of reference_element 
	let rel_top = ref.getBoundingClientRect().top
	// absolute 
	let abs_top = rel_top + scroll_top

	// height is starting of reference_element + height of popover 
	// .height not reliable because of scale() animation!
	// 100px must be added because of content-header!
	let content_top_padding = 100
	let virtual_height = abs_top + (popover.getBoundingClientRect().height * 1.02) + content_top_padding
	let min_height = virtual_height + 35 + 50 // plus padding 

	let content_height = getContentHeight()

	console.log(Date.now(), "Content's height is " + content_height + "px")
	console.log(Date.now(), "Minimal height required is " + min_height + "px")

	if (min_height > content_height) {
		console.warn(Date.now(), "Content's height is not enough for popover")
		console.log(Date.now(), min_height)

		setContentHeight({
			min_height, content_height
		})
	} else {
		restoreContentHeight()
	}
}

function getCurrentContextDefinition() {
	if (current_context.reference_element) {
		return current_context.reference_element.getAttribute("data-popover")
	}

	return "UNKNOWN"
}

/**
 * Timer to close popover
 */
let close_timer = null

function cancelClose() {
	if (close_timer !== null) {
		console.log(Date.now(), "Stopping close timer", getCurrentContextDefinition())
	}

	clearTimeout(close_timer)
	close_timer = null
}

function requestClose(timeout) {
	clearTimeout(close_timer)

	if (timeout === undefined) {
		timeout = 250
	}

	if (close_timer === null) {
		console.log(Date.now(), "Starting close timer", getCurrentContextDefinition(), timeout)
	} else {
		console.log(Date.now(), "RESTARTING close timer", getCurrentContextDefinition(), timeout)
	}

	close_timer = setTimeout(() => {
		/**
		 * reset close_timer because resetCurrentContext()
		 * closes the popover
		 */
		close_timer = null

		if (current_context.reference_element) {
			resetCurrentContext()
		}
	}, timeout)
}

/**
 * Close popup when mobile view is active
 */
window.addEventListener("resize", (e) => {
	if (1000 > window.innerWidth) {
		requestClose(0)
	}
})

/**
 * Resets the current context:
 * - removes the cloned node from the document
 * - restores the style of the reference element
 */
function resetCurrentContext() {
	if (!current_context.reference_element) {
		console.warn("resetCurrentContext(): nothing to reset")
		return
	}

	/**
	 * Clear cancel timer
	 */
	if (close_timer !== null) {
		console.log(Date.now(), "Cancelling ongoing close timer")

		clearTimeout(close_timer)
		close_timer = null
	}

	const clone = current_context.cloned_element
	const ref = current_context.reference_element

	clone.parentNode.removeChild(clone)
	ref.style.opacity = 1

	current_context.cloned_element = null
	current_context.reference_element = null

	const popover = current_context.popover_element

	popover.parentNode.removeChild(popover)

	restoreContentHeight()
	window.napcdoc.lib.unblurContent()
}

function onWheelEventHandler(e) {
	const content = document.querySelector("#napcdoc-layout-content")

	content.scrollTop += e.deltaY
}

function initContext(reference_element) {
	if (current_context.reference_element) {
		console.error("initContext() current context was not reset")
		return
	}

	const reference_style = window.getComputedStyle(reference_element)
	// Clone element
	const clone = reference_element.cloneNode(true)

	clone.addEventListener("mouseenter", (e) => {
		cancelClose()
	})

	clone.addEventListener("mouseleave", (e) => {
		requestClose()
	})

	clone.addEventListener("wheel", onWheelEventHandler, {
		passive: true
	})

	// Apply styles
	clone.style.fontFamily = reference_style.fontFamily
	clone.style.fontSize = reference_style.fontSize
	clone.style.fontWeight = reference_style.fontWeight
	clone.style.color = reference_style.color

	clone.style.position = "fixed"
	clone.style.zIndex = 4
	clone.style.top = "0px"
	clone.style.left = "0px"
	clone.style.willChange = "transform"

	const popover = document.createElement("div")

	const definition_name = reference_element.getAttribute("data-popover")
	const definition = window.napcdoc.lib.getDefinition(definition_name)

	popover.className = "popover"
	popover.style.display = "flex"
	popover.style.top = "0px"
	popover.style.left = "0px"
	popover.innerHTML = `
	<div class="popover-content" data-definition-type="${definition.type}">
		<div class="arrow-background"></div>
		<div class="arrow-line"></div>
		${window.napcdoc.lib.getPopoverContent(definition_name, definition)}
	</div>
	`

	popover.addEventListener("wheel", onWheelEventHandler, {
		passive: true
	})

	popover.addEventListener("mouseenter", (e) => {
		cancelClose()
	})

	popover.addEventListener("mouseleave", (e) => {
		requestClose()
	})

	document.body.appendChild(clone)
	document.body.appendChild(popover)

	reference_element.style.opacity = 0

	current_context.reference_element = reference_element
	current_context.cloned_element = clone
	current_context.popover_element = popover

	adjustContentHeight()

	popover.classList.add("visible")

	window.napcdoc.lib.blurContent()
}

function context_updatePositions() {
	if (!current_context.reference_element) {
		console.error("context_updatePositions(): invalid context")
		return
	}

	const clone = current_context.cloned_element
	const ref = current_context.reference_element
	const popover = current_context.popover_element
	const ref_pos = ref.getBoundingClientRect()

	clone.style.transform = `translate3d(${ref_pos.left}px, ${ref_pos.top}px, 0)`

	let left_position = ref_pos.left
	left_position += (ref_pos.width / 2)

	popover.style.top = `${ref_pos.top + 35}px`
	popover.style.left = `${left_position - (POPOVER_WIDTH / 2)}px`
}

function onContentScrolled() {
	if (current_context.reference_element) {
		context_updatePositions()
	}
}

window.napcdoc.lib.initPopover = function() {
	for (const element of document.querySelectorAll("[data-popover]")) {
		const definition_name = element.getAttribute("data-popover")

		element.addEventListener("mouseenter", (e) => {
			if (1000 > window.innerWidth) {
				console.warn("Popover is disabled on mobile", window.innerWidth)

				return
			}

			if (current_context.reference_element) {
				resetCurrentContext()
			}

			initContext(e.currentTarget)
			context_updatePositions()
		})
	}

	document.querySelector("#napcdoc-layout-content").addEventListener("scroll", (e) => {
		onContentScrolled()
	}, {
		passive: true
	})
}
console.log("Loaded file initPopover.js");} catch (e) {
console.error("Error in file initPopover.js", e);}
})();

(function() {
try{window.napcdoc.lib.blurContent = function() {
	if (!("_blur_counter" in window.napcdoc)) {
		window.napcdoc._blur_counter = 0
	}

	let new_blur_counter = window.napcdoc._blur_counter + 1

	if (new_blur_counter === 1) {
		document.querySelector("#nd-right-content").classList.add("blurred")
	}

	window.napcdoc._blur_counter = new_blur_counter
	console.log("inc", window.napcdoc._blur_counter)
}
console.log("Loaded file blurContent.js");} catch (e) {
console.error("Error in file blurContent.js", e);}
})();

(function() {
try{window.napcdoc.lib.getDefinition = function(definition_name) {
	return window.napcdoc.definitions[definition_name]
}
console.log("Loaded file getDefinition.js");} catch (e) {
console.error("Error in file getDefinition.js", e);}
})();

(function() {
try{window.napcdoc.lib.getSVGMarkup = function(svg, width, height) {
	let svg_content = window.napcdoc.assets.svg[`${svg}.svg`]

	svg_content = svg_content.replace(/width="([0-9]+)"/, `width="${width}"`)
	svg_content = svg_content.replace(/height="([0-9]+)"/, `height="${height}"`)

	return `
	<div
		class="napcdoc-svg-image"
		style="width:${width}px;height:${height}px;display:flex;align-items:center;justify-content:center;flex-grow:0;flex-shrink:0">
		${svg_content}
	</div>
	`
}

console.log("Loaded file getSVGMarkup.js");} catch (e) {
console.error("Error in file getSVGMarkup.js", e);}
})();

(function() {
try{window.napcdoc.lib.highlightString = function(string, string_to_highlight, html_element) {
	if (!string_to_highlight.length) {
		return string
	}

	// from: https://stackoverflow.com/a/43819621/2005038
	let reg = new RegExp(string_to_highlight, 'gi');

	return string.replace(reg, function(str) {return `<${html_element}>${str}</${html_element}>`;});
}
console.log("Loaded file highlightString.js");} catch (e) {
console.error("Error in file highlightString.js", e);}
})();

(function() {
try{// https://www.javascripttutorial.net/dom/css/check-if-an-element-is-visible-in-the-viewport/

window.napcdoc.lib.isInViewPort = function(element) {
	const rect = element.getBoundingClientRect()

	return (
		rect.top >= 0 &&
		rect.left >= 0 &&
		rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) &&
		rect.right <= (window.innerWidth || document.documentElement.clientWidth)
	);
}
console.log("Loaded file isInViewport.js");} catch (e) {
console.error("Error in file isInViewport.js", e);}
})();

(function() {
try{window.napcdoc.lib.localStorageGet = function(key, fallback) {
	try {
		let tmp = window.localStorage.getItem(key)

		if (!tmp.toString().length) {
			return fallback
		}

		return tmp
	} catch (error) {}

	return fallback
}
console.log("Loaded file localStorageGet.js");} catch (e) {
console.error("Error in file localStorageGet.js", e);}
})();

(function() {
try{window.napcdoc.lib.localStorageSet = function(key, value) {
	try {
		window.localStorage.setItem(key, value)
	} catch (error) {}
}
console.log("Loaded file localStorageSet.js");} catch (e) {
console.error("Error in file localStorageSet.js", e);}
})();

(function() {
try{/**
 *
 */
window.napcdoc.lib.search = function(search_space, search_term, highlight_element) {
	let results = search_space.map(entry => {
		const search_terms = search_term.split(" ")
		let include = true

		/**
		 * multiple search terms are treated as AND
		 * example: "parse dns" -> MUST include "parse" AND "dns"
		 */
		for (const term of search_terms) {
			if (!entry.label.toLowerCase().includes(term.toLowerCase())) {
				include = false

				break
			}
		}

		return {
			...entry,
			show: include
		}
	})

	if (!search_term.length) {
	//	return []
	}

	return results.map(result => {
		let html = result.label

		for (const term of search_term.split(" ")) {
			html = window.napcdoc.lib.highlightString(html, term, highlight_element)
		}

		return {
			...result,
			html,
			module: window.napcdoc.lib.getModuleOfDefinition(result.definition)
		}
	})
}
console.log("Loaded file search.js");} catch (e) {
console.error("Error in file search.js", e);}
})();

(function() {
try{window.napcdoc.lib.unblurContent = function() {
	if (!("_blur_counter" in window.napcdoc)) {
		console.error("unblurContent called before blurContent() got called")

		return
	}

	let new_blur_counter = window.napcdoc._blur_counter - 1

	if (new_blur_counter === 0) {
		document.querySelector("#nd-right-content").classList.remove("blurred")
	}

	window.napcdoc._blur_counter = new_blur_counter
	console.log("dec", window.napcdoc._blur_counter)
}
console.log("Loaded file unblurContent.js");} catch (e) {
console.error("Error in file unblurContent.js", e);}
})();

function replaceDefinitions(code) {
	let definition_names = Object.keys(window.napcdoc.definitions)

	definition_names = definition_names.sort((a,b) => b.length - a.length).filter(definition_name => {
		return "general_info" in window.napcdoc.definitions[definition_name]
	})

	let regex = new RegExp(definition_names.join("|"), "g")

	code = code.replaceAll(
		regex, (m) => {
			let kind = window.napcdoc.definitions[m].type

			if (kind === "fn") kind = "function"

			const module_name = window.napcdoc.lib.getModuleOfDefinition(m)

			const link = window.napcdoc.lib.fixLink(
				`definition/${module_name}/${m}.html#${m}`
			)

			return `<span class="c-${kind}" style="font-weight:400;"><a style="text-decoration:none" href="${link}">${m}</a></span>`
		}
	)

	return code
}

document.querySelectorAll("pre.code.hljs").forEach(el => {
	el.innerHTML = window.hljs.highlight(el.innerText, {
		language: "c"
	}).value

	el.innerHTML = replaceDefinitions(el.innerHTML)
})

//window.napcdoc.lib.initPopover()
window.napcdoc.lib.initGlobalSearch()
window.napcdoc.lib.initLocalSearch()
