Catcher catcher;
Timer timer;
Drop[] drops;

int total_drops = 0;

void setup() {
  //fullScreen();
  size(800, 450);
  
  catcher = new Catcher(32);
  drops = new Drop[1000];
  
  timer = new Timer(300);
  timer.start();
}

void draw() {
  background(255);
  
  catcher.setLocation(mouseX, mouseY);
  catcher.display();
  
  if (timer.is_finished()) {
    drops[total_drops] = new Drop(random(4, 10));
    total_drops++;
    
    if (total_drops >= drops.length) {
      total_drops = 0; 
    }
    
    timer.start();
  }
  
  for (int i = 0; i < total_drops; i++) {
    drops[i].move();
    drops[i].display();
    if (catcher.intersect(drops[i])) {
      drops[i].caught(); 
    }
  }
}
