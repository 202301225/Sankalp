#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

int CodeSnippetManager::closestSnippet( string s1,string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> vec(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; ++i)
        {
            vec[0][i] = i;
        }

        for (int j = 0; j <= len2; ++j)
        {
            vec[0][j] = j;
        }

        for (int i = 1; i <= len1; ++i)
        {

            for (int j = 1; j <= len2; ++j)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    vec[i][j] = vec[i - 1][j - 1];
                }
                else
                {
                    vec[i][j] = 1 + min({vec[i - 1][j], vec[i][j - 1], vec[i - 1][j - 1]});
                }
            }
        }

        return vec[len1][len2];
    }