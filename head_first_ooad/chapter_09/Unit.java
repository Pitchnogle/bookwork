import java.util.List;
import java.util.LinkedList;
import java.util.HashMap;

public class Unit {
  private String type;
  private String name;
  private int id;
  private List weapons;
  private HashMap properties;

  public Unit(int id) {
    this.id = id;
  }

  public int getId() {
    return id;
  }

  public void setType(String type) {
    this.type = type;
  }

  public String getType() {
    return type;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  public void addWeapon(Weapon weapon) {
    if (weapons == null) {
      weapons = new LinkedList();
    }
    weapons.add(weapon);
  }

  public List getWeapons() {
    return weapons;
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