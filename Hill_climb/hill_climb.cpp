#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<int> position;


matrix SOLUTION = {{1,2,3},{4,5,6}, {7,8,0}};


int hValue(matrix node)
{
    int heuristic = 0;

    for(int i = 0; i< node.size(); i++){
        for(int j = 0; j< node.size(); j++){
            for(int x = 0; x<node.size(); x++){
                for(int y = 0; y < node.size(); y++){
                    if(SOLUTION[i][j] == node[x][y])
                        heuristic += abs(i-x) + abs(j - y);
                }
            }

        }
    }
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

void hill_climb(matrix node){
    matrix livenode = node;

    while(true){

        vector<matrix> children = genChildren(livenode);
        int min = 0;
        
        for(int i = 0; i < children.size(); i++)
        {
            if( hValue(children[i]) < hValue(children[min]) )
                min = i;
        }

        if(hValue(children[min]) > hValue(livenode))
        {
            if(checkSame(livenode,  SOLUTION)){
                cout<<"Solution found"<<endl;
                printNode(livenode);
                break;
            } else{
                cout<<"Local Maxima"<<endl;
                printNode(livenode);
                break;
            }
        }

        livenode = children[min];
    }

    
    

}


int main() {
    matrix root = {{1,2,3},{4,0,6}, {7,5,8}};
    hill_climb(root);

    

    return 0;
}
