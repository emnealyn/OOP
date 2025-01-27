import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Parrot {
    private List<String> phrases;
    private Random random;

    public Parrot(String initialPhrase) {
        phrases = new ArrayList<>();
        phrases.add(initialPhrase);
        random = new Random();
    }

    public void say(int times) {
        if (!phrases.isEmpty()) {
            for (int i = 0; i < times; i++) {
                int randomIndex = random.nextInt(phrases.size());
                System.out.println(phrases.get(randomIndex));
            }
        } else {
            System.out.println("I don't have anything to say!");
        }
    }

    public void addPhrase(String newPhrase) {
        phrases.add(newPhrase);
    }

    public static void main(String[] args) {
        Parrot parrot = new Parrot("It's rather late!");

        parrot.say(3); 
        parrot.addPhrase("Oh well!");
        parrot.addPhrase("Whatever!");
        parrot.say(2); 
    }
}

