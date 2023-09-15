#include "my_deque.h"

template <typename T>
Deque<T>::Deque() : m_deque{}, m_front_iterator{m_deque.begin()}, m_back_iterator{m_deque.end()}, m_size(0), m_capacity(5) {}

template <typename T>
Deque<T>::~Deque()
{
    clear();
}

template <typename T>
Deque<T>::Deque(const Deque<T>& oth)
{
    m_deque = oth.m_deque;
    m_front_iterator = oth.m_front_iterator;
    m_back_iterator = oth.m_back_iterator;
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
}

template <typename T>
Deque<T>::Deque(Deque<T>&& oth)
{
    m_deque = oth.m_deque;
    m_front_iterator = oth.m_front_iterator;
    m_back_iterator = oth.m_back_iterator;
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
    oth.m_deque.clear();
}

template <typename T>
Deque<T>::Deque(T val)
{
    m_deque.push_back(val);
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    m_deque = oth.m_deque;
    m_front_iterator = oth.m_front_iterator;
    m_back_iterator = oth.m_back_iterator;
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
    return *this;
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    m_deque = oth.m_deque;
    m_front_iterator = oth.m_front_iterator;
    m_back_iterator = oth.m_back_iterator;
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
    oth.m_deque.clear();
    return *this;
}

template <typename T>
bool Deque<T>::operator==(const Deque<T>& oth)
{
    return (m_deque == oth.m_deque);
}

template <typename T>
bool Deque<T>::operator!=(const Deque<T>& oth)
{
    return (m_deque != oth.m_deque);
}

template <typename T>
bool Deque<T>::operator>(Deque<T>& oth)
{
    return (m_deque > oth.m_deque);
}

template <typename T>
bool Deque<T>::operator<(Deque<T>& oth)
{
    return (m_deque > oth.m_deque);
}

template <typename T>
bool Deque<T>::operator>=(Deque<T>& oth)
{
    return !(m_deque < oth.m_deque);
}

template <typename T>
bool Deque<T>::operator<=(Deque<T>& oth)
{
    return !(m_deque > oth.m_deque);
}

template <typename T>
T& Deque<T>::front()
{
    return *m_front_iterator;
}

template <typename T>
const T& Deque<T>::front() const
{
    return *m_front_iterator;
}

template <typename T>
T& Deque<T>::back()
{
    return *m_back_iterator;
}

template <typename T>
const T& Deque<T>::back() const
{
    return *m_back_iterator;
}

template <typename T>
bool Deque<T>::empty()
{
    return m_deque.empty();
}

template <typename T>
int Deque<T>::size()
{
    return m_size;
}

template <typename T>
void Deque<T>::clear()
{
    m_deque.clear();
    m_front_iterator = m_deque.begin();
    m_back_iterator = m_deque.end();
    m_size = 0;
    m_capacity = 0;
}

template <typename T> 
void Deque<T>::insert(int pos, const T& val)
{
    m_deque.insert(m_front_iterator + pos, val);
}

template <typename T>
void Deque<T>::erase(int pos)
{
    m_deque.erase(m_front_iterator + pos);
}

template <typename T>
void Deque<T>::push_back(const T& val)
{
    if (m_size >= m_capacity)
    {
        resize(m_capacity * 2);
    }
    m_deque.push_back(val);
    m_front_iterator = m_deque.begin();
    m_back_iterator = m_deque.end();
    ++m_size;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (empty())
    {
        throw std::logic_error("Deque is empty!");
    }
    m_deque.pop_back();
    --m_back_iterator;
    --m_size;
}

template <typename T>
void Deque<T>::push_front(const T& val)
{   
    if (m_size >= m_capacity)
    {
        resize(m_capacity * 2);
    }
    m_deque.push_front(val);
    m_front_iterator = m_deque.begin();
    m_back_iterator = m_deque.end();
    ++m_size;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        throw std::logic_error("Deque is empty!");
    }
    m_deque.pop_front();
    ++m_front_iterator;
    --m_size;
}

template <typename T>
void Deque<T>::resize(std::size_t new_size)
{
    m_deque.resize(new_size);
    while (m_size > new_size)
    {
        pop_back();
    }
    while (m_size < new_size)
    {
        push_back(T());
    }
    m_size = new_size;
}

template <typename T>
void Deque<T>::swap(Deque<T>& oth)
{
    m_deque.swap(oth.m_deque);

    std::swap(m_front_iterator, oth.m_front_iterator);
    std::swap(m_back_iterator, oth.m_back_iterator);

    std::swap(m_size, oth.m_size);
    std::swap(m_capacity, oth.m_capacity);
}

template <typename T>
void Deque<T>::print()
{
    for (const auto& i : m_deque)
    {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
}
