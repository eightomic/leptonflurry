# LeptonFlurry

[![LeptonFlurry](leptonflurry.jpg)](https://github.com/eightomic/leptonflurry)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)
- [Quality](README.md?tab=readme-ov-file#quality)
- [Speed](README.md?tab=readme-ov-file#speed)

## Introduction

LeptonFlurry is the efficient non-cryptographic CBRNG that has excellent statistical randomness quality test results, low-footprint implementation (efficient memory usage and small code size), massive parallelism (up to 2⁶⁴ key-based independent bitstreams that each have a counter-based period of 2¹²⁸), no division/modulus/multiplication operators and ultra-fast speed.

## Author

LeptonFlurry was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

LeptonFlurry is licensed with [BSD-3-Clause](LICENSE).

## Implementation

Each mention of LeptonFlurry refers to each of the 6 following variants individually (`leptonflurry1x32`, `leptonflurry2x32`, `leptonflurry4x32`, `leptonflurry1x64`, `leptonflurry2x64` and `leptonflurry4x64`) implemented in C (requiring the `stdint.h` header to define both a 32-bit, unsigned integral type for `uint32_t` and a 64-bit, unsigned integral type for `uint64_t`).

[leptonflurry.c](leptonflurry.c)

#### 32-Bit

Each 32-bit LeptonFlurry variant uses 4 `uint32_t` `counter` integers that must be seeded and 2 `uint32_t` `key` integers that must be seeded.

The `leptonflurry1x32` function generates a deterministic pseudorandom `uint32_t` integer as the return value.

The `leptonflurry2x32` function generates 2 deterministic pseudorandom `uint32_t` integers in the `output` array.

The `leptonflurry4x32` function generates 4 deterministic pseudorandom `uint32_t` integers in the `output` array.

#### 64-Bit

`leptonflurry1x64`, `leptonflurry2x64` and `leptonflurry4x64` aren't ready to publish yet.

## Quality

LeptonFlurry bitstreams yielded the following excellent results (with multiple increment combinations of the counter and the key) from statistical randomness quality tests.

#### Bit Independence Criterion (BIC)

LeptonFlurry passed cryptographic BIC tests with bitstreams that each had XORed output pairs (as a result of bit flips that were equidistributed among both the counter and the key).

#### Dieharder 3.31.1

LeptonFlurry passed `dieharder -Y 1 -a -g 200 -k 2` (each ambiguous result resolved to a `PASSED` result).

#### NIST STS 2.1.2

LeptonFlurry passed `assess 1000000` with 100 bitstreams.

#### Next-Bit Test (Forward Unpredictability)

LeptonFlurry passed next-bit tests (that combined BIC and SAC to indicate asymptotic next-bit security properties).

#### PractRand 0.96

LeptonFlurry passed `RNG_test stdin -tlmin 1KB -tlmax 32TB`.

#### Strict Avalanche Criterion (SAC)

LeptonFlurry passed cryptographic SAC tests (with a near-perfect score between 0.4995 and 0.5005) with 100 bitstreams that each had 2¹⁹ output pairs (as a result of bit flips that were equidistributed among both the counter and the key).

#### TestU01 1.2.3

LeptonFlurry passed BigCrush and pseudoDIEHARD.

## Speed

#### 32-Bit

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (with `gcc -O3` from an AMD A4-9120C) that generated 1 billion pseudorandom `uint32_t` integers in a blocking `#pragma GCC unroll 0` loop.

```
                           Elapsed    Counter-Based

leptonflurry4x32           976ms      Yes
leptonflurry2x32           1502ms     Yes
leptonflurry1x32           2421ms     Yes
xorwow                     2882ms     No
pcg32_minimal              2983ms     No
pcg_oneseq_64_xsh_rr_32    2987ms     No
lehmer_mcg32               3402ms     No
pcg_oneseq_64_xsh_rs_32    3404ms     No
lcg32                      3409ms     No
threefry4x32               3532ms     Yes
philox4x32                 3626ms     Yes
threefry2x32               4959ms     Yes
philox2x32                 5139ms     Yes
squares32                  7552ms     Yes
chacha8                    13230ms    Yes
chacha20                   26402ms    Yes
```
