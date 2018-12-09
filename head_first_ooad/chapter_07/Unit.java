import java.util.HashMap;

public class Unit {
  private String type;
  private HashMap properties;

  public Unit() {

  }

  public void setType(String type) {
    this.type = type;
  }

  public String getType() {
    return type;
  }

  public void setProperty(String property, Object value)
  {
    if (properties == null) {
      properties = new HashMap();
    }
    properties.put(property, value);
  }
  
  public Object getProperty(String property) {
    if (properties == null) {
      return null;
    }
    return properties.get(property);
  }

}