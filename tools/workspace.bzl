load("//third_party/apollo:workspace.bzl", apollo="repo")
load("//third_party/boost:workspace.bzl", boost="repo")
load("//third_party/proj:workspace.bzl", proj="repo")

def include_third_repos():
    apollo()
    boost()
    # proj()