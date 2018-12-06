import java.awt.*;
import javax.swing.ImageIcon;

public class AnimationTest2 {
  public static void main(String[] args) {
    AnimationTest2 test = new AnimationTest2();
    test.run();
  }

  private static final DisplayMode POSSIBLE_MODES[] = {
    new DisplayMode(1920, 1080, 32, 0),
    new DisplayMode(1920, 1080, 24, 0),
    new DisplayMode(1920, 1080, 16, 0),
    new DisplayMode(800, 600, 32, 0),
    new DisplayMode(800, 600, 24, 0),
    new DisplayMode(800, 600, 16, 0),
    new DisplayMode(640, 480, 32, 0),
    new DisplayMode(640, 480, 24, 0),
    new DisplayMode(640, 480, 16, 0)
  };

  private static final long DEMO_TIME = 10000;

  private ScreenManager screen;
  private Image bgImage;
  private Animation animation;

  public void loadImages() {
    // Load images
    bgImage = loadImage("images/background.png");
    Image player1 = loadImage("images/player1.png");
    Image player2 = loadImage("images/player2.png");
    Image player3 = loadImage("images/player3.png");

    // Create animation
    animation = new Animation();
    animation.addFrame(player1, 250);
    animation.addFrame(player2, 150);
    animation.addFrame(player1, 150);
    animation.addFrame(player2, 150);
    animation.addFrame(player3, 200);
    animation.addFrame(player2, 150);
  }

  private Image loadImage(String filename) {
    return new ImageIcon(filename).getImage();
  }

  public void run() {
    screen = new ScreenManager();
    try {
      DisplayMode displayMode = screen.findFirstCompatibleMode(POSSIBLE_MODES);
      screen.setFullScreen(displayMode);
      loadImages();
      animationLoop();
    }
    finally {
      screen.restoreScreen();
    }
  }

  public void animationLoop() {
    long startTime = System.currentTimeMillis();
    long currTime = startTime;

    while (currTime - startTime < DEMO_TIME) {
      long elapsedTime = System.currentTimeMillis() - currTime;
      currTime += elapsedTime;

      // Update animation
      animation.update(elapsedTime);

      // Draw to the screen
      Graphics g = screen.getGraphics();
      draw(g);
      g.dispose();
      screen.update();

      // Take a nap
      try {
        Thread.sleep(20);
      }
      catch (InterruptedException e) {
        // do nothing
      }
    }
  }

  public void draw(Graphics g) {
    // Draw the background
    g.drawImage(bgImage, 0, 0, null);

    // Draw an animated frame
    g.drawImage(animation.getImage(), 0, 0, null);
  }
}
