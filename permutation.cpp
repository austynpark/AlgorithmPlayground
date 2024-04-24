    vector<vector<int>> permute(vector<int>& nums) {

        int nums_size = nums.size();
        int unpicked_count = nums_size;
        vector<vector<int>> result;
        vector<bool> is_picked(nums_size, false);
        vector<int> possible_permute;

        recursive_permute(nums, nums_size, is_picked, nums_size, result, possible_permute);

        return result;
    }

    void recursive_permute(const vector<int>& nums, const int nums_size, vector<bool>& is_picked, int unpicked_count, vector<vector<int>>& result, vector<int>& possible_permute)
    {
        if(unpicked_count == 0) {
            result.push_back(possible_permute);
            return;
        }

        for(int i = 0; i < nums_size; ++i)
        {
            if(!is_picked[i])
            {
                is_picked[i] = true;
                possible_permute.push_back(nums[i]);
                recursive_permute(nums, nums_size, is_picked, unpicked_count - 1, result, possible_permute);
                is_picked[i] = false;
                possible_permute.pop_back();
            }
        }
    }