cmake_minimum_required(VERSION 3.10)
project(Lab5_Advanced_OOP)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create library with all the class implementations
add_library(OOPClasses STATIC
    src/Point.cpp
    src/Book.cpp
    src/Polynomial.cpp
    src/Date.cpp
    src/Complex.cpp
    src/Fraction.cpp
)

# Main executables
add_executable(point_demo src/main_point.cpp)
target_link_libraries(point_demo OOPClasses)

add_executable(book_demo src/main_book.cpp)
target_link_libraries(book_demo OOPClasses)

add_executable(polynomial_demo src/main_polynomial.cpp)
target_link_libraries(polynomial_demo OOPClasses)

add_executable(date_demo src/main_date.cpp)
target_link_libraries(date_demo OOPClasses)

add_executable(fraction_complex_demo src/main_fraction_complex.cpp)
target_link_libraries(fraction_complex_demo OOPClasses)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(OOPClasses PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(point_demo PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(book_demo PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(polynomial_demo PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(date_demo PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(fraction_complex_demo PRIVATE -Wall -Wextra -pedantic)
endif()

# Install rules (optional)
install(TARGETS point_demo book_demo polynomial_demo date_demo fraction_complex_demo
        RUNTIME DESTINATION bin)

# Custom target to build all demos
add_custom_target(all_demos
    DEPENDS point_demo book_demo polynomial_demo date_demo fraction_complex_demo
)