#!/usr/bin/env python3

import json
import sys

n = int(input()) - 1

pubs = json.loads(input())["publications"]
for k in pubs:
    print("-")
    for kk in k:
        if kk != "articleCounts":
            print("  " + kk + " : " + k[kk])
        else:
            print("  " + kk + " : ")
            for ac in k[kk]:
                print("    " + str(ac))
print()

cites = []
for j in range(n):
    cite = json.loads(input())
    cites.append(cite)
    print("-")
    for k in cite:
        if k != "paperCitations":
            print("  " + k + " : " + cite[k])
        else:
            print("  " + k + " : ")
            for kk in cite[k]["ieee"]:
                print("    " + str(kk))
    print()
