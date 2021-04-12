int Solution::reverse(int A) {
    int sign = A/abs(A);
    
    int org = abs(A);
    int rev = 0;
    
    while(org != 0){
        if (rev > 214748364){
            return 0;
        }
        if (rev == 214748364 and org%10 >7){
            return 0;
        }
        rev *= 10;
        rev += org%10;
        org = floor(org/10) ;
    }
    return sign*rev;
}