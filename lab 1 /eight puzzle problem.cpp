#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
typedef vector<vector<int>> matrix;
typedef vector<int> position;



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

void DFS(matrix problem, matrix solution){
    stack<matrix> node_stack;
    node_stack.push(problem);
    vector<matrix> closed_list;
    matrix livenode;
    
    
    while(!node_stack.empty()){
        livenode = node_stack.top();
        node_stack.pop();
        
        if(checkSame(livenode, solution)){
            cout<<"Solution found!!";
            return;
        }
        
        vector<matrix> children = genChildren(livenode);
        closed_list.push_back(livenode);
        
        for(int i = 0; i < children.size(); i++)
        {
            if(!presentInClosedList(children[i],closed_list))
                node_stack.push(children[i]);
            
        }

        
    }
    cout<<"No possible Solution found";


}

void BFS(matrix problem, matrix solution){
    queue<matrix> node_queue;
    node_queue.push(problem);
    vector<matrix> closed_list;
    matrix livenode;

    while (!node_queue.empty())
    {
       livenode = node_queue.front();
       node_queue.pop();

       if(checkSame(livenode, solution)){
            cout<<"Solution found!!";
            return;
        }

        vector<matrix> children = genChildren(livenode);
        closed_list.push_back(livenode);
        
        for(int i = 0; i < children.size(); i++)
        {
            if(!presentInClosedList(children[i],closed_list))
                node_queue.push(children[i]);
            
        }


    }

    cout<<"No possible Solution found";
    
}


int main() {

    matrix solution = {{1,2,3},{4,5,6},{7,8,0}}; // Zero is represented by empty
    matrix problem = {{1,2,3},{4,5,6},{7,0,8}};
    
    
    DFS(problem,solution);



    return 0;
}
