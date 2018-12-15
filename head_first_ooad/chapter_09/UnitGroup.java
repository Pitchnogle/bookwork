import java.util.List;
import java.util.Map;

public class UnitGroup {
  private Map units;

  public UnitGroup(List unitList) {
    units = new HashMap();
    for (Unit unit : unitList) {
      units.put(unit.getId(), unit);
    }
  }

  public UnitGroup() {
    this(new LinkedList());
  }

  public void addUnit(Unit unit) {
    units.put(unit.getId(), unit);
  }

  public void removeUnit(Unit unit) {
    units.remove(unit.getId());
  }

  public void removeUnit(int id) {
    units.remove(id);
  }

  public int getUnit(int id) {
    return (Unit)units.get(id);
  }

  public List getUnits() {
    List unitList = new LinkedList();
    for (Unit unit : units.entrySet()) {
      unitList.add(unit);
    }
    return unitList;
  }
}