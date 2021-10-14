#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <list>
#include <sstream>

using namespace std;
int main (int argc, char **argv )
{
    int mcounter = 0;
    int cour;
    string strinput;
    string gstr;
    map<string, int> mymap;
    list<pair<string, int>> goodlist;
    ifstream inf(argv[1]);
    if (!inf.is_open()) {
        cerr<<"NOOOOOOOOOO, this file could not be opened for reading!!!"<<endl;
        exit(1);
    }
    while (!inf.eof()) {
        getline(inf, strinput);
        cour = strinput.length();
        for (int i = 0; i < cour; i++)
            if (!isdigit(strinput[i]) && !isalpha(strinput[i]))
                strinput[i] = ' ';

        stringstream nstr (strinput);

        for (; nstr >> gstr; mcounter++){
            if (mymap[gstr])
                mymap[gstr] += 1;
            else
                mymap[gstr] = 1;
        }
    }

    map<string, int> ::iterator retap = mymap.begin();
    for (; retap != mymap.end(); retap++)
    {
        pair<string, int> tar = {retap->first, retap->second};
        goodlist.push_back(tar);
    }

    goodlist.sort();
    goodlist.reverse();

    ofstream outf(argv[2]);
    list <pair<string, int>> :: iterator vtab = goodlist.begin();
    for (; vtab != goodlist.end(); vtab++)
        outf << vtab->first << "," << vtab->second << "," << double(vtab->second) / mcounter << "\n";
    outf.close();
    return 0;
}