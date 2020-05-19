## Notes

This chapter is all about function pointers.

### Looking for Mr. Right...

The demonstrated using function pointers to avoid code duplication.
```
$ gcc -Wall find.c -o find && ./find
Search results:
----------------------------------------
William: SBM GSOH likes sports, TV, dining
Josh: SJM likes sports, movies and theater
----------------------------------------
Search results:
----------------------------------------
William: SBM GSOH likes sports, TV, dining
Mike: DWM DS likes trucks, sports and bieber
Peter: SAM likes chess, working out and art
Josh: SJM likes sports, movies and theater
----------------------------------------
Search results:
----------------------------------------
Matt: SWM NS likes art, movies, theater
----------------------------------------
Search results:
----------------------------------------
William: SBM GSOH likes sports, TV, dining
Matt: SWM NS likes art, movies, theater
Luis: SLM ND likes books, theater, art
Josh: SJM likes sports, movies and theater
Jed: DBM likes theater, books and dining
----------------------------------------
```

### Test Drive

This program demonstrates the general stdlib sort() function.
```$ gcc -Wall test_drive.c -o test_drive && ./test_drive
These are the scores in descending order:
Score = 554
Score = 543
Score = 323
Score = 112
Score = 32
Score = 11
Score = 3
These are the names in order:
Diego
Juan
Pablo
Rodrigo
```

### Dear Johns
This program demonstrates use of function pointers to replace a switch block.
```
$ gcc -Wall send_dear_johns.c -o send_dear_johns
$ ./send_dear_johns
Dear Mike,
Unfortunately, your last date contacted us to
say that they will not be seeing you again.

Dear Luis,
Good news: your last date has asked us to
arrange another meething. Please call ASAP.

Dear Matt,
Good news: your last date has asked us to
arrange another meething. Please call ASAP.

Dear William,
Congratulations! Your last date has contacted
us with a proposal of marriage

```

### Make your functions stretchy
This program demonstrates use of variadic functions, which are functions with a
variable number of arguments.
```
$ gcc -Wall price_drinks.c -o price_drinks
$ ./price_drinks
Price is 11.61
Price is 16.92
Price is 5.89
```
