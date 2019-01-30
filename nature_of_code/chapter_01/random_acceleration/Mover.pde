class Mover {
  PVector position;
  PVector velocity;
  PVector acceleration;
  
  float top_speed;
  
  Mover() {
    position = new PVector(width / 2, height / 2);
    velocity = new PVector(0, 0);
    
    top_speed = 10;
  }
  
  void update() {
    acceleration = PVector.random2D();
    //acceleration.mult(random(2));
    
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
    if (position.x < 0 || position.x > width) {
      velocity.x *= -1; 
    }
    
    if (position.y < 0 || position.y > height) {
      velocity.y *= -1; 
    }
  }
  
  void limit(float max) {
    if (max > velocity.mag()) {
      velocity.setMag(max);
    }
  }
}
