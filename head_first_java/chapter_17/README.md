### Notes

### Separate the source code from the build process  

```
MyProject/
├── classes
└── src
```

**Compile with the -d (directory) flag**

```
% cd MyProject/src
% javac -d ../classes MyApp.java
```

or

```
% cd MyProject/src
% javac -d ../classes *.java
```

**Running the code**

```
% cd MyProject/classes
% java MyApp
```

### Put Java into a JAR

1. Make sure all the classes are in the classes directory
2. Create a **manifest.txt** that states which class has the main() method  
   ```
   Main-Class: MyApp
   ```
3. Run the jar tool to create JAR file  
   ```
   % cd MyProject/classes
   % jar -cvmf manifest.txt my_app.jar *.class
   ```
4. Run the JAR file  
   ```
   % java -jar my_app.jar
   ```

### Build Project with Packages

Packages are Java's way of dealing with name possible name conflicts. With packages, it's possible to have multiple classes with the same name. Package typically use a _reverse domain package names_.

The following section uses the directory structure:  
```
MyProject/
├── classes
│   └── com
│       └── bar
│           └── Foo.class
└── src
    └── com
        └── bar
            └── Foo.java
```

To define the package name, add the following line to top of Foo.java:  
```Java
package com.bar;
```

This means _Foo_ is in the package _com.bar.Foo_.

**Compile a package**

```
% cd MyProject/src
% javac -d ../classes com/bar/Foo.java
```

**Run code**

```
% cd MyProject/classes
% java com.bar.Foo
```

**Create a JAR**

1. Make sure to create the **manifest.txt** file:  
  ```
  Main-Class: com.bar.Foo
  ```

2. Create the JAR file  
  ```
  % cd MyProject/classes
  % jar -cvmf manifest.txt MyApp.jar com
  ```

**Execute a JAR**

```
% java -jar MyApp.jar
```
