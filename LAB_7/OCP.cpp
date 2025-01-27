#include <iostream>


// Interfejs rabatu
class Discount {
    public:
        double discount;

};

// Regularny rabat
class RegularDiscount : public Discount {
    public:
        RegularDiscount() {
            discount = 0.1;     // 10% rabatu
        }
                            
};

// Sezonowy rabat
class SeasonalDiscount : public Discount {
    public:
        SeasonalDiscount() {
            discount = 0.2;     // 20% rabatu
        }
};

int main() {
    RegularDiscount regularDiscount;
    SeasonalDiscount seasonalDiscount;

    std::cout << "Regular Discount: " << regularDiscount.discount << std::endl;
    std::cout << "Seasonal Discount: " << seasonalDiscount.discount << std::endl;

    
    return 0;
}