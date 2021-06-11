#include <gtest/gtest.h>
#include "../src/lookup-seq.h"

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <optional>
#include <thread>
#include <array>
#include <algorithm>

using namespace std;

TEST(hash_seq, Zadatak) {

    HashTable<int, int> H;
    int intended_result; 
    int result;
    bool bool_intended_result;
    bool bool_result;

    //add i lookup test
    H.add_or_update(2,3);
    intended_result=3; 
    result = 0; 
    std::optional<int> val = H.value(2);
    if (val.has_value()) result= val->first;
    ASSERT_EQ(intended_result, result);


    //update test
    H.add_or_update(2, 4);
    intended_result = 4;
    result = 0;
    std::optional<int> val = H.value(2);
    if (val.has_value()) result = val->first;
    ASSERT_EQ(intended_result, result);

    //remove test
    H.remove(2);
    bool_intended_result = false;
        bool_result = false;
    std::optional<int> val = H.value(2);
    if (val.has_value()) bool_result=true;
    ASSERT_EQ(bool_intended_result, bool_result);

    
   //find_if_test
    bool p(std::pair<int, int> p)
    {

        bool b = (p.first % 5 == 0);

        return b;
    }
    H.add_or_update(2, 3);
    std::optional<std::pair<int, int>> val = H.find_if(p);
    bool_intended_result = false;
    result = false;
    if (val.has_value()) bool_result=true;
    ASSERT_EQ(bool_intended_result, bool_result);

    H.add_or_update(5, 3);
    bool_intended_result = true;
    result = false;
    if (val.has_value()) bool_result = true;
    ASSERT_EQ(bool_intended_result, bool_result);


    //find_all test
    bool p(std::pair<int, int> p)
    {

        bool b = (p.first % 7 == 0);

        return b;
    }
    H.add_or_update(2, 3);
    std:list<std::pair<int, int>> val = H.find_all(p);
    bool_intended_result = false;
    result = false;
    if (!val.empty()) bool_result = true;
    ASSERT_EQ(bool_intended_result, bool_result);

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
