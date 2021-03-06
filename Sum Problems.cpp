// 1. Two Sum

// Given an array of integers, return indices of the two numbers such that they add up to a specific target. if(nums[3,3] && tar=6,then it is possible)



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
      int n=nums.size();
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
          mp[nums[i]]=i;
      int in1=-1,in2;
      for(int i=0;i<n;i++)
      {
       if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=i)
       {
        in1=mp[target-nums[i]];
        in2=i;
        break;
       }
           
      }
      vector<int>ans;
      if(in1!=-1)
      {
       ans.push_back(in1);
       ans.push_back(in2);
      }
        return ans;
          
    }
};

// 15. 3Sum

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

vector<vector<int>> threeSum(vector<int>& nums) // This gives TLE in Leetcode
    {
     vector<vector<int>>vec;
     int n=nums.size();
     if(n<=2)return vec;
     sort(nums.begin(),nums.end());
     vector<int>vv;
     set<vector<int>>ss;
     for(int i=0;i<n-2;i++)
     {
      int l=i+1;
      int r=n-1;

      while(l<r)
      {
       if(nums[i]+nums[l]+nums[r]==0)
       {
        vv.push_back(nums[i]);
        vv.push_back(nums[l]);
        vv.push_back(nums[r]);
        ss.insert(vv);
        vv.clear();
        l++;r--;
       }
       else if(nums[i]+nums[l]+nums[r]<0)
           l++;
       else
           r--;
      }
     }
     for(auto x:ss)
         vec.push_back(x);
     return vec;
    }

// -->2nd Method

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>>vv;
      for(int i=0;i<n-2;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) // [-4,-1,-1,0,1,2]
            continue;
        int tar=-nums[i];
        int l=i+1,r=n-1;
        while(l<r)
        {
         if(nums[l]+nums[r]==tar)
         {
          vv.push_back(vector<int>{nums[i],nums[l],nums[r]});
          while(l+1<n && nums[l]==nums[l+1])l++;
          while(r-1>=0 && nums[r]==nums[r-1])r--;
          l++;
          r--;
         }
         else if(nums[l]+nums[r]<tar)
             l++;
         else
             r--;
        }
      }
       return vv;
      }
};

// 18. 4Sum

// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
//Find all unique quadruplets in the array which gives the sum of target.

  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
     int n=nums.size();
     vector<vector<int>>ans;
     if(n<4)
         return ans;
     sort(nums.begin(),nums.end());
     set<vector<int>>ss;
     for(int i=0;i<n-3;i++)
     {
      int tar1=target-nums[i];
      for(int j=i+1;j<n-2;j++)
      {
       int tar2=tar1-nums[j];
       int lo=j+1,hi=n-1;
       while(lo<hi)
       {
        if(nums[lo]+nums[hi]==tar2)
        {
         vector<int>vv;
         vv.push_back(nums[i]);
         vv.push_back(nums[j]);
         vv.push_back(nums[lo]);
         vv.push_back(nums[hi]);
         ss.insert(vv);
         lo++;hi--;
        }
        else if(nums[lo]+nums[hi]<tar2)
            lo++;
        else
            hi--;
       }
      }
     }
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};

// 16. 3Sum Closest
/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     int pp=INT_MAX,ans;
     for(int i=0;i<n-2;i++)
     {
      int lo=i+1,hi=n-1;
      while(lo<hi)
      {
       int zz=nums[i]+nums[lo]+nums[hi];
       if(abs(target-zz)<abs(pp))
           pp=abs(target-zz),ans=zz;
       if(zz<target)
           lo++;
       else
           hi--;
       //cout<<ans;
      }
         
     }
     return ans;
     
    }
};



// 454. 4Sum II

// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
     int n=A.size();
     if(n==0)
         return 0;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<n;j++)
      {
       mp[A[i]+B[j]]++;
      }
     }
     int cnt=0;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(mp.find(0-C[i]-D[j])!=mp.end())
           cnt+=mp[-C[i]-D[j]];
      }
     }
     return cnt;
     
     
    }
};

// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
      int n=nums.size();
      int res=0,cur=0;
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        cur+=nums[i];
        if(cur==k)
            res++;
        if(mp.find(cur-k)!=mp.end())// if cur sum exceeds or equal(0,5,5,5 && k==10) k value ,so we check by eliminating k from cur
            res+=mp[cur-k];
        mp[cur]++;
      }
      return res;
    }
};

// 416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0)
         return 1;
     if(n==1)
         return 0;
     int sum=0;
     for(int i=0;i<n;i++)
         sum+=nums[i];
     if(sum & 1)
         return 0;
     else
     {
      int tar=sum/2;
      bool dp[n+1][tar+1];
      for(int i=0;i<=n;i++)
          dp[i][0]=1;
      for(int i=1;i<=tar;i++)
          dp[0][i]=0;
      for(int i=1;i<=n;i++)
      {
       for(int j=1;j<=tar;j++)
       {
         if(j<nums[i-1])
             dp[i][j]=dp[i-1][j];
         else
             dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
             
       }
      }
         return dp[n][tar];
     }
          
     }
     
};

// 1524. Number of Sub-arrays With Odd Sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
     int n=arr.size();
     int ans=0,cur=0;
     int cnt[]={1,0};
     int fcb=1e9+7;
     for(int i=0;i<n;i++)
     {
      cur^=(arr[i] & 1); //prefix sum till now is odd/even
      ans+=cnt[1-cur];   
      ans%=fcb;
      cnt[cur]++;
     }
     return ans;
     
    }
};

/*
cur = 0 if current prefix sum is even
cur = 1 if current prefix sum is odd
count[0] is the number of even prefix sum
count[1] is the number of odd prefix sum

For each element in A:
if current prefix sum is even, ans += the number of odd prefix sum(e+o=o)
if current prefix sum is odd, ans += the number of even prefix sum(o+e=o)
*/



// Largest subarray with 0 sum

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

/*void zero(ll a[],ll n)[o(n*n)]
{
 ll maxx=0,sum;
 for(ll i=0;i<n;i++)
 {
  sum=0;
  for(ll j=i;j<n;j++)
  {
    sum+=a[j];
    if(sum==0)
     maxx=max(maxx,j-i+1);
  }
 }
 cout<<maxx<<endl;
}*/
void zero1(ll a[],ll n)//o(n) -i.e-->arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
{
 map<ll,ll>mp;
 ll sum=0,maxx=0;
 for(ll i=0;i<n;i++)
 {
  sum+=a[i];
  if(sum==0)
    maxx=max(maxx,i+1);
  else if(mp.find(sum)!=mp.end())
    maxx=max(maxx,i-mp[sum]);
  else
    mp[sum]=i;
 }
 cout<<maxx<<endl;
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  //zero(a,n);
  zero1(a,n);
 }
 return 0;
}

// Longest substring with equal number of 0s and 1s -->consider 0 as -1

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  ll n=str.length();
  map<ll,ll>mp;
  ll maxx=0,sum=0;
  for(ll i=0;i<n;i++)
  {
   if(str[i]=='1')
     sum++;
   else
     sum--;
   if(sum==0)
    maxx=max(maxx,i+1);
   else if(mp.find(sum)!=mp.end())
    maxx=max(maxx,i-mp[sum]);
   else
    mp[sum]=i;
  }
  cout<<maxx<<endl;

 }
 return 0;

}

