import java.util.LinkedList;

import com.sun.org.apache.bcel.internal.generic.ReturnInstruction;

public class Inventory {
  private LinkedList<Guitar> guitars;

  public Inventory() {
    guitars = new LinkedList<Guitar>();
  }

  public void addGuitar(String serialNumber, double price, Builder builder, String model, Type type, Wood backWood, Wood topWood) {
    Guitar guitar = new Guitar(serialNumber, price, new GuitarSpec(builder, model, type, backWood, topWood));
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

  public LinkedList<Guitar> search(GuitarSpec searchSpec) {
    LinkedList<Guitar> matchingGuitars = new LinkedList<Guitar>();

    for (Guitar guitar : guitars) {
      GuitarSpec guitarSpec = guitar.getSpec();

      // Ignore serial# since it's unique
      // Ignore price since that's also unique
      if (searchSpec.getBuilder() != guitarSpec.getBuilder()) {
        continue;
      }
      String model = searchSpec.getModel().toLowerCase();
      if (model != null && !model.equals("") && !model.equals(guitar.getModel().toLowerCase())) {
        continue;
      }
      if (searchSpec.getType() != guitarSpec.getType()) {
        continue;
      }
      if (searchSpec.getBackWood() != guitarSpec.getBackWood()) {
        continue;
      }
      if (searchSpec.getTopWood() != guitarSpec.getTopWood()) {
        continue;
      }
      
      matchingGuitars.add(guitar);
    }
    return matchingGuitars;
  }
}