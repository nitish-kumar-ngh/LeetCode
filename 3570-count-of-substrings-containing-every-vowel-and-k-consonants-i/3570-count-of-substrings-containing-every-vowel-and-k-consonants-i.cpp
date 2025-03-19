class Solution {
public:
    bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countOfSubstrings(string word, int l) {
    int ans = 0, n = word.size();

    for (int i = 0; i < n; i++) {
        unordered_set<char> vowels;
        int nonVowelCount = 0;

        for (int j = i; j < n; j++) {
            char c = word[j];

            if (isVowel(c)) 
                vowels.insert(c); 
            else 
                nonVowelCount++;

            int len = j - i + 1;
            if (len >= l + 5 && vowels.size() == 5 && nonVowelCount == l) {
                ans++;
            }
        }
    }

    return ans;
}
    
};