class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        map<char, int> ts;
        for (auto &c : t) {
            ts[c]++;
        }
        int needed = ts.size();
        int first_take=0, next_take=0;
        pair<int,int> sol({INT_MAX,0});

        while (true) {
            if (needed > 0) { // if we still need some chars
                if (next_take == m) break;
                if (--ts[s[next_take++]] == 0) needed--; // keep going right until we found all needed chars in right amount
            } else {
                if (ts[s[first_take++]]++ == 0) needed++; // if it was 0 before adding the char, we now lost one needed requirement
            }
            if (needed == 0 && sol.first>next_take-first_take) { // if we have all needed reqs and its smaller
                sol={next_take-first_take,first_take}; // we assign it as new solution
            }
        }
        if (sol.first==INT_MAX) return ""; // if we never found any solution
        return s.substr(sol.second,sol.first);
    }
};