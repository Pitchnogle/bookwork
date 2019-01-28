void setup() {
  fullScreen();
  //size(800, 450);
  colorMode(HSB);
  background(0);
}

void draw() {
  // Hue in cyan - violet range
  int hue = (int)random(125, 190);  
  int diameter = (int)random(10);
  int x = (int)random(width);
  int y = (int)random(height);
  
  // Draw a random star per draw
  noStroke();
  fill(hue, 255 - hue, 255);
  ellipse(x, y, diameter, diameter);
}
