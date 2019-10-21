cmake_minimum_required(VERSION 3.0)


if ($ENV{TRAVIS_BUILD_NUMBER})
    project(ILS_Task VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(ILS_Task VERSION 1.0.0)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


cmake_policy(PUSH)

cmake_policy(SET CMP0057 NEW)
find_package(Doxygen)

if (DOXYGEN_FOUND)

    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_GENERATE_RTF YES)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/doc")
    set(DOXYGEN_OUTPUT_LANGUAGE "Russian")

    doxygen_add_docs(doc "${PROJECT_SOURCE_DIR}")

endif()

cmake_policy(POP)



add_custom_target("sundries"
    SOURCES
    "README.md"
    "CHANGELOG.md"
    ".travis.yml"
    )

add_executable(task1 "cars.cpp" "task1.cpp" "test1.cpp")
add_executable(task2 "cars.cpp" "task2.cpp" "test2.cpp")
add_executable(task3            "task3.hpp" "test3.cpp")
add_executable(task4 "cars.cpp"             "test4.cpp")
add_executable(task5 "cars.cpp" "task5.hpp" "test5.cpp")


enable_testing()

add_test(test_task1 task1)
add_test(test_task2 task2)
add_test(test_task3 task3)
add_test(test_task4 task4)
add_test(test_task5 task5)


install(TARGETS
    "task1"
    "task2"
    "task3"
    "task4"
    "task5"
    RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dinsul2.0@gmail.com)

include (CPack)
