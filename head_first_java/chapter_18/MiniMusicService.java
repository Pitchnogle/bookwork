import javax.sound.midi.*;
import java.io.*;
import javax.swing.*;
import javax.xml.catalog.Catalog;

import java.awt.*;
import java.awt.event.*;

public class MiniMusicService implements Service {
  MyDrawPanel myPanel;

  public JPanel getGuiPanel() {
    JPanel mainPanel = new JPanel();
    myPanel = new MyDrawPanel();
    JButton playItButton = new JButton("Play it");
    playItButton.addActionListener(new PlayItListener());
    mainPanel.add(myPanel);
    mainPanel.add(playItButton);
    return mainPanel;
  }

  public class PlayItListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      try {
        Sequencer sequencer = MidiSystem.getSequencer();
        sequencer.open();

        sequencer.addControllerEventListener(myPanel, new int[] {127});
        Sequence sequence = new Sequence(Sequence.PPQ, 4);
        Track track = sequence.createTrack();

        for (int i = 0; i < 100; i += 4) {
          int rNum = (int)(Math.random() * 50 + 1);
          if (rNum < 38) {
            track.add(makeEvent(144, 1, rNum, 100, i));
            track.add(makeEvent(176, 1, 127,    0, i));
            track.add(makeEvent(128, 1, rNum, 100, i + 2));
          }
        }

        sequencer.setSequence(sequence);
        sequencer.setTempoInBPM(220);
        sequencer.start();
      }
      catch (Exception ex) {
        ex.printStackTrace();
      }
    }
  }

  public MidiEvent makeEvent(int command, int chan, int one, int two, int tick) {
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

    public Dimension getPreferredSize() {
      return new Dimension(300, 300);
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
