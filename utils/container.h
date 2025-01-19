//
// Created by Beowulf Hrothgar on 2025-01-10.
//

#ifndef CONTAINER_H
#define CONTAINER_H

template<typename T>
class Container {
public:
    virtual ~Container() = default;

    [[nodiscard]] virtual size_t size() const = 0;

    virtual T &operator[](int idx) const = 0;
};

#endif //CONTAINER_H
