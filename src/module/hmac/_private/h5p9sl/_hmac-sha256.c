/*
   hmac_sha256.c
   Originally written by https://github.com/h5p9sl
 */

#include <module/hmac/_private/h5p9sl/_hmac-sha256.h>
#include <module/hmac/_private/h5p9sl/_sha256.h>

#include <stdlib.h>
#include <string.h>

#define SHA256_BLOCK_SIZE 64

/* LOCAL FUNCTIONS */

// Concatenate X & Y, return hash.
static void* H(const void* x,
               const size_t xlen,
               const void* y,
               const size_t ylen,
               void* out,
               const size_t outlen);

// Wrapper for sha256
static void* sha256(const void* data,
                    const size_t datalen,
                    void* out,
                    const size_t outlen);

// Declared in hmac_sha256.h
size_t H5P9SL_hmac_sha256(const void* key,
                   const size_t keylen,
                   const void* data,
                   const size_t datalen,
                   void* out,
                   const size_t outlen) {
  uint8_t k[SHA256_BLOCK_SIZE];
  uint8_t k_ipad[SHA256_BLOCK_SIZE];
  uint8_t k_opad[SHA256_BLOCK_SIZE];
  uint8_t ihash[H5P9SL_SHA256_HASH_SIZE];
  uint8_t ohash[H5P9SL_SHA256_HASH_SIZE];
  size_t sz;
  int i;

  memset(k, 0, sizeof(k));
  memset(k_ipad, 0x36, SHA256_BLOCK_SIZE);
  memset(k_opad, 0x5c, SHA256_BLOCK_SIZE);

  if (keylen > SHA256_BLOCK_SIZE) {
    // If the key is larger than the hash algorithm's
    // block size, we must digest it first.
    sha256(key, keylen, k, sizeof(k));
  } else {
    memcpy(k, key, keylen);
  }

  for (i = 0; i < SHA256_BLOCK_SIZE; i++) {
    k_ipad[i] ^= k[i];
    k_opad[i] ^= k[i];
  }

  // Perform HMAC algorithm: ( https://tools.ietf.org/html/rfc2104 )
  //      `H(K XOR opad, H(K XOR ipad, data))`
  H(k_ipad, sizeof(k_ipad), data, datalen, ihash, sizeof(ihash));
  H(k_opad, sizeof(k_opad), ihash, sizeof(ihash), ohash, sizeof(ohash));

  sz = (outlen > H5P9SL_SHA256_HASH_SIZE) ? H5P9SL_SHA256_HASH_SIZE : outlen;
  memcpy(out, ohash, sz);
  return sz;
}

// used as an alternative to malloc()
static uint8_t _tmp_buffer[1256];
void napc_halt(
	const char *file,
	int file_line,
	const char *fn,
	const char *fmt,
	...
);
//

static void* H(const void* x,
               const size_t xlen,
               const void* y,
               const size_t ylen,
               void* out,
               const size_t outlen) {
  void* result;
  size_t buflen = (xlen + ylen);
  uint8_t *buf = _tmp_buffer;

  memset(_tmp_buffer, 0, sizeof(_tmp_buffer));

  if (buflen > sizeof(_tmp_buffer)) {
    napc_halt(
      __FILE__,
      __LINE__,
      __func__,
      "Buflen exceeds buffer! (buflen=%lu)",
      (unsigned long)buflen
    );
  }

  memcpy(buf, x, xlen);
  memcpy(buf + xlen, y, ylen);
  result = sha256(buf, buflen, out, outlen);

  memset(_tmp_buffer, 0, sizeof(_tmp_buffer));

  return result;
}

static void* sha256(const void* data,
                    const size_t datalen,
                    void* out,
                    const size_t outlen) {
  size_t sz;
  H5P9SL_Sha256Context ctx;
  H5P9SL_SHA256_HASH hash;

  H5P9SL_Sha256Initialise(&ctx);
  H5P9SL_Sha256Update(&ctx, data, datalen);
  H5P9SL_Sha256Finalise(&ctx, &hash);

  sz = (outlen > H5P9SL_SHA256_HASH_SIZE) ? H5P9SL_SHA256_HASH_SIZE : outlen;
  return memcpy(out, hash.bytes, sz);
}
