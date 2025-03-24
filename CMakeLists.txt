cmake_minimum_required(VERSION 3.10)

# Project name
project(IntegralLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and header files
set(SOURCES
    integral/integral.cpp
)

set(HEADERS
    integral/include/integral.h
)

Include(FetchContent)

FetchContent_Declare(
  etl
  GIT_REPOSITORY https://github.com/ETLCPP/etl
  GIT_TAG        20.40.0
)

FetchContent_MakeAvailable(etl)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/integral/include
)

# Link libraries (if needed)
target_link_libraries(${PROJECT_NAME} PRIVATE etl::etl)

# Set compiler options for different platforms
if(MSVC)  # If using Visual Studio on Windows
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4  # Warning level 4 for MSVC
        /O2  # Optimization level 2 for MSVC
    )
else()  # If not on Windows (Linux)
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -Wpedantic # Enable warnings for other compilers
        -O2 # Enable compiler optimizations
    )
endif()

# Set library output directories for different configurations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# Install the library and headers
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES ${HEADERS} DESTINATION include)

# CPack configuration
include(InstallRequiredSystemLibraries)

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "panyeczky@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "Assignment for #FFA500")
set(CPACK_PACKAGE_VENDOR "Mate Panyeczky")

# Include CPack configuration
include(CPack)