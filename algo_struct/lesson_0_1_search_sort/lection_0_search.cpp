//
// Created by user on 04.11.2021.
//

int find_element_simple(int element, int* a, int size) {
    for (int i=0; i<size; i++)
        if (a[i] == element)
            return i;
    return -1;
}



int _bin_search(int element, int* a, int left, int right) {
    if ((right - left) > 1) {
        int center = (left + right) / 2;
        if (a[center] > element)
            return _bin_search(element, a, left, center);
        else if (a[center] < element)
            return _bin_search(element, a, center, right);
        else
            return center;
    } else {
        if (a[left] == element)
            return left;
        if (a[right] == element)
            return right;
        return -1;
    };
}


int find_element_binary(int element, int* a, int size){
    return _bin_search(element, a, 0, size - 1);
}


