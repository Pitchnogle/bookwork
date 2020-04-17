#ifndef UTIL_h
#define UTIL_h

// eprintf: print error message and exit
void eprintf(char *, ...);

// weprintf: print warning message
void weprintf(char *, ...);

// estrdup: 
char *estrdup(char *);

// emalloc: 
void *emalloc(size_t);

// erealloc: 
void *erealloc(void *, size_t);

// progname: 
char *progname(void);

// setprogname: 
void setprogname(char *);

#endif // UTIL_h
