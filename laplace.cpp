#include <bits/stdc++.h>
using namespace std;

//-1 to the n-th power
int power(int n)
{
    return n % 2 ? -1 : 1;
}

// laplace expansion
int laplace(vector<vector<int>> &mat, int size)
{
    if (size == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    int value = 0;
    for (int i = 0; i < size; ++i)
    {
        vector<vector<int>> nmat;
        for (int n = 1; n < size; ++n)
        {
            vector<int> temp;
            for (int m = 0; m < size; ++m)
            {
                if (m != i)
                    temp.push_back(mat[n][m]);
            }
            nmat.push_back(temp);
        }
        value += mat[0][i] * power(i) * laplace(nmat, size - 1);
    }
    return value;
}

// read input and print output for a given matrix
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    }
    cout << laplace(arr, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    solve();
}
