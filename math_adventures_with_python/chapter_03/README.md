# Chapter 3

## Exercise 3-1: Finding the Factor
```py
def factors(num):
	'''
	returns a list of the factors of num
	'''
	factor_list = []
	for i in range(1, num + 1):
		if num % i == 0:
			factor_list.append(i)
	return factor_list

def gcf(a, b):
	'''
	returns the greatest common factor between a and b
	'''
	a_factors = factors(a)
	b_factors = factors(b)
	common = []
	for f in a_factors:
		if f in b_factors:
			common.append(f)
	return max(common)
```
```py
>>> gcf(150, 138)
6
```
```py
>>> gcf(17, 150)
1
```

## Exercise 3-2: Finding the Square Root
Compared to the book version, I simplified the call here. We start with worst
case initial guesses. To get a more accurate approximation, we just iterate
more in the loop.
```py
def average(a, b):
  return (a + b) / 2

def square_root(num):
  low = 1
  high = num
  for i in range(50):
    guess = average(low, high)
    if guess ** 2 == num:
      return guess
    elif guess ** 2 > num:
      high = guess
    else:
      low = guess
  return guess

print(square_root(200))
print(square_root(1000))
print(square_root(50000))
14.142135623731114
31.622776601683455
223.60679774998044
```
