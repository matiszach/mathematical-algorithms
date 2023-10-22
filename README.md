# mathematical-algorithms
My implementations of various mathematical algorithms

# Laplace Expansion

The Laplace expansion algorithm calculates a determinant of the __n x n__ matrix by recursively calculating determinants for submatrices until it reaches a base case of a __2 x 2__ matrix.
Hence in order to calculate determinant of the __n x n__ matrix the algorithm needs to calculate determinants of n submatrices of size __(n - 1) x (n - 1)__ the complexity is $O(n!)$.

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

# Gaussian Elimination

The Gaussian elimination algorithm finds all solutions to the system of the linear equations or indicates that there are none.
It does so by reducing the matrix to the echelon form using three elementary row operations in the matrix.
1. Swap the positions of the two rows
2. Multiply a row by a non-zero scalar
3. Add a scalar multiple of the row to another row

Then from the echelon form it is easy to solve for every variable.

Reducing a matrix to the echelon form requieres to use at most one operation per every number in the matrix so the algorithm performs at most $n^2$ operations. Each operation takes entire row so the complexity is $O(n^3)$.

## Usage

To use the program you need to compile it first using c++ 17 or higher.
```
g++ -std=c++17 -o gaussian_elimination gaussian_elimination.cpp
```
Then run it

```
./gaussian_elimination
```

The program takes as an input the number n indicating number of equations and then in every of the next n lines n + 1 space separated numbers, where first n of them indicate coefficients of terms $x_1, x_2, ... , x_n$ and the last indicates the constant result of the equation.

## Example Input

```
4
1 2 0 3 5
0 1 3 2 8
2 3 0 1 1
5 1 3 2 1
```

## Example Output

```
------------

Echelon form: 

1 0 0 0 -1.4 
0 1 0 0 0.714286 
0 0 3 0 3.97143 
0 0 0 35 58 

------------

Solutions: 

x1 = -1.4
x2 = 0.714286
x3 = 1.32381
x4 = 1.65714
```
