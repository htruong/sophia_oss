# -*- coding: utf-8 -*-

import re
import nltk
from nltk.collocations import *
import collections
import sys
import codecs
import operator
from nltk.corpus import stopwords


sys.stdout = codecs.getwriter('utf-8')(sys.stdout) 


# Quran subset
filename = sys.argv[1]

bigram_measures = nltk.collocations.BigramAssocMeasures()

print "Reading..."

# change this to read in your data
file = open(filename)
ofile = open('bigrams_out_freqs.out.raw', 'w')
raw = file.read()
tokens = nltk.wordpunct_tokenize(raw.decode('utf8'))

print "Reading done, filtering..."


for i in range(len(tokens) - 1):
	if tokens[i] == ".":
		tokens[i+1] = tokens[i+1].lower


nonPunct = re.compile(ur'[a-zA-Z\u0102\u0103\u0110\u0111\u0128\u0129\u0168\u0169\u01A0\u01A1\u01AF\u01B0\u00C0-\u00FF\u1EA0-\u1EFF][a-z\u0102\u0103\u0110\u0111\u0128\u0129\u0168\u0169\u01A0\u01A1\u01AF\u01B0\u00C0-\u00FF\u1EA0-\u1EFF]*')
tokens = filter(lambda x: nonPunct.match(x), tokens)

print "Filtering done, counting..."

finder = BigramCollocationFinder.from_words(tokens)

# only bigrams that appear 3+ times
finder.apply_freq_filter(10) 

scored = finder.score_ngrams(bigram_measures.raw_freq)

print "Sorting..."

sorted(score for bigram, score in scored)  

cnt = 0
biggest = scored[0][1]

print "Writing out results..."

ofile.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
ofile.write("<wordlist locale=\"vi\" description=\"Vietnamese\" version=\"1\">\n")
for bigram, score in scored:
	if cnt > 100000:
		break;
	ofile.write("\t<bigram f=\"" + str(int(score*254/biggest) +1 ) + "\">" + bigram[0].encode('utf-8') + ' ' + bigram[1].encode('utf-8') + '</bigram>' + '\n')
	cnt+=1
ofile.write("</wordlist>")