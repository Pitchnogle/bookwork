import java.io.*;
import java.net.*;
import java.util.*;

public class SimpleChatServer {
  ArrayList clientOutputStreams;

  public static void main(String[] args) {
    SimpleChatServer server = new SimpleChatServer();
    server.go();
  }

  public void go() {
    clientOutputStreams = new ArrayList();

    try {
      ServerSocket serverSock = new ServerSocket(5000);

      while (true) {
        Socket clientSocket = serverSock.accept();
        PrintWriter writer = new PrintWriter(clientSocket.getOutputStream());
        clientOutputStreams.add(writer);

        Thread t = new Thread(new ClientHandler(clientSocket));
        t.start();
        System.out.println("got a connection");
      }
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  public class ClientHandler implements Runnable {
    BufferedReader reader;
    Socket sock;

    public ClientHandler(Socket clientSocket) {
      try {
        sock = clientSocket;
        InputStreamReader streamReader = new InputStreamReader(sock.getInputStream());
        reader = new BufferedReader(streamReader);
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }

    public void run() {
      String msg;

      try {
        while ((msg = reader.readLine()) != null) {
          System.out.println("read: " + msg);
          tellEveryone(msg);
        }
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }
  }

  public void tellEveryone(String msg) {
    Iterator iterator = clientOutputStreams.iterator();
    while (iterator.hasNext()) {
      try {
        PrintWriter writer = (PrintWriter)iterator.next();
        writer.println(msg);
        writer.flush();
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }
  }
}
