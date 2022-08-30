#include <iostream>
using namespace std;

typedef struct cube{
					string up;
	string left; 	string front;	string right;	string back;
					string down;
}Cube;

int TC, N;
string cmd;
Cube mycube;
int face_turn_idx[2][9] = {
							{6, 3, 0, 7, 4, 1, 8, 5, 2},
							{2, 5, 8, 1, 4, 7, 0, 3, 6}
						  };

void initialize(){
	mycube.up = "wwwwwwwww";
	mycube.down = "yyyyyyyyy";
	mycube.front = "rrrrrrrrr";
	mycube.back = "ooooooooo";
	mycube.left = "ggggggggg";
	mycube.right = "bbbbbbbbb";
}

string turn_face(string f, int dir){
	string res = "";
	for(int i=0; i<9; ++i)
		res += f[face_turn_idx[dir][i]];
	return res;
}

string sub_str(string str, string cmd){
	string res = "";
	for(auto c: cmd)
		res += str[c-'0'];
	return res;
}

void write_str(string w_str, string& to_str, string cmd){
	for(int i=0; i<cmd.size(); ++i)
		to_str[cmd[i]-'0'] = w_str[i];
}

void turn_cube(string cmd){
	if(cmd == "U+"){
		mycube.up = turn_face(mycube.up, 0);
		string tmp = sub_str(mycube.front, "012");
		write_str(sub_str(mycube.right, "012"), mycube.front, "012");
		write_str(sub_str(mycube.back, "012"), mycube.right, "012");
		write_str(sub_str(mycube.left, "012"), mycube.back, "012");
		write_str(tmp, mycube.left, "012");
	}
	else if(cmd == "U-"){
		mycube.up = turn_face(mycube.up, 1);
		string tmp = sub_str(mycube.front, "012");
		write_str(sub_str(mycube.left, "012"), mycube.front, "012");
		write_str(sub_str(mycube.back, "012"), mycube.left, "012");
		write_str(sub_str(mycube.right, "012"), mycube.back, "012");
		write_str(tmp, mycube.right, "012");
	}
	else if(cmd == "D+"){
		mycube.down = turn_face(mycube.down, 0);
		string tmp = sub_str(mycube.front, "678");
		write_str(sub_str(mycube.left, "678"), mycube.front, "678");
		write_str(sub_str(mycube.back, "678"), mycube.left, "678");
		write_str(sub_str(mycube.right, "678"), mycube.back, "678");
		write_str(tmp, mycube.right, "678");
	}
	else if(cmd == "D-"){
		mycube.down = turn_face(mycube.down, 1);
		string tmp = sub_str(mycube.front, "678");
		write_str(sub_str(mycube.right, "678"), mycube.front, "678");
		write_str(sub_str(mycube.back, "678"), mycube.right, "678");
		write_str(sub_str(mycube.left, "678"), mycube.back, "678");
		write_str(tmp, mycube.left, "678");
	}
	else if(cmd == "F+"){
		mycube.front = turn_face(mycube.front, 0);
		string tmp = sub_str(mycube.up, "678");
		write_str(sub_str(mycube.left, "852"), mycube.up, "678");
		write_str(sub_str(mycube.down, "210"), mycube.left, "852");
		write_str(sub_str(mycube.right, "036"), mycube.down, "210");
		write_str(tmp, mycube.right, "036");
	}
	else if(cmd == "F-"){
		mycube.front = turn_face(mycube.front, 1);
		string tmp = sub_str(mycube.up, "678");
		write_str(sub_str(mycube.right, "036"), mycube.up, "678");
		write_str(sub_str(mycube.down, "210"), mycube.right, "036");
		write_str(sub_str(mycube.left, "852"), mycube.down, "210");
		write_str(tmp, mycube.left, "852");
	}
	else if(cmd == "B+"){
		mycube.back = turn_face(mycube.back, 0);
		string tmp = sub_str(mycube.up, "210");
		write_str(sub_str(mycube.right, "852"), mycube.up, "210");
		write_str(sub_str(mycube.down, "678"), mycube.right, "852");
		write_str(sub_str(mycube.left, "036"), mycube.down, "678");
		write_str(tmp, mycube.left, "036");
	}
	else if(cmd == "B-"){
		mycube.back = turn_face(mycube.back, 1);
		string tmp = sub_str(mycube.up, "210");
		write_str(sub_str(mycube.left, "036"), mycube.up, "210");
		write_str(sub_str(mycube.down, "678"), mycube.left, "036");
		write_str(sub_str(mycube.right, "852"), mycube.down, "678");
		write_str(tmp, mycube.right, "852");
	}
	else if(cmd == "L+"){
		mycube.left = turn_face(mycube.left, 0);
		string tmp = sub_str(mycube.up, "036");
		write_str(sub_str(mycube.back, "852"), mycube.up, "036");
		write_str(sub_str(mycube.down, "036"), mycube.back, "852");
		write_str(sub_str(mycube.front, "036"), mycube.down, "036");
		write_str(tmp, mycube.front, "036");
	}
	else if(cmd == "L-"){
		mycube.left = turn_face(mycube.left, 1);
		string tmp = sub_str(mycube.up, "036");
		write_str(sub_str(mycube.front, "036"), mycube.up, "036");
		write_str(sub_str(mycube.down, "036"), mycube.front, "036");
		write_str(sub_str(mycube.back, "852"), mycube.down, "036");
		write_str(tmp, mycube.back, "852");
	}
	else if(cmd == "R+"){
		mycube.right = turn_face(mycube.right, 0);
		string tmp = sub_str(mycube.up, "852");
		write_str(sub_str(mycube.front, "852"), mycube.up, "852");
		write_str(sub_str(mycube.down, "852"), mycube.front, "852");
		write_str(sub_str(mycube.back, "036"), mycube.down, "852");
		write_str(tmp, mycube.back, "036");
	}
	else if(cmd == "R-"){
		mycube.right = turn_face(mycube.right, 1);
		string tmp = sub_str(mycube.up, "852");
		write_str(sub_str(mycube.back, "036"), mycube.up, "852");
		write_str(sub_str(mycube.down, "852"), mycube.back, "036");
		write_str(sub_str(mycube.front, "852"), mycube.down, "852");
		write_str(tmp, mycube.front, "852");
	}
}

void print_top(){
	for(int i=0; i<9; i+=3){
		for(int j=0; j<3; ++j){
			cout << mycube.up[i+j];
		}
		cout << '\n';
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> TC;
	while(TC--){
		initialize();
		cin >> N;
		while(N--){
			cin >> cmd;
			turn_cube(cmd);
		}
	 	print_top();
	}
	return 0;
}
