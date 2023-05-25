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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "modint_bench_test",
    srcs = ["modint_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":modint",
        "@com_google_benchmark//:benchmark_main",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "compressor",
    srcs = ["compressor.h"],
)

cc_test(
    name = "compressor_test",
    srcs = ["compressor_test.cc"],
    deps = [
        ":compressor",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "segment_tree_bench_test",
    srcs = ["segment_tree_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":segment_tree",
        "@com_google_benchmark//:benchmark_main",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "dual_segment_tree_bench_test",
    srcs = ["dual_segment_tree_bench_test.cc"],
    tags = ["manual"],
    deps = [
        ":dual_segment_tree",
        "@com_google_benchmark//:benchmark_main",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "rerooting",
    srcs = ["rerooting.h"],
    deps = [":bidirected_graph"],
)

cc_test(
    name = "rerooting_test",
    srcs = ["rerooting_test.cc"],
    deps = [
        ":modint",
        ":rerooting",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "graph",
    srcs = ["graph.h"],
    deps = [":fix"],
)

cc_test(
    name = "graph_test",
    srcs = ["graph_test.cc"],
    deps = [
        ":graph",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "rolling_hash",
    srcs = ["rolling_hash.h"],
    deps = [":pow"],
)

cc_test(
    name = "rolling_hash_test",
    srcs = ["rolling_hash_test.cc"],
    deps = [
        ":rolling_hash",
        ":primitive_root",
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "int_sqrt",
    srcs = ["int_sqrt.h"],
    deps = [":binary_search"],
)

cc_test(
    name = "int_sqrt_test",
    srcs = ["int_sqrt_test.cc"],
    deps = [
        ":int_sqrt",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "divisors",
    srcs = ["divisors.h"],
)

cc_test(
    name = "divisors_test",
    srcs = ["divisors_test.cc"],
    deps = [
        ":divisors",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "lca",
    srcs = ["lca.h"],
    deps = [
        ":graph",
        ":fix",
    ],
)

cc_test(
    name = "lca_test",
    srcs = ["lca_test.cc"],
    deps = [
        ":lca",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "pow",
    srcs = ["pow.h"],
)

cc_test(
    name = "pow_test",
    srcs = ["pow_test.cc"],
    deps = [
        ":pow",
        ":modint",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "numeric_sequence",
    srcs = ["numeric_sequence.h"],
    deps = [":pow"],
)

cc_test(
    name = "numeric_sequence_test",
    srcs = ["numeric_sequence_test.cc"],
    deps = [
        ":numeric_sequence",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "z_algorithm",
    srcs = ["z_algorithm.h"],
)

cc_test(
    name = "z_algorithm_test",
    srcs = ["z_algorithm_test.cc"],
    deps = [
        ":z_algorithm",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "primitive_root",
    srcs = ["primitive_root.h"],
    deps = [
        ":divisors",
        ":pow",
        ]
)

cc_test(
    name = "primitive_root_test",
    srcs = ["primitive_root_test.cc"],
    deps = [
        ":primitive_root",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "sparse_table",
    srcs = ["sparse_table.h"],
)

cc_test(
    name = "sparse_table_test",
    srcs = ["sparse_table_test.cc"],
    deps = [
        ":sparse_table",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "rotate90",
    srcs = ["rotate90.h"],
)

cc_test(
    name = "rotate90_test",
    srcs = ["rotate90_test.cc"],
    deps = [
        ":rotate90",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "pbds",
    srcs = ["pbds.h"],
)

cc_test(
    name = "pbds_test",
    srcs = ["pbds_test.cc"],
    deps = [
        ":pbds",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "binary_trie",
    srcs = ["binary_trie.h"],
)

cc_test(
    name = "binary_trie_test",
    srcs = ["binary_trie_test.cc"],
    deps = [
        ":binary_trie",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "suffix_array",
    srcs = ["suffix_array.h"],
)

cc_test(
    name = "suffix_array_test",
    srcs = ["suffix_array_test.cc"],
    deps = [
        ":binary_search",
        ":suffix_array",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "rational_reconstruction",
    srcs = ["rational_reconstruction.h"],
    deps = [":modint"],
)

cc_test(
    name = "rational_reconstruction_test",
    srcs = ["rational_reconstruction_test.cc"],
    deps = [
        ":rational_reconstruction",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "type_traits",
    srcs = ["type_traits.h"],
)

cc_test(
    name = "type_traits_test",
    srcs = ["type_traits_test.cc"],
    deps = [
        ":type_traits",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "debug",
    srcs = ["debug.h"],
    deps = [":type_traits"],
)

cc_test(
    name = "debug_test",
    srcs = ["debug_test.cc"],
    deps = [
        ":debug",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "fix",
    srcs = ["fix.h"],
)

cc_test(
    name = "fix_test",
    srcs = ["fix_test.cc"],
    deps = [
        ":fix",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "dfs_order",
    srcs = ["dfs_order.h"],
    deps = [":graph"],
)

cc_test(
    name = "dfs_order_test",
    srcs = ["dfs_order_test.cc"],
    deps = [
        ":dfs_order",
        "@com_google_googletest//:gtest_main",
    ],
)
