/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval &a, Interval &b){
    return a.start < b.start;
}

vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    A.push_back(newInterval);
    sort(A.begin(), A.end(), comp);
    vector<Interval> res;

    res.push_back(A[0]);
    int n = A.size();

    for(int i=1; i<n; i++){
        if(A[i].start <= res[res.size()-1].end) res[res.size()-1].end=max(res[res.size()-1].end,A[i].end);
        else res.push_back(A[i]);
    }

    return res;
}
