# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build

# Include any dependencies generated for this target.
include CMakeFiles/Network.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Network.dir/flags.make

CMakeFiles/Network.dir/Network.cpp.o: CMakeFiles/Network.dir/flags.make
CMakeFiles/Network.dir/Network.cpp.o: ../Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Network.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Network.dir/Network.cpp.o -c /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/Network.cpp

CMakeFiles/Network.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Network.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/Network.cpp > CMakeFiles/Network.dir/Network.cpp.i

CMakeFiles/Network.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Network.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/Network.cpp -o CMakeFiles/Network.dir/Network.cpp.s

CMakeFiles/Network.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/Network.dir/Network.cpp.o.requires

CMakeFiles/Network.dir/Network.cpp.o.provides: CMakeFiles/Network.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/Network.dir/build.make CMakeFiles/Network.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/Network.dir/Network.cpp.o.provides

CMakeFiles/Network.dir/Network.cpp.o.provides.build: CMakeFiles/Network.dir/Network.cpp.o

# Object files for target Network
Network_OBJECTS = \
"CMakeFiles/Network.dir/Network.cpp.o"

# External object files for target Network
Network_EXTERNAL_OBJECTS =

Network: CMakeFiles/Network.dir/Network.cpp.o
Network: CMakeFiles/Network.dir/build.make
Network: CMakeFiles/Network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Network.dir/build: Network
.PHONY : CMakeFiles/Network.dir/build

CMakeFiles/Network.dir/requires: CMakeFiles/Network.dir/Network.cpp.o.requires
.PHONY : CMakeFiles/Network.dir/requires

CMakeFiles/Network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Network.dir/clean

CMakeFiles/Network.dir/depend:
	cd /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build /home/INTRANET/benromdh/Desktop/myfiles/prog17-18/Neuron/build/CMakeFiles/Network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Network.dir/depend
