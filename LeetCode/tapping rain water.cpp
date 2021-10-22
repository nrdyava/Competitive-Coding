class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        
        stack<int> lstack, rstack;
        
        lstack.push(height[0]);
        rstack.push(n-1);
        
        
        for(int i=n-2; i>0; i--){
            if(height[i]>height[rstack.top()]) rstack.push(i);
        }
        
        int ans = 0;
        
        for(int i=1; i<n-1; i++){
            while(rstack.top()<=i) rstack.pop();
            
            if(lstack.top()>height[i] && height[rstack.top()]>height[i]) ans += (min(lstack.top(), height[rstack.top()]) - height[i]);
            
            if(height[i]>lstack.top()) lstack.push(height[i]);
        }
        return ans;
    }
};