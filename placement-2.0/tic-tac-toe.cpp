#include <bits/stdc++.h>
using namespace std;

string tictactoe(vector<vector<int>> & moves) {
    int arr[3][3];
    for(int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            arr[i][j] = -1;
        }
    }

    bool chance = false;

    for (auto x : moves) {
        cout << x[0] << " " << x[1] << endl;
        if (!chance) {
            arr[x[0]][x[1]] = 0;
        } else {
            arr[x[0]][x[1]] = 1;
        }

        chance = !chance;
        //now check winner

        for (int i = 0; i < 3; i += 1) {
            if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
                if (arr[i][0] == 0) {
                    return "A";
                } else if (arr[i][0] == 1){
                    return "B";
                }
            }

            if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
                if (arr[0][i] == 0) {
                    return "A";
                } else if (arr[0][i] == 1) {
                    return "B";
                }
            }
        }

        //check for diagonals
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
                if (arr[0][0] == 0) {
                    return "A";
                } else if (arr[0][0] == 1) {
                    return "B";
                }
        }

        if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
                if (arr[0][2] == 0) {
                    return "A";
                } else if (arr[0][2] == 1) {
                    return "B";
                }
        }

        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 3; j += 1) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (moves.size() < 9) {
        return "Pending";
    }
    return "Draw";
}

int main() {
    vector<vector<int> > arr = {{0,0}, {1,1}, {0,1}, {0,2}, {1,0}, {2,0}};
    cout << arr.size() << endl;
    cout << tictactoe(arr);
}
