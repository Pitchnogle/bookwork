import java.awt.*;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class AnimationTest1 {
  public static void main(String[] args) {
    DisplayMode displayMode;

    if (args.length == 3) {
      displayMode = new DisplayMode(
        Integer.parseInt(args[0]),
        Integer.parseInt(args[1]),
        Integer.parseInt(args[2]),
        DisplayMode.REFRESH_RATE_UNKNOWN);
    }
    else {
      displayMode = new DisplayMode(1920, 1080, 32, DisplayMode.REFRESH_RATE_UNKNOWN);
    }

    AnimationTest1 test = new AnimationTest1();
    test.run(displayMode);
  }

  private static final long DEMO_TIME = 10000;

  private SimpleScreenManager screen;
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

  public void run(DisplayMode displayMode) {
    screen = new SimpleScreenManager();
    try {
      screen.setFullScreen(displayMode, new JFrame());
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
      Graphics g = screen.getFullScreenWindow().getGraphics();
      draw(g);
      g.dispose();

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
