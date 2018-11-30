import java.util.*;
import java.io.*;

public class Jukebox1 {
  ArrayList<String> songList = new ArrayList<String>();

  public static void main(String[] args) {
    Jukebox1 jukebox = new Jukebox1();
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
    songList.add(tokens[0]);
  }
}
