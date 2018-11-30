public class Song implements Comparable<Song> {
  String title;
  String artist;

  Song(String t, String a) {
    title = t;
    artist = a;
  }

  public String getTitle() {
    return title;
  }

  public String getArtist() {
    return artist;
  }

  public String toString() {
    return title;
  }

  public int compareTo(Song s) {
    return title.compareTo(s.getTitle());
  }

  public boolean equals(Object song) {
    Song s = (Song)song;
    return getTitle().equals(s.getTitle());
  }

  public int hashCode() {
    return title.hashCode();
  }
}
