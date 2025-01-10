#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    const auto v = make_unique<Vector>(100);
    std::cout << v->size() << (*v)[10] << std::endl;
}
