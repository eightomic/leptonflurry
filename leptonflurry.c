/*
  Copyright © 2026 Eightomic <eightomic@proton.me>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <stdint.h>

uint32_t leptonflurry32x1(uint64_t counter, uint64_t key) {
  uint32_t a = counter ^ (counter >> 32) ^ 11111111;
  uint32_t b = key ^ (key >> 32);

  b += a ^ (a >> 7);
  a = (b + (b << 5)) ^ ((uint32_t)counter) ^ (b >> 7);
  b += (a << 7) ^ ((uint32_t)key) ^ a ^ (a >> 5);
  a += (b + (b << 13)) ^ (b >> 9);
  b += (a << 9) + (a ^ (a >> 5));
  a += (b + (b << 11)) ^ (b >> 7);
  b += a + (a << 5);
  a += b;
  return (a ^ (a >> 17)) + b;
}
