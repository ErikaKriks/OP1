cmake_minimum_required(VERSION 3.10)

project(project VERSION 1.0)

# Add your source files
set(SOURCES
    main.cpp
    functions.cpp
)

# Add your header file
set(HEADERS
    functions.h
)

# Create an executable
add_executable(myprogram ${SOURCES} ${HEADERS})

# Set C++ standard
set_target_properties(myprogram PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

