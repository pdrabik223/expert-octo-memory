cmake_minimum_required(VERSION 3.19)
project(expert_octo)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/DEBUG)
endif ()

set(CMAKE_CXX_STANDARD 14)

set(plane_dir
        plane/plane.h
        plane/plane.cpp
        plane/cell_type.h
        utility/coord.h
        utility/coord.cpp
        )

set(sfml_window_dir


        sfml_window/window_plane.h
        sfml_window/window_plane.cpp
        sfml_window/color_scheme.h
        sfml_window/color_scheme.cpp
        )


set(maze_painter_dir
        maze_painter/maze_painter.h maze_painter/maze_painter.cpp)


add_subdirectory(SFML)


add_executable(number_painter number_painter.cpp
        ${plane_dir}
        ${sfml_window_dir}
        ${maze_painter_dir})

set(executables number_painter)

foreach (executable IN LISTS executables)
    target_include_directories(${executable}
            PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include

            )
    target_link_directories(${executable}
            PUBLIC ${PROJECT_SOURCE_DIR}/sfml/src

            )
    target_link_libraries(${executable}
            sfml-graphics
            sfml-system
            sfml-window
            )
endforeach ()

set(debug_files_to_copy
        ${PROJECT_SOURCE_DIR}/cmake-build-debug/sfml/lib/sfml-graphics-d-2.dll
        ${PROJECT_SOURCE_DIR}/cmake-build-debug/sfml/lib/sfml-window-d-2.dll
        ${PROJECT_SOURCE_DIR}/cmake-build-debug/sfml/lib/sfml-system-d-2.dll
        )

set(release_files_to_copy
        ${PROJECT_SOURCE_DIR}/cmake-build-release/sfml/lib/sfml-graphics-2.dll
        ${PROJECT_SOURCE_DIR}/cmake-build-release/sfml/lib/sfml-window-2.dll
        ${PROJECT_SOURCE_DIR}/cmake-build-release/sfml/lib/sfml-system-2.dll
        )

#foreach (file IN LISTS debug_files_to_copy)
#    add_custom_command(
#            TARGET ${PROJECT_NAME} POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy
#            ${file}
#            ${PROJECT_SOURCE_DIR}/cmake-build-debug/
#    )
#endforeach ()
#
#foreach (file IN LISTS release_files_to_copy)
#    add_custom_command(
#            TARGET ${PROJECT_NAME} POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy
#            ${file}
#            ${PROJECT_SOURCE_DIR}/cmake-build-release/
#    )
#endforeach ()
