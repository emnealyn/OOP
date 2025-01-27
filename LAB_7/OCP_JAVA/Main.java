package OCP_JAVA;

public class Main {
    public static void main(String[] args) {
        RegularDiscount regularDiscount = new RegularDiscount();
        SeasonalDiscount seasonalDiscount = new SeasonalDiscount();

        System.out.println("Regular discount: " + regularDiscount.discount);
        System.out.println("Seasonal discount: " + seasonalDiscount.discount);

    }
}