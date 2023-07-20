cmake_minimum_required(VERSION 3.0)
project(video)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5MultimediaWidgets CONFIG REQUIRED)

set(video_SRC
  src/main.cpp
  src/video.cpp
  src/indexedfilemodel.cpp
  src/filenamedelegate.cpp
  src/player.cpp
)

# Tell CMake to create the helloworld executable
add_executable(video ${video_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(video Qt5::Widgets Qt5::MultimediaWidgets)

# Install the executable
install(TARGETS video DESTINATION bin)
