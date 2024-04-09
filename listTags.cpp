#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

void CodeSnippetManager::listTags()
    {
        int tagnum = 1;
        cout << endl<< MAGENTA << "Available snippets TAGs are:" << RESET << endl;
        for (auto it = snippets.begin(); it != snippets.end(); ++it)
        {
         cout << BOLD_YELLOW << tagnum  << RESET << "-> " << BOLD_CYAN << it->second.second << RESET << endl;
            tagnum++;
        }
    }