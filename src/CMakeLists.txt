# Copyright (c) 2014-2015, 2017 Chan Beom Park <cbpark@gmail.com>
#
# This file is part of mt2-cwrapper, which is released under the GNU General
# Public License. See file LICENSE in the top directory of this project or
# go to <http://www.gnu.org/licenses/> for full license details.

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(MT2Calculator_SRC
  symm_mt2_minuit2.cc symm_mt2_minuit2_c.cc lester_mt2_bisect_c.cc mt2_bisect.cpp
  mt2_bisect_c.cc)
ADD_LIBRARY(MT2Calculator SHARED ${MT2Calculator_SRC})
TARGET_LINK_LIBRARIES(MT2Calculator ${ROOT_LIBRARIES})
SET(LIBRARY_TARGET ${LIBRARY_TARGET} MT2Calculator)

IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
  SET(test_symm_mt2_minuit2_SRC test_symm_mt2_minuit2.c)
  ADD_EXECUTABLE(test_symm_mt2_minuit2 ${test_symm_mt2_minuit2_SRC})
  TARGET_LINK_LIBRARIES(test_symm_mt2_minuit2 MT2Calculator)
  SET(EXECUTABLE_TARGET ${EXECUTABLE_TARGET} test_symm_mt2_minuit2)
  SET_TARGET_PROPERTIES(test_symm_mt2_minuit2 PROPERTIES INSTALL_RPATH "@loader_path/../lib")

  SET(test_lester_mt2_bisect_SRC test_lester_mt2_bisect.c)
  ADD_EXECUTABLE(test_lester_mt2_bisect ${test_lester_mt2_bisect_SRC})
  TARGET_LINK_LIBRARIES(test_lester_mt2_bisect MT2Calculator)
  SET(EXECUTABLE_TARGET ${EXECUTABLE_TARGET} test_lester_mt2_bisect)
  SET_TARGET_PROPERTIES(test_lester_mt2_bisect PROPERTIES INSTALL_RPATH "@loader_path/../lib")
ENDIF(CMAKE_BUILD_TYPE STREQUAL "Debug")

INSTALL(TARGETS ${EXECUTABLE_TARGET} ${LIBRARY_TARGET}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

FILE(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
INSTALL(FILES ${HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME})
