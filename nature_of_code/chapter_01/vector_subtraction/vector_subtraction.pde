// Draws a line from the center of the window to the mouse position

void setup() {
  //fullScreen();
  size(800, 450);
}

void draw() {
  background(255);
  
  PVector mouse = new PVector(mouseX, mouseY);
  PVector center = new PVector(width / 2, height / 2);
  
  mouse.sub(center);
  
  translate(width / 2, height / 2);
  stroke(0, 0, 255);
  strokeWeight(4);
  line(0, 0, mouse.x, mouse.y);
}
