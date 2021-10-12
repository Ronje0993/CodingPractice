class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        	unordered_map<int, int> hash_table;
	        vector<int> result(2);
	for (int i = 0; i < nums.size(); i++){
		if ( hash_table.find( nums[i] ) != hash_table.end() ){
			result[0] = hash_table[nums[i]];
			result[1] = i;
            break;
		} else {
			hash_table.insert(make_pair(target - nums[i], i));
		}
	}
	return result; 
    }
};

