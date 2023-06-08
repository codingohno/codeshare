#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool explored[15][301][401] = { false };

class Game {
	typedef  vector<int> State; // { level, player HP, enemy HP, Round }
private:
	int levelinfo[15][2]; //dmg ,heal
	int maxLevel;
	int maxPlayerHP;
	int monsterDMG;

	queue<State> search_queue;

	bool isSolution(State& curState) {
		return curState[2] - levelinfo[curState[0]][0] <= 0;
	}

	void extend(State& curState) { // Only valid states are pushed.
		if (curState[1] - monsterDMG > 0) { // Attack, Level-Up.
			search_queue.push(State{ curState[0], curState[1] - monsterDMG,curState[2] - levelinfo[curState[0]][0], curState[3] + 1 });
			if (curState[0] + 1 != maxLevel)
				search_queue.push(State{ curState[0] + 1, curState[1] - monsterDMG,curState[2], curState[3] + 1 });
		} // Heal.
		if (min(maxPlayerHP, curState[1] + levelinfo[curState[0]][1]) - monsterDMG > 0)
			search_queue.push(State{ curState[0], min(maxPlayerHP,curState[1] + levelinfo[curState[0]][1]) - monsterDMG,curState[2], curState[3] + 1 });
	}


public:
	Game(int L, int HP, int MHP, int MDMG) : maxLevel(L), maxPlayerHP(HP), monsterDMG(MDMG) {
		for (int i = 0; i < maxLevel; i++){
			cin >> levelinfo[i][0] >> levelinfo[i][1];
		}
		search_queue.push(State{ 0, HP, MHP, 1 }); // Root State (always valid)
	}

	void solve() {
		while (!search_queue.empty()) {
			State curState = search_queue.front();
			search_queue.pop();
			if (explored[curState[0]][curState[1]][curState[2]])
				continue;
			else explored[curState[0]][curState[1]][curState[2]] = true;
			if (isSolution(curState)) {
				cout << curState[3] << '\n';
				return;
			}
			extend(curState);
		}
		cout << "-1\n"; // Impossible.
	}
};

int main() {
	int lvl, health_pow, MHP, MDMG;
	cin >> lvl >> health_pow >> MHP >> MDMG;
	Game G(lvl,health_pow, MHP, MDMG);
	G.solve();

	return 0;
}



//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//#define MONSTER_HP 0
//#define PLAYER_HP 1
//#define PLAYER_LEVEL 2
//#define PLAYER_ATTACK 3
//#define PLAYER_HEAL 4
//#define MOVES 5
//
//using namespace std;
//typedef struct _state{
//    int monster_hp,player_hp,player_level,
//
//}state;
//
//int main(void){
//
//    //define a state
//    ///state {monster_hp,player_hp,player level,moves}
//
//    //we have 4 data in state:
//    typedef vector<int> state;
//
//
//    //get data
//    int max_lvl,p_max_hp,m_hp,m_dmg;
//    cin>>max_lvl>>p_max_hp>>m_hp>>m_dmg;
//    /*cout<<"monster hp"<<m_hp<<endl;
//    cout<<"monster damage"<<m_dmg<<endl;
//    cout<<"player hp"<<p_max_hp<<endl;
//    cout<<"player max level"<<max_lvl<<endl;*/
//
//    //vector of levels
//    vector<vector<int>> level_info;
//    level_info.push_back({0,0});
//    for(int i=1;i<=max_lvl;i++){
//        int atk=-1,heal=-1;
//        cin>>atk>>heal;
//        level_info.push_back({atk,heal});
//    }
//    int solution=-1;
//    //make first state
//
//    ///state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//    state first={m_hp,p_max_hp,1,level_info[1][0],level_info[1][1],0};
//
//    //put in made q
//    queue <state> q ;
//    q.push(first);
//    bool done=false;
//    int while_loop_count=0;
//
//    cout<<"monster_hp,player_hp,player level,player_attack,player_heal,moves"<<endl;
//    while((!q.empty())&&(!done)){
//        while_loop_count++;
//        //cout<<"whlie loop"<<while_loop_count<<endl;
//        //get one from the front
//        state get_state=q.front();
//        q.pop();
//
//        //check for dead person
//        if(get_state[PLAYER_HP]<=0){continue;}
//
//        //else not deead
//
//        ///if we can survive always choose to attack first//or we will win before the monster attack up
//        if((get_state[PLAYER_HP]-m_dmg>0)||(get_state[MONSTER_HP]-get_state[PLAYER_ATTACK]<=0)){
//            //attack
//            state extend_1=get_state;
//            cout<<"\nbefore "<<extend_1[0]<<" "<<extend_1[1]<<" "<<extend_1[2]<<" "<<extend_1[3]<<" "<<extend_1[4]<<" "<<extend_1[5]<<endl;
//            extend_1[MOVES]+=1;
//            extend_1[MONSTER_HP]-=get_state[PLAYER_ATTACK];
//            extend_1[PLAYER_HP]-=m_dmg;
//            cout<<"monster hp after"<<extend_1[MONSTER_HP]<<endl;
//            if(extend_1[MONSTER_HP]<=0){cout<<"changing the solution value"<<endl;solution=extend_1[MOVES];done=true;}
//            else if(extend_1[PLAYER_HP]>0){q.push(extend_1);cout<<"push in: "<<extend_1[0]<<" "<<extend_1[1]<<" "<<extend_1[2]<<" "<<extend_1[3]<<" "<<extend_1[4]<<" "<<extend_1[5]<<endl;}
//        }
//        ///else we will try to heal
//        else{
//            //heal
//            state extend_2=get_state;
//            extend_2[MOVES]+=1;
//            extend_2[PLAYER_HP]+=get_state[PLAYER_HEAL];
//            //remove extra healing
//            if(extend_2[PLAYER_HP]>p_max_hp){extend_2[PLAYER_HP]=p_max_hp;}
//            //monster damage
//            extend_2[PLAYER_HP]-=m_dmg;
//            //check for same health
//            if((extend_2[PLAYER_HP]>0)&&(extend_2[PLAYER_HP]!=get_state[PLAYER_HP])){q.push(extend_2);cout<<"push in: "<<extend_2[0]<<" "<<extend_2[1]<<" "<<extend_2[2]<<" "<<extend_2[3]<<" "<<extend_2[4]<<" "<<extend_2[5]<<endl;}
//        }
//        ///also if we are not going to die we will level up
//        //level up
//        state extend_3=get_state;
//        extend_3[MOVES]+=1;
//        extend_3[PLAYER_HP]-=m_dmg;
//        extend_3[PLAYER_LEVEL]+=1;
//        if((extend_3[PLAYER_LEVEL]<=max_lvl)&&(extend_3[PLAYER_HP]>0)){
//            extend_3[PLAYER_ATTACK]=level_info[extend_3[PLAYER_LEVEL]][0];
//            extend_3[PLAYER_HEAL]=level_info[extend_3[PLAYER_LEVEL]][1];
//            q.push(extend_3);
//            cout<<"push in: "<<extend_3[0]<<" "<<extend_3[1]<<" "<<extend_3[2]<<" "<<extend_3[3]<<" "<<extend_3[4]<<" "<<extend_3[5]<<endl;
//        }
//
//        cout<<"CUR SOLUTION VAL"<<solution<<endl<<endl;
//    }
//    cout<<solution<<endl;
//
//}



//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//#define MONSTER_HP 0
//#define PLAYER_HP 1
//#define PLAYER_LEVEL 2
//#define PLAYER_ATTACK 3
//#define PLAYER_HEAL 4
//#define MOVES 5
//
//using namespace std;
//
//int main(void){
//
//    //define a state
//    ///state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//
//    //we have 4 data in state:
//    typedef vector<int> state;
//
//
//    //get data
//    int max_lvl,p_max_hp,m_hp,m_dmg;
//    cin>>max_lvl>>p_max_hp>>m_hp>>m_dmg;
//    /*cout<<"monster hp"<<m_hp<<endl;
//    cout<<"monster damage"<<m_dmg<<endl;
//    cout<<"player hp"<<p_max_hp<<endl;
//    cout<<"player max level"<<max_lvl<<endl;*/
//
//    //vector of levels
//    vector<vector<int>> level_info;
//    level_info.push_back({0,0});
//    for(int i=1;i<=max_lvl;i++){
//        int atk=-1,heal=-1;
//        cin>>atk>>heal;
//        level_info.push_back({atk,heal});
//    }
//    int solution=-1;
//    //make first state
//
//    ///state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//    state first={m_hp,p_max_hp,1,level_info[1][0],level_info[1][1],0};
//
//    //put in made q
//    queue <state> q ;
//    q.push(first);
//    bool done=false;
//    int while_loop_count=0;
//
//    cout<<"monster_hp,player_hp,player level,player_attack,player_heal,moves"<<endl;
//    while((!q.empty())&&(!done)){
//        while_loop_count++;
//        //cout<<"whlie loop"<<while_loop_count<<endl;
//        //get one from the front
//        state get_state=q.front();
//        q.pop();
//
//        //check for dead person
//        if(get_state[PLAYER_HP]<=0){continue;}
//
//        //else not deead
//
//        ///if we can survive always choose to attack first//or we will win before the monster attack up
//        if((get_state[PLAYER_HP]-m_dmg>0)||(get_state[MONSTER_HP]-get_state[PLAYER_ATTACK]<=0)){
//            //attack
//            state extend_1=get_state;
//            cout<<"\nbefore "<<extend_1[0]<<" "<<extend_1[1]<<" "<<extend_1[2]<<" "<<extend_1[3]<<" "<<extend_1[4]<<" "<<extend_1[5]<<endl;
//            extend_1[MOVES]+=1;
//            extend_1[MONSTER_HP]-=get_state[PLAYER_ATTACK];
//            extend_1[PLAYER_HP]-=m_dmg;
//            cout<<"monster hp after"<<extend_1[MONSTER_HP]<<endl;
//            if(extend_1[MONSTER_HP]<=0){cout<<"changing the solution value"<<endl;solution=extend_1[MOVES];done=true;}
//            else if(extend_1[PLAYER_HP]>0){q.push(extend_1);cout<<"push in: "<<extend_1[0]<<" "<<extend_1[1]<<" "<<extend_1[2]<<" "<<extend_1[3]<<" "<<extend_1[4]<<" "<<extend_1[5]<<endl;}
//        }
//        ///else we will try to heal
//        else{
//            //heal
//            state extend_2=get_state;
//            extend_2[MOVES]+=1;
//            extend_2[PLAYER_HP]+=get_state[PLAYER_HEAL];
//            //remove extra healing
//            if(extend_2[PLAYER_HP]>p_max_hp){extend_2[PLAYER_HP]=p_max_hp;}
//            //monster damage
//            extend_2[PLAYER_HP]-=m_dmg;
//            //check for same health
//            if((extend_2[PLAYER_HP]>0)&&(extend_2[PLAYER_HP]!=get_state[PLAYER_HP])){q.push(extend_2);cout<<"push in: "<<extend_2[0]<<" "<<extend_2[1]<<" "<<extend_2[2]<<" "<<extend_2[3]<<" "<<extend_2[4]<<" "<<extend_2[5]<<endl;}
//        }
//        ///also if we are not going to die we will level up
//        //level up
//        state extend_3=get_state;
//        extend_3[MOVES]+=1;
//        extend_3[PLAYER_HP]-=m_dmg;
//        extend_3[PLAYER_LEVEL]+=1;
//        if((extend_3[PLAYER_LEVEL]<=max_lvl)&&(extend_3[PLAYER_HP]>0)){
//            extend_3[PLAYER_ATTACK]=level_info[extend_3[PLAYER_LEVEL]][0];
//            extend_3[PLAYER_HEAL]=level_info[extend_3[PLAYER_LEVEL]][1];
//            q.push(extend_3);
//            cout<<"push in: "<<extend_3[0]<<" "<<extend_3[1]<<" "<<extend_3[2]<<" "<<extend_3[3]<<" "<<extend_3[4]<<" "<<extend_3[5]<<endl;
//        }
//
//        cout<<"CUR SOLUTION VAL"<<solution<<endl<<endl;
//    }
//    cout<<solution<<endl;
//
//}








//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//#define MONSTER_HP 0
//#define PLAYER_HP 1
//#define PLAYER_LEVEL 2
//#define PLAYER_ATTACK 3
//#define PLAYER_HEAL 4
//#define MOVES 5
//
//using namespace std;
//
//int main(void){
//
//    //define a state
//    ///state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//
//    //we have 4 data in state:
//    typedef vector<int> state;
//
//
//    //get data
//    int max_lvl,p_max_hp,m_hp,m_dmg;
//    cin>>max_lvl>>p_max_hp>>m_hp>>m_dmg;
//    /*cout<<"monster hp"<<m_hp<<endl;
//    cout<<"monster damage"<<m_dmg<<endl;
//    cout<<"player hp"<<p_max_hp<<endl;
//    cout<<"player max level"<<max_lvl<<endl;*/
//
//    //vector of levels
//    vector<vector<int>> level_info;
//    level_info.push_back({0,0});
//    for(int i=1;i<=max_lvl;i++){
//        int atk=-1,heal=-1;
//        cin>>atk>>heal;
//        level_info.push_back({atk,heal});
//    }
//    int solution=-1;
//    //make first state
//
//    ///state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//    state first={m_hp,p_max_hp,1,level_info[1][0],level_info[1][1],0};
//
//    //put in made q
//    queue <state> q ;
//    q.push(first);
//    bool done=false;
//    int while_loop_count=0;
//
//    //cout<<"monster_hp,player_hp,player level,player_attack,player_heal,moves"<<endl;
//    while((!q.empty())&&(!done)){
//        while_loop_count++;
//        if(while_loop_count>1000){while(1){}}
//        //cout<<"whlie loop"<<while_loop_count<<endl;
//        //get one from the front
//        state get_state=q.front();
//        q.pop();
//
//        //check for dead person
//        if(get_state[PLAYER_HP]<=0){continue;}
//
//        //else not deead
//        //attack
//        state extend_1=get_state;
//        extend_1[MOVES]+=1;
//        extend_1[MONSTER_HP]-=get_state[PLAYER_ATTACK];
//        extend_1[PLAYER_HP]-=m_dmg;
//        if(extend_1[MONSTER_HP]<=0){solution=extend_1[MOVES];done=true;}
//        else if(extend_1[PLAYER_HP]>0){q.push(extend_1);/*cout<<"push in: "<<extend_1[0]<<" "<<extend_1[1]<<" "<<extend_1[2]<<" "<<extend_1[3]<<" "<<extend_1[4]<<" "<<extend_1[5]<<endl;*/}
//
//
//        //heal
//        state extend_2=get_state;
//        extend_2[MOVES]+=1;
//        extend_2[PLAYER_HP]+=get_state[PLAYER_HEAL];
//        extend_2[PLAYER_HP]-=m_dmg;
//        if(extend_2[PLAYER_HP]>p_max_hp){extend_2[PLAYER_HP]=p_max_hp;}
//        //check for same health
//        if((extend_2[PLAYER_HP]>0)&&(extend_2[PLAYER_HP]!=get_state[PLAYER_HP])){q.push(extend_2);/*cout<<"push in: "<<extend_2[0]<<" "<<extend_2[1]<<" "<<extend_2[2]<<" "<<extend_2[3]<<" "<<extend_2[4]<<" "<<extend_2[5]<<endl;*/}
//
//
//        //level up
//        state extend_3=get_state;
//        extend_3[MOVES]+=1;
//        extend_3[PLAYER_HP]-=m_dmg;
//        extend_3[PLAYER_LEVEL]+=1;
//        if((extend_3[PLAYER_LEVEL]<=max_lvl)&&(extend_3[PLAYER_HP]>0)){
//            extend_3[PLAYER_ATTACK]=level_info[extend_3[PLAYER_LEVEL]][0];
//            extend_3[PLAYER_HEAL]=level_info[extend_3[PLAYER_LEVEL]][1];
//            q.push(extend_3);
//            //cout<<"push in: "<<extend_3[0]<<" "<<extend_3[1]<<" "<<extend_3[2]<<" "<<extend_3[3]<<" "<<extend_3[4]<<" "<<extend_3[5]<<endl;
//        }
//    }
//    cout<<solution<<endl;
//
//}
//





//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//
//using namespace std;
//
////define a state
/////state {monster_hp,player_hp,player level,player_attack,player_heal,moves}
//
////we have 4 data in state:
//typedef vector<int> state;
//typedef pair<int,int> level_info;
//class monster{
//private:
//    int monster_initial_hp;
//    int player_max_hp;
//    int player_max_level;
//    int monster_damage;
//    vector<level_info> level_data_vector;
//    int solutions;
//
//
//public:
//    monster();
//    void solve();
//    set<state> extend(const state selected_state);
//    void show();
//};
//
//void monster::show(){
//    cout<<solutions<<endl;
//}
//
//
//set<state> monster::extend(const state selected_state){
//    set<state> ret_set;
//    state temp=selected_state;
//
//    ///check alive
//    if(temp[1]<=0){return ret_set;}
//
//    ///player attack
//    //we dont do player death checking while generating result because the monster might be already dead
//    //0:monster_hp
//    temp[0]-=selected_state[3];
//    //1:player_hp
//    temp[1]-=monster_damage;
//    //2:player level
//    temp[2]=selected_state[2];
//    //3:player_attack
//    temp[3]=selected_state[3];
//    //4:player_heal
//    temp[4]=selected_state[4];
//    //5:moves
//    temp[5]=selected_state[5]+1;
//    ret_set.insert(temp);
//
//    //player heal //check whether if heal will change hp status// if hp dont change dont allow
//    int new_hp=selected_state[1]+selected_state[4]-monster_damage;
//    if(new_hp>player_max_hp){new_hp=player_max_hp;}
//    if(new_hp!=selected_state[1]){//make sure hp not going back to the same state
//
//        //0:monster_hp
//        temp[0]=selected_state[0];
//        //1:player_hp
//        temp[1]=new_hp;
//        //2:player level
//        temp[2]=selected_state[2];
//        //3:player_attack
//        temp[3]=selected_state[3];
//        //4:player_heal
//        temp[4]=selected_state[4];
//        //5:moves
//        temp[5]=selected_state[5]+1;
//
//
//        ret_set.insert(temp);
//
//    }
//
//    //player level up
//    //check whether reach max level
//    if(selected_state[2]!=player_max_level){
//        temp=selected_state;
//
//        //0:monster_hp
//        temp[0]=selected_state[0];
//        //1:player_hp
//        temp[1]=selected_state[1]-monster_damage;
//        //2:player level
//        temp[2]=selected_state[2]+1;
//        //3:player_attack
//        temp[3]=level_data_vector[selected_state[2]+1].first;
//        //4:player_heal
//        temp[4]=level_data_vector[selected_state[2]+1].second;
//        //5:moves
//        temp[5]=selected_state[5]+1;
//
//        ret_set.insert(temp);
//
//    }
//
//    return ret_set;
//
//}
//
//void monster::solve(){
//    //create a queue to track the states exploration
//    queue <state> q;
//
//    //input first state
//    ///state {0:monster_hp,1:player_hp,2:player level,3:player_attack,4:player_heal,5:moves}
//    state first_state={monster_initial_hp,player_max_hp,1,level_data_vector[1].first,level_data_vector[1].second,0};
//    q.push(first_state);
//
//    ///start game
//    while(!q.empty()){
//        //get a state from the queue
//        state selected_state=q.front();
//        q.pop();
//
//
//        //extend all your possiblilities //there is no way to go back to the last state//level up one way//stop level up when max//attacking is one way //only healing might cuz looping//stop healing when max
//        set<state> next_states_set=extend(selected_state);//generate if the player is alive
//
//        for(auto pos_state:next_states_set){
//            //check for answer //all given states are derived when a player is still alive
//            ///win
//            if(pos_state[0]<=0){
//                //record moves
//                solutions=pos_state[5];
//                break;
//            }
//            else{
//                //if alive add it back to the queue
//                bool alive=(pos_state[1]>0)?true:false;
//                if(alive){
//                    q.push(pos_state);
//                }
//            }
//        }
//
//        //check if done
//        if(solutions!=-1){//done
//            break;
//        }
//        //else not done here we go again to the queue
//    }
//    return ;
//}
//
//
//
//monster::monster(){
//    int p_max_hp,m_init_hp,pml,md;
//    cin>>pml>>p_max_hp>>m_init_hp>>md;
//
//    monster_initial_hp=m_init_hp;
//    monster_damage=md;
//    player_max_hp=p_max_hp;
//    player_max_level=pml;
//
//    solutions=-1;
//
//    //input level info into vector
//    //put a dummy at the 0th place
//    level_data_vector.emplace_back(level_info(-1,-1));
//    for(int i=1;i<=player_max_level;i++){
//        int temp_attack,temp_heal;
//        cin>>temp_attack>>temp_heal;
//
//        //insert level info
//        level_data_vector.emplace_back(level_info(temp_attack,temp_heal));
//    }
//}
//
//
//int main()
//{
//    ///find shortest the best way is bfs
//    //create
//    monster MONSTER;
//    //solve
//    MONSTER.solve();
//    //show ans
//    MONSTER.show();
//
//    return 0;
//}

///try none oop way
