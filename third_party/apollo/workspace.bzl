"""import apollo"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def repo():
    http_archive(
        name = "baidu_apollo",
        sha256 = "a3cc5478acd649b4adfac0760472d6046f589a3506f6d7b9c634d3bb4462f430",
        strip_prefix = "apollo-6.0.0",
        urls = ["https://github.com/ApolloAuto/apollo/archive/refs/tags/v6.0.0.tar.gz",],
    )
