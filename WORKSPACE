workspace(name = "silver_computing_machine")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


######################################## TOOL ###########################################

# To be compatible with cmake projects
http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/refs/tags/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://bazelbuild.github.io/rules_foreign_cc/0.9.0/flatten.html#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()


######################################## DEPS ###########################################

# gtest & gmock
http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.10.0.zip",
    sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
    build_file = "@//:gtest.BUILD",
)


# eigen
_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
"""
http_archive(
  name="eigen",
  build_file_content = _ALL_CONTENT,
  strip_prefix = "eigen-3.4",
  urls=["https://gitlab.com/libeigen/eigen/-/archive/3.4/eigen-3.4.tar.bz2"],
  sha256 = "a6f7aaa7b19c289dfeb33281e1954f19bf2ba1c6cae2c182354d820f535abef8",
)

#
