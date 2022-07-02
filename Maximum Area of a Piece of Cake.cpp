//Leetcode July Streak Day 2/31

/* 
Problem :- 1465.Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts[M]

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. 
Since the answer can be a large number, return this modulo 109 + 7.


Example 1:
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4

Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. 
After you cut the cake, the green piece of cake has the maximum area.

Example 2:
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6

Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts.
After you cut the cake, the green and yellow pieces of cake have the maximum area.

Example 3:
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
*/

//Code:-



class Solution {
public:
            
        
int maxDiff(vector<int> v, int length){
        sort(v.begin(),v.end());
        int max_diff=v[0];
        for(int i=1;i<v.size();i++){
            max_diff=max(max_diff,v[i]-v[i-1]);
        }
        
        max_diff=max(max_diff,length-v.back());
        return max_diff;
        
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long height=maxDiff(horizontalCuts, h);
        long width=maxDiff(verticalCuts, w);
        return (height*width)%1000000007;
    }
};