// Done using concept of linear equations in two variables

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> sol(2, 0);
    long oriSum = (A.size() * (A.size() + 1)) / 2;
    long oriSqSum = (A.size() * (2 * A.size() + 1) * (A.size() + 1)) / 6;
    
    
    for (int i = 0; i < A.size(); i++) {
        oriSum -= (long)A[i];
        oriSqSum -= (long)A[i]*(long)A[i];
    }
    
    sol[1] = (oriSum + oriSqSum/oriSum) / 2;
    sol[0] = sol[1] - oriSum;
    
    return sol;
}
