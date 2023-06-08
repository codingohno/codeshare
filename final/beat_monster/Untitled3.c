//
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
//    if
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
