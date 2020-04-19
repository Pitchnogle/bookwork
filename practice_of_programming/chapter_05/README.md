# Notes

There are two testing programs presented in this chapter:
- **strings**  
  Displays printable characters from binary files
- **vis**  
  Displays file similar to hexdump

## Tips

The `strings` function contains the following line:
```C
printf("%s:%.*s\n", name, i, buf);
```

This prints the filename and the current buffer contents to a line. In the code,
the string isn't terminated. The `%.*s` takes the string length from the next
argument `i` since the string is not null terminated.

The exercise section suggests the **vis** program. The actual use of **vis** as
described is dubious, so the version implemented is essentially similar to how
hexdump is used; it is essentially similar to `hexdump -C filename`.