#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

void CodeSnippetManager::searchByTag(string tag)
{
    vector<string> Match;

    for (auto it = snippets.begin(); it != snippets.end(); ++it)
    {
        if (it->second.second.find(tag) != string::npos)
        {
            Match.push_back(it->first);
        }
    }
    if (Match.empty())
    {
        cout << endl
             << BOLD_RED << "No snippets found with tag '" << RESET << BOLD_BLUE << tag << RESET << "'" << endl;
    }
    else
    {
        cout << endl
             << "Snippets with tag '" << BOLD_BLUE << tag << RESET << "':" << endl;
        for (auto snippetIt = Match.begin(); snippetIt != Match.end(); ++snippetIt)
        {
            cout << "- " << BOLD_BLUE << *snippetIt << RESET << endl;
        }
    }
}