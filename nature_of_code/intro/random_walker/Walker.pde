class Walker {
  float x;
  float y;
  
  float hue = 0;
  
  final int pen_size = 8;
  
  Walker() {
    x = width / 2;
    y = height / 2;
  }
  
  void display() {
    stroke((int)hue, 255, 255);
    strokeWeight(pen_size);
    point(x, y);
  }
  
  void step() {
    float xstep = random(-pen_size, pen_size);
    float ystep = random(-pen_size, pen_size);
    
    x += xstep;
    y += ystep;
    
    // The walker can't leave the screen
    constrain(x, 0, width);
    constrain(y, 0, height);
    
    hue += 0.25;
    if (hue >= 255) {
      hue = 0;  
    }
  }
}
