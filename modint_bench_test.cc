#include <benchmark/benchmark.h>

#include "modint.h"

static void BM_ModInt_Fib(benchmark::State& state) {
  const int N = 100000;
  for (auto _ : state) {
    ModInt<> a = 0, b = 0, c = 1;
    for (int i = 0; i < N; ++i) {
      a = b;
      b = c;
      c = a + b;
      benchmark::DoNotOptimize(c);
    }
  }
}
BENCHMARK(BM_ModInt_Fib);

BENCHMARK_MAIN();
