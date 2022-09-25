
import java.util.Arrays;

public class Solution {

    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int[] resultSumEvenNumbers = new int[queries.length];
        int currentSumEvenNumbers = Arrays.stream(nums).filter(n -> n % 2 == 0).sum();

        for (int i = 0; i < queries.length; ++i) {
            int value = queries[i][0];
            int index = queries[i][1];

            currentSumEvenNumbers -= (nums[index] % 2 == 0) ? nums[index] : 0;
            nums[index] += value;
            currentSumEvenNumbers += (nums[index] % 2 == 0) ? nums[index] : 0;

            resultSumEvenNumbers[i] = currentSumEvenNumbers;
        }

        return resultSumEvenNumbers;
    }
}
