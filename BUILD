load("@io_bazel_rules_go//go:def.bzl", "go_binary")

package(default_visibility = ["//visibility:public"])

go_binary(
    name = "yasnippet",
    srcs = ["yasnippet.go"],
)

cc_library(
    name = "gcd",
    srcs = ["gcd.h"],
)

cc_test(
    name = "gcd_test",
    srcs = ["gcd_test.cc"],
    deps = [
        ":gcd",
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
    name = "factorize",
    srcs = ["factorize.h"],
)

cc_test(
    name = "factorize_test",
    srcs = ["factorize_test.cc"],
    deps = [
        ":factorize",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "prime",
    srcs = ["prime.h"],
)

cc_test(
    name = "prime_test",
    srcs = ["prime_test.cc"],
    deps = [
        ":prime",
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
    name = "disjointset",
    srcs = ["disjointset.h"],
)

cc_test(
    name = "disjointset_test",
    srcs = ["disjointset_test.cc"],
    deps = [
        ":disjointset",
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
    name = "setminmax",
    srcs = [
        "setmax.h",
        "setmin.h",
    ],
)

cc_test(
    name = "setminmax_test",
    srcs = ["setminmax_test.cc"],
    deps = [
        ":setminmax",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "rollinghash",
    srcs = ["rollinghash.h"],
)

cc_test(
    name = "rollinghash_test",
    srcs = ["rollinghash_test.cc"],
    deps = [
        ":rollinghash",
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
