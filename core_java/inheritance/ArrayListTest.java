package inheritance;

import java.util.*;

public class ArrayListTest {
  public static void main(String[] args) {
    // Fill the staff array with three Employee objects
    var staff = new ArrayList<Employee>();
    staff.add(new Employee("Carl Cracker", 75000, 1987, 12, 15));
    staff.add(new Employee("Harry Hacker", 50000, 1989, 10, 1));
    staff.add(new Employee("Tony Tester", 40000, 1990, 3, 15));

    // Raise everyone's salary by 5%
    for (Employee e : staff) {
      e.raiseSalary(5);
    }

    // Print out info about the staff
    for (Employee e : staff) {
      System.out.println(e);
    }
  }
}