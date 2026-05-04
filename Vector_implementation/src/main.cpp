#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <limits>
template <typename T>
class Vector_c {
private:
    T* m_begin;
    T* m_back;
    T* m_cap;
public:

    class iterator {
    private:
        T* m_ptr;
    public:
        iterator(T* data) : m_ptr{ data } {}
        T& operator*() { return *m_ptr; }
        iterator& operator++() {
            m_ptr++;
            return *this;
        }
        bool operator!=(const iterator& other_value) { return m_ptr != other_value.m_ptr; }
        bool operator==(const iterator& other_value) { return m_ptr == other_value.m_ptr; }
    };

    Vector_c() : m_begin{ nullptr }, m_back{ nullptr }, m_cap{ nullptr } {}
    ~Vector_c() = default;
    T& operator[](size_t i) { return *(m_begin + i); }
    //Element access
    const T at(size_t index) const { return *(m_begin + index); }

    const T front() const { return *m_begin; }

    const T back() const { return *(m_back - 1); }

    const T* data() const { return m_begin; }

    //Iterators
    const iterator begin() const { return iterator(m_begin); }

    const iterator end() const { return iterator(m_back - 1); }

    //Capacity
    size_t size() const { return m_back - m_begin; }

    size_t capacity() const { return m_cap - m_begin; }

    bool empty() const {
        if (size() == 0) {
            return true;
        }
        else return false;
    }

    size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }

    void reserve(size_t new_cap) {
        if (new_cap > capacity()) {
            m_cap += new_cap;
        }
    }

    //Modifiers
    void push_back(const T& value) {
        if (m_back == m_cap) {
            grow();
        }
        *m_back = value;
        ++m_back;
    }

    void pop_back() const {
        if (size() > 0) {
            --m_back;
        }
    }

    void shrink_to_fit() const {

    }

    //Spare functions
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
        m_back = m_begin + old_size;    //0x55555556b2b0
        m_cap = m_begin + new_capacity; //0x55555556b2b4
    }

};

int main() {
    Vector_c<std::string> vec;
    vec.push_back("one");
    vec.push_back("two");/*
    std::cout << "front: " << vec.front() << "\n";
    std::cout << "back: " << vec.back() << "\n";
    std::cout << "size: " << vec.size() << "\n";*/
    std::cout << "max_size " << vec.max_size();
}
