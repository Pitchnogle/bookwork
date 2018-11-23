public class PhraseOMatic {
  public static void main(String[] args) {
    String[] wordListOne = {
      "24/7", "Multi-Tier", "30,000 Foot", "B-to-B", "Win-Win", "Front-End", "Web-Based", 
      "Pervasive", "Smart", "Six-Sigma", "Critical-Path", "Dynamic"
    };
    
    String[] wordListTwo = {
      "Empowered", "Sticky", "Value-Added", "Oriented", "Centric", "Distributed", "Clustered",
      "Branded", "Outside-the-Box", "Positioned", "Networked", "Focused", "Leveraged", "Aligned",
      "Targeted", "Shared", "Cooperative", "Accelerated"
    };

    String[] wordListThree = {
      "Process", "Tipping-Point", "Solution", "Architecture", "Core Competency", "Strategy",
      "Mindshare", "Portal", "Space", "Vision", "Paradigm", "Mission"
    };

    int oneLength = wordListOne.length;
    int twoLength = wordListTwo.length;
    int threeLength = wordListThree.length;

    int rand1 = (int)(Math.random() * oneLength);
    int rand2 = (int)(Math.random() * twoLength);
    int rand3 = (int)(Math.random() * threeLength);

    String phrase = wordListOne[rand1] + " " + wordListTwo[rand2] + " " + wordListThree[rand3];
    System.out.println("What we need is a " + phrase);
  }
}
