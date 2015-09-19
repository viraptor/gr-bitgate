INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_BITGATE bitgate)

FIND_PATH(
    BITGATE_INCLUDE_DIRS
    NAMES bitgate/api.h
    HINTS $ENV{BITGATE_DIR}/include
        ${PC_BITGATE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BITGATE_LIBRARIES
    NAMES gnuradio-bitgate
    HINTS $ENV{BITGATE_DIR}/lib
        ${PC_BITGATE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BITGATE DEFAULT_MSG BITGATE_LIBRARIES BITGATE_INCLUDE_DIRS)
MARK_AS_ADVANCED(BITGATE_LIBRARIES BITGATE_INCLUDE_DIRS)

