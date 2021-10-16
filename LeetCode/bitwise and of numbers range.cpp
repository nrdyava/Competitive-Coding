class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return right;
        int shift = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            shift++;
        }
        
        return right<<shift;
    }
};