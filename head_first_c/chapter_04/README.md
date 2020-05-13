## Notes

### Programming exercise (pg 165)

```
$ gcc -Wall totaller_orig.c -o totaller_orig
Price of item: 1.23
Total so far: 1.30
Price of item: 4.57
Total so far: 6.15
Price of item: 11.92
Total so far: 18.78
Price of item:
Final total: 18.78
Number of items: 3
```

### Data Sizes Up Close (pg 167)

*The text uses %z for printing sizeof results which produced a warning on WSL.
The code herein substitudes %lu for %z instead.*

```
$ gcc -Wall data_sizes.c -o data_sizes
$ ./data_sizes
The value of INT_MAX is 2147483647
The value of INT_MIN is -2147483648
An int takes 4 bytes
The value of SHRT_MAX is 32767
The value of SHRT_MIN is -32768
A short takes 2 bytes
The value of FLT_MAX is 340282346638528859811704183484516925440.000000
The value of FLT_MIN is 0.00000000000000000000000000000000000001175494350822
The value of FLT_MAX is 3.40282e+38
The value of FLT_MIN is 1.17549e-38
A float takes 4 bytes
```

### Totaller (pg 169)

On page 169, the book code was revised to move the add_with_tax() function below
main(). This causes an issue where the code assumes a different signature than
is used. The C solution is to split function declarations into separate _header_
file than simply declaring the before main() as before.

The reason header are needed is that it's possible to contrive a situation where
code can't be arranged in order.

For example:
```
float ping() {
	...
	pong();
	...
}

float pong() {
	...
	ping();
	...
}
```

For the _Test Drive_ on page 175, we recompile using the separate header.

```
$ gcc -Wall totaller.c -o totaller
$ ./totaller
Price of item: 1.23
Total so far: 1.30
Price of item: 4.57
Total so far: 6.15
Price of item: 11.92
Total so far: 18.78
Price of item:
Final total: 18.78
Number of items: 3
```

### Test Drive (pg 186)

```
$ gcc -Wall message_hider.c encrypt.c -o message_hider
$ ./message_hider
I am a secret message
V?~r?~?lz|mzk?rzll~xz
```

```
$ ./message_hider < encrypt.h
ipv{zq|mfok7|w~m?5rzll~xz6$
```

### Automate your builds with the make tool

The chapter ends with an example of a multifile project where _make_ would prove
useful.

The concept here is that depending on the number of files, compilation could 
take a long time. However, most of the time, it is not necessary to recompile
all the files. The _make_ tool determines whether or not a file should recompile
based on a timestamp.

```
launch.o: launch.c launch.h thruster.h
	gcc -c launch.c

thruster.o: thruster.c thruster.h
	gcc -c thruster.c

launch: launch.o thruster.o
	gcc launch.o thruster.o -o launch
```