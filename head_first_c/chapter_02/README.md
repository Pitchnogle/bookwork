## Notes

### Compass Magnets (pg 49-51)

```
$ gcc -Wall southeast.c -o southeast
$ ./southeast
Avast! Now at: [31, -63]
```

### Arrays and Pointers

```
char s[] = "This is a character array"
char *t = s;
```

- sizeof s is the size of the array
- sizeof t is the size of s[0]
- &s == s
- &t != t
- s can't point anywhere else!

### The Case of the Lethal List (pg 60-63)

```C
int doses[] = {1, 3, 2, 1000};
printf("Issue dose %i", 3[doses]);
```

```C
doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
```

### Using Pointers for Data Entry (pg 65)

In this example, note that `scanf` reads one less character than the array len.
We need to keep space for the string terminator `\0`. Also, `scanf` will quit
reading as soon as whitespace is encountered.

```C
char name[40];
printf("Enter your name: ");
scanf("%39s", name);
```

Keep in mind `scanf` can cause buffer overruns. Use `fgets` as an alternative,
and then `sscanf` to parse out multiple variables.

For the example above the safer equivalent would be:

```C
char name[40];
fgets(name, sizeof (name), stdin);
```

### cards[] or cards*? (pg 74)

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
```C
s[0] = 'S';
```
then the compiler will produce an error.
