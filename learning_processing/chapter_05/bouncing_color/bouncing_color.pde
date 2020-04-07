float c1 = 0;
float c2 = 255;

float dc1 = 1;
float dc2 = -1;

void setup() {
  //fullScreen(); 
  size(800, 450);
}

void draw() {
  noStroke();
  
  // Draw left rectangle
  fill(c1, 0, c2);
  rect(0, 0, width / 2, height);
  
  // Draw right rectangle
  fill(c2, 0, c1);
  rect(width / 2, 0, width / 2, height);
  
  // Adjust the color values
  c1 += dc1;
  c2 += dc2;
  
  if (c1 < 0 || c1 > 255) {
    dc1 *= -1; 
  }
  
  if (c2 < 0 || c2 > 255) {
    dc2 *= -1; 
  }
}
