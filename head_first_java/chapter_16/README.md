### Notes

The **Song** file used the format <title\>!<artist\> instead of the slash (/) as the delimeter.

For simplicity, the extra *rating* and *bpm* fields and accessor functions were omitted as these fields were not actually used in the example jukebox code.

These two blocks of code are equivalent:

```Java
public <T extends Foo> void doSomething(ArrayList<T> list)
```

```Java
public void doSomething(ArrayList<? extends Foo> list)
```
