import java.util.Random;

Random generator;

void setup() {
  size(800, 400);
  background(255);
  
  generator = new Random();
}

void draw() {
  float num = (float)generator.nextGaussian();
  
  float sd = 10; // adjust this
  float mean = width / 2;
  
  float x = sd * num + mean;
  
  noStroke();
  fill(0, 10);
  ellipse(x, height / 2, 32, 32);
}
