//
// Created by user on 20.12.2021.
//

#include "string_distance.h"



using namespace std;

int levenstein(string s1, string s2){

    int** t = new int*[s1.size()+1];
    for (int i = 0; i < s1.size()+1;i++)
        t[i] = new int[s2.size() + 1];

    for (int i = 0; i <= s1.size(); i++)
        for (int j = 0; j <= s2.size(); j++)
            if ((i == 0) or (j == 0))
                    t[i][j] = i + j;
            else
                if (s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1];
                else {
                    t[i][j] = min(t[i - 1][j], t[i][j - 1]);
                    t[i][j] = min(t[i][j], t[i - 1][j - 1]);
                    t[i][j]++;
                };
    int result = t[s1.size()][s2.size()];

    for (int i = 0; i < s1.size()+1;i++)
        delete[] t[i];
    delete[] t;

    return result;
}

int levenstein_opt(string* s1, string* s2){

    if (s1->size() > s2->size())
        swap(s1, s2);

    int* curr = new int[s1->size() + 1];
    int* prev = new int[s1->size() + 1];

    for (int i = 0; i <= s2->size(); i++) {
        for (int j = 0; j <= s1->size(); j++)
            if ((i == 0) or (j == 0))
                curr[j] = i + j;
            else if ((*s2)[i - 1] == (*s1)[j - 1])
                curr[j] = prev[j - 1];
            else {
                curr[j] = min(prev[j], curr[j - 1]);
                curr[j] = min(curr[j], prev[j - 1]);
                curr[j]++;
            };
        swap(curr, prev);
    };
    int result = prev[s1->size()];

    delete[] curr;
    delete[] prev;

    return result;


}

int damerau_levenstein(string* s1, string* s2){
    int** t = new int*[s1->size()+1];
    for (int i = 0; i < s1->size()+1;i++)
        t[i] = new int[s2->size() + 1];

    for (int i = 0; i <= s1->size(); i++)
        for (int j = 0; j <= s2->size(); j++)
            if ((i == 0) or (j == 0))
                t[i][j] = i + j;
            else {
                if ((*s1)[i - 1] == (*s2)[j - 1])
                    t[i][j] = t[i - 1][j - 1];
                else {
                    t[i][j] = min(t[i - 1][j], t[i][j - 1]);
                    t[i][j] = min(t[i][j], t[i - 1][j - 1]);
                    t[i][j]++;
                };
                if ((i > 1) and (j > 1) and ((*s1)[i-2] == (*s2)[j-1])  and ((*s1)[i-1] == (*s2)[j-2]))
                    t[i][j] = min(t[i][j], t[i-2][j-2] + 1);
            }
    int result = t[s1->size()][s2->size()];

    for (int i = 0; i < s1->size()+1;i++)
        delete[] t[i];
    delete[] t;

    return result;

}


int damerau_levenstein_opt(string* s1, string* s2){
    if (s1->size() > s2->size())
        swap(s1, s2);

    int* data = new int[3 * (s1->size() + 1)];

    int* curr = data;
    int* prev = &data[s1->size() + 1];
    int* prevprev = &data[2 * (s1->size() + 1)];

    for (int i = 0; i <= s2->size(); i++) {
        for (int j = 0; j <= s1->size(); j++)
            if ((i == 0) or (j == 0))
                curr[j] = i + j;
            else {
                if ((*s2)[i - 1] == (*s1)[j - 1])
                    curr[j] = prev[j - 1];
                else {
                    curr[j] = min(prev[j], curr[j - 1]);
                    curr[j] = min(curr[j], prev[j - 1]);
                    curr[j]++;
                };
                if ((i > 1) and (j > 1) and ((*s1)[i-2] == (*s2)[j-1])  and ((*s1)[i-1] == (*s2)[j-2]))
                    curr[j] = min(curr[j], prevprev[j-2] + 1);

            };
        swap(prevprev, curr);
        swap(prev, prevprev);
    };
    int result = prev[s1->size()];

    delete[] data;

    return result;
}


inline int MIN(int a, int b){
    return a > b ? b : a;
}

int fuzzy_damerau_levenstein(string* s1, string* s2, int size, int inf){
    if (s1->size() > s2->size())
        swap(s1, s2);

    size = size > s1->size() ? s1->size() : size;

    int* data = new int[3 * (size + 1)];

    int* curr = data;
    int* prev = &data[size + 1];
    int* prevprev = &data[2 * (size + 1)];

    prev[size] = inf;
    for (int j = 0; j < size; j++)
        prev[j] = j;

    for (int i = 1; i <= s2->size(); i++) {
        curr[size] = inf;
        for (int j = 0; j < MIN(size, s1->size() - i); j++){
            if ((*s1)[i - 1] == (*s2)[i + j - 1])
                curr[j] = prev[j];
            else {
                curr[j] = min(prev[j], prev[j + 1]);
                if (j > 0) curr[j] = min(curr[j], curr[j - 1]);
                curr[j]++;
            };
            if ((i > 1) and ((*s1)[i-2] == (*s2)[j-1])  and ((*s1)[i-1] == (*s2)[j-2]))
                curr[j] = min(curr[j], prevprev[j] + 1);
        };
        swap(prevprev, curr);
        swap(prev, prevprev);
    };

    int result = prev[0];
    delete[] data;
    return result;
}

