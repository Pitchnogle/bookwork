Walker w;

void setup() {
  //fullScreen();
  size(800, 450);
  background(255);
  
  w = new Walker();
}

void draw() {
  w.step();
  w.display();
}
