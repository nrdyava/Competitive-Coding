class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.end());
        
        while(!ms.empty()){
            int a = *ms.begin();
            for(int i=a; i<a+k; i++){
                auto itr = ms.find(i);
                if(itr==ms.end()) return false;
                ms.erase(itr);
            }
        }
        return true;
    }
};