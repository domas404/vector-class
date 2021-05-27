#include "myvector.h"
#include "myvector.cpp"
#include <vector>
#include <chrono>

using hrClock = chrono::high_resolution_clock;

int main(){
    unsigned int sz = 100000000;
    double time_taken1=0;
    int count=0;
    for (int i=0; i<100; ++i){
        auto pr1 = chrono::high_resolution_clock::now();
        vector<int> v1;
        for (int i=1; i<= sz; ++i){
            v1.push_back(i);
            if(v1.size() == v1.capacity()) count++;
        }
        auto pab1 = chrono::high_resolution_clock::now();
        time_taken1 += chrono::duration_cast<chrono::nanoseconds>(pab1 - pr1).count();
        v1.clear();
    }
    time_taken1 *= 1e-9;
    cout << "std::vector push_back laikas: " << time_taken1/100 << " s" << endl;
    cout << count << endl;
    count=0;

    double time_taken2=0;
    for (int i=0; i<100; ++i){
        auto pr2 = chrono::high_resolution_clock::now();
        Vector<int> v2;
        for (int i=1; i<= sz; ++i){
            v2.push_back(i);
            if(v2.size() == v2.capacity()) count++;
        }
        auto pab2 = chrono::high_resolution_clock::now();
        time_taken2 += chrono::duration_cast<chrono::nanoseconds>(pab2 - pr2).count();
        v2.clear();
    }
    time_taken2 *= 1e-9;
    cout << "mano Vector push_back laikas: " << time_taken2/100 << " s" << endl;
    cout << count << endl;
}