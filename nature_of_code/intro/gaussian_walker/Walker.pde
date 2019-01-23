import java.util.Random;

class Walker {
  float x;
  float y;
  
  Random generator;

  final int pen_size = 4;
  
  Walker() {
    x = width / 2;
    y = height / 2;
    
    generator = new Random();
  }
  
  void display() {
    stroke(0);
    strokeWeight(pen_size);
    point(x, y);
  }
  
  void step() {
    float rx = (float)generator.nextGaussian();
    float ry = (float)generator.nextGaussian();
    
    // The standard deviation is our pen size
    float sd = pen_size;
    
    x += sd * rx; // using zero mean
    y += sd * ry; // using zero mean
  }
}
