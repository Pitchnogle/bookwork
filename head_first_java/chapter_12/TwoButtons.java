import java.awt.BorderLayout;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import java.awt.*;

public class TwoButtons {
  JFrame frame;
  JLabel label;

  public static void main(String[] args) {
    TwoButtons gui = new TwoButtons();
    gui.go();
  }

  public void go() {
    frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JButton labelButton = new JButton("Change Label");
    labelButton.addActionListener(new LabelListener());

    JButton colorButton = new JButton("Change Circle");
    colorButton.addActionListener(new ColorListener());

    label = new JLabel("I'm a label");
    MyDrawPanel drawPanel = new MyDrawPanel();

    frame.getContentPane().add(BorderLayout.SOUTH, colorButton);
    frame.getContentPane().add(BorderLayout.CENTER, drawPanel);
    frame.getContentPane().add(BorderLayout.EAST, labelButton);
    frame.getContentPane().add(BorderLayout.WEST, label);

    frame.setSize(300, 300);
    frame.setVisible(true);
  }

  class LabelListener implements ActionListener {
    public void actionPerformed(ActionEvent event) {
      label.setText("Ouch!");
    }
  }

  class ColorListener implements ActionListener {
    public void actionPerformed(ActionEvent event) {
      frame.repaint();
    }
  }

  class MyDrawPanel extends JPanel {
    public void paintComponent(Graphics g) {
      Graphics2D g2d = (Graphics2D)g;
  
      int red = (int)(Math.random() * 256);
      int green = (int)(Math.random() * 256);
      int blue = (int)(Math.random() * 256);
      Color startColor = new Color(red, green, blue);
  
      red = (int)(Math.random() * 256);
      green = (int)(Math.random() * 256);
      blue = (int)(Math.random() * 256);
      Color endColor = new Color(red, green, blue);
  
      GradientPaint gradient = new GradientPaint(70, 70, startColor, 150, 150, endColor);
      g2d.setPaint(gradient);
      g2d.fillRect(0, 0, frame.getWidth(), frame.getHeight());
    }
  }
}