Zoog zorg;
Zoog bleeg;

void setup() {
  fullScreen();
  //size(800, 450);
  
  zorg = new Zoog(100, 125, 60, 60, 16);
  bleeg = new Zoog(300, 225, 60, 60, 16);
}

void draw() {
  background(255);
  
  // The mouse x position determines speed factor
  float factor = constrain(mouseX / 10, 0, 5);
  
  zorg.jiggle(factor);
  bleeg.jiggle(factor);
  
  zorg.display();
  bleeg.display();
}
