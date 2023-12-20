load("//third_party/apollo:workspace.bzl", apollo="repo")
load("//third_party/grpc:workspace.bzl", grpc = "repo")

def include_third_repos():
    apollo()

    # glog()
