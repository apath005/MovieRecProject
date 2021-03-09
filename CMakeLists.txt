cmake_minimum_required(VERSION 2.8)


set(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(recommender
        main.cpp
        spreadsheet.cpp
        )

ADD_EXECUTABLE(test
	test.cpp
	)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
