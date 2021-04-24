int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for (int i=0;i<32;i++){
        int bit_pos_sum = 0;
        for (int j = 0;j<A.size();j++){
            bit_pos_sum += (A[j]>>i)&1;
        }
        ans = ans+((bit_pos_sum%3)<<i);
        
    }
    return ans;
}