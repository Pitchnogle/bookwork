the_count = [1, 2, 3, 4, 5]
fruits = ['apples', 'oranges', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

# This first kind of for-loop goes through a list
for number in the_count:
    print(f"This is count {number}")

# Same as above
for fruit in fruits:
    print(f"A fruit of type {fruit}")

# Also, we go go through mixed lists
for i in change:
    print(f"I got {i}")

# We can also build lists, first start with an empty one
elements = []

# Then use the range function to do 0 to 5 counts
for i in range(0, 6):
    print(f"Adding {i} to the list.")
    # Append is a function that lists understand
    elements.append(i)

# Now we can print the elements
for i in elements:
    print(f"Element was: {i}")
