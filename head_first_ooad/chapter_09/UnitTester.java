public class UnitTester {
  public static void main(String[] args) {
    UnitTester tester = new UnitTester();
    Unit unit = new Unit(1000);
    tester.testId(unit, 1000);
    tester.testType(unit, "infantry", "infantry");
    tester.testUnitSpecificProperty(unit, "hitPoints", new Integer(25), new Integer(25));
    tester.testChangeProperty(unit, "hitPoints", new Integer(15), new Integer(15));
    tester.testNonExistentProperty(unit, "strength");
    tester.testName(unit, "Bob", "Bob");
  }

  public void testType(Unit unit, String type, String expectedType) {
    System.out.println("\nTesting setting/getting of the type property.");
    unit.setType(type);
    String outputType = unit.getType();
    if (expectedType.equals(outputType)) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed: " + outputType +  "didn't match " + expectedType);
    }
  }

  public void testUnitSpecificProperty(Unit unit, String propertyName, Object inputValue, Object expectedOutputValue) {
    System.out.println("\nTesting setting/getting a unit-speific property.");
    unit.setProperty(propertyName, inputValue);
    Object outputValue = unit.getProperty(propertyName);
    if (expectedOutputValue.equals(outputValue)) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed: " + outputValue +  "didn't match " + expectedOutputValue);
    }
  }

  public void testChangeProperty(Unit unit, String propertyName, Object inputValue, Object expectedOutputValue) {
    System.out.println("\nTesting changing an existing property's value.");
    unit.setProperty(propertyName, inputValue);
    Object outputValue = unit.getProperty(propertyName);
    if (expectedOutputValue.equals(outputValue)) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed: " + outputValue +  "didn't match " + expectedOutputValue);
    }
  }

  public void testNonExistentProperty(Unit unit, String propertyName) {
    System.out.println("\nTesting getting a non-existing property's value.");
    Object outputValue = unit.getProperty(propertyName);
    if (outputValue == null) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed with a value of " + outputValue);
    }
  }

  public void testId(Unit unit, int expectedId) {
    System.out.println("\nTesting getting unit's id");
    int id = unit.getId();
    if (id == expectedId) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed with id of " + id);
    }
  }

  public void testName(Unit unit, String name, String expectedName) {
    System.out.println("\nTesting setting/getting a unit's name.");
    unit.setName(name);
    String outputValue = unit.getName();
    if (expectedName.equals(outputValue)) {
      System.out.println("Test passed");
    }
    else {
      System.out.println("Test failed: " + outputValue +  "didn't match " + expectedName);
    }
  }
}