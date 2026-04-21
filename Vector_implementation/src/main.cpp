#include <iostream>
#include <memory.h>
#include <vector>
template <typename T> class Vector_c {
private:
    T* begin;
    T* back;
    T* end;
public:
    Vector_c() : begin{ nullptr }, back{ nullptr }, end{ nullptr } {}
    ~Vector_c() = default;
    size_t size() const { return back - begin; }
    size_t capacity() const { return end - begin; }

    void grow() {
        size_t old_size = size();
        size_t new_capacity = 0;
        if (capacity() == 0) new_capacity = 1;
        else capacity() * 2;
        T* data = new T[size];
        for (int i = 0; i < new_capacity; i++) {
            data[i] = begin[i];
        }
        delete[] begin;
        begin = data;
        back = (new_capacity - 1) + begin;
        end = new_capacity + begin;
    }

    void push(const T& value) {
        if (back == end) {
            grow();
        }

    }
};

int main() {
    Vector_c<int> vec;
}
