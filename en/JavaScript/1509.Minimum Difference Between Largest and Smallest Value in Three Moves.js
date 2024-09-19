// @algorithm @lc id=1616 lang=javascript
// @title minimum-difference-between-largest-and-smallest-value-in-three-moves
// @test([5,3,2,4])=0
// @test([1,5,0,10,14])=1
// @test([3,100,20])=0
/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function (nums) {
  nums.sort((a, b) => a - b);
  if (nums.length <= 3) return 0;
  return Math.min(
    nums[nums.length - 1] - nums[3],
    nums[nums.length - 4] - nums[0],
    nums[nums.length - 3] - nums[1],
    nums[nums.length - 2] - nums[2],
  );
};
