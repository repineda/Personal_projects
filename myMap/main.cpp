#include <iostream>
#include <string>
#include <cstdlib>
#include "myMap.h"


using namespace std;

int main()
{
    myMap<int,string> smap(5,"five");
    smap.insert(5, "five");
    smap.insert(4, "four");
    smap.insert(3, "three");
    smap.insert(2, "two");
    smap.insert(1, "one");
    smap.insert(0, "zero");
    cout<< "At testing" << endl;
    cout<< smap.at(0) << endl;
    cout<< smap.at(1) << endl;
    cout<< smap.at(2) << endl;
    cout<< smap.at(3) << endl;
    cout<< smap.at(4) << endl;
    cout<< smap.at(5) << endl;
    cout<< " at testing done" << endl;
    smap.clear();
    cout<<"cleared" << endl;
    smap.insert(5, "five");
    smap.insert(4, "four");
    smap.insert(3, "three");
    smap.insert(2, "two");
    smap.insert(1, "one");
    smap.insert(0, "zero");
    cout<< "reinserted" << endl;
    cout<< "At testing" << endl;
    cout<< smap.at(0) << endl;
    cout<< smap.at(1) << endl;
    cout<< smap.at(2) << endl;
    cout<< smap.at(3) << endl;
    cout<< smap.at(4) << endl;
    cout<< smap.at(5) << endl;
    cout<< " at testing done" << endl;
    cout << smap.count(4) << endl;
    cout <<"^^^^^ count" << endl;
    smap.emplace(6,"six");
    cout << "emaplaced 6 " << smap.at(6) << endl;
    smap.erase(0);
    cout << "erased 0 " << endl;
    smap.find(3);
    smap.lower_bound(3);
    cout << smap[3] << endl;

    return 0;
}

