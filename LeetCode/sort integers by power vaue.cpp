class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=lo;i<=hi;i++)
        {
            int count=0;
            int p=i;
            while(p!=1)
            {
               if(p%2==0)
                   p=p/2;
                else
                    p=(3*p)+1;
                count++;
            }
        pq.push({count,i});
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top().second;
    }
};