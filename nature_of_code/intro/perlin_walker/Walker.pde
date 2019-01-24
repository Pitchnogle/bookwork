class Walker {
  float x;
  float y;
  float tx;
  float ty;
  
  float hue = 0;
  
  final int pen_size = 8;
  
  Walker() {
    x = width / 2;
    y = height / 2;
    
    tx = 0;
    ty = 10000;
  }
  
  void display() {
    stroke((int)hue, 255, 255);
    strokeWeight(pen_size);
    point(x, y);
  }
  
  void step() {
    x = map(noise(tx), 0, 1, 0, width);
    y = map(noise(ty), 0, 1, 0, height);
    
    tx += 0.01;
    ty += 0.01;
    
    hue += 0.25;
    if (hue >= 255) {
      hue = 0;  
    }
  }
}
