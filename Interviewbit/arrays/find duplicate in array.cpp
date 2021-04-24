int Solution::repeatedNumber(const vector<int> &A) {
        int n = A.size();
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += A[i];
        }
        long long int m = n-1;
        long long int total = (m * (m+1)) / 2;
        return sum - total;
    }