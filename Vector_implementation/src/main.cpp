#include <iostream>
#include <memory.h>
#include <vector>
template <typename T> class Vector_c {
private:
    T* m_begin;
    T* m_back;
    T* m_cap;
    T* sizeof_element;
public:
    Vector_c() : m_begin{ nullptr }, m_back{ nullptr }, m_cap{ nullptr } {}
    ~Vector_c() = default;
    size_t size() const { return m_back - m_begin; }

    size_t capacity() const { return m_cap - m_begin; }

    size_t begin() const { return *m_begin; }

    size_t back() const { return *m_back; }

    void grow() {
        size_t old_size = size();
        size_t new_capacity = 0;
        if (capacity() == 0) new_capacity = 1;
        else new_capacity = capacity() * 2;
        T* data = new T[new_capacity];
        for (int i = 0; i < old_size; i++) {
            data[i] = m_begin[i];
        }
        delete[] m_begin;
        m_begin = data;                 //0x55555556b2b0
        m_back = m_begin + old_size;
        m_cap = m_begin + new_capacity;
    }

    void push_back(const T& value) {
        sizeof_element = sizeof(value);
        if (m_back == m_cap) {
            grow();
            *m_back = value;
        }
        m_back += sizeof_element;
        *m_back = value;
    }

    void pop_back() {
        if (size() > 0) {
            m_back -= sizeof_element;
        }
    }
};

int main() {
    Vector_c<int> vec;
    vec.push_back(11);
    vec.push_back(22);
    vec.push_back(33);
    vec.push_back(44);
    vec.push_back(55);
    std::cout << "begin: " << vec.begin() << "\n";
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "back: " << vec.back() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
    vec.pop_back();
    std::cout << "back: " << vec.back() << "\n";
}
