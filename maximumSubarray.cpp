    int maxSubArray(vector<int>& nums) {
       int max_sum = nums[0];
       int sum = nums[0];
       int nums_size = nums.size();

        for(int i = 1; i < nums_size; ++i)
        {
            if(nums[i] > sum && sum < 0)
                sum = nums[i];
            else
                sum += nums[i];

            max_sum = max(sum, max_sum);
        }

       return max_sum; 
    }