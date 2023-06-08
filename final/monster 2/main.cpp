#include <iostream>
#include <map>


using namespace std;

int main()
{
    map<long long,int> m;//type of num //count
    typedef map<long long,int> maptype;
    int n;
    cin>>n;

    //WE CAN TRY TO RECORD THE GREATEST NUMBER AND THE COUNT
    long long type=-1;
    int count=-1;


    while(n--){
        long long int temp;
        cin>>temp;

        maptype::iterator it=m.find(temp);

        if(it!=m.end()){
            m[temp]+=1;
        }
        else{
            m[temp]=1;
        }

        //update the ace card
        if(count!=-1){
            //after adding compare with cur ace
            if(m[temp]>(count)){
                //change without hestitation
                type=temp;
                count=(m[temp]);
            }
            else if(m[temp]==(count)){
                if(temp>type){
                    type=temp;
                }
            }
        }
        else if(count==-1){
            type=(m.begin())->first;
            count=1;
        }
        cout<<type<<endl;



    }

}
