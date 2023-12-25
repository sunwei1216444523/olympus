load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "test1",
    srcs = [
        "paser_for_baidu_hdmap.cpp",
    ],
    deps = [
        "@baidu_apollo//modules/map/proto:map_cc_proto",
        "@boost//:boost",
        # "@baidu_apollo//modules/routing:apollo_routing",
    ],
    data = [
        "@baidu_apollo//modules/map/hdmap/test-data:base_map_bin",
    ],
)