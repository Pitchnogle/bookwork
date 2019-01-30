class Stripe {
  float x;  // horizontal location of stripe
  float vx; // horizontal velocity
  float w;  // width of stripe
  boolean mouse_over; // is the mouse over the stripe?
  
  Stripe() {
    x = 0;
    vx = random(1);
    w = random(10, 30);
    mouse_over = false;
  }
  
  void display() {
    if (mouse_over) {
      fill(255);
    }
    else {
      fill(255, 100); 
    }
    noStroke();
    rect(x, 0, w, height);
  }
  
  void move() {
    x += vx;
    if (x > width + 20) x -= 20;
  }
  
  void rollover(int mx) {
    // Left edge is x, Right edge is x + w
    if (mx > x && mx < x + w) {
      mouse_over = true; 
    }
    else {
      mouse_over = false; 
    }
  }
}
