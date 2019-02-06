Cell[][] grid;

int cols = 80;
int rows = 45;

void setup() {
  size(800, 450);
  grid = new Cell[cols][rows];
  for (int c = 0; c < cols; c++) {
    for (int r = 0; r < rows; r++) {
      grid[c][r] = new Cell(c * 10, r * 10, 10, 10, r + c);   
    }
  }
}

void draw() {
  background(0);
  for (int c = 0; c < cols; c++) {
    for (int r = 0; r < rows; r++) {
      grid[c][r].oscillate();
      grid[c][r].display();
    }
  }
}
