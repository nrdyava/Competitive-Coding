int marh(vector<int> &heights){
    int n = heights.size();

    stack<int> s;
    s.push(-1);

    vector<int> left_smaller(n, -1), right_smaller(n, n);
    int max_area = heights[0];

    int i=0;

    while(i<n){
        while(s.top()!=-1 && heights[s.top()] > heights[i]){
            right_smaller[s.top()] = i;
            s.pop();
        }

        if(i>0 && heights[i] == heights[i-1]){
            left_smaller[i] = left_smaller[i-1];
        }
        else{
            left_smaller[i] = s.top();
        }

        s.push(i);
        i++;
    }

    for(int i=0; i<n; i++){
        max_area = max(max_area, heights[i] * (right_smaller[i] - left_smaller[i] - 1));
    }

    return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();

    vector<int> dp(n, 0);

    int mra = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == 0) dp[j] = 0;
            else dp[j]++;
        }
        mra = max(mra, marh(dp));
    }

    return mra;
}
