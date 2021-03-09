# Create a mapping of state abbreviations
states = {
    'Oregon': 'OR',
    'Florida': 'FL',
    'California': 'CA',
    'New York': 'NY',
    'Montana': 'MT'
}

# Create a basic set of states and some cities in them
cities = {
    'CA': 'San Francisco',
    'MT': 'Bozeman',
    'FL': 'Jacksonville'
}

# Add some more cities
cities['NY'] = 'New York'
cities['OR'] = 'Portland'

# Print out some cities
print('-' * 10)
print('NY state has:', cities['NY'])
print('OR state has:', cities['OR'])

# Print some states
print('-' * 10)
print("Montana's abbreviation is: ", states['Montana'])
print("Florida's abbreviation is: ", states['Florida'])

# Do it by using the state then cities dictionaries
print('-' * 10)
print("Montana has: ", cities[states['Montana']])
print("Florida has: ", cities[states['Florida']])

# Print every state abbreviation
print('-' * 10)
for state, abbrev in list(states.items()):
    print(f"{state} is abbreviated {abbrev}")

# Print every city in state
print('-' * 10)
for abbrev, city in list(cities.items()):
    print(f"{abbrev} has the city {city}")

# Now do both at the same time
print('-' * 10)
for state, abbrev in list(states.items()):
    print(f"{state} is abbreviated {abbrev}")
    print(f"and has the city {cities[abbrev]}")

print('-' * 10)
# Safely get an abbreviation by state that might not be there
state = states.get('Texas')

if not state:
    print("Sorry, no Texas.")

# Get a city with a default value
city = cities.get('TX', 'Does not exist')
print(f"The city for the state 'TX' is: {city}")