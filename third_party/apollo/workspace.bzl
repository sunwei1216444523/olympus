"""import apollo"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def repo():
    http_archive(
        name = "baidu_apollo",
        sha256 = "33c5ff3f1978cccfea1afd372a47fd0ec57df122db8dd37e6013c06341a79131",
        strip_prefix = "apollo-sw7.0.2",
        urls = ["https://github.com/sunwei1216444523/apollo/archive/refs/tags/sw7.0.2.tar.gz",],
    )
