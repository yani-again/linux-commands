# Hexdump Clone

My attempt at recreating the `hexdump` command from Linux.

## Features
Allows you to hexdump 1 file in the same way as the real `hexdump` command by executing the 'main' file from the terminal along with 1 argument for the file you want to hexdump.

For example:
~/hexdump/main ~/Downloads/myfile
This calls my implementation of the hexdump command on a file called 'myfile' in the path '~/Downloads/'

## Installation
No installation required

Just download the 'main.c' file and compile it with the C compiler of your choice, then run it in your terminal as outlined above.

## Notes
The output from the real `hexdump` command may visually differ from the output from my implementation. This will depend on your system.

My implementation simply outputs the data from the specified file byte-by-byte in order.

x86/x86-64 machines (what you're likely using) use litle-endian byte order when storing multi-byte values in memory, so the real `hexdump` may look like it 'flips' pairs of bytes when compared to my implementation.

For example, my implementation will print the hex bytes 01 and 02 in order: 0102.
Whereas the real `hexdump` on a little-endian system will print the hex bytes 01 and 02 in the opposite order: 0201.

This is not an error nor an issue with both the real `hexdump` command and my implementation.

This could be a future update on my implementation, where I will add an optional flag to output the bytes in both little-endian and big-endian formats. This is functionality not included in the real `hexdump` command by default and has to be achieved using the -e format string option.
