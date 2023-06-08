#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <list>

using namespace std;
typedef vector<int> state;//9 int vector is a state

class solver{
private:
    state initial_vec;
    int ans=-1;
    set<state> explored;//only 9 are needed to put in
public:
    solver();
    void solving();
    set<state> extend(state chosen_state);
    void show_ans();
};

void solver::show_ans(){
    if(ans!=-1){cout<<"You can solve it within "<<ans<<" steps.\n";}
    else{cout<<"You'd better skip this game.\n";}
}

set<state> solver::extend(state chosen_state){
    chosen_state[9]++;
    set<state> ret_set;

    //first find the location of zero
    int loc=0;
    for(int i=0;i<9;i++){
        if(chosen_state[i]==0){loc=i;break;}
    }
    int zero_col=loc%3;
    int zero_row=loc/3;

    //check up
    if(zero_row-1>=0){
        //exchange
        state temp_state=chosen_state;
        temp_state[loc]=chosen_state[loc-3];
        temp_state[loc-3]=0;

        //if not found in explored we can insert into set
        //for explore check
        state store_visited=temp_state;store_visited.erase(--store_visited.end());
        if(explored.count(store_visited)==0){ret_set.insert(temp_state);}
    }
    //check down
    if(zero_row+1<=2){
        //exchange
        state temp_state=chosen_state;
        temp_state[loc]=chosen_state[loc+3];
        temp_state[loc+3]=0;

        //if not found in explored we can insert into set
        //for explore check
        state store_visited=temp_state;store_visited.erase(--store_visited.end());
        if(explored.count(store_visited)==0){ret_set.insert(temp_state);}
    }
    //check left
    if(zero_col-1>=0){
        //exchange
        state temp_state=chosen_state;
        temp_state[loc]=chosen_state[loc-1];
        temp_state[loc-1]=0;

        //if not found in explored we can insert into set
        //for explore check
        state store_visited=temp_state;store_visited.erase(--store_visited.end());
        if(explored.count(store_visited)==0){ret_set.insert(temp_state);}

    }
    //check right
    if(zero_col+1<=2){
        //exchange
        state temp_state=chosen_state;
        temp_state[loc]=chosen_state[loc+1];
        temp_state[loc+1]=0;

        //if not found in explored we can insert into set
        //for explore check
        state store_visited=temp_state;store_visited.erase(--store_visited.end());
        if(explored.count(store_visited)==0){ret_set.insert(temp_state);}
    }

    return ret_set;
}

void solver::solving(){
    //one queue needed for bfs
    queue<state> Q;
    //make init state

    Q.push(initial_vec);

    //check for first one
    if((initial_vec[0]==1)&&(initial_vec[1]==2)&&(initial_vec[2]==3)&&(initial_vec[3]==4)&&(initial_vec[4]==5)&&(initial_vec[5]==6)&&(initial_vec[6]==7)&&(initial_vec[7]==8)&&(initial_vec[8]==0)){
        ans=0;
        return ;
    }


    while(!Q.empty()){
        //get a state from the queue
        state select=Q.front();
        Q.pop();

        //check for too much steps
        if(select[9]>14){return ;}

        //mark as explored
        state store_visited=select;store_visited.erase(--store_visited.end());
        explored.insert(store_visited);
        //extend and explore
        set<state> set_of_next_moves=extend(select);
        //for every next possible move
        for(auto pos_next_state:set_of_next_moves){
            //if is answer
            if((pos_next_state[8]==0)&&(pos_next_state[7]==8)&&(pos_next_state[6]==7)&&(pos_next_state[5]==6)&&(pos_next_state[4]==5)&&(pos_next_state[3]==4)&&(pos_next_state[2]==3)&&(pos_next_state[1]==2)&&(pos_next_state[0]==1))
            {
                ans=pos_next_state[9];
                return ;
            }

            //else not answer
            //insert into queue
            else{
                Q.push(pos_next_state);
            }
        }
    }


}


solver::solver(){
    //get initial state
    int temp;
    for(int i=0;i<9;i++){
        cin>>temp;
        initial_vec.push_back(temp);
    }
    initial_vec.push_back(0);

    ans=-1;
}


int main()
{
    int T;
    cin>>T;
    while(T--){
        solver S;
        S.solving();
        S.show_ans();
    }

    return 0;
}






