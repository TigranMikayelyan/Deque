#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <list>
#include <exception>
#include <iostream>

template <typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    Deque(const Deque<T>&);
    Deque(Deque<T>&&);
    Deque(T);
public:
    Deque& operator=(const Deque<T>&);
    Deque& operator=(Deque<T>&&);
    bool operator==(const Deque<T>&);
    bool operator!=(const Deque<T>&);
    bool operator>(Deque<T>&);
    bool operator<(Deque<T>&);
    bool operator>=(Deque<T>&);
    bool operator<=(Deque<T>&);
public:
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool empty();
    int size();
    void clear();
    void insert(int, const T&);
    void erase(int);
    void push_back(const T&);
    void pop_back();
    void push_front(const T&);
    void pop_front();
    void resize(std::size_t);
    void swap(Deque<T>&);
    void print();
private:
    std::list<T> m_deque;
    typename std::list<T>::iterator m_front_iterator;
    typename std::list<T>::iterator m_back_iterator;
    std::size_t m_size;
    std::size_t m_capacity;
};

#endif // MY_DEQUE_H