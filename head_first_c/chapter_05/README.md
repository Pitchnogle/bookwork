## Notes

### Pool Puzzle

```$ make pool_puzzle && ./pool_puzzle
cc     pool_puzzle.c   -o pool_puzzle
Snappy is a Piranha with 69 teeth. He is 4
Name: Snappy
Species: Piranha
4 years old, 69 teeth
```

### Long Exercise

```
$ gcc -Wall long_exercise.c -o long_exercise && ./long_exercise
Name: Snappy
Species: Piranha
4 years old, 69 teeth
Feed with 0.20 lbs of meat and allow to swim in the jacuzzi for 7.50 hours
```

### You can give your struct a proper name using typedef

Instead of this:
```
struct cellphone {
	int cell_no;
	const char *wallpaper;
	float minutes_of_charge;
};
```

You can make an alias using typedef:
```
typedef struct cellphone {
	int cell_no;
	const char *wallpaper;
	float minutes_of_charge;
} phone;

phone p = {5557879, "sinistro.png", 1.35};
```

In this case, by adding the typedef the cellphone label isn't necessary in many
cases. _However, in some cases, like for linking to another struct cellphone,
it is._

### Test Drive (pg 237)

```
$ gcc -Wall turtle.c -o turtle && ./turtle
Happy Birthday Myrtle! You are now 100 years old!
Myrtle's age is now 100
```

The code uses the `->` operator. These two expressions are equivalent:
```
(*t).age == t->age
```

### Safe Cracker

```
$ gcc -Wall safe_cracker.c -o safe_cracker && ./safe_cracker     
Contents = GOLD!
```

### A union lets you reuse memory space

Using C99, we can use designated initializers to set values
```
quantity q = {.weight = 4.2};
```

We can also use the dot notation
```
quantity q;
q.volume = 3.7;
```

```
$ gcc -Wall fruit_union.c -o fruit_union && ./fruit_union        
This order contains 4.20 lbs of apples
```

### Code Magnets (pg 256)

The trouble with unions is though it can store data as different contexts,
without some additional data, we can have trouble knowing what is the right
value to use. We can use enums to help.

```
$ gcc -Wall enumtest.c -o enumtest && ./enumtest
This order contains 144 apples
This order contains 17.60 lbs of strawberries
This order contains 10.50 pints of orange juice
```

### Extras

The last section of this chapter briefly covers bitfields, but the book's 
example isn't very complete. I added a simple example which combines bitfields
and a union.

```
$ gcc -Wall bitunion.c -o bitunion && ./bitunion
u.value = 0x75
u.bitfield.foo = 0x5
u.bitfield.bar = 0x3
u.bitfield.baz = 0x1
```

This is the kind of idea which could be useful for something like a low-level 
device driver to set specific bits within a register, but also get and set the 
whole register at once.
