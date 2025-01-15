//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <memory>

#include "container.h"

class Vector final : public Container {
public:
    Vector(): elem{std::make_unique<double[]>(0)}, sz{0} {
    };

    Vector(const std::initializer_list<double> &list);

    explicit Vector(int s);

    ~Vector() override = default;

    [[nodiscard]] size_t size() const override;

    double &operator[](int idx) const override;

    Vector &operator+=(const Vector &v);

    Vector &operator-=(const Vector &v);

    double operator*=(const Vector &v) const;

    Vector &operator*=(double d);

private:
    std::unique_ptr<double[]> elem = std::make_unique<double[]>(0);
    size_t sz = 0;
};

#endif //VECTOR_H
