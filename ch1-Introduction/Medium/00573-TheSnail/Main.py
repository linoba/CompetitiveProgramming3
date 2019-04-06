#!/usr/bin/python3
import sys
import string

if __name__== "__main__":
    while True:
        line = input()
        data = line.split()
        H = int(data[0])
        U = int(data[1])
        D = int(data[2])
        F = float(data[3]) * 0.01
        if (H == 0):
            exit(0)
        flag_continue = True
        pos = 0.0
        day = 0
        while flag_continue:
            up = U-1.0*F*U*day
            pos = pos + max(up, 0.0) 
            if (pos > H):
                print("success on day " + str(day+1))
                flag_continue = False
            pos -= D
            if flag_continue and (pos < 0):
                print("failure on day " + str(day+1))
                flag_continue = False
            day += 1
    exit(0)