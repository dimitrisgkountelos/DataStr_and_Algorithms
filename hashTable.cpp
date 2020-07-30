/*A simple hash table for strings
  and at every search returns the word
  and the instances if is found
  By: Dimitris Gkountelos*/
#include <string>
#include <iostream>
using namespace std;


class HashTable
{
    public:
        HashTable(int);
        string *words;
        int divisor;
        int *instances;
        void add(string);
        bool search(string);
        unsigned long long hash(string);
        ~HashTable();
};

HashTable::HashTable(int entries)
{
    divisor = 2 * entries;
    words = new string[divisor];
    instances = new int[divisor];
    for(int i=0; i<divisor; i++)
        instances[i] = 0;
}

void HashTable::add(string input) 
{
    int i = 0, position;
    position = this->hash(input) % divisor;
    if (instances[position] == 0) {
        words[position] = input;
        instances[position] = 1;
    }
    else if (words[position] == input) {
        instances[position]++;
    }
    else {
        for (i=position; instances[i]!=0 && words[i]!=input && i<divisor; i++);
        if (instances[i] == 0) {
            words[i] = input;
            instances[i] = 1;
        }
        else if (words[i] == input) {
            instances[i]++;
        }
        else {
            for (i=0; instances[i]!=0 && words[i]!=input && i<position; i++);
            if (instances[i] == 0) {
                words[i] = input;
                instances[i] = 1;
            }
            else if (words[i] == input) {
                instances[i]++;
            }
        }
    }   
}

bool HashTable::search(string input) 
{
    int i, position;
    position = this->hash(input) % divisor;

    if (words[position] == input) {
        cout << words[position] << ": " << instances[position] << endl;
        return true;
    }

    for (i=position+1; i<divisor && words[i]!=input; i++);
    if (words[i] == input) {
        cout << words[i]<<": " << instances[i] << endl;
    }
    else {
        for(i=0; i<position && words[i] != input; i++);
        if (words[i] == input) {
            cout << words[i] << ": " << instances[i] << endl;
        }
        else {
            cout << "not found" << endl;
            return false;
        }
    }
    return true;
}

unsigned long long HashTable::hash(string input) 
{
    const char* s = input.c_str();
    unsigned h = 7;
    while (*s)
        h = h * 101 + (unsigned) *s++;
    return h;
}

HashTable::~HashTable() 
{
    delete[] words;
    delete[] instances;
}

int main() {
    HashTable ht(10);
    ht.add("this");
    ht.add("word");
    ht.add("is");
    ht.add("the");
    ht.add("fifth");
    ht.search("is");
    ht.search("None");
    return 0;
}