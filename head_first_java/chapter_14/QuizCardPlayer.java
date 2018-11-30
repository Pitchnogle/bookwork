import java.util.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;

public class QuizCardPlayer {
  private JTextArea display;
  private ArrayList<QuizCard> cardList;
  private QuizCard currentCard;
  private int currentCardIndex;
  private JFrame frame;
  private JButton nextButton;
  private boolean isShowAnswer;

  public static void main(String[] args) {
    QuizCardPlayer player = new QuizCardPlayer();
    player.go();
  }

  public void go() {
    frame = new JFrame("Quiz Card Player");
    JPanel mainPanel = new JPanel();
    Font bigFont = new Font("sanserif", Font.BOLD, 24);

    display = new JTextArea(10, 20);
    display.setFont(bigFont);
    display.setLineWrap(true);
    display.setEditable(false);

    JScrollPane qScroller = new JScrollPane(display);
    qScroller.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
    qScroller.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

    nextButton = new JButton("Show Question");
    mainPanel.add(qScroller);
    mainPanel.add(nextButton);
    nextButton.addActionListener(new NextCardListener());

    JMenuBar menuBar = new JMenuBar();
    JMenu fileMenu = new JMenu("File");
    JMenuItem loadMenuItem = new JMenuItem("Load card set");
    loadMenuItem.addActionListener(new OpenMenuListener());
    fileMenu.add(loadMenuItem);
    menuBar.add(fileMenu);

    frame.setJMenuBar(menuBar);
    frame.getContentPane().add(BorderLayout.CENTER, mainPanel);
    frame.setSize(640, 500);
    frame.setVisible(true);
  }

  public class NextCardListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      if (isShowAnswer) {
        display.setText(currentCard.getAnswer());
        nextButton.setText("Next Card");
        isShowAnswer = false;
      }
      else {
        if (currentCardIndex < cardList.size()) {
          showNextCard();
        }
        else {
          display.setText("That was the last card");
          nextButton.setEnabled(false);
        }
      }
    }
  }

  public class OpenMenuListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      JFileChooser fileOpen = new JFileChooser();
      fileOpen.showOpenDialog(frame);
      loadFile(fileOpen.getSelectedFile());
    }
  }

  public void loadFile(File file) {
    cardList = new ArrayList<QuizCard>();
    try {
      BufferedReader reader = new BufferedReader(new FileReader(file));
      String line = null;
      while ((line = reader.readLine()) != null) {
        makeCard(line);
      }
    }
    catch (Exception e) {
      System.out.println("Couldn't read the card file");
      e.printStackTrace();
    }
    showNextCard();
  }

  private void makeCard(String lineToParse) {
    String[] result = lineToParse.split("/");
    QuizCard card = new QuizCard(result[0], result[1]);
    cardList.add(card);
    System.out.println("Made a card");
  }

  private void showNextCard() {
    currentCard = cardList.get(currentCardIndex);
    currentCardIndex++;
    display.setText(currentCard.getQuestion());
    nextButton.setText("Show Answer");
    isShowAnswer = true;
  }
}