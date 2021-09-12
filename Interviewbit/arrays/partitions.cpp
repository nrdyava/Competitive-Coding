int Solution::solve(int A, vector<int> &B) {
    vector<int> prefix, suffix;

    int count=0, currsum=0, tsum=0;

    for(int i=0; i<B.size(); i++) tsum+=B[i];
    

    if(tsum%3 != 0) return 0;

    for(int i=0; i<A; i++){
        currsum += B[i];
        if(currsum == tsum/3) prefix.push_back(i);
    }

    currsum = 0;
    for(int i=A-1; i>=0; i--){
        currsum += B[i];
        if(currsum == tsum/3) suffix.push_back(i);
    }

    for(int i=0; i<prefix.size(); i++){
        for(int j=0; j<suffix.size(); j++){
            if(prefix[i]<suffix[j]-1) count++;
        }
    }

    return count;

}
