#include "circulararray.h"
/*
CircularArray::CircularArray(){
data(nullptr);
 n_items(0);
 n_allocated(0);
 idx_front(0);
}

CircularArray::~CircularArray() {
    delete[] data;
    data = nullptr;
}

void CircularArray::reallocate(int new_size) {
    Thing* newbuffer = new Thing[new_size];
    for (int i = 0; i < n_items; i++) {
        newbuffer[i] = data[(idx_front + i) % n_allocated];
    }
    delete[] data;
    data = newbuffer;
    idx_front = 0;
    n_allocated = new_size;
}

void CircularArray::push_back(const Thing &t) {
    if (n_allocated == 0) {
        reallocate(1);
        n_allocated++;
        data[0] = t;
        n_items++;
        return;
    }
    if (n_allocated == n_items) {
        reallocate(2 * n_allocated);
        n_allocated = 2 * n_allocated;
    }
    data[(n_items + idx_front) % n_allocated] = t;
    n_items++;
}

void CircularArray::push_front(const Thing &t) {
    if (n_allocated == 0) {
        reallocate(1);
        n_allocated++;
        data[0] = t;
        n_items++;
        return;
    }
    if (n_allocated == n_items) {
        reallocate(2 * n_allocated);
        n_allocated = 2 * n_allocated;
        for (int i = n_items; i > 0; --i) {
            data[i] = data[i - 1];
        }
    }
    if (idx_front == 0) {
        for (int i = n_items; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = t;
        n_items++;
        return;
    }
    idx_front = (idx_front - 1) % n_allocated;
    data[idx_front] = t;
    n_items++;
}

void CircularArray::push_at(const Thing &t, int i) {
    if (i < 0 || i > n_items) return;
    if (n_allocated == 0) {
        push_back(t);
        return;
    }
    if (i == 0) {
        push_front(t);
        return;
    }
    if (i == n_items - 1) {
        push_back(t);
        return;
    }
    if (n_allocated == n_items) {
        reallocate(2 * n_allocated);
        n_allocated = 2 * n_allocated;
        for (int j = n_items; j > i; j--) {
            data[j] = data[j - 1];
        }
    }
    for (int j = n_items; j > i; j--) {
        data[(idx_front + j) % n_allocated] = data[(idx_front + j - 1) % n_allocated];
    }
    data[(idx_front + i) % n_allocated] = t;
    n_items++;
}

void CircularArray::pop_back() {
    if (n_allocated == 0) return;
    n_items--;
    if (n_items == n_allocated / 4) {
        reallocate(n_allocated / 2);
        n_allocated = n_allocated / 2;
    }
}

void CircularArray::pop_front() {
    if (n_allocated == 0) return;
    idx_front = (idx_front + 1) % n_allocated;
    n_items--;
    if (n_items == n_allocated / 4) {
        reallocate(n_allocated / 2);
        n_allocated = n_allocated / 2;
    }
}

void CircularArray::pop_at(int i) {
    if (i < 0 || i >= n_items) return;
    if (i == 0) {
        pop_front();
        return;
    }
    if (i == n_items - 1) {
        pop_back();
        return;
    }
    for (int j = i + 1; j < n_items; j++) {
        data[(idx_front + j - 1) % n_allocated] = data[(idx_front + j) % n_allocated];
    }
    n_items--;
    if (n_items == n_allocated / 4) {
        reallocate(n_allocated / 2);
        n_allocated = n_allocated / 2;
    }
}

int CircularArray::size() const {
    return n_items;
}

int CircularArray::allocated() const {
    return n_allocated;
}

Thing& CircularArray::operator[](int i) {
    if (i < 0 || i >= n_items) throw std::out_of_range("Index out of range");
    return data[(idx_front + i) % n_allocated];
}
/*
