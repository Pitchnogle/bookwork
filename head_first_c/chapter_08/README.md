## Notes

### Code you can take to the bank
This is the first project in the book which splits out the code into multiple
files.

The initial example code used <> for the checksum and encrypt includes. I didn't
notice that and used "" out of habit, so I didn't encounter the error the book
was trying to get at...

```
$ gcc -Wall -c encrypt.c -o encrypt.o
$ gcc -Wall -c checksum.c -o checksum.o
$ gcc -Wall test_code.c encrypt.o checksum.o -o test_code
$ ./test_code
Encrypted to 'Loz~t?ymvzq{?~q{?zqkzm'
Checksum is 89561741
Decrypted back to 'Speak friend and enter'
Checksum is 89548156
```

To use the <> brackets in the #include lines, we need to put those headers into
the standard locations, such as /usr/local/include

### Make Magnets (pg 361)

```
$ make
gcc -c encrypt.c -o encrypt.o
gcc -c checksum.c -o checksum.o
ar -rcs libhfsecurity.a encrypt.o checksum.o
gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault
```
```
$ ./bank_vault
Encrypted to 'Loz~t?ymvzq{?~q{?zqkzm'
Checksum is 89561741
Decrypted back to 'Speak friend and enter'
Checksum is 89548156
```

### Dynamic Libraries
The final section shows how to make a dynamic library. This section is not as
well structured as the static library section.

To make things easier, I ended up just adding all the hfcal stuff into the
makefile.

Since we are running the test program from the local folder, we need to modify
the LD_LIBRARY_PATH environmental path.
```
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/.
$ ./hfcal_test
Weight: 123.40 lbs
Distance: 1.20 miles
Calories burned: 103.66 cal
```
