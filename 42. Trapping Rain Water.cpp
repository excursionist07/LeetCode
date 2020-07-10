class Solution {
public:
    int trap(vector<int>& height)
    {
      int n=height.size();
      if(n==0)
          return 0;
      int pre[n],suff[n];
      pre[0]=height[0];
      suff[n-1]=height[n-1];
      for(int i=1;i<n;i++)
          pre[i]=max(pre[i-1],height[i]);
      for(int i=n-2;i>=0;i--)
          suff[i]=max(suff[i+1],height[i]);
      int sum=0;
      for(int i=0;i<n;i++)
      {
       int zz=min(pre[i],suff[i]);
       if(zz>=height[i])
           sum+=(zz-height[i]);
      }
      return sum;
    }
};