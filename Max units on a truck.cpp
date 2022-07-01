//Leetcode July Streak Day 1/31

/* 
Problem :- 1710.Maximum Units on a Truck [E]

You are assigned to put some amount of boxes onto one truck.
 You are given a 2D array boxTypes, where 
 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes 
that can be put on the truck. You can choose any boxes to put on the truck
 as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Example 1:
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Example 2:
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
*/

//Code:-


bool compare(vector<int>v1 , vector<int>v2)
{
  //compare on the basis of index 1 of the units
  return v1[1]>v2[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
      int totalUnits=0;
      int i=0;
      //sort the array wrt to the units size
      
      sort(boxTypes.begin(), boxTypes.end(), compare);
      
      while(truckSize>0 && i<boxTypes.size())
      {
        if(boxTypes[i][0]<=truckSize)
        {
          totalUnits += boxTypes[i][0] * boxTypes[i][1];
          truckSize -= boxTypes[i][0];
        }
        else
        {
          int canTake = truckSize;
          truckSize -= canTake;
          totalUnits += canTake * boxTypes[i][1];
        }
        i++;
      }
      return totalUnits;
    }
};

//Time Complexity = O(nlogn).
//Space Complexity= O(1).