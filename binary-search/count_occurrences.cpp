class Solution {
public:

    int first(vector<int>& nums,int target){

        int ans=-1,l=0,r=nums.size()-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(nums[mid]==target){

                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }

        return ans;
    }

    int last(vector<int>& nums,int target){

        int ans=-1,l=0,r=nums.size()-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(nums[mid]==target){

                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }

        return ans;
    }

    int count(vector<int>& nums,int target){

        int f=first(nums,target);

        if(f==-1)
            return 0;

        int l=last(nums,target);

        return l-f+1;
    }
};
