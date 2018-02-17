#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    //17. Letter Combinations of a Phone Number
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits == "") {
            return res;
        }
        findCombination(digits, 0, "");
        return res;
    }

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
        if (index == digits.size()) {
            //保存s
            res.push_back(s);
            return;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            findCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }
};

int main() {
    return 0;
}

/*
 * 递归与回溯
 * 1.树形问题
 * 17
 * */