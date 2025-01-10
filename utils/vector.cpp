//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#include "vector.h"

int Vector::size() const {
    return this->sz;
}

double& Vector::operator[](const int idx) const {
    return this->elem[idx];
}

