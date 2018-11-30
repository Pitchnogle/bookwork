public class Guitar {
  private String serialNumber;
  private double price;
  private Builder builder;
  private String model;
  private Type type;
  private Wood backWood;
  private Wood topWood;

  public Guitar(String serialNumber, double price, Builder builder, String model, Type type, Wood backWood, Wood topWood) {
    this.serialNumber = serialNumber;
    this.price = price;
    this.builder = builder;
    this.model = model;
    this.type = type;
    this.backWood = backWood;
    this.topWood = topWood;
  }

  public String getSerialNumber() {
    return serialNumber;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
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