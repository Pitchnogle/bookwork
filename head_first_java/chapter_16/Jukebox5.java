import java.util.*;
import java.io.*;

// Equivalent to Jukebox8 in the book...

public class Jukebox5 {
  ArrayList<Song> songList = new ArrayList<Song>();

  public static void main(String[] args) {
    Jukebox5 jukebox = new Jukebox5();
    jukebox.go();
  }

  public void go() {
    getSongs();

    System.out.println("Unordered song list:");
    System.out.println(songList);

    TreeSet<Song> songSet = new TreeSet<Song>();
    songSet.addAll(songList);
    System.out.println("Sorted song set (no duplicates):");
    System.out.println(songSet);
  }

  void getSongs() {
    try {
      File file = new File("duplicates.txt");
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

  class ArtistCompare implements Comparator<Song> {
    public int compare(Song one, Song two) {
      return one.getArtist().compareTo(two.getArtist());
    }
  }
}
