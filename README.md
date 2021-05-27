# Vector class

Vector klasės realizacija.
Šioje klasėje įgyvendintos 2-oje užduotyje naudotos std::vector funkcijos.
## *push_back* payginimas:
Palyginimui naudojami 100 iteracijų laiko vidurkiai.

|                             | 10'000   | 100'000  | 1'000'000 | 10'000'000 | 100'000'000 |
| --------------------------- | :---:    | :---:    | :---:     | :---:      | :---:       |
| std::vector                 | 4.985e-5 | 0.000369 | 0.002768  | 0.036885   | 0.299628    |
| mano Vector                 | 1.995e-5 | 0.000289 | 0.001900  | 0.030270   | 0.215559    |

## std::vector ir Vector palyginimas (v2.0)
Skaičiavimai atlikti su 100'000 elementų failu.

|                                     | std::vector  | mano Vector  |
| ----------------------------------- | :---:        | :---:        |
| Nuskaitymas ir skaičiavimai         | 0.838771     | 0.839255     |
| Rūšiavimas pagal įvertinimus        | 0.014124     | 0.013946     |
| Skirstymas                          | 0.012996     | 0.007979     |
| Kietiakų rašymas į failą            | 0.423123     | 0.417823     |
| Varguolių rašymas į failą           | 0.308549     | 0.296763     |
| **Visas programos veikimo laikas:** | **1.614873** | **1.597195** |
## Realizuoti metodai
### front() ir back()
        T front(){ return *data; }
        T back(){ return *(avail-1); }
### reserve()
        void reserve(size_type n){
            if (capacity() < n)
                limit = data + n;
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
### push_back()
        void push_back(const T& val){
            if (avail == limit)
                grow();
            unchecked_append(val);
        }