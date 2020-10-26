#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
    vector <pair<int, int> > zari;
    vector <int> quick(numOfAllPlayers, 0);
    for(int i=1; i<numOfAllPlayers; ++i){
        zari.push_back(pair<int, int> (i, 0));
    }
    for(int i=0; i<numOfQuickPlayers; ++i){
        quick[(namesOfQuickPlayers[i]-'A')] = 1;
    }
    int curr = 0;
    pair <int, int> sulle (0, 1);
    for(int i=0; i<numOfGames; ++i){
        curr = (curr + numOfMovesPerGame[i])%(numOfAllPlayers-1);
		if(curr<0) curr += numOfAllPlayers-1;
        if(quick[zari[curr].first]){    // 자리에 앉은 사람의 일련번호에 대해 조사
            sulle.second += 1;
        }
        else{
            pair <int, int> tmp (zari[curr].first, zari[curr].second + 1);
            zari[curr] = sulle;
            sulle = tmp;
        }
    }
    for(int i=0; i<numOfAllPlayers-1; ++i){
        char who = zari[i].first + 'A';
        cout << who << " " << zari[i].second << endl;
    }
    char sullename = sulle.first + 'A';
    cout << sullename << " " << sulle.second << endl;

}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}

/* test input
17
5
B D I M P
11
3 -4 5 6 -7 -8 10 -12 -15 -20 23

// output
B 0
C 0
D 0
L 1
Q 1
A 3
F 2
I 0
J 0
G 1
K 1
M 0
N 0
H 1
P 0
E 1
O 1
*/