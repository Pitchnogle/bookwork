import java.awt.*;
import javax.swing.ImageIcon;
import java.awt.geom.AffineTransform;

public class SpriteTest2 {
  public static void main(String[] args) {
    SpriteTest2 test = new SpriteTest2();
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

  private static final long DEMO_TIME = 20000;
  private static final long FADE_TIME = 1000;
  private static final int NUM_SPRITES = 3;

  private ScreenManager screen;
  private Image bgImage;
  private Sprite sprites[];

  public void loadImages() {
    // Load images
    bgImage = loadImage("images/background.png");
    Image player1 = loadImage("images/player1.png");
    Image player2 = loadImage("images/player2.png");
    Image player3 = loadImage("images/player3.png");

    // Create and initialize sprites
    sprites = new Sprite[NUM_SPRITES];
    for (int i = 0; i < NUM_SPRITES; i++) {
      Animation animation = new Animation();
      animation.addFrame(player1, 250);
      animation.addFrame(player2, 150);
      animation.addFrame(player1, 150);
      animation.addFrame(player2, 150);
      animation.addFrame(player3, 200);
      animation.addFrame(player2, 150);

      sprites[i] = new Sprite(animation);

      // Set random starting position
      sprites[i].setX((float)Math.random() * (screen.getWidth() - sprites[i].getWidth()));
      sprites[i].setY((float)Math.random() * (screen.getHeight() - sprites[i].getHeight()));

      // Set random stating velocity
      sprites[i].setVelocityX((float)Math.random() - 0.5f);
      sprites[i].setVelocityY((float)Math.random() - 0.5f);
    }
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

  public void drawFade(Graphics2D g, long currTime) {
    long time = 0;
    if (currTime <= FADE_TIME) {
      time = FADE_TIME - currTime;
    }
    else if (currTime > DEMO_TIME - FADE_TIME) {
      time = FADE_TIME - DEMO_TIME + currTime;
    }
    else {
      return;
    }

    byte numBars = 8;
    int barHeight = screen.getHeight() / numBars;
    int blackHeight = (int)(time * barHeight / FADE_TIME);

    g.setColor(Color.black);
    for (int i = 0; i < numBars; i++) {
      int y = i * barHeight + (barHeight - blackHeight) / 2;
      g.fillRect(0, y, screen.getWidth(), screen.getHeight());
    }
  }

  public void update(long elapsedTime) {
    for (int i = 0; i < NUM_SPRITES; i++) {
      Sprite sprite = sprites[i];

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
  }

  public void draw(Graphics2D g) {
    // Draw the background
    g.drawImage(bgImage, 0, 0, null);

    AffineTransform transform = new AffineTransform();
    for (int i = 0; i < NUM_SPRITES; i++) {
      Sprite sprite = sprites[i];

      // Transform the sprite
      transform.setToTranslation(sprite.getX(), sprite.getY());

      // If the sprite is moving left the flip the image
      if (sprite.getVelocityX() < 0) {
        transform.scale(-1, 1);
        transform.translate(-sprite.getWidth(), 0);
      }

      // Draw it
      g.drawImage(sprite.getImage(), transform, null);
    }
  }
}
