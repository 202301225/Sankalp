#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;


void CodeSnippetManager::addSnippet( string snippetname,  string codeSnippet,string tagOfSnippet)
    {
        snippets[snippetname] = make_pair(codeSnippet, tagOfSnippet);
        saveSnippets();

        cout << endl
             << BOLD_GREEN << "Snippet  '" << BOLD_BLUE << snippetname << RESET << BOLD_GREEN << "' added successfully.\n"
             << RESET;
    }