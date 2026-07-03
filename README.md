# Recursion Exercises (C++)

Four self-contained functions written **recursively** (no loops), with an
assertion-based test driver.

## Functions
| Function | Description |
|----------|-------------|
| `modulo(m, n)` | Computes `m % n` by repeated subtraction. |
| `occurrences(number, d)` | Counts how many times digit `d` appears in `number`. |
| `lucky7s(s)` | Inserts `"77"` between each pair of adjacent identical characters. |
| `combinations(array, size, target)` | Whether any subset of `array` sums to `target`. |

## Build & Run
```bash
g++ -std=c++17 project2.cpp -o recursive
./recursive
```

## Suggested improvements
- Rename `project2.cpp` to something descriptive (e.g. `recursion_exercises.cpp`).
- Consider renaming the repo from `recursive` to `recursion-exercises`.
