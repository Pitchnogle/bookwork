# Core Java - Vol 1

This folder contains content related to the book [**Core Java Vol. 1, 11th Edition**](https://www.oreilly.com/library/view/core-java-volume/9780135167199/) from O'Reilly.

_Most of my other Java books are grossly out of date. This one is current as of Java 11._

## Notes

### jshell

Java 9 added a new interactive interpreter called _jshell_. This works similar to other interactive interpreters such as _python_.

```
$ jshell
|  Welcome to JShell -- Version 10.0.2
|  For an introduction type: /help intro

jshell> /help intro
|
|                                   intro
|                                   =====
|
|  The jshell tool allows you to execute Java code, getting immediate results.
|  You can enter a Java definition (variable, method, class, etc), like:  int x = 8
|  or a Java expression, like:  x + x
|  or a Java statement or import.
|  These little chunks of Java code are called 'snippets'.
|
|  There are also the jshell tool commands that allow you to understand and
|  control what you are doing, like:  /list
|
|  For a list of commands: /help

jshell> System.out.printf("The ultimate answer to life, the universe, and everything is %d.\n", 7 * 6);
The ultimate answer to life, the universe, and everything is 42.
$1 ==> java.io.PrintStream@6f7fd0e6

jshell> /exit
|  Goodbye
```

- To exit jshell, type ```/ex``` or ```/exit```.

### Class Design Hints

1. _Always keep data private_  
  This is first and foremost; doing anything else violates encapsulation. You may need to  write an accessor or mutator method occasionally, but you are still better off keeping the instance fields private. Bitter experience shows that the data representation may change, but how the data is used will change much less frequently.

2. _Always initialize data_  
  Java won't initialize local variables for you, but it will initialize instance fields or objects. Don't rely on the defaults, but initialize all variables explicitly, either by supplying a default or by setting defaults in all constructors.

3. _Don't use too many basic types in a class_  
  The idea is to replace multiple _related_ uses of basic types with other classes. This keeps your classes easier to understand and change. For example, replace the following instance fields in a _Customer_ class:  
    ```Java
    private String street;
    private String city;
    private String state;
    private int zip;
    ```  
    with a new class called _Address_. This way, you can more easily cope with changes to addresses, such as the need to deal with international addresses.

4. _Not all fields need individual field accessors and mutators_  
  You may need to get and set an employee's salary. You certainly won't need to change the hiring date once the object is constructed. And, quite often, objects have instance fields that you don't want others to get or set, such as an array of state abbreviations in an _Address_ class.

5. _Break up classes that have too many responsibilities_  
  This hint is of course, vague. "Too many" is obviously in the eye of the beholder. Here is an example of a bad design:  
    ```Java
    public class CardDeck { // "bad" design
      private int[] value;
      private int[] card;

      public CardDeck() { ... }
      public void shuffle() { ... }
      public int getTopValue() { ... }
      public int getTopSuit() { ... }
      public void draw() { ... }
    }
    ```  
    This class really implements two separate concepts: a _deck of cards_, with its _shuffle_ and _draw_ methods, and a _card_ with methods to inspect its value and suit.  
    ```Java
    public class CardDeck { // "better" design
      private Card[] cards;

      public CardDeck() { ... }
      public void shuffle() { ... }
      public void getTop() { ... }
      public void draw() { ... }
    }

    public class Card {
      private int value;
      private int suit;

      public Card(int value, int suit) { ... }
      public int getValue() { ... }
      public int getSuit() { ... }
    }
    ```

6. _Make the names of your classes and methods reflect their responsibilities_  
  Just as variables should have meaningful names that reflect what they represent, so should classes. A good convention is that a class name should be a noun (_Order_) or noun proceeded by an adjective (_RushOrder_) or a gerund (an "-ing" word, as in _BillingAddress_). As for methods, follow the standard convention that accessor methods begin with a lowercase _get_ (_getSalary_) and mutator methods use a lowercase _set_ (_setSalary_)

7. _Prefer immutable classes_  
  The problem with mutation is that it can happen concurrently when multiple threads try to update an object at the same time; the results are unpredictable. When classes are immutable, it is safe to share their objects among multiple threads.  

    Therefore, it is a good idea to make classes immutable when you can. This is particularly easy with classes that represent values, such as a string or a point in time. Computations can simply yield new values instead of updating existing ones.  
    
    Of course, not _all_ classes should be immutable.

