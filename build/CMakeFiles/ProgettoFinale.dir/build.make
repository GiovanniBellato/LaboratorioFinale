# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/giovanni/coding/universita_programmazione/LaboratorioFinale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build

# Include any dependencies generated for this target.
include CMakeFiles/ProgettoFinale.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProgettoFinale.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProgettoFinale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProgettoFinale.dir/flags.make

CMakeFiles/ProgettoFinale.dir/codegen:
.PHONY : CMakeFiles/ProgettoFinale.dir/codegen

CMakeFiles/ProgettoFinale.dir/src/main.cpp.o: CMakeFiles/ProgettoFinale.dir/flags.make
CMakeFiles/ProgettoFinale.dir/src/main.cpp.o: /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/main.cpp
CMakeFiles/ProgettoFinale.dir/src/main.cpp.o: CMakeFiles/ProgettoFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProgettoFinale.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgettoFinale.dir/src/main.cpp.o -MF CMakeFiles/ProgettoFinale.dir/src/main.cpp.o.d -o CMakeFiles/ProgettoFinale.dir/src/main.cpp.o -c /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/main.cpp

CMakeFiles/ProgettoFinale.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgettoFinale.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/main.cpp > CMakeFiles/ProgettoFinale.dir/src/main.cpp.i

CMakeFiles/ProgettoFinale.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgettoFinale.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/main.cpp -o CMakeFiles/ProgettoFinale.dir/src/main.cpp.s

CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o: CMakeFiles/ProgettoFinale.dir/flags.make
CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o: /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/CycleDevice.cpp
CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o: CMakeFiles/ProgettoFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o -MF CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o.d -o CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o -c /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/CycleDevice.cpp

CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/CycleDevice.cpp > CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.i

CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/CycleDevice.cpp -o CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.s

CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o: CMakeFiles/ProgettoFinale.dir/flags.make
CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o: /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/Device.cpp
CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o: CMakeFiles/ProgettoFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o -MF CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o.d -o CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o -c /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/Device.cpp

CMakeFiles/ProgettoFinale.dir/src/Device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgettoFinale.dir/src/Device.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/Device.cpp > CMakeFiles/ProgettoFinale.dir/src/Device.cpp.i

CMakeFiles/ProgettoFinale.dir/src/Device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgettoFinale.dir/src/Device.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/Device.cpp -o CMakeFiles/ProgettoFinale.dir/src/Device.cpp.s

CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o: CMakeFiles/ProgettoFinale.dir/flags.make
CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o: /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/DomoticSystem.cpp
CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o: CMakeFiles/ProgettoFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o -MF CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o.d -o CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o -c /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/DomoticSystem.cpp

CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/DomoticSystem.cpp > CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.i

CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/DomoticSystem.cpp -o CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.s

CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o: CMakeFiles/ProgettoFinale.dir/flags.make
CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o: /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/ManualDevice.cpp
CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o: CMakeFiles/ProgettoFinale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o -MF CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o.d -o CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o -c /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/ManualDevice.cpp

CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/ManualDevice.cpp > CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.i

CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/src/ManualDevice.cpp -o CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.s

# Object files for target ProgettoFinale
ProgettoFinale_OBJECTS = \
"CMakeFiles/ProgettoFinale.dir/src/main.cpp.o" \
"CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o" \
"CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o" \
"CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o" \
"CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o"

# External object files for target ProgettoFinale
ProgettoFinale_EXTERNAL_OBJECTS =

ProgettoFinale: CMakeFiles/ProgettoFinale.dir/src/main.cpp.o
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/src/CycleDevice.cpp.o
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/src/Device.cpp.o
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/src/DomoticSystem.cpp.o
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/src/ManualDevice.cpp.o
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/build.make
ProgettoFinale: CMakeFiles/ProgettoFinale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ProgettoFinale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProgettoFinale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProgettoFinale.dir/build: ProgettoFinale
.PHONY : CMakeFiles/ProgettoFinale.dir/build

CMakeFiles/ProgettoFinale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProgettoFinale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProgettoFinale.dir/clean

CMakeFiles/ProgettoFinale.dir/depend:
	cd /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/giovanni/coding/universita_programmazione/LaboratorioFinale /Users/giovanni/coding/universita_programmazione/LaboratorioFinale /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build /Users/giovanni/coding/universita_programmazione/LaboratorioFinale/build/CMakeFiles/ProgettoFinale.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProgettoFinale.dir/depend

