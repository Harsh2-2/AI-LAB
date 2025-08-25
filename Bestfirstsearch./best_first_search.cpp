#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<int> position;


matrix SOLUTION = {{1,2,3},{4,5,6}, {7,8,0}};
int hValue(matrix node);

class Compare{
    public: 
        bool operator()(matrix a, matrix b)
        {
            if(hValue(a) > hValue(b)){
                return true;
            }
            return false;
        }

};

int hValue(matrix node)
{
    int heuristic = 0;


    // Number of wrong tiles heuristic.
    for(int i = 0; i < node.size(); i++){
        for(int j = 0; j < node.size(); j++){
            if(node[i][j] != SOLUTION[i][j])
                heuristic++;
        }
    }

    // Distance heuristic.
    // for(int i = 0; i< node.size(); i++){
    //     for(int j = 0; j< node.size(); j++){
    //         for(int x = 0; x<node.size(); x++){
    //             for(int y = 0; y < node.size(); y++){
    //                 if(SOLUTION[i][j] == node[x][y])
    //                     heuristic += abs(i-x) + abs(j - y);
    //             }
    //         }

    //     }
    // }
    return heuristic;

    
}

void printNode(matrix node) {
    for(int i = 0; i<node.size(); i++){
        for(int j = 0; j<node[0].size(); j++){
            cout<<node[i][j]<<" ";
        }
        cout<<'\n';
    }
}

bool checkSame(matrix problem, matrix solution) {
    for(int i = 0; i<problem.size(); i++){
        for(int j = 0; j<problem[0].size(); j++){
            if(problem[i][j] != solution[i][j])
                return false;
        }
    }
    return true;
}

matrix move(matrix node, position zero_position, position swap_position ){
    node[zero_position[0]][zero_position[1]] = node[swap_position[0]][swap_position[1]];
    node[swap_position[0]][swap_position[1]] = 0;
    return node;
}

vector<int> findZero(matrix node){
    position position = {-1,-1};
    for(int i = 0; i<node.size(); i++){
        for(int j = 0; j<node[0].size(); j++){
            if(node[i][j] == 0){
                position[0] = i;
                position[1] = j;
            }    
        }
    }
    return position;
}

vector<matrix> genChildren(matrix node){
    position position_zero = findZero(node);
    position position_swap = {-1,-1};
    vector<matrix> children;

    // Upper move
    if(position_zero[0] - 1 >= 0){
        position_swap[0] = position_zero[0] - 1;
        position_swap[1] = position_zero[1];
        children.push_back(move(node, position_zero, position_swap));
    }

    // Down move
    if(position_zero[0] + 1 < node.size()){
        position_swap[0] = position_zero[0] + 1;
        position_swap[1] = position_zero[1];
        children.push_back(move(node, position_zero, position_swap));
    }


    // Left move
    if(position_zero[1] - 1 >= 0){
        position_swap[0] = position_zero[0];
        position_swap[1] = position_zero[1] - 1;
        children.push_back(move(node, position_zero, position_swap));
    }


    // Right move
    if(position_zero[1] + 1 < node[0].size()){
        position_swap[0] = position_zero[0];
        position_swap[1] = position_zero[1] + 1;
        children.push_back(move(node, position_zero, position_swap));
    }

    return children;    
        
}

bool presentInClosedList(matrix node, vector<matrix> list){

    for(int i = 0; i < list.size(); i++){
        
        if(checkSame(node,list[i])){
            return true;
        }
    }
    return false;
}


void bestFirstSearch(matrix node){
    priority_queue<matrix, vector<matrix>, Compare> pQueue;
    pQueue.push(node);
    vector<matrix> closed_list;
    matrix livenode;
    int count = 0;

    while(!pQueue.empty()){
        count++;
        livenode = pQueue.top();
        pQueue.pop();

        if(checkSame(livenode, SOLUTION)){
            cout<<"Count: "<<count<<endl;
            cout<<"Solution found!!";
            return;
        }

        vector<matrix> children = genChildren(livenode);
        closed_list.push_back(livenode);
        
        for(int i = 0; i < children.size(); i++)
        {
            if(!presentInClosedList(children[i],closed_list))
                {
                    pQueue.push(children[i]);
                }
            
        }
    }

    cout<<"Sollution not found";
}


int main() {

    // matrix root = {{2,6,4},{7,0,3}, {5,1,8}};
    matrix root = {{5,1,3},{4,2,6}, {7,0,8}};

    bestFirstSearch(root);

        
    
    
    return 0;
}
