//#804. Unique Morse Code Words (C++) - 4ms/71.25% 8.4MB/98.15%
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique;
        string out;
        for (string const &str : words) {
            out.clear();
            for (char const &c : str) {
                out.append(morse[c - 'a']);
            }
            unique.insert(out);
        }
        return unique.size();
    }
};