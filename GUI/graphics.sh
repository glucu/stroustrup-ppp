#!/bin/bash

# Set the directory where the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Set the directory where the GUI files are located
GUI_DIR="$SCRIPT_DIR/../GUI"

# Specify the source files relative to the GUI directory
SOURCE_FILES="$GUI_DIR/Graph.cpp $GUI_DIR/Window.cpp $GUI_DIR/Simple_window.cpp $GUI_DIR/GUI.cpp"

# Set the include path for header files
INCLUDE_PATH="-I$GUI_DIR"

# Run the compilation command
#  g++ -W -Wall -g -std=c++14 $SOURCE_FILES `fltk-config --ldflags --use-images` $INCLUDE_PATH "$SCRIPT_DIR/../ch12/$1"

g++ -g -std=c++14 $SOURCE_FILES `fltk-config --ldflags --use-images` $INCLUDE_PATH $1 


# $GUI_DIR/GUI.cpp 
