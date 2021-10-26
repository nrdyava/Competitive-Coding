class Solution {
public:
    bool isRobotBounded(string instructions) {        
        unordered_map<char, char> left;
        unordered_map<char, char> right;
        unordered_map<char, pair<int, int>> dirs;
        
        left['N'] = 'W'; right['N'] = 'E';
        left['W'] = 'S'; right['E'] = 'S';
        left['S'] = 'E'; right['S'] = 'W';
        left['E'] = 'N'; right['W'] = 'N';
        
        dirs['N'] = make_pair(0, 1);
        dirs['W'] = make_pair(-1, 0);
        dirs['S'] = make_pair(0, -1);
        dirs['E'] = make_pair(1, 0);
        
        char currdir = 'N';
        int x = 0, y=0;
        int dx = dirs[currdir].first, dy = dirs[currdir].second;
        
        for(int i=0; i<instructions.length(); i++){
            if(instructions[i] == 'G'){
                x = x+dx;
                y = y+dy;
            }
            else if(instructions[i] == 'L'){
                currdir = left[currdir];
                dx = dirs[currdir].first;
                dy = dirs[currdir].second;
            }
            else if(instructions[i] == 'R'){
                currdir = right[currdir];
                dx = dirs[currdir].first;
                dy = dirs[currdir].second;
            }
        }
        if(x == 0 && y == 0) return true;
        else if(currdir != 'N') return true;
        return false;
    } 
};