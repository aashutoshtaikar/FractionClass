cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++17)

#headers
include_directories(include)

#project name
project(FractionClass)

#naming all source files as src_files
file(GLOB src_files
    "src/*.cpp"
)

# source files
add_executable(${PROJECT_NAME} ${src_files} )

#path for generated executables
install(TARGETS ${PROJECT_NAME} DESTINATION /)

#to find and link thread libs for the target platform and config
#find_package (Threads)
#target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
