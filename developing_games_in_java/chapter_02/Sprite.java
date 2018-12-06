import java.awt.Image;

public class Sprite {
  private Animation animation;
  // Position (pixels)
  private float x;
  private float y;
  // Velocity (pixels/millisecond)
  private float dx;
  private float dy;

  public Sprite(Animation animation) {
    this.animation = animation;
  }

  public void update(long elapsedTime) {
    x += dx * elapsedTime;
    y += dy * elapsedTime;
    animation.update(elapsedTime);
  }

  public float getX() {
    return x;
  }

  public float getY() {
    return y;
  }

  public void setX(float x) {
    this.x = x;
  }

  public void setY(float y) {
    this.y = y;
  }

  public int getWidth() {
    return animation.getImage().getWidth(null);
  }

  public int getHeight() {
    return animation.getImage().getHeight(null);
  }

  public float getVelocityX() {
    return dx;
  }

  public float getVelocityY() {
    return dy;
  }

  public void setVelocityX(float dx) {
    this.dx = dx;
  }

  public void setVelocityY(float dy) {
    this.dy = dy;
  }

  public Image getImage() {
    return animation.getImage();
  }
}
