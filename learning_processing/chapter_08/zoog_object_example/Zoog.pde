class Zoog {
  // Zoog's variables
  float x;
  float y;
  float w;
  float h;
  float eye_size;
  
  // Constructor
  Zoog(float x, float y, float w, float h, float eye_size) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.eye_size = eye_size;
  }
  
  void jiggle(float speed) {
    // Change the location of this Zoog randomly
    x = x + random(-1, 1) * speed;
    y = y + random(-1, 1) * speed;
    
    // Constrain this Zoog to the window
    x = constrain(x, 0, width);
    y = constrain(y, 0, height);
  }
  
  void display() {
    ellipseMode(CENTER);
    rectMode(CENTER);
    
    // Draw this Zoog's arms
    for (float i = y - h / 3; i < y - h / 2; i += 10) {
      stroke(0);
      line(x - w / 4, i, x + w / 4, i);
    }
    
    // Draw this Zoog's body
    stroke(0);
    fill(175);
    rect(x, y, w / 6, h);
    
    // Draw this Zoog's head
    stroke(0);
    fill(255);
    ellipse(x, y - h, w, h);
    
    // Draw this Zoog's eyes
    fill(0);
    ellipse(x - w / 3, y - h, eye_size, eye_size * 2);
    ellipse(x + w / 3, y - h, eye_size, eye_size * 2);

    // Draw this Zoog's legs
    stroke(0);
    line(x - w / 12, y + h / 2, x - w / 4, y + h / 2 + 10);
    line(x + w / 12, y + h / 2, x + w / 4, y + h / 2 + 10);   
  }
}
