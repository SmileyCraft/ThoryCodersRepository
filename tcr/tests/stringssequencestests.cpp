
#include "../stringssequences/stringmatching.cpp"
#include "../stringssequences/longestincreasingsubsequence.cpp"
#include "../stringssequences/longestcommonsubsequence.cpp"
#include "../stringssequences/split.cpp"

// STRING MATCHING

void testStringMatching(){
    cout << "STRING MATCHING" << endl;
    cout << automaton("abacabacabab") << endl; // {0 0 1 0 1 2 3 4 5 6 7 2}
    cout << automaton("abccabcabccaa") << endl; // {0 0 0 0 1 2 3 1 2 3 4 5 1}
    cout << automaton("ababacabababacabababababacaba") << endl; // {0 0 1 2 3 0 1 2 3 4 5 4 5 6 7 8 9 10 11 12 13 4 5 4 5 6 7 8 9}
    cout << automaton("anano@ananasbananos") << endl; // {0 0 1 2 0 0 1 2 3 4 3 0 0 1 2 3 4 5 0}
    cout << matchStrings("ananasbananos", "anano") << endl; // {1 2 3 4 3 0 0 1 2 3 4 5 0}
    cout << firstHashMatch("ananasbananos", "anano") << endl; // 7
    cout << firstHashMatch("hbakuvdsbfujgkhjuadbvliuaberukgalieugjdbvnjkaglvjhabkifvusdfkvbseruhkdfvbjsk", "vb") << endl; // 61
    cout << firstHashMatch("mjbhnhyuihgtyuhbvcdkljhgyhujkpojhgvfcdmnbgvfdfghjkjhgfdsdcfvgbhjko", "jyschfyusbhv") << endl; // -1
    cout << endl;
}

// LONGEST INCREASING SUBSEQUENCE

void testLongestIncreasingSubsequence(){
    cout << "LONGEST INCREASING SUBSEQUENCE" << endl;
    auto compare = [](int a, int b){return a < b;};
    cout << longestIncreasingSubsequence(vector<int>{7, 8, 9, 4, 5, 6, 1, 2, 3}, compare) << endl; // {6 7 8}
    cout << longestIncreasingSubsequence(vector<int>{3, 2, 1, 6, 5, 4, 9, 8, 7}, compare) << endl; // {2 5 8}
    cout << longestIncreasingSubsequence(vector<int>{7, 2, 4, 9, 1, 6, 8, 3, 5}, compare) << endl; // {1 2 5 6}
    cout << endl;
}

// LONGEST COMMON SUBSEQUENCE

void testLongestCommonSubsequence(){
    cout << "LONGEST COMMON SUBSEQUENCE" << endl;
    cout << longestCommonSubsequence(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}),
                                     vector<int>({4, 2, 6, 8, 1, 3, 9, 5, 7})) << endl;
                                     // {{0 4} {2 5} {4 7} {6 8}}
    cout << longestCommonSubsequence(vector<char>({'G', 'A', 'T', 'T', 'A', 'C', 'A'}),
                                     vector<char>({'G', 'T', 'A', 'A', 'T', 'C', 'T', 'A', 'A', 'C'})) << endl;
                                     // {{0 0} {1 3} {2 4} {3 6} {4 8} {5 9}}
    cout << endl;
}

// SPLIT

void testSplit(){
    cout << "SPLIT" << endl;
    cout << split("XDwowXDniceXDXx_420Blazit_xXXDDXXDyoloXDswagXD", "XD") << endl; // { wow nice Xx_420Blazit_xX DX yolo swag }
    cout << split("ababbabaaabababbbababbaaba", "bab") << endl; // {a  aaa abb abbaaba}
    cout << endl;
}

// COMBINED TEST

void testStringsSequences(){
    cout << "-----o-----o----- STRING AND SEQUENCE ALGORITHMS -----o-----o-----" << endl << endl;
    testStringMatching();
    testLongestIncreasingSubsequence();
    testLongestCommonSubsequence();
    testSplit();
}
