//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include "container.h"

class Vector final : public Container {
public:
    Vector(): elem{new double[0]}, sz{0} {
    };

    Vector(const std::initializer_list<double> &list);

    explicit Vector(int s);

    ~Vector() override;

    [[nodiscard]] size_t size() const override;

    double &operator[](int idx) const override;

    Vector &operator+=(const Vector &v);

    Vector &operator-=(const Vector &v);

    double operator*=(const Vector &v) const;

    Vector &operator*=(double d);

private:
    double *elem;
    size_t sz;
};

#endif //VECTOR_H
