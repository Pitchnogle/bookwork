from sys import argv

script, in_file = argv

def print_all(f):
    print(f.read())

def rewind(f):
    f.seek(0)

def print_a_line(line_count, f):
    print(line_count, f.readline(), end = '')

current_file = open(in_file)

print("First let's print the whole file:")
print_all(current_file)

print("\nNow let's rewind...")
rewind(current_file)

print("\nLet's print three lines:")
print_a_line(1, current_file)
print_a_line(2, current_file)
print_a_line(3, current_file)