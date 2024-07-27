class Solution {
public:
    string countOfAtoms(string f) {
        int n = f.size();
        vector<int> v(n, 1); // Initialize with 1 to handle default cases
        stack<int> st;
        int i = 0;

        while (i < n) {
            if ('A' <= f[i] && f[i] <= 'Z') {
                int index = i;
                if (i < n - 1 && 'a' <= f[i + 1] && f[i + 1] <= 'z') {
                    i++;
                }
                i++;

                string temp;
                while (i < n && isdigit(f[i])) {
                    temp += f[i];
                    i++;
                }
                //  cout<<index<<" ol "<< temp<<endl;

                v[index] = temp.empty() ? 1 : stoi(temp);

            //  cout<<v[index]<<" --";
            } else if (f[i] == '(') {
                st.push(i);
                i++;
            } else if (f[i] == ')') {
                int prev = st.top();
                st.pop();
                i++;
                string temp;

                while (i < n && isdigit(f[i])) {
                    temp += f[i];
                    i++;
                }

                int mult = temp.empty() ? 1 : stoi(temp);

                for (int j = prev + 1; j < i - 1; j++) {
                    if (v[j] != 0) {
                        v[j] *= mult;
                    }
                }
            } else {
                i++;
            }
        }

        // v[index]=soti(temp);

        map<string, int> mp;
        

        for (int i = 0; i < n; i++) {
            if ('A' <= f[i] && f[i] <= 'Z') {
                string add;
                add += f[i];
                
                int valu=v[i];
                
                if (i < n - 1 && 'a' <= f[i + 1] && f[i + 1] <= 'z') {
                    add += f[i + 1];
                    i++;
                }
                mp[add] += valu;
                //  cout<<add<<" 00 "<<v[i]<<endl;
            }
        }

        string ans;

        for (auto it : mp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }

        return ans;
    }
};
