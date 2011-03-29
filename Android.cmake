# this one is important
SET(CMAKE_SYSTEM_NAME Android)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER   agcc3)
SET(CMAKE_CXX_COMPILER ag++3)

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH /home/jer/cm7/out/target/product/vision/system/lib /home/jer/cm7/external/sqlite/dist /mnt/jer/cm7/manual/argp-standalone-1.3 /home/jer/cm7/manual/libssh/include)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
