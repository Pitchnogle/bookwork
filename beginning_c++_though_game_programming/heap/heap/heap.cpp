// Chapter 9 -- Heap
// Demonstrates dynamically allocating memory

#include <iostream>
using namespace std;

int* int_on_heap();
void leak1();
void leak2();

int main()
{
	int* p_heap = new int;
	*p_heap = 10;
	cout << "*p_heap: " << *p_heap << "\n\n";

	int* p_heap2 = int_on_heap();
	cout << "*p_heap2: " << *p_heap2 << "\n\n";

	cout << "Freeing memory pointed to by p_heap.\n\n";
	delete p_heap;

	cout << "Freeing memory pointed to be p_heap2.\n\n";
	delete p_heap2;

	// Get rid of dangling pointers
	p_heap = 0;
	p_heap2 = 0;

	return 0;
}

int* int_on_heap()
{
	int* p_tmp = new int(20);
	return p_tmp;
}

// These functions are not called, but demonstrate memory leaks

void leak1()
{
	int* drip = new int(30);
	// leak since drip isn't freed
}

void leak2()
{
	int* drip = new int(50);
	// leak here since first int allocated isn't freed
	drip = new int(100);
	delete drip;
}
