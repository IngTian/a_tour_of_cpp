#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    const auto v = make_unique<Vector>(100);

    const Vector a{1, 2, 3, 4, 5};
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }

    try {
        std::cout << v->size() << (*v)[9] << std::endl;
    } catch (out_of_range &err) {
        std::cerr << err.what() << std::endl;
    }
}
