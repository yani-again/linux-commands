# Cat Clone

My attempt at recreating the `cat` command from Linux.

## Features
- Print the raw contents of a specified file
- Print the raw contents of multiple specified files

## Usage
Once you've compiled the main.c file, locate it and input into your terminal:
<location of the main file> <file to print>

You can specify multiple files to print.

Example usage:
~/c-code/linux-commands/cat/main ~/recipes/chocolate-cake.txt

## Installation
No installation required.

Just download the 'main.c' file and compile it with the C compiler of your choice, then run it from your terminal as outlined above.

## Notes
Initial commit doesn't include full implementation of the > operator (used to write the contents of one file into another).

It works, however it appends the file name plus a newline character at the beginning of the file due to incomplete implementation.

This will be updated in the future, if it hasn't aready as of you reading this.
