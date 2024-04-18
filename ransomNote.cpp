    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<int, int> map;

        int str_len = magazine.length();

        for(int i = 0; i < str_len; ++i)
        {
            ++map[magazine[i]];
        }

        str_len = ransomNote.length();

        for(int i = 0; i < str_len; ++i)
        {
            if(--map[ransomNote[i]] < 0)
                return false;
        }

        return true;
    }