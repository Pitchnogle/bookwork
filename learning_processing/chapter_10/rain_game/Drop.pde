class Drop {
  float x;
  float y;
  float vy;
  color c;
  float r;
  
  Drop(int r) {
    this.r = r;
    x = random(width);
    y = -4 * r;
    vy = random(1, 5);
    c = color(50, 100, 150);
  }
  
  void move() {
    y += vy; 
  }
  
  void caught() {
    vy = 0;
    y = -1000;
  }
  
  void display() {
    noStroke();
    fill(c);
    for (int i = 2; i < r; i++) {
      ellipse(x, y + 4 * i, 2 * i, 2 * i); 
    }
  }
}
