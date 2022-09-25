
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function (nums, queries) {
    let resultSumEvenNumbers = new Array(queries.length);
    let currentSumEvenNumbers = nums.filter(n => n % 2 === 0).reduce((n_01, n_02) => (n_01 + n_02), 0);

    for (let i = 0; i < queries.length; ++i) {
        let value = queries[i][0];
        let index = queries[i][1];

        currentSumEvenNumbers -= (nums[index] % 2 === 0) ? nums[index] : 0;
        nums[index] += value;
        currentSumEvenNumbers += (nums[index] % 2 === 0) ? nums[index] : 0;

        resultSumEvenNumbers[i] = currentSumEvenNumbers;
    }

    return resultSumEvenNumbers;
};
