    int minSubArrayLen(int target, vector<int>& nums) {
        int nums_size = nums.size();
        int sum = 0;
        int begin = 0;
        int end = 0;
        int length = INT_MAX;

        while(end < nums_size)
        {
            sum += nums[end];

            while(sum >= target)
            {
                length = min(length, end - begin + 1);
                sum -= nums[begin];
                ++begin;
            }

            ++end;
        }
   
        return length == INT_MAX ? 0 : length;
    }