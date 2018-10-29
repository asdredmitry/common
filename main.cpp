#include <iostream>
#include <deque>
#include <utility>
#include <limits.h>
using namespace std;
const int max1 = 1200;
const int inf = INT_MAX;
void bfs(char ** graph, bool ** used, char ** from, int ** weight, int n, int m)
{
    deque < pair<int, int> > d;
    d.push_back(make_pair(n - 1, m - 1));
    used[n - 1][m - 1] = true;
    from[n - 1][m - 1] = 'r';
    weight[n - 1][m - 1] = 0;
    while (!d.empty())
    {
        cout << d.size() << " " << endl;
        pair <int, int> cur = d.front();
        d.pop_front();
        cout << cur.first << " cur  " << cur.second << endl;
        if (graph[cur.first][cur.second] == '.')
        {
            int addFirst = 0;
            int addSecond = 0;
            //cout << " I am here" << endl;
            if (from[cur.first][cur.second] == 'r')
                addSecond = -1;
            else if (from[cur.first][cur.second] == 'l')
                addSecond = 1;
            else if (from[cur.first][cur.second] == 'd')
                addFirst = -1;
            else if (from[cur.first][cur.second] == 'u')
                addFirst = 1;
            cout << cur.first + addFirst << " " << cur.second + addSecond << endl;
            if (cur.first + addFirst < n && cur.first + addFirst >= 0 && cur.second + addSecond < m && cur.second + addSecond >= 0 && !used[cur.first + addFirst][cur.second + addSecond])
            {
                cout << " I am and here too" << endl;
                d.push_front(make_pair(cur.first + addFirst, cur.second + addSecond));
                used[cur.first + addFirst][cur.second + addSecond] = true;
                weight[cur.first + addFirst][cur.second + addSecond] = weight[cur.first][cur.second];
                from[cur.first + addFirst][cur.second + addSecond] = from[cur.first][cur.second];
            }
        }
        else
        {
            int addFirst = 0;
            int addSecond = 0;
            int addFirst1 = 0;
            int addSecond1 = 0;
            int addFirst2 = 0;
            int addSecond2 = 0;
            char fr1, fr2;
            if (from[cur.first][cur.second] == 'r')
            {
                addSecond = -1;
                addFirst1 = 1;
                addFirst2 = -1;
                fr1 = 'u';
                fr2 = 'd';
            }
            else if (from[cur.first][cur.second] == 'l')
            {
                addSecond = 1;
                addFirst1 = 1;
                addFirst2 = -1;
                fr1 = 'u';
                fr2 = 'd';

            }
            else if (from[cur.first][cur.second] == 'd')
            {
                addFirst = -1;
                addSecond1 = 1;
                addSecond2 = -1;
                fr1 = 'l';
                fr2 = 'r';
            }
            else if (from[cur.first][cur.second] == 'u')
            {
                addFirst = 1;
                addSecond1 = 1;
                addSecond2 = -1;
                fr1 = 'l';
                fr2 = 'r';
            }
            if (cur.first + addFirst >= 0 && cur.first + addFirst < n && cur.second + addSecond >= 0 && cur.second + addSecond < m && !used[cur.first + addFirst][cur.second + addSecond])
            {
                d.push_front(make_pair(cur.first + addFirst, cur.second + addSecond));
                used[cur.first + addFirst][cur.second + addSecond] = true;
                weight[cur.first + addFirst][cur.second + addSecond] = weight[cur.first][cur.second];
                from[cur.first + addFirst][cur.second + addSecond] = from[cur.first][cur.second];
            }
            if (cur.first + addFirst1 >= 0 && cur.first + addFirst1 < n && cur.second + addSecond1 >= 0 && cur.second + addSecond1 < m && !used[cur.first + addFirst1][cur.second + addSecond1])
            {
                d.push_back(make_pair(cur.first + addFirst1, cur.second + addSecond1));
                used[cur.first + addFirst1][cur.second + addSecond1] = true;
                weight[cur.first + addFirst1][cur.second + addSecond1] = weight[cur.first][cur.second] + 1;
                from[cur.first + addFirst1][cur.second + addSecond1] = fr1;
            }
            if (cur.first + addFirst2 >= 0 && cur.first + addFirst2 < n && cur.first + addSecond2 >= 0 && cur.first + addSecond2 < m && !used[cur.first + addFirst2][cur.second + addSecond2])
            {
                d.push_back(make_pair(cur.first + addFirst2, cur.second + addSecond2));
                used[cur.first + addFirst2][cur.second + addSecond2] = true;
                weight[cur.first + addFirst2][cur.second + addSecond2] = weight[cur.first][cur.second];
                from[cur.first + addFirst2][cur.second + addSecond2] = fr2;
            }
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    char ** graph = new char *[max1];
    bool ** used = new bool *[max1];
    char ** from = new char *[max1];
    int ** weight = new int *[max1];
    for(int i = 0; i < max1; i++)
    {
        graph[i] = new char[max1];
        used[i] = new bool[max1];
        from[i] = new char[max1];
        weight[i] = new int[max1];
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            used[i][j] = false;
            from[i][j] = 'n';
            weight[i][j] = inf;
        }
    }
    bfs(graph, used, from, weight, n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << weight[i][j] << " ";
        cout << endl;
    }

}
