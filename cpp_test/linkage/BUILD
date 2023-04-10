load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "foo",
    hdrs = ["declaration.h"],
    srcs = ["definition.cc"],
    # srcs = ["primitive_default_construction.cc"],
)

cc_binary(
    name = "linkage_test",
    srcs = ["main.cc"],
    deps = [":foo"],
)
