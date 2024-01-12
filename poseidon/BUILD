load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_test(
    name = "test_geo_point",
    srcs = [
        "envelop.h",
        "geo_point.h",
        "point_pair.h",
        "test.cpp",
    ],
)

cc_binary(
    name = "poseidon",
    srcs = [
        "envelop.h",
        "geo_point.h",
        "graphconstants.h",
        "graphid.h",
        "point_pair.h",
        "tilehierachy.h",
        "tilehierachy.cpp",
        "tiles.cpp",
        "tiles.h",
    ],
)
