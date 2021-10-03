class Solution {
public:
    
    bool helper(vector<int>& arr,int start , vector<bool>& visited){
        if(start >= arr.size() || start < 0){
            return false;
        }
        
        if(arr[start] == 0){
            return true;
        }
        
        if(visited[start] == false){
            visited[start] = true;
        } else {
            return false;
        }
        
       bool check = helper(arr , start - arr[start] , visited);
       
        if(check == false){
            check = helper(arr , start + arr[start] , visited);
        }
        return check;
    }
    
    bool canReach(vector<int>& arr, int start) {
       vector<bool> visited(arr.size() , false); 
       return helper(arr , start , visited);
    }
};