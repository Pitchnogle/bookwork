import java.util.LinkedList;

public class Inventory {
  private LinkedList<Instrument> inventory;

  public Inventory() {
    inventory = new LinkedList<Instrument>();
  }

  public void addInstrument(String serialNumber, double price, InstrumentSpec spec) {
    Instrument instrument = new Instrument(serialNumber, price, spec);
    inventory.add(instrument);
  }

  public Instrument get(String serialNumber) {
    for (Instrument instrument : inventory) {
      if (instrument.getSerialNumber().equals(serialNumber)) {
        return instrument;
      }
    }
    return null;
  }

  public LinkedList<Instrument> search(InstrumentSpec searchSpec) {
    LinkedList<Instrument> matchingInstruments = new LinkedList<Instrument>();

    for (Instrument instrument : inventory) {
      if (instrument.getSpec().matches(searchSpec)) {
        matchingInstruments.add(instrument);
      }
    }
    return matchingInstruments;
  }
}
