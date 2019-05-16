#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    long long int M[200], n, lyginam=0, ats=0, s=0, nr=0;
    cin>>n;
        for (int i=0; i<n; i++) {
        cin>>M[i];
    }
     for (int i=0; i<n; i++) {
            lyginam=M[i];
            if(lyginam>M[i+1]&& lyginam>M[i-1] && nr!=1 && lyginam>0 || M[i]>M[i+1] && nr!=1 && i==0 && lyginam>0|| M[n-1]>M[n-2]&& nr!=1 && i==n-1 && lyginam>0){
                ats=lyginam;
                nr++;
                s++;
            }
        }
        for (int i=0; i<n; i++) {
                lyginam=M[i];
            if(lyginam>M[i+1]&& lyginam>M[i-1] && ats>lyginam && lyginam>0 || M[i]>M[i+1] && ats>lyginam && lyginam>0 && i==0  || M[n-1]>M[n-2] && ats>lyginam && lyginam>0 && i==n-1){
            ats=lyginam;
            s++;
        }
     }
    
     if(s==0)
        cout<<"NO";
      else 
     cout<<ats;
    return 0;
}
