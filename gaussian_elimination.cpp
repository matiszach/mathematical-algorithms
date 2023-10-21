#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
#define pb push_back

// margin to avoid round errors when comparing to 0
ld margin = 1e-6;

// check if two numbers are equal with margin error
bool equals(ld x, ld y)
{
    return abs(x - y) <= margin;
}

// round to zero if number is less than margin
ld round_to_zero(ld x)
{
    return (abs(x) <= margin ? (ld)0 : x);
}

// solve the system of eqautions
void solve()
{
    // read input
    int n;
    cin >> n;
    vector<vector<ld>> M(n + 1, vector<ld>(n + 2));
    vector<vector<ld>> M2(n + 1, vector<ld>(n + 2));
    vector<vector<pair<int, ld>>> vars(n + 1, vector<pair<int, ld>>());
    vector<ld> vals(n + 2);
    vector<bool> R(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
            cin >> M[i][j];
    }

    // echelon form under the diagonal
    for (int i = 1; i <= n; ++i)
    {
        int idx = i;
        while (equals(M[idx][i], (ld)0) && idx < n)
            ++idx;
        for (int j = idx + 1; j <= n; ++j)
        {
            if (equals(M[j][i], (ld)0))
                continue;
            ld q = M[j][i] / M[idx][i];
            for (int k = 1; k <= n + 1; ++k)
            {
                M[j][k] = round_to_zero(M[j][k] - M[idx][k] * q);
            }
        }
    }

    // sorting equations in order of echelon form "stairs"
    vector<pii> vec;
    for (int i = 1; i <= n; ++i)
    {
        int len = 0;
        for (int j = 1; j <= n + 1; ++j)
        {
            if (!equals(M[i][j], (ld)0))
                break;
            ++len;
        }
        vec.pb({len, i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
        {
            M2[i][j] = M[vec[i - 1].second][j];
        }
    }

    // echelon form above the diagonal
    for (int i = n; i >= 1; --i)
    {
        int idx = n;
        while (equals(M2[idx][i], (ld)0) && idx > 1)
            --idx;
        for (int j = idx - 1; j >= 1; --j)
        {
            if (equals(M2[j][i], (ld)0))
                continue;
            ld q = M2[j][i] / M2[idx][i];
            for (int k = 1; k <= n + 1; ++k)
            {
                M2[j][k] = round_to_zero(M2[j][k] - M2[idx][k] * q);
            }
        }
    }

    // output echelon form of the matrix
    cout << "\n------------\n\n";
    cout << "Echelon form: \n\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
            cout << M2[i][j] << " ";
        cout << "\n";
    }

    // solving for x1, x2, ... , xn
    bool labeled = 1;
    for (int i = n; i >= 1; --i)
    {
        ld res = M2[i][n + 1];
        for (int j = i + 1; j <= n; ++j)
        {
            if (equals(M2[i][j], (ld)0))
                continue;
            if (R[j])
                vars[i].pb({j, M2[i][j]});
            else
                res = round_to_zero(res - vals[j] * M2[i][j]);
        }
        if (equals(M2[i][i], (ld)0))
        {
            if (equals(res, (ld)0))
            {
                R[i] = 1;
                labeled = 0;
            }
            else
            {
                cout << "The system of equations is indeterminate\n";
                return;
            }
        }
        else if (equals(res, (ld)0))
        {
            R[i] = 1;
            labeled = 0;
        }
        else
        {
            vals[i] = res / M2[i][i];
        }
    }

    // output solutions
    cout << "\n------------\n";
    cout << "\nSolutions: \n\n";
    if (labeled)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << "x" << i << " = " << vals[i] << "\n";
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (R[i])
                cout << "x" << i << " is any real number";
            else
            {
                cout << "x" << i << " = " << vals[i];
                for (pair<int, ld> p : vars[i])
                {
                    ld factor = p.second / M2[i][i];
                    if (factor > 0)
                        cout << " - ";
                    else
                    {
                        cout << " + ";
                        factor = -factor;
                    }
                    cout << factor << " * x" << p.first;
                }
            }
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    solve();
}
