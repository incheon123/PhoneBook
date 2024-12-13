# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PhoneBook_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PhoneBook_autogen.dir\\ParseCache.txt"
  "PhoneBook_autogen"
  )
endif()
