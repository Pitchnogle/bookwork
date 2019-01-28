int diameter;

void setup() {
  fullScreen();
  colorMode(HSB);
  
  diameter = height / 2;
}

void draw() {
  background(0);
  noStroke();
  
  float d = distance(width / 2, height / 2, mouseX, mouseY);
  
  float hue = map(d, 0, diameter / 2, 0, 255);
  fill(hue, 255, 255);
  ellipseMode(CENTER);
  ellipse(width / 2, height / 2, diameter, diameter);
}

float distance(float x1, float y1, float x2, float y2) {
  float dx = x1 - x2;
  float dy = y1 - y2;
  float d = sqrt(dx * dx + dy * dy);
  return d;
}
