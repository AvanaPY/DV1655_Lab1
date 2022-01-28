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
      case 49: // ClassBody
      case 50: // VarList
      case 51: // VarDeclaration
      case 52: // MethodList
      case 53: // MethodDeclaration
      case 54: // MethodBodyDeclaration
      case 55: // MBD
      case 56: // MethodParameterList
      case 57: // MethodParameterDecl
      case 58: // Type
      case 59: // StatementList
      case 60: // Statement
      case 61: // Expression
      case 62: // FunctionArgumentList
      case 63: // Identifier
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
      case 49: // ClassBody
      case 50: // VarList
      case 51: // VarDeclaration
      case 52: // MethodList
      case 53: // MethodDeclaration
      case 54: // MethodBodyDeclaration
      case 55: // MBD
      case 56: // MethodParameterList
      case 57: // MethodParameterDecl
      case 58: // Type
      case 59: // StatementList
      case 60: // Statement
      case 61: // Expression
      case 62: // FunctionArgumentList
      case 63: // Identifier
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
      case 49: // ClassBody
      case 50: // VarList
      case 51: // VarDeclaration
      case 52: // MethodList
      case 53: // MethodDeclaration
      case 54: // MethodBodyDeclaration
      case 55: // MBD
      case 56: // MethodParameterList
      case 57: // MethodParameterDecl
      case 58: // Type
      case 59: // StatementList
      case 60: // Statement
      case 61: // Expression
      case 62: // FunctionArgumentList
      case 63: // Identifier
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
      case 49: // ClassBody
      case 50: // VarList
      case 51: // VarDeclaration
      case 52: // MethodList
      case 53: // MethodDeclaration
      case 54: // MethodBodyDeclaration
      case 55: // MBD
      case 56: // MethodParameterList
      case 57: // MethodParameterDecl
      case 58: // Type
      case 59: // StatementList
      case 60: // Statement
      case 61: // Expression
      case 62: // FunctionArgumentList
      case 63: // Identifier
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
      case 49: // ClassBody
      case 50: // VarList
      case 51: // VarDeclaration
      case 52: // MethodList
      case 53: // MethodDeclaration
      case 54: // MethodBodyDeclaration
      case 55: // MBD
      case 56: // MethodParameterList
      case 57: // MethodParameterDecl
      case 58: // Type
      case 59: // StatementList
      case 60: // Statement
      case 61: // Expression
      case 62: // FunctionArgumentList
      case 63: // Identifier
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
#line 69 "parser.yy"
                                                  {
                            yylhs.value.as < Node * > () = new Node("Program", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                            printf("r1 ");
                        }
#line 699 "parser.tab.cc"
    break;

  case 3:
#line 76 "parser.yy"
                                  {
                            yylhs.value.as < Node * > () = new Node("Program", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                            printf("r1 ");
                        }
#line 710 "parser.tab.cc"
    break;

  case 4:
#line 84 "parser.yy"
                                                                                                                           {
                                                                    yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < Node * > ()->type);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(n);
                                                                    printf("r2 ");
                                                                }
#line 722 "parser.tab.cc"
    break;

  case 5:
#line 93 "parser.yy"
                                                         {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                            
                        }
#line 735 "parser.tab.cc"
    break;

  case 6:
#line 101 "parser.yy"
                                       {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = classes;
                        }
#line 747 "parser.tab.cc"
    break;

  case 7:
#line 110 "parser.yy"
                                                         {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[3].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            printf("r5 ");
                        }
#line 757 "parser.tab.cc"
    break;

  case 8:
#line 115 "parser.yy"
                                                                           {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[5].value.as < Node * > ()->type);

                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[3].value.as < Node * > ()->type));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            printf("r6 ");
                        }
#line 769 "parser.tab.cc"
    break;

  case 9:
#line 122 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[2].value.as < Node * > ()->type);
                            printf("r5 ");
                        }
#line 778 "parser.tab.cc"
    break;

  case 10:
#line 126 "parser.yy"
                                                                  {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[4].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[2].value.as < Node * > ()->type));
                            printf("r6 ");
                        }
#line 788 "parser.tab.cc"
    break;

  case 11:
#line 133 "parser.yy"
                                {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());    
                        }
#line 797 "parser.tab.cc"
    break;

  case 12:
#line 137 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  
                        }
#line 806 "parser.tab.cc"
    break;

  case 13:
#line 141 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                        }
#line 816 "parser.tab.cc"
    break;

  case 14:
#line 148 "parser.yy"
                                               {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r7.2 ");
                        }
#line 826 "parser.tab.cc"
    break;

  case 15:
#line 153 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Variable List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r7.1 ");
                        }
#line 836 "parser.tab.cc"
    break;

  case 16:
#line 160 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("Variable", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            printf("r8 ");
                        }
#line 847 "parser.tab.cc"
    break;

  case 17:
#line 168 "parser.yy"
                                                     {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r8.1 ");
                        }
#line 857 "parser.tab.cc"
    break;

  case 18:
#line 173 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("Method List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r8.2 ");
                        }
#line 867 "parser.tab.cc"
    break;

  case 19:
#line 180 "parser.yy"
                                                                                                       {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[6].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            printf("r9.2 ");
                        }
#line 878 "parser.tab.cc"
    break;

  case 20:
#line 186 "parser.yy"
                                                                                                                             {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[9].value.as < Node * > ()->type);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Returns", yystack_[2].value.as < Node * > ()->type));
                            printf("r9.3 ");
                        }
#line 890 "parser.tab.cc"
    break;

  case 21:
#line 195 "parser.yy"
                                                          {
                                    yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                                    printf("r10 ");
                                }
#line 900 "parser.tab.cc"
    break;

  case 22:
#line 200 "parser.yy"
                                    {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                    printf("r10 ");
                                }
#line 910 "parser.tab.cc"
    break;

  case 23:
#line 207 "parser.yy"
                    {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 918 "parser.tab.cc"
    break;

  case 24:
#line 210 "parser.yy"
                           {
                yylhs.value.as < Node * > ()=yystack_[0].value.as < Node * > ();
            }
#line 926 "parser.tab.cc"
    break;

  case 25:
#line 215 "parser.yy"
                                                                  {
                            yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                            printf("r16 ");
                        }
#line 936 "parser.tab.cc"
    break;

  case 26:
#line 220 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("Parameter List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16.1 ");
                        }
#line 946 "parser.tab.cc"
    break;

  case 27:
#line 225 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("Arguments", "None");
                            printf("r16.2 ");
                        }
#line 955 "parser.tab.cc"
    break;

  case 28:
#line 231 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Parameter", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r16 ");
                        }
#line 966 "parser.tab.cc"
    break;

  case 29:
#line 239 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                                printf("r22 ");
                            }
#line 975 "parser.tab.cc"
    break;

  case 30:
#line 243 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                                printf("r23 ");
                            }
#line 984 "parser.tab.cc"
    break;

  case 31:
#line 247 "parser.yy"
                               {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                                printf("r24 ");
                            }
#line 993 "parser.tab.cc"
    break;

  case 32:
#line 251 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                        }
#line 1001 "parser.tab.cc"
    break;

  case 33:
#line 256 "parser.yy"
                                                {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                            printf("r25 ");
                        }
#line 1011 "parser.tab.cc"
    break;

  case 34:
#line 261 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node("Statement List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            printf("r25.1 ");
                        }
#line 1021 "parser.tab.cc"
    break;

  case 35:
#line 268 "parser.yy"
                                                                                            {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());

                                Node* else_node = new Node("ELSE", "");
                                else_node->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(else_node);
                                printf("r29 ");
                            }
#line 1036 "parser.tab.cc"
    break;

  case 36:
#line 278 "parser.yy"
                                                                      {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r30 ");
                            }
#line 1047 "parser.tab.cc"
    break;

  case 37:
#line 284 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r31 ");
                            }
#line 1057 "parser.tab.cc"
    break;

  case 38:
#line 289 "parser.yy"
                                                            { 
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r32 ");
                            }
#line 1068 "parser.tab.cc"
    break;

  case 39:
#line 295 "parser.yy"
                                                                                 {
                                yylhs.value.as < Node * > () = new Node("Assign[]", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r33 ");
                            }
#line 1080 "parser.tab.cc"
    break;

  case 40:
#line 302 "parser.yy"
                        { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1086 "parser.tab.cc"
    break;

  case 41:
#line 305 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r34 ");
                            }
#line 1097 "parser.tab.cc"
    break;

  case 42:
#line 311 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r35 ");
                            }
#line 1108 "parser.tab.cc"
    break;

  case 43:
#line 317 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r36 ");
                            }
#line 1119 "parser.tab.cc"
    break;

  case 44:
#line 323 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r37 ");
                            }
#line 1130 "parser.tab.cc"
    break;

  case 45:
#line 329 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r38 ");
                            }
#line 1141 "parser.tab.cc"
    break;

  case 46:
#line 335 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r39 ");
                            }
#line 1152 "parser.tab.cc"
    break;

  case 47:
#line 341 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r40 ");
                            }
#line 1163 "parser.tab.cc"
    break;

  case 48:
#line 347 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r41 ");
                            }
#line 1174 "parser.tab.cc"
    break;

  case 49:
#line 353 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1185 "parser.tab.cc"
    break;

  case 50:
#line 359 "parser.yy"
                                                      {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r42 ");
                            }
#line 1196 "parser.tab.cc"
    break;

  case 51:
#line 365 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("Length Of", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r43 ");
                            }
#line 1206 "parser.tab.cc"
    break;

  case 52:
#line 370 "parser.yy"
                                                                          {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r44 ");
                            }
#line 1218 "parser.tab.cc"
    break;

  case 53:
#line 377 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r50 ");
                            }
#line 1228 "parser.tab.cc"
    break;

  case 54:
#line 382 "parser.yy"
                                          {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                printf("r51 ");
                            }
#line 1238 "parser.tab.cc"
    break;

  case 55:
#line 387 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r52 ");
                            }
#line 1248 "parser.tab.cc"
    break;

  case 56:
#line 392 "parser.yy"
                                      {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                printf("r53 ");
                            }
#line 1258 "parser.tab.cc"
    break;

  case 57:
#line 397 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->type);
                                printf("r48 ");
                            }
#line 1267 "parser.tab.cc"
    break;

  case 58:
#line 401 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                                printf("r45 ");
                            }
#line 1276 "parser.tab.cc"
    break;

  case 59:
#line 405 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                                printf("r46 ");
                            }
#line 1285 "parser.tab.cc"
    break;

  case 60:
#line 409 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                                printf("r47 ");
                            }
#line 1294 "parser.tab.cc"
    break;

  case 61:
#line 413 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                                printf("r49 ");
                            }
#line 1303 "parser.tab.cc"
    break;

  case 62:
#line 419 "parser.yy"
                                                           {
                                yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                                printf("r54 ");
                            }
#line 1313 "parser.tab.cc"
    break;

  case 63:
#line 424 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Arguments", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                printf("r55 ");
                            }
#line 1323 "parser.tab.cc"
    break;

  case 64:
#line 429 "parser.yy"
                                   {
                                yylhs.value.as < Node * > () = new Node("Function Argument List", "Empty");
                            }
#line 1331 "parser.tab.cc"
    break;

  case 65:
#line 434 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), "");
                                printf("r56 ");
                            }
#line 1340 "parser.tab.cc"
    break;


#line 1344 "parser.tab.cc"

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

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
      19,    41,    46,    61,  -138,    27,  -138,    41,    61,  -138,
      59,    11,  -138,    87,    41,     3,    82,    58,    72,    63,
    -138,  -138,    64,    83,  -138,    91,  -138,    41,  -138,   100,
      28,    41,    41,    70,  -138,  -138,    91,  -138,    66,    71,
    -138,    81,    73,    74,  -138,  -138,   116,  -138,    51,    51,
      92,   -18,  -138,    41,    22,    93,    89,    51,  -138,    94,
      41,   263,  -138,   263,    96,  -138,  -138,  -138,    95,    98,
      99,  -138,     7,    35,    35,    51,   137,  -138,   285,  -138,
     300,     0,   236,   102,    35,    35,    35,   103,   105,   110,
    -138,   356,  -138,  -138,  -138,    44,    35,    35,    35,    35,
      35,    35,    35,    35,    35,     6,    35,  -138,    35,    35,
      35,   285,   372,   388,   404,    35,   108,  -138,   283,   283,
     160,   160,   110,   110,   110,   110,   110,  -138,   123,   420,
     314,   434,   328,    90,   122,   127,   106,   448,  -138,    35,
    -138,  -138,   141,    97,   129,   285,   285,  -138,  -138,   462,
      43,    35,  -138,  -138,   162,   184,  -138,    35,   342,   152,
    -138,   462,  -138,   133,   285,   206,  -138
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,    65,     0,     1,     0,     2,     6,
       0,     0,     5,     0,     0,     0,     0,     0,     0,    29,
      31,     9,     0,    11,    15,    12,    18,     0,    32,     0,
       0,     0,     0,     0,     7,    14,    13,    17,     0,     0,
      10,     0,     0,     0,    30,    16,     0,     8,    27,    27,
       0,     0,    26,     0,     0,     0,     0,     0,    28,     0,
       0,     0,    25,     0,     0,    58,    59,    60,     0,     0,
       0,    61,     0,     0,     0,    23,     0,    22,    24,    34,
       0,    57,     0,     0,     0,     0,     0,     0,     0,    55,
      57,     0,    19,    21,    33,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    46,    47,
      48,    49,    41,    42,    45,    43,    44,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    64,
      50,    38,     0,     0,     0,     0,     0,    37,    53,    63,
       0,     0,    20,     4,     0,     0,    52,     0,     0,     0,
      36,    62,    39,     0,     0,     0,    35
  };

  const short
  parser::yypgoto_[] =
  {
    -138,  -138,  -138,  -138,   171,   151,   -10,   -22,   163,    18,
     132,    12,   159,   144,   -15,  -137,   -76,    17,  -138,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    22,    75,    24,    25,    26,
      76,    77,    51,    52,    27,    78,    79,    80,   150,    90
  };

  const short
  parser::yytable_[] =
  {
       5,    35,    94,    32,   -32,    23,    11,     4,   154,   155,
       4,     4,    18,    17,    28,    19,    20,    28,    14,    87,
      23,    56,    28,   127,     1,    57,    38,   165,   108,    28,
      42,    43,     4,    53,    53,   133,   109,    18,    65,     4,
      19,    20,    53,    37,    21,     4,     6,    28,    28,    66,
      67,    15,    58,    35,    37,     4,    28,    71,    72,    64,
      81,    59,    81,    19,    20,    57,     7,    10,    13,    40,
      73,    88,   108,    74,    28,    81,     4,    95,    94,    94,
     109,    81,   156,    31,    19,    20,   157,     4,    93,    94,
      89,    91,    18,    29,    93,    19,    20,    16,    30,    33,
      18,   112,   113,   114,   128,    34,    39,    44,    45,    46,
      95,    48,    49,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    47,   129,    50,   130,   131,   132,    55,    61,
      60,   144,   137,    84,    63,    83,    85,    86,   152,   115,
      65,     4,   111,   116,    95,    95,   106,   138,   147,    19,
      20,    66,    67,    95,    95,    68,   149,    69,    70,    71,
      72,   139,   145,    95,    95,    65,     4,   146,   158,   151,
     153,   163,    73,   164,   161,    74,    66,    67,    92,    12,
      68,    41,    69,    70,    71,    72,    36,    65,     4,   100,
     101,   102,   103,   104,   105,    82,   106,    73,    66,    67,
      74,    62,    68,   159,    69,    70,    71,    72,    54,    65,
       4,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      66,    67,    74,     0,    68,   160,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       4,    73,     0,     0,    74,     0,     0,   166,    19,    20,
      66,    67,   110,     0,    68,     0,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,    65,     4,     0,     0,
       0,    73,     0,     0,    74,    19,    20,    66,    67,     0,
       0,    68,     0,    69,    70,    71,    72,     0,    65,     4,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    66,
      67,    74,     0,    68,     0,    69,    70,    71,    72,    98,
      99,     0,   100,   101,   102,   103,   104,   105,     0,   106,
      73,     0,     0,    74,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,   105,     0,   106,     0,    96,    97,
      98,    99,   107,   100,   101,   102,   103,   104,   105,     0,
     106,     0,    96,    97,    98,    99,   141,   100,   101,   102,
     103,   104,   105,     0,   106,     0,    96,    97,    98,    99,
     143,   100,   101,   102,   103,   104,   105,     0,   106,     0,
      96,    97,    98,    99,   162,   100,   101,   102,   103,   104,
     105,     0,   106,     0,     0,   117,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,   134,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,     0,   106,     0,     0,   135,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,   136,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,   105,     0,   106,   140,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,     0,
     106,   142,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,     0,   106,   148,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,   105,     0,   106
  };

  const short
  parser::yycheck_[] =
  {
       1,    23,    78,    18,     4,    15,     7,     4,   145,   146,
       4,     4,     9,    14,    15,    12,    13,    18,     7,    12,
      30,    39,    23,    17,     5,    43,    27,   164,    28,    30,
      31,    32,     4,    48,    49,   111,    36,     9,     3,     4,
      12,    13,    57,    25,    41,     4,     0,    48,    49,    14,
      15,    40,    53,    75,    36,     4,    57,    22,    23,    60,
      61,    39,    63,    12,    13,    43,     5,    40,     9,    41,
      35,    72,    28,    38,    75,    76,     4,    78,   154,   155,
      36,    82,    39,    11,    12,    13,    43,     4,    76,   165,
      73,    74,     9,    11,    82,    12,    13,    10,    40,    36,
       9,    84,    85,    86,   105,    41,     6,    37,    42,    38,
     111,    38,    38,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    41,   106,     8,   108,   109,   110,    36,    40,
      37,    41,   115,    38,    40,    39,    38,    38,    41,    36,
       3,     4,    40,    38,   145,   146,    36,    39,    42,    12,
      13,    14,    15,   154,   155,    18,   139,    20,    21,    22,
      23,    38,    40,   164,   165,     3,     4,    40,   151,    28,
      41,    19,    35,    40,   157,    38,    14,    15,    41,     8,
      18,    30,    20,    21,    22,    23,    23,     3,     4,    29,
      30,    31,    32,    33,    34,    63,    36,    35,    14,    15,
      38,    57,    18,    41,    20,    21,    22,    23,    49,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      14,    15,    38,    -1,    18,    41,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    35,    -1,    -1,    38,    -1,    -1,    41,    12,    13,
      14,    15,    16,    -1,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    35,    -1,    -1,    38,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    -1,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    14,
      15,    38,    -1,    18,    -1,    20,    21,    22,    23,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      35,    -1,    -1,    38,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    24,    25,
      26,    27,    42,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    24,    25,    26,    27,    42,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    24,    25,    26,    27,
      42,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      24,    25,    26,    27,    42,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    39,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    39,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    39,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    39,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    45,    46,     4,    63,     0,     5,    47,    48,
      40,    63,    48,     9,     7,    40,    10,    63,     9,    12,
      13,    41,    49,    50,    51,    52,    53,    58,    63,    11,
      40,    11,    58,    36,    41,    51,    52,    53,    63,     6,
      41,    49,    63,    63,    37,    42,    38,    41,    38,    38,
       8,    56,    57,    58,    56,    36,    39,    43,    63,    39,
      37,    40,    57,    40,    63,     3,    14,    15,    18,    20,
      21,    22,    23,    35,    38,    50,    54,    55,    59,    60,
      61,    63,    54,    39,    38,    38,    38,    12,    63,    61,
      63,    61,    41,    55,    60,    63,    24,    25,    26,    27,
      29,    30,    31,    32,    33,    34,    36,    42,    28,    36,
      16,    40,    61,    61,    61,    36,    38,    39,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    17,    63,    61,
      61,    61,    61,    60,    39,    39,    39,    61,    39,    38,
      37,    42,    37,    42,    41,    40,    40,    42,    37,    61,
      62,    28,    41,    41,    59,    59,    39,    43,    61,    41,
      41,    61,    42,    19,    40,    59,    41
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,    17,     2,     1,     5,     7,     4,
       6,     1,     1,     2,     2,     1,     3,     2,     1,     9,
      12,     2,     1,     1,     1,     3,     1,     0,     2,     1,
       3,     1,     1,     2,     1,    11,     7,     5,     4,     7,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     6,     5,     4,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "INTEGER_LITERAL", "IDENTIFIER", "CLASS",
  "MAIN", "EXTENDS", "STRING", "PUBLIC", "STATIC", "VOID", "T_Int",
  "T_Bool", "T_True", "T_False", "RETURN", "LENGTH", "IF", "ELSE", "WHILE",
  "SYS_PRINTLN", "THIS", "NEW", "PLUSOP", "MINOP", "MULOP", "DIVOP",
  "ASSIGN_OP", "AND", "OR", "EQ", "LT", "GT", "DOT", "NOT", "LHKP", "RHKP",
  "LP", "RP", "'{'", "'}'", "';'", "','", "$accept", "Goal", "MainClass",
  "OptionalClassList", "ClassDeclaration", "ClassBody", "VarList",
  "VarDeclaration", "MethodList", "MethodDeclaration",
  "MethodBodyDeclaration", "MBD", "MethodParameterList",
  "MethodParameterDecl", "Type", "StatementList", "Statement",
  "Expression", "FunctionArgumentList", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    69,    69,    76,    84,    93,   101,   110,   115,   122,
     126,   133,   137,   141,   148,   153,   160,   168,   173,   180,
     186,   195,   200,   207,   210,   215,   220,   225,   231,   239,
     243,   247,   251,   256,   261,   268,   278,   284,   289,   295,
     302,   305,   311,   317,   323,   329,   335,   341,   347,   353,
     359,   365,   370,   377,   382,   387,   392,   397,   401,   405,
     409,   413,   419,   424,   429,   434
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
#line 1893 "parser.tab.cc"

