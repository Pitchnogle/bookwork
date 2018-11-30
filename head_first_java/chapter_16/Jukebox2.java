import java.util.*;
import java.io.*;

// Equivalent to Jukebox3 in the book...

public class Jukebox2 {
  ArrayList<Song> songList = new ArrayList<Song>();

  public static void main(String[] args) {
    Jukebox2 jukebox = new Jukebox2();
    jukebox.go();
  }

  public void go() {
    getSongs();
    
    System.out.println("Unordered song list:");
    System.out.println(songList);

    System.out.println("Sorted song list:");
    Collections.sort(songList);
    System.out.println(songList);
  }

  void getSongs() {
    try {
      File file = new File("songlist.txt");
      BufferedReader reader = new BufferedReader(new FileReader(file));
      String line = null;
      while ((line = reader.readLine()) != null) {
        addSong(line);
      }
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  void addSong(String s) {
    String[] tokens = s.split("!");
    
    Song nextSong = new Song(tokens[0], tokens[1]);
    songList.add(nextSong);
  }
}
