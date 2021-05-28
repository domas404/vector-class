# Vector class

* Vector klasės realizacija.
* Šioje klasėje įgyvendintos 2-oje užduotyje naudotos std::vector funkcijos.
## *push_back* payginimas:
Palyginimui naudojami 100 iteracijų laiko vidurkiai.

|                             | 10'000   | 100'000  | 1'000'000 | 10'000'000 | 100'000'000 |
| --------------------------- | :---:    | :---:    | :---:     | :---:      | :---:       |
| std::vector                 | 4.985e-5 | 0.000369 | 0.002768  | 0.036885   | 0.299628    |
| mano Vector                 | 1.995e-5 | 0.000289 | 0.001900  | 0.030270   | 0.215559    |

Atliktų atminties perskirstymų skaičius, pildant 100'000'000 elementų failą:

* Naudojant std::vector - 27;
* Naudojant Vector klasę - 27.

## *std::vector* ir Vector palyginimas (v2.0)
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
* front()
* back()
* clear()
* pop_back()
* assign()
* reserve()
* resize()
* push_back()