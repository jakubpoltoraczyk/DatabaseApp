project(DatabaseApp)

find_package(Qt5 5.11.3 COMPONENTS Quick Widgets Core REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
  main.cpp
  srcback/controller/basiccontroller.cpp
  srcback/databaseclient/mockdatabaseclient.cpp
  srcback/databaseclient/sqldatabaseclient.cpp
  srcgui/clientserviceview/clientserviceviewcontroller.cpp
  srcgui/windowmanager/windowmanager.cpp

  srcback/controller/basiccontroller.h
  srcback/databaseclient/databaseclient.h
  srcback/databaseclient/mockdatabaseclient.h
  srcback/databaseclient/sqldatabaseclient.h
  srcgui/clientserviceview/clientserviceviewcontroller.h
  srcgui/windowmanager/windowmanager.h

  qml.qrc
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${srcgui_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow")

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)
target_link_libraries(${PROJECT_NAME}
  Qt5::Quick
  Qt5::Widgets
  Qt5::Core
)
