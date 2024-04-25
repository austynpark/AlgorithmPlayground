    vector<string> letterCombinations(string digits) {
        int digit_len = digits.length();

        std::vector<std::vector<char>> possible_letters = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        std::vector<string> result;
        std::string comb_num;

        if(digit_len == 0)
            return result;

        backTracking(possible_letters, digits, 0, result, comb_num);

        return result;
    }

    void backTracking(const std::vector<std::vector<char>>& possible_letters, const string& digits, int current_digit, std::vector<string>& result, std::string& comb_num) {

        int digit_len = digits.length();

        if(current_digit == digit_len)
        {
            result.push_back(comb_num);
            return;
        }

        int digit = digits[current_digit] - '2';
        for(int j = 0; j < possible_letters[digit].size(); ++j)
        {
            comb_num.push_back(possible_letters[digit][j]);
            backTracking(possible_letters, digits, current_digit + 1, result, comb_num);
            comb_num.pop_back();
        }
    }