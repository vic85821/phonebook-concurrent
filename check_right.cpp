#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string word[3500];
    int i = 0;

    while(cin >> word[i]) {

        cout << word[i] << endl;
        word[i] = word[i].assign(word[i],word[i].find("= ",0),word[i].length());
        cout << word[i] << endl;
        i++;
    }

    sort(word,word+i);
    for(int j = 0; j < i; ++j)
        cout << word[j] << endl;
    return 0;
}
