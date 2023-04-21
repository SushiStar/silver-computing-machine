load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "eigen_matrix",
    srcs = ["eigen_matrix.cc"],
    deps = [
        "@eigen",
    ],
)

cc_binary(
    name = "eigen_std_conversion",
    srcs = ["eigen_std_vector_conversion.cc"],
    deps = [
        "@eigen",
    ],
)

cc_binary(
    name = "eigen_vector_conversion",
    srcs = ["eigen_vector_conversion.cc"],
    deps = [
        "@eigen",
    ],
)
