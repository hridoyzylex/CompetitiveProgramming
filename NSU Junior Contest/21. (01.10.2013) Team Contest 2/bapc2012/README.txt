The problem texts are copyright by the BAPC 2012 jury. They are licensed under the
Creative Commons Attribution-Share Alike license version 3.0; The complete license text
can be found at: http://creativecommons.org/licenses/by-sa/3.0/legalcode 

The samples directory contains sample input and output files that are also in the problem
set and were provided to the contestants during the contest. Not that there are no sample
files for problem B, see the note below.

The testdata directory contains all testdata as used in the judgings. The time limits
depend on the judging machine, but are in general about twice the slowest (correct) jury
submission. For most problems, the difference between a correct and a slow solution is
very large.

The solutions directory contains jury solutions for all problems in various languages.
Some solutions are wrong or too slow; the filename and a special tag inside the file
indicate this. Some solutions contain explanations or proofs of the solution.

Problem B is an interactive problem for which special tools are available in the extra
directory. BlackOutGUI.jar is a visualizer that was provided to the contestants during
the contest, and which can be used to test the solution to B.

The jury program for B can be build with the following command:
   g++ -O2 -Wall runjury_blackout.cpp interactive.c -o runjury_blackout
Furthermore, precalc.cpp must be compiled and run before the jury program will work.
This will generate a 128Mb file called precalc.in which is used by the runjury_blackout
program. To test a solution, use the runjury_blackout program as wrapper around the
submission. For example:
   ./runjury_blackout ./B < testdata/B.in
The output of this call should be idendical to testdata/B.out.
