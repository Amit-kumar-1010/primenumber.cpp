#include <iostream>
using namespace std;
int main()
{
  int n,m=0,i,flag=0;
  cout<<"entre the number to check prime ";
  cin>>n;
  m=n/2;
  for(int i=2;i<=m;i++)
    {
      if(n%i==0)
      {
        cout<<"number is not prime"<<endl;
        flag=1;
        break;
      }
    }
  if(flag==0)
  
    cout<<"number is prime"<<endl;
    return 0;
  }
// }

// int main() {
//   std::cout << "Hello World!\n";
// }