//
// Created by Beowulf Hrothgar on 2025-01-10.
//

#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
public:
    virtual ~Container() = default;

    [[nodiscard]] virtual size_t size() const = 0;

    virtual double &operator[](int idx) const = 0;
};

#endif //CONTAINER_H
