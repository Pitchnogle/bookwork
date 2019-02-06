class Catcher {
  float r; // radius
  float x; // location
  float y;
  
  Catcher(float r) {
    this.r = r;
    x = 0;
    y = 0;
  }
  
  void setLocation(int x, int y) {
    this.x = x;
    this.y = y;
  }
  
  void display() {
    stroke(0);
    fill(175);
    ellipse(x, y, 2 * r, 2 * r);
  }
  
  boolean intersect(Drop d) {
    float distance = dist(x, y, d.x, d.y);
    if (distance < r + d.r) {
      return true; 
    }
    else {
      return false; 
    }
  }
}
