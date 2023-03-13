load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_deps():

    # gtest & gmock
    http_archive(
        name = "gtest",
        url = "https://github.com/google/googletest/archive/release-1.10.0.zip",
        sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
        build_file = "@//:gtest.BUILD",
    )

    # eigen3
    http_archive(
        name = "eigen",
        build_file = "//deps:eigen.BUILD",
        sha256 = "8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72",
        strip_prefix = "eigen-3.4.0",
        urls = [
            "https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz",
        ],
    )


