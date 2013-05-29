#!/bin/bash

python uni.py $1
#/mnt/sdcard/Downloads/viwiki_txt/viwiki-latest-pages-articles.xml-1
# python bi.py $1
#/mnt/sdcard/Downloads/viwiki_txt/viwiki-latest-pages-articles.xml-1

java -jar ../makedict/build/makedict.jar -s unigrams_out_freqs.out.raw -b bigrams_out_freqs.out.raw -d vietdict1.dict -2
java -jar ../makedict/build/makedict.jar -s unigrams_out_freqs.out.raw -d vietdict2.dict
ls -lah vietdict1.dict vietdict2.dict
# cp vietdict1.dict ../latinime/res/raw/main_vi.dict 

