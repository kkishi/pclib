load("@io_bazel_rules_go//go:def.bzl", "go_binary")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "extgcd",
    srcs = ["extgcd.h"],
)

cc_test(
    name = "extgcd_test",
    srcs = ["extgcd_test.cc"],
    deps = [
        ":extgcd",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "rational",
    srcs = ["rational.h"],
)

cc_test(
    name = "rational_test",
    srcs = ["rational_test.cc"],
    deps = [
        ":rational",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "modint",
    srcs = ["modint.h"],
)

cc_test(
    name = "modint_test",
    srcs = ["modint_test.cc"],
    deps = [
        ":modint",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "modint_bench_test",
    srcs = ["modint_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":modint",
        "@benchmark",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "compress",
    srcs = ["compress.h"],
)

cc_test(
    name = "compress_test",
    srcs = ["compress_test.cc"],
    deps = [
        ":compress",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "macros",
    srcs = ["macros.h"],
)

cc_test(
    name = "macros_test",
    srcs = ["macros_test.cc"],
    deps = [
        ":macros",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bound_grid",
    srcs = ["bound_grid.h"],
)

cc_library(
    name = "factors",
    srcs = ["factors.h"],
)

cc_test(
    name = "factors_test",
    srcs = ["factors_test.cc"],
    deps = [
        ":factors",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "primes",
    srcs = ["primes.h"],
)

cc_test(
    name = "primes_test",
    srcs = ["primes_test.cc"],
    deps = [
        ":primes",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "segment_tree",
    srcs = ["segment_tree.h"],
)

cc_test(
    name = "segment_tree_test",
    srcs = ["segment_tree_test.cc"],
    deps = [
        ":segment_tree",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "segment_tree_bench_test",
    srcs = ["segment_tree_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":segment_tree",
        "@benchmark",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "dual_segment_tree",
    srcs = ["dual_segment_tree.h"],
)

cc_test(
    name = "dual_segment_tree_test",
    srcs = ["dual_segment_tree_test.cc"],
    deps = [
        ":dual_segment_tree",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "dual_segment_tree_bench_test",
    srcs = ["dual_segment_tree_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":dual_segment_tree",
        "@benchmark",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "dijkstra",
    srcs = ["dijkstra.h"],
    deps = [":graph"],
)

cc_test(
    name = "dijkstra_test",
    srcs = ["dijkstra_test.cc"],
    deps = [
        ":dijkstra",
        ":graph",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "disjoint_set",
    srcs = ["disjoint_set.h"],
)

cc_test(
    name = "disjoint_set_test",
    srcs = ["disjoint_set_test.cc"],
    deps = [
        ":disjoint_set",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "geometry",
    srcs = ["geometry.h"],
)

cc_test(
    name = "geometry_test",
    srcs = ["geometry_test.cc"],
    deps = [
        ":geometry",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "rerooting",
    srcs = ["rerooting.h"],
    deps = [
        ":bidirected_graph",
    ],
)

cc_test(
    name = "rerooting_test",
    srcs = ["rerooting_test.cc"],
    deps = [
        ":modint",
        ":rerooting",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bignum",
    srcs = ["bignum.h"],
)

cc_test(
    name = "bignum_test",
    srcs = ["bignum_test.cc"],
    deps = [
        ":bignum",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "grid",
    srcs = ["grid.h"],
)

cc_test(
    name = "grid_test",
    srcs = ["grid_test.cc"],
    deps = [
        ":grid",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "binary_search",
    srcs = ["binary_search.h"],
)

cc_test(
    name = "binary_search_test",
    srcs = ["binary_search_test.cc"],
    deps = [
        ":binary_search",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "warshall_floyd",
    srcs = ["warshall_floyd.h"],
)

cc_test(
    name = "warshall_floyd_test",
    srcs = ["warshall_floyd_test.cc"],
    deps = [
        ":warshall_floyd",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "strongly_connected_component",
    srcs = ["strongly_connected_component.h"],
    deps = [":graph"],
)

cc_test(
    name = "strongly_connected_component_test",
    srcs = ["strongly_connected_component_test.cc"],
    deps = [
        ":graph",
        ":strongly_connected_component",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "graph",
    srcs = ["graph.h"],
)

cc_test(
    name = "graph_test",
    srcs = ["graph_test.cc"],
    deps = [
        ":graph",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bidirected_graph",
    srcs = ["bidirected_graph.h"],
)

cc_test(
    name = "bidirected_graph_test",
    srcs = ["bidirected_graph_test.cc"],
    deps = [
        ":bidirected_graph",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bellman_ford",
    srcs = ["bellman_ford.h"],
    deps = [":graph"],
)

cc_test(
    name = "bellman_ford_test",
    srcs = ["bellman_ford_test.cc"],
    deps = [
        ":bellman_ford",
        ":graph",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "rolling_hash_match",
    srcs = ["rolling_hash_match.h"],
)

cc_test(
    name = "rolling_hash_match_test",
    srcs = ["rolling_hash_match_test.cc"],
    deps = [
        ":rolling_hash_match",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "rolling_hash",
    srcs = ["rolling_hash.h"],
)

cc_test(
    name = "rolling_hash_test",
    srcs = ["rolling_hash_test.cc"],
    deps = [
        ":rolling_hash",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bit",
    srcs = ["bit.h"],
)

cc_test(
    name = "bit_test",
    srcs = ["bit_test.cc"],
    deps = [
        ":bit",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "mo",
    srcs = ["mo.h"],
)

cc_test(
    name = "mo_test",
    srcs = ["mo_test.cc"],
    deps = [
        ":mo",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "edmonds_karp",
    srcs = ["edmonds_karp.h"],
    deps = [":graph"],
)

cc_test(
    name = "edmonds_karp_test",
    srcs = ["edmonds_karp_test.cc"],
    deps = [
        ":edmonds_karp",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "topological_sort",
    srcs = ["topological_sort.h"],
)

cc_test(
    name = "topological_sort_test",
    srcs = ["topological_sort_test.cc"],
    deps = [
        ":topological_sort",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "i128",
    srcs = ["i128.h"],
)

cc_test(
    name = "i128_test",
    srcs = ["i128_test.cc"],
    deps = [
        ":i128",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "matrix",
    srcs = ["matrix.h"],
)

cc_test(
    name = "matrix_test",
    srcs = ["matrix_test.cc"],
    deps = [
        ":matrix",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "int_sqrt",
    srcs = ["int_sqrt.h"],
    deps = [
        ":binary_search",
    ],
)

cc_test(
    name = "int_sqrt_test",
    srcs = ["int_sqrt_test.cc"],
    deps = [
        ":int_sqrt",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "divisors",
    srcs = ["divisors.h"],
    deps = [
        ":binary_search",
    ],
)

cc_test(
    name = "divisors_test",
    srcs = ["divisors_test.cc"],
    deps = [
        ":divisors",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "lca",
    srcs = ["lca.h"],
    deps = [
        ":graph",
    ],
)

cc_test(
    name = "lca_test",
    srcs = ["lca_test.cc"],
    deps = [
        ":lca",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
