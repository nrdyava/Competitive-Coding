int searchutil(vector<int> A, int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (A[mid] == key)
        return mid;
 
    if (A[l] <= A[mid]) {
        if (key >= A[l] && key <= A[mid])
            return searchutil(A, l, mid - 1, key);
        return searchutil(A, mid + 1, h, key);
    }
 
    if (key >= A[mid] && key <= A[h])
        return searchutil(A, mid + 1, h, key);
 
    return searchutil(A, l, mid - 1, key);
}


int Solution::search(const vector<int> &A, int B) {
    return searchutil(A, 0, A.size() - 1, B);
}
