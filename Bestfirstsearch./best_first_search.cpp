
#include <iostream>
using namespace std;

string goal = "123456780";   // Goal state (0 = blank)

// Function to count misplaced tiles (heuristic)
int heuristic(string s) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] != '0' && s[i] != goal[i]) h++;
    }
    return h;
}

// Function to print puzzle state in 3x3 grid
void printState(string s) {
    for (int i = 0; i < 9; i++) {
        cout << s[i] << " ";
        if (i % 3 == 2) cout << endl;
    }
    cout << endl;
}

// Function to generate all possible moves
vector<string> getNextStates(string s) {
    vector<string> nextStates;
    int pos = s.find('0'); // blank position
    int x = pos / 3, y = pos % 3;

    // possible moves (up, down, left, right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            string t = s;
            swap(t[pos], t[nx * 3 + ny]);
            nextStates.push_back(t);
        }
    }
    return nextStates;
}

// Node structure for priority queue
struct Node {
    string state;
    int g, h;    // g = steps, h = heuristic
    Node* parent;
};

// Comparison for Best First (only heuristic matters)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->h > b->h;
    }
};

// Function to print solution path
void printPath(Node* node) {
    vector<string> path;
    while (node != NULL) {
        path.push_back(node->state);
        node = node->parent;
    }
    reverse(path.begin(), path.end());

    cout << "\nSolution Path:\n";
    for (string s : path) {
        printState(s);
    }
}

void bestFirstSearch(string start) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    unordered_set<string> visited;

    Node* root = new Node{start, 0, heuristic(start), NULL};
    pq.push(root);

    while (!pq.empty()) {
        Node* cur = pq.top();
        pq.pop();

        if (cur->state == goal) {
            cout << "Goal reached in " << cur->g << " steps.\n";
            printPath(cur);
            return;
        }

        if (visited.count(cur->state)) continue;
        visited.insert(cur->state);

        vector<string> nextStates = getNextStates(cur->state);
        for (string ns : nextStates) {
            if (!visited.count(ns)) {
                Node* child = new Node{ns, cur->g + 1, heuristic(ns), cur};
                pq.push(child);
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    string start = "125340678"; // Example starting state
    cout << "Initial State:\n";
    printState(start);

    bestFirstSearch(start);

    return 0;
}
