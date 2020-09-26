/*
Given a string S, we can split S into 2 strings: S1 and S2. Return the number of ways S can be split such that the number of unique characters between S1 and S2 are the same.
Example 1:
Input: "aaaa"
Output: 3
Explanation: we can get a - aaa, aa - aa, aaa- a

Example 2:
Input: "bac
Output: 0
*/


#include<iostream>
#include<string.h>
using namespace std;

int split_count(char c[])
 {
  char str1[30],str2[30];
  int count=0,len,m,flag=0,s,i1,i2,l1,l2,d,uniq1[26],uniq2[26]; 
    len=strlen(c);
    for(int i=0;i<len-1;i++)
     {
          
         for(int j=0;j<=i;j++)
             {
                  str1[j]=c[j];
             }
          s=(len)-(i+1);
          m=i+1;
     
         for(int k=0;k<s;k++)
             { 
                  str2[k]=c[m];
                  m++;
              }                 //two splited strings are str1,str2
         l1=i+1;
         l2=s;
      
        
         for(d=0;d<=26;d++)        //making string as 0
             {
                  uniq1[d]=0;
                  uniq2[d]=0;
             }

         for(i1=0;i1<l1;i1++)           //setting 1 to character value if it present in first split
             {
                   int s= str1[i1]-97;
                   uniq1[s]=1;
             }
       
         for(i2=0;i2<l2;i2++)          // //setting 1 to character value if it present in second split
             {
                    int s= str2[i2]-97;
                     uniq2[s]=1;
             }
    
         for(int g=0;g<=26;g++)
             { 
                 if(uniq1[g]==uniq2[g])
                     {
                          continue;
                     } 
                 else 
                         flag=1;
              }
         
          if(flag==1)
              {
                  flag=0;
              }
          else
                count++;
     }
 
   return(count);


 }


int main()
{
 char str[30];
 int count;
 

      cout<<"Entre a string to split\n";
      cin>>str;

     
  count=split_count(str);
cout<<count<<" number of ways we can split the string"<<str;
}
