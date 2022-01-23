//
// Created by user on 24.11.2021.
//


void merge(int* a, int* b, int* res, int size_a, int size_b) {
    int i = 0, j = 0, k = 0;
    while ((i < size_a) || (j < size_b))
        if((j >= size_b) || ((i < size_a) && (a[i] >= b[j])))
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
}


int binarySearch(int* a, int x, int left, int right){
    int l = left, r = right;
    int c, center;

    while((r-l) > 1){
        c = l + (r - l) / 2;
        center = a[c];

        if (x == center){
            return c;
        }
        if (x > center)
            l = c;
        else
            r = c;
    }
    if ((r < right) and (a[r] == x)) return r;
    if (a[l] == x) return l;

    if((a[left] > x) and (left == l))
        return -2; // вышли за диапозон слева
    if(r == right)
        return -3; // вышли за диапозон справа
    return -1; // нет внутри
}


int galopingBinarySearch(int* a, int x, int left, int right){
    for(int i = 1; (left + i) < right; i <<= 1){
        int res = binarySearch(a, x, left, left + i);
        if (res >= -2) return res;
    }
    return binarySearch(a, x, left, right);
}


int galopingMerge(int* a, int* b, int* res, int sizeA, int sizeB){
    int* minA = sizeA > sizeB ? b : a;
    int minSz = sizeA > sizeB ? sizeB : sizeA;
    int* maxA = sizeA > sizeB ? a : b;
    int maxSz = sizeA > sizeB ? sizeA : sizeB;
    int border = 0 , j = 0;
    for(int i=0; i<minSz; i++){
        int cur = minA[i];
        int idx = galopingBinarySearch(maxA, cur, border, maxSz);
        if (idx > 0){
            res[j++] = cur;
            border = idx + 1;
        }
    }
    return j;
}
