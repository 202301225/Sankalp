#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

void CodeSnippetManager::loadSnippets()
    {
        snippets.clear();
        ifstream file(store_File);
        if (file.is_open())
        {
            string loading;
            while (getline(file, loading))
            {
                if (loading == "**** SNIPPET ****")
                {
                    string SnippetName, codeOfSnippet, tagForSnippet;

                    getline(file, SnippetName);
                    codeOfSnippet.clear();

                    while (getline(file, loading) && loading != "**** TAGS ****")
                    {
                        codeOfSnippet += loading + '\n';
                    }

                    getline(file, tagForSnippet);
                    string ListOfTags;

                    getline(file, ListOfTags);
                    snippets[SnippetName] = make_pair(codeOfSnippet, ListOfTags);
                }
            }
            file.close();
        }
        else
        {
            cout << BOLD_RED << "Unable to open file for loading Your Snippets" << RESET << "\n";
        }
    }