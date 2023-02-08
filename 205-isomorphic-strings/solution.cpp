class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sTotTable[256];
        int tTosTable[256];
        int size = s.length();
        for (int i = 0; i < 256; i++)
        {
            sTotTable[i] = 300;
            tTosTable[i] = 300;
        }

        for (int i = 0; i < size; i++)
        {
            if (sTotTable[s[i]] == 300)
            {
                if (tTosTable[t[i]] == 300)
                {
                    sTotTable[s[i]] = t[i];
                    tTosTable[t[i]] = s[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (sTotTable[s[i]] != t[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};