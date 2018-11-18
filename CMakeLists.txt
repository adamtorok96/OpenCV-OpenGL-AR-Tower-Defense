cmake_minimum_required(VERSION 3.10)
project(OpenCV_OpenGL_AR_TowerDefense)

set(CMAKE_CXX_STANDARD 11)

include(/usr/local/lib/cmake/opencv4/OpenCVConfig.cmake)

set(OpenGL_GL_PREFERENCE LEGACY)

include(FindOpenGL)
message(STATUS "OPENGL_FOUND = ${OPENGL_FOUND}")
message(STATUS "OPENGL_GLU_FOUND = ${OPENGL_GLU_FOUND}")
message(STATUS "OPENGL_INCLUDES= ${OPENGL_LIBRARIES}")

include(FindGLEW)
message(STATUS "Glew_FOUND = ${GLEW_FOUND}")

include(FindGLUT)
message(STATUS "GLUT_FOUND = ${GLUT_FOUND}")

find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCE_FILES
        main.cpp
        TowerDefense.cpp TowerDefense.h
        Detector.cpp Detector.h
        FrameHandler.cpp FrameHandler.h
        GameObject.cpp GameObject.h
        GameModelLoader.cpp GameModelLoader.h
        ArucoObjectMapper.cpp ArucoObjectMapper.h
        Tower.cpp Tower.h
        Minion.cpp Minion.h
        GameModel.cpp GameModel.h
        Path.cpp Path.h
        StartPath.cpp StartPath.h
)

set(LIB_FILES
        ${OpenCV_LIBS}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${GLUT_LIBRARIES}
        GL
        tinyobjloader
        nlohmann_json::nlohmann_json
)

add_executable(OpenCV_OpenGL_AR_TowerDefense ${SOURCE_FILES})

target_link_libraries(OpenCV_OpenGL_AR_TowerDefense ${LIB_FILES})