#include <stdio.h>

struct exercise {
	const char *description;
	float duration;
};

struct meal {
	const char *ingredients;
	float weight;
};

struct preferences {
	struct meal food;
	struct exercise exercise;
};

struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct preferences care;
};

void
label(struct fish f)
{
	printf("Name: %s\nSpecies: %s\n%d years old, %d teeth\n",
		f.name, f.species, f.age, f.teeth);
	printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
		f.care.food.weight, f.care.food.ingredients,
		f.care.exercise.description, f.care.exercise.duration);
}

int
main()
{
	struct fish snappy = {
		"Snappy", "Piranha", 69, 4,
		{{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}
	};

	label(snappy);

	return 0;
}