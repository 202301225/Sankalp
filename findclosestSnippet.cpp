#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;


string CodeSnippetManager::findclosestSnippet( string input)
    {
        string str;

        int minDistance = numeric_limits<int>::max();

        for (auto it = snippets.begin(); it != snippets.end(); ++it)
        {
            int distance = closestSnippet(input, it->first);

            if (distance < minDistance)
            {
                minDistance = distance;
                str = it->first;
            }
        }

        return str;
    }