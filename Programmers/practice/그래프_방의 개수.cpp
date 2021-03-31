#include <vector>
#include <set>
#include <map>
#define x 0
#define y 1
using namespace std;
typedef vector<int> Point;

int solution(vector<int> arrows) {
    vector<Point> move = {{0, 1}, {1, 1}, {1, 0}, {1, -1},
                        {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int answer = 0;
    Point curr = {0, 0};                        // current position
    set<Point> visited = {curr};                // visited points
    map<Point, set<Point>> paths;               // visited paths

    for(auto arr: arrows){
        for(int i=0; i<2; ++i){
            // move the point to arr direction
            Point next = {curr[x]+move[arr][x], curr[y]+move[arr][y]};

            // if next point was already visited
            if(visited.find(next)!=visited.end()){
                // and current path not in visited paths
                if(paths[curr].find(next) == paths[curr].end()){
                    ++answer;                   // found a room
                }
            }
            // if next point was not visited
            else{
                visited.insert(next);
            }
            paths[curr].insert(next);   // insert curr->next path
            paths[next].insert(curr);   // insert next->curr path
            curr = next;                // point update
        }
    }
    return answer;
}
