cmake_minimum_required(VERSION 3.15)
project(xdt_lib VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(XDT_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cpuid.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/sse.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/xdt.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/vendor.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/avx.hh
)

set(XDT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cpuid.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/avx.cc
)

add_library(xdt ${XDT_SOURCES} ${XDT_HEADERS})

target_include_directories(xdt
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(xdt PUBLIC cxx_std_17)
set_target_properties(xdt PROPERTIES CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

target_compile_options(xdt PRIVATE -Wall -Wextra -Wshadow)

add_library(xdt::xdt ALIAS xdt)

include(GNUInstallDirs)
install(TARGETS xdt
    EXPORT xdtTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${XDT_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT xdtTargets
    FILE xdtTargets.cmake
    NAMESPACE xdt::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/xdt
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/xdtConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/xdtConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/xdtConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/xdt
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xdtConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/xdtConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/xdt
)
