Walker w;

void setup() {
  fullScreen();
  background(0);
  colorMode(HSB);
  
  w = new Walker();
}

void draw() {
  w.step();
  w.display();
}
