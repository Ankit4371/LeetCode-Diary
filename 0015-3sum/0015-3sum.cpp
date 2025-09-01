class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // we don't want duplicates
        // O(n3) brute force
        // O(n2) using sort & 2 pointer
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n-2;i++){
            int first = nums[i];
            // it is sorted.
            if(first>0)break;
            
            
            int target = 0-nums[i];
            
            // 2 pointer technique
            int start = i+1;
            // remove duplicate for i!=j wrong i & j both can have -1 but is should be different indexes
            // while(start<n && nums[start] == first )start++;
            
            int end = n-1;
            // optimization. wrong. i,j,k can be 0 0 0 with diff indexes.
            // if(nums[end]==nums[i] || nums[start]==nums[end])continue;
            
            while(start<end){
                int sum = nums[start] + nums[end];
                
                if(sum == target){
                    int second = nums[start];
                    int third = nums[end];
                    ans.push_back({first,second,third});
                    // what to do here. imp.
                    // remove dulicates for second & third.
                    while(start<end && nums[start] == second)start++;
                    while(start<end && nums[end] == third)end--;
                }
                else if(sum<target){
                    start++;
                }else{
                    end--;
                }
//                 
                
            }
            // removing duplicates for first
            while(i<n-1 && nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};