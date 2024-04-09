#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;


void CodeSnippetManager::listSnippets()
    {

        if (snippets.empty())
        {

            cout << BOLD_RED << "No Snippets available!.file is Empty" << RESET << endl;
        }
        else

        {

            cout << endl;
             cout  << MAGENTA << "Available snippets are:" << RESET << endl;

            int snippetnum= 1;

            for (auto it = snippets.begin(); it != snippets.end(); ++it)
            {

                cout << BOLD_YELLOW << snippetnum << RESET << "->  " << BOLD_CYAN << it->first << RESET << endl;

                snippetnum++;
            }
        }
    }