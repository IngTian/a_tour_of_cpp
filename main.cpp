#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    const auto v = make_unique<Vector<double> >(100);

    const Vector<double> a{1, 2, 3, 4, 5};
    for (auto elem: a) {
        std::cout << elem << std::endl;
    }

    try {
        std::cout << v->size() << (*v)[9] << std::endl;
    } catch (out_of_range &err) {
        std::cerr << err.what() << std::endl;
    }
}
