class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;

        for(int i=0;i<timePoints.size();i++){
            string curr=timePoints[i];

            int hour = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalMin = hour*60+min;
            minutes.push_back(totalMin);
        }

        sort(minutes.begin(),minutes.end());
        int n = minutes.size();
        int mini = INT_MAX;

        for(int i=0;i<n-1;i++){
            int totalDiff = (minutes[i+1]) - minutes[i];
            mini = min(mini,totalDiff);
        }
        int s = (1440+minutes[0]) - minutes[n-1];
        mini = min(mini,s);
        return mini;
    }
};