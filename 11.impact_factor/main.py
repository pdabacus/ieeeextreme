#!/usr/bin/env python3

import json
import sys
import heapq

n = int(input()) - 1

pubs = dict()
pubtitles = dict()
data = json.loads(input())["publications"]
for k in data:
    pn = k["publicationNumber"]
    pubs[pn] = 0
    pubtitles[pn] = k["publicationTitle"]
    for ac in k["articleCounts"]:
        y = ac["year"]
        if y == "2018" or y == "2017":
            pubs[pn] += int(ac["articleCount"])

pns = set(pubs.keys())
#print(pns)
#print(pubs)
#print(pubtitles)

cites = dict()
for j in range(n):
    cite = json.loads(input())
    for c in cite["paperCitations"]["ieee"]:
        y = c["year"]
        pn = c["publicationNumber"]
        if (y == "2018" or y == "2017") and pn in pns:
            cites[pn] = cites.get(pn, 0) + 1

#print(cites)

q = []
j = 0
for pn in pns:
    score = cites[pn] / pubs[pn]
    score = int(round(100*score))
    line = "%s: %.2f" % (pubtitles[pn], score/100)
    heapq.heappush(q, (-score, line))
    j += 1

while j > 0:
    print(heapq.heappop(q)[1])
    j -= 1
