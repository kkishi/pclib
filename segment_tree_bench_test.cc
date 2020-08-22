#include <benchmark/benchmark.h>

#include "segment_tree.h"

static void BM_SegmentTree_Set(benchmark::State& state) {
  const int N = 1000000;
  const int M = 1000;
  for (auto _ : state) {
    state.PauseTiming();
    SegmentTree<int> tree(N, [](int a, int b) { return a + b; });
    std::vector<std::pair<int, int>> input;
    for (int i = 0; i < M; ++i) {
      input.push_back({std::rand() % N, std::rand()});
    }
    state.ResumeTiming();

    for (auto [i, x] : input) {
      tree.Set(i, x);
    }
  }
}
BENCHMARK(BM_SegmentTree_Set);

static void BM_SegmentTree_Aggregate(benchmark::State& state) {
  const int N = 1000000;
  const int M = 1000;

  SegmentTree<int> tree(N, [](int a, int b) { return a + b; });
  for (int i = 0; i < N; ++i) {
    tree.Set(i, std::rand() / N);
  }

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
      tree.Aggregate(begin, end);
    }
  }
}
BENCHMARK(BM_SegmentTree_Aggregate);

BENCHMARK_MAIN();
