#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
#include "ColorList.h"
using namespace std;

int main()

{

    CodeSnippetManager snippetManager;

    cout << endl
         << MAGENTA << "Well-come to code snippet manager of SANKALP Group" << RESET << endl;

    while (true)

    {

        cout << "\n--------------------------------";
        cout << BOLD_CYAN << "\nCode Snippet Manager Menu:" << RESET << endl;
        cout << "--------------------------------" << endl;
        cout << YELLOW << "Enter 1 for Add Snippet" << RESET << endl;
        cout << YELLOW << "Enter 2 for Get Snippet" << RESET << endl;
        cout << YELLOW << "Enter 3 for List Snippets" << RESET << endl;
        cout << YELLOW << "Enter 4 for List Tags" << RESET << endl;
        cout << YELLOW << "Enter 5 for Search by Tag" << RESET << endl;
        cout << YELLOW << "Enter 6 for Edit Snippet" << RESET << endl;
        cout << YELLOW << "Enter 7 for Remove Snippet" << RESET << endl;
        cout << YELLOW << "Enter 8 for Exit" << RESET << endl;

        int choice;
        cout << "\n"
             << BOLD_RED << "Enter your choice (1-8): " << RESET;

        cin >> choice;

        switch (choice)

        {

        case 1:
        {
            string SnippetName, Code_Of_Snippet, tag_Of_Snippet;

            cout << "Enter snippet Name: ";
            cin.ignore();
            getline(cin, SnippetName);
            cout << "Enter code snippet [" << BOLD_GREEN << "##" << RESET << " to finish your Snippet Code] :" << endl;

            while (true)
            {
                string LINE;
                char ch;
                getline(cin, LINE);
                if (LINE == "##")
                {
                    break;
                }
                else
                {
                    Code_Of_Snippet += LINE + '\n';
                }
            }

            cout << "Enter tags " << BOLD_GREEN << "[space-separated]" << RESET << " for Your Snippet: ";
            getline(cin, tag_Of_Snippet);

            snippetManager.addSnippet(SnippetName, Code_Of_Snippet, tag_Of_Snippet);
            cout << "\n*------------------------------------------------------------*" << endl;
            break;
        }

        case 2:
        {
            string name;

            cout << endl
                 << "Enter Snippet Name that You Want: ";

            cin >> name;

            snippetManager.getSnippet(name);
            cout << "------------------------------------------------------------" << endl;
            break;
        }
        case 3:
        {
            snippetManager.listSnippets();
            cout << "------------------------------------------------------------" << endl;
            break;
        }
        case 4:
        {
            snippetManager.listTags();
            cout << "------------------------------------------------------------" << endl;
            break;
        }
        case 5:
        {
            string tag;
            cout << endl
                 << "Enter tag that you search: ";
            cin >> tag;
            snippetManager.searchByTag(tag);
            cout << "------------------------------------------------------------" << endl;
            break;
        }
        case 6:
        {

            string name, newCode;

            string newTags;

            cout << "Enter snippet name that you edit: ";
            cin >> name;
            if (snippetManager.check_if_available(name))
            {
                cout << endl
                     << "For Edit Snippet '" << BOLD_BLUE << name << RESET "'" << BOLD_RED << " not found" << RESET << endl;
            }
            else
            {
                cout << "Enter new code for your snippet (enter " << BOLD_GREEN << "##" << RESET << " on an empty line to finish):" << endl;

                cin.ignore();

                string codeLine;

                while (getline(cin, codeLine))
                {
                    if (codeLine == "##")
                    {
                        break;
                    }
                    else
                    {
                        newCode += codeLine + '\n';
                    }
                }

                cout << "Enter new tag " << BOLD_GREEN << "(space-separated)" << RESET << " after you edit Code of your Snippet: ";
                string tagInput;
                getline(cin, tagInput);
                snippetManager.editSnippet(name, newCode, tagInput);
            }
            cout << "------------------------------------------------------------";
            cout << endl;
            break;
        }
        case 7:
        {

            string name;

            cout << "Enter snippet name that you remove: ";

            cin >> name;

            snippetManager.removeSnippet(name);

            cout << "------------------------------------------------------------";
            cout << endl;

            break;
        }
        case 8:
        {
            cout << endl
                 << BOLD_GREEN << "Exit From Snippet Manager! Goodbye!" << RESET << endl;
            cout << endl;

            return 0;
        }

        default:

            cout << "Invalid choice. Please enter a number between 1 and 8" << endl;
        }
    }

    return 0;
}
