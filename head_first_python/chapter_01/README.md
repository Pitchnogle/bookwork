# Chapter 1
What version of python is installed?
```
$ python3 -V
Python 3.6.7
```
Lists use 0-based indexing.
```
>>> movies = ["The Holy Grail", "The Life of Brian", "The Meaning of Life"]
>>> print(movies[1])
The Life of Brian
```
One neat trick is to use _negative_ indexing. The last item in a list is at
index -1.
```
>>> print(movies[-1])
The Meaning of Life
```
We can add items to a list in a number of ways. Lists don't have to store the
same types of data either.
```
>>> movies = ["The Holy Grail", "The Life of Brian", "The Meaning of Life"]
>>> movies.insert(1, 1975)
>>> movies.insert(3, 1979)
>>> movies.append(1983)
>>> print(movies)
['The Holy Grail', 1975, 'The Life of Brian', 1979, 'The Meaning of Life', 1983]
```
It's time to iterate
```
>>> movies = ["The Holy Grail", "The Life of Brian", "The Meaning of Life"]
>>> for each_movie in movies:
...     print(each_movie)
... 
The Holy Grail
The Life of Brian
The Meaning of Life
```
Iterate using while...
```
>>> movies = ["The Holy Grail", "The Life of Brian", "The Meaning of Life"]
>>> count = 0
>>> while count < len(movies):
...     print(movies[count])
...     count = count + 1
... 
The Holy Grail
The Life of Brian
The Meaning of Life
```
Store lists within lists
```
>>> movies = ["The Holy Grail", 1975, "Terry Jones & Terry Gilliam", 91, ["Graham Chapman", ["Michael Palin",
... "John Cleese", "Terry Gilliam", "Eric Idle", "Terry Jones"]]]
>>> print(movies[4][1][3])
Eric Idle
>>> print(movies)
['The Holy Grail', 1975, 'Terry Jones & Terry Gilliam', 91, ['Graham Chapman', ['Michael Palin', 'John Cleese', 'Terry Gilliam', 'Eric Idle', 
'Terry Jones']]]
```
Create a function in python
```python
>>> def print_lol(the_list):
...     for each_item in the_list:
...             if isinstance(each_item, list):
...                     print_lol(each_item)
...             else:
...                     print(each_item)
... 
```
```
>>> print_lol(movies)
The Holy Grail
1975
Terry Jones & Terry Gilliam
91
Graham Chapman
Michael Palin
John Cleese
Terry Gilliam
Eric Idle
Terry Jones
```
