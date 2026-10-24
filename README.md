# LeptonFlurry

[![LeptonFlurry](leptonflurry.jpg)](https://github.com/eightomic/leptonflurry)

LeptonFlurry (as an [open-source](LICENSE) product of [Eightomic](https://eightomic.github.io)) is the fast efficient CBRNG (non-cryptographic) that has 2⁶⁴ key-based independent parallel bitstreams that each have a counter-based period of 2⁶⁴, excellent statistical randomness quality test results (counter/key iterated bitstreams passed Dieharder 3.31.1 `dieharder -Y 1 -a -g 200 -k 2`, NIST STS 2.1.2 `assess 1000000` with 100 bitstreams, PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 32TB`, TestU01 1.2.3 BigCrush and cryptographic SAC tests that each had 2¹⁸ bit-flipped output pairs with near-perfect avalanche scores between 0.4991 and 0.5009), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, no internal state transitions (the counter/key is the implementation-managed state) and ultra-fast speed (relative to the aforementioned constraints).

Each mention of LeptonFlurry refers to each of the following 6 variants individually (`leptonflurry32x1`, `leptonflurry32x2`, `leptonflurry32x4`, `leptonflurry64x1`, `leptonflurry64x2` and `leptonflurry64x4`) implemented in C (requiring the `stdint.h` header to define unsigned integral types for both a 32-bit `uint32_t` and a 64-bit `uint64_t`).

[leptonflurry.c](leptonflurry.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of generating 10 million pseudorandom output integers (`uint32_t` for `leptonflurry32` variants and `uint64_t` for `leptonflurry64` variants) in a blocking loop.

The `leptonflurry32x1` function generates (from a `uint64_t` `counter` integer that must be seeded and a `uint64_t` `key` integer that must be seeded) a deterministic pseudorandom `uint32_t` integer as the return value.

```
                   Elapsed   Counter/Key/Mixing/Output Bits

leptonflurry32x1   1196ms    224
squares32          2266ms    352
```

`leptonflurry32x2`, `leptonflurry32x4`, `leptonflurry64x1`, `leptonflurry64x2` and `leptonflurry64x4` aren't ready to publish yet.
