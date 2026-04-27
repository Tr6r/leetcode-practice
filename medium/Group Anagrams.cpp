/*
LC 49 - Group Anagrams
Time: O(N*K), Space: O(N*K)

Use frequency count (26 letters) to build a unique key for each string,
then group strings with the same key using unordered_map.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int index = 0;
        std::unordered_map<string, int> map;
        vector<int> table;
        table.resize(26);
        for (int i = 0; i < strs.size(); i++) {
            table.assign(26, 0);
            for (int ch : strs[i]) {
                int temp = (int)ch - 97;
                table[temp]++;
            }
            string key = "";
            for (int j = 0; j < table.size(); j++) {
                if (table[j] != 0) {
                    key += (char)(table[j] + 48); // index char
                    key += (char)(j + 97);        // char
                }
            }
            auto it = map.find(key);
            if (it != map.end()) {
                int v = it->second; // get map_value
                result[v].push_back(strs[i]);
                continue;
            }
            if (index >= result.size())
                result.resize(index + 1);
            map[key] = index;
            result[index].push_back(strs[i]);
            index++;
        }
        return result;
    }
};