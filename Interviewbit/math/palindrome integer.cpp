int Solution::isPalindrome(int A) {
    if (A<0){
        return false;
    }
    
    int rev = 0;
    int org = A;
    
    while(org != 0){
        rev *= 10;
        rev += org%10;
        org = floor(org/10);
    }
    
    if (rev == A) return true;
    return false;
}
