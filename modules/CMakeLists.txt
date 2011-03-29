project(modules C)

find_package(LibSSH 0.4.0)

set(PLUGIN_VERSION_INSTALL_DIR "${PLUGIN_INSTALL_DIR}-${LIBRARY_SOVERSION}")

set(MODULES_PUBLIC_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
  CACHE INTERNAL "modules include directories"
)

set(MODULES_PRIVATE_INCLUDE_DIRS
  ${CSTDLIB_PUBLIC_INCLUDE_DIRS}
  ${CSYNC_PUBLIC_INCLUDE_DIRS}
  ${LIBSMBCLIENT_INCLUDE_DIRS}
)

set(SFTP_PLUGIN
  csync_sftp
)

include_directories(
  ${MODULES_PUBLIC_INCLUDE_DIRS}
  ${MODULES_PRIVATE_INCLUDE_DIRS}
)

install(
  TARGETS
    ${SMB_PLUGIN}
  DESTINATION
    ${PLUGIN_VERSION_INSTALL_DIR}
)

macro_add_plugin(csync_dummy csync_dummy.c)
target_link_libraries(csync_dummy csync)

if (LIBSSH_FOUND)
macro_add_plugin(${SFTP_PLUGIN} csync_sftp.c)
target_link_libraries(${SFTP_PLUGIN} ${CSYNC_LIBRARY} ${CSTDLIB_LIBRARY} ${LIBSSH_LIBRARIES})

install(
  TARGETS
    ${SFTP_PLUGIN}
  DESTINATION
    ${PLUGIN_VERSION_INSTALL_DIR}
)
endif (LIBSSH_FOUND)


# create test file as bad plugin for the vio testcase
file(WRITE
  ${CMAKE_CURRENT_BINARY_DIR}/csync_bad.so
  "bad plugin"
)

