import java.util.List;
import java.util.LinkedList;

public class Subway {
  private List stations;
  private List connections;

  public Subway() {
    stations = new LinkedList();
    connections = new LinkedList();
  }

  public void addStation(String stationName) {
    if (!this.hasStation(stationName)) {
      Station station = new Station(stationName);
      stations.add(station);
    }
  }

  public boolean hasStation(String stationName) {
    return stations.contains(new Station(stationName));
  }

  public void addConnection(String stationName1, String stationName2, String lineName) {
    if (this.hasStation(stationName1) && this.hasStation(stationName2)) {
      Station station1 = new Station(stationName1);
      Station station2 = new Station(stationName2);
      Connection connection = new Connection(station1, station2, lineName);
      connections.add(connection);
      connections.add(new Connection(station2, station1, connection.getLineName()));
    }
    else {
      throw new RuntimeException("Invalid connection");
    }
  }
}