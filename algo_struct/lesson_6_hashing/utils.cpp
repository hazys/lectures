//
// Created by user on 18.12.2021.
//

#include "utils.h"


int hash_int(int x, int max_value){
    int p = 31;
    int m = 2063074129;
    return ((p * x) % max_value + m) % max_value;
}
int hash_string(string s, int max_value){
    int p = 31;
    int m = 2063074129;
    int res = s[0];
    for (int i = 1; i < s.size(); i++)
        res = ((p * res) % max_value + m) % max_value;
    return res;

}