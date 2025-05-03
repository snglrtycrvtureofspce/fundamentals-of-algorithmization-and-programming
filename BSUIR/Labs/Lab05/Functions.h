#pragma once
#include <stack>

int64_t ackermann_recursive(int64_t m, int64_t n, int& depth, int current_depth = 0) {
    if (current_depth > depth)
        depth = current_depth;
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ackermann_recursive(m - 1, 1, depth, current_depth + 1);

    return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1, depth, current_depth + 1), depth, current_depth + 1);
}

int64_t ackermann_iterative(int64_t m, int64_t n) {
    std::stack<int64_t> s;
    s.push(m);
    while (!s.empty()) {
        m = s.top();
        s.pop();

        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            n = 1;
            s.push(m - 1);
        }
        else {
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }

    return n;
}