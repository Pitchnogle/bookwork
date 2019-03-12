This is a simple test to draw out a xy function plot -- a "chirping" sine wave.

In this method, the line() function is called within a loop to draw the sine wave. The time elapsed is computed between the time where the frequency is at its lowest. The chirp frequency increases to the max then decreases back to the min.

It is also possible to initialize the screen using a faster 2D renderer:  
```Java
fullScreen(P2D);
```
