class Mover {
  PVector position;
  PVector velocity;
  PVector acceleration;
  
  float top_speed;
  float tx;
  float ty;
  
  Mover() {
    position = new PVector(random(width), random(height));
    velocity = new PVector(0, 0);
    
    top_speed = 10;
    tx = 0;
    ty = 10000;
  }
  
  void update() {
    PVector mouse = new PVector(mouseX, mouseY);
    PVector dir = PVector.sub(mouse, position);
    dir.normalize();
    dir.mult(0.5);
    
    acceleration = dir;
    
    velocity.add(acceleration);
    velocity.limit(top_speed);
    
    position.add(velocity);
  }
  
  void display() {
    stroke(0);
    strokeWeight(4);
    fill(255, 0, 0);
    ellipse(position.x, position.y, 32, 32);
  }
  
  void check_edges() {
    if (position.x > width) {
      position.x = 0;
    }
    else if (position.x < 0) {
      position.x = width;
    }
    
    if (position.y > height) {
      position.y = 0;
    }
    else if (position.y < 0) {
      position.y = height;
    }
  }
  
  void limit(float max) {
    if (max > velocity.mag()) {
      velocity.setMag(max);
    }
  }
}
