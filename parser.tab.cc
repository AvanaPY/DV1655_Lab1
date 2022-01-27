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
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                            printf("r7 ");
                                        }
#line 720 "parser.tab.cc"
    break;

  case 7:
#line 87 "parser.yy"
                                          {
                                            yylhs.value.as < Node * > () = new Node("Var declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            printf("r8 ");
                                        }
#line 731 "parser.tab.cc"
    break;

  case 9:
#line 96 "parser.yy"
                                                                                                                               {
                                yylhs.value.as < Node * > () = new Node("Type Method Declaration", yystack_[6].value.as < Node * > ()->type);
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r9 ");
                            }
#line 742 "parser.tab.cc"
    break;

  case 10:
#line 102 "parser.yy"
                                                                                                             {
                                yylhs.value.as < Node * > () = new Node("Type Method Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r9.2 ");
                            }
#line 754 "parser.tab.cc"
    break;

  case 12:
#line 112 "parser.yy"
                                                                         {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r10 ");
                            }
#line 765 "parser.tab.cc"
    break;

  case 13:
#line 118 "parser.yy"
                                                                                 {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r11 ");
                            }
#line 776 "parser.tab.cc"
    break;

  case 14:
#line 124 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("Method Body-Var Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r12 ");
                            }
#line 786 "parser.tab.cc"
    break;

  case 15:
#line 129 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("Method Body-Statement Declaration", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r14 ");
                            }
#line 796 "parser.tab.cc"
    break;

  case 16:
#line 136 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); }
#line 802 "parser.tab.cc"
    break;

  case 17:
#line 137 "parser.yy"
                                             {
                                            yylhs.value.as < Node * > () = new Node("Method Arg Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r16 ");
                                        }
#line 813 "parser.tab.cc"
    break;

  case 18:
#line 145 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 819 "parser.tab.cc"
    break;

  case 19:
#line 146 "parser.yy"
                                             {
                                            yylhs.value.as < Node * > () = new Node("Method Var Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r19 ");
                                        }
#line 829 "parser.tab.cc"
    break;

  case 20:
#line 153 "parser.yy"
                              { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 835 "parser.tab.cc"
    break;

  case 21:
#line 154 "parser.yy"
                                        {
                                            yylhs.value.as < Node * > () = new Node("Method Statement Declaration", "");
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                            printf("r21 ");
                                        }
#line 845 "parser.tab.cc"
    break;

  case 22:
#line 161 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                                printf("r22 ");
                            }
#line 854 "parser.tab.cc"
    break;

  case 23:
#line 165 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                                printf("r23 ");
                            }
#line 863 "parser.tab.cc"
    break;

  case 24:
#line 169 "parser.yy"
                             {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                                printf("r24 ");
                            }
#line 872 "parser.tab.cc"
    break;

  case 25:
#line 173 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("VOID", "");
                                printf("r25 ");
                            }
#line 881 "parser.tab.cc"
    break;

  case 26:
#line 177 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("IDENTIFIER", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r26 ");
                            }
#line 891 "parser.tab.cc"
    break;

  case 27:
#line 184 "parser.yy"
                                {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r27 ");
                            }
#line 901 "parser.tab.cc"
    break;

  case 28:
#line 189 "parser.yy"
                                                                                             {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r29 ");
                            }
#line 912 "parser.tab.cc"
    break;

  case 29:
#line 195 "parser.yy"
                                                                      {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r30 ");
                            }
#line 923 "parser.tab.cc"
    break;

  case 30:
#line 201 "parser.yy"
                                                     {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r31 ");
                            }
#line 933 "parser.tab.cc"
    break;

  case 31:
#line 206 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r32 ");
                            }
#line 944 "parser.tab.cc"
    break;

  case 32:
#line 212 "parser.yy"
                                                                  {
                                yylhs.value.as < Node * > () = new Node("Assign []", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r33 ");
                            }
#line 956 "parser.tab.cc"
    break;

  case 33:
#line 221 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r34 ");
                            }
#line 967 "parser.tab.cc"
    break;

  case 34:
#line 227 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r35 ");
                            }
#line 978 "parser.tab.cc"
    break;

  case 35:
#line 233 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r36 ");
                            }
#line 989 "parser.tab.cc"
    break;

  case 36:
#line 239 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r37 ");
                            }
#line 1000 "parser.tab.cc"
    break;

  case 37:
#line 245 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r38 ");
                            }
#line 1011 "parser.tab.cc"
    break;

  case 38:
#line 251 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r39 ");
                            }
#line 1022 "parser.tab.cc"
    break;

  case 39:
#line 257 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r40 ");
                            }
#line 1033 "parser.tab.cc"
    break;

  case 40:
#line 263 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r41 ");
                            }
#line 1044 "parser.tab.cc"
    break;

  case 41:
#line 269 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1055 "parser.tab.cc"
    break;

  case 42:
#line 275 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1066 "parser.tab.cc"
    break;

  case 43:
#line 281 "parser.yy"
                                           {
                                yylhs.value.as < Node * > () = new Node("LENGTH", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r43 ");
                            }
#line 1076 "parser.tab.cc"
    break;

  case 44:
#line 286 "parser.yy"
                                                                               {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r44 ");
                            }
#line 1088 "parser.tab.cc"
    break;

  case 45:
#line 293 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                                printf("r45 ");
                            }
#line 1097 "parser.tab.cc"
    break;

  case 46:
#line 297 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                                printf("r46 ");
                            }
#line 1106 "parser.tab.cc"
    break;

  case 47:
#line 301 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                                printf("r47 ");
                            }
#line 1115 "parser.tab.cc"
    break;

  case 48:
#line 305 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->type);
                                printf("r48 ");
                            }
#line 1124 "parser.tab.cc"
    break;

  case 49:
#line 309 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                                printf("r49 ");
                            }
#line 1133 "parser.tab.cc"
    break;

  case 50:
#line 313 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r50 ");
                            }
#line 1143 "parser.tab.cc"
    break;

  case 51:
#line 318 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r51 ");
                            }
#line 1153 "parser.tab.cc"
    break;

  case 52:
#line 323 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r52 ");
                            }
#line 1163 "parser.tab.cc"
    break;

  case 53:
#line 328 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r53 ");
                            }
#line 1173 "parser.tab.cc"
    break;

  case 54:
#line 335 "parser.yy"
                          { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 1179 "parser.tab.cc"
    break;

  case 55:
#line 336 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r54 ");
                            }
#line 1189 "parser.tab.cc"
    break;

  case 56:
#line 343 "parser.yy"
                                {
                                yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), "");
                                printf("r55 ");
                            }
#line 1198 "parser.tab.cc"
    break;

  case 57:
#line 347 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("MAIN", "");
                                printf("r56 ");
                            }
#line 1207 "parser.tab.cc"
    break;


#line 1211 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -63;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       9,    50,    17,    13,   -63,   -63,    -7,   -63,    50,   -63,
      41,    12,    46,    50,   340,    47,    34,   -63,    33,   -63,
     174,    50,   -63,    71,   340,    54,   340,    -3,    50,    48,
      58,   174,   -63,    50,   340,   -63,    59,   -63,    86,     3,
      78,    50,   -63,    64,   -63,   340,    79,    69,   -36,    50,
     340,    50,    81,   340,   -63,    51,    89,   338,    50,    94,
      96,    97,   101,   103,   340,    20,   340,    65,   -63,   -33,
     -63,   338,    65,   142,   142,   142,   -63,   340,    65,   340,
     -63,   -33,   142,   142,    92,   100,   -63,   -63,   -63,   -63,
      42,   142,   142,   166,   -63,   182,   198,   214,   275,   -63,
     102,   106,   109,   229,   275,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   111,     2,   114,   -63,   107,
     -63,   142,   113,   -63,   290,   299,   308,   332,   275,   275,
     275,   275,   275,   245,    65,   -63,   118,    65,   142,   260,
     -63,   -63,   116,   142,   120,   275,   -63,   119,   275,    67,
     122,   150,   -63,   142,   -63,   133,   275,    65,   128,   132,
     -63
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
       0,     0,     0,     0,    19,     0,     8,    15,    21,    26,
      16,     8,     0,     0,     0,     0,    10,     8,    13,    18,
      20,     0,     0,     0,     0,     0,    45,    46,    47,    49,
       0,     0,     0,     0,    48,     0,     0,     0,    31,     9,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       3,     0,     0,    53,    38,    39,    40,    41,    33,    34,
      37,    35,    36,     0,     0,    43,     0,     0,     0,     0,
      51,    42,     0,     0,     0,    32,    50,     0,    55,     0,
       0,     0,    44,     0,    29,     0,    54,     0,     0,     0,
      28
  };

  const short
  parser::yypgoto_[] =
  {
     -63,   -63,   -63,   -63,     7,   140,   104,   123,   -23,   -22,
     108,   -62,    11,   -63,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     9,    64,    27,    65,    48,    66,    67,
      21,    68,    93,   149,    94
  };

  const unsigned char
  parser::yytable_[] =
  {
       6,    52,    82,    34,    53,    80,     4,    11,    83,    34,
      85,     5,    16,    22,     1,   135,    80,     7,     8,    22,
      29,    20,    13,    22,     4,    22,    10,    36,    17,     5,
      22,    31,    40,    22,    61,    35,    62,    63,    18,    19,
      46,    44,    77,    78,    22,    14,     4,    12,    54,    22,
      56,     5,    22,    15,     4,    23,    69,    70,    76,     5,
     101,    77,    78,    22,    69,    22,    81,    24,    25,     4,
      69,    81,   142,    79,     5,   144,    22,    81,    22,    61,
      30,    62,    63,    69,    79,    95,    96,    37,    59,   102,
      32,    53,    38,    97,    98,   158,     4,    43,    42,    47,
      17,     5,   103,   104,   152,    51,    61,   153,    62,    63,
      18,    19,    45,    50,    57,   136,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    60,    71,    28,    72,
      99,    73,   139,    81,    33,    74,    81,    75,   100,    28,
     120,   121,    41,   122,   134,    86,     4,   137,   138,   145,
     140,     5,   143,    49,   148,   147,    81,   151,    49,   150,
     154,    58,    87,    88,   156,   155,   157,   159,    89,    90,
     160,    39,    28,    55,     0,    84,    91,     0,     4,     0,
      26,     0,    17,     5,     0,    92,     0,    28,   105,   106,
     107,   108,    18,    19,   109,   110,   111,   112,   113,     0,
       0,   114,     0,   115,   105,   106,   107,   108,   116,     0,
     109,   110,   111,   112,   113,     0,     0,   114,     0,   117,
     105,   106,   107,   108,   116,     0,   109,   110,   111,   112,
     113,     0,     0,   114,     0,   118,   105,   106,   107,   108,
     116,     0,   109,   110,   111,   112,   113,     0,     0,   114,
     119,   105,   106,   107,   108,     0,   116,   109,   110,   111,
     112,   113,     0,     0,   114,     0,   123,   105,   106,   107,
     108,   116,     0,   109,   110,   111,   112,   113,     0,     0,
     114,   141,   105,   106,   107,   108,     0,   116,   109,   110,
     111,   112,   113,     0,     0,   114,   146,   105,   106,   107,
     108,     0,   116,   109,   110,   111,   112,   113,     0,     0,
     114,     0,     0,   106,   107,   108,     0,   116,   109,   110,
     111,   112,   113,   107,   108,   114,     0,   109,   110,   111,
     112,   113,   116,   108,   114,     0,   109,   110,   111,   112,
     113,   116,     4,   114,     4,     0,    17,     5,    17,     5,
     116,     0,    61,     0,    62,    63,    18,    19,    18,    19,
     109,   110,   111,   112,   113,     0,     0,   114,     0,     0,
       0,     0,     0,     0,   116
  };

  const short
  parser::yycheck_[] =
  {
       1,    37,    35,     6,    40,    67,     4,     8,    41,     6,
      72,     9,    13,    14,     5,    13,    78,     0,     5,    20,
      21,    14,    10,    24,     4,    26,    33,    28,     8,     9,
      31,    24,    33,    34,    14,    38,    16,    17,    18,    19,
      41,    38,    65,    65,    45,    33,     4,     6,    49,    50,
      51,     9,    53,     7,     4,     8,    57,    58,    38,     9,
      18,    84,    84,    64,    65,    66,    67,    33,    35,     4,
      71,    72,   134,    66,     9,   137,    77,    78,    79,    14,
       9,    16,    17,    84,    77,    74,    75,    39,    37,    90,
      36,    40,    34,    82,    83,   157,     4,    11,    39,    35,
       8,     9,    91,    92,    37,    36,    14,    40,    16,    17,
      18,    19,    34,    34,    33,   116,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    37,    33,    20,    33,
      38,    34,   121,   134,    26,    34,   137,    34,    38,    31,
      38,    35,    34,    34,    33,     3,     4,    33,    41,   138,
      37,     9,    34,    45,   143,    39,   157,    38,    50,    39,
      38,    53,    20,    21,   153,    15,    33,    39,    26,    27,
      38,    31,    64,    50,    -1,    71,    34,    -1,     4,    -1,
       6,    -1,     8,     9,    -1,    43,    -1,    79,    22,    23,
      24,    25,    18,    19,    28,    29,    30,    31,    32,    -1,
      -1,    35,    -1,    37,    22,    23,    24,    25,    42,    -1,
      28,    29,    30,    31,    32,    -1,    -1,    35,    -1,    37,
      22,    23,    24,    25,    42,    -1,    28,    29,    30,    31,
      32,    -1,    -1,    35,    -1,    37,    22,    23,    24,    25,
      42,    -1,    28,    29,    30,    31,    32,    -1,    -1,    35,
      36,    22,    23,    24,    25,    -1,    42,    28,    29,    30,
      31,    32,    -1,    -1,    35,    -1,    37,    22,    23,    24,
      25,    42,    -1,    28,    29,    30,    31,    32,    -1,    -1,
      35,    36,    22,    23,    24,    25,    -1,    42,    28,    29,
      30,    31,    32,    -1,    -1,    35,    36,    22,    23,    24,
      25,    -1,    42,    28,    29,    30,    31,    32,    -1,    -1,
      35,    -1,    -1,    23,    24,    25,    -1,    42,    28,    29,
      30,    31,    32,    24,    25,    35,    -1,    28,    29,    30,
      31,    32,    42,    25,    35,    -1,    28,    29,    30,    31,
      32,    42,     4,    35,     4,    -1,     8,     9,     8,     9,
      42,    -1,    14,    -1,    16,    17,    18,    19,    18,    19,
      28,    29,    30,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42
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
      37,    14,    16,    17,    48,    50,    52,    53,    55,    58,
      58,    33,    33,    34,    34,    34,    38,    52,    53,    48,
      55,    58,    35,    41,    50,    55,     3,    20,    21,    26,
      27,    34,    43,    56,    58,    56,    56,    56,    56,    38,
      38,    18,    58,    56,    56,    22,    23,    24,    25,    28,
      29,    30,    31,    32,    35,    37,    42,    37,    37,    36,
      38,    35,    34,    37,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    33,    13,    58,    33,    41,    56,
      37,    36,    55,    34,    55,    56,    36,    39,    56,    57,
      39,    38,    37,    40,    38,    15,    56,    33,    55,    39,
      38
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
       0,     2,     2,    17,     6,     8,     4,     3,     0,    10,
       9,     0,     2,     2,     1,     1,     4,     2,     2,     1,
       2,     1,     1,     3,     1,     1,     1,     1,    13,     8,
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
  "T_True", "T_False", "PLUSOP", "MINOP", "MULOP", "DIVOP", "THIS", "NEW",
  "AND", "OR", "EQ", "LT", "GT", "'{'", "'('", "'['", "']'", "')'", "'}'",
  "';'", "','", "'='", "'.'", "'!'", "$accept", "Goal", "MainClass",
  "ClassDeclaration", "VarDeclaration", "MethodDeclaration",
  "MethodBodyDeclaration", "MethodArgumentDeclaration",
  "MethodVarDeclaration", "MethodStatementDeclaration", "Type",
  "Statement", "Expression", "FunctionCallDeclaration", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    47,    47,    56,    64,    71,    80,    87,    93,    96,
     102,   109,   112,   118,   124,   129,   136,   137,   145,   146,
     153,   154,   161,   165,   169,   173,   177,   184,   189,   195,
     201,   206,   212,   221,   227,   233,   239,   245,   251,   257,
     263,   269,   275,   281,   286,   293,   297,   301,   305,   309,
     313,   318,   323,   328,   335,   336,   343,   347
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
#line 1732 "parser.tab.cc"

