#include <stdint.h>

uint32_t leptonflurry32x1(uint64_t counter, uint64_t key) {
  uint32_t a = counter ^ (counter >> 32) ^ 111111111;
  uint32_t b = key ^ (key >> 32);

  a += a << 9;
  b += (b << 13) ^ a ^ (a >> 15);
  a = (b + (b << 7)) ^ ((uint32_t)counter) ^ (b >> 7);
  b += (a << 9) ^ ((uint32_t)key) ^ a ^ (a >> 13);
  a += (b + (b << 15)) ^ (b >> 9);
  b += (a << 13) + (a ^ (a >> 5));
  a += (b + (b << 13)) ^ (b >> 7);
  return (a ^ (a >> 5)) + (b ^ (b >> 17));
}
