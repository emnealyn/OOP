import java.util.ArrayList;
import java.util.Collections;

interface SortingStrategy {
    void sort(ArrayList<Integer> data);
}

class AscendingSort implements SortingStrategy {
    @Override
    public void sort(ArrayList<Integer> data) {
        Collections.sort(data);
        System.out.println("Sorted in ascending order: " + data);
    }
}

class DescendingSort implements SortingStrategy {
    @Override
    public void sort(ArrayList<Integer> data) {
        Collections.sort(data, Collections.reverseOrder());
        System.out.println("Sorted in descending order: " + data);
    }
}

class Sorter {
    private SortingStrategy strategy;

    public void setStrategy(SortingStrategy strategy) {
        this.strategy = strategy;
    }

    public void sort(ArrayList<Integer> data) {
        if (strategy == null) {
            System.out.println("No sorting strategy set");
            return;
        }
        strategy.sort(data);
    }
}

public class Strategy {
    public static void main(String[] args) {
        ArrayList<Integer> data = new ArrayList<>();
        data.add(3);
        data.add(6);
        data.add(2);
        data.add(8);
        data.add(1);
        data.add(7);

        Sorter sorter = new Sorter();

        sorter.setStrategy(new AscendingSort());
        sorter.sort(data);

        sorter.setStrategy(new DescendingSort());
        sorter.sort(data);
    }
}