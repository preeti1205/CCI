/*
CTCI
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 or 3 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

class Solution {
public:
    int climbStairs_recursive(int n) {  // will run outa memory after n = 40

      if (n <= -1) return 0;
      if (n < 3) return n;

      return climbStairs(n - 1) + climbStairs(n - 2) + climbstairs(n - 3);

    }

    int climbStairs_bottom_up(int n) {  // will run outa memory after n = 40
      double arr[n + 1];
      arr[0] = 0;
      arr[1] = 1;
      arr[2] = 2;

      for(int i = 3; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i - 2] + arr[i - 3];
      }
      return arr[n];
    }
};
