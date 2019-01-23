int[] random_counts;

void setup() {
  //fullScreen(); // slow
  size(800, 400);
  
  random_counts = new int[100];
}

void draw() {
  background(255);
  
  int index = int(random(random_counts.length));
  random_counts[index]++;
  
  stroke(0);
  fill(150);
  int w = width / random_counts.length;
  for (int x = 0; x < random_counts.length; x++) {
    rect(x * w, height - random_counts[x], w - 1, random_counts[x]); 
  }
}
