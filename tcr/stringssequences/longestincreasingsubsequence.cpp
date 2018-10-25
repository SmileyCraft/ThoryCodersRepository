
template <class T, class F>
vector<int> longestIncreasingSubsequence(vector<T> sequence, F f){
    vector<int> prev(sequence.size()), best;
    for (int i = 0; i < sequence.size(); i++){
        int mini = 0, maxi = best.size();
        while (mini < maxi){
            int mid = (mini + maxi) >> 1;
            if (sequence[i] < sequence[best[mid]]) maxi = mid;
            else mini = mid + 1;
        }
        if (mini == best.size()) best.push_back(i);
        else best[mini] = i;
        if (mini == 0) prev[i] = -1;
        else prev[i] = best[mini - 1];
    }
    vector<int> lis(best.size());
    for (int i = lis.size() - 1, j = best.back(); i >= 0; i--){
        lis[i] = j;
        j = prev[j];
    }
    return lis;
}

// TESTING

void testLongestIncreasingSubsequence(){
    cout << "LONGEST INCREASING SUBSEQUENCE" << endl;
    auto compare = [](int a, int b){return a < b;};
    cout << longestIncreasingSubsequence(vector<int>{7, 8, 9, 4, 5, 6, 1, 2, 3}, compare) << endl; // {6 7 8}
    cout << longestIncreasingSubsequence(vector<int>{3, 2, 1, 6, 5, 4, 9, 8, 7}, compare) << endl; // {2 5 8}
    cout << longestIncreasingSubsequence(vector<int>{7, 2, 4, 9, 1, 6, 8, 3, 5}, compare) << endl; // {1 2 5 6}
    cout << endl;
}
