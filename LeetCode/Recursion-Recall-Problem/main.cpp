#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution17 {
    //17. Letter Combinations of a Phone Number
    //3^n=O(2^n)
    //数据规模最大n=20
private:
    vector<string> res;
    const string letterMap[10] = {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };

    //s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    //寻找和digits[index]匹配的字母。获得digits[0...index]翻译得到的解
    void findCombination(const string &digits, int index, const string &s) {
        cout << index << ":" << s << endl;

        if (index == digits.size()) {
            //保存s
            res.push_back(s);
            cout << "get " << s << ",return" << endl;
            return;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            cout << "digits[" << index << "]=" << c << ",use " << letters[i] << endl;
            findCombination(digits, index + 1, s + letters[i]);
        }
        cout << "digits[" << index << "]=" << c << " complete,return" << endl;
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits == "") {
            return res;
        }
        findCombination(digits, 0, "");
        return res;
    }
};

class Solution46 {
    //46. Permutations
private:
    vector<vector<int>> res;
    vector<bool> used;

    //p中保存了一个有index个元素的排列
    //向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermutation(const vector<int> &nums, int index, vector<int> &p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                //将nums[i]添加在p中
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        res.clear();
        if (nums.size() == 0) {
            return res;
        }
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }
};

class Solution77 {
    //77. Combinations
private:
    vector<vector<int>> res;

    //求解C(n,k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int> &c) {
        if (c.size() == k) {
            res.push_back(c);
            return;
        }

        //优化剪枝
        //分析：还有k-c.size()个空位，所以[i...n]中至少要有k-c.size()个元素，i最多为n-(k-c.size())+1
        for (int i = start; i <= n - (k - c.size()) + 1; i++) {
            c.push_back(i);
            generateCombinations(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        if (n <= 0 || k <= 0 || k > n) {
            return res;
        }
        vector<int> c;
        generateCombinations(n, k, 1, c);
        return res;
    }
};

class Solution79 {
    //79. Word Search
private:
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    //board[startx][starty]开始，寻找word[index...word.size()]
    bool searchWord(const vector<vector<char>> &board, string &word, int index, int startx, int starty) {
        if (index == word.size() - 1) {
            return word[index] == board[startx][starty];
        }
        if (word[index] == board[startx][starty]) {
            visited[startx][starty] = true;
            //从startx，starty出发，向四个方向寻扎
            for (int i = 0; i < 4; i++) {
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if (inArea(newx, newy) && !visited[newx][newy])
                    if (searchWord(board, word, index + 1, newx, newy)) {
                        return true;
                    }
            }
            visited[startx][starty] = false;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution200 {
    //200. Number of Islands
private:
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    //从grid[x][y]的位置开始进行floodfill
    //保证（x,y）合法，且grid[x][y]是没有被访问过的
    void dfs(vector<vector<char>> &grid, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
                dfs(grid, newx, newy);
            }
        }
        return;
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        if (m == 0) {
            return 0;
        }
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

class Solution51 {
    //51. N-Queens
private:
    vector<vector<string>> res;
    vector<bool> col, dia1, dia2;

    //尝试在一个n皇后问题中，摆放第index行的皇后位置
    void putQueue(int n, int index, vector<int> &row) {
        if (n == index) {
            res.push_back(generateBoard(n, row));
            return;
        }
        for (int i = 0; i < n; i++) {
            //尝试将第index行的皇后摆放在第i列
            if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                row.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                putQueue(n, index + 1, row);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        }
        return;
    }

    vector<string> generateBoard(int n, vector<int> &row) {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][row[i]] = 'Q';
        }
        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);
        vector<int> row;
        putQueue(n, 0, row);
        return res;
    }
};

int main() {
    //17
//    vector<string> res = Solution17().letterCombinations("234");
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << endl;
//    }


    //51
//    int n = 4;
//    vector<vector<string>> res = Solution51().solveNQueens(n);
//    for (int i = 0; i < res.size(); i++) {
//        for (int j = 0; j < n; j++) {
//            cout << res[i][j] << endl;
//        }
//        cout << endl;
//    }
    return 0;
}

/*
 * 递归与回溯
 * 1.树形问题
 * 回溯：暴力法的主要手段
 * 17
 * 93
 * 131
 *
 * 2.排列
 * 46
 * 47
 *
 * 3.组合
 * 优化：回溯法进行剪枝
 * 77
 * 39
 * 40
 * 216
 * 78
 * 90
 * 401
 *
 * 4.二维平面回溯
 * 79
 *
 * - floodfill
 * 200
 * 130
 * 417
 *
 * 5.经典AI-递归回溯
 * 51
 * 52
 * 37求解数独
 * */