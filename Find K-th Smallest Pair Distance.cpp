// https://leetcode.com/problems/find-k-th-smallest-pair-distance

//https://www.youtube.com/watch?v=ym93rTBR4j8

class Solution {
public:
    //counting how many pairs are there in that value mid
    bool checkPairs(int mid, vector<int>& nums,int k){
        int ans = 0,j=1,n= nums.size();
        
        for(int i=0;i<n;i++){
            
            while(j<n && nums[j]-nums[i]<=mid )
                j++;
            ans += j-i-1;
        }
        return ans>=k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int start= 0,end = nums[n-1]-nums[0];
        //max diff will be the difference between last =first
        //iterating over all our differences and getting where our range will lie
        
        while(start<=end){
            int mid = start + (end - start)/2;
            if(checkPairs(mid,nums,k)){
                end = mid-1;    //more the difference (mid) more will be pairs 
            }
            else{
                start = mid+1;      //less pairs here hence mid+1
            }
            
        }
        return  start;
    }
};
