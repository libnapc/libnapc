#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fileno()
	#include <sys/stat.h> // fstat()

	napc_size HAL_napc_File_getSize(void *ptr) {
		FILE **fp = ptr;

		struct stat stats;
		const int fd = fileno(*fp);

		if (fd == -1) {
			NAPC_PANIC("Failed to get fileno().");
		} else if (fstat(fd, &stats) == -1) {
			NAPC_PANIC("Failed to fstat() file.");
		}

		return stats.st_size;
	}
#endif
