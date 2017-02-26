project (convex)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 2.4.5)

set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true )

if( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )  
endif()

# Find CGAL and CGAL Qt5
find_package(CGAL COMPONENTS Qt5)

# Find Qt5 itself
find_package(Qt5 QUIET COMPONENTS Xml Script OpenGL Gui Svg)

find_package(GLUT)
find_package(OpenGL)

set( HDRS glviewer.h scene.h window.h  include/cdt.h)

set( SRCS glviewer.cpp main.cpp window.cpp)


set(SRC_MOC window.h glviewer.h)

if(WIN32)
	add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4503 /nologo" )
endif(WIN32)



if( CGAL_FOUND AND Qt5_FOUND AND OPENGL_FOUND )
	include_directories(BEFORE . ./build)
    include(${CGAL_USE_FILE})
   # include(${QT_USE_FILE})

    # UI files (Qt Designer files)
    qt5_wrap_ui( DT_UI_FILES convex.ui)

    # qrc files (resources files, that contain icons, at least)
    qt5_add_resources( DT_RESOURCE_FILES convex.qrc )
    # The executable itself.
    add_executable( convex ${SRCS} ${DT_UI_FILES} ${DT_RESOURCE_FILES} )
    qt5_use_modules(convex Gui OpenGL Xml Script Svg )
    # Link with Qt libraries
    target_link_libraries( convex ${QT_LIBRARIES} )
    
    # Link with Glut and OpenGL
    target_link_libraries( convex ${OPENGL_LIBRARY} ${GLUT_LIBRARY}  )

    # Link with CGAL
    target_link_libraries( convex ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})

else()
  message(STATUS "NOTICE: This program requires CGAL and Qt5, and will not be compiled.")

endif()
