## Notes

### Recursive data structures

As mentioned in the previous chapter, when we require a linked structure, we
can't use the typedef alias; we need to use the struct's tag name instead.

```
typedef struct tag_name {
	...
} struct_alias;
```

So a linked-list struct would resemble:
```
typedef struct tag_name {
	...
	struct tag_name *next;
} struct_alias;
```

### Island Tour

```
$ gcc -Wall tour.c -o tour
$ ./tour < trip1.txt
Name: Delfino Isle
 open: 09:00-17:00
Name: Angel Island
 open: 09:00-17:00
Name: Wild Cat Island
 open: 09:00-17:00
Name: Neri's Island
 open: 09:00-17:00
Name: Great Todday
 open: 09:00-17:00
Name: Ramita de la Baya
 open: 09:00-17:00
Name: Island of the Blue Dolphins
 open: 09:00-17:00
Name: Fantasy Island
 open: 09:00-17:00
Name: Farna
 open: 09:00-17:00
Name: Isla de Muert
 open: 09:00-17:00
Name: Tabor Island
 open: 09:00-17:00
Name: Haunted Isle
 open: 09:00-17:00
Name: Sheena Island
 open: 09:00-17:00
```

### Top Secret

```
$ gcc -Wall -g spies.c -o spies && ./spies
Does suspect has a mustache? (y/n): n
Loretta Barnesworth? (y/n): n
Who's the suspect? Hayden Fantucci
Give me a question thst is TRUE for Hayden Fantucci
 but not for Loretta Barnesworth?Has facial scar
Run Again? (y/n): y
Does suspect has a mustache? (y/n): n
Has facial scar
? (y/n): y
Hayden Fantucci
? (y/n): y
SUSPECT IDENTIFIED
Run Again? (y/n): n
```

The original version in the book had a memory leak when the strdup() was called
when a new question was added.

```
$ gcc -g -Wall spies.c -o spies                                  
hadella@DESKTOP-GV2Q0UA:/mnt/c/Users/hadella/bookwork/head_first_c/chapter_06$ valgrind --leak-check=full ./spies
==135== Memcheck, a memory error detector
==135== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.   
==135== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==135== Command: ./spies
==135==
==135== error calling PR_SET_PTRACER, vgdb might block
Does suspect has a mustache? (y/n): n
Loretta Barnesworth? (y/n): n
Who's the suspect? Hayden Fantucci
Give me a question thst is TRUE for Hayden Fantucci
 but not for Loretta Barnesworth? Has a facial scar
Run Again? (y/n): n
==135== 
==135== HEAP SUMMARY:
==135==     in use at exit: 20 bytes in 1 blocks
==135==   total heap usage: 13 allocs, 12 frees, 8,432 bytes allocated
==135== 
==135== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
==135==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==135==    by 0x4ED99B9: strdup (strdup.c:42)
==135==    by 0x1088F3: create (spies.c:25)
==135==    by 0x1089CB: main (spies.c:52)
==135==
==135== LEAK SUMMARY:
==135==    definitely lost: 20 bytes in 1 blocks
==135==    indirectly lost: 0 bytes in 0 blocks
==135==      possibly lost: 0 bytes in 0 blocks
==135==    still reachable: 0 bytes in 0 blocks
==135==         suppressed: 0 bytes in 0 blocks
==135==
==135== For counts of detected and suppressed errors, rerun with: -v
==135== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

The solution was to free the old question's memory before calling strdup(). See
line 85 in spies.c.

```
$ valgrind --leak-check=full ./spies
==129== Memcheck, a memory error detector
==129== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==129== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==129== Command: ./spies
==129==
==129== error calling PR_SET_PTRACER, vgdb might block
Does suspect has a mustache? (y/n): n
Loretta Barnesworth? (y/n): n
Who's the suspect? Hayden Fantucci
Give me a question thst is TRUE for Hayden Fantucci
 but not for Loretta Barnesworth? Has a facial scar
Run Again? (y/n): n
==129==
==129== HEAP SUMMARY:
==129==     in use at exit: 0 bytes in 0 blocks
==129==   total heap usage: 13 allocs, 13 frees, 8,432 bytes allocated
==129==
==129== All heap blocks were freed -- no leaks are possible
==129==
==129== For counts of detected and suppressed errors, rerun with: -v
==129== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

