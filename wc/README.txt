# Wc Clone

My attempt at recreating the `wc` command from Linux.

## Features
- Print the lines, words, and characters contained in a file
- Use -l -w -c flags to print only the lines, words, or characters contained in a file
- Use a combination of the flags to print the respective statistics of a file

Example:
~/c-code/linux-commands/wc/main ~/recipes/chocolate-cake.txt
Output:
14  25  184

Example:
~/c-code/linux-commands/wc/main -lc ~/recipes/chocolate-cake.txt
Output:
14  184

-l will print the amount of lines contained in the file
-w will print the amount of words contained in the file
-lw will print the amount of lines and words contained in the file

Feel free to compare the output of my version against the real `wc` command to check if the output is accurate. If there are cases where it doesn't work correctly, please let me know!

## Installation
No installation required.

Just download the 'main' file if you're on Linux and run it directly as outlined above.

Or if you are not on a Linux computer, download the 'main.c' file and compile it using a compiler of your choice, then run the output file as outlined above.

## Notes
Updated to allow destination file and options to be put in any order and with any combination (e.g. -wc and -w -c will both work)
