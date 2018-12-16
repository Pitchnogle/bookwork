import java.io.*;

public class SubwayLoader {
  private Subway subway;

  public SubwayLoader() {
    subway = new Subway();
  }

  public Subway loadFromFile(File subwayFile) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(subwayFile));

    loadStations(subway, reader);
    String lineName = reader.readLine();
    while (lineName != null && lineName.length() > 0) {
      loadLine(subway, reader, lineName);
      lineName = reader.readLine();
    }

    return subway;
  }

  private void loadStations(Subway subway, BufferedReader reader) throws IOException {
    String currentLine;
    currentLine = reader.readLine();
    while (currentLine.length() > 0) {
      //System.out.println("add station:" +  currentLine);
      subway.addStation(currentLine);
      currentLine = reader.readLine();
    }
  }

  private void loadLine(Subway subway, BufferedReader reader, String lineName) throws IOException {
    String stationName1;
    String stationName2;
    stationName1 = reader.readLine();
    stationName2 = reader.readLine();
    while (stationName2 != null && stationName2.length() > 0) {
      subway.addConnection(stationName1, stationName2, lineName);
      stationName1 = stationName2;
      stationName2 = reader.readLine();
    }
  }
}