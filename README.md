# Disk Analyzer
Disk analyzer is a c++ dynamic program that presents all the subdirectories and the subfiles of a
given path with all their necessary information (name, size, percentage usage,...etc.)
Made by: Eman Negm, Salma Wafa, Mohamed Gamal, Ahmed Ehab, Ramy ElGendi
Last Updated: Sunday, 28 December 2020 6:00 am

## Limitations
- The root path has to be hard-coded
-The vector cannot be more than 4000 in size, and so putting the ‘/’ as the address could lead to
crashing the program since there will be way too many files for it to handle.

## Usage
To start the program, you first type the main path in main.cpp. Then, when you run the code, the
pie chart of the root appears on the right. If you want to make another directory the root, select
the directory and press "scan". If you want to delete the pie chart, press "stop". If there
is a new directory/file added to the directory you are analyzing and you want it to appear on the
pie chart, press "refresh".
