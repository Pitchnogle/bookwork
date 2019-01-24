class Mover {
  PVector position;
  PVector velocity;
  
  Mover() {
    position = new PVector(random(width), random(height));
    velocity = new PVector(random(-4, 4), random(-4, 4));
  }
  
  void update() {
    position.add(velocity);
  }
  
  void display() {
    stroke(0);
    strokeWeight(4);
    fill(255, 0, 0);
    ellipse(position.x, position.y, 32, 32);
  }
  
  void check_edges() {
    if (position.x < 0 || position.x > width) {
      velocity.x *= -1; 
    }
    
    if (position.y < 0 || position.y > height) {
      velocity.y *= -1; 
    }
  }
}
