public class GuitarSpec {
  private Builder builder;
  private String model;
  private Type type;
  private Wood backWood;
  private Wood topWood;

  public GuitarSpec(Builder builder, String model, Type type, Wood backWood, Wood topWood) {
    this.builder = builder;
    this.model = model;
    this.type = type;
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

  public String getBackWood() {
    return backWood.toString();
  }

  public String getTopWood() {
    return topWood.toString();
  }
}