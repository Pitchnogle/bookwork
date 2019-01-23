Walker w;

void setup() {
  fullScreen();
  background(255);
  
  w = new Walker();
}

void draw() {
  w.step();
  w.display();
}
