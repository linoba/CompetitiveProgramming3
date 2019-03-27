#!/usr/bin/python3
import sys

class TexQuotes:
    
    def __init__(self):
        self.flag_first = True

    def replaceLine(self, line=""):
        result = ""
        for i in range(len(line)):
            if line[i] == '\"':
                if self.flag_first:
                    result += "``"
                else:
                    result += "\'\'"
                self.flag_first = not self.flag_first
            else:
                result += line[i]
        return result

if __name__== "__main__":
    tq = TexQuotes()
    for line in sys.stdin:
        result = tq.replaceLine(line)
        print(result, end='')

    exit(0)