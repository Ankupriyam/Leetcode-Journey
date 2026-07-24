class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        unordered_set<int> st, s;
        int n = a.size();

        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                st.insert(a[i]^a[j]);
            }
        }

        for(auto num: st){
            for(auto x: a){               
                s.insert(num^x);
            }
        }
        return s.size();
    }
};class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        unordered_set<int> st, s;
        int n = a.size();

        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                st.insert(a[i]^a[j]);
            }
        }

        for(auto num: st){
            for(auto x: a){               
                s.insert(num^x);
            }
        }
        return s.size();
    }
};