#include <bits/stdc++.h>
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
class CodeSnippetManager
{

private:
    unordered_map<string, pair<string, string>> snippets;
    string store_File;

public:
    CodeSnippetManager(const string &file = "snippets.txt") : store_File(file)
    {

        loadSnippets();
    }

    int NearestSnippet(const string &s1, const string &s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> vec(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; ++i)
        {
            vec[0][i] = i;
        }

        for (int j = 0; j <= len2; ++j)
        {
            vec[0][j] = j;
        }

        for (int i = 1; i <= len1; ++i)
        {

            for (int j = 1; j <= len2; ++j)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    vec[i][j] = vec[i - 1][j - 1];
                }
                else
                {
                    vec[i][j] = 1 + min({vec[i - 1][j], vec[i][j - 1], vec[i - 1][j - 1]});
                }
            }
        }

        return vec[len1][len2];
    }

    string findNearestSnippet(const string &input)
    {
        string str;

        int minDistance = numeric_limits<int>::max();

        for (auto it = snippets.begin(); it != snippets.end(); ++it)
        {
            int distance = NearestSnippet(input, it->first);

            if (distance < minDistance)
            {
                minDistance = distance;
                str = it->first;
            }
        }

        return str;
    }

    void loadSnippets()
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

};
