PVector position;
PVector velocity;

void setup() {
  size(800, 450);
  
  position = new PVector(0, 0);
  velocity = new PVector(3, 5);
}

void draw() {
  background(255);
  
  position.add(velocity);
  
  if (position.x < 0 || position.x > width) {
    velocity.x *= -1; 
  }
  
  if (position.y < 0 || position.y > height) {
    velocity.y *= -1; 
  }
  
  stroke(0);
  strokeWeight(4);
  fill(255, 0, 0);
  ellipse(position.x, position.y, 32, 32);
}
