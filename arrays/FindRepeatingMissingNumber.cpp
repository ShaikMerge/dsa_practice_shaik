//
// Created by shaja on 15-09-2026.
//

#include "FindRepeatingMissingNumber.h"


#include <bits/stdc++.h>
using namespace std;


vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
     vector<int> ans;
     set<int> st;
    int actual_sum = 0;
    int n = grid.size();
    int a = 0,b = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            actual_sum += grid[i][j];
            if (st.find(grid[i][j]) != st.end()) a = grid[i][j];  //repeating number
            st.insert(grid[i][j]);
         }
    }
    // (n ^ 2 ) (n ^ 2  + 1 ) / 2
    int expected_sum = ((n * n) * (n * n  + 1) )/ 2 ;
    // expected_sum + a - b = actual_sum   - >  b =expected_sum + a - actual_sum
    b = expected_sum + a - actual_sum;
    return vector<int>{a,b};
}
int  main() {


    vector<vector<int>> grid{{9,1,7} , {8,9,2} , {3,4,6}};
    vector<int> ans  = findMissingAndRepeatedValues(grid);
    for(int i=0;i<ans.size();i++) { cout<<ans[i]<<" "; }

}
