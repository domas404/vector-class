# Vector class

## Realizuoti metodai

### front() ir back()

        T front(){ return *data; }
        T back(){ return *(avail-1); }
### reserve()
        void reserve(size_type n){
            if (capacity() < n){
                limit = data + n;
            }
        }

### clear()
        void clear(){ uncreate(); }

### pop_back()
        void pop_back(){ avail--; }

### assign()
        void assign(size_type n, const T& val){ create(n, val); }
        void assign(const_iterator i, const_iterator j){ create(i, j); }

### resize()
        void resize(size_type n){ avail = data + n; }

### push_back payginimas apskaičiuojant 100 iteracijų laiko vidurkį:

| push_back palyginimas       | 10'000   | 100'000  | 1'000'000 | 10'000'000 | 100'000'000 |
| --------------------------- | :---:    | :---:    | :---:     | :---:      | :---:       |
| std::vector                 | 4.985e-5 | 0.000369 | 0.002768  | 0.036885   | 0.299628    |
| mano Vector                 | 1.995e-5 | 0.000289 | 0.001900  | 0.030270   | 0.215559    |

