#include<iostream>
#include<vector>

using namespace std;

int n, minn = 100000;
int stat[22][22];
bool checked[22];
vector<int> team_s, team_l;

void recur(int k)
{
    if(k == n/2) {
        team_l.clear();
        int stat_s=0, stat_l=0;
        for(int i=2; i<=n; i++) {
            if(!checked[i])
                team_l.push_back(i);
        }
        for(int i=0; i<team_s.size(); i++) {
            for(int j=0; j<team_s.size(); j++) {
                stat_s += stat[team_s[i]][team_s[j]];
                stat_l += stat[team_l[i]][team_l[j]];
            }
        }
        int diff = abs(stat_s - stat_l);
        minn = (diff < minn) ? diff : minn;
        return;
    }
    for(int i=2; i<=n; i++) {
        if(!checked[i] && team_s.back()<i) {
            team_s.push_back(i);
            checked[i] = true;

            recur(k+1);
            team_s.pop_back();
            checked[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> stat[i][j];
        }
    }
    team_s.push_back(1);
    recur(1);
    cout << minn;
}