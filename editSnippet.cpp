#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;


void CodeSnippetManager::editSnippet(string Snippetname, string CodeOfSnippet, string SetOfTags)

    {

        snippets[Snippetname] = make_pair(CodeOfSnippet, SetOfTags);

        saveSnippets();

        cout << endl
             << "Snippet '" << BOLD_BLUE << Snippetname << RESET << "'" << BOLD_GREEN << " edited successfully" << RESET << endl;
    }