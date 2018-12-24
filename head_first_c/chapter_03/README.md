## Notes

```
$ gcc -Wall geo2json.c -o geo2json
$ ./geo2json < gpsdata.csv
data=[
{latitude: 42.363400, longitude: -71.098465, info: "Speed = 21"},
{latitude: 42.363327, longitude: -71.097588, info: "Speed = 23"},
{latitude: 42.363255, longitude: -71.096710, info: "Speed = 17"},
{latitude: 42.363182, longitude: -71.095833, info: "Speed = 22"},
{latitude: 42.363110, longitude: -71.094955, info: "Speed = 14"},
{latitude: 42.363037, longitude: -71.094078, info: "Speed = 16"},
{latitude: 42.362965, longitude: -71.093201, info: "Speed = 18"},
{latitude: 42.362892, longitude: -71.092323, info: "Speed = 22"},
{latitude: 42.362820, longitude: -71.091446, info: "Speed = 17"},
{latitude: 42.362747, longitude: -71.090569, info: "Speed = 23"},
{latitude: 42.362675, longitude: -71.089691, info: "Speed = 14"},
{latitude: 42.362602, longitude: -71.088814, info: "Speed = 19"},
{latitude: 42.362530, longitude: -71.087936, info: "Speed = 16"},
{latitude: 42.362457, longitude: -71.087059, info: "Speed = 16"},
{latitude: 42.362385, longitude: -71.086182, info: "Speed = 21"},
{latitude: 29.401320, longitude: -66.027832, info: "Speed = 20"},
{latitude: 29.132971, longitude: -71.136475, info: "Speed = 22"}
]
```

_The book version of the code wasn't working correctly on WSL. The CSV file was created in windows in VS Code, so it added the `CR LF` to the end of the lines. I modified the regex to account for this, which was necessary even though I am using Linux since that's what the file is using._

```
$ gcc -Wall bermuda.c -o bermuda
$ ./bermuda < gpsdata.csv
29.401320,-66.027832,Speed = 20
29.132971,-71.136475,Speed = 22
```

Then, pipe the output of `bermuda` into `geo2json`. The _parentheses_ are necessary in the example below.

```
$ (./bermuda | ./geo2json) < gpsdata.csv
data=[
{latitude: 29.401320, longitude: -66.027832, info: "Speed = 20"},
{latitude: 29.132971, longitude: -71.136475, info: "Speed = 22"}
]
```

The next section demonstrates multiple open files.

```
$ cat spooky.csv
30.685163,-68.137207,Type=Yeti
28.304380,-74.575195,Type=UFO
29.132971,-71.136475,Type=Ship
28.343065,-92.753906,Type=Elvis
27.868217,-68.005371,Type=Goatsucker
30.496017,-73.333740,Type=Disappearance
26.224447,-71.477051,Type=UFO
29.401320,-66.027832,Type=Ship
37.879536,-69.477539,Type=Elvis
22.705256,-68.192139,Type=Elvis
27.166695,-87.484131,Type=Elvis
```

```
$ gcc categorize.c -o categorize
```

Skipping directly to the one which uses command-line arguments.

```
$ ./categorize UFO ufos.csv Elvis elvis.csv others.csv
$ cat ufos.csv
28.304380,-74.575195,Type=UFO
26.224447,-71.477051,Type=UFO
$ cat elvis.csv
28.343065,-92.753906,Type=Elvis
37.879536,-69.477539,Type=Elvis
22.705256,-68.192139,Type=Elvis
27.166695,-87.484131,Type=Elvis
$ cat others.csv
30.685163,-68.137207,Type=Yeti
29.132971,-71.136475,Type=Ship
27.868217,-68.005371,Type=Goatsucker
30.496017,-73.333740,Type=Disappearance
29.401320,-66.027832,Type=Ship
```
