#ifndef charsetdetect_
#define charsetdetect_

/* The classes below are exported */
#if defined(_MSC_VER)
#  define LIB_EXPORT __declspec(dllexport)
#  define LIB_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#  define LIB_EXPORT /* */
#  define LIB_IMPORT /* */
#  pragma GCC visibility push(default)
#endif
#
#if defined(__cplusplus)
	extern "C" {
#endif

#ifdef _WINDLL
#  define LIBAPI LIB_EXPORT
#else
#  define LIBAPI LIB_IMPORT
#endif

// Opaque type of character set detectors
LIBAPI typedef void* csd_t;

// Create a new character set detector. Must be freed by csd_close.
// If creation fails, returns (csd_t)-1.
LIBAPI csd_t csd_open(void);

// Feeds some more data to the character set detector. Returns 0 if it
// needs more data to come to a conclusion and a positive number if it has enough to say what
// the character set is. Returns a negative number if there is an error.
LIBAPI int csd_consider(csd_t csd, const char *data, int length);

// Closes the character set detector and returns the detected character set name as an ASCII string.
// Returns NULL if detection failed.
LIBAPI const char *csd_close(csd_t csd);

#if defined(__cplusplus)
	}
#endif

#if defined(__GNUC__)
#  pragma GCC visibility pop
#endif

#endif
