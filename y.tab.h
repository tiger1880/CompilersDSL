#ifndef _yy_defines_h_
#define _yy_defines_h_

#define INTEGERS 257
#define LINE_OP 258
#define IF 259
#define ELIF 260
#define ELSE 261
#define FOR 262
#define WHILE 263
#define RETURN 264
#define VOID 265
#define CONTINUE 266
#define BREAK 267
#define PARALLEL 268
#define PERPENDICULAR 269
#define BOOLEAN 270
#define FUNC 271
#define FIG 272
#define UNARY 273
#define DATATYPE 274
#define CMP_OP 275
#define EQ_CMP_OP 276
#define ASSIGN_OP 277
#define EQUAL 278
#define STRING_TOKEN 279
#define ENDLINE 280
#define ID 281
#define FLOATS 282
#define CONSTRUCTOR 283
#define NOT 284
#define AND 285
#define OR 286
#define SCALE 287
#define CENTER 288
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char* name; 
    enum eletype Eletype;  
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
