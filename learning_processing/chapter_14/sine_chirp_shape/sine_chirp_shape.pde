float wave[];

final float FMIN = 1;
final float FMAX = 40;

float freq = FMIN;
float fadjust = 1;

int start = millis();

void setup() {
  //size(800, 450);
  fullScreen();
  
  wave = new float[width];
}

void draw() {
  background(0);
  stroke(255, 0, 0);
  
  update(freq, width);
  
  freq += fadjust;
  if (freq == FMAX) fadjust = -1;
  if (freq == FMIN) {
    int stop = millis();
    println("elapsed = " + (stop - start));
    fadjust =  1;
    start = millis();
  }
  
  draw_wave();
}

void update(float freq, int n) {
  for (int i = 0; i < n; i++) {
    float tmp = sin(2 * PI * i * freq / n);
    wave[i] = (1.0 + tmp) * height / 2;
  }
}

void draw_wave() {
  noFill();
  
  beginShape(LINES);
  for (int i = 1; i < width; i++) {
    vertex(i - 1, wave[i - 1]);
    vertex(i,     wave[i]); 
  }
  endShape();
}
