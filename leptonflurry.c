#include <stdint.h>

struct leptonflurry_state {
  uint64_t a;
  uint64_t b;
};

uint8_t leptonflurry(struct leptonflurry_state *s) {
  s->a += (s->a >> 8) + s->b;
  s->b += 11111111;
  return s->a;
}
