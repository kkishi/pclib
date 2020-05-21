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
