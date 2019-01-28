void setup() {
  fullScreen();
  colorMode(HSB);
  noStroke();
}

void draw() {
  // Black background
  background(0);
  
  int i = 0;
  while (i < width) {
    
    float distance = abs(mouseX - i);
    fill(0, 255, 255 - distance);
    rect(i, 0, 10, height);
    
    i += 10;
  }
}
