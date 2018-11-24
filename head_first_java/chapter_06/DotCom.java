import java.util.*;

public class DotCom {
  private ArrayList<String> locationCells;
  private String name;

  public void setLocationCells(ArrayList<String> locs) {
    locationCells = locs;
  }

  public void setName(String s) {
    name = s;
  }
  
  public String checkYourself(String userGuess) {    
    String result = "miss";

    int index = locationCells.indexOf(userGuess);
    if (index >= 0) {
      locationCells.remove(index);

      if (locationCells.isEmpty()) {
        result = "kill";
      }
      else {
        result = "hit";
      }
    }
    
    return result;
  }
}
