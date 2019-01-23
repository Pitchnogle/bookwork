int ink = 0; // black

void setup() {
  fullScreen();
  background(255); // white
}

void draw() {
  float mouseSpeed = abs(mouseX - pmouseX);
  strokeWeight(mouseSpeed);
  
  line(pmouseX, pmouseY, mouseX, mouseY);
}

// Flip ink from black<->white on mouse click
void mousePressed() {
  ink = ink == 0 ? 255 : 0;
  stroke(ink);
}
