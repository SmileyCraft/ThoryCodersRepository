vector<string> split(string s, string del){
    vector<string> splits;
    string sub;
    for (int i = 0; i <= s.size() - del.size(); i++){
        if (s.substr(i, del.size()) == del){
            splits.push_back(sub);
            i += del.size() - 1;
            sub = "";
            if (i == s.size() - 1)
                splits.push_back("");
        }
        else
            sub += s[i];
    }
    return splits;
}
