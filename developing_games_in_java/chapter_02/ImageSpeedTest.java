import java.awt.*;
import javax.swing.JFrame;
import javax.swing.ImageIcon;

public class ImageSpeedTest extends JFrame {
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
      displayMode = new DisplayMode(800, 600, 16, DisplayMode.REFRESH_RATE_UNKNOWN);
    }

    ImageSpeedTest test = new ImageSpeedTest();
    test.run(displayMode);
  }

  private static final int FONT_SIZE = 24;
  private static final long TIME_PER_IMAGE = 1500;

  private SimpleScreenManager screen;
  private Image bgImage;
  private Image opaqueImage;
  private Image transparentImage;
  private Image translucentImage;
  private Image antiAliasedImage;
  private boolean imagesLoaded;

  public void run(DisplayMode displayMode) {
    setBackground(Color.blue);
    setForeground(Color.white);
    setFont(new Font("Dialog", Font.PLAIN, FONT_SIZE));
    imagesLoaded = false;

    screen = new SimpleScreenManager();
    try {
      screen.setFullScreen(displayMode, this);
      synchronized (this) {
        loadImages();
        // Wait for test to complete
        try {
          wait();
        }
        catch (InterruptedException ex) {}
      }
    }
    finally {
      screen.restoreScreen();
    }
  }

  public void loadImages() {
    bgImage = loadImage("images/background.jpg");
    opaqueImage = loadImage("images/opaque.png");
    transparentImage = loadImage("images/transparent.png");
    translucentImage = loadImage("images/translucent.png");
    antiAliasedImage = loadImage("images/antialiased.png");
    imagesLoaded = true;

    // Signal awt to repaint this window
    repaint();
  }

  private final Image loadImage(String filename) {
    return new ImageIcon(filename).getImage();
  }

  public void paint(Graphics g) {
    // Set text anti-aliasing
    if (g instanceof Graphics2D) {
      Graphics2D g2d = (Graphics2D)g;
      g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
    }

    // Draw images
    if (imagesLoaded) {
      drawImage(g, opaqueImage, "Opaque");
      drawImage(g, transparentImage, "Transparent");
      drawImage(g, translucentImage, "Translucent");
      drawImage(g, antiAliasedImage, "Translucent (Anti-Aliased)");

      // Notify that the test is complete
      synchronized (this) {
        notify();
      }
    }
    else {
      g.drawString("Loading Images...", 5, FONT_SIZE);
    }
  }

  public void drawImage(Graphics g, Image image, String name) {
    int w = screen.getFullScreenWindow().getWidth() - image.getWidth(null);
    int h = screen.getFullScreenWindow().getWidth() - image.getHeight(null);
    int numImages = 0;

    g.drawImage(bgImage, 0, 0, null);

    long startTime = System.currentTimeMillis();
    while (System.currentTimeMillis() - startTime < TIME_PER_IMAGE) {
      int x = Math.round((float)Math.random() * w);
      int y = Math.round((float)Math.random() * h);
      g.drawImage(image, x, y, null);
      numImages++;
    }
    long time = System.currentTimeMillis() - startTime;
    float speed = numImages * 1000f / time;
    System.out.println(name + ": " + speed + " images/second");
  }
}
