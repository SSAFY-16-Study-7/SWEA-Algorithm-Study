#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MOD = 1'000'000'007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        string str;
        cin >> str;

        int days = str.length();

        vector<vector<long long>> dp(days, vector<long long>(16, 0));

        // 첫날
        int admin = str[0] - 'A';
        int adminBit = 1 << admin;
        int aBit = 1 << 0; // 첫날 A가 열쇠를 가지고 있음

        for (int mask = 1; mask < 16; mask++) {

            // 책임자가 참여하고
            // A도 참여해야 함
            if ((mask & adminBit) && (mask & aBit)) {
                dp[0][mask] = 1;
            }
        }

        // 2일차 이후
        for (int day = 1; day < days; day++) {

            int admin = str[day] - 'A';
            int adminBit = 1 << admin;

            for (int cur = 1; cur < 16; cur++) {

                // 오늘 책임자는 반드시 참여
                if (!(cur & adminBit))
                    continue;

                for (int prev = 1; prev < 16; prev++) {

                    // 어제와 오늘 참가자 중
                    // 최소 한 명은 겹쳐야 열쇠 전달 가능
                    if (prev & cur) {
                        dp[day][cur] += dp[day - 1][prev];
                        dp[day][cur] %= MOD;
                    }
                }
            }
        }

        long long ans = 0;

        for (int mask = 1; mask < 16; mask++) {
            ans += dp[days - 1][mask];
            ans %= MOD;
        }

        cout << "#" << tc << " " << ans << '\n';
    }

    return 0;
}
