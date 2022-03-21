#if !defined(HAL_NAPC_SERIAL_h)
	#define HAL_NAPC_SERIAL_h

	void HAL_napc_initSerial(void);
	void HAL_napc_puts(const char *str);
	void HAL_napc_putc(char ch);
#endif
