## Notes

### Making the Remote Server

There are a number of steps necessary to make the remote service.

1. Make a Remote Interface  
  1. Extend java.rmi.Remote  
    ```Java
    public interface MyRemote extends Remote {
    ```
  2. Declare that all methods _throw a remote exception_  
    ```Java
    import java.rmi.*;

    public interface MyRemote extends Remote {
      public String sayHello() throws RemoteException;
    }
    ```
  3. Be sure arguments and return values are primitives or Serializable  
    ```Java
    public String sayHello() throws RemoteException;
    ```

2. Make a Remote Implementation  
  1. Implement a remote interface  
    ```Java
    public class MyRemoteImpl extends UnicastRemoteObject implements MyRemote {
      public String sayHello() {
        return "server says, 'Hey'";
      }
    }
    ```
  2. Extend UnicastRemoteObject  
    ```Java
    public class MyRemoteImpl extends UnicastRemoteObject implements MyRemote {
    ```
  3. Write a no-arg constructor that declares a RemoteException  
    ```Java
    public MyRemoteImpl() throws RemoteException {}
    ```
  4. Register the service with the RMI registry  
    ```Java
    try {
      MyRemote service = new MyRemoteImpl();
      Naming.rebind("Remote Hello", service);
    }
    catch (Exception e) { ... }
    ```

3. Generate the stubs and skeletons  
   ```
   % rmic MyRemoteImpl
   ```

4. Run rmiregistry  
   ```
   % rmiregistry
   ```
   
5. Start the service  
   Bring up the service on a separate terminal  
   ```
   % java MyRemoteImpl
   ```
