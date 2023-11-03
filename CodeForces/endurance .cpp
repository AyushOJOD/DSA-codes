#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int ath;

    cin>>ath;

    long long str,end;

    long long firstEndu,firstStrength;
    int flag=0;

    for(int cntr=0;cntr < ath;cntr++)
    {
        // profile[cntr][0]=cntr;

        cin>>end;
        cin>>str;

        if (cntr == 0)
        {
            firstEndu=end;
            firstStrength=str;
        }
        else{
            if(end >= firstEndu && str>=firstStrength)
            {
                flag=1;
            }
        }
    }

    if(flag == 0)
    {
        cout<< firstStrength<<endl;
    }

    cout << -1<<endl;

    return ;
}



int main(){

    int tst;

    cin>>tst;

    while(tst--)
    {
        solve();
    }
    return 0;
}