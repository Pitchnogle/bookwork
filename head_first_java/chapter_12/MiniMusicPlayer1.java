import javax.sound.midi.*;

public class MiniMusicPlayer1 {
  public static void main(String[] args) {
    try {
      Sequencer sequencer = MidiSystem.getSequencer();
      sequencer.open();

      Sequence sequence = new Sequence(Sequence.PPQ, 4);
      Track track = sequence.createTrack();

      for (int i = 5; i < 61; i += 4) {
        track.add(makeEvent(144, 1, i, 100, i));
        track.add(makeEvent(128, 1, i, 100, i + 2));
      }

      sequencer.setSequence(sequence);
      sequencer.setTempoInBPM(220);
      sequencer.start();

      // The book version would hang. This addition was made to have the program automatically
      // quit once the note finished playing.
      while (sequencer.isRunning() == true) {
        Thread.sleep(10);
      }

      sequencer.close();
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
}