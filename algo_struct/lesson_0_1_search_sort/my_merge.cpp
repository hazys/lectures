//
// Created by user on 27.11.2021.
//

int _binary(int element, int* a, int left, int right) {
    if ((right - left) > 1) {
        int center = (left + right) / 2;
        if (a[center] > element)
            return _binary(element, a, left, center);
        else if (a[center] < element)
            return _binary(element, a, center, right);
        else
            return center;
    } else {
        if (a[left] == element)
            return left;
        //if (a[right] == element)
        //    return right;
        return -1;
    };
}


int _my_merge(int* a, int* b, int* res, int la, int ra, int lb, int rb, int pos){
    if (ra - la < 2) {
        int tmp = _binary(a[la], b, lb, rb);
        if(tmp != -1){
            res[pos] = a[la];
            return pos + 1;
        }
        return pos;
    }
    if (rb - lb < 2) {
        int tmp = _binary(b[lb], a, la, ra);
        if(tmp != -1){
            res[pos] = b[lb];
            return pos + 1;
        }
        return pos;
    }
    int ma = (la + ra) / 2;
    int mb = (lb + rb) / 2;
    int a_min = a[la], a_mid = a[ma], a_max = a[ra-1];
    int b_min = b[lb], b_mid = b[mb], b_max = b[rb-1];

    int new_pos = pos;

    if (not ((a_mid < b_min) or (b_mid < a_min)))
        new_pos = _my_merge(a, b, res, la, ma, lb, mb, new_pos);

    if (not ((a_mid < b_mid) or (b_max < a_min)))
        new_pos = _my_merge(a, b, res, la, ma, mb, rb, new_pos);

    if (not ((a_max < b_min) or (b_mid < a_mid)))
        new_pos = _my_merge(a, b, res, ma, ra, lb, mb, new_pos);

    if (not ((a_max < b_mid) or (b_max < a_mid)))
        new_pos = _my_merge(a, b, res, ma, ra, mb, rb, new_pos);

    return new_pos;

}

int my_merge(int* a, int* b, int* res, int sizeA, int sizeB){
    return _my_merge(a, b, res, 0, sizeA, 0, sizeB, 0);

}
