#!/bin/bash

#=============================================================================================
#  DESCRIPTION
#    This file helps the developer building the Integral library.
#    Use the "Release" or "Debug" option as "./build.sh Release" in order to build accordingly
#  MAINTENANCE
#    This file provides a clean build. Please note that any local changes in the folders might 
#    be deleted if you run the script. Search for "#Removing prev build folders" to find out
#    the exact files that will be deleted.
#=============================================================================================


# Ensure that the script exits if any command fails
set -e

#Removing prev build folders
clean_up() {
    rm -rf ./build
    rm -rf ./CMakeFiles
    rm -rf ./_deps
    rm -rf ./CMakeCache.txt
    rm -rf ./cmake_install.cmake
    rm -rf ./CPack*
    rm -rf ./libIntegralLibrary.so
    rm -rf ./Makefile
}

clean_up

# Define the build directory
BUILD_DIR=build

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir $BUILD_DIR
fi

# Run cmake to configure the project in the build directory
echo "Configuring the project with CMake..."
cmake -S . -B $BUILD_DIR

# Build the project
echo "Building the project..."
cmake --build $BUILD_DIR

# Defining build mode
if [ "$1" == "Release" ] || [ "$1" == "Debug" ]; then
    cmake -DCMAKE_BUILD_TYPE=$1 .
    cmake --build . --config $1
else
    echo "Invalid build configuration. Parameter can be 'Release' or 'Debug'"
    clean_up
    exit 1
fi


# Optionally, run tests (if you have a test framework set up)
# cmake --build $BUILD_DIR --target test

echo "Build completed successfully!"

# Package the project using CPack
echo "Packaging the project using CPack..."
cd $BUILD_DIR
cpack

echo "Build and packaging completed successfully!"
exit 0
