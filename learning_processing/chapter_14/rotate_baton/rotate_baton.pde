float theta = 0;

void setup() {
  size(800, 450, P2D);
  
  strokeWeight(4);
  stroke(0, 0, 200);
  fill(0, 0, 200);
}

void draw() {
  background(255);
  
  translate(width / 2, height / 2);
  
  // Rotate by the angle theta
  rotate(theta);
  theta += 0.05;
  
  draw_baton();
}

void draw_baton() {
  beginShape();
  line(-100, 0, 100, 0);
  ellipse(-100, 0, 20, 20);
  ellipse(100, 0, 20, 20);
  endShape();
}
