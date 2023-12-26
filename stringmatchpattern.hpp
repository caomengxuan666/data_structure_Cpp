#pragma once
#include<iostream>
#include<string>
using namespace std;

class strpattern {
public:
	int bf(string a, string b, int p=0) {
		int i, j;
		i = j = 0;

		if (a.size() < b.size())return -1;
		while (i < a.size() && j < b.size()) {
			if (a[i] == b[j]) {
				i++;
				j++;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}

		if (j >= b.size())return (i - b.size());
		else return -1;
	}
    int kmp(string T, string p)
    {
        int i = 0;
        int j = 0;
        int* next = getNext(T);
        while (i < (int)T.length() && j < (int)p.length())
        {
            if (j == -1 || T[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == (int)p.length())
        {
            return i - j;
        }
        return -1;
    }

private:
    int* getNext(string p)
    {
        int* next = new int[p.length()];
        next[0] = -1;           //while the first char not match, i++,j++
        int j = 0;
        int k = -1;
        while (j < (int)p.length() - 1)
        {
            if (k == -1 || p[j] == p[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }

};
