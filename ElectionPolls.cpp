//consider candidates are not participating in voting.
#include<iostream>
#include<string>
using namespace std;
int main()
{
int v,c;
cout<<"Enter the number of all voters: ";
cin>>v;
cout<<"Enter the number of Candidate: ";
cin>>c;
int *cv=new int[c];//declaring an array for counting votes
for(int j;j<c;j++)
    cv[j]=0;
string cand[c];
cout<<"Enter the name of "<<c<<" Candidate:"<<endl;
for(int i=0;i<c;i++)
    cin>>cand[i];
cout<<"\n\nVote anybody from below list"<<endl;
cout<<"__________________________________________________"<<endl;
for(int i=0;i<c;i++)
    cout<<cand[i]<<endl;

//to vote enter the names any from candidate   
cout<<"Enter the name of candidates "<<v<<" times randomly to vote them: "<<endl;
string vote[v];
try
{
    for(int i=0;i<v;i++)
    {
        cin>>vote[i];
        int s=0;
        for(int j=0;j<c;j++)
        {
            if(vote[i]==cand[j])
            {
               cv[j]++;//inc in votes of candidate
               s++;
            }
            if(s==0)throw -1;
        }
    }
int max=0;string temp;
for(int i=0;i<c;i++)
    {
    if(cv[i]>max)
        {max=cv[i];temp.erase();temp=cand[i];}
    }
    
//arrange candidate in alphabetically who got the same votes
    
for(int i=0;i<c;i++)
{
    if(max==cv[i]&& temp!=cand[i])
    {
      int n=0;
      while(temp[n]==cand[i][n])n++;
      if(temp[n]<cand[i][n])
        {temp.erase();temp=cand[i];}
    }
}
cout<<"Winner of Election is: "<<temp;
}
catch(...)
    {
    cout<<"Invalid candidate name Please check ";
    }
return 0;
}
