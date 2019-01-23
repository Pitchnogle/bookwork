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
    // Use montecarlo probability to determine step
    float xstep = montecarlo() * 10;
    float ystep = montecarlo() * 10;
    
    x += random(-xstep, xstep);
    y += random(-ystep, ystep);
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
