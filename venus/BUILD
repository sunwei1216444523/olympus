load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_test(
    name = "test",
    srcs = [
        "geotools.h",
        "geotools.cpp",
        "test.cpp",
    ],
    deps = [
        "@proj//:proj",
    ],
)