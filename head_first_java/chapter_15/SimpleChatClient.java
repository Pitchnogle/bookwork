import java.io.*;
import java.net.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleChatClient {
  JTextField outgoing;
  JTextArea incoming;
  BufferedReader reader;
  PrintWriter writer;
  Socket sock;

  public static void main(String[] args) {
    SimpleChatClient client = new SimpleChatClient();
    client.go();
  }

  public void go() {
    setupGui();
    setupNetworking();

    Thread readerThread = new Thread(new IncomingReader());
    readerThread.start();
  }

  private void setupGui() {
    JFrame frame = new JFrame("Simple Chat Client");
    JPanel panel = new JPanel();
    incoming = new JTextArea(15, 50);
    incoming.setLineWrap(true);
    incoming.setWrapStyleWord(true);
    incoming.setEditable(false);
    JScrollPane qScroller = new JScrollPane(incoming);
    qScroller.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
    qScroller.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
    outgoing = new JTextField(20);
    JButton sendButton = new JButton("Send");
    sendButton.addActionListener(new SendButtonListener());
    panel.add(qScroller);
    panel.add(outgoing);
    panel.add(sendButton);
    frame.getContentPane().add(BorderLayout.CENTER, panel);
    frame.setSize(600, 350);
    frame.setVisible(true);
  }

  private void setupNetworking() {
    try {
      sock = new Socket("127.0.0.1", 5000);
      InputStreamReader streamReader = new InputStreamReader(sock.getInputStream());
      reader = new BufferedReader(streamReader);
      writer = new PrintWriter(sock.getOutputStream());
      System.out.println("networking established");
    }
    catch (IOException e) {
      e.printStackTrace();
    }
  }

  public class SendButtonListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      try {
        writer.println(outgoing.getText());
        writer.flush();
      }
      catch (Exception e) {
        e.printStackTrace();
      }

      outgoing.setText("");
      outgoing.requestFocus();
    }
  }

  public class IncomingReader implements Runnable {
    public void run() {
      String msg;
      try {
        while ((msg = reader.readLine()) != null) {
          System.out.println("read: " + msg);
          incoming.append(msg + "\n");
        }
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }
  }
}
