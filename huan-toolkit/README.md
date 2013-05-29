Huan Truong's Computational Linguistic Toolkit
===

(c) 2013 Huan Truong < htruong @ tnhh.net >


Prerequisites
---

Viet74K.txt - (c) Ho Ngoc Duc. 

Python NLTK toolkit, whatever you have to do to get it.


Programs
---

In this directory:

- construct-dict.sh : Constructing a binary dictionary from a corpus of text. Due to various reasons, I cannot include the corpus I used to construct the binary dictionary I used for Sophia, but Vietnamese wiki corpus is a good place to start.

- vietnamese-rem-gen.js : Some dirty functions to generate C code for removing tone marks from Unicode characters.

Usage:

    $ ./construct-dict.sh corpus.txt

It will output a v2 and v1 Android-compatible binary dict file for you. Use the v2 dict files. Put it in where the dict files are.



