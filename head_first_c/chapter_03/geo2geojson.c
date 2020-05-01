/*
This example was inspired by the geo2json presented in the book.

However, the website to view the converted file is dead. I've modified the code
to output basically the same data but using the **GeoJSON** data format. The
result matches the picture from the text.

The **GeoJSON** does coordinates at [longitude, latitude]

The output produced can be pasted to the url:
http://geojson.io/#map=2/20.0/0.0

Here is a reference page for geoJSON:
https://macwright.org/2015/03/23/geojson-second-bite.html
*/
#include <stdio.h>

int main()
{
  float latitude;
  float longitude;
  char info[80];
  int started = 0;

  printf("{\"type\":\"FeatureCollection\",\"features\": [\n");
  while (scanf("%f,%f,%79[^\r\n]", &latitude, &longitude, info) == 3) {
    if (started)
      printf(",\n");
    else
      started = 1;
    
    if (latitude < -90 || latitude > 90) {
      fprintf(stderr, "Invalid latitude: %f\n", latitude);
      return 2;
    }
    if (longitude < -180 || longitude > 180) {
      fprintf(stderr, "Invalid longitude: %f\n", longitude);
      return 2;
    }

    printf("{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[");
    printf("%f, %f]},\"properties\":{\"info\": \"%s\"}}", longitude, latitude, info);
  }
  puts("]}\n");

  return 0;
}