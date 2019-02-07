Mover mover;

void setup() {
  size(800, 450);
  
  mover = new Mover();
}

void draw() {
  background(255);
  
  mover.update();
  mover.check_edges();
  mover.display();
}
