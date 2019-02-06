class Ball {
  float r;
  float x;
  float y;
  float vx;
  float vy;
  color c = color(100, 50);
  
  Ball(float r) {
    this.r = r;
    
    x = random(width);
    y = random(height);
    
    vx = random(-5, 5);
    vy = random(-5, 5);
  }
  
  void move() {
    x += vx;
    y += vy;
    
    // Check horizonal edges
    if (x > width || x < 0) {
      vx *= -1; 
    }
    
    // Check vertical edges
    if (y > height || y < 0) {
      vy *= -1; 
    }
  }
  
  void display() {
    stroke(0);
    fill(0, 50);
    ellipse(x, y, 2 * r, 2 * r);
    c = color(100, 50);
  }
  
  void highlight() {
    c = color(0, 150);  
  }
  
  boolean intersect(Ball other) {
    float distance = dist(x, y, other.x, other.y);
    if (distance < r + other.r) {
      return true; 
    }
    else {
      return false; 
    }
  }
}
