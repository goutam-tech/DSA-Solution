class Solution
{
public:
    bool canRepresentBST(vector<int> &arr)
    {
        stack<int> st;
        int lowerBound = INT_MIN;

        for (int val : arr)
        {
            if (val < lowerBound)
                return false;

            while (!st.empty() && st.top() < val)
            {
                lowerBound = st.top();
                st.pop();
            }

            st.push(val);
        }

        return true;
    }
};