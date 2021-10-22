/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    bool isceleb(int i, int n){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(knows(i, j) || !knows(j, i)) return false;
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        int cand = 0;
        for(int i=0; i<n; i++){
            if(knows(cand, i)) cand = i;
        }
        return (isceleb(cand, n))?cand:-1;
    }
};