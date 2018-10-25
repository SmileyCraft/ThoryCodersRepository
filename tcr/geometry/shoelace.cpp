
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
