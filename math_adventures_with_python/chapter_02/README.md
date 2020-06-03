# Chapter 2
This chapter is a brief intro to python

## Exercise 2-1: Finding the Sum
```py
def sum_n(n):
	sum = 0
	for i in range(n):
		sum += i + 1
	return sum
```
```py
>>> sum_n(100)
5050
```
```py
>>> sum_n(1000)
500500
```
Looks like there is a pattern here. We can leverage this pattern to alter the
code.
```py
def sum_n(n):
	return int(n * (n + 1) / 2)
```

## Exercise 2-2: Finding the Average
```py
def ave_list(a_list):
	return sum(a_list) / len(a_list)
```
```py
>>> d = [53, 28, 54, 84, 65, 60, 22, 93, 62, 27, 16, 25, 74, 42, 4, 42, 15, 96, 11, 70, 83, 97, 75]
>>> ave_list(d)
52.08695652173913
```
