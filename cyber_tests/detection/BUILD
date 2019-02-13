load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "publisher",
    srcs = ["publisher.cc"],
    deps = [
        "//cyber",
        "//cyber_tests/detection/proto:detection_cc_proto",
    ],
)
