#!/bin/bash

module load compilers/gnu-5.4.0
gcc --version

make clean
make

./tema2_blas input