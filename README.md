# LeptonFlurry

[![LeptonFlurry](leptonflurry.jpg)](https://github.com/eightomic/leptonflurry)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)
- [Randomness](README.md?tab=readme-ov-file#randomness)
- [Speed](README.md?tab=readme-ov-file#speed)

## Introduction

LeptonFlurry is the ultra-efficient counter-based PRNG (non-cryptographic) that has a period of at least 2⁶⁴ (from 2 32-bit counters), excellent statistical randomness quality test results, low-footprint implementation, massive parallelism (up to 2⁶⁴ key-based independent streams that each have a period of 2⁶⁴), state rewinding (counter-based index jumps) and ultra-fast speed.

When independent parallel streams aren't required, a chaotic PRNG ([QuarkBurst](https://github.com/eightomic/quarkburst)) is the alternative.

## Author

LeptonFlurry was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

LeptonFlurry is licensed with [BSD-3-Clause](LICENSE).

## Implementation

Each mention of LeptonFlurry refers to each of the 3 following variants individually (`leptonflurry1x32`, `leptonflurry2x32`, `leptonflurry4x32` and `leptonflurry8x32`) implemented in C (requiring the `stdint.h` header to define a 32-bit, unsigned integral type for `uint32_t`).

[leptonflurry.c](leptonflurry.c)

#### `leptonflurry1x32`

The `leptonflurry1x32` function generates (from 2 `uint32_t` `counter` integers that must be seeded and 2 `uint32_t` `key` integers that must be seeded) a deterministic pseudorandom `uint32_t` integer as the return value.

#### `leptonflurry2x32`

`leptonflurry2x32` doesn't exist.

#### `leptonflurry4x32`

`leptonflurry4x32` doesn't exist.

#### `leptonflurry8x32`

`leptonflurry8x32` doesn't exist.

## Randomness

LeptonFlurry yielded the following excellent results (from a stream that permutes through 2 `uint32_t` `counter` integers with 2 fixed `uint32_t` `key` integers) from statistical randomness quality tests.

#### Dieharder 3.31.1

LeptonFlurry passed `dieharder -Y 1 -a -g 200 -k 2` (each ambiguous result resolved to a `PASSED` result).

#### PractRand 0.96

LeptonFlurry passed `RNG_test stdin -tlmin 1KB -tlmax 8TB`.

Further testing is in progress (BigCrush, NIST STS, PractRand 32TB, SmokeRand).

## Speed

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (using `gcc -O3` from an AMD A4-9120C) that generates 1 billion pseudorandom `uint32_t` integers (and hashes them) in a `#pragma GCC unroll 0` loop.

| PRNG | Elapsed |
| --- | --- |
| **`leptonflurry8x32`** | **?ms** |
| **`leptonflurry4x32`** | **?ms** |
| **`leptonflurry2x32`** | **?ms** |
| **`leptonflurry1x32`** | **2612ms** |
| `threefry4x32` | 3532ms |
| `philox4x32` | 3626ms |
| *`aes_ni_ctr_128` (`-maes -msse4`) | 3796ms |
| `threefry2x32` | 4959ms |
| `philox2x32` | 5139ms |
| `squares32` | 7552ms |
| `chacha8` | 13230ms |
| `chacha20` | 26402ms |

\* Each 128-bit output integer was extracted as 2 `uint64_t` integers.
