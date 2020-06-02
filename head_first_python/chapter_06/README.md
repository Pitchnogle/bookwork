# Chapter 6
We start out similar to last chapter, but with a modified file format; the first
two entries are now the name, and date-of-birth of the athletes.
```
>>> def sanitize(time_string):
...     if '-' in time_string:  
...         splitter = '-'      
...     elif ':' in time_string:
...         splitter = ':'      
...     else:
...         return(time_string)
...     (mins, secs) = time_string.split(splitter)
...     return(mins + '.' + secs)
... 
>>> def get_coach_data(filename):
...     try:
...         with open(filename) as f:
...             data = f.readline()
...         return(data.strip().split(','))
...     except IOError as ioerr:
...         print('File error: ' + str(ioerr))
...         return(None)
...
>>> sarah = get_coach_data('sarah2.txt')
>>> (sarah_name, sarah_dob) = sarah.pop(0), sarah.pop(0)
>>> print(sarah_name + "'s fastest times are: " + str(sorted(set([sanitize(t) for t in sarah]))[0:3]))
Sarah Sweeney's fastest times are: ['2.18', '2.21', '2.22']
```
The program is fine, but the data is disjointed. We can couple associated data
together in python using a dictionary.
```
>>> cleese = {}
>>> palin = dict()
>>> type(cleese)
<class 'dict'>
>>> type(palin)
<class 'dict'>
```
Now we can add key/value pairs to our dictionaries.
```
>> cleese['Name'] = 'John Cleese'
>>> cleese['Occupations'] = ['actor', 'comedian', 'writer', 'film producer']
>>> palin = {'Name': 'Michael Palin', 'Occupations': ['comedian', 'actor', 'writer', 'tv']}
>>> palin['Name']
'Michael Palin'
>>> cleese['Occupations'][-1]
'film producer'
```
We can even add new keys once the dictionary has been created.
```
>>> palin['Birthplace'] = 'Broomhill, Sheffield, England'
>>> cleese['Birthplace'] = 'Wester-super-Mare, North Somerset, England'
>>> palin
{'Name': 'Michael Palin', 'Occupations': ['comedian', 'actor', 'writer', 'tv'], 'Birthplace': 'Broomhill, Sheffield, England'}
>>> cleese
{'Name': 'John Cleese', 'Occupations': ['actor', 'comedian', 'writer', 'film producer'], 'Birthplace': 'Wester-super-Mare, North Somerset, England'}
```
Now we modify our athlete code to use a dictionary.
```
>>> sarah = get_coach_data('sarah2.txt')
>>> sarah_data = {}
>>> sarah_data['Name'] = sarah.pop(0)
>>> sarah_data['DOB'] = sarah.pop(0)
>>> sarah_data['Times'] = sarah  
>>> print(sarah_data['Name'] + "'s fastest times are: " + str(sorted(set([sanitize(t) for t in sarah_data['Times']]))[0:3]))
Sarah Sweeney's fastest times are: ['2.18', '2.21', '2.22']
```
This code is arguably better, but most of the file processing is done outside of
the file. Let's improve the get_coach_data() function further:
```
def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        templ = data.strip().split(',')
        return({'Name': templ.pop(0),
                'DOB': templ.pop(0),
                'Times': str(sorted(set([sanitize(t) for t in templ]))[0:3])})
    except IOError as ioerr:
        print('File Error: ' + str(ioerr))
        return(None)
```
```
>>> james = get_coach_data('james2.txt')
>>> print(james['Name'] + "'s fastest times are: " + james['Times'])
James Lee's fastest times are: ['2.01', '2.22', '2.34']
```
The next section introduces `classes` a mechanism to couple code and data 
together.
```
class Athlete:
    def __init__(self, a_name, a_dob=None, a_times=[]):
        self.name = a_name
        self.dob = a_dob
        self.times = a_times
    
    def top3(self):
        return(sorted(set([sanitize(t) for t in self.times]))[0:3])
    
def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        templ = data.strip().split(',')
        return(Athlete(templ.pop(0), templ.pop(0), templ))
    except IOError as ioerr:
        print('File Error: ' + str(ioerr))
        return(None)
```
```
>>> james = get_coach_data('james2.txt')
>>> print(james.name + "'s fastest times are: " + str(james.top3()))
James Lee's fastest times are: ['2.01', '2.22', '2.34']
```
