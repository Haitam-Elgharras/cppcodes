class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind ;
        int j=0 ;
        bool test=0 ;
   for(int i=0;i<nums.size()-1;i++)  {
        for( j=0;j<=nums.size()-1;j++){
            if(i!=j){
            if(nums[i]+nums[j]==target)
            {test =1;
           ind.push_back(i);
           ind.push_back(j);
            return ind ;}
        } 
       }
       
   } 
    ind[0]=-1 ;
            ind[1]=-1 ;  
  return ind ;}
};