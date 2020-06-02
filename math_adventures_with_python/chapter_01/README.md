# Chapter 1

This chapter uses turtle graphics like in the `logo` programming language.

## Exercise 1-1: Square Dance
```py
from turtle import *

shape('turtle')

forward(100)
right(90)

forward(100)
right(90)

forward(100)
right(90)

forward(100)
right(90)
```
We can improve this code by using loops and function definitions.
```py
from turtle import *

shape('turtle')

def square():
  for i in range(4):
    forward(100)
    right(90)

square()
```

## Exercise 1-2: A Circle of Squares
```py
from turtle import *

shape('turtle')
speed(0)

def square():
  for i in range(4):
    forward(100)
    right(90)

for i in range(60):
  square()
  right(5)
```
We modify this slightly to be able to specify the side length of the square.
```py
from turtle import *

shape('turtle')
speed(0)

def square(side_len=100):
  for i in range(4):
    forward(side_len)
    right(90)

for i in range(60):
  square()
  right(5)
```

## Exercise 1-3: Tri and Tri Again
This draws an equalateral triangle
```py
from turtle import *

shape('turtle')
speed(0)

def triangle(side_len=100):
  for i in range(3):
    forward(side_len)
    right(120)

triangle()
```

## Exercise 1-4: Polygon Functions
```py
from turtle import *

shape('turtle')
speed(0)

def polygon(sides=4, side_len=100):
  for i in range(sides):
    forward(side_len)
    right(360/sides)

polygon(5)
```

## Exercise 1-5: Turtle Spiral
```py
from turtle import *

shape('turtle')
speed(0)

def square(side_len=100):
  for i in range(4):
    forward(side_len)
    right(90)

side_len = 5
for i in range(60):
  square(side_len)
  right(5)
  side_len += 5
```

## Exercise 1-6: A Star is Born
```py
from turtle import *

speed(0)

def star(side_len=100):
  angle = 144 # 180 - 360 / (2 * 5)
  for i in range(5):
    forward(side_len)
    right(angle)

side_len = 5
for i in range(60):
  star(side_len)
  right(5)
  side_len += 5
```