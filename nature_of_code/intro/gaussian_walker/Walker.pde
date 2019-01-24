import java.util.Random;

class Walker {
  float x;
  float y;
  
  float hue = 0;
  
  Random generator;

  final int pen_size = 8;
  final int step_size = 4;
  
  Walker() {
    x = width / 2;
    y = height / 2;
    
    generator = new Random();
  }
  
  void display() {
    stroke((int)hue, 255, 255);
    strokeWeight(pen_size);
    point(x, y);
  }
  
  void step() {
    float rx = (float)generator.nextGaussian();
    float ry = (float)generator.nextGaussian();
    
    // The standard deviation is our pen size
    float sd = step_size;
    
    x += sd * rx; // using zero mean
    y += sd * ry; // using zero mean
    
    // The walker can't leave the screen
    constrain(x, 0, width);
    constrain(y, 0, height);
    
    hue += 0.25;
    if (hue >= 255) {
      hue = 0;  
    }
  }
}
