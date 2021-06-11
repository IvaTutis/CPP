#ifndef _ISORT_H_ 
#define _ISORT_H_ 


using namespace std;
#include <vector>
#include <iterator>
#include <algorithm>
// Verzija s indeksima
template <typename Record>
void insertion_sort_ind(std::vector<Record> &vec)
{
     int i, j, duljina = vec.size( );
     Record key;
     for(j = 1; j < duljina; j++)
    {
           key = vec[j];
           for(i = j - 1; (i >= 0) && (vec[i] < key); i--)
          {
                 vec[i+1] = vec[i];
          }
         vec[i+1] = key;
    }
     return;
}


// Verzija koja uzima iterator range -- koristiti samo std::next i std::prev
template <typename Iter>
void insertion_sort(Iter first, Iter last) {
    if( first == last ) return;

    Iter i, j, temp;
    for(i = std::next(first); std::next(i)!=last; i=std::next(i))
    {
        temp=i;
       for(j = std::prev(i); (j!=first) && (*j < *temp); j = std::prev(j))
        {
            swap (*j, *temp);
            temp=std::prev(temp);
        }
    }
     return;
}

// verzija sa algoritmima std::rotate i std::upper_bound
template <typename Iter>
void insertion_sort1(Iter first, Iter last) {
   for (Iter it = first; it != last; ++it)
        std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
    return;
}


#endif
