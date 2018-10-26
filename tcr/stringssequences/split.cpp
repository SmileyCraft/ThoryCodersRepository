
vector<string> split(string s, string del){
    vector<string> splits;
    string sub;
    for (int i = 0; true; i++){
        if (i > s.size() - del.size()){
            for (; i < s.size(); i++)
                sub += s[i];
            splits.push_back(sub);
            return splits;
        }
        if (s.substr(i, del.size()) == del){
            splits.push_back(sub);
            i += del.size() - 1;
            sub = "";
        }
        else
            sub += s[i];
    }
}
