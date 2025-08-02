cmake_minimum_required(VERSION 3.16)
project(MoneRig VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -Wall -Wextra")


include(FetchContent)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)


find_package(CURL REQUIRED)


find_package(OpenSSL REQUIRED)


FetchContent_Declare(
    rapidjson
    GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(rapidjson)


include_directories(
    ${Boost_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    ${rapidjson_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)


file(GLOB_RECURSE CORE_SRC    src/core/*.cpp)
file(GLOB_RECURSE NETWORK_SRC src/network/*.cpp)
file(GLOB_RECURSE STRATUM_SRC src/stratum/*.cpp)
file(GLOB_RECURSE HTTP_SRC    src/http/*.cpp)
file(GLOB_RECURSE UTILS_SRC   src/utils/*.cpp)
file(GLOB_RECURSE CONFIG_SRC  src/config/*.cpp)

set(SOURCES
    ${CORE_SRC}
    ${NETWORK_SRC}
    ${STRATUM_SRC}
    ${HTTP_SRC}
    ${UTILS_SRC}
    ${CONFIG_SRC}
    src/main.cpp
)


add_executable(monerig ${SOURCES})


target_link_libraries(monerig
    ${Boost_LIBRARIES}
    ${CURL_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    target_compile_options(monerig PRIVATE -mavx2 -msse4.2 -fopenmp)
endif()


enable_testing()
add_subdirectory(test)


execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-DGIT_COMMIT="${GIT_COMMIT}")

install(TARGETS monerig DESTINATION bin)
cmake_minimum_required(VERSION 3.10)
project(MyMiner)

set(CMAKE_CXX_STANDARD 17)

find_package(CUDA REQUIRED) # или OpenCL, если используешь другое API

include_directories(src)
add_executable(myminer src/main.cpp src/miner.cpp)
target_link_libraries(myminer ${CUDA_LIBRARIES})
cmake_minimum_required(VERSION 3.16)
project(MoneRig VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -Wall -Wextra")


include(FetchContent)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)


find_package(CURL REQUIRED)


find_package(OpenSSL REQUIRED)


FetchContent_Declare(
    rapidjson
    GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(rapidjson)


include_directories(
    ${Boost_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    ${rapidjson_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)


file(GLOB_RECURSE CORE_SRC    src/core/*.cpp)
file(GLOB_RECURSE NETWORK_SRC src/network/*.cpp)
file(GLOB_RECURSE STRATUM_SRC src/stratum/*.cpp)
file(GLOB_RECURSE HTTP_SRC    src/http/*.cpp)
file(GLOB_RECURSE UTILS_SRC   src/utils/*.cpp)
file(GLOB_RECURSE CONFIG_SRC  src/config/*.cpp)

set(SOURCES
    ${CORE_SRC}
    ${NETWORK_SRC}
    ${STRATUM_SRC}
    ${HTTP_SRC}
    ${UTILS_SRC}
    ${CONFIG_SRC}
    src/main.cpp
)


add_executable(monerig ${SOURCES})


target_link_libraries(monerig
    ${Boost_LIBRARIES}
    ${CURL_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    target_compile_options(monerig PRIVATE -mavx2 -msse4.2 -fopenmp)
endif()


enable_testing()
add_subdirectory(test)


execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-DGIT_COMMIT="${GIT_COMMIT}")

install(TARGETS monerig DESTINATION bin)
cmake_minimum_required(VERSION 3.10)
project(MyMiner)

set(CMAKE_CXX_STANDARD 17)

find_package(CUDA REQUIRED) # или OpenCL, если используешь другое API

include_directories(src)
add_executable(myminer src/main.cpp src/miner.cpp)
target_link_libraries(myminer ${CUDA_LIBRARIES})



