/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.c"

int g_addr = 100;
int i=1,lnum1=0;
int stack[100],index1=0,end[100],arr[10],ct,c,b,fl,top=0,label[20],label_num=0,ltop=0;
char st1[100][10];
char temp_count[2]="0";
int plist[100],flist[100],k=-1,errc=0,j=0;
char temp[2]="t";
char null[2]=" ";
void yyerror(char *s);
int printline();
extern int yylineno;
void scope_start()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}
void scope_end()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
void if1()
{
	label_num++;
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = not %s\n",temp,st1[top]);
 	printf("if %s goto L%d\n",temp,label_num);
	temp_count[0]++;
	label[++ltop]=label_num;

}
void if2()
{
	label_num++;
	printf("\ngoto L%d\n",label_num);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=label_num;
}
void if3()
{
	printf("\nL%d:\n",label[ltop--]);
}
void while1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void while2()
{
	label_num++;
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,label_num);
	temp_count[0]++;
	label[++ltop]=label_num;
}
void while3()
{
	int y=label[ltop--];
	printf("\ngoto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}
void dowhile1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void dowhile2()
{
 	printf("\nif %s goto L%d\n",st1[top--],label[ltop--]);
}
void for1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void for2()
{
	label_num++;
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,label_num);
	temp_count[0]++;
	label[++ltop]=label_num;
	label_num++;
	printf("goto L%d\n",label_num);
	label[++ltop]=label_num;
	label_num++;
	printf("L%d:\n",label_num);
	label[++ltop]=label_num;
}
void for3()
{
	printf("\ngoto L%d\n",label[ltop-3]);
	printf("L%d:\n",label[ltop-1]);
}
void for4()
{
	printf("\ngoto L%d\n",label[ltop]);
	printf("L%d:\n",label[ltop-2]);
	ltop-=4;
}
void push(char *a)
{
	strcpy(st1[++top],a);
}
void array1()
{
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = %s\n",temp,st1[top]);
	strcpy(st1[top],temp);
	temp_count[0]++;
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);
	top--;
	strcpy(st1[top],temp);
	temp_count[0]++;
}
void codegen()
{
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);
	top-=2;
	strcpy(st1[top],temp);
	temp_count[0]++;
}
void codegen_umin()
{
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = -%s\n",temp,st1[top]);
	top--;
	strcpy(st1[top],temp);
	temp_count[0]++;
}
void codegen_assign()
{
	printf("\n%s = %s\n",st1[top-2],st1[top]);
	top-=2;
}

#line 231 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    ID = 261,                      /* ID  */
    NUM = 262,                     /* NUM  */
    REAL = 263,                    /* REAL  */
    WHILE = 264,                   /* WHILE  */
    IF = 265,                      /* IF  */
    RETURN = 266,                  /* RETURN  */
    PREPROC = 267,                 /* PREPROC  */
    LE = 268,                      /* LE  */
    STRING = 269,                  /* STRING  */
    PRINT = 270,                   /* PRINT  */
    FUNCTION = 271,                /* FUNCTION  */
    DO = 272,                      /* DO  */
    ARRAY = 273,                   /* ARRAY  */
    ELSE = 274,                    /* ELSE  */
    STRUCT = 275,                  /* STRUCT  */
    STRUCT_VAR = 276,              /* STRUCT_VAR  */
    FOR = 277,                     /* FOR  */
    GE = 278,                      /* GE  */
    EQ = 279,                      /* EQ  */
    NE = 280,                      /* NE  */
    INC = 281,                     /* INC  */
    DEC = 282,                     /* DEC  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    NEQ = 285,                     /* NEQ  */
    UMINUS = 286                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define WHILE 264
#define IF 265
#define RETURN 266
#define PREPROC 267
#define LE 268
#define STRING 269
#define PRINT 270
#define FUNCTION 271
#define DO 272
#define ARRAY 273
#define ELSE 274
#define STRUCT 275
#define STRUCT_VAR 276
#define FOR 277
#define GE 278
#define EQ 279
#define NE 280
#define INC 281
#define DEC 282
#define AND 283
#define OR 284
#define NEQ 285
#define UMINUS 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 171 "parser.y"

		int ival;
		char *str;
	

#line 349 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_NUM = 7,                        /* NUM  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_PREPROC = 12,                   /* PREPROC  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_PRINT = 15,                     /* PRINT  */
  YYSYMBOL_FUNCTION = 16,                  /* FUNCTION  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_ARRAY = 18,                     /* ARRAY  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_STRUCT = 20,                    /* STRUCT  */
  YYSYMBOL_STRUCT_VAR = 21,                /* STRUCT_VAR  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_INC = 26,                       /* INC  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_start = 48,                     /* start  */
  YYSYMBOL_Function = 49,                  /* Function  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_parameter = 51,                 /* parameter  */
  YYSYMBOL_Type = 52,                      /* Type  */
  YYSYMBOL_CompoundStmt = 53,              /* CompoundStmt  */
  YYSYMBOL_StmtList = 54,                  /* StmtList  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_dowhile = 56,                   /* dowhile  */
  YYSYMBOL_57_1 = 57,                      /* $@1  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_for = 59,                       /* for  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_if = 63,                        /* if  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_else = 66,                      /* else  */
  YYSYMBOL_while = 67,                     /* while  */
  YYSYMBOL_68_8 = 68,                      /* $@8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_assignment = 70,                /* assignment  */
  YYSYMBOL_assignment1 = 71,               /* assignment1  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_consttype = 75,                 /* consttype  */
  YYSYMBOL_Declaration = 76,               /* Declaration  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_79_15 = 79,                     /* $@15  */
  YYSYMBOL_array = 80,                     /* array  */
  YYSYMBOL_81_16 = 81,                     /* $@16  */
  YYSYMBOL_E = 82,                         /* E  */
  YYSYMBOL_83_17 = 83,                     /* $@17  */
  YYSYMBOL_84_18 = 84,                     /* $@18  */
  YYSYMBOL_85_19 = 85,                     /* $@19  */
  YYSYMBOL_86_20 = 86,                     /* $@20  */
  YYSYMBOL_87_21 = 87,                     /* $@21  */
  YYSYMBOL_88_22 = 88,                     /* $@22  */
  YYSYMBOL_89_23 = 89,                     /* $@23  */
  YYSYMBOL_90_24 = 90,                     /* $@24  */
  YYSYMBOL_91_25 = 91,                     /* $@25  */
  YYSYMBOL_92_26 = 92,                     /* $@26  */
  YYSYMBOL_93_27 = 93,                     /* $@27  */
  YYSYMBOL_94_28 = 94,                     /* $@28  */
  YYSYMBOL_95_29 = 95,                     /* $@29  */
  YYSYMBOL_96_30 = 96,                     /* $@30  */
  YYSYMBOL_97_31 = 97,                     /* $@31  */
  YYSYMBOL_98_32 = 98,                     /* $@32  */
  YYSYMBOL_99_33 = 99,                     /* $@33  */
  YYSYMBOL_100_34 = 100,                   /* $@34  */
  YYSYMBOL_101_35 = 101,                   /* $@35  */
  YYSYMBOL_102_36 = 102,                   /* $@36  */
  YYSYMBOL_T = 103,                        /* T  */
  YYSYMBOL_104_37 = 104,                   /* $@37  */
  YYSYMBOL_105_38 = 105,                   /* $@38  */
  YYSYMBOL_F = 106,                        /* F  */
  YYSYMBOL_107_39 = 107                    /* $@39  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    37,    35,    41,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      31,    33,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   177,   177,   178,   179,   180,   183,   202,   221,   222,
     225,   228,   229,   230,   233,   236,   237,   240,   241,   242,
     243,   244,   245,   246,   252,   253,   260,   261,   262,   265,
     265,   265,   268,   268,   268,   268,   271,   271,   271,   274,
     275,   278,   278,   278,   281,   282,   283,   284,   285,   286,
     289,   289,   289,   289,   306,   310,   311,   315,   318,   319,
     322,   322,   322,   322,   353,   365,   395,   396,   400,   404,
     407,   407,   410,   410,   411,   411,   412,   413,   413,   413,
     414,   414,   414,   415,   415,   415,   416,   416,   416,   417,
     417,   417,   418,   418,   418,   419,   419,   419,   420,   420,
     420,   421,   421,   421,   422,   424,   424,   425,   425,   426,
     428,   429,   429,   430,   431
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "VOID",
  "ID", "NUM", "REAL", "WHILE", "IF", "RETURN", "PREPROC", "LE", "STRING",
  "PRINT", "FUNCTION", "DO", "ARRAY", "ELSE", "STRUCT", "STRUCT_VAR",
  "FOR", "GE", "EQ", "NE", "INC", "DEC", "AND", "OR", "NEQ", "'<'", "'>'",
  "'='", "UMINUS", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "','", "'{'",
  "'}'", "';'", "'['", "']'", "$accept", "start", "Function",
  "parameter_list", "parameter", "Type", "CompoundStmt", "StmtList",
  "stmt", "dowhile", "$@1", "$@2", "for", "$@3", "$@4", "$@5", "if", "$@6",
  "$@7", "else", "while", "$@8", "$@9", "assignment", "assignment1",
  "$@10", "$@11", "$@12", "consttype", "Declaration", "$@13", "$@14",
  "$@15", "array", "$@16", "E", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30",
  "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "T", "$@37", "$@38", "F",
  "$@39", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-102)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,   -66,   -66,   -66,   -66,    82,   -66,   -66,   167,    20,
      31,   167,    48,     4,    23,   167,    70,    70,    58,   -66,
       3,   -66,   -66,    -3,   -66,    70,   -66,    25,   -66,    71,
     -66,    55,   187,     7,   129,    95,   -66,    98,    17,   -66,
     150,   115,   118,    28,   -66,   155,    22,   117,   124,   -66,
     -66,    77,   -66,    17,   -66,   -66,    44,    66,   -66,   121,
     125,   -66,   -66,   118,   135,   -66,   112,   129,   129,   132,
     129,    17,   133,   164,   157,   158,   151,   161,   154,   165,
     166,   168,    26,   -21,   -66,   -66,   -66,   -66,   -66,   -66,
     142,   -66,   -66,   -66,   -66,   -66,   -66,   -66,    44,    17,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,    26,    26,    26,    26,    53,   -66,   160,     0,
     163,   -66,   169,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   153,    -8,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    66,    66,   -66,   -66,   170,   172,    17,
     156,   -66,   159,   190,   118,    17,   -66,   -66,    44,    44,
      44,    44,    44,    44,    44,    44,    44,   162,    17,    76,
     -66,   -66,   173,   196,    44,   -66,    78,   -66,   171,   175,
     174,   -66,   118,   -66,    17,    17,   118,   -66,    94,    44,
     -66,   193,   -66,   176,   118,   -66,   177,    17,   -66,   -66,
      44,   179,   118,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    69,    11,    12,    13,    50,    58,    59,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     3,
       0,     1,     2,    60,    64,     0,     4,    56,    54,     0,
      51,     0,     0,     0,     0,     0,    55,     0,     0,    68,
       0,     0,     0,     0,     9,     0,    48,     0,    49,    61,
      66,   113,   111,     0,   114,   104,    52,    76,   109,    60,
       0,    16,     6,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    74,    53,   105,   107,    67,
       0,     7,     8,    44,    45,    46,    65,    47,    62,     0,
      78,    81,    84,    87,    90,    93,    96,    99,   102,   113,
     112,   110,     0,     0,     0,     0,    50,    41,     0,     0,
       0,    29,     0,    14,    26,    28,    15,    21,    22,    18,
      20,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    75,   106,   108,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    63,    71,    79,    82,
      85,    88,    91,    94,    97,   100,   103,     0,     0,     0,
      25,    23,     0,     0,    32,    19,     0,    36,     0,     0,
       0,    42,     0,    27,     0,     0,     0,    37,     0,    33,
      43,    40,    30,     0,     0,    38,     0,     0,    39,    31,
      34,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,    59,   -66,   -66,   145,   -29,   -61,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -27,    35,   -66,   -66,   -66,     5,   -31,
     -66,   -66,   -66,   -66,   -66,   -53,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    42,   -66,   -66,   -65,
     -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    43,    44,    12,    62,    90,   126,   127,
     154,   196,   128,   180,   193,   201,   129,   182,   191,   195,
     130,   148,   186,    47,    13,    18,    38,    86,    54,    15,
      35,    71,   132,    55,    72,    56,   112,   113,    73,   134,
      74,   135,    75,   136,    76,   137,    77,   138,    78,   139,
      79,   140,    80,   141,    81,   142,    57,   114,   115,    58,
      82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    41,    91,    40,    45,    14,   150,     6,     7,    31,
       2,     3,     4,    14,    84,    85,    14,   110,    98,   111,
      14,    14,    14,    51,     6,     7,    20,    84,    85,   125,
      14,    21,   109,     6,     7,    45,    33,    14,   157,    48,
      94,    95,    34,    97,   151,    32,   133,    42,    24,   145,
     146,    28,    29,    52,    23,    66,    53,    67,   -50,   131,
      36,    40,    52,    68,    25,    53,    16,    19,    63,    64,
      22,    93,    48,    48,    26,    48,    27,     6,     7,    84,
      85,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     -77,    30,   147,   173,    16,    14,   169,   -56,    17,    39,
     -80,   -83,   174,    87,    88,   -89,   -92,   -86,   -95,   -98,
    -101,    84,    85,    84,    85,   176,   177,    37,   181,     6,
       7,   187,   -70,    16,   152,   190,   -56,    17,    49,    84,
      85,   188,   189,   198,   192,    46,     6,     7,     2,     3,
       4,   203,    50,     1,   200,     2,     3,     4,   116,     6,
       7,   117,   118,   119,   143,   144,    59,   120,    60,   121,
      61,    65,     9,    69,   122,    70,    34,    -5,     1,    89,
       2,     3,     4,     5,     6,     7,    96,   100,    99,     8,
     101,   103,   102,   105,    61,   123,   124,     9,     1,   104,
       2,     3,     4,     5,     6,     7,   106,   156,   107,   149,
     170,   108,   153,   171,   172,   179,   175,     9,   155,    92,
     167,   168,   194,   178,   184,   183,     0,     0,   185,   202,
     197,   199
};

static const yytype_int16 yycheck[] =
{
      53,    32,    63,    32,    33,     0,     6,     7,     8,     6,
       3,     4,     5,     8,    35,    36,    11,    82,    71,    40,
      15,    16,    17,     6,     7,     8,     6,    35,    36,    90,
      25,     0,     6,     7,     8,    64,    39,    32,    46,    34,
      67,    68,    45,    70,    44,    42,    99,    40,    44,   114,
     115,    16,    17,    36,     6,    33,    39,    35,    33,    90,
      25,    90,    36,    41,    41,    39,    41,     8,    40,    41,
      11,    66,    67,    68,    15,    70,     6,     7,     8,    35,
      36,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      13,    33,    39,   154,    41,    90,   149,    44,    45,    44,
      23,    24,   155,    37,    38,    28,    29,    30,    31,    32,
      33,    35,    36,    35,    36,   168,    40,    46,    40,     7,
       8,   182,    45,    41,   119,   186,    44,    45,    33,    35,
      36,   184,   185,   194,    40,     6,     7,     8,     3,     4,
       5,   202,    44,     1,   197,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   112,   113,     6,    15,    43,    17,
      42,     6,    20,    46,    22,    41,    45,     0,     1,    44,
       3,     4,     5,     6,     7,     8,    44,    13,    45,    12,
      23,    30,    24,    29,    42,    43,    44,    20,     1,    28,
       3,     4,     5,     6,     7,     8,    31,    44,    32,    39,
      44,    33,    39,    44,    14,     9,    44,    20,    39,    64,
      40,    39,    19,    40,    39,    44,    -1,    -1,    44,    40,
      44,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    12,    20,
      48,    49,    52,    71,    75,    76,    41,    45,    72,    48,
       6,     0,    48,     6,    44,    41,    48,     6,    71,    71,
      33,     6,    42,    39,    45,    77,    71,    46,    73,    44,
      52,    76,    40,    50,    51,    52,     6,    70,    75,    33,
      44,     6,    36,    39,    75,    80,    82,   103,   106,     6,
      43,    42,    53,    40,    41,     6,    33,    35,    41,    46,
      41,    78,    81,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   107,    82,    35,    36,    74,    37,    38,    44,
      54,    53,    51,    75,    70,    70,    44,    70,    82,    45,
      13,    23,    24,    30,    28,    29,    31,    32,    33,     6,
     106,    40,    83,    84,   104,   105,     6,     9,    10,    11,
      15,    17,    22,    43,    44,    53,    55,    56,    59,    63,
      67,    76,    79,    82,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   103,   103,   106,   106,    39,    68,    39,
       6,    44,    75,    39,    57,    39,    44,    46,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    40,    39,    82,
      44,    44,    14,    53,    82,    44,    82,    40,    40,     9,
      60,    40,    64,    44,    39,    44,    69,    53,    82,    82,
      53,    65,    40,    61,    19,    66,    58,    44,    53,    44,
      82,    62,    40,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    52,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    57,
      58,    56,    60,    61,    62,    59,    64,    65,    63,    66,
      66,    68,    69,    67,    70,    70,    70,    70,    70,    70,
      72,    73,    74,    71,    71,    71,    71,    71,    75,    75,
      77,    78,    79,    76,    76,    76,    76,    76,    76,    76,
      81,    80,    83,    82,    84,    82,    82,    85,    86,    82,
      87,    88,    82,    89,    90,    82,    91,    92,    82,    93,
      94,    82,    95,    96,    82,    97,    98,    82,    99,   100,
      82,   101,   102,    82,    82,   104,   103,   105,   103,   103,
     106,   107,   106,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     3,     1,
       2,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     1,     1,     3,     2,     3,     1,     5,     1,     0,
       0,     9,     0,     0,     0,    12,     0,     0,     8,     2,
       0,     0,     0,     7,     3,     3,     3,     3,     1,     1,
       0,     0,     0,     6,     3,     3,     1,     1,     1,     1,
       0,     0,     0,     8,     2,     6,     5,     6,     4,     1,
       0,     5,     0,     4,     0,     4,     1,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     1,     0,     4,     0,     4,     1,
       3,     0,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* Function: Type ID '(' ')' CompoundStmt  */
#line 183 "parser.y"
                                        {
	if(strcmp((yyvsp[-3].str),"main")!=0)
	{
		printf("goto F%d\n",lnum1);
	}
	if ((yyvsp[-4].ival)!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
	else
	{
		insert((yyvsp[-3].str),FUNCTION);
		insert((yyvsp[-3].str),(yyvsp[-4].ival));
		g_addr+=4;
	}
	}
#line 1603 "y.tab.c"
    break;

  case 7: /* Function: Type ID '(' parameter_list ')' CompoundStmt  */
#line 202 "parser.y"
                                                       {
	if ((yyvsp[-5].ival)!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline()); errc++;
	}

	if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") && strcmp	((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
	{printf("Error : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());errc++;}
	else
	{
		insert((yyvsp[-4].str),FUNCTION);
		insert((yyvsp[-4].str),(yyvsp[-5].ival));
		for(j=0;j<=k;j++)
		{insertp((yyvsp[-4].str),plist[j]);}
					k=-1;
	}
	}
#line 1625 "y.tab.c"
    break;

  case 10: /* parameter: Type ID  */
#line 225 "parser.y"
                    {plist[++k]=(yyvsp[-1].ival);insert((yyvsp[0].str),(yyvsp[-1].ival));insertscope((yyvsp[0].str),i);}
#line 1631 "y.tab.c"
    break;

  case 23: /* stmt: RETURN consttype ';'  */
#line 246 "parser.y"
                               {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
						storereturn(ct,FLOAT);
					else
						storereturn(ct,INT); ct++;
					}
#line 1642 "y.tab.c"
    break;

  case 24: /* stmt: RETURN ';'  */
#line 252 "parser.y"
                     {storereturn(ct,VOID); ct++;}
#line 1648 "y.tab.c"
    break;

  case 25: /* stmt: RETURN ID ';'  */
#line 253 "parser.y"
                        {
          int sct=returnscope((yyvsp[-1].str),stack[top-1]);	//stack[top-1] - current scope
		      int type=returntype((yyvsp[-1].str),sct);
          if (type==259) storereturn(ct,FLOAT);
          else storereturn(ct,INT);
          ct++;
    }
#line 1660 "y.tab.c"
    break;

  case 29: /* $@1: %empty  */
#line 265 "parser.y"
             {dowhile1();}
#line 1666 "y.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 265 "parser.y"
                                                        {dowhile2();}
#line 1672 "y.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 268 "parser.y"
                    {for1();}
#line 1678 "y.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 268 "parser.y"
                                    {for2();}
#line 1684 "y.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 268 "parser.y"
                                                   {for3();}
#line 1690 "y.tab.c"
    break;

  case 35: /* for: FOR '(' E $@3 ';' E $@4 ';' E $@5 ')' CompoundStmt  */
#line 268 "parser.y"
                                                                              {for4();}
#line 1696 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 271 "parser.y"
                      {if1();}
#line 1702 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 271 "parser.y"
                                            {if2();}
#line 1708 "y.tab.c"
    break;

  case 39: /* else: ELSE CompoundStmt  */
#line 274 "parser.y"
                         {if3();}
#line 1714 "y.tab.c"
    break;

  case 41: /* $@8: %empty  */
#line 278 "parser.y"
              {while1();}
#line 1720 "y.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 278 "parser.y"
                                   {while2();}
#line 1726 "y.tab.c"
    break;

  case 43: /* while: WHILE $@8 '(' E ')' $@9 CompoundStmt  */
#line 278 "parser.y"
                                                            {while3();}
#line 1732 "y.tab.c"
    break;

  case 50: /* $@10: %empty  */
#line 289 "parser.y"
                 {push((yyvsp[0].str));}
#line 1738 "y.tab.c"
    break;

  case 51: /* $@11: %empty  */
#line 289 "parser.y"
                                 {strcpy(st1[++top],"=");}
#line 1744 "y.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 289 "parser.y"
                                                             {codegen_assign();}
#line 1750 "y.tab.c"
    break;

  case 53: /* assignment1: ID $@10 '=' $@11 E $@12  */
#line 290 "parser.y"
        {
		int sct=returnscope((yyvsp[-5].str),stack[index1-1]);
		int type=returntype((yyvsp[-5].str),sct);
		if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup((yyvsp[-5].str)))
		{
			int currscope=stack[index1-1];
			int scope=returnscope((yyvsp[-5].str),currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
			{
				check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
			}
		}
		}
#line 1770 "y.tab.c"
    break;

  case 54: /* assignment1: ID ',' assignment1  */
#line 306 "parser.y"
                                {
					if(lookup((yyvsp[-2].str)))
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
				}
#line 1779 "y.tab.c"
    break;

  case 56: /* assignment1: ID  */
#line 311 "parser.y"
              {
		if(lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		}
#line 1788 "y.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 322 "parser.y"
                      {push((yyvsp[0].str));}
#line 1794 "y.tab.c"
    break;

  case 61: /* $@14: %empty  */
#line 322 "parser.y"
                                      {strcpy(st1[++top],"=");}
#line 1800 "y.tab.c"
    break;

  case 62: /* $@15: %empty  */
#line 322 "parser.y"
                                                                  {codegen_assign();}
#line 1806 "y.tab.c"
    break;

  case 63: /* Declaration: Type ID $@13 '=' $@14 E $@15 ';'  */
#line 323 "parser.y"
        {
		if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0))
		{
			printf("\nError : Type Mismatch : Line %d\n",printline());
			fl=1;
		}
		if(!lookup((yyvsp[-6].str)))
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope((yyvsp[-6].str),currscope);
			if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline());
			else
			{
				insert_dup((yyvsp[-6].str),(yyvsp[-7].ival),currscope);
				check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
				int sg=returnscope((yyvsp[-6].str),stack[index1-1]);
				g_addr+=4;
			}
		}
		else
		{
			int scope=stack[index1-1];
			insert((yyvsp[-6].str),(yyvsp[-7].ival));
			insertscope((yyvsp[-6].str),scope);
			check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
			g_addr+=4;
		}
	}
#line 1840 "y.tab.c"
    break;

  case 64: /* Declaration: assignment1 ';'  */
#line 353 "parser.y"
                           {
				if(!lookup((yyvsp[-1].str)))
				{
					int currscope=stack[index1-1];
					int scope=returnscope((yyvsp[-1].str),currscope);
					if(!(scope<=currscope && end[scope]==0) || scope==0)
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 1856 "y.tab.c"
    break;

  case 65: /* Declaration: Type ID '[' assignment ']' ';'  */
#line 365 "parser.y"
                                                 {
			int itype;
			if(!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) { itype=259; } else itype = 258;
			if(itype!=258)
			{ printf("\nError : Array index must be of type int : Line %d\n",printline());errc++;}
			if(atoi((yyvsp[-2].str))<=0)
			{ printf("\nError : Array index must be of type int > 0 : Line %d\n",printline());errc++;}
			if(!lookup((yyvsp[-4].str)))
			{
				int currscope=stack[top-1];
				int previous_scope=returnscope((yyvsp[-4].str),currscope);
				if(currscope==previous_scope)
				{printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());errc++;}
				else
				{
					insert_dup((yyvsp[-4].str),ARRAY,currscope);
				insert_by_scope((yyvsp[-4].str),(yyvsp[-5].ival),currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
					if (itype==258) {insert_index((yyvsp[-4].str),(yyvsp[-2].str));}
				}
			}
			else
			{
				int scope=stack[top-1];
				insert((yyvsp[-4].str),ARRAY);
				insert((yyvsp[-4].str),(yyvsp[-5].ival));
				insertscope((yyvsp[-4].str),scope);
				if (itype==258) {insert_index((yyvsp[-4].str),(yyvsp[-2].str));}
			}
		}
#line 1890 "y.tab.c"
    break;

  case 67: /* Declaration: STRUCT ID '{' Declaration '}' ';'  */
#line 396 "parser.y"
                                            {
						insert((yyvsp[-4].str),STRUCT);
						g_addr+=4;
						}
#line 1899 "y.tab.c"
    break;

  case 68: /* Declaration: STRUCT ID ID ';'  */
#line 400 "parser.y"
                           {
				insert((yyvsp[-1].str),STRUCT_VAR);
				g_addr+=4;
				}
#line 1908 "y.tab.c"
    break;

  case 70: /* $@16: %empty  */
#line 407 "parser.y"
           {push((yyvsp[0].str));}
#line 1914 "y.tab.c"
    break;

  case 72: /* $@17: %empty  */
#line 410 "parser.y"
         {strcpy(st1[++top],"+");}
#line 1920 "y.tab.c"
    break;

  case 73: /* E: E '+' $@17 T  */
#line 410 "parser.y"
                                    {codegen();}
#line 1926 "y.tab.c"
    break;

  case 74: /* $@18: %empty  */
#line 411 "parser.y"
          {strcpy(st1[++top],"-");}
#line 1932 "y.tab.c"
    break;

  case 75: /* E: E '-' $@18 T  */
#line 411 "parser.y"
                                     {codegen();}
#line 1938 "y.tab.c"
    break;

  case 77: /* $@19: %empty  */
#line 413 "parser.y"
        {push((yyvsp[0].str));}
#line 1944 "y.tab.c"
    break;

  case 78: /* $@20: %empty  */
#line 413 "parser.y"
                       {strcpy(st1[++top],"<=");}
#line 1950 "y.tab.c"
    break;

  case 79: /* E: ID $@19 LE $@20 E  */
#line 413 "parser.y"
                                                    {codegen();}
#line 1956 "y.tab.c"
    break;

  case 80: /* $@21: %empty  */
#line 414 "parser.y"
        {push((yyvsp[0].str));}
#line 1962 "y.tab.c"
    break;

  case 81: /* $@22: %empty  */
#line 414 "parser.y"
                       {strcpy(st1[++top],">=");}
#line 1968 "y.tab.c"
    break;

  case 82: /* E: ID $@21 GE $@22 E  */
#line 414 "parser.y"
                                                    {codegen();}
#line 1974 "y.tab.c"
    break;

  case 83: /* $@23: %empty  */
#line 415 "parser.y"
        {push((yyvsp[0].str));}
#line 1980 "y.tab.c"
    break;

  case 84: /* $@24: %empty  */
#line 415 "parser.y"
                       {strcpy(st1[++top],"==");}
#line 1986 "y.tab.c"
    break;

  case 85: /* E: ID $@23 EQ $@24 E  */
#line 415 "parser.y"
                                                    {codegen();}
#line 1992 "y.tab.c"
    break;

  case 86: /* $@25: %empty  */
#line 416 "parser.y"
        {push((yyvsp[0].str));}
#line 1998 "y.tab.c"
    break;

  case 87: /* $@26: %empty  */
#line 416 "parser.y"
                        {strcpy(st1[++top],"!=");}
#line 2004 "y.tab.c"
    break;

  case 88: /* E: ID $@25 NEQ $@26 E  */
#line 416 "parser.y"
                                                     {codegen();}
#line 2010 "y.tab.c"
    break;

  case 89: /* $@27: %empty  */
#line 417 "parser.y"
        {push((yyvsp[0].str));}
#line 2016 "y.tab.c"
    break;

  case 90: /* $@28: %empty  */
#line 417 "parser.y"
                        {strcpy(st1[++top],"&&");}
#line 2022 "y.tab.c"
    break;

  case 91: /* E: ID $@27 AND $@28 E  */
#line 417 "parser.y"
                                                     {codegen();}
#line 2028 "y.tab.c"
    break;

  case 92: /* $@29: %empty  */
#line 418 "parser.y"
        {push((yyvsp[0].str));}
#line 2034 "y.tab.c"
    break;

  case 93: /* $@30: %empty  */
#line 418 "parser.y"
                       {strcpy(st1[++top],"||");}
#line 2040 "y.tab.c"
    break;

  case 94: /* E: ID $@29 OR $@30 E  */
#line 418 "parser.y"
                                                    {codegen();}
#line 2046 "y.tab.c"
    break;

  case 95: /* $@31: %empty  */
#line 419 "parser.y"
        {push((yyvsp[0].str));}
#line 2052 "y.tab.c"
    break;

  case 96: /* $@32: %empty  */
#line 419 "parser.y"
                        {strcpy(st1[++top],"<");}
#line 2058 "y.tab.c"
    break;

  case 97: /* E: ID $@31 '<' $@32 E  */
#line 419 "parser.y"
                                                    {codegen();}
#line 2064 "y.tab.c"
    break;

  case 98: /* $@33: %empty  */
#line 420 "parser.y"
        {push((yyvsp[0].str));}
#line 2070 "y.tab.c"
    break;

  case 99: /* $@34: %empty  */
#line 420 "parser.y"
                        {strcpy(st1[++top],">");}
#line 2076 "y.tab.c"
    break;

  case 100: /* E: ID $@33 '>' $@34 E  */
#line 420 "parser.y"
                                                    {codegen();}
#line 2082 "y.tab.c"
    break;

  case 101: /* $@35: %empty  */
#line 421 "parser.y"
        {push((yyvsp[0].str));}
#line 2088 "y.tab.c"
    break;

  case 102: /* $@36: %empty  */
#line 421 "parser.y"
                        {strcpy(st1[++top],"=");}
#line 2094 "y.tab.c"
    break;

  case 103: /* E: ID $@35 '=' $@36 E  */
#line 421 "parser.y"
                                                    {codegen_assign();}
#line 2100 "y.tab.c"
    break;

  case 104: /* E: array  */
#line 422 "parser.y"
           {array1();}
#line 2106 "y.tab.c"
    break;

  case 105: /* $@37: %empty  */
#line 424 "parser.y"
         {strcpy(st1[++top],"*");}
#line 2112 "y.tab.c"
    break;

  case 106: /* T: T '*' $@37 F  */
#line 424 "parser.y"
                                    {codegen();}
#line 2118 "y.tab.c"
    break;

  case 107: /* $@38: %empty  */
#line 425 "parser.y"
          {strcpy(st1[++top],"/");}
#line 2124 "y.tab.c"
    break;

  case 108: /* T: T '/' $@38 F  */
#line 425 "parser.y"
                                     {codegen();}
#line 2130 "y.tab.c"
    break;

  case 110: /* F: '(' E ')'  */
#line 428 "parser.y"
              {(yyval.str)=(yyvsp[-1].str);}
#line 2136 "y.tab.c"
    break;

  case 111: /* $@39: %empty  */
#line 429 "parser.y"
        {strcpy(st1[++top],"-");}
#line 2142 "y.tab.c"
    break;

  case 112: /* F: '-' $@39 F  */
#line 429 "parser.y"
                                   {codegen_umin();}
#line 2148 "y.tab.c"
    break;

  case 113: /* F: ID  */
#line 430 "parser.y"
        {push((yyvsp[0].str));fl=1;}
#line 2154 "y.tab.c"
    break;

  case 114: /* F: consttype  */
#line 431 "parser.y"
               {push((yyvsp[0].str));}
#line 2160 "y.tab.c"
    break;


#line 2164 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 434 "parser.y"


#include "lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}
