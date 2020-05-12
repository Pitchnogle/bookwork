#include <stdio.h>
#include <string.h>

char tracks[][80] = {
	"Fox on the Run",
	"Sunglasses at Night",
	"Dr. Feelgood",
	"Rock of Ages",
	"Billie Jean"
};

void
find_track(char search_for[])
{
	int i;
	for (i = 0; i < 5; i++)
		if (strstr(tracks[i], search_for))
			printf("Track %i: '%s'\n", i, tracks[i]);
}

int
main()
{
	char search_for[80];
	printf("Search for: ");
	fgets(search_for, 80, stdin);

	// Book version has a bug. This fixes it...
	search_for[strlen(search_for) - 1] = '\0';

	find_track(search_for);

	return 0;
}
