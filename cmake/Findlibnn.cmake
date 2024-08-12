find_path(LIBNN_INCLUDE_DIR NAMES ex_nn.hpp
PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/libnn
PATH_SUFFIXES include
CMAKE_FIND_ROOT_PATH_BOTH
)

find_library(LIBNN_LIBRARY
NAMES libnn.so
PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/libnn
REQUIRED
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
${CMAKE_FIND_PACKAGE_NAME}
REQUIRED_VARS LIBNN_LIBRARY LIBNN_INCLUDE_DIR
FAIL_MESSAGE "Error: Example NN Library not found in sysroot!!"
)

message(STATUS "Found libnn: ${LIBNN_LIBRARY}")