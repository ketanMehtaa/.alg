// @algorithm @lc id=1293 lang=javascript
// @title three-consecutive-odds
// @test([2,6,4,1])=false
// @test([1,2,34,3,4,5,7,23,12])=true
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function (arr) {
  if (arr.length < 3) return false;
  let seq = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] % 2) {
      seq += 1;
    } else {
      seq = 0;
    }
    if (seq == 3) {
      return true;
    }
  }
  return false;
};
