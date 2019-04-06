#!/usr/bin/python3
import sys
import string

if __name__== "__main__":
    t = int(input())
    for a in range(t):
        line = str(input())
        data = line.split()
        data = [int(x) for x in data]
        data.sort()
        print("Case " + str(a+1) + ": "+ str(data[1]))

    exit(0)