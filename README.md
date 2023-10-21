# mathematical-algorithms
My implementations of various mathematical algorithms

# Laplace Expansion

The laplace expansion algorithm calculates a determinant of the n x n matrix by recursively calculating determinants for submatrices until it reaches a base case of an 2 x 2 matrix.
Hence in order to calculate determinant of the n x n matrix the algorithm needs to calculate determinants of n submatrices of size (n - 1) x (n - 1) the complexity is ***n!***.

## Usage

To use the program you need to compile it first using c++ 17 or higher.
```
g++ -std=c++17 -o laplace laplace.cpp
```
Then run it

```
./laplace
```

The program takes n as the first line of input and then n lines of n space separated numbers indicating rows of the matrix.

### Example Input

```
5
1 0 0 2 3
7 6 2 4 1
2 1 4 8 3
3 1 5 0 1
0 2 3 1 4
```

### Example Output

```
-2574
```
