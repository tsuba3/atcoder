#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <string>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>

using namespace std;

int main() {
    char track, direction;
    int station, hour;
    string _station;
    cin >> track >> _station >> direction >> hour;

    if (track == 'B' && _station == "A7") {
        station = 6; // B 路線の A7 駅はB6とする。
    } else {
        station = atoi(_station.substr(1).c_str());
    }

    int da[] = {3, 5, 2, 3, 4, 3, 4, 2, 2, 3, 6, 2};
    int db[] = {4, 3, 3, 2, 3};

    vector<int> all_time;
    if (track == 'A' && direction == 'U') {
        if (1 <= station && station <= 6) {
            // A1 -> A7
            int dt = 0;
            for (int i = 0; i < station - 1; ++i) dt += da[i];
            for (int i = 0; i < 103; ++i) all_time.push_back(10 * i + 55 + dt);
        } else {
            // A7 -> A13
            int dt = 0;
            for (int si = 8; si <= station; ++si) dt += da[si - 1];
            all_time.push_back(70 + dt);
        }
        // A1 -> A13
        int dt = 0;
        for (int i = 0; i < station - 1; ++i) dt += da[i];
        for (int i = 0; i < 102; ++i) all_time.push_back(10 * i + 60 + dt);
    } else if (track == 'A' && direction == 'D') {
        int dt = 0;
        for (int si = 13; si > station; --si) dt += da[si - 2];
        // A13 -> A1
        for (int i = 0; i < 103; ++i) all_time.push_back(10 * i + 52 + dt);
        if (1 <= station && station <= 7) {
            int dt = 0;
            for (int si = 7; si > station; --si) dt += da[si - 2];
            for (int i = 0; i < 103; ++i) all_time.push_back(10 * i + 66 + dt);
        }
    } else if (track == 'B' && direction == 'U') {
        int dt = 0;
        for (int i = 0; i < station - 1; ++i) dt += db[i];
        for (int i = 0; i < 170; ++i) all_time.push_back(6 * i + 60 + dt);
    } else { // track == 'B' && direction == 'D'
        int dt = 0;
        for (int si = 6; si > station; si--) dt += db[si - 2];
        for (int i = 0; i < 170; ++i) all_time.push_back(6 * i + 71 + dt);
    }

    vector<int> ans;
    for (int i = 0; i < all_time.size(); ++i) {
        int minute = all_time[i] - (hour - 5) * 60;
        if (0 <= minute && minute < 60) ans.push_back(minute);
    }
    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << "No train\n";
    } else {
        cout << setfill('0') << setw(2) << hour << ": ";
        for (int i = 0; i < ans.size() - 1; ++i) cout << setfill('0') << setw(2) << ans[i] << ' ';
        cout << setfill('0') << setw(2) << ans[ans.size() - 1] << '\n';
    }

    return 0;
}
