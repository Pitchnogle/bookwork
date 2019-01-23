float xoff = 0.0;

// Our "knobs" are: noiseDetail(), xoff, yoff

void setup() {
  fullScreen();
  
  //noiseDetail(3, 0.8);
}

void draw() {
  loadPixels();
  //float xoff = 0.0; // if we do this the screen won't change
  for (int x = 0; x < width; x++) {
    float yoff = 0.0;
    for (int y = 0; y < height; y++) {
      float bright = map(noise(xoff, yoff), 0, 1, 0, 255);
      pixels[x + y * width] = color(bright);
      yoff += 0.01;
    }
    xoff += 0.005;
  }
  updatePixels();
}
