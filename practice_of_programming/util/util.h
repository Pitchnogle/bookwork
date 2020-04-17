#ifndef UTIL_h
#define UTIL_h

// eprintf: print error message and exit
void eprintf(char *, ...);

// weprintf: print warning message
void weprintf(char *, ...);

// estrdup: duplicate string with exit on error
char *estrdup(char *);

// emalloc: malloc with exit on error
void *emalloc(size_t);

// erealloc: realloc with exit on error
void *erealloc(void *, size_t);

// progname: get program name
char *progname(void);

// setprogname: set program name
void setprogname(char *);

#endif // UTIL_h
