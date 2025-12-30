// LeetCode 1395 - Count Number of Teams
// Topics: Array, Brute Force, Combinatorics

class Solution {
    int smaller(vector<int>& rating, int x, int y, int val){
        int count = 0;
        for(int i = x; i <= y; i++){
            if(rating[i] < val)
                count++;
        }
        return count;
    }

    int greater(vector<int>& rating, int x, int y, int val){
        int count = 0;
        for(int i = x; i <= y; i++){
            if(rating[i] > val)
                count++;
        }
        return count;
    }

public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i = 0; i < n; i++){
            int leftSmall = smaller(rating, 0, i-1, rating[i]);
            int rightSmall = smaller(rating, i+1, n-1, rating[i]);
            int leftGreater = greater(rating, 0, i-1, rating[i]);
            int rightGreater = greater(rating, i+1, n-1, rating[i]);

            ans += ((leftSmall * rightGreater) + (rightSmall * leftGreater));
        }
        return ans;
    }
};
