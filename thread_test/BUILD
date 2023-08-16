load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    linkopts = ["-pthread"],
)

#cc_binary (
#    name = "execution_policy",
#    srcs = ["execution_policy.cc"],
#    linkopts = ["-ltbb"],
#)

cc_binary (
    name = "shared_mutex",
    srcs = ["shared_mutex.cc"],
    linkopts = ["-pthread"],
)
