#include <iostream>
#include <memory.h>
#include <vector>
template <typename T> class Vector_c {
private:
    T* m_begin;
    T* m_back;
    T* m_cap;
public:
    Vector_c() : m_begin{ nullptr }, m_back{ nullptr }, m_cap{ nullptr } {}
    ~Vector_c() = default;

    //Element access
    const T at(size_t index) const { return *(m_begin + index); }

    const T front() const { return *m_begin; }

    const T back() const { return *(m_back - 1); }

    const T* data() const { return m_begin; }

    //Iterators
    T* begin() const {

    }

    T* end() const {

    }

    //Capacity
    //empty size max_size reserve capacity shrink_to_fit
    size_t size() const { return m_back - m_begin; }

    size_t capacity() const { return m_cap - m_begin; }

    //Modifiers
    void push_back(const T& value) {
        if (m_back == m_cap) {
            grow();
        }
        *m_back = value;
        ++m_back;
    }

    void pop_back() {
        if (size() > 0) {
            --m_back;
        }
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
    /*
    Vector_c<int> vec;
    vec.push_back(11);
    vec.push_back(22);
    vec.push_back(33);
    */
    Vector_c<std::string> vec;
    vec.push_back("one");
    vec.push_back("two");

    std::cout << "front: " << vec.front() << "\n";
    std::cout << "back: " << vec.back() << "\n";
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
    std::cout << "at: " << vec.at(1) << "\n";
    std::cout << "data: " << vec.data() << "\n";
    vec.pop_back();
    std::cout << "back: " << vec.back() << "\n";
}
