### Notes

The **Song** file uses the format <*title*\>!<*artist*\>. The delimiter is a '!' instead of a slash '/'.

For simplicity, the extra *rating* and *bpm* fields and accessor functions were omitted as these fields were not actually used in the example jukebox code. They are in the book examples but aren't used.

These two blocks of code are equivalent:

```Java
public <T extends Foo> void doSomething(ArrayList<T> list)
```

```Java
public void doSomething(ArrayList<? extends Foo> list)
```

Is there an advantage of one over another? Turns out that it depends on whether the **T** is used somewhere else. The upper version might be more readable if **T** is used in several places.

These two blocks of code are also equivalent:

```Java
public <T extends Foo> void doSomething(ArrayList<T> one, ArrayList<T> two)
```

```Javas
public void doSomething(ArrayList<? extends Foo> one, ArrayList<? extends Foo> two)
```