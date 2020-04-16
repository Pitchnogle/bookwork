# Notes

## Check for memory leaks
```
valgrind --tool=memcheck --leak-check=yes <progname>
```

## Chapter content

This chapter provided implementations of several common data structures:  
- array (fixed)
- array (growable)
- linked-list
- binary tree
- hash table

Most of the code was provided as snippets. To that end, there is a demonstration
written for each type. Some additional functions not covered in the text were
also added for completeness.