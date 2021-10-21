class Solution {
public:
    int rob(vector<int>& nums) {
	
	int len = nums.size();
	if (len == 1) return nums[0];
        	if (len == 2) return (max(nums[0],nums[1]));

	nums[2] = max(nums[2] + nums[0], nums[1]);
for (int i = 3; i < len; ++i){
	nums[i] = max((nums[i]+ nums[i-3]),max((nums[i]+ nums[i-2]), nums[i-1]));
}    

return nums[len-1];    
    }
};


