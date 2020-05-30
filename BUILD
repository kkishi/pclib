package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gcd",
    srcs = ["gcd.h"],
)

cc_test(
    name = "gcd_test",
    srcs = [
        "gcd_test.cc",
    ],
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
    srcs = [
        "rational_test.cc",
    ],
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
    srcs = [
        "modint_test.cc",
    ],
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
    srcs = [
        "compress_test.cc",
    ],
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
    srcs = [
        "macros_test.cc",
    ],
    deps = [
        ":macros",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "bound_grid",
    srcs = ["bound_grid.h"],
    deps = [
        ":macros",
    ],
)

cc_library(
    name = "factorize",
    srcs = ["factorize.h"],
)

cc_test(
    name = "factorize_test",
    srcs = [
        "factorize_test.cc",
    ],
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
    srcs = [
        "prime_test.cc",
    ],
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
    srcs = [
        "segment_tree_test.cc",
    ],
    deps = [
        ":segment_tree",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "dijkstra",
    srcs = ["dijkstra.h"],
)

cc_test(
    name = "dijkstra_test",
    srcs = [
        "dijkstra_test.cc",
    ],
    deps = [
        ":dijkstra",
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
    srcs = [
        "disjointset_test.cc",
    ],
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
    srcs = [
        "geometry_test.cc",
    ],
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
    srcs = [
        "rerooting_test.cc",
    ],
    deps = [
        ":modint",
        ":rerooting",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
