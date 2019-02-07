Walker w;

void setup() {
  //fullScreen();
  size(800, 450);
  
  background(0);
  colorMode(HSB);
  
  w = new Walker();
}

void draw() {
  w.step();
  w.display();
}
