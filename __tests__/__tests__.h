#if !defined(NAPC_ALL_TESTS_FILE_h)
    #define NAPC_ALL_TESTS_FILE_h

    #if defined(__cplusplus)
        extern "C" {
    #endif
    void napc_aes__runTests(void);
    void napc_dns__runTests(void);
    void napc_hmac__runTests(void);
    void napc_misc__runTests(void);
    void napc_parser__runTests(void);
    void napc_pool__runTests(void);
    void napc_reader__runTests(void);
    void napc_writer__runTests(void);

    void napc_runAllTests(void);
    #if defined(__cplusplus)
        }
    #endif
#endif
