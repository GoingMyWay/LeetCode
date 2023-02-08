class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> hashMap;
        for ( int i = 0; i < list1.size(); i ++ ) {
            hashMap.insert(pair<string, int>(list1[i], i));
        }
        int best = 1e9, tmp = 0;
        vector<string> result;
        for ( int j = 0; j < list2.size(); j ++) {
            if ( 0 == hashMap.count(list2[j]) ) {
                tmp = 1e9;
            } else {
                tmp = hashMap[list2[j]];
            }
            if ( j + tmp < best ) {
                vector<string> res;
                res.push_back(list2[j]);
                result = res;
                best = j + tmp;
            } else if ( j + tmp == best ) {
                result.push_back(list2[j]);
            }
        }
        return result;
    }
};