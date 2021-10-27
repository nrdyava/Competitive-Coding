class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), [](const int&x, const int &y){return x>y;});
        
        int i=0;
        while(i<n){
            if(citations[i]>=i+1) i++;
            else break;
        }
        return i;
    }
};n