#include <cmath>
#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> board;
std::vector<std::vector<int>> steps{
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},  // Ma tran cac cach di chuyen cua ma
    {1, -2},  {1, 2},  {2, -1},  {2, 1}};

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 0;
}
void backTrack(int x, int y, int step) {
    board[x][y] = step;
    if (step == n * m) {  // Neu di het cac o, in ra ket qua
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        exit(0);
    }
    for (auto move : steps) {
        int xNext = x + move[0];  // Chi so x tiep theo
        int yNext = y + move[1];  // Chi so y tiep theo
        if (isValid(xNext, yNext)) {
            backTrack(xNext, yNext, step + 1);
        }
    }
    board[x][y] = 0;  // Quay lui
}
int main() {
    std::cin >> n >> m;
    board.resize(n, std::vector<int>(m, 0));
    backTrack(0, 0, 1);
}