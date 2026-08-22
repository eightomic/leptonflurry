#include <stdint.h>

uint32_t leptonflurry1x32(uint32_t *counter, uint32_t *key) {
  uint32_t a = counter[0] + counter[1] + key[0] + 11111111;
  uint32_t b = counter[2] + counter[3] + key[1];

  a += (a << 9) + b;
  a += counter[0] ^ b ^ (b >> 7);
  b += (b << 13) + a;
  b += counter[1] ^ a ^ (a >> 5);
  a += a << 5;
  a ^= counter[2];
  b += b << 15;
  b ^= counter[3];
  a += (b + (b << 7)) ^ (b >> 15);
  b += (a + (a << 15)) ^ (a >> 13);
  a += (b + (b << 9)) ^ (b >> 5);
  b += (a + (a << 13)) ^ (a >> 7);
  return a + (b ^ (b >> 17));
}
