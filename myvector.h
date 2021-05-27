// Vector klases realizacija
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <memory>

using namespace std;

template <class T>
class Vector{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        // konstruktoriai
        Vector() { create(); }
        explicit Vector(size_type n, const T& val = T{}) { create(n, val); }
        
        // rule of three
        Vector(const Vector& v) { create(v.begin(), v.end()); }
        Vector& operator=(const Vector&);
        ~Vector() { uncreate(); }
        
        T& operator[](size_type i) { return data[i]; }
        const T& operator[](size_type i) const { return data[i]; }

        size_type size() const { return avail - data; }
        size_type capacity() const { return limit - data; }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }
        iterator end() { return avail; }
        const_iterator end() const { return avail; }

        void push_back(const T& val){
            if (avail == limit)
                grow();
            unchecked_append(val);
        }
        T front(){ return *data; }
        T back(){ return *(avail-1); }

        void clear(){ uncreate(); }
        void pop_back(){ avail--; }
        
        void reserve(size_type n){
            if (capacity() < n){
                limit = data + n;
            }
        }
        void resize(size_type n){ avail = data + n; }
        
        void assign(size_type n, const T& val){ create(n, val); }
        constexpr void assign(const_iterator i, const_iterator j){ create(i, j); }

    private:
        iterator data;
        iterator limit;
        iterator avail;

        allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);
};

#endif