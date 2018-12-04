import java.awt.*;
import javax.swing.JFrame;

/*
The SimpleScreenManager class manages initializing and displaying full-screen graphics mode
*/
public class SimpleScreenManager {
  private GraphicsDevice device;

  public SimpleScreenManager() {
    GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
    device = environment.getDefaultScreenDevice();
  }

  public void setFullScreen(DisplayMode displayMode, JFrame frame) {
    frame.setUndecorated(true);
    frame.setResizable(false);

    device.setFullScreenWindow(frame);
    if (displayMode != null && device.isDisplayChangeSupported()) {
      try {
        device.setDisplayMode(displayMode);
      }
      catch (IllegalArgumentException e) {
        // do nothing
      }
    }
  }

  public Window getFullScreenWindow() {
    return device.getFullScreenWindow();
  }

  public void restoreScreen() {
    Window window = device.getFullScreenWindow();
    if (window != null) {
      window.dispose();
    }
    device.setFullScreenWindow(null);
  }
}
