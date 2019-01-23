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
    float xstep = random(-pen_size, pen_size);
    float ystep = random(-pen_size, pen_size);
    
    x += xstep;
    y += ystep;
  }
}
