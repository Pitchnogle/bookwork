Mover mover;

void setup() {
  size(800, 400);
  
  mover = new Mover();
}

void draw() {
  background(255);
  
  mover.update();
  mover.check_edges();
  mover.display();
}
