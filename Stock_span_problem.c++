class solution
{
  public:
    vector<int> calculateSpan(vector<int>&arr)
      {
            int n = arr.size();
            vector<int> ans(n, 1);
            stack<pair<int, int>> st;  // Stack to store {price, index}
  
            for (int i = 0; i < n; i++) {
              // Pop elements from stack while the current price is greater or equal
              while (!st.empty() && arr[i] >= st.top().first) {
                  st.pop();
              }
  
          // Compute the span
              ans[i] = (st.empty()) ? (i + 1) : (i - st.top().second);
  
          // Push current price and index onto stack
              st.push({arr[i], i});
            }
      
            return ans;
      }
}
  
