
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> resultSumEvenNumbers(queries.size());
        int currentSumEvenNumbers = 0;
        for (const auto& n : nums) {
            currentSumEvenNumbers += (n % 2 == 0) ? n : 0;
        }
        /*
        Alternatively for currentSumEvenNumbers:
        static constexpr auto isEven = [](int accumulated, int current) {return (current % 2 == 0) ? accumulated + current : accumulated; };
        int currentSumEvenNumbers = accumulate(nums.begin(), nums.end(), 0, isEven);
        */

        for (int i = 0; i < queries.size(); ++i) {
            int value = queries[i][0];
            int index = queries[i][1];

            currentSumEvenNumbers -= (nums[index] % 2 == 0) ? nums[index] : 0;
            nums[index] += value;
            currentSumEvenNumbers += (nums[index] % 2 == 0) ? nums[index] : 0;

            resultSumEvenNumbers[i] = currentSumEvenNumbers;
        }
        return resultSumEvenNumbers;
    }
};
