#include<iostream>
#include<vector>

 int maximumUniqueSubarray(std::vector<int> nums) {
       int some=0, i=0 , j ,test,place=0,it ;
    unsigned int  t=0 ;
        int b=0 , b2=0;
        std::vector<int> testtab ;
        std::vector<int> sub  ;
        if(nums.size()==0)
        {
            return {} ;   
        }
        else {
   while(i<nums.size()){
          test = nums[i] ;
       t=nums[i];
       //[5,2,1,2,5,2,1,2,5]
           j= i+1 ; 
           
            while( (test!=nums[j])&& (j<nums.size() ) ) {//5+2+1
         for(it=0;it<testtab.size();it++)
         {if(nums[j]==testtab[it])
         {   b2=1 ;
         break ;       }

         }
         if(b2==1){break ; }
         else {testtab.push_back(nums[j]) ;}
         b2=0 ;
            t=t+nums[j];
            if(b!=1)
            {place =j;
             b=1; }
            j++ ; }
if(b==1){
       i=place ;
       testtab={};
       }
       else i=j ;
       b=0 ;
       if(t>some)
       { 
         some=t;
         std::cout<<some<< std:: endl  ;}
            
         } 
        return some ; }
        }
        
int main(){
    std:: vector<int> num={1,7,2,1,3,2} ;
std :: cout<<maximumUniqueSubarray(num) ;

}