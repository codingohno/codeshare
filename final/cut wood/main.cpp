#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    int Q,L;
    cin>>L>>Q;
    set<int> s;
    //insert first one
    s.insert(0);s.insert(L);
    while(Q--){
        //get query
        char cmd;int num;
        cin>>cmd>>num;

        if(cmd=='a'){//cut
            s.insert(num);
        }
        else{//else is b print
            int ending,starting;
            set<int>::iterator it=s.upper_bound(num);
            ending=*it;

            //one step forward
            it--;
            starting=*it;

            cout<<ending-starting<<endl;
        }
    }
    return 0;
}
