#include <stdint.h>

uint32_t leptonflurry1x32(uint32_t *counter, uint32_t *key) {
  uint32_t a = counter[0] + counter[1] + key[0] + 11111111;
  uint32_t b = counter[2] + counter[3] + key[1];

  a += (a << 9) ^ counter[2] ^ (a >> 5) ^ counter[3] ^ key[1];
  b += (b << 13) ^ counter[0] ^ (b >> 9) ^ counter[1] ^ key[0] ^ a;
  a += (b + (b << 7)) ^ (b >> 5);
  b += (a + (a << 9)) ^ (a >> 7);
  a += (b << 11) + (b ^ (b >> 9));
  b += (a << 13) + (a ^ (a >> 11));
  return (a ^ (a >> 17)) + (b << 15) + (b ^ (b >> 13));
}

void leptonflurry2x32(uint32_t *counter, uint32_t *key, uint32_t *output) {
  uint32_t a = counter[0] + counter[1] + key[0] + 111111111;
  uint32_t b = counter[2] + counter[3] + key[1];

  a += (a << 9) ^ counter[2] ^ (a >> 5) ^ counter[3] ^ key[1];
  b += (b << 13) ^ counter[0] ^ (b >> 9) ^ counter[1] ^ key[0] ^ a;
  a += (b + (b << 9)) ^ (b >> 7);
  b += (a + (a << 7)) ^ (a >> 5);
  a += (b << 13) + (b ^ (b >> 11));
  b += (a << 11) + (a ^ (a >> 9));
  a = (a ^ (a >> 15)) + (b << 17) + (b ^ (b >> 11));
  output[0] = a ^ b;
  output[1] = (a << 15) + (a ^ (a >> 17)) + b;
}

void leptonflurry4x32(uint32_t *counter, uint32_t *key, uint32_t *output) {
  uint32_t a = counter[0] + counter[1] + key[0] + 1111111111;
  uint32_t b = counter[2] + counter[3] + key[1];
  uint32_t c;
  uint32_t d;

  a += (a << 9) ^ counter[2] ^ (a >> 5) ^ counter[3] ^ key[1];
  b += (b << 13) ^ counter[0] ^ (b >> 9) ^ counter[1] ^ key[0] ^ a;
  a += (b + (b << 7)) ^ (b >> 5);
  b += (a + (a << 9)) ^ (a >> 7);
  a += (b << 11) + (b ^ (b >> 9));
  c = a;
  b += (a << 13) + (a ^ (a >> 11));
  d = b;
  a = (a ^ (a >> 17)) + (b << 15) + (b ^ (b >> 13));
  output[0] = a ^ b;
  output[1] = (a << 15) + (a ^ (a >> 17)) + b;
  b += a ^ (a >> 15);
  output[2] = b + c;
  output[3] = b ^ d;
}
