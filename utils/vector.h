//
// Created by Beowulf Hrothgar on 2025-01-09.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>

#include "container.h"

template<std::copyable T>
class Vector final : public Container<T> {
public:
    Vector(): elem{std::make_unique<T[]>(0)}, sz{0} {
    };

    Vector(const std::initializer_list<T> &list): elem{std::make_unique<T[]>(list.size())}, sz{list.size()} {
        int i = 0;
        for (const auto item: list) {
            this->elem[i] = item;
            ++i;
        }
    };

    explicit Vector(size_t s): elem{std::make_unique<T[]>(s)}, sz{s} {
        for (int i = 0; i < s; ++i) {
            this->elem[i] = 0;
        }
    };

    Vector(const Vector &v): elem{std::make_unique<T>(v.size())}, sz{v.size()} {
        for (int i = 0; i < v.size(); i++) {
            this->elem[i] = v.elem[i];
        }
    };

    Vector(Vector &&v) noexcept: elem{std::move(v.elem)}, sz{v.size()} {
        v.sz = 0;
    };

    ~Vector() override = default;

    [[nodiscard]] size_t size() const override {
        return this->sz;
    };

    T *begin() const {
        return &this->elem[0];
    }

    T *end() const {
        return this->begin() + this->size();
    }

    Vector &operator=(const Vector &v) {
        auto new_elems = std::make_unique<T>(v.size());
        this->sz = v.size();
        for (int i = 0; i < v.size(); ++i) {
            new_elems[i] = v.elem[i];
        }
        this->elem = std::move(new_elems);
        return *this;
    };

    Vector &operator=(Vector &&v) noexcept {
        this->elem = std::move(v.elem);
        this->sz = v.size();
        return *this;
    };

    T &operator[](int idx) const override {
        if (idx < 0 || idx >= this->size()) {
            throw std::out_of_range("Index is out of range.");
        }

        return this->elem[idx];
    };

    Vector &operator+=(const Vector &v) {
        if (this->size() != v.size()) {
            throw std::length_error("Vectors must be of the same length.");
        }

        for (int i = 0; i < this->size(); ++i) {
            this->elem[i] += v.elem[i];
        }

        return *this;
    };

    Vector &operator-=(const Vector &v) {
        if (this->size() != v.size()) {
            throw std::length_error("Vectors must be of the same length.");
        }

        for (int i = 0; i < this->size(); ++i) {
            this->elem[i] -= v.elem[i];
        }

        return *this;
    };

    T operator*=(const Vector &v) const {
        if (this->size() != v.size()) {
            throw std::length_error("Vectors must be of the same length.");
        }

        T result = 0;
        for (int i = 0; i < this->size(); ++i) {
            result += this->elem[i] * v.elem[i];
        }

        return result;
    };

    Vector &operator*=(T d) {
        for (int i = 0; i < this->size(); ++i) {
            this->elem[i] *= d;
        }

        for (int i = 0; i < this->size(); ++i) {
            this->elem[i] *= d;
        }

        return *this;
    };

private:
    std::unique_ptr<T[]> elem = std::make_unique<T[]>(0);
    size_t sz = 0;
};

#endif //VECTOR_H
