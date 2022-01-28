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
    Node* classes;

#line 52 "parser.tab.cc"


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
#line 124 "parser.tab.cc"


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
      case 47: // OptionalClassList
      case 48: // ClassDeclaration
      case 49: // VarList
      case 50: // VarDeclaration
      case 51: // MethodList
      case 52: // MethodDeclaration
      case 53: // MethodBodyDeclaration
      case 54: // MethodParameterList
      case 55: // MethodParameterDecl
      case 56: // Type
      case 57: // Statement
      case 58: // Expression
      case 59: // FunctionArgumentList
      case 60: // Identifier
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
      case 47: // OptionalClassList
      case 48: // ClassDeclaration
      case 49: // VarList
      case 50: // VarDeclaration
      case 51: // MethodList
      case 52: // MethodDeclaration
      case 53: // MethodBodyDeclaration
      case 54: // MethodParameterList
      case 55: // MethodParameterDecl
      case 56: // Type
      case 57: // Statement
      case 58: // Expression
      case 59: // FunctionArgumentList
      case 60: // Identifier
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
      case 47: // OptionalClassList
      case 48: // ClassDeclaration
      case 49: // VarList
      case 50: // VarDeclaration
      case 51: // MethodList
      case 52: // MethodDeclaration
      case 53: // MethodBodyDeclaration
      case 54: // MethodParameterList
      case 55: // MethodParameterDecl
      case 56: // Type
      case 57: // Statement
      case 58: // Expression
      case 59: // FunctionArgumentList
      case 60: // Identifier
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
      case 47: // OptionalClassList
      case 48: // ClassDeclaration
      case 49: // VarList
      case 50: // VarDeclaration
      case 51: // MethodList
      case 52: // MethodDeclaration
      case 53: // MethodBodyDeclaration
      case 54: // MethodParameterList
      case 55: // MethodParameterDecl
      case 56: // Type
      case 57: // Statement
      case 58: // Expression
      case 59: // FunctionArgumentList
      case 60: // Identifier
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
      case 47: // OptionalClassList
      case 48: // ClassDeclaration
      case 49: // VarList
      case 50: // VarDeclaration
      case 51: // MethodList
      case 52: // MethodDeclaration
      case 53: // MethodBodyDeclaration
      case 54: // MethodParameterList
      case 55: // MethodParameterDecl
      case 56: // Type
      case 57: // Statement
      case 58: // Expression
      case 59: // FunctionArgumentList
      case 60: // Identifier
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
#line 54 "parser.yy"
                                                  {
                                        yylhs.value.as < Node * > () = new Node("Program", "");
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                        root = yylhs.value.as < Node * > ();
                                        printf("r1 ");
                                    }
#line 684 "parser.tab.cc"
    break;

  case 3:
#line 63 "parser.yy"
                                                                                                                           {
                                                                    yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < Node * > ()->type);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(n);
                                                                    printf("r2 ");
                                                                }
#line 696 "parser.tab.cc"
    break;

  case 4:
#line 72 "parser.yy"
                                                         {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                            
                        }
#line 709 "parser.tab.cc"
    break;

  case 5:
#line 80 "parser.yy"
                                       {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = classes;
                        }
#line 721 "parser.tab.cc"
    break;

  case 6:
#line 89 "parser.yy"
                                                                  {
                                            yylhs.value.as < Node * > () = new Node("Class", yystack_[4].value.as < Node * > ()->type);
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r5 ");
                                        }
#line 732 "parser.tab.cc"
    break;

  case 7:
#line 95 "parser.yy"
                                                                                    {
                                            yylhs.value.as < Node * > () = new Node("Class", yystack_[6].value.as < Node * > ()->type);

                                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[4].value.as < Node * > ()->type));
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r6 ");
                                        }
#line 745 "parser.tab.cc"
    break;

  case 8:
#line 105 "parser.yy"
                                               {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r7.2 ");
                        }
#line 755 "parser.tab.cc"
    break;

  case 9:
#line 110 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Variable List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r7.1 ");
                        }
#line 765 "parser.tab.cc"
    break;

  case 10:
#line 117 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("Variable", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            printf("r8 ");
                        }
#line 776 "parser.tab.cc"
    break;

  case 11:
#line 125 "parser.yy"
                                                     {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r8.1 ");
                        }
#line 786 "parser.tab.cc"
    break;

  case 12:
#line 130 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("Method List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r8.2 ");
                        }
#line 796 "parser.tab.cc"
    break;

  case 13:
#line 137 "parser.yy"
                                                                                                         {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[6].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            printf("r9.2 ");
                        }
#line 807 "parser.tab.cc"
    break;

  case 14:
#line 143 "parser.yy"
                                                                                                                               {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[9].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Returns", yystack_[2].value.as < Node * > ()->type));
                            printf("r9.3 ");
                        }
#line 819 "parser.tab.cc"
    break;

  case 15:
#line 152 "parser.yy"
                                                              {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r10 ");
                                }
#line 830 "parser.tab.cc"
    break;

  case 16:
#line 158 "parser.yy"
                                      {
                                    printf("r12 ");
                                    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                                }
#line 839 "parser.tab.cc"
    break;

  case 17:
#line 162 "parser.yy"
                                        {
                                    yylhs.value.as < Node * > () = new Node("Statement List", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r14 ");
                                }
#line 849 "parser.tab.cc"
    break;

  case 18:
#line 169 "parser.yy"
                                                                  {
                            yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                            printf("r16 ");
                        }
#line 859 "parser.tab.cc"
    break;

  case 19:
#line 174 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("Parameter List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16.1 ");
                        }
#line 869 "parser.tab.cc"
    break;

  case 20:
#line 179 "parser.yy"
                              {
                            yylhs.value.as < Node * > () = new Node("Arguments", "None");
                            printf("r16.2 ");
                        }
#line 878 "parser.tab.cc"
    break;

  case 21:
#line 185 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Parameter", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16 ");
                        }
#line 889 "parser.tab.cc"
    break;

  case 22:
#line 193 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                                printf("r22 ");
                            }
#line 898 "parser.tab.cc"
    break;

  case 23:
#line 197 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                                printf("r23 ");
                            }
#line 907 "parser.tab.cc"
    break;

  case 24:
#line 201 "parser.yy"
                             {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                                printf("r24 ");
                            }
#line 916 "parser.tab.cc"
    break;

  case 25:
#line 207 "parser.yy"
                                          {
                                    yylhs.value.as < Node * > () = new Node("Statement", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r27 ");
                                    }
#line 927 "parser.tab.cc"
    break;

  case 26:
#line 213 "parser.yy"
                                                                                     {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());

                                Node* else_node = new Node("ELSE", "");
                                else_node->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(else_node);
                                printf("r29 ");
                            }
#line 942 "parser.tab.cc"
    break;

  case 27:
#line 223 "parser.yy"
                                                                  {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r30 ");
                            }
#line 953 "parser.tab.cc"
    break;

  case 28:
#line 229 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", yystack_[2].value.as < Node * > ()->value);
                                printf("r31 ");
                            }
#line 962 "parser.tab.cc"
    break;

  case 29:
#line 233 "parser.yy"
                                                    { 
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r32 ");
                            }
#line 973 "parser.tab.cc"
    break;

  case 30:
#line 239 "parser.yy"
                                                                       {
                                yylhs.value.as < Node * > () = new Node("Assign[]", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r33 ");
                        }
#line 985 "parser.tab.cc"
    break;

  case 31:
#line 248 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r34 ");
                            }
#line 996 "parser.tab.cc"
    break;

  case 32:
#line 254 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r35 ");
                            }
#line 1007 "parser.tab.cc"
    break;

  case 33:
#line 260 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r36 ");
                            }
#line 1018 "parser.tab.cc"
    break;

  case 34:
#line 266 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r37 ");
                            }
#line 1029 "parser.tab.cc"
    break;

  case 35:
#line 272 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r38 ");
                            }
#line 1040 "parser.tab.cc"
    break;

  case 36:
#line 278 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r39 ");
                            }
#line 1051 "parser.tab.cc"
    break;

  case 37:
#line 284 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r40 ");
                            }
#line 1062 "parser.tab.cc"
    break;

  case 38:
#line 290 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r41 ");
                            }
#line 1073 "parser.tab.cc"
    break;

  case 39:
#line 296 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1084 "parser.tab.cc"
    break;

  case 40:
#line 302 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1095 "parser.tab.cc"
    break;

  case 41:
#line 308 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("LENGTH", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r43 ");
                            }
#line 1105 "parser.tab.cc"
    break;

  case 42:
#line 313 "parser.yy"
                                                                            {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r44 ");
                            }
#line 1117 "parser.tab.cc"
    break;

  case 43:
#line 320 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                                printf("r45 ");
                            }
#line 1126 "parser.tab.cc"
    break;

  case 44:
#line 324 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                                printf("r46 ");
                            }
#line 1135 "parser.tab.cc"
    break;

  case 45:
#line 328 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                                printf("r47 ");
                            }
#line 1144 "parser.tab.cc"
    break;

  case 46:
#line 332 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->type);
                                printf("r48 ");
                            }
#line 1153 "parser.tab.cc"
    break;

  case 47:
#line 336 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                                printf("r49 ");
                            }
#line 1162 "parser.tab.cc"
    break;

  case 48:
#line 340 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r50 ");
                            }
#line 1172 "parser.tab.cc"
    break;

  case 49:
#line 345 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r51 ");
                            }
#line 1182 "parser.tab.cc"
    break;

  case 50:
#line 350 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r52 ");
                            }
#line 1192 "parser.tab.cc"
    break;

  case 51:
#line 355 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r53 ");
                            }
#line 1202 "parser.tab.cc"
    break;

  case 52:
#line 362 "parser.yy"
                                                           {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r54 ");
                            }
#line 1213 "parser.tab.cc"
    break;

  case 53:
#line 368 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r55 ");
                            }
#line 1223 "parser.tab.cc"
    break;

  case 54:
#line 375 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), "");
                                printf("r56 ");
                            }
#line 1232 "parser.tab.cc"
    break;


#line 1236 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -52;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       0,    12,    31,    37,   -52,    14,   -52,    12,    37,   -52,
      44,    -6,   -52,    64,    12,     8,    65,    46,    41,   -52,
      11,   -52,    12,    72,     8,    50,    -7,   -52,    -3,   -52,
      49,    53,    11,   -52,    12,    12,   -52,   -52,   -52,    83,
       2,    61,    66,    75,   -52,     8,     8,    90,    57,   -52,
      12,    96,    12,    68,     8,   -52,    95,    92,   331,   -52,
     331,   101,   109,   110,   111,     8,    21,    93,    34,   146,
      93,    19,    19,    19,   -52,    93,    93,    19,    19,    19,
      39,   -52,   -52,   -52,   -52,     6,    19,    19,   201,   -52,
     218,   235,   269,   144,   163,   112,   116,   113,   252,   329,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    48,
      19,   123,   125,   124,   114,   -52,   131,   -52,    19,   133,
     -52,   343,   353,   362,   371,   329,   329,   329,   329,   329,
     -52,   143,   285,    93,    93,   -52,    19,   -52,   301,   -52,
      19,   -52,    89,   108,   182,   -52,   329,   102,   164,   -52,
     -52,   -52,    19,   147,   329,    93,   122,   -52
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    54,     0,     1,     0,     2,     5,
       0,     0,     4,     0,     0,     0,     0,     0,    22,    24,
       0,     9,     0,     0,     0,     0,     0,     8,     0,    12,
       0,     0,     0,    23,     0,     0,     6,    11,    10,     0,
       0,     0,     0,     0,     7,    20,    20,     0,     0,    19,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    16,     0,    17,     0,     0,
       0,     0,     0,     0,    13,    15,    25,     0,     0,     0,
       0,    43,    44,    45,    47,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     3,     0,     0,
      51,    36,    37,    38,    39,    31,    32,    35,    33,    34,
      41,     0,     0,     0,     0,    28,     0,    14,     0,    49,
       0,    40,     0,     0,     0,    48,    53,     0,     0,    27,
      30,    42,     0,     0,    52,     0,     0,    26
  };

  const short
  parser::yypgoto_[] =
  {
     -52,   -52,   -52,   -52,   174,    43,   -18,   151,    -8,   129,
     152,   136,    18,   -51,    13,   -52,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    65,    21,    28,    29,    66,
      48,    49,    22,    76,    88,   147,    89
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    34,    27,    26,    14,     1,    11,    67,    26,    67,
       4,    18,    19,    17,    27,    75,     4,    26,    75,    80,
      37,    30,    81,     4,    96,     4,    18,    19,    15,    18,
      19,     6,    37,    41,    42,    62,    36,    63,    64,    82,
      83,    44,     7,     4,    35,    84,    85,    27,    10,    55,
      13,    57,     4,    62,    86,    63,    64,    68,    20,    68,
      74,   130,    87,    50,    50,    68,    68,    32,    68,    68,
      77,    16,    50,    23,    68,    68,    78,    25,    95,    68,
      24,    31,   142,   143,    97,    90,    91,    33,    39,    38,
      92,    93,    94,     4,    43,    53,    45,     4,    54,    98,
      99,    46,    58,    62,   156,    63,    64,    62,   131,    63,
      64,    47,     4,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    62,   132,    63,    64,     4,    52,   148,    60,
      61,   138,    68,    68,    56,    70,    62,    54,    63,    64,
     151,    68,    68,   152,    71,    72,    73,   149,   119,   144,
       4,   117,   118,   146,    68,    68,   136,   133,    79,   134,
      62,   157,    63,    64,   135,   154,   100,   101,   102,   103,
     137,   139,   104,   105,   106,   107,   108,   109,   140,   153,
     110,   155,    12,    40,   115,   100,   101,   102,   103,    69,
      59,   104,   105,   106,   107,   108,   109,     0,    51,   110,
       0,     0,     0,   116,   100,   101,   102,   103,     0,     0,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
       0,     0,   150,   100,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,     0,     0,   110,     0,   111,
     100,   101,   102,   103,     0,     0,   104,   105,   106,   107,
     108,   109,     0,     0,   110,     0,   112,   100,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,     0,
       0,   110,     0,   113,   100,   101,   102,   103,     0,     0,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
     120,   100,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,     0,     0,   110,   114,   100,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,     0,
       0,   110,   141,   100,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,     4,     0,   110,   145,     0,
       0,     0,     0,     0,     0,    62,     0,    63,    64,    18,
      19,   100,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,     0,     0,   110,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   102,   103,   110,
       0,   104,   105,   106,   107,   108,   109,   103,     0,   110,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   104,
     105,   106,   107,   108,   109,     0,     0,   110
  };

  const short
  parser::yycheck_[] =
  {
       1,     8,    20,     6,    10,     5,     7,    58,     6,    60,
       4,    18,    19,    14,    32,    66,     4,     6,    69,    70,
      28,    22,     3,     4,    18,     4,    18,    19,    34,    18,
      19,     0,    40,    34,    35,    14,    39,    16,    17,    20,
      21,    39,     5,     4,    26,    26,    27,    65,    34,    50,
       6,    52,     4,    14,    35,    16,    17,    58,    15,    60,
      39,    13,    43,    45,    46,    66,    67,    24,    69,    70,
      36,     7,    54,     8,    75,    76,    42,    36,    39,    80,
      34,     9,   133,   134,    85,    72,    73,    37,    35,    40,
      77,    78,    79,     4,    11,    38,    35,     4,    41,    86,
      87,    35,    34,    14,   155,    16,    17,    14,   109,    16,
      17,    36,     4,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    14,   110,    16,    17,     4,    37,    39,    34,
      38,   118,   133,   134,    38,    34,    14,    41,    16,    17,
      38,   142,   143,    41,    35,    35,    35,    39,    35,   136,
       4,    39,    36,   140,   155,   156,    42,    34,    12,    34,
      14,    39,    16,    17,    40,   152,    22,    23,    24,    25,
      39,    38,    28,    29,    30,    31,    32,    33,    35,    15,
      36,    34,     8,    32,    40,    22,    23,    24,    25,    60,
      54,    28,    29,    30,    31,    32,    33,    -1,    46,    36,
      -1,    -1,    -1,    40,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      -1,    -1,    40,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    -1,    38,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    36,    -1,    38,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    -1,    38,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      38,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    37,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    37,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    33,     4,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    16,    17,    18,
      19,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    24,    25,    36,
      -1,    28,    29,    30,    31,    32,    33,    25,    -1,    36,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    45,    46,     4,    60,     0,     5,    47,    48,
      34,    60,    48,     6,    10,    34,     7,    60,    18,    19,
      49,    50,    56,     8,    34,    36,     6,    50,    51,    52,
      60,     9,    49,    37,     8,    56,    39,    52,    40,    35,
      51,    60,    60,    11,    39,    35,    35,    36,    54,    55,
      56,    54,    37,    38,    41,    60,    38,    60,    34,    55,
      34,    38,    14,    16,    17,    49,    53,    57,    60,    53,
      34,    35,    35,    35,    39,    57,    57,    36,    42,    12,
      57,     3,    20,    21,    26,    27,    35,    43,    58,    60,
      58,    58,    58,    58,    58,    39,    18,    60,    58,    58,
      22,    23,    24,    25,    28,    29,    30,    31,    32,    33,
      36,    38,    38,    38,    37,    40,    40,    39,    36,    35,
      38,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      13,    60,    58,    34,    34,    40,    42,    39,    58,    38,
      35,    37,    57,    57,    58,    37,    58,    59,    39,    39,
      40,    38,    41,    15,    58,    34,    57,    39
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    55,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    17,     2,     1,     6,     8,     2,     1,
       3,     2,     1,     9,    12,     2,     1,     1,     3,     1,
       0,     2,     1,     3,     1,     2,    11,     7,     5,     4,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     6,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     3,     1,     1
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
  "AND", "OR", "EQ", "LT", "GT", "DOT", "'{'", "'('", "'['", "']'", "')'",
  "'}'", "';'", "','", "'='", "'!'", "$accept", "Goal", "MainClass",
  "OptionalClassList", "ClassDeclaration", "VarList", "VarDeclaration",
  "MethodList", "MethodDeclaration", "MethodBodyDeclaration",
  "MethodParameterList", "MethodParameterDecl", "Type", "Statement",
  "Expression", "FunctionArgumentList", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    54,    54,    63,    72,    80,    89,    95,   105,   110,
     117,   125,   130,   137,   143,   152,   158,   162,   169,   174,
     179,   185,   193,   197,   201,   207,   213,   223,   229,   233,
     239,   248,   254,   260,   266,   272,   278,   284,   290,   296,
     302,   308,   313,   320,   324,   328,   332,   336,   340,   345,
     350,   355,   362,   368,   375
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
#line 1760 "parser.tab.cc"

