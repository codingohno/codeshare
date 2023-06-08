#include <iostream>
#include <sstream>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

///algorithm
///Monotonic Queues.


using namespace std;
int main(void){
    int T;cin>>T;
    while(T--){
        int num;
        cin>>num;

        vector<int> strength;strength.push_back(-1);
        vector<int> height;height.push_back(-1);

        //input to vec strength
        for(int i=0;i<num;i++){
            int temp;cin>>temp;
            strength.push_back(temp);
        }
        //input to vec height
        for(int i=0;i<num;i++){
            int temp;cin>>temp;
            height.push_back(temp);
        }

        //use a stack//make a monotonic sequence stack//whenever something is popped then the answer of it
        //the good thing is if i can find answer just wait and pile up until some answer appear
        //and all the answer from the botom to the top is the answer
        stack<int> index_stack_unsolved;
        vector<int> answer(strength.size());answer[0]=-1;


        //for all the animals iterate and record unsolved with a stack
        vector<int> ::iterator it_s,it_h;
        it_s=strength.end();it_s--;
        it_h=height.end();it_h--;

        for(int i=num;i>=0;i--){
            if(index_stack_unsolved.empty()){
                //add directly
                index_stack_unsolved.push(i);
            }
            else{
                int top_index=index_stack_unsolved.top();
                bool empty_bool=index_stack_unsolved.empty();
                //we need a weaker animal on the top
                //while the cur_animal is strong than the animal on the top pop it and the answer of the popped animal is found
                //if an animal is popped it means we have solve it
                while(!empty_bool&&((strength[top_index]<strength[i])||((strength[top_index]==strength[i])&&(height[top_index]<height[i])))){
                    //found answer for this
                    answer[top_index]=i;

                    //pop and maintain the monotonic sequence which we havent find the answer
                    index_stack_unsolved.pop();

                    //update top index
                    if(!index_stack_unsolved.empty()){
                        top_index=index_stack_unsolved.top();
                    }else{empty_bool=true;}
                }

                //popped solved all the solvable animals answer
                //push in current
                index_stack_unsolved.push(i);
            }
        }

        //after pushing all the indexes
        //we have all the indexes which dont have some better animal in front of it
        //so the answers is zero for those we still stay in the stack

        while(!index_stack_unsolved.empty()){
            answer[index_stack_unsolved.top()]=0;
            index_stack_unsolved.pop();
        }

        //print answer
        cout<<answer[1];
        for(int i=1+1;i<answer.size();i++){
            cout<<" "<<answer[i];
        }
        cout<<endl;
    }

    return 0;
}



//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <set>
//using namespace std;
//int main(void){
//    int T;cin>>T;
//    while(T--){
//        //num of animals
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        ///collect the input
//        //sstream
//        string temp;
//        getline(cin,temp);
//        stringstream s(temp);
//        getline(cin,temp);
//        stringstream h(temp);
//
//
//        ///structures to keep data
//        //map
//        map<int,set<int>> m;//key is strength->index->height
//        typedef map<int,set<int>> map_t;
//        //vector
//        vector<int> height_v;height_v.push_back(-1);//ignore the zeroth
//        //answer vector
//        vector<int>answer;answer.push_back(-1);
//
//
//        ///input the data into structures and also generate answer
//        int temp_s,temp_h;
//        int index=0;
//        while((s>>temp_s)&&(h>>temp_h)){
//            index++;
//            map_t::iterator it=m.find(temp_s);
//
//            if(it!=m.end()){
//                m[temp_s].insert(index);
//            }else{
//                set<int> new_s;
//                m[temp_s]=new_s;
//                m[temp_s].insert(index);
//            }
//
//            //vector of height
//            height_v.push_back(temp_h);
//
//            //search for the it again if last is a end() iteratro
//            if(it==m.end()){it=m.find(temp_s);}
//
//            //search all the the greater than us numbers
//            int sub_ans=-1;
//            while(it!=m.end()){
//
//                //test the last one form the set
//                //it->second is the set
//                //it->first is the strength
//
//                //if the strength is the same
//                if(it->first==temp_s){
//                    //check the height of each from the back if the height is greater than temp_h then we can store the ans already
//                    for(auto check_height_ind:it->second){//for every index in the same strength set
//                        if(height_v[check_height_ind]>temp_h){
//                            if(check_height_ind>sub_ans){//never will be itself
//                                sub_ans=check_height_ind;
//                            }
//                            break;
//                        }
//                    }
//                }
//                //else if strength is greater
//                else if(it->first>temp_s){
//                    //check the last in the set because it is the greatest index one
//                    int greatest_ind=*(--(it->second.end()));
//
//                    if(greatest_ind>sub_ans)sub_ans=greatest_ind;
//                }
//                else{//error
//                    exit(1);cout<<"error"<<endl;
//                    exit(234);
//                }
//                it++;
//            }
//
//            //after all the checking store the answer
//            if(sub_ans>0){
//                answer.push_back(sub_ans);
//            }else{
//                answer.push_back(0);
//            }
//        }
//
//        //answer
//        cout<<answer[1];
//        for(int i=1+1;i<answer.size();i++){
//            cout<<" "<<answer[i];
//        }
//        cout<<endl;
//    }
//}


//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//int main(void){
//    int T;cin>>T;
//    while(T--){
//        //num of animals
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        //collect the input
//        multimap<int,int> strength;
//        multimap<int,int> height;
//
//        for(int i=1;i<=num;i++){
//            int temp;
//            cin>>temp;
//            strength.insert(pair<int,int>(temp,i));
//        }
//        getchar();
//        for(int i=1;i<=num;i++){
//            int temp;
//            cin>>temp;
//            height.insert(pair<int,int>(temp,i));
//        }
//
//        //record ans
//        vector<int> answer(height.size());
//        for
//
//
//
//        //index for strength
//
//        int start=1;
//        for(int i=1;i<=strength.size()-1;i++){
//            //stored bool
//            bool stored=false;
//            for(int j=i-1;j>=start;j--){
//                if(strength[j]>strength[i]){
//                    answer[i]=j;
//                    //cout<<"storing"<<j<<endl;
//                    stored=true;
//                    break;
//                }
//            }
//            if(!stored){
//                //cout<<"storing cuz no foudn"<<0<<endl;
//                answer[i]=0;
//            }
//
//            if(strength[i]>strength[start]){start=i;}
//
//        }
//
//
//        //index for height//try to modify the ans
//        for(int i=1;i<=height.size()-1;i++){
//            int strength_ans_point=answer[i];
//            for(int j=i-1;j>strength_ans_point;j--){//end point is strenth ans point
//                if((height[j]>height[i])&&(strength[i]==strength[j])){
//                    answer[i]=j;
//                    break;
//                }
//            }
//        }
//        //answer
//        cout<<answer[1];
//        for(int i=1+1;i<answer.size();i++){
//            cout<<" "<<answer[i];
//        }
//        cout<<endl;
//    }
//}


//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main(void){
//    int T;cin>>T;
//    while(T--){
//        //num of animals
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        //collect the input
//        vector<int> strength;strength.push_back(-1);
//        vector<int> height;height.push_back(-1);
//
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            strength.push_back(temp);
//        }
//        getchar();
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            height.push_back(temp);
//        }
//
//        //index for strength
//        vector<int> answer(height.size());
//        int start=1;
//        for(int i=1;i<=strength.size()-1;i++){
//            //stored bool
//            bool stored=false;
//            for(int j=i-1;j>=start;j--){
//                if(strength[j]>strength[i]){
//                    answer[i]=j;
//                    //cout<<"storing"<<j<<endl;
//                    stored=true;
//                    break;
//                }
//            }
//            if(!stored){
//                //cout<<"storing cuz no foudn"<<0<<endl;
//                answer[i]=0;
//            }
//
//            if(strength[i]>strength[start]){start=i;}
//
//        }
//
//
//        //index for height//try to modify the ans
//        for(int i=1;i<=height.size()-1;i++){
//            int strength_ans_point=answer[i];
//            for(int j=i-1;j>strength_ans_point;j--){//end point is strenth ans point
//                if((height[j]>height[i])&&(strength[i]==strength[j])){
//                    answer[i]=j;
//                    break;
//                }
//            }
//        }
//        //answer
//        cout<<answer[1];
//        for(int i=1+1;i<answer.size();i++){
//            cout<<" "<<answer[i];
//        }
//        cout<<endl;
//    }
//}

//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
/////lower bound upper bound
//int main()
//{
//    int T;cin>>T;
//    while(T--){
//        ///numbers of animals in each testcase
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        //collect the input
//        vector<int> strength;
//        vector<int> height;
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            strength.push_back(temp);
//        }
//        getchar();
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            height.push_back(temp);
//        }
//
////        lower bound
////        auto it=strength.rend();
////        cout<<*it<<endl;
//
//        //lower bound
//        auto it=upper_bound(strength.rbegin(),--(--strength.rend()),13);
//        cout<<*it<<endl;
//
//
////        //reverse the vector
////        for(vector<int>::reverse_iterator rit=strength.rbegin();rit!=strength.rend();rit++){
////            cout<<*rit<<endl;
////        }
////1
////6
////12 11 10 9 8 7
////12 11 10 9 8 7
//
//
//
//    }
//    return 0;
//}




//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
/////lower bound upper bound
//int main()
//{
//    int T;cin>>T;
//    while(T--){
//        ///numbers of animals in each testcase
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        //collect the input
//        vector<int> strength;
//        vector<int> height;
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            strength.push_back(temp);
//        }
//        for(int i=0;i<num;i++){
//            int temp;
//            cin>>temp;
//            height.push_back(temp);
//        }
//
//        ///record cur animal
//        vector<int>::reverse_iterator cur_animal=strength.rend();cur_animal--;
//        vector<int>::reverse_iterator cur_animal_h=height.rend();cur_animal_h--;
//        ///for every animal
//        for(auto animal:strength){
//
//            ///--------------search in strength-------------
//            ///find the answer
//            //determine r start point r end point and target
//            vector <int>::reverse_iterator rit_start_s=cur_animal;//included
//            vector <int>::reverse_iterator rit_end_s=strength.rend();//not included
//            int target_strength=animal;
//            ///the first one greater than its strength
//            auto it_target=lower_bound(rit_start_s,rit_end_s,target_strength);
//
//            cout<<"upper bound for: "<<*cur_animal<<" is "<<*it_target<<endl;
//
//            //if cant find upper bound
//            //find lower bound
//
//
//            //if we have a upper bound
//
//            ///--------------search in height-------------
//            if(it_target!=height.end()){
//            vector <int>::reverse_iterator rit_start_h=cur_animal_h;
//            vector <int>::reverse_iterator rit_end_h=height.rbegin();advance(rit_end_h,distance(strength.rbegin(),it_target));
//            int target_height=animal;
//            ///the first one greater than its strength
//            auto it_target=upper_bound(rit_start,rit_end,target_strength);
//
//
//
//
//
//
//            //second record the answer because of its potential to be answer of next
//
//            cur_animal--;
//        }
//    }
//    return 0;
//}



//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int T;cin>>T;
//    while(T--){
//        numbers of animals in each testcase
//        int num;
//        cin>>num;
//        getchar();//remove endline
//
//        /collect the input
//        string temp;
//        getline(cin,temp);
//        stringstream s(temp);
//
//        getline(cin,temp);
//        stringstream h(temp);
//
//        compare and get
//        /store using a vector
//        vector<vector<int>>v;
//
//
//        int max_s=-1,max_h=-1,max_ind=0;//max ind is also total of discarded elements
//        int temp_h,temp_s;int ind=0;
//        while((s>>temp_s)&&(h>>temp_h)){
//            increase index
//            ind++;
//
//            /answer
//            check for ans from the vector
//            bool found=false;
//            for(int row=v.size()-1;row>=0;row--){
//                if(v[row][0]>temp_s){
//                    generate index
//                    int gen_ind=max_ind+row+1;
//                    cout<<gen_ind<<((ind==num)?"\n":" ");
//                    found=true;
//                    break;
//                }
//                else if((v[row][0]==temp_s)&&(v[row][1]>temp_h)){
//                    generate index
//                    int gen_ind=max_ind+row+1;
//                    cout<<gen_ind<<((ind==num)?"\n":" ");
//                    found=true;
//                    break;
//                }
//            }
//            if not found
//            if(!found){
//                if(max_s>temp_s)cout<<max_ind<<((ind==num)?"\n":" ");
//                else if((max_s==temp_s)&&(max_h>temp_h)){cout<<max_ind<<((ind==num)?"\n":" ");}
//                else cout<<0<<((ind==num)?"\n":" ");
//            }
//
//            push
//            v.push_back({temp_s,temp_h});
//
//            update the greatest strength and height and ind//maintain the data structure
//            if((temp_s>max_s)||((temp_s==max_s)&&(temp_h>max_h))){
//                max_s=temp_s;
//                max_h=temp_h;
//                max_ind=ind;
//                clear the queue
//                v.clear();
//            }
//        }
//    }
//    return 0;
//}
