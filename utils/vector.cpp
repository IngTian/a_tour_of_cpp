//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#include "vector.h"

#include <algorithm>
#include <stdexcept>

Vector::Vector(const size_t s) {
    this->sz = s;
    this->elem = std::make_unique<double[]>(s);
    for (int i = 0; i < s; ++i) {
        this->elem[i] = 0;
    }
}

Vector::Vector(
    const std::initializer_list<double> &list
): elem{std::make_unique<double[]>(list.size())}, sz{list.size()} {
    int i = 0;
    for (const auto item: list) {
        this->elem[i] = item;
        ++i;
    }
}

Vector::Vector(const Vector &v): Vector(v.size()) {
    for (int i = 0; i < v.size(); ++i) {
        this->elem[i] = v.elem[i];
    }
}

Vector::Vector(Vector &&v) noexcept: elem{std::move(v.elem)}, sz{v.size()} {
    v.sz = 0;
}

size_t Vector::size() const {
    return this->sz;
}

Vector &Vector::operator=(const Vector &v) {
    auto new_elems = std::make_unique<double[]>(v.size());
    this->sz = v.sz;
    for (int i = 0; i < v.size(); ++i) {
        new_elems[i] = v.elem[i];
    }
    this->elem = std::move(new_elems);
    return *this;
}

Vector &Vector::operator=(Vector &&v) noexcept {
    this->sz = v.sz;
    this->elem = std::move(v.elem);
    return *this;
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

