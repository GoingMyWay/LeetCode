class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        for ( int i = 0; i < points.size(); i ++ ) {
            map<int, int> hashMap;
            for ( int m = 0; m < points.size(); m ++ ) {
                if ( i == m) { continue; }
                
                int dist = pow(points[i].first - points[m].first, 2) + pow(points[i].second - points[m].second, 2);
                map<int, int>::iterator iter = hashMap.find(dist);
                if ( iter == hashMap.end() ) {
                    hashMap.insert(pair<int, int>(dist, 1));
                } else {
                    hashMap[dist] += 1;
                }
            }
            map<int, int>::iterator iter = hashMap.begin();
            while( iter != hashMap.end() ) {
                result += iter->second * (iter->second - 1);
                iter++;
            }
            // map<int, int> swapMap;  
            // hashMap.swap(swapMap);  
            // hashMap.clear();
        }
        return result;
    }
};