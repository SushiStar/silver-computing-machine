load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "eigen_spline",
    srcs = ["eigen_spline.cc"],
    deps = [
        "@eigen",
    ],
)
