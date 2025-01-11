//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#include "vector.h"

#include <algorithm>
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

Vector::Vector(const std::initializer_list<double> &list): elem{new double[list.size()]}, sz{list.size()} {
    std::ranges::copy(list, this->elem);
}

Vector::~Vector() {
    delete[] this->elem;
}

size_t Vector::size() const {
    return this->sz;
}

double &Vector::operator[](const int idx) const {
    if (idx < 0 || idx >= this->size()) {
        throw std::out_of_range("Index is out of range.");
    }

    return this->elem[idx];
}

Vector &Vector::operator+=(const Vector &v) {
    if (this->size() != v.size()) {
        throw std::length_error("Vectors must be of the same length.");
    }

    for (int i = 0; i < this->size(); ++i) {
        this->elem[i] += v.elem[i];
    }

    return *this;
}

Vector &Vector::operator-=(const Vector &v) {
    if (this->size() != v.size()) {
        throw std::length_error("Vectors must be of the same length.");
    }

    for (int i = 0; i < this->size(); ++i) {
        this->elem[i] -= v.elem[i];
    }

    return *this;
}

double Vector::operator*=(const Vector &v) const {
    if (this->size() != v.size()) {
        throw std::length_error("Vectors must be of the same length.");
    }

    double result = 0;
    for (int i = 0; i < this->size(); ++i) {
        result += this->elem[i] * v.elem[i];
    }

    return result;
}

Vector &Vector::operator*=(const double d) {
    for (int i = 0; i < this->size(); ++i) {
        this->elem[i] *= d;
    }

    for (int i = 0; i < this->size(); ++i) {
        this->elem[i] *= d;
    }

    return *this;
}

