load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_proto_library(
    name = "map_cc_proto",
    deps = [
        "@baidu_apollo//modules/map/proto:map_proto",
    ],
)

cc_library(
    name = "test1",
    srcs = [
        "test.cpp",
    ],
    deps = [
        # "@baidu_apollo//modules/map/proto:map_cc_proto",
        ":map_cc_proto",
        # "@baidu_apollo//modules/routing:apollo_routing",
    ],
)