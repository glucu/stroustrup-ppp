Expression:
    PTerm
    Expression "|" PTerm
PTerm:
    STerm
    PTerm "^" STerm
STerm:
    Unary
    STerm "&" Unary
Unary:
    Primary
    "!" Primary
    "~" Primary
Primary:
    Number
    "(" Expression ")"
Number:
    integer-number
