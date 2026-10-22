class Solution {
private:
    vector<int> nsr(vector<int>& heights, int n) {

        vector<int> res(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            res[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return res;
    }
    vector<int> nsl(vector<int>& heights, int n) {

        vector<int> res(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = nsr(heights, n);
        vector<int> left = nsl(heights, n);

        int mx = 0;
        for(int i = 0; i < n; i++) {
            int area = (right[i]-left[i]-1) * heights[i];
            mx = max(mx,area);
        }

        return mx;
    }
};
