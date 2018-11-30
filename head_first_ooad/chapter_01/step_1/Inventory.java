import java.util.LinkedList;

import com.sun.org.apache.bcel.internal.generic.ReturnInstruction;

public class Inventory {
  private LinkedList<Guitar> guitars;

  public Inventory() {
    guitars = new LinkedList<Guitar>();
  }

  public void addGuitar(String serialNumber, double price, String builder, String model, String type, String backWood, String topWood) {
    Guitar guitar = new Guitar(serialNumber, price, builder, model, type, backWood, topWood);
    guitars.add(guitar);
  }

  public Guitar getGuitar(String serialNumber) {
    for (Guitar guitar : guitars) {
      if (guitar.getSerialNumber().equals(serialNumber)) {
        return guitar;
      }
    }
    return null;
  }

  public Guitar search(Guitar searchGuitar) {
    for (Guitar guitar : guitars) {
      // Ignore serial# since it's unique
      // Ignore price since that's also unique
      String builder = searchGuitar.getBuilder();
      if (builder != null && !builder.equals("") && !builder.equals(guitar.getBuilder())) {
        continue;
      }
      String model = searchGuitar.getModel();
      if (model != null && !model.equals("") && !model.equals(guitar.getModel())) {
        continue;
      }
      String type = searchGuitar.getType();
      if (type != null && !type.equals("") && !type.equals(guitar.getType())) {
        continue;
      }
      String backWood = searchGuitar.getBackWood();
      if (backWood != null && !backWood.equals("") && !backWood.equals(guitar.getBackWood())) {
        continue;
      }
      String topWood = searchGuitar.getTopWood();
      if (topWood != null && !topWood.equals("") && !topWood.equals(guitar.getTopWood())) {
        continue;
      }

      // The initial book version on page 5 didn't return anything here...
      return guitar;
    }
    return null;
  }
}