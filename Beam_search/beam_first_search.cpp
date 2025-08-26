#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> map;
typedef pair<int,int> position;

class Node{
    public:
        position pos;
        int h, f, g;
        Node* parent;
    
    Node(position _xy, int heuristic, int cost, Node *before ){
        pos = _xy;
        h = heuristic;
        f = heuristic + cost;
        g = cost;
        parent = before; 
    }
};

class Compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->f > b->f;
    }
};

void printMap(map map, position dest){

    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[0].size(); j++){
            if(i == dest.first && j == dest.second)
                cout<<"\033[41m   \033[0m";
            else if(map[i][j] == 1)
                cout<<"\033[47m   \033[0m";
            else if (map[i][j] == 0)
                cout<<"   ";
            else
                cout<<"\033[42m   \033[0m";
        }
        cout<<"\n";
    }
    cout<<endl<<endl;
}

bool is_visited(position cur, vector<position> visited){
    for(auto i : visited){
        if(cur == i){
            return true;
        }
    }
    return false;
}

position add_pos(position a, position b){
    return {a.first + b.first, a.second + b.second};
}

int heuristic(position cur_pos, position dest ){
    return ((dest.first - cur_pos.first) + (dest.second - cur_pos.second));
}

priority_queue<Node* , vector<Node*>, Compare> genMoves(Node* root, map map, position src, position dest){
    priority_queue<Node* , vector<Node*>, Compare> moves;
    vector<position> dir = {{0,-1},{0,1}, {-1,0}, {1,0} }; // up down left right
    for(auto i: dir){
        position next = add_pos(root->pos, i);
        if(next.first < 0 || next.first >= map.size() || next.second < 0 || next.second >= map[0].size())
            continue;
        if(map[next.first][next.second] == 1) continue;
        int h = heuristic(next, dest);
        int cost = root->g + 1;
        Node* child = new Node(next, h, cost, root);
        moves.push(child);
    }   
    return moves;
}

void beam_search(Node* root, map map, position dest, int beam_size){
    priority_queue<Node* , vector<Node*>, Compare> open_list;
    vector<position> visited;
    if(root->pos == dest){
        cout<<"Found"<<endl;
        return;
    }
    visited.push_back(root->pos);
    open_list.push(root);
    while (!open_list.empty())
    {
        Node* livenode = open_list.top();
        // cout<<livenode->pos.first<<","<<livenode->pos.second<<"\n";
        // cout<<livenode->g<<endl;
        map[livenode->pos.first][livenode->pos.second] = 2;
        printMap(map, dest);
        open_list.pop();
        priority_queue<Node* , vector<Node*>, Compare> moves = genMoves(livenode, map, livenode->pos, dest);
        for(int i = 0; i<beam_size; i++){
            if(is_visited(moves.top()->pos, visited)){
                continue;
            }
            if(moves.top()->pos == dest){
                cout<<"Found"<<endl;
                return;
            }

            open_list.push(moves.top());
            visited.push_back(moves.top()->pos);
            moves.pop();
        }
    }
}

int main(){
    map map = {
        {1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1},
        {1,0,0,0,1,0,1,0,1},
        {1,0,1,0,0,0,1,0,1},
        {1,0,1,1,0,1,0,0,1},
        {1,1,1,1,0,0,0,1,1},
        {1,0,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,1}
    };
    
    position src = {1,1};
    position dest = {7,7};
    int g = 0;
    int h = heuristic(src, dest);
    int f = g + h;
    Node* start = new Node(src, h, g, nullptr);

    // a_star_search(start, map, dest);
    beam_search(start,map,dest,2);

    return 0;
}
