void setup() {
  size(800, 800);
}

void draw() {
  background(255);
  stroke(0);
  noFill();
  draw_circle(width / 2, height / 2, height / 2);
}

void draw_circle(float x, float y, float r) {
  ellipse(x, y, r, r);
  if (r > 20) {
    draw_circle(x + r / 2, y, r / 2);
    draw_circle(x - r / 2, y, r / 2);
    draw_circle(x, y + r / 2, r / 2);
    draw_circle(x, y - r / 2, r / 2);
  }
}
