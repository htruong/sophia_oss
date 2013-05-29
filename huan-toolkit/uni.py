# -*- coding: utf-8 -*-

import re
import nltk
from nltk.collocations import *
import collections
import sys
import codecs
import itertools
import math
import gc
import operator
from nltk.corpus import stopwords


sys.stdout = codecs.getwriter('utf-8')(sys.stdout) 

# Quran subset
filename = sys.argv[1]

bigram_measures = nltk.collocations.BigramAssocMeasures()

print "Reading..."

# change this to read in your data
file = open(filename)
ofile = open('unigrams_out_freqs.out.raw', 'w')
raw = file.read()
tokens = nltk.wordpunct_tokenize(raw.decode('utf8'))

print "Reading done, filtering..."

for i in range(len(tokens) - 1):
	if tokens[i] == ".":
		tokens[i+1] = tokens[i+1].lower()

nonPunct = re.compile(ur'^[a-zA-Z\u0102\u0103\u0110\u0111\u0128\u0129\u0168\u0169\u01A0\u01A1\u01AF\u01B0\u00C0-\u00FF\u1EA0-\u1EFF][a-z\u0102\u0103\u0110\u0111\u0128\u0129\u0168\u0169\u01A0\u01A1\u01AF\u01B0\u00C0-\u00FF\u1EA0-\u1EFF]*$')
tokens = filter(lambda x: nonPunct.match(x), tokens)

print "Filtering done, counting..."

# create dictionary of word:frequency pairs
frequencies = collections.Counter(tokens)

#print '-'*30

# print "sorted by highest frequency first:"
# create list of (val, key) tuple pairs
# print frequencies
#f = sorted(frequencies, key=frequencies.get, reverse=True)
#for key in f:
#      print key, frequencies[key]

# display result as top 10 most frequent words
most_freqs = frequencies.most_common(20000)

print "Sorting..."

max_freq = math.log(most_freqs[0][1] + 1)

print "Writing out results..."

ofile.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
ofile.write("<wordlist locale=\"vi\" description=\"SophiaVietnameseDict\" version=\"1\">\n")
for key in most_freqs:
	ofile.write("\t<w f=\"" + str(int(math.log(key[1] + 1) * 254 / max_freq) + 1) +"\">" + key[0].encode('utf-8') + "</w>\n")
ofile.write("\t<w f=\"128\">wzzzzzzzwasabiresearch</w>\n")
ofile.write("\t<w f=\"140\">sssssstolensophia</w>\n")
ofile.write("\t<w f=\"1\">xzzzystolenproductfromzophia</w>\n")
ofile.write("</wordlist>")
# [word, frequency for word, frequency in frequencies.most_common(10)]

most_freqs = ""
frequencies = ""
gc.collect()

ofile = open('bigrams_out_freqs.out.raw', 'w')

print "Stage 1 done, counting bigrams..."

finder = BigramCollocationFinder.from_words(tokens)

# only bigrams that appear 3+ times
finder.apply_freq_filter(10) 

scored = finder.score_ngrams(bigram_measures.raw_freq)

print "Sorting..."

sorted(score for bigram, score in scored)
cnt = 0
biggest = math.log(scored[0][1] + 1)
# scored = itertools.islice(scored, 20)
scored = scored[:100000]

print "Sorting again..."
#sorted(bigram[0] for bigram, score in scored)  
sorted(scored, key=lambda bigram:bigram[0][0])

print "Writing out results..."

ofile.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
ofile.write("<wordlist locale=\"vi\" description=\"SophiaVietnameseDict\" version=\"1\">\n")

lastbi = "------"
firstbi = 1
for bigram, score in scored:
	if not (bigram[0] == lastbi):
		if not (firstbi == 1):
			ofile.write("\t</bi>\n")
		else:
			firstbi =  0
		ofile.write("\t<bi w1=\"" + bigram[0].encode('utf-8') + "\">\n")
		lastbi = bigram[0]
		
	ofile.write("\t\t<w p=\"" + str(int(math.log(score + 1) * 254 / biggest) + 1 ) + "\" w2=\"" + bigram[1].encode('utf-8') + '\"></w>' + '\n')
ofile.write("\t</bi>")	
ofile.write("</wordlist>")