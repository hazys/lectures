#include <iostream>
#include "string_distance.h"
#include <string>

using namespace std;


int main() {

    //string s1 = "mother2";
    //string s2 = "father1";

    //string s1 = "мама";
    //string s2 = "папа";

    //string s1 = "bababa";
    //string s2 = "abbaab1";

    string s1 = "bababa";
    string s2 = "bbb1aba";

    std::cout << levenstein(s1, s2) << std::endl;
    std::cout << levenstein_opt(&s1, &s2) << std::endl;
    std::cout << damerau_levenstein(&s1, &s2) << std::endl;
    std::cout << damerau_levenstein_opt(&s1, &s2) << std::endl;
    std::cout << fuzzy_damerau_levenstein(&s1, &s2, 10) << std::endl;

    return 0;
}
