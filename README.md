# CourseForge



Project Overview

This C++ application simulates a course planning subsystem while benchmarking basic sorting algorithms. The project uses a Linear Congruential Generator (LCG) to construct deterministic datasets for student records and course offerings, then evaluates the computational overhead of Selection Sort and Insertion Sort by tracking real-time execution metrics.



Key Features



Deterministic Data Generator: Constructs student records and course requirements using a pseudo-random Linear Congruential Generator governed by seed 6154. Student records feature university IDs starting at 202316154 and generated GPA values.



Selection Sort Class: Implements array sorting based on student GPA, recording key comparisons and element swaps.



Insertion Sort Class: Implements incremental sorting based on student GPA, recording key comparisons and array shift operations.



Execution Tracing: Features a trace mode that logs array state updates during insertion sort passes on a subset of dataset records.



System Requirements



C++ Compiler: GCC, Clang, or MSVC with C++11 support or higher.



Platform: Cross-platform compatible (Linux, macOS, Windows).



Compilation and Execution



To compile the application using standard g++:

g++ -std=c++11 "assignment main code.cpp" -o course\_planner



To run the executable on Linux/macOS:

./course\_planner



To run the executable on Windows:

course\_planner.exe



Runtime Output Overview

The application prints dataset configuration metadata—including active seed, generated course counts, record limits, and credit caps—followed by execution metrics for both sorting algorithms. It concludes with an intermediate trace demonstrating element positioning across insertion sort iterations.



License

This software is provided as open-source for educational and algorithmic testing purposes.



done by: Tayeb Al-Tayeb

