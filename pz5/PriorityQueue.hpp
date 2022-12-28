#pragma once

#include <vector>
#include <algorithm>

template<typename T>
class PriorityQueue : private std::vector<T> {
private:
    void siftup(size_t start) {
        while (this->at(start) > this->at(start / 2)) {
            std::swap(this->at(start), this->at(start / 2));
            start /= 2;
        }
    }
    void siftdown(size_t start) {
        size_t n = this->size();
        bool lleaf_is_bigger = ((start * 2 + 1) < n && this->at(start) < this->at(start * 2 + 1));
        bool rleaf_is_bigger = ((start * 2 + 2) < n && this->at(start) < this->at(start * 2 + 2));
        while (lleaf_is_bigger || rleaf_is_bigger) {
            size_t l = start * 2 + 1;
            size_t r = start * 2 + 2;
            if (rleaf_is_bigger) {
                if (this->at(l) > this->at(r)) {
                    std::swap(this->at(start), this->at(l));
                    start = l;
                } else {
                    std::swap(this->at(start), this->at(r));
                    start = r;
                }
            } else {
                std::swap(this->at(start), this->at(l));
                start = l;
            }
            lleaf_is_bigger = ((start * 2 + 1) < n && this->at(start) < this->at(start * 2 + 1));
            rleaf_is_bigger = ((start * 2 + 2) < n && this->at(start) < this->at(start * 2 + 2));
        }
    }
public:
    using vector<T>::size;
    void push(const T&);
    T pop();
};

template<typename T>
void PriorityQueue<T>::push(const T& item) {
    this->push_back(item);
    this->siftup(this->size() - 1);
}

template<typename T>
T PriorityQueue<T>::pop() {
    T tmp = this->front();
    std::swap(this->front(), this->back());
    this->pop_back();
    this->siftdown(0);
    return tmp;
}