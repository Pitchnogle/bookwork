import java.awt.*;
import javax.swing.*;
import java.rmi.*;
import java.awt.event.*;

public class ServiceBrowser {
  JPanel panel;
  JComboBox serviceList;
  ServiceServer server;

  public static void main(String[] args) {
    ServiceBrowser browser = new ServiceBrowser();
    browser.buildGui();
  }

  public void buildGui() {
    JFrame frame = new JFrame("RMI Browser");
    panel = new JPanel();
    frame.getContentPane().add(BorderLayout.CENTER, panel);

    Object[] services = getServicesList();
    serviceList = new JComboBox(services);
    frame.getContentPane().add(BorderLayout.NORTH, serviceList);
    serviceList.addActionListener(new MyListListener());

    frame.setSize(500, 500);
    frame.setVisible(true);
  }

  void loadService(Object serviceSelection) {
    try {
      Service service = server.getService(serviceSelection);

      panel.removeAll();
      panel.add(service.getGuiPanel());
      panel.validate();
      panel.repaint();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  Object[] getServicesList() {
    Object o = null;
    Object[] services = null;

    try {
      o = Naming.lookup("rmi://127.0.0.1/ServiceServer");
    }
    catch (Exception e) {
      e.printStackTrace();
    }
    server = (ServiceServer)o;

    try {
      services = server.getServiceList();
    }
    catch (Exception e) {
      e.printStackTrace();
    }

    return services;
  }

  class MyListListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      Object selection = serviceList.getSelectedItem();
      loadService(selection);
    }
  }
}
