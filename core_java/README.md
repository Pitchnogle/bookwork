# Core Java - Vol 1

This folder contains content related to the book [**Core Java Vol. 1, 11th Edition**](https://www.oreilly.com/library/view/core-java-volume/9780135167199/) from O'Reilly.

_Most of my other Java books are grossly out of date. This one is current as of Java 11._

## Notes

- To exit jshell, type ```/ex``` or ```/exit```.

### Class Design Hints

1. _Always keep data private_  
  This is first and formost; doing anything else violates encapsulation. You may need to  
  write an accessor or mutator method occasionally, but you are still better off keeping  
  the instance fields private. Bitter experience shows that the data representation may  
  change, but how the data is used will change much less frequently.

2. _Always initialize data_  
  Java won't initialize local variables for you, but it will initialize instance fields  
  or objects. Don't relay on the defaults, but initialize all variables explicitly, either  
  by supplying a default or by setting defaults in all constructors.

3. _Don't use too many basic types in a class_  
  The idea is to replace mutiple _related_ uses of basic types with other classes. This  
  keeps your classes easier to understand and to change. For example, replace the following  
  instance fields in a _Customer_ class:  
  ```Java
  private String street;
  private String city;
  private String state;
  private int zip;
  ```  
  with a new class called _Address_. This way, you can more easily cope with changes to  
  addresses, such as the need to deal with international addresses.

4. _Not all fields need individual field accessors and mutators_  
  You may need to get and set an employee's salary. You certainly won't need to change the  
  hiring date once the object is constructed. And, quite often, objects have instance fields  
  that you don't want others to get or set, such as an array of state abbreviations in a  
  _Address_ class.

