# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tutorial.dir/flags.make

CMakeFiles/Tutorial.dir/src/camera.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tutorial.dir/src/camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/camera.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/camera.cpp

CMakeFiles/Tutorial.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/camera.cpp > CMakeFiles/Tutorial.dir/src/camera.cpp.i

CMakeFiles/Tutorial.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/camera.cpp -o CMakeFiles/Tutorial.dir/src/camera.cpp.s

CMakeFiles/Tutorial.dir/src/engine.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tutorial.dir/src/engine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/engine.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/engine.cpp

CMakeFiles/Tutorial.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/engine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/engine.cpp > CMakeFiles/Tutorial.dir/src/engine.cpp.i

CMakeFiles/Tutorial.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/engine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/engine.cpp -o CMakeFiles/Tutorial.dir/src/engine.cpp.s

CMakeFiles/Tutorial.dir/src/graphics.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tutorial.dir/src/graphics.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/graphics.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/graphics.cpp

CMakeFiles/Tutorial.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/graphics.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/graphics.cpp > CMakeFiles/Tutorial.dir/src/graphics.cpp.i

CMakeFiles/Tutorial.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/graphics.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/graphics.cpp -o CMakeFiles/Tutorial.dir/src/graphics.cpp.s

CMakeFiles/Tutorial.dir/src/main.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tutorial.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/main.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/main.cpp

CMakeFiles/Tutorial.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/main.cpp > CMakeFiles/Tutorial.dir/src/main.cpp.i

CMakeFiles/Tutorial.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/main.cpp -o CMakeFiles/Tutorial.dir/src/main.cpp.s

CMakeFiles/Tutorial.dir/src/object.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tutorial.dir/src/object.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/object.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/object.cpp

CMakeFiles/Tutorial.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/object.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/object.cpp > CMakeFiles/Tutorial.dir/src/object.cpp.i

CMakeFiles/Tutorial.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/object.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/object.cpp -o CMakeFiles/Tutorial.dir/src/object.cpp.s

CMakeFiles/Tutorial.dir/src/shader.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Tutorial.dir/src/shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/shader.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/shader.cpp

CMakeFiles/Tutorial.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/shader.cpp > CMakeFiles/Tutorial.dir/src/shader.cpp.i

CMakeFiles/Tutorial.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/shader.cpp -o CMakeFiles/Tutorial.dir/src/shader.cpp.s

CMakeFiles/Tutorial.dir/src/window.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Tutorial.dir/src/window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/window.cpp.o -c /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/window.cpp

CMakeFiles/Tutorial.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/window.cpp > CMakeFiles/Tutorial.dir/src/window.cpp.i

CMakeFiles/Tutorial.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/src/window.cpp -o CMakeFiles/Tutorial.dir/src/window.cpp.s

# Object files for target Tutorial
Tutorial_OBJECTS = \
"CMakeFiles/Tutorial.dir/src/camera.cpp.o" \
"CMakeFiles/Tutorial.dir/src/engine.cpp.o" \
"CMakeFiles/Tutorial.dir/src/graphics.cpp.o" \
"CMakeFiles/Tutorial.dir/src/main.cpp.o" \
"CMakeFiles/Tutorial.dir/src/object.cpp.o" \
"CMakeFiles/Tutorial.dir/src/shader.cpp.o" \
"CMakeFiles/Tutorial.dir/src/window.cpp.o"

# External object files for target Tutorial
Tutorial_EXTERNAL_OBJECTS =

Tutorial: CMakeFiles/Tutorial.dir/src/camera.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/engine.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/graphics.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/main.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/object.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/shader.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/window.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/build.make
Tutorial: /usr/local/lib/libSDL2main.a
Tutorial: /usr/local/lib/libSDL2.dylib
Tutorial: /usr/local/Cellar/imagemagick/7.0.8-12/lib/libMagick++-7.Q16HDRI.dylib
Tutorial: CMakeFiles/Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tutorial.dir/build: Tutorial

.PHONY : CMakeFiles/Tutorial.dir/build

CMakeFiles/Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tutorial.dir/clean

CMakeFiles/Tutorial.dir/depend:
	cd /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7 /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7 /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug /Users/kcrodrigue/Documents/CS480/CS480Rodrigue/PA7/cmake-build-debug/CMakeFiles/Tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tutorial.dir/depend

