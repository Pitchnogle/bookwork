# Chapter 4
```
man = []
other = []
try:
	data = open('sketch.txt')
	for each_line in data:
		try:
			(role, line_spoken) = each_line.split(':', 1)
			line_spoken = line_spoken.strip()
			if role == 'Man':
				man.append(line_spoken)
			elif role == 'Other Man':
				other.append(line_spoken)
		except ValueError:
			pass
	data.close()
except IOError:
	print('The datafile is missing!')
```

```
>>> print(man)
['Is this the right room for an argument?', "No you haven't!", 'When?', "No you didn't!", "You didn't!", 'You did not!', 'Ah! (taking out his 
wallet and paying) Just the five minutes.', 'You most certainly did not!', "Oh no you didn't!", "Oh no you didn't!", "Oh look, this isn't an argument!", "No it isn't!", "It's just contradiction!", 'It IS!', 'You just contradicted me!', 'You DID!', 'You did just then!', '(exasperated) Oh, this is futile!!', 'Yes it is!']
```

```
>>> print(other)
["I've told you once.", 'Yes I have.', 'Just now.', 'Yes I did!', "I'm telling you, I did!", "Oh I'm sorry, is this a five minute argument, or the full half hour?", 'Just the five minutes. Thank you.', 'Anyway, I did.', "Now let's get one thing quite clear: I most definitely told you!", 'Oh yes I did!', 'Oh yes I did!', 'Yes it is!', "No it isn't!", 'It is NOT!', "No I didn't!", 'No no no!', 'Nonsense!', "No it isn't!"]   
```
Let's save the data. First attempt...
```
try:
	man_file = open('man_file.txt', 'w')
	other_file = open('other_file.txt', 'w')

	print(man, file=man_file)
	print(other, file=other_file)

	man_file.close()
	other_file.close()
except IOError:
	print('File Error')
```
The trouble with the approach above is that if something goes wrong, the files
won't be closed properly. We can adjust the code to handle this.
```
try:
	man_file = open('man_file.txt', 'w')
	other_file = open('other_file.txt', 'w')

	print(man, file=man_file)
	print(other, file=other_file)

except IOError as err:
	print('File Error: ' + str(err))

finally:
	if 'man_file' in locals():
		man_file.close()
	if 'other_file' in locals():
		other_file.close()
```
## Use the keyword with to work with files
```
try:
	data = open('its.txt', 'w')
	print("It's...", file=data)
except IOError as err:
	print('File Error: ' + str(err))
finally:
	if 'data' in locals():
		data.close()
```
is equivalent to...
```
try:
	with open('its.txt', 'w') as data:
		print("It's...", file=data)
except IOError as err:
	print('File Error: ' + str(err))
```
We also use __with__ with the comma operator to combine things into single line.
```
try:
	with open('man_data.txt', 'w') as man_file, open('other_data.txt', 'w') as other_file:
		print(man, file=man_file)
		print(other, file=other_file)
except IOError as err:
	print('File Error: ' + str(err))
```
Ok, we've saved the data in a few ways. The trouble is the data is now one long
list. We can print out the data like we did in chapter 1.
```
import sys
def print_lol(the_list, indent=False, level=0, fh=sys.stdout):
	for each_item in the_list:
		if isinstance(each_item, list):
			print_lol(each_item, indent, level + 1, fh)
		else:
			if indent:
				for tab_stop in range(level):
					print('\t', end='', file=fh)
			print(each_item, file=fh)
```
Then we can print out the data.
```
>>> print_lol(man)
Is this the right room for an argument?
No you haven't!
When?
No you didn't!
You didn't!
You did not!
Ah! (taking out his wallet and paying) Just the five minutes.
You most certainly did not!
Oh no you didn't!
Oh no you didn't!
Oh look, this isn't an argument!
No it isn't!
It's just contradiction!
It IS!
You just contradicted me!
You DID!
You did just then!
(exasperated) Oh, this is futile!!
Yes it is!
```
## Pickle
Python provides a convenient way to save/load binary data using __pickle__.
```
import pickle

try:
	with open('man_data.bin', 'wb') as man_file, open('other_data.bin', 'wb') as other_file:
		pickle.dump(man, man_file)
		pickle.dump(other, other_file)

except IOError as err:
	print('File error: ' + str(err))

except pickle.PickleError as perr:
	print('Pickling error: ' + str(perr))
```

```
import pickle

try:
	with open('man_data.bin', 'rb') as man_file:
		new_man = pickle.load(man_file)
		
except IOError as err:
	print('File error: ' + str(err))
	
except pickle.PickleError as perr:
	print('Pickling error: ' + str(perr))
```
