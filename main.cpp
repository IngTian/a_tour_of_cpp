#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    const auto v = make_unique<Vector>(100);

    try {
        std::cout << v->size() << (*v)[-9] << std::endl;
    } catch (out_of_range &err) {
        std::cerr << err.what() << std::endl;
    }
}
