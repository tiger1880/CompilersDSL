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
#define SUM_ASSIGN_OP 278
#define SUB_ASSIGN_OP 279
#define EQUAL 280
#define STRING_TOKEN 281
#define ENDLINE 282
#define ID 283
#define FLOATS 284
#define TRICONSTRUCT 285
#define CIRCLECONSTRUCT 286
#define PARACONSTRUCT 287
#define REGPOLYCONSTRUCT 288
#define NOT 289
#define AND 290
#define OR 291
#define SCALE 292
#define CENTER 293
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char* name; 
    enum eletype eletype;  
    vector<char*>* nameList;
    vector<int>* dimList;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
