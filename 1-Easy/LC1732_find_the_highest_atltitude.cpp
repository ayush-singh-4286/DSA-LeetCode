// LeetCode Question: 1732. Find the Highest Altitude  
// Topics: Array, Prefix Sum

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;

        for(int i = 0; i < gain.size(); i++){
            altitude += gain[i];
            if(altitude > maxAltitude)
                maxAltitude = altitude;
        }
        return maxAltitude;
    }
};
