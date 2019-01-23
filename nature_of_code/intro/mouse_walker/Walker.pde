class Walker {
  float x;
  float y;
  
  final int pen_size = 4;
  
  Walker() {
    x = width / 2;
    y = height / 2;
  }
  
  void display() {
    stroke(0);
    strokeWeight(pen_size);
    point(x, y);
  }
  
  void step() {
    // 20% of time choose direction of mouse otherwise random
    x += random(1) < 0.2 ? (mouseX > x ? 4 : -4) : random(-4, 4);
    y += random(1) < 0.2 ? (mouseY > y ? 4 : -4) : random(-4, 4);
  }
}
