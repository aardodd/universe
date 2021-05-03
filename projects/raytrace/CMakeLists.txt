cmake_minimum_required(VERSION 3.18)

add_executable(raytrace
    "source/raytrace/main.cpp"
)

target_include_directories(raytrace
    PUBLIC "source"
)

target_compile_features(raytrace PUBLIC cxx_std_20)