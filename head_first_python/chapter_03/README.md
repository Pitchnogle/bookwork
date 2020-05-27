# Chapter 3
Navigate to the folder which contains our source data, _sketch.txt_.
```
>>> import os
>>> os.getcwd()
'/mnt/c/Users/hadella/bookwork/head_first_python'
>>> os.chdir('chapter_03')
>>> os.getcwd()
'/mnt/c/Users/hadella/bookwork/head_first_python/chapter_03'
```
Open the file and read a few lines...
```
>>> data = open('sketch.txt')
>>> print(data.readline(), end='')
Man: Is this the right room for an argument?
>>> print(data.readline(), end='')
Other Man: I've told you once.
```
Go back to the beginning of the file, then read all lines...
```
>>> data.seek(0)
0
>>> for each_line in data:
...     print(each_line, end='')
... 
Man: Is this the right room for an argument?
Other Man: I've told you once.
Man: No you haven't!
Other Man: Yes I have.
...
Other Man: No it isn't!
Man: Yes it is!
>>> data.close()
```
Take a closer look at the data...
```
>>> data = open('sketch.txt')
>>> for each_line in data:
...     (role, line_spoken) = each_line.split(':')
...     print(role, end='')
...     print(' said: ', end='')
...     print(line_spoken, end='')
... 
Man said:  Is this the right room for an argument?
Other Man said:  I've told you once.
Man said:  No you haven't!
Other Man said:  Yes I have.
...
Other Man said:  Just the five minutes. Thank you.
Other Man said:  Anyway, I did.
Man said:  You most certainly did not!
Traceback (most recent call last):
  File "<stdin>", line 2, in <module>
ValueError: too many values to unpack (expected 2)
```
The trouble is the original data has some lines which contain "(pause)" and no
colons to split. The book covers two approaches to deal with this. The first is
to apply extra logic before calling split. The second approach uses exception 
handling.
```
>>> for each_line in data:
...     try:
...         (role, line_spoken) = each_line.split(':', 1)
...         print(role, end='')
...         print(' said: ', end='')
...         print(line_spoken, end='')
...     except:
...         pass
... 
Man said:  Is this the right room for an argument?
Other Man said:  I've told you once.
Man said:  No you haven't!
Other Man said:  Yes I have.
Man said:  When?
Other Man said:  Just now.
Man said:  No you didn't!
...
Other Man said:  Nonsense!
Man said:  (exasperated) Oh, this is futile!!
Other Man said:  No it isn't!
Man said:  Yes it is!
>>> data.close()
```
## Be specific with your exceptions
```
>>> import os
>>> try:
...     data = open('sketch.txt')
...     for each_line in data:
...         try:
...             (role, line_spoken) = each_line.split(':', 1)
...             print(role, end='')
...             print(' said: ', end='')
...             print(line_spoken, end='')
...         except ValueError:
...             pass
...     data.close()
... except IOError:
...     print('The data file is missing!')
... 
Man said:  Is this the right room for an argument?
Other Man said:  I've told you once.
Man said:  No you haven't!
Other Man said:  Yes I have.
Man said:  When?
Other Man said:  Just now.
Man said:  No you didn't!
Other Man said:  Yes I did!
Man said:  You didn't!
Other Man said:  I'm telling you, I did!
Man said:  You did not!
Other Man said:  Oh I'm sorry, is this a five minute argument, or the full half hour?
Man said:  Ah! (taking out his wallet and paying) Just the five minutes.
Other Man said:  Just the five minutes. Thank you.
Other Man said:  Anyway, I did.
Man said:  You most certainly did not!
Other Man said:  Now let's get one thing quite clear: I most definitely told you!
Man said:  Oh no you didn't!
Other Man said:  Oh yes I did!
Man said:  Oh no you didn't!
Other Man said:  Oh yes I did!
Man said:  Oh look, this isn't an argument!
Other Man said:  Yes it is!
Man said:  No it isn't!
Man said:  It's just contradiction!
Other Man said:  No it isn't!
Man said:  It IS!
Other Man said:  It is NOT!
Man said:  You just contradicted me!
Other Man said:  No I didn't!
Man said:  You DID!
Other Man said:  No no no!
Man said:  You did just then!
Other Man said:  Nonsense!
Man said:  (exasperated) Oh, this is futile!!
Other Man said:  No it isn't!
Man said:  Yes it is!
```
