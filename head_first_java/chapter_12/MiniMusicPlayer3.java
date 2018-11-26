import javax.sound.midi.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;

public class MiniMusicPlayer3 {
  static JFrame frame = new JFrame("My First Music Video");
  static MyDrawPanel panel;

  public static void main(String[] args) {
    MiniMusicPlayer3 mini = new MiniMusicPlayer3();
    mini.go();
  }

  public void setupGui() {
    panel = new MyDrawPanel();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setContentPane(panel);
    frame.setBounds(30, 30, 300, 300);
    frame.setVisible(true);
  }

  public void go() {
    setupGui();

    try {
      Sequencer sequencer = MidiSystem.getSequencer();
      sequencer.open();
      sequencer.addControllerEventListener(panel, new int[] {127});

      Sequence sequence = new Sequence(Sequence.PPQ, 4);
      Track track = sequence.createTrack();

      int r = 0;
      for (int i = 0; i < 60; i += 4) {
        r = (int)(Math.random() * 50 + 1);
        track.add(makeEvent(144, 1, r, 100, i));
        track.add(makeEvent(176, 1, 127, 0, i));
        track.add(makeEvent(128, 1, r, 100, i + 2));
      }

      sequencer.setSequence(sequence);
      sequencer.setTempoInBPM(220);
      sequencer.start();
    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  public static MidiEvent makeEvent(int command, int chan, int one, int two, int tick) {
    MidiEvent event = null;
    try {
      ShortMessage msg = new ShortMessage();
      msg.setMessage(command, chan, one, two);
      event = new MidiEvent(msg, tick);
    }
    catch (Exception e) {
      // do nothing
    }
    return event;
  }

  class MyDrawPanel extends JPanel implements ControllerEventListener {
    boolean msg = false;

    public void controlChange(ShortMessage event) {
      msg = true;
      repaint();
    }

    public void paintComponent(Graphics g) {
      if (msg) {
        Graphics2D g2d = (Graphics2D)g;
  
        int red = (int)(Math.random() * 250);
        int green = (int)(Math.random() * 250);
        int blue = (int)(Math.random() * 250);
        g.setColor(new Color(red, green, blue));

        int h = (int)(Math.random() * 120 + 10);
        int w = (int)(Math.random() * 120 + 10);
        int x = (int)(Math.random() * 40 + 10);
        int y = (int)(Math.random() * 40 + 10);
        g.fillRect(x, y, w, h);

        msg = false;
      }
    }
  }
}