/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    vector<int> result;
    result.push_back(1);
    
    for(int i = 2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < (int)result.size(); j++){
            int prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
        while(carry){
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    for(int i = (int)result.size() - 1; i >= 0; i--){
        cout << result[i];
    }
    cout << "\n";
}