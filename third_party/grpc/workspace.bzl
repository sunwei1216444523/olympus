"""import grpc here"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def repo():
    http_archive(
        name = "com_github_grpc_grpc",
        sha256 = "419dba362eaf8f1d36849ceee17c3e2ff8ff12ac666b42d3ff02a164ebe090e9",
        strip_prefix = "grpc-1.30.0",
        urls = [
            "https://apollo-system.cdn.bcebos.com/archive/6.0/v1.30.0.tar.gz",
            "https://github.com/grpc/grpc/archive/v1.30.0.tar.gz",
        ],
    )
    load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
    grpc_deps()
