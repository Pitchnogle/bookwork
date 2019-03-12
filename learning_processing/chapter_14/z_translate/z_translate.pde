float z = 0;

void setup() {
  size(800, 450, P3D);
}

void draw() {
  background(0);
  stroke(255);
  fill(100);
  
  translate(width / 2, height / 2, z);
  rectMode(CENTER);
  rect(0, 0, 8, 8);
  
  z++;
}
