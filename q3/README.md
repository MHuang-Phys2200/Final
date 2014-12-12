##Final problem 3 for PHYS2200
####Calculation of a series using floating point variables

This problem asks for the calculation of a convergent series to a relative error. In this case the error is 3 time the machine epsilon.

Summation(1/k^4) = pi^4/90

machine epsilon is the value that is small enough that cannot be represented by a floating point variable. ( where 1 + machine epsilon = 1)

* **Process**

The process for finding machine epsilon is to keep dividing a floating variable by 2 until 1 + variable = 1. A common problem with floating point variables arises When adding the values of the series starting from k=1. The prblem is for values farther from 0, machine epsilon is larger. 

0 + machine epsilon 0 = 0 

1 + machine epsilon 1 = 1 

machine epsilon 0 < machine epsilon 1

when k = 1, 1/k^4 = 1 and the value of 1/k^4 decreases as K increases so the values being added eventually decrease to a point where they are smaller than machine epsilon and the value calculated by the computer will not change as K increases. The solution from class was to start from K = n where n is the end value of the summation. This lets the computer start with lower values of 1/k^4, eliminating the problem with floating point variables.
