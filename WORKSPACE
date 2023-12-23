load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

"""首先解决Apollo需要依赖的库"""
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


http_archive(
    name = "com_google_protobuf",
    sha256 = "6dd0f6b20094910fbb7f1f7908688df01af2d4f6c5c21331b9f636048674aebf",
    strip_prefix = "protobuf-3.14.0",
    urls = ["https://github.com/protocolbuffers/protobuf/releases/download/v3.14.0/protobuf-all-3.14.0.tar.gz"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "rules_proto",
    sha256 = "dc3fb206a2cb3441b485eb1e423165b231235a1ea9b031b4433cf7bc1fa460dd",
    strip_prefix = "rules_proto-5.3.0-21.7",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/5.3.0-21.7.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()
"""然后调用Apollo自己的deps"""
load("//tools:workspace.bzl", "include_third_repos")
include_third_repos()
load("@baidu_apollo//tools:workspace.bzl", "basic_repositories")
basic_repositories()
"""最后才能使用apollo"""

# http_archive(
#     name = "rules_cc",
#     urls = ["https://github.com/bazelbuild/rules_cc/archive/master.zip"],
# )

# load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies", "rules_cc_toolchains")

# rules_cc_dependencies()

# rules_cc_toolchains()

# grpc

# http_archive(
#     name = "zlib",
#     build_file = "@com_google_protobuf//:third_party/zlib.BUILD",
#     sha256 = "629380c90a77b964d896ed37163f5c3a34f6e6d897311f1df2a7016355c45eff",
#     strip_prefix = "zlib-1.2.11",
#     urls = ["https://github.com/madler/zlib/archive/v1.2.11.tar.gz"],
# )


# load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

# grpc_extra_deps()
