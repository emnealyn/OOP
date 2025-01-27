#include <iostream>
#include <string>

class Pizza {
    private:
        std::string dough;
        std::string sauce;
        std::string topping;

    public:
        Pizza(const std::string& dough, const std::string& sauce, const std::string& topping) : dough(dough), sauce(sauce), topping(topping) {}

        class Builder {
            private:
                std::string dough;
                std::string sauce;
                std::string topping;
    
            public:
                Builder& setDough(std::string dough) {
                    this->dough = dough;
                    return *this;
                }

                Builder& setSauce(std::string sauce) {
                    this->sauce = sauce;
                    return *this;
                }

                Builder& setTopping(std::string topping) {
                    this->topping = topping;
                    return *this;
                }

                Pizza build() {
                    return Pizza(dough, sauce, topping);
                }
            };

        
        void display() const {
            std::cout << "\\/ Pizza ingredients below \\/" << std::endl;
            std::cout << "Dough: " << dough << std::endl;
            std::cout << "Sauce: " << sauce << std::endl;
            std::cout << "Topping: " << topping << std::endl;
            
        }
};

int main() {
    Pizza pizza = Pizza::Builder()
                    .setDough("Thin")
                    .setSauce("Tomato")
                    .setTopping("Cheese + ham")
                    .build();
    
    pizza.display();
    
    return 0;
}