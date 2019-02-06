float r = 1;
float theta = 0;

void setup() {
  size(800, 450);
  background(255);
  
}

void draw() {
  translate(width / 2, height / 2);
  
  float x = r * cos(theta);
  float y = r * sin(theta);
  
  noStroke();
  fill(0);
  ellipse(x, y, 16, 16);
  
  theta += 0.01;
  r += 0.05;
}
