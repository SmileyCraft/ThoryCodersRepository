
pair<point, NUMBER> shoelace(vector<point>& polygon){ // O(n)
    int n = polygon.size();
    NUMBER total = polygon[n - 1].x * polygon[0].y - polygon[0].x * polygon[n - 1].y;
    point weightedSum = total * (polygon[n - 1] + polygon[0]);
    for (int i = 0; i < n - 1; i++){
        NUMBER area = polygon[i].x * polygon[i + 1].y - polygon[i + 1].x * polygon[i].y;
        total += area;
        weightedSum += area * (polygon[i] + polygon[i + 1]);
    }
    return pair<point, NUMBER>(weightedSum / (total * 3), total / 2);
}

// TESTING

void testShoelace(){
    cout << "SHOELACE" << endl;
    vector<point> polygon = {{1,1},{2,1},{1,3}};
    cout << shoelace(polygon) << endl; // {(1.333 1.667) 1}
    polygon = {{0,0},{7,5},{1,4},{6,9},{-2,9},{3,8},{-2,3},{1,-3}};
    cout << shoelace(polygon) << endl; // {(1.774 4.369) 32.5}
    cout << endl;
}
