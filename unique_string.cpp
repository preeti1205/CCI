#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
  string str;
  cout<<"Enter the string :";
  
  cin>>str;

  int z=0;
  bool b1[128]; 

  for(int i=0;i< (str.size());i++)
  {
    int  ch=(int) str[i];
    if( b1[ch] )
      {
        z=100;
        break;
      }
    b1[ch]=true;
  }
  
  if (z==100)
    cout<<"NO";
  else if( z==0 )
    cout<<"YES";
  cout>>endl;

  return 0;
}
