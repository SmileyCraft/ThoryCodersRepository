double Shoelace(vector<double> vertX, vector<double> vertY){
    int n = vertX.size();
    double shoelace = vertX[n-1] * vertY[0] - vertX[0] * vertY[n-1];
    for (int i = 0; i < n - 1; i++)
        shoelace += vertX[i] * vertY[i+1] - vertX[i+1] * vertY[i];
    return 0.5 * shoelace;
}

void testShoelace(){
    vector<double> pollyX = {0,1,1,0};
    vector<double> pollyY = {0,0,1,1};
    cout << Shoelace(pollyX, pollyY) << endl; // 1
}
