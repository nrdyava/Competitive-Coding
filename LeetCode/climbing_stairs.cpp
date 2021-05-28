class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n == 2) return 2;
        int mem_arr[n];
        mem_arr[0] = 1;
        mem_arr[1] = 2;
        for (int i=2;i<n;i++) mem_arr[i] = (mem_arr[i-1])+(mem_arr[i-2]);
        return mem_arr[n-1]; 
    }
};