#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        if (height == 0)
            return 0;
        int width = grid[0].size();

        for (int i=width-2;i>=0;--i){
            grid[height-1][i] += grid[height-1][i+1];
        }

        for (int j=height-2;j>=0;--j){
            grid[j][width-1] += grid[j+1][width-1];
        }

        for (int i=height-2;i>=0;--i){
            for (int j=width-2;j>=0;--j){
                int left = grid[i][j+1];
                int down = grid[i+1][j];
                grid[i][j] += left > down ? down : left;
            }
        }

        // for (int i=0;i<grid.size();++i){
        //     for (int j=0;j<grid.size();++j){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return grid[0][0];
    }
};