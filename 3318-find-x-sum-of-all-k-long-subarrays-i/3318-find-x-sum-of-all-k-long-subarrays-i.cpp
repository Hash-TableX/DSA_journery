class Solution {
 public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    vector<int> ans;
    long windowSum = 0;
    unordered_map<int, int> count;
    multiset<pair<int, int>> top;  
    multiset<pair<int, int>> bot;  

    
    auto update = [&count, &top, &bot, &windowSum](int num, int freq) -> void {
      if (count[num] > 0) {  
        if (auto it = bot.find({count[num], num}); it != bot.end()) {
          bot.erase(it);
        } else {
          it = top.find({count[num], num});
          top.erase(it);
          windowSum -= num * count[num];
        }
      }
      count[num] += freq;
      if (count[num] > 0)
        bot.insert({count[num], num});
    };

    for (int i = 0; i < nums.size(); ++i) {
      update(nums[i], 1);
      if (i >= k)
        update(nums[i - k], -1);

      while (!bot.empty() && top.size() < x) {
        const auto [countB, b] = *bot.rbegin();
        bot.erase(--bot.end());
        top.insert({countB, b});
        windowSum += b * countB;
      }

      while (!bot.empty() && *bot.rbegin() > *top.begin()) {
        const auto [countB, b] = *bot.rbegin();
        const auto [countT, t] = *top.begin();
        bot.erase(--bot.end());
        top.erase(top.begin());
        bot.insert({countT, t});
        top.insert({countB, b});
        windowSum += b * countB;
        windowSum -= t * countT;
      }
      if (i >= k - 1)
        ans.push_back(windowSum);
    }

    return ans;
  }
};
