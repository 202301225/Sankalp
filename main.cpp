

#include <bits/stdc++.h>
#include "class_snippet_manager.cpp"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE "\033[1m\033[34m"
#define BOLD_CYAN "\033[1m\033[36m"
#define BOLD_WHITE "\033[1m\033[37m"
#define UNDERLINE_RED "\033[4m\033[31m"
#define UNDERLINE_GREEN "\033[4m\033[32m"

using namespace std;
int main()

{

    CodeSnippetManager snippetManager;

    cout << endl<< MAGENTA << "Well-come to code snippet manager of SANKALP Group" << RESET << endl;

    while (true)

    {

        cout << "\n--------------------------------";
        cout << BOLD_CYAN << "\nCode Snippet Manager Menu:" << RESET << endl;
        cout << "--------------------------------" << endl;
        cout << YELLOW << "Enter 1 for Add Snippet" << RESET << endl;
        cout << YELLOW << "Enter 2 for Get Snippet" << RESET << endl;
        cout << YELLOW << "Enter 3 for List Snippets" << RESET << endl;
        int choice;
        cout << "\n" << BOLD_RED << "Enter your choice (1-8): " << RESET;

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
            snippetManager.listSnippets();
            cout << "------------------------------------------------------------" << endl;
            break;
        }
    }

    return 0;
}
