//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>

class Vector {
public:
    Vector(): elem{new double[0]}, sz{0} {
    };

    Vector(const std::initializer_list<double> &list);

    explicit Vector(int s);

    ~Vector();

    [[nodiscard]] size_t size() const;

    double &operator[](int idx) const;

    Vector &operator+=(const Vector &v);

    Vector &operator-=(const Vector &v);

    double operator*=(const Vector &v) const;

    Vector &operator*=(double d);

private:
    double *elem;
    size_t sz;
};

#endif //VECTOR_H
