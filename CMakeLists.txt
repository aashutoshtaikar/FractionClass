cmake_minimum_required(VERSION 2.8)

include_directories(include)

project(FractionClass)

#find_package (Threads)

file(GLOB src_files
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${src_files} )

#target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
