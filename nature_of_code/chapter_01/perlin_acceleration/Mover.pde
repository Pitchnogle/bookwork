class Mover {
  PVector position;
  PVector velocity;
  PVector acceleration;
  
  float top_speed;
  float tx;
  float ty;
  
  Mover() {
    position = new PVector(width / 2, height / 2);
    velocity = new PVector(0, 0);
    
    top_speed = 10;
    tx = 0;
    ty = 10000;
  }
  
  void update() {
    float ax = map(noise(tx), 0, 1, -0.05, 0.05);
    float ay = map(noise(ty), 0, 1, -0.05, 0.05);
    
    tx += 0.02;
    ty += 0.02;
    
    acceleration = new PVector(ax, ay);
    
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
