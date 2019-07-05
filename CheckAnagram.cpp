/*
     Easiest way to check if two strings are anagram of each other or not.
     A anagram of a string is another string that contains same characters (same length), only the order of chracters can be 
     different.

     For example: SILENT and LISTEN
	                FORTY FIVE and OVER FIFTY
               
     Time Complexity  : O(n)
     Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//Function to check whether strings are anagram or not
int anagram(string str1, string str2)
{
     
     //if two strings are of different length then that string can not be string
         if(str1.length()!=str2.length())
	            {
	              	return 1;
            	}
    
     //val is storing the XOR value   
        int val = 0;
        for(int i=0; i<str1.length(); i++)
              {
                   val^=(int)str1[i];
                   val^=(int)str2[i];
              }
              
        return val;
}

//Driver Code
int main()
{
     string str1, str2;
     getline(cin, str1);
     getline(cin, str2);

     int res = anagram(str1, str2);
     if(res==0)
     {
          cout<<"Yes, It is anagram."<<endl;
     }
     else
     {
          cout<<"No, it is not an anagram."<<endl;
     }
}
