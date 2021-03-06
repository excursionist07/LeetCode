// 287. Find the Duplicate Number


class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
     int n=nums.size();
     int ans;
     /*int slow=nums[0],fast=nums[0];
     do{
        slow=nums[slow];
        fast=nums[nums[fast]];
     }while(slow!=fast);
     slow=nums[0];
     while(slow!=fast)
     {
      slow=nums[slow];
      fast=nums[fast];
     }
     return slow;*/
     for(int i=0;i<n;i++)
     {
      if(nums[abs(nums[i])-1]>0)
          nums[abs(nums[i])-1]*=-1;
      else
          ans=abs(nums[i]);
          
     }
     return ans;
        
    }
    
    
};

// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0) return 0;
     int idx=0;
     for(int j=1;j<n;j++)
     {
      if(nums[j]!=nums[idx])
      {
       idx++;
       nums[idx]=nums[j];
      }
     }
     return idx+1;
    }
};

// 80. Remove Duplicates from Sorted Array II

// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
      int n=nums.size();
      if(n==0)
          return 0;
      int idx=1;
      bool ff=0;
     for(int i=1;i<n;i++)
     {
      if(nums[i]!=nums[i-1])
      {
       nums[idx]=nums[i];
       idx++;
       ff=0;
      }
      else if(nums[i]==nums[i-1] && !ff)
      {
       nums[idx]=nums[i];
       idx++;
       ff=1;
      }
     }
     return idx;
        
    }
};

// 448. Find All Numbers Disappeared in an Array

vector<int> findDisappearedNumbers(vector<int>& nums)
    {
     vector<int>ans;
     int n=nums.size();
     for(int i=0;i<n;i++)
     {
      if(nums[abs(nums[i])-1]>0) 
        nums[abs(nums[i])-1]*=-1;

     }
        for(int i=0;i<n;i++)
        {
         if(nums[i]>0)// index number  which is +ve means that index number was not present in array to make it negative
             ans.push_back(i+1);
        }
        return ans;

    }

// 268. Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
     int n=nums.size();
        int xx=0;
     for(int i=0;i<=n;i++)
         xx^=i;
     for(int i=0;i<n;i++)
         xx^=nums[i];
     return xx;
    }
};

// 41. First Missing Positive

class Solution {
public:
    
    int findit(vector<int>& nums,int n)
    {
     int j=0;
     for(int i=0;i<n;i++)
     {
      if(nums[i]<=0)
      {
       swap(nums[i],nums[j]);// all 0 && -ve numbers on left side of array
       j++;
      }
     }
     n=n-j;
     rotate(nums.begin(),nums.begin()+j,nums.end()); // if some a[] is {1,2,3,4} and j=1 then after rotation a[] becomes={2,3,4,1} i.e:-rotate left by j times
     for(int i=0;i<n;i++)
     {
      if(abs(nums[i])-1<n && nums[abs(nums[i])-1]>0)
          nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
     }
     for(int i=0;i<n;i++)
     {
      if(nums[i]>0)
          return i+1;
     }
        return n+1;
    }
    
    int firstMissingPositive(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0)return 1;
     //int n=nums.size();
     return findit(nums,n);
    }
};
 // Repeat and Missing Number Array--> Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. 

#define bits<std/c++.h>
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
typedef  long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

/*
s1=(n*(n+1)/2)-xx+yy;
s2=(n*(n+1)(2*n+1))/6-xx^2+yy^2
where, xx=missing ,yy=repeating
*/
int main() 
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll s1=0,s2=0;
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
   cin>>a[i];
   s1+=a[i];
   s2+=(a[i]*a[i]);
  }
  ll aa=n*(n+1);
  aa=aa*((2*n)+1);
  aa=aa/6;
  aa=aa-s2;
  ll bb=(n)*(n+1);
  bb=bb/2;
  bb=bb-s1;
  ll xx=(aa/bb)+bb;
  xx=xx/2;
  ll yy=xx-bb;
  cout<<yy<<" "<<xx<<endl;
 }
 return 0;
}

// 2nd method
for (i = 0; i < size; i++) { 
        if (arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
        else
            cout << abs(arr[i]) << "\n"; 
    } 
  
    cout << "and the missing element is "; 
    for (i = 0; i < size; i++) { 
        if (arr[i] > 0) 
            cout << (i + 1); 
        
        
  // 442. Find All Duplicates in an Array
        
   class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>ans;
      for(int i=0;i<n;i++)
      {
        if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1]*=-1;
        else
            ans.push_back(abs(nums[i]));
      }
      return ans;
        
    }
};

