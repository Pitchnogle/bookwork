import java.awt.*;
import javax.swing.ImageIcon;

public class SpriteTest1 {
  public static void main(String[] args) {
    SpriteTest1 test = new SpriteTest1();
    test.run();
  }

  private static final DisplayMode POSSIBLE_MODES[] = {
    new DisplayMode(1920, 1080, 32, 0),
    new DisplayMode(1920, 1080, 24, 0),
    new DisplayMode(1920, 1080, 16, 0),
    new DisplayMode(800, 600, 32, 0),
    new DisplayMode(800, 600, 24, 0),
    new DisplayMode(800, 600, 16, 0)
  };

  private static final long DEMO_TIME = 10000;

  private ScreenManager screen;
  private Image bgImage;
  private Sprite sprite;

  public void loadImages() {
    // Load images
    bgImage = loadImage("images/background.png");
    Image player1 = loadImage("images/player1.png");
    Image player2 = loadImage("images/player2.png");
    Image player3 = loadImage("images/player3.png");

    // Create animation
    Animation animation = new Animation();
    animation.addFrame(player1, 250);
    animation.addFrame(player2, 150);
    animation.addFrame(player1, 150);
    animation.addFrame(player2, 150);
    animation.addFrame(player3, 200);
    animation.addFrame(player2, 150);

    sprite = new Sprite(animation);
    sprite.setVelocityX(0.3f);
    sprite.setVelocityY(0.2f);
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

      // Update the sprites
      update(elapsedTime);

      // Draw and update the screen
      Graphics2D g = screen.getGraphics();
      draw(g);
      g.dispose();
      screen.update();

      // Take a nap
      try {
        Thread.sleep(20);
      }
      catch (InterruptedException e) { }
    }
  }

  public void update(long elapsedTime) {
    // Check sprite bounds
    if (sprite.getX() < 0) {
      sprite.setVelocityX(Math.abs(sprite.getVelocityX()));
    }
    else if (sprite.getX() + 2 * sprite.getWidth() >= screen.getWidth()) {
      sprite.setVelocityX(-Math.abs(sprite.getVelocityX()));
    }
    if (sprite.getY() < 0) {
      sprite.setVelocityY(Math.abs(sprite.getVelocityY()));
    }
    else if (sprite.getY() + 2 * sprite.getHeight() >= screen.getHeight()) {
      sprite.setVelocityY(-Math.abs(sprite.getVelocityY()));
    }

    // Update sprite
    sprite.update(elapsedTime);
  }

  public void draw(Graphics g) {
    // Draw the background
    g.drawImage(bgImage, 0, 0, null);

    // Draw the sprite
    g.drawImage(sprite.getImage(), Math.round(sprite.getX()), Math.round(sprite.getY()), null);
  }
}
