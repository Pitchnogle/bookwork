Mover m;

void setup() {
  size(800, 450);
  
  m = new Mover();
}

void draw() {
  background(255);
  
  m.update();
  m.check_edges();
  m.display();
}
