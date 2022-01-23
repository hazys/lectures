//
// Created by user on 04.11.2021.
//

#include <cstdlib>

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int* a, int size){
    for (int i = 0; i < size; i++) {
        int max = a[i], max_idx = i;
        for (int j = i + 1; j < size; j++)
            if (max < a[j])
                max = a[j], max_idx = j;
        swap(a[i], a[max_idx]);
    }
}

void bubbleSort(int* a, int size){
    for (int i = 0; i < size; i++) {
        bool fl = true;
        for (int j = 0; j < size-i-1; j++)
            if (a[j] < a[j+1])
                swap(a[j], a[j+1]), fl = false;
        if (fl) return;
    }
}

void insertionSort(int* a, int size){
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0; j--)
            if (a[j] > a[j-1])
                swap(a[j], a[j-1]);
            else
                break;
    }
}


void _merge(int* a, int* b, int* res, int size_a, int size_b) {
    int i = 0, j = 0, k = 0;
    while ((i < size_a) || (j < size_b))
        if((j >= size_b) || ((i < size_a) && (a[i] >= b[j])))
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
}


int* _msplit(int* a, int size){
    if (size == 1){
        int* res = new int[1];
        res[0] = a[0];
        return res;
    } else {
        int center = size / 2;
        int* res = new int[size];
        int* l = _msplit(a, center);
        int* r = _msplit(&a[center], size - center);
        _merge(l, r, res, center, size-center);
        delete [] l;
        delete [] r;
        return res;
    }
}


void mergeSort(int* a, int size){
    int* res = _msplit(a, size);
    for(int i=0; i<size; i++) a[i] = res[i];
    delete [] res;
}






/*
function merge(a : int[n]; left, mid, right : int):
it1 = 0
it2 = 0
result : int[right - left]

while left + it1 < mid and mid + it2 < right
if a[left + it1] < a[mid + it2]
result[it1 + it2] = a[left + it1]
it1 += 1
else
result[it1 + it2] = a[mid + it2]
it2 += 1

while left + it1 < mid
        result[it1 + it2] = a[left + it1]
it1 += 1

while mid + it2 < right
        result[it1 + it2] = a[mid + it2]
it2 += 1

for i = 0 to it1 + it2
        a[left + i] = result[i]


function mergeSortRecursive(a : int[n]; left, right : int):
if left + 1 >= right
return
mid = (left + right) / 2
mergeSortRecursive(a, left, mid)
mergeSortRecursive(a, mid, right)
merge(a, left, mid, right)


function mergeSortIterative(a : int[n]):
for i = 1 to n, i *= 2
for j = 0 to n - i, j += 2 * i
        merge(a, j, j + i, min(j + 2 * i, n))

*/


void _mergeAB(int res[], int a[], int b[], int sizeA, int sizeB){
    for(int i = 0, j = 0, k = 0; k < sizeA + sizeB; k++){
        if (i == sizeA) {res[k] = b[j++]; continue;}
        if (j == sizeB) {res[k] = a[i++]; continue;}
        res[k] = (a[i] < b[j] ? a[i++] : b[j++]);
    }
}

void _merge(int a[], int l, int m, int r){
    //инициализация индексов
    int it1 = l;
    int it2 = m;
    int itr = 0;

    //выделение дополнительной памяти в стеке
    int result[r - l];

    while ((it1 < m) || (it2 < r))
        if ((it1 >= m) || ((it2 < r) && (a[it1] < a[it2])))
            result[itr++] = a[it2++];
        else
            result[itr++] = a[it1++];

    for (int i = 0; i < r-l; i++)
        a[l + i] = result[i];
}

void _mergeSortRecursive(int a[], int left, int right) {
    if (left + 1 >= right)
       return;
    int mid = left + (right - left) / 2;
    _mergeSortRecursive(a, left, mid);
    _mergeSortRecursive(a, mid, right);
    _merge(a, left, mid, right);
}

#define MIN(a, b) a > b ? b : a

void mergeSortIterative(int* a, int size){
    for (int i = 1; i < size; i *= 2)
        for (int j = 0; j < size - i; j += 2 * i)
            _merge(a, j, j + i, MIN(j + 2 * i, size));
}


void mergeSortRecursive(int* a, int size){
    _mergeSortRecursive(a,0, size);
}



// radix Sort

int _getMax(int a[], int size){
    int mx = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void _countSort(int a[], int size, int exp)
{
    int result[size];
    int i, count[10] = { 0 };

    for (i = 0; i < size; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        result[--count[d]] = a[i];
    }

    for (i = 0; i < size; i++)
        a[i] = result[size - i - 1];
}

void radixSort(int a[], int size){
    int m = _getMax(a, size);
    for (int exp = 1; m / exp > 0; exp *= 10)
        _countSort(a, size, exp);
}


// bitonic

void _bitonicSwap(int a[], int i, int j, int dir){
    if (dir==(a[i]>a[j]))
        swap(a[i],a[j]);
}

int powerOfTwo(int x) {
    if ((x & (x - 1)) == 0)
        return x >> 1;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x - (x >> 1);
}


void _bitonicMerge(int a[], int l, int r, int dir){
    if (r - l > 1)    {
        int k = powerOfTwo( r - l );
        //for (int i = l; i < l + k; i++)
        for (int i = l; i < r - k; i++)
            _bitonicSwap(a, i, i + k, dir);
        _bitonicMerge(a, l, l + k, dir);
        _bitonicMerge(a, l + k, r, dir);
    }
}

void _bitonicSort(int a[], int l, int r, int dir){
    if (r - l > 1){
        int k = (r - l) / 2;
        _bitonicSort(a, l, l + k, !dir);
        _bitonicSort(a, l + k, r, dir);
        _bitonicMerge(a, l, r, dir);
    }
}


void bitonicSort(int a[], int size){
    _bitonicSort(a, 0, size, 1);

}

/*
void bitonicSort(int a[], int size){
    for (int k = 2; k <= size; k *= 2) // k is doubled every iteration
        for (int j = k/2; j > 0; j /= 2) // j is halved at every iteration, with truncation of fractional parts
            for (int i = 0; i < size; i++){
                int l = i ^ j; // in C-like languages this is "i ^ j"
                if (l > i)
                    if ((((i & k) == 0) && (a[i] > a[l])) || (((i | k) != 0) && (a[i] < a[l])))
                        swap(a[i], a[l]);
            }
}
*/

// timsort

// heapsort

/*
void _heapify(int a[], int size, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && a[l] > a[largest])
        largest = l;

    if (r < size && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        _heapify(a, size, largest);
    }
}
*/


void siftUP(int a[], int item, int& size){
    a[size] = item;
    int i = size;
    while((i > 0) && (a[(i - 1) / 2] < a[i])) {
        swap(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
}

int siftDown(int a[], int item_idx, int& size){
    int res = a[item_idx];
    a[item_idx] = a[--size];
    int i = item_idx;
    while(true){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_el = i;
        if ( (l < size + 1) && (a[l] > a[min_el]) ) min_el = l;
        if ( (r < size + 1) && (a[r] > a[min_el]) ) min_el = r;
        if (min_el == i) break;
        swap(a[i], a[min_el]);
        i = min_el;
    }
    return res;
}


void _heapify(int a[], int size){
    for(int i = 0; i < size; i++){
        int size = i;
        siftUP(a, i, size);
    }
}

void heapSort(int a[], int size){
    _heapify(a, size);

    int n = size;
    for(int i=0; i<size; i++){
        int tmp = siftDown(a, 0, n);
        a[n] = tmp;
    }
}


/*
void heapSort(int a[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        _heapify(a, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(a[0], a[i]);
        _heapify(a, i, 0);
    }
}
*/










int _partition (int* a, int l, int r)
{
    int p = a[r], i = l - 1;
    for (int j = l; j <= r - 1; j++)
        if (a[j] >= p)
            swap(a[++i], a[j]);
    swap(a[i+1], a[r]);
    return ++i;
}


void _quick(int* a, int l, int r)
{
    if (l < r){
        int pi = _partition(a, l, r);
        _quick(a, l, pi - 1);
        _quick(a, pi + 1, r);
    }
}

void quickSort(int* a, int size){
    _quick(a, 0, size - 1);
}




void bucketSort(int* a, int size, int num_buckets, int max_elemet){
    int** buckets = new int*[num_buckets];
    int* idx = new int [num_buckets];
    for(int i=0; i < num_buckets; i++){
        buckets[i] = new int [size];
        idx[i] = 0;
    }

    int div = (max_elemet + num_buckets) / num_buckets;
    for (int i=0; i<size; i++){
        int b_idx = a[i] / div;
        buckets[b_idx][idx[b_idx]++] = a[i];
    }

    for (int i = 0; i < num_buckets; i++)
        quickSort(buckets[i], idx[i]);

    int k = 0;
    for (int i = num_buckets-1; i >= 0; i--)
        for (int j = 0; j < idx[i]; j++)
            a[k++] = buckets[i][j];

    delete [] idx;
    for(int i=0; i < num_buckets; i++)
        delete [] buckets[i];
    delete [] buckets;


}



void countSort(int* a, int size, int max_elemet){
    int* elements = new int [max_elemet+1];
    for(int i=0; i < max_elemet+1; i++){
        elements[i] = 0;
    }

    for (int i=0; i<size; i++){
        elements[a[i]]++;
    }

    int k =0;
    for (int i = max_elemet; i >= 0; i--)
        for(int j= 0; j<elements[i]; j++)
            a[k++] = i;

    delete [] elements;
}



void _merge1(int* a, int* b, int* res, int size_a, int size_b) {
    int i = 0, j = 0, k = 0;
    while ((i < size_a) || (j < size_b))
        if((j >= size_b) || ((i < size_a) && (a[i] <= b[j])))
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
}

void _merge2(int a[], int b[], int res[], int sizeA, int sizeB){
    for(int i = 0, j = 0, k = 0; k < sizeA + sizeB; k++){
        if (i == sizeA) {res[k] = b[j++]; continue;}
        if (j == sizeB) {res[k] = a[i++]; continue;}
        res[k] = (a[i] < b[j] ? a[i++] : b[j++]);
    }
}

void _merge3(int a[], int temp[], int l, int m, int r){
    int i, j;
    //for(i=m+1; i>1; i--) temp[i-1] = a[i-1];
    for(i=m-1; i>=l; i--) temp[i] = a[i];
    //for(j=m; j<r; j++) temp[r+m-j] = a[j+1];
    for(j=m; j<r; j++) temp[r+m-j-1] = a[j];
    //for(int k = l, j = r - 1, i = l; k <= r; k++)
    for(int k = l, j = r - 1, i = l; k < r; k++)
        if(temp[j] < temp[i])
            a[k] = temp[j--];
        else
            a[k] = temp[i++];
}

void _mergeSort1(int a[], int temp[], int l, int r){
    if(r <= l + 1) return;
    int m = (r + l) / 2;
    _mergeSort1(a, temp, l, m );
    _mergeSort1(a, temp, m, r);
    _merge3(a, temp, l, m, r);
}

void mergeSortDown(int a[], int size){
    int temp[size];
    _mergeSort1(a, temp, 0, size);
}



void _mergeSortABr(int a[], int b[], int l, int r){
    if(r <= l + 1) return;
    int m = (r + l) / 2;
    _mergeSortABr(b, a, l, m );
    _mergeSortABr(b, a, m, r);
    _merge2(b + l, b + m, a + l, m - l, r - m);
}

void  _mergeSortAB(int a[], int l, int r){
    int temp[r];
    for (int i=l; i<r; i++) temp[i] = a[i];
    _mergeSortABr(a, temp, l, r);
}

void  mergeSortAB(int a[], int size){
    _mergeSortAB(a, 0, size);
}

inline int min(int a, int b){
    return a < b ? a : b;
}

void _mergeSortUP(int a[], int l, int r){
    int temp[r];
    for(int m=1; m<r; m=m+m)
        for (int i = l; i <= r-m ; i+= m+m) {
            _merge3(a, temp, i, i+m, min(i + m + m, r));

        }
}

void mergeSortUP(int a[], int size){
    _mergeSortUP(a, 0, size);
}





// модернизированный свап
void _iswap(int* xs, int i, int j) {
    int tmp = xs[i]; xs[i] = xs[j]; xs[j] = tmp;
}

// модернизированное слияние
void _imerge(int* a, int i, int m, int j, int n, int w) {
    while (i < m && j < n)
        _iswap(a, w++, a[i] < a[j] ? i++ : j++);
    while (i < m)
        _iswap(a, w++, i++);
    while (j < n)
        _iswap(a, w++, j++);
}

// заголовок функции
void _imsort(int* a, int l, int r);

// классическое слияние, модернизированное для работы inplace
void _isort(int* a, int l, int r, int w) {
    int m;
    if (r - l > 1) {
        m = l + (r - l) / 2;
        _imsort(a, l, m);
        _imsort(a, m, r);
        _imerge(a, l, m, m, r, w);
    }
    else
        // переброска буферов
        while (l < r)
            _iswap(a, l++, w++);
}

// основная процедура, управляет порядком слияния
void _imsort(int* a, int l, int r) {
    int m, n, w;
    if (r - l > 1) {
        m = l + (r - l) / 2;
        w = l + r - m;
        _isort(a, l, m, w); // сортировка второй половины
        while (w - l > 2) {
            n = w;
            w = l + (n - l + 1) / 2;
            _isort(a, w, n, l);  // сортировка половины от предыдущей рабочей зоны
            _imerge(a, l, l + n - w, n, r, w); // слияние 1/4 и 1/2 во 2-ю 1/4
        }
        for (n = w; n > l; --n) // сортировка вставками, когда дошли до 2-х элементов
            for (m = n; m < r && a[m] < a[m - 1]; ++m)
                _iswap(a, m, m - 1);
    }
}

void mergeSortInplace(int a[], int size){
    _imsort(a, 0, size);
}





int  _kpartition(int a[], int l, int r){
    int p_idx = rand() % (r - l), p = a[l + p_idx], k = l;
    for(int i = l; i < r; i++) {
        if (a[i] < p) swap(a[i], a[k++]);
    }
    return k;
}


int kStatistic(int a[], int k, int l, int r){
    if (r - l == 1)  return a[l];
    if (r - l == 2) {
        if (a[l] > a[l + 1])
            swap(a[l], a[l + 1]);
        return a[k - 1];
    }

    int p = _kpartition(a, l, r);
    if(p >= k ) {
        if (p == r) p = l + (r - l) / 2;
        return kStatistic(a, k, l, p);
    }
    if(p < k ) {
        if (p == l) p = l + (r - l) / 2;
        return kStatistic(a, k, p, r);
    }
}


