class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int max_profit_till_now = 0;
        int min_ele_till_now = min(*prices.begin(), *(prices.begin()+1));
        max_profit_till_now =  max(*(prices.begin()+1) - *prices.begin(),0);
        for (auto i = prices.begin()+2; i!=prices.end();i++){
            max_profit_till_now = max(max_profit_till_now, *i - min_ele_till_now);
            if (*i < min_ele_till_now) min_ele_till_now = *i;
        }
        return max_profit_till_now;
    }
};