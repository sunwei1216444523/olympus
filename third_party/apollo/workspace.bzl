"""import apollo"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def repo():
    http_archive(
        name = "baidu_apollo",
        sha256 = "99731a4a0cbbcd17335dc62c56cfafce7fedf868cab9d46f6356fa664f9080ab",
        strip_prefix = "apollo-sw7.0.1",
        urls = ["https://github.com/sunwei1216444523/apollo/archive/refs/tags/sw7.0.1.tar.gz",],
    )
