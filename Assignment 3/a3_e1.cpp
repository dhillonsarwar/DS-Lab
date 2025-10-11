vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> result;
    Stack st;

    for (int i = 0; i < A.size(); i++) {
        
        while (!st.empty() && st.top() >= A[i])
            st.pop();

      
        if (st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top());

        
        st.push(A[i]);
    }

    return result;
}
