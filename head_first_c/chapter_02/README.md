## Notes

```
$ gcc -Wall southeast.c -o southeast
$ ./southeast
Avast! Now at: [31, -63]
```

### The Case of the Lethal List

```C
int doses[] = {1, 3, 2, 1000};
printf("Issue dose %i", 3[doses]);
```

```C
doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
```

### cards[] or cards*?

```C
void stack_deck(char cards[]) {}
```
and
```C
void stack_deck(char *cards) {}
```
are equivalent.

### Tip

Instead of writing:  
```C
char *s = "some string";
```
do this instead:  
```C
const char *s = "some string";
```
That way, if you do something in the code, such as:  
```
s[0] = 'S';
```
then the compiler will produce an error.
