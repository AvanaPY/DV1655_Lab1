// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 11 "parser.yy"

    #define YY_DECL yy::parser::symbol_type yylex()
    YY_DECL;
    Node* root;

#line 51 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 123 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 45: // Goal
      case 46: // MainClass
      case 47: // ClassDeclaration
      case 48: // VarDeclaration
      case 49: // MethodDeclaration
      case 50: // MethodBodyDeclaration
      case 51: // MethodArgumentDeclaration
      case 52: // MethodVarDeclaration
      case 53: // MethodStatementDeclaration
      case 54: // Type
      case 55: // Statement
      case 56: // Expression
      case 57: // FunctionCallDeclaration
      case 58: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 18: // T_Int
      case 19: // T_Bool
      case 20: // T_True
      case 21: // T_False
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 45: // Goal
      case 46: // MainClass
      case 47: // ClassDeclaration
      case 48: // VarDeclaration
      case 49: // MethodDeclaration
      case 50: // MethodBodyDeclaration
      case 51: // MethodArgumentDeclaration
      case 52: // MethodVarDeclaration
      case 53: // MethodStatementDeclaration
      case 54: // Type
      case 55: // Statement
      case 56: // Expression
      case 57: // FunctionCallDeclaration
      case 58: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 18: // T_Int
      case 19: // T_Bool
      case 20: // T_True
      case 21: // T_False
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 45: // Goal
      case 46: // MainClass
      case 47: // ClassDeclaration
      case 48: // VarDeclaration
      case 49: // MethodDeclaration
      case 50: // MethodBodyDeclaration
      case 51: // MethodArgumentDeclaration
      case 52: // MethodVarDeclaration
      case 53: // MethodStatementDeclaration
      case 54: // Type
      case 55: // Statement
      case 56: // Expression
      case 57: // FunctionCallDeclaration
      case 58: // Identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 18: // T_Int
      case 19: // T_Bool
      case 20: // T_True
      case 21: // T_False
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 45: // Goal
      case 46: // MainClass
      case 47: // ClassDeclaration
      case 48: // VarDeclaration
      case 49: // MethodDeclaration
      case 50: // MethodBodyDeclaration
      case 51: // MethodArgumentDeclaration
      case 52: // MethodVarDeclaration
      case 53: // MethodStatementDeclaration
      case 54: // Type
      case 55: // Statement
      case 56: // Expression
      case 57: // FunctionCallDeclaration
      case 58: // Identifier
        value.move< Node * > (that.value);
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 18: // T_Int
      case 19: // T_Bool
      case 20: // T_True
      case 21: // T_False
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 45: // Goal
      case 46: // MainClass
      case 47: // ClassDeclaration
      case 48: // VarDeclaration
      case 49: // MethodDeclaration
      case 50: // MethodBodyDeclaration
      case 51: // MethodArgumentDeclaration
      case 52: // MethodVarDeclaration
      case 53: // MethodStatementDeclaration
      case 54: // Type
      case 55: // Statement
      case 56: // Expression
      case 57: // FunctionCallDeclaration
      case 58: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 18: // T_Int
      case 19: // T_Bool
      case 20: // T_True
      case 21: // T_False
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 47 "parser.yy"
                                                 {
                                        yylhs.value.as < Node * > () = new Node("Program", "");
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                        root = yylhs.value.as < Node * > ();
                                        printf("r1 ");
                                    }
#line 673 "parser.tab.cc"
    break;

  case 3:
#line 56 "parser.yy"
                                                                                                                           {
                                                                    yylhs.value.as < Node * > () = new Node("MainClass", "");
                                                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    printf("r2 ");
                                                                }
#line 684 "parser.tab.cc"
    break;

  case 4:
#line 64 "parser.yy"
                                                                                {
                                            yylhs.value.as < Node * > () = new Node("Class", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r5 ");
                                        }
#line 696 "parser.tab.cc"
    break;

  case 5:
#line 71 "parser.yy"
                                                                                                  {
                                            yylhs.value.as < Node * > () = new Node("Class Extends", yystack_[4].value.as < Node * > ()->type);
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r6 ");
                                        }
#line 708 "parser.tab.cc"
    break;

  case 6:
#line 80 "parser.yy"
                                                         {
                                            yylhs.value.as < Node * > () = new Node("Var declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                            printf("r7 ");
                                        }
#line 719 "parser.tab.cc"
    break;

  case 7:
#line 86 "parser.yy"
                                          {
                                            yylhs.value.as < Node * > () = new Node("Var declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            printf("r8 ");
                                        }
#line 730 "parser.tab.cc"
    break;

  case 9:
#line 95 "parser.yy"
                                                                                                                                          {
                                yylhs.value.as < Node * > () = new Node("Type Method Declaration", yystack_[8].value.as < Node * > ()->type);
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                printf("r9 ");
                            }
#line 741 "parser.tab.cc"
    break;

  case 10:
#line 101 "parser.yy"
                                                                                                                        {
                                yylhs.value.as < Node * > () = new Node("Type Method Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                printf("r9 ");
                            }
#line 753 "parser.tab.cc"
    break;

  case 12:
#line 111 "parser.yy"
                                                                         {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r10 ");
                            }
#line 764 "parser.tab.cc"
    break;

  case 13:
#line 117 "parser.yy"
                                                                                 {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r11 ");
                            }
#line 775 "parser.tab.cc"
    break;

  case 14:
#line 123 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r12 ");
                            }
#line 785 "parser.tab.cc"
    break;

  case 15:
#line 128 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("Method Body-Statement Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r14 ");
                            }
#line 795 "parser.tab.cc"
    break;

  case 16:
#line 135 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); }
#line 801 "parser.tab.cc"
    break;

  case 17:
#line 136 "parser.yy"
                                             {
                                            yylhs.value.as < Node * > () = new Node("Method Arg Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r16 ");
                                        }
#line 812 "parser.tab.cc"
    break;

  case 18:
#line 144 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 818 "parser.tab.cc"
    break;

  case 19:
#line 145 "parser.yy"
                                             {
                                            yylhs.value.as < Node * > () = new Node("Method Var Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r19 ");
                                        }
#line 828 "parser.tab.cc"
    break;

  case 20:
#line 152 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 834 "parser.tab.cc"
    break;

  case 21:
#line 153 "parser.yy"
                                        {
                                            yylhs.value.as < Node * > () = new Node("Method Statement Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r21 ");
                                        }
#line 844 "parser.tab.cc"
    break;

  case 22:
#line 160 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                                printf("r22 ");
                            }
#line 853 "parser.tab.cc"
    break;

  case 23:
#line 164 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                                printf("r23 ");
                            }
#line 862 "parser.tab.cc"
    break;

  case 24:
#line 168 "parser.yy"
                             {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                                printf("r24 ");
                            }
#line 871 "parser.tab.cc"
    break;

  case 25:
#line 172 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("VOID", "");
                                printf("r25 ");
                            }
#line 880 "parser.tab.cc"
    break;

  case 26:
#line 176 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("IDENTIFIER", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r26 ");
                            }
#line 890 "parser.tab.cc"
    break;

  case 27:
#line 183 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r27 ");
                            }
#line 900 "parser.tab.cc"
    break;

  case 28:
#line 188 "parser.yy"
                                                                     {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r29 ");
                            }
#line 911 "parser.tab.cc"
    break;

  case 29:
#line 194 "parser.yy"
                                                           {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r30 ");
                            }
#line 922 "parser.tab.cc"
    break;

  case 30:
#line 200 "parser.yy"
                                                     {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r31 ");
                            }
#line 932 "parser.tab.cc"
    break;

  case 31:
#line 205 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r32 ");
                            }
#line 943 "parser.tab.cc"
    break;

  case 32:
#line 211 "parser.yy"
                                                                  {
                                yylhs.value.as < Node * > () = new Node("Assign []", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r33 ");
                            }
#line 955 "parser.tab.cc"
    break;

  case 33:
#line 220 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r34 ");
                            }
#line 966 "parser.tab.cc"
    break;

  case 34:
#line 226 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r35 ");
                            }
#line 977 "parser.tab.cc"
    break;

  case 35:
#line 232 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r36 ");
                            }
#line 988 "parser.tab.cc"
    break;

  case 36:
#line 238 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r37 ");
                            }
#line 999 "parser.tab.cc"
    break;

  case 37:
#line 244 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r38 ");
                            }
#line 1010 "parser.tab.cc"
    break;

  case 38:
#line 250 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r39 ");
                            }
#line 1021 "parser.tab.cc"
    break;

  case 39:
#line 256 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r40 ");
                            }
#line 1032 "parser.tab.cc"
    break;

  case 40:
#line 262 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r41 ");
                            }
#line 1043 "parser.tab.cc"
    break;

  case 41:
#line 268 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1054 "parser.tab.cc"
    break;

  case 42:
#line 274 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1065 "parser.tab.cc"
    break;

  case 43:
#line 280 "parser.yy"
                                           {
                                yylhs.value.as < Node * > () = new Node("LENGTH", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r43 ");
                            }
#line 1075 "parser.tab.cc"
    break;

  case 44:
#line 285 "parser.yy"
                                                                               {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r44 ");
                            }
#line 1087 "parser.tab.cc"
    break;

  case 45:
#line 292 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                                printf("r45 ");
                            }
#line 1096 "parser.tab.cc"
    break;

  case 46:
#line 296 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                                printf("r46 ");
                            }
#line 1105 "parser.tab.cc"
    break;

  case 47:
#line 300 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                                printf("r47 ");
                            }
#line 1114 "parser.tab.cc"
    break;

  case 48:
#line 304 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->type);
                                printf("r48 ");
                            }
#line 1123 "parser.tab.cc"
    break;

  case 49:
#line 308 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                                printf("r49 ");
                            }
#line 1132 "parser.tab.cc"
    break;

  case 50:
#line 312 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r50 ");
                            }
#line 1142 "parser.tab.cc"
    break;

  case 51:
#line 317 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r51 ");
                            }
#line 1152 "parser.tab.cc"
    break;

  case 52:
#line 322 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r52 ");
                            }
#line 1162 "parser.tab.cc"
    break;

  case 53:
#line 327 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r53 ");
                            }
#line 1172 "parser.tab.cc"
    break;

  case 54:
#line 334 "parser.yy"
                          { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 1178 "parser.tab.cc"
    break;

  case 55:
#line 335 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r54 ");
                            }
#line 1188 "parser.tab.cc"
    break;

  case 56:
#line 342 "parser.yy"
                                {
                                yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), "");
                                printf("r55 ");
                            }
#line 1197 "parser.tab.cc"
    break;

  case 57:
#line 346 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("MAIN", "");
                                printf("r56 ");
                            }
#line 1206 "parser.tab.cc"
    break;


#line 1210 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -60;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      11,    38,    28,    24,   -60,   -60,    18,   -60,    38,   -60,
      39,    -9,    70,    38,    50,    45,    49,   -60,    43,   -60,
     169,    38,   -60,    80,    50,    56,    50,    -4,    38,    54,
      60,   169,   -60,    38,    50,   -60,    68,   -60,    84,    -3,
      76,    38,   -60,    73,   -60,    50,    77,    78,     6,    38,
      50,    38,    79,    50,   -60,    36,    94,   218,    38,    82,
      99,    83,   100,   102,    22,    50,   182,    50,    22,   -60,
     -31,   -60,   218,    22,   150,   150,   150,    75,   -31,    98,
      50,    22,    50,   -60,   150,   150,   200,    95,   -60,   -60,
     -60,   -60,    66,   150,   150,   217,   -60,   238,   259,   -60,
     104,   280,   364,   101,   105,   103,   110,   301,   364,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,    22,
       2,    22,   -60,   -60,   106,   107,   -60,   150,   113,   -60,
     384,    74,   395,   405,   364,   364,   364,   364,   364,   322,
     136,   -60,   118,   -60,   150,   -60,   343,   -60,   -60,    22,
     150,   364,   -60,   -60,   364,    46,   -60,   150,   364
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    56,    57,     0,     1,     0,     2,
       0,     0,     0,     0,     8,     0,     0,    25,    22,    24,
      11,     0,    26,     0,     8,     0,     0,     0,     0,     0,
       0,    11,    23,     0,     0,     4,     0,     7,     0,     0,
       0,     0,     6,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     8,    15,    21,
      26,    16,     8,     0,     0,     0,     0,     0,     0,     0,
       8,    13,    18,    20,     0,     0,     0,     0,    45,    46,
      47,    49,     0,     0,     0,     0,    48,     0,     0,    27,
       0,     0,    31,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    10,     0,     0,     3,     0,     0,    53,
      38,    39,    40,    41,    33,    34,    37,    35,    36,     0,
       0,    43,     0,    29,     0,     9,     0,    51,    42,     0,
       0,    32,    50,    28,    55,     0,    44,     0,    54
  };

  const signed char
  parser::yypgoto_[] =
  {
     -60,   -60,   -60,   -60,    -6,   124,    85,   108,   -49,   -45,
     115,   -59,    12,   -60,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     9,    65,    27,    66,    48,    67,    68,
      21,    69,    95,   155,    96
  };

  const unsigned char
  parser::yytable_[] =
  {
       6,    13,    34,    34,    84,    77,     4,    11,    20,    83,
      85,     5,    16,    22,    87,   141,     1,    80,    31,    22,
      29,    81,    83,    22,    14,    22,     4,    36,     7,     8,
      22,     5,    40,    22,    35,    44,    61,    80,    62,    63,
      46,    81,     4,    52,    22,    12,    53,     5,    54,    22,
      56,    10,    22,    23,     4,    64,    70,    71,    17,     5,
     140,    82,   143,    78,    22,    70,    22,    78,    18,    19,
       4,    70,    78,    59,    82,     5,    53,    15,    25,    22,
      78,    22,    24,   156,   105,    70,   157,    97,    98,    30,
     153,   106,    32,    37,    38,    43,   101,   102,   111,   112,
     113,   114,   115,   116,   117,   107,   108,    42,    47,   118,
      45,    50,    57,    99,    51,    72,   120,    74,    78,   142,
      78,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    60,    73,   104,    75,    28,    76,   100,   127,   146,
     125,    33,   123,   126,   128,   145,    28,   144,    78,    41,
     147,   149,   150,    88,     4,    39,   151,    86,    55,     5,
      49,     0,   154,     0,     0,    49,     0,     0,    58,   158,
      89,    90,     0,     4,     0,    26,     0,    17,     5,     0,
      28,    91,    92,     0,    93,     0,     4,    18,    19,     0,
      17,     5,     0,    94,    79,     0,    61,    28,    62,    63,
      18,    19,     0,     0,     4,     0,     0,     0,    17,     5,
       0,     0,   103,     0,    61,    64,    62,    63,    18,    19,
       0,     0,     4,     0,     0,     0,    17,     5,     0,     0,
       0,     0,    61,    64,    62,    63,    18,    19,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,    64,   118,     0,   119,     0,     0,     0,     0,   120,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,   118,     0,   121,     0,     0,     0,     0,
     120,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,     0,   118,     0,   122,     0,     0,     0,
       0,   120,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,     0,   118,   124,     0,     0,     0,
       0,     0,   120,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,     0,     0,   118,     0,   129,     0,
       0,     0,     0,   120,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,     0,   118,   148,     0,
       0,     0,     0,     0,   120,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,     0,   118,   152,
       0,     0,     0,     0,     0,   120,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,   118,
       0,     0,     0,     0,     0,     0,   120,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,   118,
     112,   113,   114,   115,   116,   117,   120,     0,     0,     0,
     118,   113,   114,   115,   116,   117,     0,   120,     0,     0,
     118,     0,     0,     0,     0,     0,     0,   120
  };

  const short
  parser::yycheck_[] =
  {
       1,    10,     6,     6,    35,    64,     4,     8,    14,    68,
      41,     9,    13,    14,    73,    13,     5,    66,    24,    20,
      21,    66,    81,    24,    33,    26,     4,    28,     0,     5,
      31,     9,    33,    34,    38,    38,    14,    86,    16,    17,
      41,    86,     4,    37,    45,     6,    40,     9,    49,    50,
      51,    33,    53,     8,     4,    33,    57,    58,     8,     9,
     119,    67,   121,    64,    65,    66,    67,    68,    18,    19,
       4,    72,    73,    37,    80,     9,    40,     7,    35,    80,
      81,    82,    33,    37,    18,    86,    40,    75,    76,     9,
     149,    92,    36,    39,    34,    11,    84,    85,    24,    25,
      26,    27,    28,    29,    30,    93,    94,    39,    35,    35,
      34,    34,    33,    38,    36,    33,    42,    34,   119,   120,
     121,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    37,    33,    38,    34,    20,    34,    39,    35,   127,
      39,    26,    38,    38,    34,    38,    31,    41,   149,    34,
      37,    15,    34,     3,     4,    31,   144,    72,    50,     9,
      45,    -1,   150,    -1,    -1,    50,    -1,    -1,    53,   157,
      20,    21,    -1,     4,    -1,     6,    -1,     8,     9,    -1,
      65,    31,    32,    -1,    34,    -1,     4,    18,    19,    -1,
       8,     9,    -1,    43,    12,    -1,    14,    82,    16,    17,
      18,    19,    -1,    -1,     4,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    14,    33,    16,    17,    18,    19,
      -1,    -1,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    14,    33,    16,    17,    18,    19,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    33,    35,    -1,    37,    -1,    -1,    -1,    -1,    42,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,
      42,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,
      -1,    42,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,
      -1,    -1,    -1,    42,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      25,    26,    27,    28,    29,    30,    42,    -1,    -1,    -1,
      35,    26,    27,    28,    29,    30,    -1,    42,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    45,    46,     4,     9,    58,     0,     5,    47,
      33,    58,     6,    10,    33,     7,    58,     8,    18,    19,
      48,    54,    58,     8,    33,    35,     6,    49,    54,    58,
       9,    48,    36,    54,     6,    38,    58,    39,    34,    49,
      58,    54,    39,    11,    38,    34,    58,    35,    51,    54,
      34,    36,    37,    40,    58,    51,    58,    33,    54,    37,
      37,    14,    16,    17,    33,    48,    50,    52,    53,    55,
      58,    58,    33,    33,    34,    34,    34,    55,    58,    12,
      52,    53,    48,    55,    35,    41,    50,    55,     3,    20,
      21,    31,    32,    34,    43,    56,    58,    56,    56,    38,
      39,    56,    56,    12,    38,    18,    58,    56,    56,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    35,    37,
      42,    37,    37,    38,    36,    39,    38,    35,    34,    37,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      55,    13,    58,    55,    41,    38,    56,    37,    36,    15,
      34,    56,    36,    55,    56,    57,    37,    40,    56
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    47,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    17,     6,     8,     4,     3,     0,    12,
      11,     0,     2,     2,     1,     1,     4,     2,     2,     1,
       2,     1,     1,     3,     1,     1,     1,     3,     7,     5,
       4,     3,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     6,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     3,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "INTEGER_LITERAL", "IDENTIFIER", "CLASS",
  "PUBLIC", "STATIC", "VOID", "MAIN", "EXTENDS", "STRING", "RETURN",
  "LENGTH", "IF", "ELSE", "WHILE", "SYS_PRINTLN", "T_Int", "T_Bool",
  "T_True", "T_False", "PLUSOP", "MINOP", "MULOP", "DIVOP", "AND", "OR",
  "EQ", "LT", "GT", "THIS", "NEW", "'{'", "'('", "'['", "']'", "')'",
  "'}'", "';'", "','", "'='", "'.'", "'!'", "$accept", "Goal", "MainClass",
  "ClassDeclaration", "VarDeclaration", "MethodDeclaration",
  "MethodBodyDeclaration", "MethodArgumentDeclaration",
  "MethodVarDeclaration", "MethodStatementDeclaration", "Type",
  "Statement", "Expression", "FunctionCallDeclaration", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    47,    47,    56,    64,    71,    80,    86,    92,    95,
     101,   108,   111,   117,   123,   128,   135,   136,   144,   145,
     152,   153,   160,   164,   168,   172,   176,   183,   188,   194,
     200,   205,   211,   220,   226,   232,   238,   244,   250,   256,
     262,   268,   274,   280,   285,   292,   296,   300,   304,   308,
     312,   317,   322,   327,   334,   335,   342,   346
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1742 "parser.tab.cc"

