class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> lastOccurrence(26);

        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        vector<bool> isPresent(26, false);

        string answer;

        for (int i = 0; i < s.size(); i++) {

            char currentChar = s[i];

            if (isPresent[currentChar - 'a']) {
                continue;
            }

            while (!answer.empty() &&
                   currentChar < answer.back() &&
                   lastOccurrence[answer.back() - 'a'] > i) {

                isPresent[answer.back() - 'a'] = false;
                answer.pop_back();
            }

            answer.push_back(currentChar);
            isPresent[currentChar - 'a'] = true;
        }

        return answer;
    }
};
