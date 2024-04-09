#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

void CodeSnippetManager::saveSnippets()
    {

        ofstream file(store_File);

        if (file.is_open())
        {

            for (auto it = snippets.begin(); it != snippets.end(); ++it)
            {
                file << "**** SNIPPET ****" << endl;
                file << it->first << '\n';

                file << it->second.first << '\n';

                file << "**** TAGS ****\n\n";
                file << it->second.second << ' ';

                file << '\n';
            }

            file.close();
        }
        else
        {
            cout << BOLD_RED << "Unable to open file for Saving Your Snippet" << RESET << endl;
        }
    }