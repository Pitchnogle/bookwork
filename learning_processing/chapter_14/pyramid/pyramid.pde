float theta = 0;

void setup() {
  size(400, 400, P3D);
}

void draw() {
  background(255);
  theta += 0.01;
  
  translate(width / 2, height / 2, 0);
  rotateX(theta);
  rotateY(theta);
  draw_pyramid(50);
  
  translate(100, 100, 20);
  draw_pyramid(10);
}

void draw_pyramid(int t) {
  stroke(0);
  
  beginShape(TRIANGLES);
  
  fill(150, 0, 0, 127);
  vertex(-t, -t, -t);
  vertex( t, -t, -t);
  vertex( 0,  0,  t);
  
  fill(0, 150, 0, 127);
  vertex( t, -t, -t);
  vertex( t,  t, -t);
  vertex( 0,  0,  t);
  
  fill(0, 0, 150, 127);
  vertex( t,  t, -t);
  vertex(-t,  t, -t);
  vertex( 0,  0,  t);
  
  fill(150, 0, 150, 127);
  vertex(-t,  t, -t);
  vertex(-t, -t, -t);
  vertex( 0,  0,  t);
  
  endShape();
}
