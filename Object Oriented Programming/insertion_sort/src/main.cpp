#include "isort.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>


int main()
{
      std::vector<int> itried{3,2,7,6,9};
    insertion_sort_ind(itried);
    for(int j = 0; j < itried.size(); j++) cout << itried[j] << " ";

    cout << "\n";
    std::list<string> L{"tri","dvadeset","jedan", "nula"};
    insertion_sort(L.begin(), L.end());
    list<string>::iterator li;
    for( li = L.begin(); li != L.end(); ++li ) {
        string element = *li;
        cout << element << " ";
    };



    return 0;
}
