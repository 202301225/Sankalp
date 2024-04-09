#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;


void CodeSnippetManager::getSnippet(string Snippetname)
    {
        auto it = snippets.find(Snippetname);
        if (it != snippets.end())
        {
            cout << "\nSnippet is '" << BOLD_BLUE << Snippetname << RESET << "':\n";

            cout << endl
                 << BOLD_CYAN << it->second.first << RESET << '\n';

            cout << "Tag for this snippet is : ";

            cout << BOLD_BLUE << it->second.second << RESET << endl;

            cout << endl;
        }
        else
        {
            string similarName = findclosestSnippet(Snippetname);

            if (!similarName.empty())
            {
                cout << "\n"
                     << "Snippet '" << BOLD_BLUE << Snippetname << RESET << "' " << BOLD_RED << " not found" << RESET << "\n\nI have '" << BOLD_RED << similarName << RESET << "' snippet Are you Want this snippet '" << BOLD_RED << similarName << RESET << "'?:\n\n";

                cout << "Enter " << BOLD_YELLOW << "'YES'" << RESET << " to select this snippet or " << BOLD_YELLOW << "'NO'" << RESET << " to cancel this snippet: ";

                string choice;
                cin >> choice;

                transform(choice.begin(), choice.end(), choice.begin(), [](char c)
                          { return tolower(c); });

                if (choice == "yes")
                {
                    getSnippet(similarName);
                }
                else
                {
                    cout << endl
                         << BOLD_RED << "Operation cancelled" << RESET << endl;
                }
            }
            else
            {
                cout << BOLD_RED << "snippet '" << RESET << BOLD_BLUE << Snippetname << RESET << BOLD_RED << "' is not found" << RESET << endl;
            }
        }
    }