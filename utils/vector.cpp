//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#include "vector.h"

#include <stdexcept>

int Vector::size() const {
    return this->sz;
}

double &Vector::operator[](const int idx) const {
    if (idx < 0 || idx >= this->size()) {
        throw std::out_of_range("Index out of range");
    }

    return this->elem[idx];
}

