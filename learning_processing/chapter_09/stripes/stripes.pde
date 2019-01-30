Stripe[] stripes = new Stripe[10];

void setup() {
  //fullScreen();
  size(800, 450);
  
  for (int i = 0; i < stripes.length; i++) {
    stripes[i] = new Stripe();
  }
}

void draw() {
  background(10);
  
  // Move and display all stripes
  for (int i = 0; i < stripes.length; i++) {
    stripes[i].rollover(mouseX);
    stripes[i].move();
    stripes[i].display();
  }
}
