#include "myvector.h"

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& rhs){
    if(&rhs != this){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vector<T>::create(){
    data = avail = limit = nullptr;
}

template <class T>
void Vector<T>::create(size_type n, const T& val){
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vector<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T>
void Vector<T>::uncreate(){
    if(data){
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = nullptr;
}

template <class T>
void Vector<T>::reserve(size_type n){
    if (capacity() < n){
        iterator new_data = alloc.allocate(n);
        iterator new_avail = uninitialized_copy(data, avail, n);

        uncreate();
        
        data = new_data;
        avail = new_avail;
        limit = data + n;
    }
}

template <class T>
void Vector<T>::grow(){
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vector<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}