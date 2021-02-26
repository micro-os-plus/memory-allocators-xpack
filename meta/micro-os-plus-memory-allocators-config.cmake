#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.18/
# https://cmake.org/cmake/help/v3.18/manual/cmake-packages.7.html#package-configuration-file

if(micro-os-plus-memory-allocators-included)
  return()
endif()

set(micro-os-plus-memory-allocators-included TRUE)

message(STATUS "Including micro-os-plus-memory-allocators...")

# -----------------------------------------------------------------------------
# Dependencies.

find_package(micro-os-plus-diag-trace REQUIRED)

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------

if(NOT TARGET micro-os-plus-memory-allocators-interface)

  add_library(micro-os-plus-memory-allocators-interface INTERFACE EXCLUDE_FROM_ALL)

  # ---------------------------------------------------------------------------

  target_sources(
    micro-os-plus-memory-allocators-interface

    INTERFACE
      ${xpack_current_folder}/src/block-pool.cpp
      ${xpack_current_folder}/src/first-fit-top.cpp
      ${xpack_current_folder}/src/lifo.cpp
  )

  target_include_directories(
    micro-os-plus-memory-allocators-interface

    INTERFACE
      ${xpack_current_folder}/include
  )

  target_link_libraries(
    micro-os-plus-memory-allocators-interface

    INTERFACE
      micro-os-plus::diag-trace-static
  )

  # ---------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::memory-allocators ALIAS micro-os-plus-memory-allocators-interface)
  message(STATUS "micro-os-plus::memory-allocators")

endif()

# -----------------------------------------------------------------------------
