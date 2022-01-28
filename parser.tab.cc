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
      case 57: // StatementList
      case 58: // Statement
      case 59: // Expression
      case 60: // FunctionArgumentList
      case 61: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 12: // T_Int
      case 13: // T_Bool
      case 14: // T_True
      case 15: // T_False
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
      case 57: // StatementList
      case 58: // Statement
      case 59: // Expression
      case 60: // FunctionArgumentList
      case 61: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 12: // T_Int
      case 13: // T_Bool
      case 14: // T_True
      case 15: // T_False
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
      case 57: // StatementList
      case 58: // Statement
      case 59: // Expression
      case 60: // FunctionArgumentList
      case 61: // Identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 12: // T_Int
      case 13: // T_Bool
      case 14: // T_True
      case 15: // T_False
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
      case 57: // StatementList
      case 58: // Statement
      case 59: // Expression
      case 60: // FunctionArgumentList
      case 61: // Identifier
        value.move< Node * > (that.value);
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 12: // T_Int
      case 13: // T_Bool
      case 14: // T_True
      case 15: // T_False
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
      case 57: // StatementList
      case 58: // Statement
      case 59: // Expression
      case 60: // FunctionArgumentList
      case 61: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // INTEGER_LITERAL
      case 4: // IDENTIFIER
      case 12: // T_Int
      case 13: // T_Bool
      case 14: // T_True
      case 15: // T_False
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
#line 65 "parser.yy"
                                                  {
                                        yylhs.value.as < Node * > () = new Node("Program", "");
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                        root = yylhs.value.as < Node * > ();
                                        printf("r1 ");
                                    }
#line 689 "parser.tab.cc"
    break;

  case 3:
#line 74 "parser.yy"
                                                                                                                           {
                                                                    yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < Node * > ()->type);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(n);
                                                                    printf("r2 ");
                                                                }
#line 701 "parser.tab.cc"
    break;

  case 4:
#line 83 "parser.yy"
                                                         {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                            
                        }
#line 714 "parser.tab.cc"
    break;

  case 5:
#line 91 "parser.yy"
                                       {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = classes;
                        }
#line 726 "parser.tab.cc"
    break;

  case 6:
#line 98 "parser.yy"
                                {
                            yylhs.value.as < Node * > () = new Node("Class List", "Empty");
                        }
#line 734 "parser.tab.cc"
    break;

  case 7:
#line 104 "parser.yy"
                                                                  {
                                            yylhs.value.as < Node * > () = new Node("Class", yystack_[4].value.as < Node * > ()->type);
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r5 ");
                                        }
#line 745 "parser.tab.cc"
    break;

  case 8:
#line 110 "parser.yy"
                                                                                    {
                                            yylhs.value.as < Node * > () = new Node("Class", yystack_[6].value.as < Node * > ()->type);

                                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[4].value.as < Node * > ()->type));
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                            printf("r6 ");
                                        }
#line 758 "parser.tab.cc"
    break;

  case 9:
#line 119 "parser.yy"
                                               {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r7.2 ");
                        }
#line 768 "parser.tab.cc"
    break;

  case 10:
#line 124 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Variable List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r7.1 ");
                        }
#line 778 "parser.tab.cc"
    break;

  case 11:
#line 129 "parser.yy"
                                 {
                            yylhs.value.as < Node * > () = new Node("Variable List", "Empty");     
                            printf("r7.2 ");
                        }
#line 787 "parser.tab.cc"
    break;

  case 12:
#line 135 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("Variable", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            printf("r8 ");
                        }
#line 798 "parser.tab.cc"
    break;

  case 13:
#line 143 "parser.yy"
                                                     {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r8.1 ");
                        }
#line 808 "parser.tab.cc"
    break;

  case 14:
#line 148 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("Method List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r8.2 ");
                        }
#line 818 "parser.tab.cc"
    break;

  case 15:
#line 153 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("Method List", "Empty");
                            printf("r8.3 ");
                        }
#line 827 "parser.tab.cc"
    break;

  case 16:
#line 159 "parser.yy"
                                                                                                       {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[6].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            printf("r9.2 ");
                        }
#line 838 "parser.tab.cc"
    break;

  case 17:
#line 165 "parser.yy"
                                                                                                                             {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[9].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Returns", yystack_[2].value.as < Node * > ()->type));
                            printf("r9.3 ");
                        }
#line 850 "parser.tab.cc"
    break;

  case 18:
#line 174 "parser.yy"
                                                                {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r10 ");
                                }
#line 861 "parser.tab.cc"
    break;

  case 19:
#line 180 "parser.yy"
                                        {
                                    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                                }
#line 869 "parser.tab.cc"
    break;

  case 20:
#line 183 "parser.yy"
                                              {
                                    yylhs.value.as < Node * > () = new Node("Statement List", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r14 ");
                                }
#line 879 "parser.tab.cc"
    break;

  case 21:
#line 190 "parser.yy"
                                                                  {
                            yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                            printf("r16 ");
                        }
#line 889 "parser.tab.cc"
    break;

  case 22:
#line 195 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("Parameter List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16.1 ");
                        }
#line 899 "parser.tab.cc"
    break;

  case 23:
#line 200 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("Arguments", "None");
                            printf("r16.2 ");
                        }
#line 908 "parser.tab.cc"
    break;

  case 24:
#line 206 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Parameter", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16 ");
                        }
#line 919 "parser.tab.cc"
    break;

  case 25:
#line 214 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                                printf("r22 ");
                            }
#line 928 "parser.tab.cc"
    break;

  case 26:
#line 218 "parser.yy"
                                      {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                                printf("r23 ");
                            }
#line 937 "parser.tab.cc"
    break;

  case 27:
#line 222 "parser.yy"
                             {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                                printf("r24 ");
                            }
#line 946 "parser.tab.cc"
    break;

  case 28:
#line 228 "parser.yy"
                                              {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r25 ");
                        }
#line 956 "parser.tab.cc"
    break;

  case 29:
#line 233 "parser.yy"
                                  {
                            yylhs.value.as < Node * > () = new Node("Statement List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r25.1 ");
                        }
#line 966 "parser.tab.cc"
    break;

  case 30:
#line 240 "parser.yy"
                                                                                            {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());

                                Node* else_node = new Node("ELSE", "");
                                else_node->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(else_node);
                                printf("r29 ");
                            }
#line 981 "parser.tab.cc"
    break;

  case 31:
#line 250 "parser.yy"
                                                                      {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r30 ");
                            }
#line 992 "parser.tab.cc"
    break;

  case 32:
#line 256 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r31 ");
                            }
#line 1002 "parser.tab.cc"
    break;

  case 33:
#line 261 "parser.yy"
                                                      { 
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r32 ");
                            }
#line 1013 "parser.tab.cc"
    break;

  case 34:
#line 267 "parser.yy"
                                                                           {
                                yylhs.value.as < Node * > () = new Node("Assign[]", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r33 ");
                            }
#line 1025 "parser.tab.cc"
    break;

  case 35:
#line 274 "parser.yy"
                        { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1031 "parser.tab.cc"
    break;

  case 36:
#line 277 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r34 ");
                            }
#line 1042 "parser.tab.cc"
    break;

  case 37:
#line 283 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r35 ");
                            }
#line 1053 "parser.tab.cc"
    break;

  case 38:
#line 289 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r36 ");
                            }
#line 1064 "parser.tab.cc"
    break;

  case 39:
#line 295 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r37 ");
                            }
#line 1075 "parser.tab.cc"
    break;

  case 40:
#line 301 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r38 ");
                            }
#line 1086 "parser.tab.cc"
    break;

  case 41:
#line 307 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r39 ");
                            }
#line 1097 "parser.tab.cc"
    break;

  case 42:
#line 313 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r40 ");
                            }
#line 1108 "parser.tab.cc"
    break;

  case 43:
#line 319 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r41 ");
                            }
#line 1119 "parser.tab.cc"
    break;

  case 44:
#line 325 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1130 "parser.tab.cc"
    break;

  case 45:
#line 331 "parser.yy"
                                                      {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1141 "parser.tab.cc"
    break;

  case 46:
#line 337 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("Length Of", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r43 ");
                            }
#line 1151 "parser.tab.cc"
    break;

  case 47:
#line 342 "parser.yy"
                                                                          {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r44 ");
                            }
#line 1163 "parser.tab.cc"
    break;

  case 48:
#line 349 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                                printf("r45 ");
                            }
#line 1172 "parser.tab.cc"
    break;

  case 49:
#line 353 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                                printf("r46 ");
                            }
#line 1181 "parser.tab.cc"
    break;

  case 50:
#line 357 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                                printf("r47 ");
                            }
#line 1190 "parser.tab.cc"
    break;

  case 51:
#line 361 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->type);
                                printf("r48 ");
                            }
#line 1199 "parser.tab.cc"
    break;

  case 52:
#line 365 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                                printf("r49 ");
                            }
#line 1208 "parser.tab.cc"
    break;

  case 53:
#line 369 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r50 ");
                            }
#line 1218 "parser.tab.cc"
    break;

  case 54:
#line 374 "parser.yy"
                                          {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r51 ");
                            }
#line 1228 "parser.tab.cc"
    break;

  case 55:
#line 379 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r52 ");
                            }
#line 1238 "parser.tab.cc"
    break;

  case 56:
#line 384 "parser.yy"
                                      {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r53 ");
                            }
#line 1248 "parser.tab.cc"
    break;

  case 57:
#line 391 "parser.yy"
                                                           {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r54 ");
                            }
#line 1259 "parser.tab.cc"
    break;

  case 58:
#line 397 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Call Expression", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r55 ");
                            }
#line 1269 "parser.tab.cc"
    break;

  case 59:
#line 402 "parser.yy"
                                   {
                                yylhs.value.as < Node * > () = new Node("Function Argument List", "Empty");
                            }
#line 1277 "parser.tab.cc"
    break;

  case 60:
#line 407 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), "");
                                printf("r56 ");
                            }
#line 1286 "parser.tab.cc"
    break;


#line 1290 "parser.tab.cc"

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


  const short parser::yypact_ninf_ = -138;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       7,    25,    45,    34,  -138,    21,  -138,    25,    34,  -138,
      61,    -2,  -138,    65,    25,   104,    70,    37,    60,  -138,
      52,  -138,    25,   103,   104,    92,    74,  -138,    -8,  -138,
      94,    93,    52,  -138,    25,    25,  -138,  -138,  -138,   128,
       2,   100,   106,   105,  -138,   104,   104,   108,    50,  -138,
      25,    55,    25,   102,   104,  -138,   113,   115,   196,  -138,
     196,   116,  -138,  -138,  -138,   121,   125,   126,  -138,    19,
     238,   238,   104,     4,   217,  -138,   405,    39,    32,   217,
     238,   238,   238,   130,   141,    89,  -138,   306,  -138,  -138,
    -138,   238,   238,   238,   238,   238,   238,   238,   238,   238,
      13,   238,   238,   238,   238,   154,   321,   336,   351,   238,
     158,  -138,   236,   236,   144,   144,    89,    89,   160,    63,
      63,  -138,   147,   366,   379,   252,   270,   157,   159,   163,
     162,   392,  -138,   238,  -138,   169,  -138,   165,  -138,   217,
     217,  -138,  -138,   405,    85,   238,  -138,   111,   146,  -138,
     238,   288,   187,  -138,   405,  -138,   174,   217,   167,  -138
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     6,    60,     0,     1,     0,     2,     5,
       0,     0,     4,     0,     0,    11,     0,     0,    25,    27,
      15,    10,     0,     0,    11,     0,     0,     9,     0,    14,
       0,     0,    15,    26,     0,     0,     7,    13,    12,     0,
       0,     0,     0,     0,     8,    23,    23,     0,     0,    22,
       0,     0,     0,     0,     0,    24,     0,     0,    11,    21,
      11,     0,    48,    49,    50,     0,     0,     0,    52,     0,
       0,     0,    19,     0,    20,    29,    35,    51,     0,     0,
       0,     0,     0,     0,     0,    55,    51,     0,    16,    18,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    41,    42,    43,    44,    36,    37,    40,    38,
      39,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    59,    45,     0,    33,     0,     3,     0,
       0,    32,    53,    58,     0,     0,    17,     0,     0,    47,
       0,     0,     0,    31,    57,    34,     0,     0,     0,    30
  };

  const short
  parser::yypgoto_[] =
  {
    -138,  -138,  -138,  -138,   207,    43,   -16,   190,     0,   164,
     177,   171,    17,  -137,   -64,     9,  -138,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    72,    21,    28,    29,    73,
      48,    49,    22,    74,    75,    76,   144,    86
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    26,   147,   148,    27,    14,    11,    62,     4,    89,
      90,    26,     1,    17,    89,   105,    27,     4,    63,    64,
     158,    30,    65,     4,    66,    67,    68,    69,    37,     4,
     121,    83,    36,    41,    42,    62,     4,    15,    70,     7,
      37,    71,    44,    35,    88,     6,    63,    64,   104,    55,
      65,    57,    66,    67,    68,    69,    27,    77,    20,    77,
      10,    26,    50,    50,    18,    19,    70,    32,    84,    71,
      13,    50,    77,    77,   102,    16,    24,    77,    77,    85,
      87,    23,   103,    90,    90,    34,    18,    19,    53,   106,
     107,   108,    54,    56,    90,    25,   100,    54,   101,   122,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    31,
     123,   124,   125,   126,    62,     4,    18,    19,   131,    97,
      98,    99,   100,   149,   101,    63,    64,   150,    33,    65,
      39,    66,    67,    68,    69,    38,    43,    45,    77,    77,
      47,    58,   143,    46,    52,    70,    77,    77,    71,    62,
       4,   152,    60,    61,   151,    79,    77,    77,    80,   154,
      63,    64,    81,    82,    65,   109,    66,    67,    68,    69,
      62,     4,    95,    96,    97,    98,    99,   100,   110,   101,
      70,    63,    64,    71,   133,    65,   153,    66,    67,    68,
      69,    98,    99,   100,   127,   101,   132,   138,   139,    62,
       4,    70,   140,   141,    71,   146,   156,   159,    18,    19,
      63,    64,   145,   157,    65,    12,    66,    67,    68,    69,
      62,     4,    40,    51,    78,    59,     0,     0,     0,     0,
      70,    63,    64,    71,     0,    65,     0,    66,    67,    68,
      69,    62,     4,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    63,    64,    71,     0,     0,     0,     0,     0,
      68,    69,    93,    94,    95,    96,    97,    98,    99,   100,
       0,   101,    70,     0,     0,    71,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,   101,     0,     0,
       0,     0,     0,   136,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,   101,     0,     0,     0,     0,
       0,   137,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,   101,     0,     0,     0,     0,     0,   155,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,   101,     0,     0,   111,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,   101,     0,     0,   128,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,   101,     0,     0,   129,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,   101,     0,     0,   130,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,   101,   134,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,   101,   135,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,   101,   142,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
     101
  };

  const short
  parser::yycheck_[] =
  {
       1,     9,   139,   140,    20,     7,     7,     3,     4,    73,
      74,     9,     5,    14,    78,    79,    32,     4,    14,    15,
     157,    22,    18,     4,    20,    21,    22,    23,    28,     4,
      17,    12,    40,    34,    35,     3,     4,    39,    34,     5,
      40,    37,    40,    26,    40,     0,    14,    15,    16,    50,
      18,    52,    20,    21,    22,    23,    72,    58,    15,    60,
      39,     9,    45,    46,    12,    13,    34,    24,    69,    37,
       9,    54,    73,    74,    35,    10,    39,    78,    79,    70,
      71,    11,    43,   147,   148,    11,    12,    13,    38,    80,
      81,    82,    42,    38,   158,    35,    33,    42,    35,   100,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     6,
     101,   102,   103,   104,     3,     4,    12,    13,   109,    30,
      31,    32,    33,    38,    35,    14,    15,    42,    36,    18,
      37,    20,    21,    22,    23,    41,     8,    37,   139,   140,
      35,    39,   133,    37,    36,    34,   147,   148,    37,     3,
       4,    40,    39,    38,   145,    39,   157,   158,    37,   150,
      14,    15,    37,    37,    18,    35,    20,    21,    22,    23,
       3,     4,    28,    29,    30,    31,    32,    33,    37,    35,
      34,    14,    15,    37,    37,    18,    40,    20,    21,    22,
      23,    31,    32,    33,    40,    35,    38,    40,    39,     3,
       4,    34,    39,    41,    37,    40,    19,    40,    12,    13,
      14,    15,    43,    39,    18,     8,    20,    21,    22,    23,
       3,     4,    32,    46,    60,    54,    -1,    -1,    -1,    -1,
      34,    14,    15,    37,    -1,    18,    -1,    20,    21,    22,
      23,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    14,    15,    37,    -1,    -1,    -1,    -1,    -1,
      22,    23,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    34,    -1,    -1,    37,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    41,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    41,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    45,    46,     4,    61,     0,     5,    47,    48,
      39,    61,    48,     9,     7,    39,    10,    61,    12,    13,
      49,    50,    56,    11,    39,    35,     9,    50,    51,    52,
      61,     6,    49,    36,    11,    56,    40,    52,    41,    37,
      51,    61,    61,     8,    40,    37,    37,    35,    54,    55,
      56,    54,    36,    38,    42,    61,    38,    61,    39,    55,
      39,    38,     3,    14,    15,    18,    20,    21,    22,    23,
      34,    37,    49,    53,    57,    58,    59,    61,    53,    39,
      37,    37,    37,    12,    61,    59,    61,    59,    40,    58,
      58,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    35,    35,    43,    16,    58,    59,    59,    59,    35,
      37,    38,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    17,    61,    59,    59,    59,    59,    40,    38,    38,
      38,    59,    38,    37,    36,    36,    41,    41,    40,    39,
      39,    41,    36,    59,    60,    43,    40,    57,    57,    38,
      42,    59,    40,    40,    59,    41,    19,    39,    57,    40
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    47,    47,    48,    48,    49,
      49,    49,    50,    51,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    55,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    17,     2,     1,     0,     6,     8,     2,
       1,     0,     3,     2,     1,     0,     9,    12,     2,     1,
       1,     3,     1,     0,     2,     1,     3,     1,     2,     1,
      11,     7,     5,     4,     7,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     6,     1,     1,
       1,     1,     1,     5,     4,     2,     3,     3,     1,     0,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "INTEGER_LITERAL", "IDENTIFIER", "CLASS",
  "MAIN", "EXTENDS", "STRING", "PUBLIC", "STATIC", "VOID", "T_Int",
  "T_Bool", "T_True", "T_False", "RETURN", "LENGTH", "IF", "ELSE", "WHILE",
  "SYS_PRINTLN", "THIS", "NEW", "PLUSOP", "MINOP", "MULOP", "DIVOP", "AND",
  "OR", "EQ", "LT", "GT", "DOT", "NOT", "LHKP", "RHKP", "LP", "RP", "'{'",
  "'}'", "';'", "','", "'='", "$accept", "Goal", "MainClass",
  "OptionalClassList", "ClassDeclaration", "VarList", "VarDeclaration",
  "MethodList", "MethodDeclaration", "MethodBodyDeclaration",
  "MethodParameterList", "MethodParameterDecl", "Type", "StatementList",
  "Statement", "Expression", "FunctionArgumentList", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    65,    65,    74,    83,    91,    98,   104,   110,   119,
     124,   129,   135,   143,   148,   153,   159,   165,   174,   180,
     183,   190,   195,   200,   206,   214,   218,   222,   228,   233,
     240,   250,   256,   261,   267,   274,   277,   283,   289,   295,
     301,   307,   313,   319,   325,   331,   337,   342,   349,   353,
     357,   361,   365,   369,   374,   379,   384,   391,   397,   402,
     407
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
#line 1825 "parser.tab.cc"

