  int minimumSum(vector<int>& nums) {
       int n=nums.size();
       vector<int>minleft(n);
       minleft[0]=0;
       for(int i=1;i<n;i++)
       {
         if(nums[minleft[i-1]]>nums[i])
         minleft[i]=i;
         else
         minleft[i]=minleft[i-1];
       }
       vector<int>minright(n);
       minright[n-1]=n-1;
       for(int i=n-2;i>=0;i--)
       {
        if(nums[minright[i+1]]>nums[i])
           minright[i]=i;
           else
           minright[i]=minright[i+1];
       }
       for(int i=0;i<n;i++)
        cout<<minleft[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<minright[i]<<" ";
        cout<<endl;
 
 
      int sum=INT_MAX;
       for(int i=1;i<n-1;i++)
       {
           if(i!=minleft[i]&&i!=minright[i]&&nums[i]>nums[minleft[i]]&&nums[i]>nums[minright[i]])
            sum=min(sum,nums[i]+nums[minleft[i]]+nums[minright[i]]);
          else if(i!=minleft[i-1]&&i!=minright[i+1]&&nums[i]>nums[minleft[i-1]]&&nums[i]>nums[minright[i+1]])
            sum=min(sum,nums[i]+nums[minleft[i-1]]+nums[minright[i+1]]);
       }
       return sum==INT_MAX?-1:sum;
    }
};