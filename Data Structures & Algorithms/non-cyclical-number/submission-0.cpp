class Solution {
public:

    int sqrd(int n) {
        int sum = 0;

        while (n > 0) {
            int rem = n % 10;
            sum += rem * rem;
            n = n / 10;
        }

        return sum;
    }

    bool solve(int n, set<int>& st) {

        if (n == 1) {
            return true;
        }
        if (st.find(n) != st.end()) {
            return false;
        }

        st.insert(n);

        return solve(sqrd(n), st);
    }

    bool isHappy(int n) {

        set<int> st;

        return solve(n, st);
    }
};