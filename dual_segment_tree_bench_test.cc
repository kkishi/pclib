#include <benchmark/benchmark.h>

#include "dual_segment_tree.h"

static void BM_DualSegmentTree_Get(benchmark::State& state) {
  const int N = 1000000;
  const int M = 1000;
  for (auto _ : state) {
    state.PauseTiming();
    DualSegmentTree<int> tree(N, [](int a, int b) { return a + b; });
    state.ResumeTiming();

    for (int i = 0; i < M; ++i) {
      tree.Get(i);
    }
  }
}
BENCHMARK(BM_DualSegmentTree_Get);

static void BM_DualSegmentTree_Update(benchmark::State& state) {
  const int N = 1000000;
  const int M = 1000;

  DualSegmentTree<int> tree(N, [](int a, int b) { return a + b; });
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<std::pair<int, int>> input;
    for (int i = 0; i < M; ++i) {
      int begin = std::rand() % (N + 1), end = std::rand() % (N + 1);
      if (begin > end) std::swap(begin, end);
      input.push_back({begin, end});
    }
    state.ResumeTiming();

    for (auto [begin, end] : input) {
      tree.Update(begin, end, 42);
    }
  }
}
BENCHMARK(BM_DualSegmentTree_Update);

BENCHMARK_MAIN();
