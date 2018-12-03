## Notes

This book is quite old by now. At the time of release the current version of Java was 1.4. Java has changed quite a bit since then...

*Currently using OpenJDK 11*

### ThreadPool Example

The primary focus in this chapter is the ThreadPool class. When compiling ThreadPool.java, I got a warning:  
```
javac ThreadPoolTest.java
Note: .\ThreadPool.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
```

To correct for this I changed the linked list declaration to:   
```
private LinkedList<Runnable> taskQueue;
```

Example usage:  
```
java ThreadPoolTest 8 4
Task:3: start
Task:2: start
Task:1: start
Task:0: start
Task:2: end
Task:3: end
Task:1: end
Task:0: end
Task:7: start
Task:6: start
Task:5: start
Task:4: start
Task:7: end
Task:6: end
Task:4: end
Task:5: end
```

Modern Java has its own built in ThreadPool. See this [link](https://howtodoinjava.com/java/multi-threading/java-thread-pool-executor-example/) for more info.
