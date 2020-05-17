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
    deps = [
        ":gcd",
    ],
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
