package inheritance;

public class ManagerTest {
  public static void main(String[] args) {
    var boss = new Manager("Carl Cracker", 80000, 1987, 12, 15);
    boss.setBonus(5000);

    var staff = new Employee[3];

    staff[0] = boss;
    staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
    staff[2] = new Employee("Tommy Tester", 40000, 1990, 3, 15);

    for (Employee employee : staff) {
      // Book example
      //System.out.println("name=" + employee.getName() + ", salary=" + employee.getSalary());

      // Use toString()
      System.out.println(employee);
    }


  }
}