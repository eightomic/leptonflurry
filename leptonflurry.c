#include <stdint.h>

uint32_t leptonflurry32x1(uint32_t *counter, uint32_t *key) {
  uint32_t a = key[0] + 11111;
  uint32_t b = key[1] + 1111111111;

  a += a << 15;
  a += counter[0] ^ b;
  a += a << 23;
  a ^= a >> 7;
  b += a + (a << 13);
  b += counter[1];
  b += b << 13;
  b ^= b >> 5;
  a += b + (b << 19);
  b += a + (a << 23);
  a ^= b ^ (b >> 17);
  b += a + (a << 7);
  a ^= b ^ (b >> 13);
  b ^= a ^ (a >> 15);
  a += b + (b << 9);
  b += a + (a << 17);
  return (a ^ (a >> 7)) + (b ^ (b >> 11));
}
