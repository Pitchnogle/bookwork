## Notes

### Design Principles  
- Identify the aspects of your application that vary and separate them from what stays the same
- Program to an interface, not an implementation
- Favor composition over inheritance

In this chapter, the SimUDuck application used the **Strategy** design pattern.

The **Strategy** pattern defines a family of algorithms , encapsulates each one, and makes them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

### Compile and run
```
$ javac MiniDuckSimulator.java
$ java MiniDuckSimulator
Quack
I'm flying!
I can't fly
I'm flying with a rocket!
```
