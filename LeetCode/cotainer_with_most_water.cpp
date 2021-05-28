class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int area = 0;
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        while(ptr1 < ptr2) {
            area = (ptr2-ptr1)*min(height[ptr1], height[ptr2]);
            max_area = max(area, max_area);
            if (height[ptr1]<height[ptr2]) ptr1++;
            else ptr2--;
        }
        return max_area;
    }
};