# LeptonFlurry

[![LeptonFlurry](leptonflurry.jpg)](https://github.com/eightomic/leptonflurry)

LeptonFlurry (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast constrained 8-bit PRNG (non-cryptographic) that has a period of at least 2⁶⁴ (from a Weyl sequence), excellent statistical randomness quality test results (single-instance bitstreams passed PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 1TB -te 0 -tf 1`), low-footprint implementation (efficient memory usage and small code size), no ROTL/ROTR operations, no auxiliary array allocations, no comparison/division/modulus/multiplication operators, reversibility (state rewinding) and ultra-fast speed (relative to the aforementioned constraints).

LeptonFlurry is implemented in C (requiring the `stdint.h` header to define unsigned integral types for both an 8-bit `uint8_t` and a 64-bit `uint64_t`).

[leptonflurry.c](leptonflurry.c)

The `leptonflurry` function modifies the state in a `struct leptonflurry_state` instance to generate a deterministic pseudorandom `uint8_t` integer as the return value. Each state variable (`a` and `b`) in a `struct leptonflurry_state` instance must be seeded before generating a deterministic `leptonflurry` bitstream (that must discard the first 3 `leptonflurry` results as a state warmup).

Eightomic is evaluating the suitability of other Weyl constants (besides `11111111`) for distinct parallel bitstreams.

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (with `gcc -Os` from an AMD A4-9120C) that generates 1 billion pseudorandom outputs (each as a `uint8_t` integer) in a blocking `#pragma GCC unroll 0` loop.

```
               Elapsed   State Bits

leptonflurry   3051ms    128
biski64        3832ms    192
sfc64          4456ms    256
```
