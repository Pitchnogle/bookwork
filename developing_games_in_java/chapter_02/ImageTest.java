import java.awt.*;
import javax.swing.JFrame;
import javax.swing.ImageIcon;

public class ImageTest extends JFrame {
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

    ImageTest test = new ImageTest();
    test.run(displayMode);
  }

  private static final int FONT_SIZE = 24;
  private static final long DEMO_TIME = 20000; // 20 s

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
    loadImages();
    try {
      screen.setFullScreen(displayMode, this);
      try {
        Thread.sleep(DEMO_TIME);
      }
      catch (InterruptedException ex) {}
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

  private Image loadImage(String filename) {
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
      g.drawImage(bgImage, 0, 0, null);
      drawImage(g, opaqueImage, 0, 0, "Opaque");
      drawImage(g, transparentImage, 320, 0, "Transparent");
      drawImage(g, translucentImage, 0, 300, "Translucent");
      drawImage(g, antiAliasedImage, 320, 300, "Translucent (Anti-Aliased)");
    }
    else {
      g.drawString("Loading Images...", 5, FONT_SIZE);
    }
  }

  public void drawImage(Graphics g, Image image, int x, int y, String caption) {
    g.drawImage(image, x, y, null);
    g.drawString(caption, x + 5, y + FONT_SIZE + image.getHeight(null));
  }
}
