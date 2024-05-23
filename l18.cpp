#include <iostream>
#include <vector>
#include <algorithm>

class MyClass {
public:
    MyClass(int val) : value(val) {}
    int getValue() const { return value; }
private:
    int value;
};

void bubbleSort(std::vector<MyClass>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j].getValue() > vec[j + 1].getValue()) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // Если не было обменов на данной итерации, то массив уже отсортирован
        }
    }
}

int main() {
    int size;
    std::cout << "Введите размер вектора: ";
    std::cin >> size;

    std::vector<MyClass> originalVector;
    for (int i = 0; i < size; ++i) {
        int val;
        std::cout << "Введите значение элемента " << i << ": ";
        std::cin >> val;
        originalVector.push_back(MyClass(val));
    }

    std::vector<MyClass> newVector;
    for (const auto& obj : originalVector) {
        if (obj.getValue() % 2 == 0 && obj.getValue() != 0) { // Исключаем значение 0
            newVector.push_back(obj);
        }
    }

    std::cout << "Исходный вектор:" << std::endl;
    for (const auto& obj : originalVector) {
        std::cout << obj.getValue() << " ";
    }
    std::cout << std::endl;

    std::cout << "Неотсортированный новый вектор:" << std::endl;
    for (const auto& obj : newVector) {
        std::cout << obj.getValue() << " ";
    }
    std::cout << std::endl;

    if (newVector.empty()) {
        std::cout << "Новый вектор пустой. Программа завершает выполнение." << std::endl;
        return 0;
    }

    bubbleSort(newVector);

    std::cout << "nОтсортированный новый вектор:" << std::endl;
    for (const auto& obj : newVector) {
        std::cout << obj.getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
