#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


class SortingStrategy {
    public:
        virtual void sort(std::vector<int>& data) = 0;
};

class AscendingSort : public SortingStrategy {
    public:
        void sort(std::vector<int>& data) override {
            std::sort(data.begin(), data.end());
            std::cout << "Sorted in descending order: [";
            for (int i : data) {
                std::cout << i << ", ";
            }
            std::cout << "]" << std::endl;
        }
};

class DescendingSort : public SortingStrategy {
    public:
        void sort(std::vector<int>& data) override {
            std::sort(data.begin(), data.end(), std::greater<int>());
            std::cout << "Sorted in descending order: [";
            for (int i : data) {
                std::cout << i << ", ";
            }
            std::cout << "]" << std::endl;
        }
};

class Sorter {
    private:
        SortingStrategy* sortingStrategy;
    public:
        void setStrategy(SortingStrategy* sortingStrategy) {
            this->sortingStrategy = sortingStrategy;
        }

        void sort(std::vector<int>& data) {
            sortingStrategy->sort(data);
        }
};

int main() {
    std::vector<int>* data = new std::vector<int>();
    data->push_back(4);
    data->push_back(1);
    data->push_back(9);
    data->push_back(3);
    data->push_back(2);

    Sorter *sorter = new Sorter();

    sorter->setStrategy(new AscendingSort());
    sorter->sort(*data);

    sorter->setStrategy(new DescendingSort());
    sorter->sort(*data);

    delete data;
    delete sorter;
}