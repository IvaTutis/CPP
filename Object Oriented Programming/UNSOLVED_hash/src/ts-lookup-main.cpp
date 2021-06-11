#include "ts-lookup.h"

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <optional>
#include <thread>
#include <array>
#include <algorithm>

// TODO samo testiranje paralelne verzije koda.
//Konačno u metodi m̀ain() (datoteka main.cpp) treba testirati samo paralelnu verziju koda.
//Napraviti smisleni test program koji će testirati cijelu klasu, ili barem njen veći dio.

//koristimo thread safe hash table
HashTable<int, int> H;

// za ispis dobivenih vrijednosti 
std::array<std::vector<int>, 3>  v;

//stop zastavica
std::atomic<bool> stop{ false };

//DONE - u svima sa key=> value je n=>n-1 osim u n=100 gdje je 100=>101
void generator() {
    int n = 1;
    while (n <= 100) {
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
        H.add_or_update(n, n - 1);
        if (n = 100) H.add_or_update(n, n + 1); 
        n++;
    }
    stop.store(true);
}

//miče sve sa ključevima djeljivima sa 3, do završetka glavne dretve. ako uspije remove-ati, taj ključ baca u vektor rezultata
//idealno, trebali bi biti više manje poredani od najnižega prema najvišemu
void remover(std::vector<int>& vec) {
    while (true) {
        for (int i = 0; i <= 100; i++) {
            if (i % 3 == 0) {
                bool b = H.remove(i);
                if (b)vec.push_back(i);
            };
        };
         if (stop.load()) return;
        }
    }

//traži sve vrijednosti parnih ključeva i sprema ih u rezultat
//opet, ovo mora biti rastuće, iako će možda neke vrijednosti biti maknute ako remover thread stigne prije do njih
void lookup(std::vector<int>& vec) {
    int i = 0; 
    while (true) {
        while (i <= 100) {
            if (i % 2 == 0) {
                std::optional<int> val = H.value(i);
                if (val.has_value()) vec.push_back(i);
            };
            i++;
        };
        if (stop.load()) return;
    }
}

//peovjerava za svaku peti ključ da li odgovara na predikat i sprema ga u rezultat
//tu bi trebali biti svi (osim djeljivih s 3 kojih se remover prije dohvati) osim 100

bool p(std::pair<int, int> p)
{
 
    bool b = (p.first % 5 == 0);

    return b;
}

void predicator(std::vector<int>& vec) {
    int i = 0;
    while (true) {
        while (i <= 100) {
            if (i % 5 == 0) {
                std::optional<std::pair<int,int>> val = H.find_if(p);
                if (val.has_value()) vec.push_back(val->first);
            };
            i++;
        };
        if (stop.load()) return;
    }
}


int main(){
    
    //inicijaliziram threadove
    std::thread t1(generator);
    std::thread t2(remover, std::ref(v[0]));
    std::thread t3(lookup, std::ref(v[1]));
    std::thread t4(predicator, std::ref(v[2]));

    //spajam threadove
    t1.join();
    t2.join();
    t3.join();
    t4.join(); 

    // Testiranje. Vrijednosti moraju biti sortirane
    if (std::is_sorted(v[0].begin(), v[0].end()))
        std::cout << "v[0] is sorted\n";
    else
        std::cout << "v[0] is NOT sorted\n";


    if (std::is_sorted(v[1].begin(), v[1].end()))
        std::cout << "v[1] is sorted\n";
    else
        std::cout << "v[1] is NOT sorted\n";



    if (std::is_sorted(v[2].begin(), v[2].end()))
        std::cout << "v[2] is sorted\n";
    else
        std::cout << "v[2] is NOT sorted\n";

    std::cout << "Received size = " << v[0].size() + v[1].size() + v[2].size() << std::endl;
    //    std::vector<int> all(100);


    return 0;
}

