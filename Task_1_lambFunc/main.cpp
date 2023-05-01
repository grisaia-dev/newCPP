#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> data = {4, 7, 9, 15, 12};

    std::cout << "Входные данные: ";
    for (unsigned n : data) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::for_each(data.begin(), data.end(), 
        [](int& n) {
            if ((n%2) != 0) return n*=3;
            return n;
        }
    );

    std::cout << "Выходные данные: ";
    for (unsigned n : data)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}