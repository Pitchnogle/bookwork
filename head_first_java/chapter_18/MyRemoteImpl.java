import java.rmi.*;
import java.rmi.server.*;

public class MyRemoteImpl extends UnicastRemoteObject implements MyRemote {
  public static void main(String[] args) {
    try {
      MyRemote service = MyRemoteImpl();
      Naming.rebind("Remote Hello", service);
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  public String sayHello() {
    return "Server says 'Hey'";
  }

  public MyRemoteImpl() throws RemoteException {}
}
