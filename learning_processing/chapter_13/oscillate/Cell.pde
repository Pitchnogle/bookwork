class Cell {
  float x;
  float y;
  float w;
  float h;
  
  float angle;
  
  Cell(float x, float y, float w, float h, float angle) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.angle = angle;
  }
  
  void oscillate() {
    angle += 0.2; 
  }
  
  void display() {
    stroke(255);
    float bright = map(sin(angle), -1, 1, 0, 255);
    fill(bright);
    rect(x, y, w, h);
  }
}
