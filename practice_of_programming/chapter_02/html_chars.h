typedef struct nameval_t nameval_t;
struct nameval_t {
  char *name;
  int   value;
};

nameval_t html_chars[] = {
  "&quot;",   0x22,
  "&amp;",    0x26,
  "&lt;",     0x3C,
  "&gt;",     0x3E,
  "&nbsp;",   0xA0,
  "&iexcl;",  0xA1,
  "&cent;",   0xA2,
  "&pound;",  0xA3,
  "&curren;", 0xA4,
  "&yen;",    0xA5,
  "&brvbar;", 0xA6,
  "&sect;",   0xA7,
  "&uml;",    0xA8,
  "&copy;",   0xA9,
  "&ordf;",   0xAA,
  "&laquo;",  0xAB,
  "&not;",    0xAC,
  "&shy;",    0xAD,
  "&reg;",    0xAE,
  "&macr;",   0xAF,
  "&deg;",    0xB0,
  "&plusmn;", 0xB1,
  "&sup2;",   0xB2,
  "&sup3;",   0xB3,
  "&acute;",  0xB4,
  "&micro;",  0xB5,
  "&para;",   0xB6,
  "&middot;", 0xB7,
  "&cedil;",  0xB8,
  "&sup1;",   0xB9,
  "&ordm;",   0xBA,
  "&raquo;",  0xBB,
  "&frac14;", 0xBC,
  "&frac12;", 0xBD,
  "&frac34;", 0xBE,
  "&iquest;", 0xBF,
  "&Agrave;", 0xC0,
  "&Aacute;", 0xC1,
  "&Acirc;",  0xC2,
  "&Atilde;", 0xC3,
  "&Auml;",   0xC4,
  "&Aring;",  0xC5,
  "&AElig;",  0xC6,
  "&Ccedil;", 0xC7,
  "&Egrave;", 0xC8,
  "&Eacute;", 0xC9,
  "&Ecirc;",  0xCA,
  "&Euml;",   0xCB,
  "&Igrave;", 0xCC,
  "&Iacute;", 0xCD,
  "&Icirc;",  0xCE,
  "&Iuml;",   0xCF,
  "&ETH;",    0xD0,
  "&Ntilde;", 0xD1,
  "&Ograve;", 0xD2,
  "&Oacute;", 0xD3,
  "&Ocirc;",  0xD4,
  "&Otilde;", 0xD5,
  "&Ouml;",   0xD6,
  "&times;",  0xD7,
  "&Oslash;", 0xD8,
  "&Ugrave;", 0xD9,
  "&Uacute;", 0xDA,
  "&Ucirc;",  0xDB,
  "&Uuml;",   0xDC,
  "&Yacute;", 0xDD,
  "&THORN;",  0xDE,
  "&szlig;",  0xDF,
  "&agrave;", 0xE0,
  "&aacute;", 0xE1,
  "&acirc;",  0xE2,
  "&atilde;", 0xE3,
  "&auml;",   0xE4,
  "&aring;",  0xE5,
  "&aelig;",  0xE6,
  "&ccedil;", 0xE7,
  "&egrave;", 0xE8,
  "&eacute;", 0xE9,
  "&ecirc;",  0xEA,
  "&euml;",   0xEB,
  "&igrave;", 0xEC,
  "&iacute;", 0xED,
  "&icirc;",  0xEE,
  "&iuml;",   0xEF,
  "&eth;",    0xF0,
  "&ntilde;", 0xF1,
  "&ograve;", 0xF2,
  "&oacute;", 0xF3,
  "&ocirc;",  0xF4,
  "&otilde;", 0xF5,
  "&ouml;",   0xF6,
  "&divide;", 0xF7,
  "&oslash;", 0xF8,
  "&ugrave;", 0xF9,
  "&uacute;", 0xFA,
  "&ucirc;",  0xFB,
  "&uuml;",   0xFC,
  "&yacute;", 0xFD,
  "&thorn;",  0xFE,
  "&yuml;",   0xFF
};