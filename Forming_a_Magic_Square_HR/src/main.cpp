#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(std::vector<std::vector<int> > s) {
    std::vector < std::vector<vector<int> > > p_s = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}, {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};
    int res = INT_MAX;
    for (int x = 0; x < p_s.size(); ++x) {
        int coast = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j){
                coast += abs(p_s.at(x)[i][j] - s[i][j]);
            }
        }
        if(coast < res)
            res = coast;
    }
    return res;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    std::vector<std::vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    std::cout << result << "\n";
    //fout << result << "\n";

    //fout.close();

    return 0;
}
