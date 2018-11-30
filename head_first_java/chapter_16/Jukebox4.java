import java.util.*;
import java.io.*;

// Equivalent to Jukebox6 in the book...

public class Jukebox4 {
  ArrayList<Song> songList = new ArrayList<Song>();

  public static void main(String[] args) {
    Jukebox4 jukebox = new Jukebox4();
    jukebox.go();
  }

  public void go() {
    getSongs();

    System.out.println("Unordered song list:");
    System.out.println(songList);

    System.out.println("Sorted song list:");
    Collections.sort(songList);
    System.out.println(songList);

    System.out.println("Sorted by artist:");
    ArtistCompare artistCompare = new ArtistCompare();
    Collections.sort(songList, artistCompare);
    System.out.println(songList);

    System.out.println("Sorted by artist (duplicates removed):");
    HashSet<Song> songSet = new HashSet<Song>();
    songSet.addAll(songList);
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
