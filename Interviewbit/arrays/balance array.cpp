int Solution::solve(vector<int> &A) {
    int TO = 0;
    int TE = 0;
    int count = 0;
    for (int i =0; i < A.size(); i++) {
        if ((i+1)&1) {
            TO+=A[i];
        } else {
            TE+=A[i];
        }
    }
    
    // PE = Sum of all even index elements before i.
    // PO = Sum of all odd index elements before i.
    // EE = Effective sum of even index elements after eliminating A[i]
    // EO = Effective sum of odd index elements after eliminating A[i]
    int PE=0;
    int PO=0;
    int EE =0;
    int EO =0;
    for(int i =0; i < A.size(); i++) {
        if ((i+1)&1) {
            //odd index
            EO = PO + TE - PE;
            EE = PE + TO - PO - A[i];
            if (EO == EE) {
                count ++;
            }
            PO+=A[i];
        } else {
            //even index
            EO = PO + TE - PE - A[i];
            EE = PE + TO - PO;
            if (EO==EE) {
                count++;
            }
            PE+=A[i];
        }
    }
    return count;
        
}