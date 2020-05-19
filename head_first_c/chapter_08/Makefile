all: bank_vault libhfsecurity.a encrypt.o checksum.o hfcal.o libhfcal.so hfcal_test

# Static library example
encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o

checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_vault: bank_vault.c libhfsecurity.a
	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault

# Dynamic library example
hfcal.o: hfcal.c
	gcc -c hfcal.c -I. -o hfcal.o

libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o libhfcal.so

hfcal_test: hfcal_test.c
	gcc -c hfcal_test.c -I. -o hfcal_test.o
	gcc hfcal_test.o -L. -lhfcal -o hfcal_test

clean:
	rm *.o libhfsecurity.a bank_vault libhfcal.so hfcal_test