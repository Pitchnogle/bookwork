# Notes

There are two testing programs presented in this chapter:
- strings  
  Displays printable characters from binary files
- vis  
  Displays binary as ASCII; printable characters are displayed normally, non-
  printable characters are printed as blue '.'

## Tips

The `strings` function contains the following line:
```C
printf("%s:%.*s\n", name, i, buf);
```

This prints the filename and the current buffer contents to a line. In the code,
the string isn't terminated. The `%.*s` takes the string length from the next
argument `i` since the string is not null terminated.
