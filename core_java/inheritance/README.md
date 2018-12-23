## Notes

```
$ javac inheritance/ManagerTest.java
$ java inheritance.ManagerTest
name=Carl Cracker, salary=85000.0
name=Harry Hacker, salary=50000.0
name=Tommy Tester, salary=40000.0
```

Update using the `toString` method:  

```
$ java inheritance.ManagerTest
inheritance.Manager[name=Carl Cracker,salary=80000.0,hireDay=1987-12-15][bonus=5000.0]
inheritance.Employee[name=Harry Hacker,salary=50000.0,hireDay=1989-10-01]
inheritance.Employee[name=Tommy Tester,salary=40000.0,hireDay=1990-03-15]
```

ArrayListTest:  
```
$ javac inheritance/ArrayListTest.java
$ java inheritance.ArrayListTest
inheritance.Employee[name=Carl Cracker,salary=78750.0,hireDay=1987-12-15]
inheritance.Employee[name=Harry Hacker,salary=52500.0,hireDay=1989-10-01]
inheritance.Employee[name=Tony Tester,salary=42000.0,hireDay=1990-03-15]
```