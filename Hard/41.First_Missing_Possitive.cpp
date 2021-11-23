class Solution {
   public:
    int firstMissingPositive(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i)
            while (A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);

        for (auto x : A) cout << x << " ";

        for (int i = 0; i < A.size(); ++i)
            if (A[i] != i + 1) return i + 1;

        return A.size() + 1;
    }
};