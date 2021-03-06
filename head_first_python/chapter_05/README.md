# Chapter 5
This chapter's jupyter notebook version does all the duplication with each
athlete. For brevity, this sections just covers one.

```
with open('james.txt') as jaf:
    data = jaf.readline()

james = data.strip().split(',')
```
We can then print out all the time data.
```
>>> print(james)
['2-34', '3:21', '2.34', '2.45', '3.01', '2:01', '2:01', '3:10', '2-22']
```
## Sorting in python
The `sort()` function performs __in-place__ sorting.
```
>>> data = [6, 3, 1, 2, 4, 5]
>>> data
[6, 3, 1, 2, 4, 5]
>>> data.sort()
>>> data
[1, 2, 3, 4, 5, 6]
```
The `sorted()` function performs __copied__ sorting.
```
>>> data = [6, 3, 1, 2, 4, 5]
>>> data
[6, 3, 1, 2, 4, 5]
>>> data2 = sorted(data)
>>> data
[6, 3, 1, 2, 4, 5]
>>> data2
[1, 2, 3, 4, 5, 6]
```
We can't quite sort the original data, since the times don't use a consistent
format.
```
def sanitize(time_string):
    if '-' in time_string:
        splitter = '-'
    elif ':' in time_string:
        splitter = ':'
    else:
        return(time_string)
    (mins, secs) = time_string.split(splitter)
    return(mins + '.' + secs)
```
Now let's sanitize the data to make it consistent.
```
clean_james = []

for each_time in james:
    clean_james.append(sanitize(each_time))
```
Next, let's display the sorted times.
```
>>> print(sorted(clean_james))
['2.01', '2.01', '2.22', '2.34', '2.34', '2.45', '3.01', '3.10', '3.21']
```
## List Comprehension
The code above has a lot of duplication. One way to help in python is to use a
technique called _list comprehension_.
```
clean_james = []

for each_time in james:
    clean_james.append(sanitize(each_time))
```
is equivalent to...
```
clean_james = [sanitize(each_time) for each_time in james]
```
We can then apply the sorting and printing in one line.
```
>>> james
['2-34', '3:21', '2.34', '2.45', '3.01', '2:01', '2:01', '3:10', '2-22']
>>> print(sorted([sanitize(t) for t in james]))
['2.01', '2.01', '2.22', '2.34', '2.34', '2.45', '3.01', '3.10', '3.21']
```
Let's now print the fastest three _unique_ times. The book code is not correct
since the james list is unsanitory...
```
clean_james = sorted([sanitize(t) for t in james])
unique_james = []

for each_time in clean_james:
    if each_time not in unique_james:
        unique_james.append(each_time)
```
```
print(unique_james[0:3])
['2.01', '2.22', '2.34']
```
## Remove duplicates using set()
There is an easier way of removing duplicate in python. Use the `set()` function.
```
>>> print(sorted(set([sanitize(t) for t in james]))[0:3])
['2.01', '2.22', '2.34']
```
## Cleaning up
So far, we still have a ton of code duplication for each of the data sets. We
need a function to clean this up.
```
def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        return(data.strip().split(','))
    except IOError as ioerr:
        print('File error: ' + str(ioerr))
        return(None)
```
```
>>> sarah = get_coach_data('sarah.txt')
>>> print(sorted(set([sanitize(t) for t in sarah]))[0:3])
['2.18', '2.25', '2.39']
```
Try to open a non-existent file.
```
>>> chris = get_coach_data('chris.txt')
File error: [Errno 2] No such file or directory: 'chris.txt'
```