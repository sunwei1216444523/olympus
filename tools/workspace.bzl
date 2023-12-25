load("//third_party/apollo:workspace.bzl", apollo="repo")
load("//third_party/boost:workspace.bzl", boost="repo")

def include_third_repos():
    apollo()
    boost()