
cmake_minimum_required(VERSION 3.16)

project(MediaPro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.2.0/gcc_64/lib/cmake/; ${CMAKE_PREFIX_PATH}")
set(OPENSSL_ROOT_DIR "~/Qt/Tools/OpenSSL/src")
set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/crypto")
# set(XKB_LIBRARY "/usr/share/X11/xkb")

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_PREFIX_PATH)

find_package(Qt6 REQUIRED COMPONENTS
  Core
  Multimedia
  Widgets
)

add_executable(MediaPro
  src/main.cpp
  src/DirectoryManager.cpp
  # src/LibraryManager.cpp
  # src/Queue.cpp
  # src/Tag.cpp
  # src/Song.cpp
  # src/DomainRule.cpp
  # src/OrderRule.cpp
  # src/DomainCondition.cpp
)

target_link_libraries(MediaPro PRIVATE 
  Qt6::Core
  Qt6::Multimedia
  Qt6::Widgets
)

target_include_directories(MediaPro PRIVATE
  ./include
)