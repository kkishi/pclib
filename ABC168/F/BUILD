cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//:compress",
    ],
)

filegroup(
    name = "testcases",
    srcs = glob([
        "in/*",
        "out/*",
    ]),
)

sh_test(
    name = "main_test",
    srcs = ["main_test.sh"],
    data = [
        ":main",
        ":testcases",
    ],
)
