//by using vector and loop

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int T;
    //cin>>T;
    scanf("%d",&T);
    while(T--){
        int string_len,query;
        //cin>>string_len>>query;
        scanf("%d %d",&string_len,&query);

        //make pairs of num,index
        typedef pair<int,int> pa;
        vector<pa> vec(string_len);

        for(int i=1;i<=string_len;i++){
            int temp_num;
            //cin>>temp_num;
            scanf("%d",&temp_num);
            vec.push_back(make_pair(temp_num,i));
        }

        sort(vec.begin(),vec.end());

        //after we made the multiset
        //find lowerbound
        while(query--){
            int L,R,X;
            //cin>>L>>R>>X;
            scanf("%d %d %d",&L,&R,&X);
            vector<pa>::iterator it=lower_bound(vec.begin(),vec.end(),make_pair(X,L));
            vector<pa>::iterator it_end=upper_bound(vec.begin(),vec.end(),make_pair(X,R));
            //if found
            int count=0;
            if((it!=vec.end())&&(it->first==X)&&(it->second<=R)){//if the first is wanted number//and within range
                //use distance
                count=distance(it,it_end);
            }
            //else not found
            else{count=0;}

            //cout<<R-L+1-count<<endl;
            printf("%d\n",R-L+1-count);

        }
        //cout<<endl;
        printf("\n");
    }
    return 0;
}


//by using vector and loop

//#include <iostream>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        int string_leng,query;
//        scanf("%d %d",&string_leng,&query);
//
//        vector<int> v;v.push_back(-1);
//        typedef map<int,int> maptype;
//        typedef vector<int> vectype;
//
//        //input
//        for(int i=1;i<=string_leng;i++){
//            int temp;
//            scanf("%d",&temp);
//            v.push_back(temp);
//        }
//
//        //start query
//        for(int i=1;i<=query;i++){//for each query
//            int L,R,X;
//            scanf("%d %d %d",&L,&R,&X);
//
//            int ans=0;
//            for(int j=L;j<=R;j++){
//                if(v[j]!=X){
//                    ans++;
//                }
//            }
//            printf("%d\n",ans);
//        }
//        printf("\n");
//    }
//
//
//
//
//
//    return 0;
//}



//slower by copy into a multi set
//#include <iostream>
//#include <map>
//#include <set>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        int string_leng,query;
//        scanf("%d %d",&string_leng,&query);
//
//
//        typedef map<int,int> maptype;
//        typedef vector<int> vectype;
//        //vector
//        vector<int> v;v.push_back(-1);
//
//        //input
//        for(int i=1;i<=string_leng;i++){
//            //insert into vec
//            int temp;
//            scanf("%d",&temp);
//            v.push_back(temp);
//        }
//
//        //start query
//        for(int i=1;i<=query;i++){//for each query
//            int L,R,X;
//            scanf("%d %d %d",&L,&R,&X);
//            vectype::iterator it_start=v.begin();advance(it_start,L);
//            vectype::iterator it_end=it_start;advance(it_end,R-L+1);
//            //copy and sort
//            multiset<int> s(it_start,it_end);
//
////            cout<<endl<<"test"<<endl;
////            for(auto test:s){
////                cout<<test<<endl;
////            }
////            cout<<"test end"<<endl;
//
//            int ans=s.count(X);
//            ans=R-L+1-ans;
//            printf("%d\n",ans);
//
//        }
//        printf("\n");
//    }
//
//
//
//
//
//    return 0;
//}

///slow
////using map and record the index
//#include <iostream>
//#include <map>
//#include <set>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        int string_leng,query;
//        scanf("%d %d",&string_leng,&query);
//
//        typedef map<int,set<int>> maptype;
//        maptype m;
//
//
//        //input
//        for(int i=1;i<=string_leng;i++){
//            int temp_num;
//            scanf("%d",&temp_num);
//            maptype::iterator it_temp=m.find(temp_num);
//            //if found
//            if(it_temp!=m.end()){
//                (it_temp->second).insert(i);
//            }
//            //not found
//            else{
//                set<int> temp_set;
//                m[temp_num]=temp_set;
//                (m[temp_num]).insert(i);
//            }
//        }
//
//        //query
//        for(int i=0;i<query;i++){
//            int L,R,X;
//            scanf("%d %d %d",&L,&R,&X);
//
//            maptype::iterator it_temp=m.find(X);
//            int ans=0;
//            if(it_temp!=m.end()){
//                //search in the set
//                set<int>::iterator it_temp2=lower_bound((it_temp->second).begin(),(it_temp->second).end(),L);
//                while(it_temp2!=((it_temp->second).end())){
//                    if((*it_temp2>=L)&&(*it_temp2<=R)){
//                        ans++;
//                        it_temp2++;
//                    }
//                    else{
//                        break;
//                    }
//                }
//            }
//
//            //after finding all we want
//            ans=R-L+1-ans;
//            printf("%d\n",ans);
//        }
//
//
//    }
//    return 0;
//}
