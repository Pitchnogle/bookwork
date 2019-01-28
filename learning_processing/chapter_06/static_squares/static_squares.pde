final int step = 5;

void setup() {
  fullScreen();
  noStroke();
}

void draw() {
  background(0);
  
  for (int x = 0; x < width; x += step) {
    for (int y = 0; y < height; y += step) {
      fill(random(255));
      rect(x, y, step, step);
    }
  }
}
