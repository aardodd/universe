cmake_minimum_required(VERSION 3.18)

add_library(core
    "source/core/container/array.cpp"
    "source/core/framework/observer.cpp"
    "source/core/framework/visitor.cpp"
    "source/core/image/targa.cpp"
    "source/core/math/abs.cpp"
    "source/core/math/max.cpp"
    "source/core/math/min.cpp"
    "source/core/math/sqrt.cpp"
    "source/core/math/ray.cpp"
    "source/core/math/vector2.cpp"
    "source/core/math/vector3.cpp"
    "source/core/standard/assert.cpp"
    "source/core/standard/type.cpp"
    "source/core/trait/condition.cpp"
    "source/core/trait/is_bool.cpp"
    "source/core/trait/is_rational.cpp"
    "source/core/trait/is_same.cpp"
    "source/core/trait/is_signed.cpp"
    "source/core/trait/is_unsigned.cpp"
    "source/core/trait/make_signed.cpp"
    "source/core/trait/make_unsigned.cpp"
    "source/core/trait/remove_reference.cpp"
    "source/core/trait/type_identity.cpp"
    "source/core/utility/binary.cpp"
    "source/core/utility/exchange.cpp"
    "source/core/utility/forward.cpp"
    "source/core/utility/memory_copy.cpp"
    "source/core/utility/move.hpp"
)

target_include_directories(core
    PUBLIC "source"
)

target_compile_features(core PUBLIC cxx_std_20)