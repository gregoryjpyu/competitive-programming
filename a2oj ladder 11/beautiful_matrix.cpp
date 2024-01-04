#include <iostream>
using namespace std;
/*
00000
00000
00010
00000
00000
*/

int main() {
    int curr;
    int res = 999;
    int dist;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> curr;
            if (curr == 1) {
                dist = abs(i - 2) + abs(j - 2);
                res = min(dist, res);
            }
        }
    }

    cout << res << endl;
    return 0;
}


/*
You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5).
You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix beautiful.



#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    vector<vector<int>> matrix(5, vector<int>(5)); //instantiate matrix
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> matrix[i][j];
        }
    }

    // bfs
    queue<tuple<int,int>> q;
    // unordered_map<int, unordered_map<int,bool>> visited;
    std::vector<std::vector<bool>> visited(5, std::vector<bool>(5, false));

    visited[2][2] = true;
    q.push({2,2});
    tuple<int, int> curr;
    int level = 0;
    while (!q.empty()) {
        int level_length = q.size();
        for (int i = 0; i < level_length; i++){
            curr = q.front(); 
            q.pop();

            // process node
            int y = get<0>(curr);
            int x = get<1>(curr);

            if (matrix[y][x] == 1){
                cout << level << endl;
                return 1;
            }

            // deal with neighbours
            vector<tuple<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};

            for (auto dir : dirs){
                int new_y = y + get<0>(dir);
                int new_x = x + get<1>(dir);

                if (visited[new_y][new_x]) continue;
                visited[new_y][new_x] = true;
            }
        }

        // increment level afterwards
        level += 1;  
    }
    // no 2 found
    return -1;

}

*/
