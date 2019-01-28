int diameter;
int step;

void setup() {
  fullScreen();
  //size(800, 450);
  colorMode(HSB);
  
  diameter = (int)(height * 0.80);
  step = 20;
}

void draw() {
  background(0);
  noStroke();
  
  for (int d = diameter; d > 0; d -= step) {
    float hue = map(d, 0, diameter, 0, 255);
    fill((int)hue, 255, 255);
    ellipse(width / 2, height / 2, d, d);
  }
}
