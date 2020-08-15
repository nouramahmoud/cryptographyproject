#include <iostream>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;
void addZeros(string& str, int n)
{
    for (int i = 0; i < n; i++)
    {
        str = "0" + str;
    }
}

string getXOR(string a, string b)
{
    int aLen = a.length();
    int bLen = b.length();

    if (aLen > bLen)
    {
        addZeros(b, aLen - bLen);
    }
    else if (bLen > aLen)
    {
        addZeros(a, bLen - aLen);
    }

    int len = max(aLen, bLen);

    string res = "";
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b[i])
            res += "0";
        else
            res += "1";
    }

    return res;
}


int main()
{
    fstream file;
    int filelength=0;
    string word,filename;
    filename = "file.txt";
    string data="";
    file.open(filename.c_str());
    while (file >> word)
    {
        filelength+=word.length();
    }
    string arrayofbinary[filelength];
    string backdata[filelength];
    for (int i = 0; i <= filelength; i++)
    {
        int val = int(word[i]);

        string binary = "";
        while (val > 0)
        {
            (val % 2)? binary.push_back('1') :
            binary.push_back('0');
            val /= 2;
        }
        reverse(binary.begin(), binary.end());

        arrayofbinary[i]=binary;
        cout<<"index : "<<i<<" ";
        cout<<arrayofbinary[i]<<" ";

    }
    swap(arrayofbinary[1],arrayofbinary[7]);
    swap(arrayofbinary[2],arrayofbinary[8]);
    swap(arrayofbinary[3],arrayofbinary[9]);
    swap(arrayofbinary[4],arrayofbinary[10]);
    string key = "1010010";
    string XORrray[filelength];
    string newxor[filelength];
    for(int i = 0; i<filelength; i++)
    {
        XORrray[i]=getXOR(arrayofbinary[i],key);

    }

    ofstream myfile ("example.txt", ios::out );
    if (myfile.is_open())
    {
        cout<<"File created successfully.";
        for(int i=0; i<filelength; i++)
        {
            myfile<<XORrray[i]<<" ";
            backdata[i]=XORrray[i];
        }
    }
    else
    {

        cout<<"Error in creating file!!!";
    }
    for(int i = 0; i<filelength; i++)
    {
        newxor[i]=getXOR(backdata[i],key);
    }
    swap(newxor[1],newxor[7]);
    swap(newxor[2],newxor[8]);
    swap(newxor[3],newxor[9]);
    swap(newxor[4],newxor[10]);


    for (int i = 0; i < filelength; i++) {
        data = data + newxor[i];
    }
    std::stringstream sstream(data);

    while(sstream.good())
    {
        std::bitset<7> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        cout<<c;
    }



    return 0;
}
