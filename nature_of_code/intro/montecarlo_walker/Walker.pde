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
    // Use montecarlo probability to determine step
    float xstep = montecarlo() * 12;
    float ystep = montecarlo() * 12;
    
    x += random(-xstep, xstep);
    y += random(-ystep, ystep);
    
    // The walker can't leave the screen
    constrain(x, 0, width);
    constrain(y, 0, height);
    
    hue += 0.25;
    if (hue >= 255) {
      hue = 0;  
    }
  }
  
  float montecarlo() {
    while (true) {
      float r1 = random(1);
      float prob = r1; // adjust this
      float r2 = random(1);
      if (r2 < prob) {
        return r1; 
      }
    }
  }
}
