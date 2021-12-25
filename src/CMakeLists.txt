add_library(
    bepuphysics2
    STATIC
    utilities/Fix64.cpp
    utilities/Vector2.cpp
)

target_compile_definitions(bepuphysics2 PUBLIC bepuphysics2)
