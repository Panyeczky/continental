# IntegralLibrary

This library provides functionality for evaluating and integrating polynomials using the **ETL (Embedded Template Library)**. It includes the ability to evaluate polynomial functions and compute their integrals using the trapezoidal rule.

## Table of Contents
- [Build Method](#build-method)
- [main.cpp](#maincpp)
- [Source Files](#source-files)
- [Integra the library](#integrate-the-library)

## Build Method
To build the project, run chmod +x ./build.sh and the ./build.sh script with either Release or Deabug as an argument.
This will build the project accordingly, ensuring that either the **Release** or **Debug** configuration is used.

The script will automatically configure the build using CMake, compile the source files, and place the resulting binary in the appropriate directories.

## main.cpp
The  file demonstrates a small example of how to use the library to evaluate and integrate polynomials. It provides a minimal setup to show how the integration works.
This small example initializes the  object with 1000 samples and computes the integral of a simple polynomial.

## Source Files

### integral.cpp
The  file implements the methods of the Integral class.
#### 
The constructor ensures that the number of samples is greater than zero. If it is less than or equal to zero, it throws an invalid_argument exception.

### integral.h
The header file defines the Integral class, which encapsulates the functionality for evaluating and integrating polynomials.

#### Constants
- : The maximum degree of the polynomial is set to 11, which means the polynomial can have coefficients for terms from `x^0` to `x^10`.
- : To change the maximum degree of the polynomial, change the MAX_POLY_DEGREE in the header file

## Integrate the library
 - Navigate to the directory where IntegralLibrary is located
 - Build the library
 - Install the library with sudo make install
 - Add the following lines to CMakeLists.txt : 
   # Find the IntegralLibrary
   find_package(IntegralLibrary REQUIRED)
   
   # Link the IntegralLibrary to your project
   target_link_libraries(YourProject PRIVATE IntegralLibrary)
 - Find example usage in main.cpp
