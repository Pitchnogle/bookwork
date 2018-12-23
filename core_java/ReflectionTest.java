import java.util.*;
import java.lang.reflect.*;

public class ReflectionTest {
  public static void main(String[] args) throws ReflectiveOperationException {
    // Read class name from the command-line or user input
    String name;
    if (args.length > 0) {
      name = args[0];
    }
    else {
      var in = new Scanner(System.in);
      System.out.println("Enter class name (e.g. java.util.Date): ");
      name = in.next();
    }

    // Print class name and superclass name (if != Object)
    Class cl = Class.forName(name);
    Class supercl = cl.getSuperclass();
    String modifiers = Modifier.toString(cl.getModifiers());
    if (modifiers.length() > 0) {
      System.out.print(modifiers + " ");
    }
    System.out.print("class " + name);
    if (supercl != null && supercl != Object.class) {
      System.out.print(" extends " + supercl.getName());
    }

    System.out.print("\n{\n");
    printConstructors(cl);
    System.out.println();
    printMethods(cl);
    System.out.println();
    printFields(cl);
    System.out.println("}");
  }

  public static void printConstructors(Class cl) {
    Constructor[] constructors = cl.getDeclaredConstructors();

    for (Constructor c : constructors) {
      String name = c.getName();
      System.out.print("   ");
      String modifiers = Modifier.toString(c.getModifiers());
      if (modifiers.length() > 0) {
        System.out.print(modifiers + " ");
      }
      System.out.print(name + "(");

      // Print parameter types
      Class[] paramTypes = c.getParameterTypes();
      for (int i = 0; i < paramTypes.length; i++) {
        if (i > 0) System.out.print(", ");
        System.out.print(paramTypes[i].getName());
      }
      System.out.println(");");
    }
  }

  public static void printMethods(Class cl) {
    Method[] methods = cl.getDeclaredMethods();

    for (Method m : methods) {
      Class retType = m.getReturnType();
      String name = m.getName();

      System.out.print("   ");
      // Print modifiers, return type, and method name
      String modifiers = Modifier.toString(m.getModifiers());
      if (modifiers.length() > 0) {
        System.out.print(modifiers + " ");
      }
      System.out.print(retType.getName() + " " + name + "(");

      // Print parameter types
      Class[] paramTypes = m.getParameterTypes();
      for (int i = 0; i < paramTypes.length; i++) {
        if (i > 0) System.out.print(", ");
        System.out.print(paramTypes[i].getName());
      }
      System.out.println(");");
    }
  }

  public static void printFields(Class cl) {
    Field[] fields = cl.getDeclaredFields();

    for (Field f : fields) {
      Class type = f.getType();
      String name = f.getName();
      System.out.print("   ");
      String modifiers = Modifier.toString(f.getModifiers());
      if (modifiers.length() > 0) {
        System.out.print(modifiers + " ");
      }
      System.out.println(type.getName() + " " + name + ";");
    }
  }
}