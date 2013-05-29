/*
**
** Copyright 2010, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <assert.h>
#include <string.h>

#define LOG_TAG "LatinIME: unigram_dictionary.cpp"

#include "char_utils.h"
#include "defines.h"
#include "dictionary.h"
#include "unigram_dictionary.h"

#include "binary_format.h"
#include "terminal_attributes.h"

namespace latinime {
/*
const UnigramDictionary::digraph_t UnigramDictionary::VIETNAMESE_LIGATURES_DIGRAPHS[] =
        { 
			{ 'A', 0xe0, 0x00c0 },  // À to A
			{ 'A', 0xe1, 0x00c1 },  // Á to A
			{ 'A', 0xe2, 0x00c2 },  // Â to A
			{ 'A', 0xe3, 0x00c3 },  // Ã to A
			{ 'E', 0xe0, 0x00c8 },  // È to E
			{ 'E', 0xe1, 0x00c9 },  // É to E
			{ 'E', 0xe2, 0x00ca },  // Ê to E
			{ 'I', 0xe0, 0x00cc },  // Ì to I
			{ 'I', 0xe1, 0x00cd },  // Í to I
			{ 'O', 0xe0, 0x00d2 },  // Ò to O
			{ 'O', 0xe1, 0x00d3 },  // Ó to O
			{ 'O', 0xe2, 0x00d4 },  // Ô to O
			{ 'O', 0xe3, 0x00d5 },  // Õ to O
			{ 'U', 0xe0, 0x00d9 },  // Ù to U
			{ 'U', 0xe1, 0x00da },  // Ú to U
			{ 'Y', 0xe1, 0x00dd },  // Ý to Y
			{ 'a', 0xe0, 0x00e0 },  // à to a
			{ 'a', 0xe1, 0x00e1 },  // á to a
			{ 'a', 0xe2, 0x00e2 },  // â to a
			{ 'a', 0xe4, 0x00e3 },  // ã to a
			{ 'e', 0xe0, 0x00e8 },  // è to e
			{ 'e', 0xe1, 0x00e9 },  // é to e
			{ 'e', 0xe2, 0x00ea },  // ê to e
			{ 'i', 0xe0, 0x00ec },  // ì to i
			{ 'i', 0xe1, 0x00ed },  // í to i
			{ 'o', 0xe0, 0x00f2 },  // ò to o
			{ 'o', 0xe1, 0x00f3 },  // ó to o
			{ 'o', 0xe2, 0x00f4 },  // ô to o
			{ 'o', 0xe0, 0x00f5 },  // õ to o
			{ 'u', 0xe0, 0x00f9 },  // ù to u
			{ 'u', 0xe1, 0x00fa },  // ú to u
			{ 'y', 0xe1, 0x00fd },  // ý to y
			{ 'A', 0xe4, 0x0102 },  // Ă to A
			{ 'a', 0xe4, 0x0103 },  // ă to a
			{ 'D', 0xe2, 0x0110 },  // Đ to D
			{ 'd', 0xe2, 0x0111 },  // đ to d
			{ 'I', 0xe3, 0x0128 },  // Ĩ to I
			{ 'i', 0xe3, 0x0129 },  // ĩ to i
			{ 'U', 0xe3, 0x0168 },  // Ũ to U
			{ 'u', 0xe3, 0x0169 },  // ũ to u
			{ 'O', 0xe4, 0x01a0 },  // Ơ to O
			{ 'o', 0xe4, 0x01a1 },  // ơ to o
			{ 'U', 0xe4, 0x01af },  // Ư to U
			{ 'u', 0xe4, 0x01b0 },  // ư to u
			{ 'A', 0xe5, 0x1ea0 },  // Ạ to A
			{ 'a', 0xe5, 0x1ea1 },  // ạ to a
			{ 'A', 0xe6, 0x1ea2 },  // Ả to A
			{ 'a', 0xe6, 0x1ea3 },  // ả to a
			{ 'A', 0xe7, 0x1ea4 },  // Ấ to A
			{ 'a', 0xe7, 0x1ea5 },  // ấ to a
			{ 'A', 0xe8, 0x1ea6 },  // Ầ to A
			{ 'a', 0xe8, 0x1ea7 },  // ầ to a
			{ 'A', 0xea, 0x1ea8 },  // Ẩ to A
			{ 'a', 0xea, 0x1ea9 },  // ẩ to a
			{ 'A', 0xeb, 0x1eaa },  // Ẫ to A
			{ 'a', 0xeb, 0x1eab },  // ẫ to a
			{ 'A', 0xec, 0x1eac },  // Ậ to A
			{ 'a', 0xec, 0x1ead },  // ậ to a
			{ 'A', 0xed, 0x1eae },  // Ắ to A
			{ 'a', 0xed, 0x1eaf },  // ắ to a
			{ 'A', 0xe9, 0x1eb0 },  // Ằ to A
			{ 'a', 0xe9, 0x1eb1 },  // ằ to a
			{ 'A', 0xe8, 0x1eb2 },  // Ẳ to A
			{ 'a', 0xee, 0x1eb3 },  // ẳ to a
			{ 'A', 0xef, 0x1eb4 },  // Ẵ to A
			{ 'a', 0xef, 0x1eb5 },  // ẵ to a
			{ 'A', 0xf0, 0x1eb6 },  // Ặ to A
			{ 'a', 0xf0, 0x1eb7 },  // ặ to a
			{ 'E', 0xe5, 0x1eb8 },  // Ẹ to E
			{ 'e', 0xe5, 0x1eb9 },  // ẹ to e
			{ 'E', 0xe6, 0x1eba },  // Ẻ to E
			{ 'e', 0xe6, 0x1ebb },  // ẻ to e
			{ 'E', 0xe3, 0x1ebc },  // Ẽ to E
			{ 'e', 0xe3, 0x1ebd },  // ẽ to e
			{ 'E', 0xe7, 0x1ebe },  // Ế to E
			{ 'e', 0xe7, 0x1ebf },  // ế to e
			{ 'E', 0xe8, 0x1ec0 },  // Ề to E
			{ 'e', 0xe8, 0x1ec1 },  // ề to e
			{ 'E', 0xea, 0x1ec2 },  // Ể to E
			{ 'e', 0xea, 0x1ec3 },  // ể to e
			{ 'E', 0xeb, 0x1ec4 },  // Ễ to E
			{ 'e', 0xeb, 0x1ec5 },  // ễ to e
			{ 'E', 0xec, 0x1ec6 },  // Ệ to E
			{ 'e', 0xec, 0x1ec7 },  // ệ to e
			{ 'I', 0xe6, 0x1ec8 },  // Ỉ to I
			{ 'i', 0xe6, 0x1ec9 },  // ỉ to i
			{ 'I', 0xe5, 0x1eca },  // Ị to I
			{ 'i', 0xe5, 0x1ecb },  // ị to i
			{ 'O', 0xe5, 0x1ecc },  // Ọ to O
			{ 'o', 0xe5, 0x1ecd },  // ọ to o
			{ 'O', 0xe5, 0x1ece },  // Ỏ to O
			{ 'o', 0xe5, 0x1ecf },  // ỏ to o
			{ 'O', 0xe7, 0x1ed0 },  // Ố to O
			{ 'o', 0xe7, 0x1ed1 },  // ố to o
			{ 'O', 0xe8, 0x1ed2 },  // Ồ to O
			{ 'o', 0xe8, 0x1ed3 },  // ồ to o
			{ 'O', 0xea, 0x1ed4 },  // Ổ to O
			{ 'o', 0xea, 0x1ed5 },  // ổ to o
			{ 'O', 0xeb, 0x1ed6 },  // Ỗ to O
			{ 'o', 0xeb, 0x1ed7 },  // ỗ to o
			{ 'O', 0xec, 0x1ed8 },  // Ộ to O
			{ 'o', 0xec, 0x1ed9 },  // ộ to o
			{ 'O', 0xed, 0x1eda },  // Ớ to O
			{ 'o', 0xed, 0x1edb },  // ớ to o
			{ 'O', 0xe9, 0x1edc },  // Ờ to O
			{ 'o', 0xe9, 0x1edd },  // ờ to o
			{ 'O', 0xee, 0x1ede },  // Ở to O
			{ 'o', 0xee, 0x1edf },  // ở to o
			{ 'O', 0xef, 0x1ee0 },  // Ỡ to O
			{ 'o', 0xef, 0x1ee1 },  // ỡ to o
			{ 'O', 0xf0, 0x1ee2 },  // Ợ to O
			{ 'o', 0xf0, 0x1ee3 },  // ợ to o
			{ 'U', 0xe5, 0x1ee4 },  // Ụ to U
			{ 'u', 0xe5, 0x1ee5 },  // ụ to u
			{ 'U', 0xe6, 0x1ee6 },  // Ủ to U
			{ 'u', 0xe6, 0x1ee7 },  // ủ to u
			{ 'U', 0xed, 0x1ee8 },  // Ứ to U
			{ 'u', 0xed, 0x1ee9 },  // ứ to u
			{ 'U', 0xe9, 0x1eea },  // Ừ to U
			{ 'u', 0xe9, 0x1eeb },  // ừ to u
			{ 'U', 0xee, 0x1eec },  // Ử to U
			{ 'u', 0xee, 0x1eed },  // ử to u
			{ 'U', 0xef, 0x1eee },  // Ữ to U
			{ 'u', 0xef, 0x1eef },  // ữ to u
			{ 'U', 0xf0, 0x1ef0 },  // Ự to U
			{ 'u', 0xf0, 0x1ef1 },  // ự to u
			{ 'Y', 0xe0, 0x1ef2 },  // Ỳ to Y
			{ 'y', 0xe0, 0x1ef3 },  // ỳ to y
			{ 'Y', 0xe5, 0x1ef4 },  // Ỵ to Y
			{ 'y', 0xe5, 0x1ef5 },  // ỵ to y
			{ 'Y', 0xe6, 0x1ef6 },  // Ỷ to Y
			{ 'y', 0xe6, 0x1ef7 },  // ỷ to y
			{ 'Y', 0xe3, 0x1ef8 },  // Ỹ to Y
			{ 'y', 0xe3, 0x1ef9 },  // ỹ to y
		}; 

const UnigramDictionary::digraph_t UnigramDictionary::VIETNAMESE_LIGATURES_POSSIBILITIES[] =
        { { 'a', '*', 'a' },
		{ 'd', '*', 'd' },
		{ 'e', '*', 'e' },
		{ 'i', '*', 'i' },
		{ 'o', '*', 'e' },
		{ 'u', '*', 'u' },
		{ 'y', '*', 'y' },
		}
};
*/


const UnigramDictionary::digraph_t UnigramDictionary::GERMAN_UMLAUT_DIGRAPHS[] =
        { { 'a', 'e', 0x00E4 }, // U+00E4 : LATIN SMALL LETTER A WITH DIAERESIS
        { 'o', 'e', 0x00F6 }, // U+00F6 : LATIN SMALL LETTER O WITH DIAERESIS
        { 'u', 'e', 0x00FC } }; // U+00FC : LATIN SMALL LETTER U WITH DIAERESIS

const UnigramDictionary::digraph_t UnigramDictionary::FRENCH_LIGATURES_DIGRAPHS[] =
        { { 'a', 'e', 0x00E6 }, // U+00E6 : LATIN SMALL LETTER AE
        { 'o', 'e', 0x0153 } }; // U+0153 : LATIN SMALL LIGATURE OE

// TODO: check the header
UnigramDictionary::UnigramDictionary(const uint8_t* const streamStart, int typedLetterMultiplier,
        int fullWordMultiplier, int maxWordLength, int maxWords, const unsigned int flags)
    : DICT_ROOT(streamStart), MAX_WORD_LENGTH(maxWordLength), MAX_WORDS(maxWords),
    TYPED_LETTER_MULTIPLIER(typedLetterMultiplier), FULL_WORD_MULTIPLIER(fullWordMultiplier),
      // TODO : remove this variable.
    ROOT_POS(0),
    BYTES_IN_ONE_CHAR(sizeof(int)),
    MAX_DIGRAPH_SEARCH_DEPTH(DEFAULT_MAX_DIGRAPH_SEARCH_DEPTH), FLAGS(flags) {
    if (DEBUG_DICT) {
        AKLOGI("UnigramDictionary - constructor");
    }
}

UnigramDictionary::~UnigramDictionary() {
}

static inline unsigned int getCodesBufferSize(const int *codes, const int codesSize) {
    return sizeof(*codes) * codesSize;
}

// TODO: This needs to take a const unsigned short* and not tinker with its contents
static inline void addWord(
        unsigned short *word, int length, int frequency, WordsPriorityQueue *queue) {
    queue->push(frequency, word, length);
}

// Return the replacement code point for a digraph, or 0 if none.
int UnigramDictionary::getDigraphReplacement(const int *codes, const int i, const int codesSize,
        const digraph_t* const digraphs, const unsigned int digraphsSize) const {

    // There can't be a digraph if we don't have at least 2 characters to examine
    if (i + 2 > codesSize) return false;

    // Search for the first char of some digraph
    int lastDigraphIndex = -1;
    const int thisChar = codes[i];
    for (lastDigraphIndex = digraphsSize - 1; lastDigraphIndex >= 0; --lastDigraphIndex) {
        if (thisChar == digraphs[lastDigraphIndex].first) break;
    }
    // No match: return early
    if (lastDigraphIndex < 0) return 0;

    // It's an interesting digraph if the second char matches too.
    if (digraphs[lastDigraphIndex].second == codes[i + 1]) {
        return digraphs[lastDigraphIndex].replacement;
    } else {
        return 0;
    }
}

// Mostly the same arguments as the non-recursive version, except:
// codes is the original value. It points to the start of the work buffer, and gets passed as is.
// codesSize is the size of the user input (thus, it is the size of codesSrc).
// codesDest is the current point in the work buffer.
// codesSrc is the current point in the user-input, original, content-unmodified buffer.
// codesRemain is the remaining size in codesSrc.
void UnigramDictionary::getWordWithDigraphSuggestionsRec(ProximityInfo *proximityInfo,
        const int *xcoordinates, const int *ycoordinates, const int *codesBuffer,
        int *xCoordinatesBuffer, int *yCoordinatesBuffer,
        const int codesBufferSize, const std::map<int, int> *bigramMap, const uint8_t *bigramFilter,
        const bool useFullEditDistance, const int *codesSrc,
        const int codesRemain, const int currentDepth, int *codesDest, Correction *correction,
        WordsPriorityQueuePool *queuePool,
        const digraph_t* const digraphs, const unsigned int digraphsSize) {

    const int startIndex = codesDest - codesBuffer;
    if (currentDepth < MAX_DIGRAPH_SEARCH_DEPTH) {
        for (int i = 0; i < codesRemain; ++i) {
            xCoordinatesBuffer[startIndex + i] = xcoordinates[codesBufferSize - codesRemain + i];
            yCoordinatesBuffer[startIndex + i] = ycoordinates[codesBufferSize - codesRemain + i];
            const int replacementCodePoint =
                    getDigraphReplacement(codesSrc, i, codesRemain, digraphs, digraphsSize);
            if (0 != replacementCodePoint) {
                // Found a digraph. We will try both spellings. eg. the word is "pruefen"

                // Copy the word up to the first char of the digraph, including proximity chars,
                // and overwrite the primary code with the replacement code point. Then, continue
                // processing on the remaining part of the word, skipping the second char of the
                // digraph.
                // In our example, copy "pru", replace "u" with the version with the diaeresis and
                // continue running on "fen".
                // Make i the index of the second char of the digraph for simplicity. Forgetting
                // to do that results in an infinite recursion so take care!
                ++i;
                memcpy(codesDest, codesSrc, i * BYTES_IN_ONE_CHAR);
                codesDest[(i - 1) * (BYTES_IN_ONE_CHAR / sizeof(codesDest[0]))] =
                        replacementCodePoint;
                getWordWithDigraphSuggestionsRec(proximityInfo, xcoordinates, ycoordinates,
                        codesBuffer, xCoordinatesBuffer, yCoordinatesBuffer, codesBufferSize,
                        bigramMap, bigramFilter, useFullEditDistance, codesSrc + i + 1,
                        codesRemain - i - 1, currentDepth + 1, codesDest + i, correction,
                        queuePool, digraphs, digraphsSize);

                // Copy the second char of the digraph in place, then continue processing on
                // the remaining part of the word.
                // In our example, after "pru" in the buffer copy the "e", and continue on "fen"
                memcpy(codesDest + i, codesSrc + i, BYTES_IN_ONE_CHAR);
                getWordWithDigraphSuggestionsRec(proximityInfo, xcoordinates, ycoordinates,
                        codesBuffer, xCoordinatesBuffer, yCoordinatesBuffer, codesBufferSize,
                        bigramMap, bigramFilter, useFullEditDistance, codesSrc + i, codesRemain - i,
                        currentDepth + 1, codesDest + i, correction, queuePool, digraphs,
                        digraphsSize);
                return;
            }
        }
    }

    // If we come here, we hit the end of the word: let's check it against the dictionary.
    // In our example, we'll come here once for "prufen" and then once for "pruefen".
    // If the word contains several digraphs, we'll come it for the product of them.
    // eg. if the word is "ueberpruefen" we'll test, in order, against
    // "uberprufen", "uberpruefen", "ueberprufen", "ueberpruefen".
    const unsigned int remainingBytes = BYTES_IN_ONE_CHAR * codesRemain;
    if (0 != remainingBytes) {
        memcpy(codesDest, codesSrc, remainingBytes);
        memcpy(&xCoordinatesBuffer[startIndex], &xcoordinates[codesBufferSize - codesRemain],
                sizeof(int) * codesRemain);
        memcpy(&yCoordinatesBuffer[startIndex], &ycoordinates[codesBufferSize - codesRemain],
                sizeof(int) * codesRemain);
    }

    getWordSuggestions(proximityInfo, xCoordinatesBuffer, yCoordinatesBuffer, codesBuffer,
            startIndex + codesRemain, bigramMap, bigramFilter, useFullEditDistance, correction,
            queuePool);
}

// bigramMap contains the association <bigram address> -> <bigram frequency>
// bigramFilter is a bloom filter for fast rejection: see functions setInFilter and isInFilter
// in bigram_dictionary.cpp
int UnigramDictionary::getSuggestions(ProximityInfo *proximityInfo,
        WordsPriorityQueuePool *queuePool, Correction *correction, const int *xcoordinates,
        const int *ycoordinates, const int *codes, const int codesSize,
        const std::map<int, int> *bigramMap, const uint8_t *bigramFilter,
        const bool useFullEditDistance, unsigned short *outWords, int *frequencies) {

    queuePool->clearAll();
    Correction* masterCorrection = correction;
    correction->resetCorrection();
    if (BinaryFormat::REQUIRES_GERMAN_UMLAUT_PROCESSING & FLAGS)
    { // Incrementally tune the word and try all possibilities
        int codesBuffer[getCodesBufferSize(codes, codesSize)];
        int xCoordinatesBuffer[codesSize];
        int yCoordinatesBuffer[codesSize];
        getWordWithDigraphSuggestionsRec(proximityInfo, xcoordinates, ycoordinates, codesBuffer,
                xCoordinatesBuffer, yCoordinatesBuffer, codesSize, bigramMap, bigramFilter,
                useFullEditDistance, codes, codesSize, 0, codesBuffer, masterCorrection,
                queuePool, GERMAN_UMLAUT_DIGRAPHS,
                sizeof(GERMAN_UMLAUT_DIGRAPHS) / sizeof(GERMAN_UMLAUT_DIGRAPHS[0]));
    } else if (BinaryFormat::REQUIRES_FRENCH_LIGATURES_PROCESSING & FLAGS) {
        int codesBuffer[getCodesBufferSize(codes, codesSize)];
        int xCoordinatesBuffer[codesSize];
        int yCoordinatesBuffer[codesSize];
        getWordWithDigraphSuggestionsRec(proximityInfo, xcoordinates, ycoordinates, codesBuffer,
                xCoordinatesBuffer, yCoordinatesBuffer, codesSize, bigramMap, bigramFilter,
                useFullEditDistance, codes, codesSize, 0, codesBuffer, masterCorrection,
                queuePool, FRENCH_LIGATURES_DIGRAPHS,
                sizeof(FRENCH_LIGATURES_DIGRAPHS) / sizeof(FRENCH_LIGATURES_DIGRAPHS[0]));
    /*} else if (BinaryFormat::REQUIRES_VIETNAMESE_LIGATURES_PROCESSING & FLAGS) {
        int codesBuffer[getCodesBufferSize(codes, codesSize)];
        int xCoordinatesBuffer[codesSize];
        int yCoordinatesBuffer[codesSize];
		AKLOGI("Trying to get suggestions the Vietnamese way.");
        getWordWithVietnameseSuggestionsRec(proximityInfo, xcoordinates, ycoordinates, codesBuffer,
                xCoordinatesBuffer, yCoordinatesBuffer, codesSize, bigramMap, bigramFilter,
                useFullEditDistance, codes, codesSize, 0, codesBuffer, masterCorrection,
                queuePool, VIETNAMESE_LIGATURES_POSSIBILITIES,
                sizeof(VIETNAMESE_LIGATURES_POSSIBILITIES) / sizeof(VIETNAMESE_LIGATURES_POSSIBILITIES[0])); */
    } else { // Normal processing
        getWordSuggestions(proximityInfo, xcoordinates, ycoordinates, codes, codesSize,
                bigramMap, bigramFilter, useFullEditDistance, masterCorrection, queuePool);
    }

    PROF_START(20);
    if (DEBUG_DICT) {
        float ns = queuePool->getMasterQueue()->getHighestNormalizedScore(
                proximityInfo->getPrimaryInputWord(), codesSize, 0, 0, 0);
        ns += 0;
        AKLOGI("Max normalized score = %f", ns);
    }
    const int suggestedWordsCount =
            queuePool->getMasterQueue()->outputSuggestions(
                    proximityInfo->getPrimaryInputWord(), codesSize, frequencies, outWords);

    if (DEBUG_DICT) {
        float ns = queuePool->getMasterQueue()->getHighestNormalizedScore(
                proximityInfo->getPrimaryInputWord(), codesSize, 0, 0, 0);
        ns += 0;
        AKLOGI("Returning %d words", suggestedWordsCount);
        /// Print the returned words
        for (int j = 0; j < suggestedWordsCount; ++j) {
            short unsigned int* w = outWords + j * MAX_WORD_LENGTH;
            char s[MAX_WORD_LENGTH];
            for (int i = 0; i <= MAX_WORD_LENGTH; i++) s[i] = w[i];
            AKLOGI("%s %i", s, frequencies[j]);
        }
    }
    PROF_END(20);
    PROF_CLOSE;
    return suggestedWordsCount;
}

void UnigramDictionary::getWordSuggestions(ProximityInfo *proximityInfo,
        const int *xcoordinates, const int *ycoordinates, const int *codes,
        const int inputLength, const std::map<int, int> *bigramMap, const uint8_t *bigramFilter,
        const bool useFullEditDistance, Correction *correction, WordsPriorityQueuePool *queuePool) {

    PROF_OPEN;
    PROF_START(0);
    PROF_END(0);

    PROF_START(1);
    getOneWordSuggestions(proximityInfo, xcoordinates, ycoordinates, codes, bigramMap, bigramFilter,
            useFullEditDistance, inputLength, correction, queuePool);
    PROF_END(1);

    PROF_START(2);
    // Note: This line is intentionally left blank
    PROF_END(2);

    PROF_START(3);
    // Note: This line is intentionally left blank
    PROF_END(3);

    PROF_START(4);
    bool hasAutoCorrectionCandidate = false;
    WordsPriorityQueue* masterQueue = queuePool->getMasterQueue();
    if (masterQueue->size() > 0) {
        float nsForMaster = masterQueue->getHighestNormalizedScore(
                proximityInfo->getPrimaryInputWord(), inputLength, 0, 0, 0);
        hasAutoCorrectionCandidate = (nsForMaster > START_TWO_WORDS_CORRECTION_THRESHOLD);
    }
    PROF_END(4);

    PROF_START(5);
    // Multiple word suggestions
    if (SUGGEST_MULTIPLE_WORDS
            && inputLength >= MIN_USER_TYPED_LENGTH_FOR_MULTIPLE_WORD_SUGGESTION) {
        getSplitMultipleWordsSuggestions(proximityInfo, xcoordinates, ycoordinates, codes,
                useFullEditDistance, inputLength, correction, queuePool,
                hasAutoCorrectionCandidate);
    }
    PROF_END(5);

    PROF_START(6);
    // Note: This line is intentionally left blank
    PROF_END(6);
#ifndef DEBUG_DICT
#define DEBUG_DICT
#endif
    if (DEBUG_DICT) {
        queuePool->dumpSubQueue1TopSuggestions();
        for (int i = 0; i < SUB_QUEUE_MAX_COUNT; ++i) {
            WordsPriorityQueue* queue = queuePool->getSubQueue(FIRST_WORD_INDEX, i);
            if (queue->size() > 0) {
                WordsPriorityQueue::SuggestedWord* sw = queue->top();
                const int score = sw->mScore;
                const unsigned short* word = sw->mWord;
                const int wordLength = sw->mWordLength;
                float ns = Correction::RankingAlgorithm::calcNormalizedScore(
                        proximityInfo->getPrimaryInputWord(), i, word, wordLength, score);
                ns += 0;
                AKLOGI("--- TOP SUB WORDS for %d --- %d %f [%d]", i, score, ns,
                        (ns > TWO_WORDS_CORRECTION_WITH_OTHER_ERROR_THRESHOLD));
                DUMP_WORD(proximityInfo->getPrimaryInputWord(), i);
                DUMP_WORD(word, wordLength);
            }
        }
    }
}

void UnigramDictionary::initSuggestions(ProximityInfo *proximityInfo, const int *xCoordinates,
        const int *yCoordinates, const int *codes, const int inputLength, Correction *correction) {
    if (DEBUG_DICT) {
        AKLOGI("initSuggest");
        DUMP_WORD_INT(codes, inputLength);
    }
    proximityInfo->setInputParams(codes, inputLength, xCoordinates, yCoordinates);
    const int maxDepth = min(inputLength * MAX_DEPTH_MULTIPLIER, MAX_WORD_LENGTH);
    correction->initCorrection(proximityInfo, inputLength, maxDepth);
}

static const char QUOTE = '\'';
static const char SPACE = ' ';

void UnigramDictionary::getOneWordSuggestions(ProximityInfo *proximityInfo,
        const int *xcoordinates, const int *ycoordinates, const int *codes,
        const std::map<int, int> *bigramMap, const uint8_t *bigramFilter,
        const bool useFullEditDistance, const int inputLength,
        Correction *correction, WordsPriorityQueuePool *queuePool) {
    initSuggestions(proximityInfo, xcoordinates, ycoordinates, codes, inputLength, correction);
    getSuggestionCandidates(useFullEditDistance, inputLength, bigramMap, bigramFilter, correction,
            queuePool, true /* doAutoCompletion */, DEFAULT_MAX_ERRORS, FIRST_WORD_INDEX);
}

void UnigramDictionary::getSuggestionCandidates(const bool useFullEditDistance,
        const int inputLength, const std::map<int, int> *bigramMap, const uint8_t *bigramFilter,
        Correction *correction, WordsPriorityQueuePool *queuePool,
        const bool doAutoCompletion, const int maxErrors, const int currentWordIndex) {
    uint8_t totalTraverseCount = correction->pushAndGetTotalTraverseCount();
    if (DEBUG_DICT) {
        AKLOGI("Traverse count %d", totalTraverseCount);
    }
    if (totalTraverseCount > MULTIPLE_WORDS_SUGGESTION_MAX_TOTAL_TRAVERSE_COUNT) {
        if (DEBUG_DICT) {
            AKLOGI("Abort traversing %d", totalTraverseCount);
        }
        return;
    }
    // TODO: Remove setCorrectionParams
    correction->setCorrectionParams(0, 0, 0,
            -1 /* spaceProximityPos */, -1 /* missingSpacePos */, useFullEditDistance,
            doAutoCompletion, maxErrors);
    int rootPosition = ROOT_POS;
    // Get the number of children of root, then increment the position
    int childCount = BinaryFormat::getGroupCountAndForwardPointer(DICT_ROOT, &rootPosition);
    int outputIndex = 0;

    correction->initCorrectionState(rootPosition, childCount, (inputLength <= 0));

    // Depth first search
    while (outputIndex >= 0) {
        if (correction->initProcessState(outputIndex)) {
            int siblingPos = correction->getTreeSiblingPos(outputIndex);
            int firstChildPos;

            const bool needsToTraverseChildrenNodes = processCurrentNode(siblingPos,
                    bigramMap, bigramFilter, correction, &childCount, &firstChildPos, &siblingPos,
                    queuePool, currentWordIndex);
            // Update next sibling pos
            correction->setTreeSiblingPos(outputIndex, siblingPos);

            if (needsToTraverseChildrenNodes) {
                // Goes to child node
                outputIndex = correction->goDownTree(outputIndex, childCount, firstChildPos);
            }
        } else {
            // Goes to parent sibling node
            outputIndex = correction->getTreeParentIndex(outputIndex);
        }
    }
}

inline void UnigramDictionary::onTerminal(const int probability,
        const TerminalAttributes& terminalAttributes, Correction *correction,
        WordsPriorityQueuePool *queuePool, const bool addToMasterQueue,
        const int currentWordIndex) {
    const int inputIndex = correction->getInputIndex();
    const bool addToSubQueue = inputIndex < SUB_QUEUE_MAX_COUNT;

    int wordLength;
    unsigned short* wordPointer;

    if ((currentWordIndex == FIRST_WORD_INDEX) && addToMasterQueue) {
        WordsPriorityQueue *masterQueue = queuePool->getMasterQueue();
        const int finalProbability =
                correction->getFinalProbability(probability, &wordPointer, &wordLength);
        if (finalProbability != NOT_A_PROBABILITY) {
            addWord(wordPointer, wordLength, finalProbability, masterQueue);

            const int shortcutProbability = finalProbability > 0 ? finalProbability - 1 : 0;
            // Please note that the shortcut candidates will be added to the master queue only.
            TerminalAttributes::ShortcutIterator iterator =
                    terminalAttributes.getShortcutIterator();
            while (iterator.hasNextShortcutTarget()) {
                // TODO: addWord only supports weak ordering, meaning we have no means
                // to control the order of the shortcuts relative to one another or to the word.
                // We need to either modulate the probability of each shortcut according
                // to its own shortcut probability or to make the queue
                // so that the insert order is protected inside the queue for words
                // with the same score. For the moment we use -1 to make sure the shortcut will
                // never be in front of the word.
                uint16_t shortcutTarget[MAX_WORD_LENGTH_INTERNAL];
                const int shortcutTargetStringLength = iterator.getNextShortcutTarget(
                        MAX_WORD_LENGTH_INTERNAL, shortcutTarget);
                addWord(shortcutTarget, shortcutTargetStringLength, shortcutProbability,
                        masterQueue);
            }
        }
    }

    // We only allow two words + other error correction for words with SUB_QUEUE_MIN_WORD_LENGTH
    // or more length.
    if (inputIndex >= SUB_QUEUE_MIN_WORD_LENGTH && addToSubQueue) {
        WordsPriorityQueue *subQueue;
        subQueue = queuePool->getSubQueue(currentWordIndex, inputIndex);
        if (!subQueue) {
            return;
        }
        const int finalProbability = correction->getFinalProbabilityForSubQueue(
                probability, &wordPointer, &wordLength, inputIndex);
        addWord(wordPointer, wordLength, finalProbability, subQueue);
    }
}

int UnigramDictionary::getSubStringSuggestion(
        ProximityInfo *proximityInfo, const int *xcoordinates, const int *ycoordinates,
        const int *codes, const bool useFullEditDistance, Correction *correction,
        WordsPriorityQueuePool* queuePool, const int inputLength,
        const bool hasAutoCorrectionCandidate, const int currentWordIndex,
        const int inputWordStartPos, const int inputWordLength,
        const int outputWordStartPos, const bool isSpaceProximity, int *freqArray,
        int*wordLengthArray, unsigned short* outputWord, int *outputWordLength) {
    if (inputWordLength > MULTIPLE_WORDS_SUGGESTION_MAX_WORD_LENGTH) {
        return FLAG_MULTIPLE_SUGGEST_ABORT;
    }

    /////////////////////////////////////////////
    // safety net for multiple word suggestion //
    // TODO: Remove this safety net            //
    /////////////////////////////////////////////
    int smallWordCount = 0;
    int singleLetterWordCount = 0;
    if (inputWordLength == 1) {
        ++singleLetterWordCount;
    }
    if (inputWordLength <= 2) {
        // small word == single letter or 2-letter word
        ++smallWordCount;
    }
    for (int i = 0; i < currentWordIndex; ++i) {
        const int length = wordLengthArray[i];
        if (length == 1) {
            ++singleLetterWordCount;
            // Safety net to avoid suggesting sequential single letter words
            if (i < (currentWordIndex - 1)) {
                if (wordLengthArray[i + 1] == 1) {
                    return FLAG_MULTIPLE_SUGGEST_ABORT;
                }
            } else if (inputWordLength == 1) {
                return FLAG_MULTIPLE_SUGGEST_ABORT;
            }
        }
        if (length <= 2) {
            ++smallWordCount;
        }
        // Safety net to avoid suggesting multiple words with many (4 or more, for now) small words
        if (singleLetterWordCount >= 3 || smallWordCount >= 4) {
            return FLAG_MULTIPLE_SUGGEST_ABORT;
        }
    }
    //////////////////////////////////////////////
    // TODO: Remove the safety net above        //
    //////////////////////////////////////////////

    unsigned short* tempOutputWord = 0;
    int nextWordLength = 0;
    // TODO: Optimize init suggestion
    initSuggestions(proximityInfo, xcoordinates, ycoordinates, codes,
            inputLength, correction);

    int freq = getMostFrequentWordLike(
            inputWordStartPos, inputWordLength, proximityInfo, mWord);
    if (freq > 0) {
        nextWordLength = inputWordLength;
        tempOutputWord = mWord;
    } else if (!hasAutoCorrectionCandidate) {
        if (inputWordStartPos > 0) {
            const int offset = inputWordStartPos;
            initSuggestions(proximityInfo, &xcoordinates[offset], &ycoordinates[offset],
                    codes + offset, inputWordLength, correction);
            queuePool->clearSubQueue(currentWordIndex);
            // TODO: pass the bigram list for substring suggestion
            getSuggestionCandidates(useFullEditDistance, inputWordLength,
                    0 /* bigramMap */, 0 /* bigramFilter */, correction, queuePool,
                    false /* doAutoCompletion */, MAX_ERRORS_FOR_TWO_WORDS, currentWordIndex);
            if (DEBUG_DICT) {
                if (currentWordIndex < MULTIPLE_WORDS_SUGGESTION_MAX_WORDS) {
                    AKLOGI("Dump word candidates(%d) %d", currentWordIndex, inputWordLength);
                    for (int i = 0; i < SUB_QUEUE_MAX_COUNT; ++i) {
                        queuePool->getSubQueue(currentWordIndex, i)->dumpTopWord();
                    }
                }
            }
        }
        WordsPriorityQueue* queue = queuePool->getSubQueue(currentWordIndex, inputWordLength);
        // TODO: Return the correct value depending on doAutoCompletion
        if (!queue || queue->size() <= 0) {
            return FLAG_MULTIPLE_SUGGEST_ABORT;
        }
        int score = 0;
        const float ns = queue->getHighestNormalizedScore(
                proximityInfo->getPrimaryInputWord(), inputWordLength,
                &tempOutputWord, &score, &nextWordLength);
        if (DEBUG_DICT) {
            AKLOGI("NS(%d) = %f, Score = %d", currentWordIndex, ns, score);
        }
        // Two words correction won't be done if the score of the first word doesn't exceed the
        // threshold.
        if (ns < TWO_WORDS_CORRECTION_WITH_OTHER_ERROR_THRESHOLD
                || nextWordLength < SUB_QUEUE_MIN_WORD_LENGTH) {
            return FLAG_MULTIPLE_SUGGEST_SKIP;
        }
        freq = score >> (nextWordLength + TWO_WORDS_PLUS_OTHER_ERROR_CORRECTION_DEMOTION_DIVIDER);
    }
    if (DEBUG_DICT) {
        AKLOGI("Freq(%d): %d, length: %d, input length: %d, input start: %d (%d)"
                , currentWordIndex, freq, nextWordLength, inputWordLength, inputWordStartPos,
                wordLengthArray[0]);
    }
    if (freq <= 0 || nextWordLength <= 0
            || MAX_WORD_LENGTH <= (outputWordStartPos + nextWordLength)) {
        return FLAG_MULTIPLE_SUGGEST_SKIP;
    }
    for (int i = 0; i < nextWordLength; ++i) {
        outputWord[outputWordStartPos + i] = tempOutputWord[i];
    }

    // Put output values
    freqArray[currentWordIndex] = freq;
    // TODO: put output length instead of input length
    wordLengthArray[currentWordIndex] = inputWordLength;
    const int tempOutputWordLength = outputWordStartPos + nextWordLength;
    if (outputWordLength) {
        *outputWordLength = tempOutputWordLength;
    }

    if ((inputWordStartPos + inputWordLength) < inputLength) {
        if (outputWordStartPos + nextWordLength >= MAX_WORD_LENGTH) {
            return FLAG_MULTIPLE_SUGGEST_SKIP;
        }
        outputWord[tempOutputWordLength] = SPACE;
        if (outputWordLength) {
            ++*outputWordLength;
        }
    } else if (currentWordIndex >= 1) {
        // TODO: Handle 3 or more words
        const int pairFreq = correction->getFreqForSplitMultipleWords(
                freqArray, wordLengthArray, currentWordIndex + 1, isSpaceProximity, outputWord);
        if (DEBUG_DICT) {
            DUMP_WORD(outputWord, tempOutputWordLength);
            for (int i = 0; i < currentWordIndex + 1; ++i) {
                AKLOGI("Split %d,%d words: freq = %d, length = %d", i, currentWordIndex + 1,
                        freqArray[i], wordLengthArray[i]);
            }
            AKLOGI("Split two words: freq = %d, length = %d, %d, isSpace ? %d", pairFreq,
                    inputLength, tempOutputWordLength, isSpaceProximity);
        }
        addWord(outputWord, tempOutputWordLength, pairFreq, queuePool->getMasterQueue());
    }
    return FLAG_MULTIPLE_SUGGEST_CONTINUE;
}

void UnigramDictionary::getMultiWordsSuggestionRec(ProximityInfo *proximityInfo,
        const int *xcoordinates, const int *ycoordinates, const int *codes,
        const bool useFullEditDistance, const int inputLength,
        Correction *correction, WordsPriorityQueuePool* queuePool,
        const bool hasAutoCorrectionCandidate, const int startInputPos, const int startWordIndex,
        const int outputWordLength, int *freqArray, int* wordLengthArray,
        unsigned short* outputWord) {
    if (startWordIndex >= (MULTIPLE_WORDS_SUGGESTION_MAX_WORDS - 1)) {
        // Return if the last word index
        return;
    }
    if (startWordIndex >= 1
            && (hasAutoCorrectionCandidate
                    || inputLength < MIN_INPUT_LENGTH_FOR_THREE_OR_MORE_WORDS_CORRECTION)) {
        // Do not suggest 3+ words if already has auto correction candidate
        return;
    }
    for (int i = startInputPos + 1; i < inputLength; ++i) {
        if (DEBUG_CORRECTION_FREQ) {
            AKLOGI("Multi words(%d), start in %d sep %d start out %d",
                    startWordIndex, startInputPos, i, outputWordLength);
            DUMP_WORD(outputWord, outputWordLength);
        }
        int tempOutputWordLength = 0;
        // Current word
        int inputWordStartPos = startInputPos;
        int inputWordLength = i - startInputPos;
        const int suggestionFlag = getSubStringSuggestion(proximityInfo, xcoordinates, ycoordinates,
                codes, useFullEditDistance, correction, queuePool, inputLength,
                hasAutoCorrectionCandidate, startWordIndex, inputWordStartPos, inputWordLength,
                outputWordLength, true /* not used */, freqArray, wordLengthArray, outputWord,
                &tempOutputWordLength);
        if (suggestionFlag == FLAG_MULTIPLE_SUGGEST_ABORT) {
            // TODO: break here
            continue;
        } else if (suggestionFlag == FLAG_MULTIPLE_SUGGEST_SKIP) {
            continue;
        }

        if (DEBUG_CORRECTION_FREQ) {
            AKLOGI("Do missing space correction");
        }
        // Next word
        // Missing space
        inputWordStartPos = i;
        inputWordLength = inputLength - i;
        if(getSubStringSuggestion(proximityInfo, xcoordinates, ycoordinates, codes,
                useFullEditDistance, correction, queuePool, inputLength, hasAutoCorrectionCandidate,
                startWordIndex + 1, inputWordStartPos, inputWordLength, tempOutputWordLength,
                false /* missing space */, freqArray, wordLengthArray, outputWord, 0)
                        != FLAG_MULTIPLE_SUGGEST_CONTINUE) {
            getMultiWordsSuggestionRec(proximityInfo, xcoordinates, ycoordinates, codes,
                    useFullEditDistance, inputLength, correction, queuePool,
                    hasAutoCorrectionCandidate, inputWordStartPos, startWordIndex + 1,
                    tempOutputWordLength, freqArray, wordLengthArray, outputWord);
        }

        // Mistyped space
        ++inputWordStartPos;
        --inputWordLength;

        if (inputWordLength <= 0) {
            continue;
        }

        const int x = xcoordinates[inputWordStartPos - 1];
        const int y = ycoordinates[inputWordStartPos - 1];
        if (!proximityInfo->hasSpaceProximity(x, y)) {
            continue;
        }

        if (DEBUG_CORRECTION_FREQ) {
            AKLOGI("Do mistyped space correction");
        }
        getSubStringSuggestion(proximityInfo, xcoordinates, ycoordinates, codes,
                useFullEditDistance, correction, queuePool, inputLength, hasAutoCorrectionCandidate,
                startWordIndex + 1, inputWordStartPos, inputWordLength, tempOutputWordLength,
                true /* mistyped space */, freqArray, wordLengthArray, outputWord, 0);
    }
}

void UnigramDictionary::getSplitMultipleWordsSuggestions(ProximityInfo *proximityInfo,
        const int *xcoordinates, const int *ycoordinates, const int *codes,
        const bool useFullEditDistance, const int inputLength,
        Correction *correction, WordsPriorityQueuePool* queuePool,
        const bool hasAutoCorrectionCandidate) {
    if (inputLength >= MAX_WORD_LENGTH) return;
    if (DEBUG_DICT) {
        AKLOGI("--- Suggest multiple words");
    }

    // Allocating fixed length array on stack
    unsigned short outputWord[MAX_WORD_LENGTH];
    int freqArray[MULTIPLE_WORDS_SUGGESTION_MAX_WORDS];
    int wordLengthArray[MULTIPLE_WORDS_SUGGESTION_MAX_WORDS];
    const int outputWordLength = 0;
    const int startInputPos = 0;
    const int startWordIndex = 0;
    getMultiWordsSuggestionRec(proximityInfo, xcoordinates, ycoordinates, codes,
            useFullEditDistance, inputLength, correction, queuePool, hasAutoCorrectionCandidate,
            startInputPos, startWordIndex, outputWordLength, freqArray, wordLengthArray,
            outputWord);
}

// Wrapper for getMostFrequentWordLikeInner, which matches it to the previous
// interface.
inline int UnigramDictionary::getMostFrequentWordLike(const int startInputIndex,
        const int inputLength, ProximityInfo *proximityInfo, unsigned short *word) {
    uint16_t inWord[inputLength];

    for (int i = 0; i < inputLength; ++i) {
        inWord[i] = (uint16_t)proximityInfo->getPrimaryCharAt(startInputIndex + i);
    }
    return getMostFrequentWordLikeInner(inWord, inputLength, word);
}

// This function will take the position of a character array within a CharGroup,
// and check it actually like-matches the word in inWord starting at startInputIndex,
// that is, it matches it with case and accents squashed.
// The function returns true if there was a full match, false otherwise.
// The function will copy on-the-fly the characters in the CharGroup to outNewWord.
// It will also place the end position of the array in outPos; in outInputIndex,
// it will place the index of the first char AFTER the match if there was a match,
// and the initial position if there was not. It makes sense because if there was
// a match we want to continue searching, but if there was not, we want to go to
// the next CharGroup.
// In and out parameters may point to the same location. This function takes care
// not to use any input parameters after it wrote into its outputs.
static inline bool testCharGroupForContinuedLikeness(const uint8_t flags,
        const uint8_t* const root, const int startPos,
        const uint16_t* const inWord, const int startInputIndex,
        int32_t* outNewWord, int* outInputIndex, int* outPos) {
    const bool hasMultipleChars = (0 != (UnigramDictionary::FLAG_HAS_MULTIPLE_CHARS & flags));
    int pos = startPos;
    int32_t character = BinaryFormat::getCharCodeAndForwardPointer(root, &pos);
    int32_t baseChar = toBaseLowerCase(character);
    const uint16_t wChar = toBaseLowerCase(inWord[startInputIndex]);

    if (baseChar != wChar) {
        *outPos = hasMultipleChars ? BinaryFormat::skipOtherCharacters(root, pos) : pos;
        *outInputIndex = startInputIndex;
        return false;
    }
    int inputIndex = startInputIndex;
    outNewWord[inputIndex] = character;
    if (hasMultipleChars) {
        character = BinaryFormat::getCharCodeAndForwardPointer(root, &pos);
        while (NOT_A_CHARACTER != character) {
            baseChar = toBaseLowerCase(character);
            if (toBaseLowerCase(inWord[++inputIndex]) != baseChar) {
                *outPos = BinaryFormat::skipOtherCharacters(root, pos);
                *outInputIndex = startInputIndex;
                return false;
            }
            outNewWord[inputIndex] = character;
            character = BinaryFormat::getCharCodeAndForwardPointer(root, &pos);
        }
    }
    *outInputIndex = inputIndex + 1;
    *outPos = pos;
    return true;
}

// This function is invoked when a word like the word searched for is found.
// It will compare the frequency to the max frequency, and if greater, will
// copy the word into the output buffer. In output value maxFreq, it will
// write the new maximum frequency if it changed.
static inline void onTerminalWordLike(const int freq, int32_t* newWord, const int length,
        short unsigned int* outWord, int* maxFreq) {
    if (freq > *maxFreq) {
        for (int q = 0; q < length; ++q)
            outWord[q] = newWord[q];
        outWord[length] = 0;
        *maxFreq = freq;
    }
}

// Will find the highest frequency of the words like the one passed as an argument,
// that is, everything that only differs by case/accents.
int UnigramDictionary::getMostFrequentWordLikeInner(const uint16_t * const inWord,
        const int length, short unsigned int* outWord) {
    int32_t newWord[MAX_WORD_LENGTH_INTERNAL];
    int depth = 0;
    int maxFreq = -1;
    const uint8_t* const root = DICT_ROOT;

    int startPos = 0;
    mStackChildCount[0] = BinaryFormat::getGroupCountAndForwardPointer(root, &startPos);
    mStackInputIndex[0] = 0;
    mStackSiblingPos[0] = startPos;
    while (depth >= 0) {
        const int charGroupCount = mStackChildCount[depth];
        int pos = mStackSiblingPos[depth];
        for (int charGroupIndex = charGroupCount - 1; charGroupIndex >= 0; --charGroupIndex) {
            int inputIndex = mStackInputIndex[depth];
            const uint8_t flags = BinaryFormat::getFlagsAndForwardPointer(root, &pos);
            // Test whether all chars in this group match with the word we are searching for. If so,
            // we want to traverse its children (or if the length match, evaluate its frequency).
            // Note that this function will output the position regardless, but will only write
            // into inputIndex if there is a match.
            const bool isAlike = testCharGroupForContinuedLikeness(flags, root, pos, inWord,
                    inputIndex, newWord, &inputIndex, &pos);
            if (isAlike && (FLAG_IS_TERMINAL & flags) && (inputIndex == length)) {
                const int frequency = BinaryFormat::readFrequencyWithoutMovingPointer(root, pos);
                onTerminalWordLike(frequency, newWord, inputIndex, outWord, &maxFreq);
            }
            pos = BinaryFormat::skipFrequency(flags, pos);
            const int siblingPos = BinaryFormat::skipChildrenPosAndAttributes(root, flags, pos);
            const int childrenNodePos = BinaryFormat::readChildrenPosition(root, flags, pos);
            // If we had a match and the word has children, we want to traverse them. We don't have
            // to traverse words longer than the one we are searching for, since they will not match
            // anyway, so don't traverse unless inputIndex < length.
            if (isAlike && (-1 != childrenNodePos) && (inputIndex < length)) {
                // Save position for this depth, to get back to this once children are done
                mStackChildCount[depth] = charGroupIndex;
                mStackSiblingPos[depth] = siblingPos;
                // Prepare stack values for next depth
                ++depth;
                int childrenPos = childrenNodePos;
                mStackChildCount[depth] =
                        BinaryFormat::getGroupCountAndForwardPointer(root, &childrenPos);
                mStackSiblingPos[depth] = childrenPos;
                mStackInputIndex[depth] = inputIndex;
                pos = childrenPos;
                // Go to the next depth level.
                ++depth;
                break;
            } else {
                // No match, or no children, or word too long to ever match: go the next sibling.
                pos = siblingPos;
            }
        }
        --depth;
    }
    return maxFreq;
}

int UnigramDictionary::getFrequency(const int32_t* const inWord, const int length) const {
    const uint8_t* const root = DICT_ROOT;
    int pos = BinaryFormat::getTerminalPosition(root, inWord, length);
    if (NOT_VALID_WORD == pos) {
        return NOT_A_PROBABILITY;
    }
    const uint8_t flags = BinaryFormat::getFlagsAndForwardPointer(root, &pos);
    const bool hasMultipleChars = (0 != (FLAG_HAS_MULTIPLE_CHARS & flags));
    if (hasMultipleChars) {
        pos = BinaryFormat::skipOtherCharacters(root, pos);
    } else {
        BinaryFormat::getCharCodeAndForwardPointer(DICT_ROOT, &pos);
    }
    const int unigramFreq = BinaryFormat::readFrequencyWithoutMovingPointer(root, pos);
    return unigramFreq;
}

// TODO: remove this function.
int UnigramDictionary::getBigramPosition(int pos, unsigned short *word, int offset,
        int length) const {
    return -1;
}

// ProcessCurrentNode returns a boolean telling whether to traverse children nodes or not.
// If the return value is false, then the caller should read in the output "nextSiblingPosition"
// to find out the address of the next sibling node and pass it to a new call of processCurrentNode.
// It is worthy to note that when false is returned, the output values other than
// nextSiblingPosition are undefined.
// If the return value is true, then the caller must proceed to traverse the children of this
// node. processCurrentNode will output the information about the children: their count in
// newCount, their position in newChildrenPosition, the traverseAllNodes flag in
// newTraverseAllNodes, the match weight into newMatchRate, the input index into newInputIndex, the
// diffs into newDiffs, the sibling position in nextSiblingPosition, and the output index into
// newOutputIndex. Please also note the following caveat: processCurrentNode does not know when
// there aren't any more nodes at this level, it merely returns the address of the first byte after
// the current node in nextSiblingPosition. Thus, the caller must keep count of the nodes at any
// given level, as output into newCount when traversing this level's parent.
inline bool UnigramDictionary::processCurrentNode(const int initialPos,
        const std::map<int, int> *bigramMap, const uint8_t *bigramFilter, Correction *correction,
        int *newCount, int *newChildrenPosition, int *nextSiblingPosition,
        WordsPriorityQueuePool *queuePool, const int currentWordIndex) {
    if (DEBUG_DICT) {
        correction->checkState();
    }
    int pos = initialPos;

    // Flags contain the following information:
    // - Address type (MASK_GROUP_ADDRESS_TYPE) on two bits:
    //   - FLAG_GROUP_ADDRESS_TYPE_{ONE,TWO,THREE}_BYTES means there are children and their address
    //     is on the specified number of bytes.
    //   - FLAG_GROUP_ADDRESS_TYPE_NOADDRESS means there are no children, and therefore no address.
    // - FLAG_HAS_MULTIPLE_CHARS: whether this node has multiple char or not.
    // - FLAG_IS_TERMINAL: whether this node is a terminal or not (it may still have children)
    // - FLAG_HAS_BIGRAMS: whether this node has bigrams or not
    const uint8_t flags = BinaryFormat::getFlagsAndForwardPointer(DICT_ROOT, &pos);
    const bool hasMultipleChars = (0 != (FLAG_HAS_MULTIPLE_CHARS & flags));
    const bool isTerminalNode = (0 != (FLAG_IS_TERMINAL & flags));

    bool needsToInvokeOnTerminal = false;

    // This gets only ONE character from the stream. Next there will be:
    // if FLAG_HAS_MULTIPLE CHARS: the other characters of the same node
    // else if FLAG_IS_TERMINAL: the frequency
    // else if MASK_GROUP_ADDRESS_TYPE is not NONE: the children address
    // Note that you can't have a node that both is not a terminal and has no children.
    int32_t c = BinaryFormat::getCharCodeAndForwardPointer(DICT_ROOT, &pos);
    assert(NOT_A_CHARACTER != c);

    // We are going to loop through each character and make it look like it's a different
    // node each time. To do that, we will process characters in this node in order until
    // we find the character terminator. This is signalled by getCharCode* returning
    // NOT_A_CHARACTER.
    // As a special case, if there is only one character in this node, we must not read the
    // next bytes so we will simulate the NOT_A_CHARACTER return by testing the flags.
    // This way, each loop run will look like a "virtual node".
    do {
        // We prefetch the next char. If 'c' is the last char of this node, we will have
        // NOT_A_CHARACTER in the next char. From this we can decide whether this virtual node
        // should behave as a terminal or not and whether we have children.
        const int32_t nextc = hasMultipleChars
                ? BinaryFormat::getCharCodeAndForwardPointer(DICT_ROOT, &pos) : NOT_A_CHARACTER;
        const bool isLastChar = (NOT_A_CHARACTER == nextc);
        // If there are more chars in this nodes, then this virtual node is not a terminal.
        // If we are on the last char, this virtual node is a terminal if this node is.
        const bool isTerminal = isLastChar && isTerminalNode;

        Correction::CorrectionType stateType = correction->processCharAndCalcState(
                c, isTerminal);
        if (stateType == Correction::TRAVERSE_ALL_ON_TERMINAL
                || stateType == Correction::ON_TERMINAL) {
            needsToInvokeOnTerminal = true;
        } else if (stateType == Correction::UNRELATED || correction->needsToPrune()) {
            // We found that this is an unrelated character, so we should give up traversing
            // this node and its children entirely.
            // However we may not be on the last virtual node yet so we skip the remaining
            // characters in this node, the frequency if it's there, read the next sibling
            // position to output it, then return false.
            // We don't have to output other values because we return false, as in
            // "don't traverse children".
            if (!isLastChar) {
                pos = BinaryFormat::skipOtherCharacters(DICT_ROOT, pos);
            }
            pos = BinaryFormat::skipFrequency(flags, pos);
            *nextSiblingPosition =
                    BinaryFormat::skipChildrenPosAndAttributes(DICT_ROOT, flags, pos);
            return false;
        }

        // Prepare for the next character. Promote the prefetched char to current char - the loop
        // will take care of prefetching the next. If we finally found our last char, nextc will
        // contain NOT_A_CHARACTER.
        c = nextc;
    } while (NOT_A_CHARACTER != c);

    if (isTerminalNode) {
        // The frequency should be here, because we come here only if this is actually
        // a terminal node, and we are on its last char.
        const int unigramFreq = BinaryFormat::readFrequencyWithoutMovingPointer(DICT_ROOT, pos);
        const int childrenAddressPos = BinaryFormat::skipFrequency(flags, pos);
        const int attributesPos = BinaryFormat::skipChildrenPosition(flags, childrenAddressPos);
        TerminalAttributes terminalAttributes(DICT_ROOT, flags, attributesPos);
        // bigramMap contains the bigram frequencies indexed by addresses for fast lookup.
        // bigramFilter is a bloom filter of said frequencies for even faster rejection.
        const int probability = BinaryFormat::getProbability(initialPos, bigramMap, bigramFilter,
                unigramFreq);
        onTerminal(probability, terminalAttributes, correction, queuePool, needsToInvokeOnTerminal,
                currentWordIndex);

        // If there are more chars in this node, then this virtual node has children.
        // If we are on the last char, this virtual node has children if this node has.
        const bool hasChildren = BinaryFormat::hasChildrenInFlags(flags);

        // This character matched the typed character (enough to traverse the node at least)
        // so we just evaluated it. Now we should evaluate this virtual node's children - that
        // is, if it has any. If it has no children, we're done here - so we skip the end of
        // the node, output the siblings position, and return false "don't traverse children".
        // Note that !hasChildren implies isLastChar, so we know we don't have to skip any
        // remaining char in this group for there can't be any.
        if (!hasChildren) {
            pos = BinaryFormat::skipFrequency(flags, pos);
            *nextSiblingPosition =
                    BinaryFormat::skipChildrenPosAndAttributes(DICT_ROOT, flags, pos);
            return false;
        }

        // Optimization: Prune out words that are too long compared to how much was typed.
        if (correction->needsToPrune()) {
            pos = BinaryFormat::skipFrequency(flags, pos);
            *nextSiblingPosition =
                    BinaryFormat::skipChildrenPosAndAttributes(DICT_ROOT, flags, pos);
            if (DEBUG_DICT_FULL) {
                AKLOGI("Traversing was pruned.");
            }
            return false;
        }
    }

    // Now we finished processing this node, and we want to traverse children. If there are no
    // children, we can't come here.
    assert(BinaryFormat::hasChildrenInFlags(flags));

    // If this node was a terminal it still has the frequency under the pointer (it may have been
    // read, but not skipped - see readFrequencyWithoutMovingPointer).
    // Next come the children position, then possibly attributes (attributes are bigrams only for
    // now, maybe something related to shortcuts in the future).
    // Once this is read, we still need to output the number of nodes in the immediate children of
    // this node, so we read and output it before returning true, as in "please traverse children".
    pos = BinaryFormat::skipFrequency(flags, pos);
    int childrenPos = BinaryFormat::readChildrenPosition(DICT_ROOT, flags, pos);
    *nextSiblingPosition = BinaryFormat::skipChildrenPosAndAttributes(DICT_ROOT, flags, pos);
    *newCount = BinaryFormat::getGroupCountAndForwardPointer(DICT_ROOT, &childrenPos);
    *newChildrenPosition = childrenPos;
    return true;
}

} // namespace latinime
