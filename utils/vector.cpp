//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#include "vector.h"

#include <stdexcept>

Vector::Vector(const int s) {
    if (s < 0) {
        throw std::length_error("Vector length cannot be negative.");
    }

    this->sz = s;
    this->elem = new double[s];
    for (int i = 0; i < s; ++i) {
        this->elem[i] = 0;
    }
}

Vector::~Vector() {
    delete[] this->elem;
}


int Vector::size() const {
    return this->sz;
}

double &Vector::operator[](const int idx) const {
    if (idx < 0 || idx >= this->size()) {
        throw std::out_of_range("Index is out of range.");
    }

    return this->elem[idx];
}

