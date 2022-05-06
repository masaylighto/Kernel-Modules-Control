project(Kmc)
cmake_minimum_required(VERSION 3.18)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
set( SOURCE_FILES "Src/Main.c" "Src/MainWindow.c" "Src/HelperFunction.c" "Src/GtkMethod.c")
add_executable(Kmc ${SOURCE_FILES})

# Add other flags to the compiler
target_compile_definitions(Kmc PRIVATE ${GTKMM_CFLAGS_OTHER})

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(Kmc PRIVATE ${GTK_INCLUDE_DIRS})

target_link_libraries(Kmc PRIVATE ${GTK_LIBRARIES})

