//
// Created by user on 20.12.2021.
//

#ifndef LESSON_7_DP_STRING_DISTANCE_H
#define LESSON_7_DP_STRING_DISTANCE_H

#include <string>
#include <algorithm>

using namespace std;

int levenstein(string s1, string s2);
int levenstein_opt(string* s1, string* s2);
int damerau_levenstein(string* s1, string* s2);
int damerau_levenstein_opt(string* s1, string* s2);

int fuzzy_damerau_levenstein(string* s1, string* s2, int size = 3, int inf=INT32_MAX);

#endif //LESSON_7_DP_STRING_DISTANCE_H
