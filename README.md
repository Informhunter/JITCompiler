# JITCompiler
JIT compiler for algebraric expressions was developed as an experimental project in 2015.
The point of the project was to measure the performance improvement of algebraric expression interpreter when using just in time compilation.

## How it works
First, expression (containing variable `x`, constants and +-*/ operations) is transformed into a parse tree.
After this parse tree can be used to calculate the expression value for any `x`.
This is the baseline algorithm with which JIT compilation is compared to.
Once the parse tree is acquired, it is translated into x86 machine code which can be executed any time the expression is needed to be calculated.

## Results
The approach gave 9x speedup of expression calculation compared to baseline algorithm (parse tree interpretation).
Also based on the results the following article was published with the complete description of implementation of the project.
https://habr.com/post/254831/ (russian)
