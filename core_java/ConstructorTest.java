import java.util.*;

public class ConstructorTest {
  // BTW -- this is also legal
  //public static void main(String args[])

  public static void main(String[] args) {
    // Fill the staff array with three Employee objects
    var staff = new Employee[3];

    staff[0] = new Employee("Harry", 40000);
    staff[1] = new Employee(60000);
    staff[2] = new Employee();

    for (Employee employee : staff) {
      System.out.println("name=" + employee.getName() + ", id=" + employee.getId() + ", salary=" + employee.getSalary());
    }
  }
}

class Employee {
  private static int nextId;

  private int id;
  private String name = ""; // instance field initialization
  private double salary;

  // Static initialization block
  static {
    var generator = new Random();
    // Set id to a random number between 0 and 9999
    nextId = generator.nextInt(10000);
  }

  // Object initialization block (uncommon technique...)
  {
    id = nextId;
    nextId++;
  }

  public Employee(String name, double salary) {
    this.name = name;
    this.salary = salary;
  }

  public Employee(double salary) {
    this("Employee #" + nextId, salary);
  }

  public Employee() {
    // name initialized to "" -- field initialization
    // salary not explicitly set -- inits to 0
    // id initialized in initialization block
  }

  public String getName() {
    return name;
  }

  public double getSalary() {
    return salary;
  }

  public int getId() {
    return id;
  }
}