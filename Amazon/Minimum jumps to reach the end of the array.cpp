/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.

*/



class Solution {
public:
    int jump(vector<int>& nums) 
    {
        //Tricky hard problem
        
        int pos = 0;
        int destination = 0;
        int jump = 0;
        
        for(int i=0;i<nums.size()-1;i++)   // we dont need to consider the last jump.
        {
            destination = max(destination , i+nums[i]);
            if(i == pos)
            {
                jump++;
                pos = destination;
            }
            
        }
        
        return jump;
        
    }
};
