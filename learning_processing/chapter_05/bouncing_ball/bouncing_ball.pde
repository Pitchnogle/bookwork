float x = 0;
float y = 0;

float vx = 8;
float vy = 0;

float ax = 0;
float ay = 0.2;

void setup() {
  fullScreen();
}

void draw() {
  background(255);
  
  // Draw the ball
  fill(255, 0, 0);
  noStroke();
  ellipse(x, y, 30, 30);
    
  vx += ax;
  vy += ay;
  
  x += vx;
  y += vy;
  
  // Horizontal wall bounce
  if (x < 0 || x > width) {
    vx *= -1; 
  }

  // Bounce ball off top of window
  if (y < 0) {
    vy *= -1;  
  }
  
  // Dampening bounce at bottom of window
  if (y > height) {
    vy *= -0.9;
    
    y = height;
  }
}

// Wack the ball upwards on mouse pressed
void mousePressed() {
  vy = -12; 
}
