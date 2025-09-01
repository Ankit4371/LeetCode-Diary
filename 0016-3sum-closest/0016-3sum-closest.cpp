class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close=INT_MAX;
        int ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            
            int second = i+1;
            int third = n-1;
            while(second<third){
                int sum = nums[i] + nums[second] + nums[third] ;
                if(sum== target){
                    return sum;
                }else if(sum > target){
                    int dist = abs(target-sum);
                    if(dist < close) {
                        close = dist;
                        ans= sum;
                    }
                    third--;
                }else {
                    int dist = abs(target-sum);
                    if(dist < close) {
                        close = dist;
                        ans= sum;
                    }
                    second++;
                }
            }
        }
        return ans;
    }
};