// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
      int n=s.length();
      int start=0,ans=0;
      unordered_map<char,int>mp;
      for(int i=0;i<n;i++)
      {
       mp[s[i]]++;
       if(mp[s[i]]>1)
       {
         ans=max(ans,i-start);
         while(s[start]!=s[i])
             mp[s[start]]--,start++;
         mp[s[start]]--;
         start++;
         
       }
      
      }
      return max(ans,n-start);
    }
};

// 1695. Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
     int n=nums.size();
     int pre[n+1];
     pre[0]=0;
     for(int i=1;i<=n;i++)
         pre[i]=pre[i-1]+nums[i-1];
     unordered_map<int,int>mp;
     int start=1,ans=0;
     for(int i=0;i<n;i++)
     {
      mp[nums[i]]++;
      if(mp[nums[i]]>1)
      {
       ans=max(ans,pre[i]-pre[start-1]);
       while(nums[start-1]!=nums[i])
           mp[nums[start-1]]--,start++;
       mp[nums[start-1]]--;
       start++;
      }
     }
     return max(ans,pre[n]-pre[start-1]);
     
    }
};

// 395. Longest Substring with At Least K Repeating Characters

// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

class Solution {
public:
    int longestSubstring(string s, int k) //O(n*log(n))
    {
     int n=s.length();
     if(n==0 || k>n)
         return 0;
     if(k==0)
         return n;
     int cnt[26]={0};
     for(int i=0;i<n;i++)
         cnt[s[i]-'a']++;
     int idx=0;
     while(idx<n && cnt[s[idx]-'a']>=k)
         idx++;
     if(idx==n)
         return n;
     int left=longestSubstring(s.substr(0,idx),k);
     int right=longestSubstring(s.substr(idx+1),k);

    return max(left,right);

    }
};
