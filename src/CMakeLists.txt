add_library(
    bepuphysics2
    STATIC
    r128/r128.cpp
    utilities/Fix64.cpp
    utilities/Vector3.cpp
)

target_compile_definitions(bepuphysics2 PUBLIC bepuphysics2)
