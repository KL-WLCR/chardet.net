/* The classes below are not exported */
#if defined(__GNUC__)
#  pragma GCC visibility push(hidden)
#endif

#include <stdio.h>
#include <stdlib.h>
#include "nscore.h"
#include "nsUniversalDetector.h"

class Detector : public nsUniversalDetector {
public:
	Detector(PRUint32 aLanguageFilter) : nsUniversalDetector(aLanguageFilter) {};
    int Consider(const char *data, int length);
    const char *Close(void);
protected:
	void Report(const char* aCharset);
    const char *mDetectedCharset;
};

#if defined(__GNUC__)
#  pragma GCC visibility pop
#endif
