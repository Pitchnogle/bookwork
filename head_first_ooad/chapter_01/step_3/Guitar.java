public class Guitar {
  private String serialNumber;
  private double price;
  private GuitarSpec guitarSpec;

  public Guitar(String serialNumber, double price, GuitarSpec guitarSpec) {
    this.serialNumber = serialNumber;
    this.price = price;
    this.guitarSpec;
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

  public GuitarSpec getSpec() {
    return GuitarSpec;
  }  
}
