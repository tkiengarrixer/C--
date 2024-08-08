#include <bitset>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_D = 10;  // Maximum number of digits (buttons)

int bitsetToInt(const bitset<MAX_D>& bs) { return (int)(bs.to_ulong()); }

// Function to check if a given bitmask of button presses covers all passwords
bool coversAll(const vector<bitset<MAX_D>>& passwords,
               const bitset<MAX_D>& presses) {
    for (const auto& pw : passwords) {
        if ((pw & presses) != pw) {
            return false;
        }
    }
    return true;
}

// Function to compute the minimum number of steps to cover all passwords
int minSteps(int D, const vector<bitset<MAX_D>>& passwords) {
    int N = passwords.size();
    int fullMask = (1 << D) - 1;
    vector<int> minStepsToCover(1 << D, INT_MAX);
    queue<pair<bitset<MAX_D>, int>> q;

    // Start with the initial state (no buttons pressed, 0 steps)
    bitset<MAX_D> initial;
    q.push({initial, 0});
    minStepsToCover[bitsetToInt(initial)] = 0;

    while (!q.empty()) {
        auto [currentPresses, steps] = q.front();
        q.pop();

        // Try pressing each button and checking the result
        for (int i = 0; i < D; ++i) {
            bitset<MAX_D> nextPresses = currentPresses;
            nextPresses.set(i);

            if (coversAll(passwords, nextPresses)) {
                // All passwords covered
                return steps + 1;
            }

            int nextPressesInt = bitsetToInt(nextPresses);
            if (minStepsToCover[nextPressesInt] > steps + 1) {
                minStepsToCover[nextPressesInt] = steps + 1;
                q.push({nextPresses, steps + 1});
            }
        }

        // Consider the RESET button
        bitset<MAX_D> resetPresses;
        if (coversAll(passwords, resetPresses)) {
            // All passwords covered by RESET
            return steps + 1;
        }

        int resetPressesInt = bitsetToInt(resetPresses);
        if (minStepsToCover[resetPressesInt] > steps + 1) {
            minStepsToCover[resetPressesInt] = steps + 1;
            q.push({resetPresses, steps + 1});
        }
    }

    return -1;  // Should not reach here if constraints are met
}

int main() {
    int D, N;
    cin >> D >> N;
    vector<bitset<MAX_D>> passwords(N);

    for (int i = 0; i < N; ++i) {
        string password;
        cin >> password;
        bitset<MAX_D> bs;
        for (int j = 0; j < D; ++j) {
            if (password[j] == '1') {
                bs.set(j);
            }
        }
        passwords[i] = bs;
    }

    cout << minSteps(D, passwords) << endl;

    return 0;
}
