#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool explored[15][301][401] = { false };

class Game {
	using State = vector<int>; // { level, player HP, enemy HP, Round }
private:
	int levelTable[15][2]; // [level] { DMG, HL }
	int maxLevel;
	int maxPlayerHP;
	int monsterDMG;

	queue<State> search_queue;

	bool isSolution(State& curState) {
		return curState[2] - levelTable[curState[0]][0] <= 0;
	}

	void extend(State& curState) { // Only valid states are pushed.
		if (curState[1] - monsterDMG > 0) { // Attack, Level-Up.
			search_queue.push(State{ curState[0], curState[1] - monsterDMG, \
				curState[2] - levelTable[curState[0]][0], curState[3] + 1 });
			if (curState[0] + 1 != maxLevel)
				search_queue.push(State{ curState[0] + 1, curState[1] - monsterDMG, \
				curState[2], curState[3] + 1 });
		} // Heal.
		if (min(maxPlayerHP, curState[1] + levelTable[curState[0]][1]) - monsterDMG > 0)
			search_queue.push(State{ curState[0], min(maxPlayerHP, \
				curState[1] + levelTable[curState[0]][1]) - monsterDMG,
				curState[2], curState[3] + 1 });
	}


public:
	Game(int L, int HP, int MHP, int MDMG) : maxLevel(L), maxPlayerHP(HP), monsterDMG(MDMG) {
	    //reset explored
	    memset(explored,0,sizeof(bool)*15*301*401);

		for (int i = 0; i < maxLevel; i++)
			cin >> levelTable[i][0] >> levelTable[i][1];
		search_queue.push(State{ 0, HP, MHP, 1 }); // Root State (always valid)
	}

	void solve() {
	    cout<<"calling sample func"<<endl;
		while (!search_queue.empty()) {
			State curState = search_queue.front();
			search_queue.pop();
			if (explored[curState[0]][curState[1]][curState[2]])
				continue;
			else explored[curState[0]][curState[1]][curState[2]] = true;
			if (isSolution(curState)) {
                ofstream sample;
                sample.open("sample_ouput.txt");
				sample << curState[3] << '\n';
                sample.close();
				return;
			}
			extend(curState);
		}
		ofstream sample;
        sample.open("sample_ouput.txt");
		sample << "-1\n"; // Impossible.
		sample.close();
	}
};



#endif // FUNCTION_H_INCLUDED
