# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/doudou/cmake_demo/cmake_demo_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/doudou/cmake_demo/cmake_demo_4/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/linklist_static.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/linklist_static.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/linklist_static.dir/flags.make

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o: lib/CMakeFiles/linklist_static.dir/flags.make
lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o: ../lib/LinkLists.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/doudou/cmake_demo/cmake_demo_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o"
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linklist_static.dir/LinkLists.cpp.o -c /home/doudou/cmake_demo/cmake_demo_4/lib/LinkLists.cpp

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linklist_static.dir/LinkLists.cpp.i"
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/doudou/cmake_demo/cmake_demo_4/lib/LinkLists.cpp > CMakeFiles/linklist_static.dir/LinkLists.cpp.i

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linklist_static.dir/LinkLists.cpp.s"
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/doudou/cmake_demo/cmake_demo_4/lib/LinkLists.cpp -o CMakeFiles/linklist_static.dir/LinkLists.cpp.s

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.requires:

.PHONY : lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.requires

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.provides: lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/linklist_static.dir/build.make lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.provides.build
.PHONY : lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.provides

lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.provides.build: lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o


# Object files for target linklist_static
linklist_static_OBJECTS = \
"CMakeFiles/linklist_static.dir/LinkLists.cpp.o"

# External object files for target linklist_static
linklist_static_EXTERNAL_OBJECTS =

lib/liblinklist.a: lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o
lib/liblinklist.a: lib/CMakeFiles/linklist_static.dir/build.make
lib/liblinklist.a: lib/CMakeFiles/linklist_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/doudou/cmake_demo/cmake_demo_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblinklist.a"
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/linklist_static.dir/cmake_clean_target.cmake
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linklist_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/linklist_static.dir/build: lib/liblinklist.a

.PHONY : lib/CMakeFiles/linklist_static.dir/build

lib/CMakeFiles/linklist_static.dir/requires: lib/CMakeFiles/linklist_static.dir/LinkLists.cpp.o.requires

.PHONY : lib/CMakeFiles/linklist_static.dir/requires

lib/CMakeFiles/linklist_static.dir/clean:
	cd /home/doudou/cmake_demo/cmake_demo_4/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/linklist_static.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/linklist_static.dir/clean

lib/CMakeFiles/linklist_static.dir/depend:
	cd /home/doudou/cmake_demo/cmake_demo_4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/doudou/cmake_demo/cmake_demo_4 /home/doudou/cmake_demo/cmake_demo_4/lib /home/doudou/cmake_demo/cmake_demo_4/build /home/doudou/cmake_demo/cmake_demo_4/build/lib /home/doudou/cmake_demo/cmake_demo_4/build/lib/CMakeFiles/linklist_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/linklist_static.dir/depend
