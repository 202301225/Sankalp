#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

void CodeSnippetManager::removeSnippet(string Snippet_name)
    {
        auto it = snippets.find(Snippet_name);
        if (it != snippets.end())
        {
            snippets.erase(it);
            saveSnippets();
            cout << endl << "Snippet '" << BOLD_BLUE << Snippet_name << RESET << "'" << BOLD_GREEN << " removed successfully" << RESET << endl;
        }
        else
        {
            cout << endl << "For Removing Snippet '" << BOLD_BLUE << Snippet_name << RESET << "'" << BOLD_RED << " not found" << RESET << endl;
        }
    }