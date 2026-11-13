
# NLZ3000 – Number of Leading Zeros Optimization

A Computer Architecture project developed as part of CE201 at the German Jordanian University.

## Project Overview

This project explores the performance improvement of counting leading zeros in 64-bit unsigned integers by replacing a software-based bit-checking loop with a processor-supported instruction.

## Optimized Implementation

The optimized implementation uses GCC's `__builtin_clzll()` intrinsic.

```c
static inline int nlz(uint64_t x)
{
    if (x == 0)
        return 64;
    return __builtin_clzll(x);
}
```

The generated x86-64 assembly includes the LZCNT instruction:

```asm
lzcntq %rax, %rdx
```

## Performance Results

Five benchmark runs were conducted on the same computer.

| Metric | Original | Optimized |
|---|---:|---:|
| Arithmetic Mean | 35.9420 s | 0.6427 s |
| Geometric Mean | 24.1773 s | 0.5634 s |

**Speedup:**
- Arithmetic mean: 55.93x
- Geometric mean: 42.92x

Both implementations produced the same expected sum:

`35,073,741,857`

## Technologies

- C Programming
- GCC 16.2.0
- MSYS2 UCRT64
- x86-64 Assembly
- LZCNT Instruction
- Performance Benchmarking

## Compilation

```bash
gcc -O2 -march=native nlz_fast.c -o nlz_fast
```

Run:

```bash
./nlz_fast
```

## Team

Mohammed Abu Shaqra & Abdallah

German Jordanian University  
CE201 – Computer Architecture  
November 2026
