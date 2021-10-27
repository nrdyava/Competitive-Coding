class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int k=0;
        int i=n-1;
        
        while(i>=0){
            if(citations[i]>=k+1) k++, i--;
            else break;
        }
        return k;
    }
};