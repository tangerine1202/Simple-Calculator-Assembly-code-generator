#ifndef STRUCT_VARS_H
#define STRUCT_VARS_H

#define MAXLEN 256
#define TBLSIZE 64
#define MAXREG 8

typedef enum
{
    MISPAREN,
    NOTNUMID,
    NOTFOUND,
    RUNOUT,
    FACROT_ORANDXOR,
    REG_RUNOUT,
    DIV_BY_ZERO,
    VAR_UNASSIGNED,
    CANT_GET_ADDR,
    UNEXPECT_TOKENTYPE,
    WRONG_ADDR,
    NULL_VALUE,
    NULL_NODE,
    NULL_REGISTER, // maybe deprecate
    LEFT_SIDE_OF_ASSIGN_IS_NOT_ID,
    NO_ASSIGN_TOKEN,
} ErrorType;

typedef enum
{
    UNKNOWN,
    END,
    INT,
    ID,
    ORANDXOR,
    ADDSUB,
    MULDIV,
    ASSIGN,
    LPAREN,
    RPAREN,
    ENDFILE
} TokenSet;

typedef struct
{
    int val;
    int unknown_val;
} Value;

typedef struct _Node
{
    char lexeme[MAXLEN];
    TokenSet token;
    int val;
    int weight;
    struct _Node *left, *right;
} BTNode;

typedef struct
{
    char name[MAXLEN];
    int val;
    int unknown_val;
    int assigned;
} Symbol;

typedef struct
{
    char name[3]; // r0, r1, r2...
    int occupied;
} Register;

extern TokenSet lookahead;
extern char lexeme[MAXLEN];
extern Symbol sbtable[TBLSIZE];
extern int sbcount;
extern Register reg[MAXREG];

extern int DEBUG_MODE;
extern int reg_needed;
extern int total_clock_cycle;
extern int last_clock_cycle;

void error(ErrorType);

int getAddr(char *);
char *getAddrName(int);
int getAddrVal(int);
int getAddrUnknownVal(int);
int getAddrAssigned(int);

int max(int, int);
int min(int, int);

inline void charswap(char *, char *);
char *reverse(char *, int, int);
char *itoa(int, char *, int);

#endif