int bs(vector<int> &A, int left, int right, int &key){
    if(right < left) return 0;

    int mid = left + (right - left)/2;

    if(A[mid] == key) return 1;
    else if(A[mid] < key){
        return bs(A, mid + 1, right, key);
    }
    else return bs(A, left, mid - 1, key);
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();

    int left, right, mid;
    left = 0;
    right = n-1;

    while(left <= right){
        mid = left + (right - left)/2;

        if(A[mid][0] == B) return 1;
        if(A[mid][m-1] == B) return 1;

        if(A[mid][0] < B && A[mid][m-1] > B) return bs(A[mid], 0, m-1, B);

        if(A[mid][0] < B) left = mid + 1;
        if(A[mid][0] > B) right = mid - 1;
    }

    return 0;
}
