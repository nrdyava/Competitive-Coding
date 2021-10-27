class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for(int i=1; i<n; i++){
            int cn = curr.size();
            int j=0;
            string ans = "";
            while(j<cn){
                int count = 0;
                char c = curr[j];
                while(j<cn && c == curr[j]){
                    count++;
                    j++;
                }
                ans += to_string(count);
                ans += c;
            }
            curr = ans;
        }
        return curr;
    }
};