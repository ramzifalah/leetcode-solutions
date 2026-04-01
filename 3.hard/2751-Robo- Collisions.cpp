// Robot Collisions
// Hard
// https://leetcode.com/problems/robot-collisions/description/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });

        vector<int> st;

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push_back(id);
            } else {
                while (!st.empty() && healths[id] > 0) {
                    int j = st.back();

                    if (healths[j] < healths[id]) {
                        st.pop_back();
                        healths[id]--;
                        healths[j] = 0;
                    } else if (healths[j] > healths[id]) {
                        healths[j]--;
                        healths[id] = 0;
                        break;
                    } else {
                        healths[j] = 0;
                        healths[id] = 0;
                        st.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }

        return ans;
    }
};
