//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
    Vector(): elem{new double[0]}, sz{0} {
    };

    explicit Vector(int s);

    ~Vector();

    [[nodiscard]] int size() const;

    double &operator[](int idx) const;

private:
    double *elem;
    int sz;
};

#endif //VECTOR_H
