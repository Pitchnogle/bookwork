#include <stdio.h>

struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
};

void
catalog(struct fish f)
{
	printf("%s is a %s with %d teeth. He is %d\n",
		f.name, f.species, f.teeth, f.age);
}

void
label(struct fish f)
{
	printf("Name: %s\nSpecies: %s\n%d years old, %d teeth\n",
		f.name, f.species, f.age, f.teeth);
}

int
main()
{
	struct fish snappy = {"Snappy", "Piranha", 69, 4};

	catalog(snappy);
	label(snappy);

	return 0;
}
