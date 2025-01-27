class Pizza {
    String dough;
    String sauce;
    String topping;


    private Pizza(PizzaBuilder builder) {
        this.dough = builder.dough;
        this.sauce = builder.sauce;
        this.topping = builder.topping;
    }

    public static class PizzaBuilder {
        String dough;
        String sauce;
        String topping;

        public PizzaBuilder dough(String dough) {
            this.dough = dough;
            return this;
        }

        public PizzaBuilder sauce(String sauce) {
            this.sauce = sauce;
            return this;
        }

        public PizzaBuilder topping(String topping) {
            this.topping = topping;
            return this;
        }

        Pizza build() {
            return new Pizza(this);
        }
    }

    public void display() {
        System.out.println("\\/ Pizza ingredients below\\/");
        System.out.println("Dough: " + dough);
        System.out.println("Sauce: " + sauce);
        System.out.println("Topping: " + topping);
    }

    public static void main(String[] args) {
        Pizza pizza = new Pizza.PizzaBuilder()
                .dough("dough")
                .sauce("tomato")
                .topping("cheese + ham")
                .build();

        pizza.display();
    }
}