public class GuitarSpec {
  private Builder builder;
  private String model;
  private Type type;
  private int numStrings;
  private Wood backWood;
  private Wood topWood;

  public GuitarSpec(Builder builder, String model, Type type,  int numStrings, Wood backWood, Wood topWood) {
    this.builder = builder;
    this.model = model;
    this.type = type;
    this.numStrings = numStrings;
    this.backWood = backWood;
    this.topWood = topWood;
  }
  
  public String getBuilder() {
    return builder.toString();
  }

  public String getModel() {
    return model;
  }

  public String getType() {
    return type.toString();
  }

  public int getNumStrings() {
    return numStrings;
  }

  public String getBackWood() {
    return backWood.toString();
  }

  public String getTopWood() {
    return topWood.toString();
  }

  public boolean matches(GuitarSpec otherSpec) {
    if (builder != otherSpec.builder) {
      return false;
    }
    if (model != null && !model.equals("") && !model.equals(otherSpec.model)) {
      return false;
    }
    if (type != otherSpec.type) {
      return false;
    }
    if (numStrings != otherSpec.numStrings) {
      return false;
    }
    if (backWood != otherSpec.backWood) {
      return false;
    }
    if (topWood != otherSpec.topWood) {
      return false;
    }

    // Found a match
    return true;
  }
}
