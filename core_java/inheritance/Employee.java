package inheritance;

import java.time.*;

public class Employee {
  private String name;
  private double salary;
  private LocalDate hireDay;

  public Employee(String name, double salary, int year, int month, int day) {
    this.name = name;
    this.salary = salary;
    hireDay = LocalDate.of(year, month, day);
  }

  public String getName() {
    return name;
  }

  public double getSalary() {
    return salary;
  }

  public LocalDate getHireDay() {
    return hireDay;
  }

  public void raiseSalary(double byPercent) {
    double raise = salary * byPercent / 100;
    salary += raise;
  }

  public boolean equals(Object otherObject) {
    // A quick test to see if the objects are identical
    if (this == otherObject) return true;

    // Must return false if the explicit parameter is null
    if (otherObject == null) return false;

    // If the classes don't match, they can't be equal
    if (getClass() != otherObject.getClass()) return false;

    // Now we know otherObject is a non-null Employee
    Employee other = (Employee) otherObject;

    // Test whether the fields have identical values
    return name.equals(other.name) && salary == other.salary && hireDay.equals(other.hireDay);
  }
}