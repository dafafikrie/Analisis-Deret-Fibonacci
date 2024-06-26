#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long fibonacci_dp(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

void measure_execution_time(int n) {
    auto start = high_resolution_clock::now();
    fibonacci_recursive(n);
    auto end = high_resolution_clock::now();
    auto duration_recursive = duration_cast<microseconds>(end - start).count();
    
    start = high_resolution_clock::now();
    fibonacci_dp(n);
    end = high_resolution_clock::now();
    auto duration_dp = duration_cast<microseconds>(end - start).count();
    
    cout << "n = " << n << "\n";
    cout << "Recursive: " << duration_recursive << " microseconds\n";
    cout << "Dynamic Programming: " << duration_dp << " microseconds\n";
    cout << "----------------------\n";
}

int main() {
    int test_cases[] = {10, 25, 30, 40, 50};
    for (int n : test_cases) {
        measure_execution_time(n);
    }
    return 0;
}

