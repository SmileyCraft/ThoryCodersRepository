
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
