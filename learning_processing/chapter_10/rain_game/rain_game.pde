Catcher catcher;

void setup() {
  //fullScreen();
  size(800, 450);
  
  catcher = new Catcher(32);
}

void draw() {
  background(255);
  
  catcher.setLocation(mouseX, mouseY);
  catcher.display();
}
