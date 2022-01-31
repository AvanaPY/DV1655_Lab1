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
      case 55: // MethodParameterList
      case 56: // MethodParameterDecl
      case 57: // Type
      case 58: // StatementList
      case 59: // Statement
      case 60: // Expression
      case 61: // FunctionArgumentList
      case 62: // Identifier
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
      case 55: // MethodParameterList
      case 56: // MethodParameterDecl
      case 57: // Type
      case 58: // StatementList
      case 59: // Statement
      case 60: // Expression
      case 61: // FunctionArgumentList
      case 62: // Identifier
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
      case 55: // MethodParameterList
      case 56: // MethodParameterDecl
      case 57: // Type
      case 58: // StatementList
      case 59: // Statement
      case 60: // Expression
      case 61: // FunctionArgumentList
      case 62: // Identifier
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
      case 55: // MethodParameterList
      case 56: // MethodParameterDecl
      case 57: // Type
      case 58: // StatementList
      case 59: // Statement
      case 60: // Expression
      case 61: // FunctionArgumentList
      case 62: // Identifier
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
      case 55: // MethodParameterList
      case 56: // MethodParameterDecl
      case 57: // Type
      case 58: // StatementList
      case 59: // Statement
      case 60: // Expression
      case 61: // FunctionArgumentList
      case 62: // Identifier
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
#line 70 "parser.yy"
                                                    {
                            yylhs.value.as < Node * > () = new Node("Program", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                        }
#line 693 "parser.tab.cc"
    break;

  case 3:
#line 76 "parser.yy"
                                  {
                            yylhs.value.as < Node * > () = new Node("Program", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                        }
#line 703 "parser.tab.cc"
    break;

  case 4:
#line 83 "parser.yy"
                                                                                                                           {
                                                                    yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < Node * > ()->value);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(n);
                                                                }
#line 714 "parser.tab.cc"
    break;

  case 5:
#line 91 "parser.yy"
                                                         {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                        }
#line 726 "parser.tab.cc"
    break;

  case 6:
#line 98 "parser.yy"
                                       {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > () = classes;
                        }
#line 738 "parser.tab.cc"
    break;

  case 7:
#line 107 "parser.yy"
                                                         {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[3].value.as < Node * > ()->value);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        }
#line 747 "parser.tab.cc"
    break;

  case 8:
#line 111 "parser.yy"
                                                                           {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[5].value.as < Node * > ()->value);

                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[3].value.as < Node * > ()->value));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        }
#line 758 "parser.tab.cc"
    break;

  case 9:
#line 117 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[2].value.as < Node * > ()->value);
                        }
#line 766 "parser.tab.cc"
    break;

  case 10:
#line 120 "parser.yy"
                                                                  {
                            yylhs.value.as < Node * > () = new Node("Class", yystack_[4].value.as < Node * > ()->value);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Class Extends", yystack_[2].value.as < Node * > ()->value));
                        }
#line 775 "parser.tab.cc"
    break;

  case 11:
#line 126 "parser.yy"
                                {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());    
                        }
#line 784 "parser.tab.cc"
    break;

  case 12:
#line 130 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  
                        }
#line 793 "parser.tab.cc"
    break;

  case 13:
#line 134 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("Class Body", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                        }
#line 803 "parser.tab.cc"
    break;

  case 14:
#line 141 "parser.yy"
                                               {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                        }
#line 812 "parser.tab.cc"
    break;

  case 15:
#line 145 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Variable List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 821 "parser.tab.cc"
    break;

  case 16:
#line 151 "parser.yy"
                                                {
                            yylhs.value.as < Node * > () = new Node("Variable", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        }
#line 831 "parser.tab.cc"
    break;

  case 17:
#line 158 "parser.yy"
                                                     {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                        }
#line 840 "parser.tab.cc"
    break;

  case 18:
#line 162 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("Method List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 849 "parser.tab.cc"
    break;

  case 19:
#line 168 "parser.yy"
                                                                                                       {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[6].value.as < Node * > ()->value);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        }
#line 859 "parser.tab.cc"
    break;

  case 20:
#line 173 "parser.yy"
                                                                                                                                   {
                            yylhs.value.as < Node * > () = new Node("Method", yystack_[9].value.as < Node * > ()->value);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Type", yystack_[10].value.as < Node * > ()->type));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Returns", yystack_[2].value.as < Node * > ()->value));
                        }
#line 871 "parser.tab.cc"
    break;

  case 21:
#line 182 "parser.yy"
                                                      {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 881 "parser.tab.cc"
    break;

  case 22:
#line 187 "parser.yy"
                                              {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 890 "parser.tab.cc"
    break;

  case 23:
#line 191 "parser.yy"
                                        {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "");
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 899 "parser.tab.cc"
    break;

  case 24:
#line 195 "parser.yy"
                                       {
                                    yylhs.value.as < Node * > () = new Node("Method Body", "Empty");
                                }
#line 907 "parser.tab.cc"
    break;

  case 25:
#line 200 "parser.yy"
                                                                    {
                            yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                        }
#line 916 "parser.tab.cc"
    break;

  case 26:
#line 204 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("Parameter List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 925 "parser.tab.cc"
    break;

  case 27:
#line 208 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("Arguments", "None");
                        }
#line 933 "parser.tab.cc"
    break;

  case 28:
#line 213 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("Parameter", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 943 "parser.tab.cc"
    break;

  case 29:
#line 220 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("Int", "");
                            }
#line 951 "parser.tab.cc"
    break;

  case 30:
#line 223 "parser.yy"
                                        {
                                yylhs.value.as < Node * > () = new Node("Int[]", "");
                            }
#line 959 "parser.tab.cc"
    break;

  case 31:
#line 226 "parser.yy"
                               {
                                yylhs.value.as < Node * > () = new Node("Bool", "");
                            }
#line 967 "parser.tab.cc"
    break;

  case 32:
#line 229 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                        }
#line 975 "parser.tab.cc"
    break;

  case 33:
#line 234 "parser.yy"
                                                {
                            yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > ();
                        }
#line 984 "parser.tab.cc"
    break;

  case 34:
#line 238 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node("Statement List", "");
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 993 "parser.tab.cc"
    break;

  case 35:
#line 244 "parser.yy"
                                              {
                                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                            }
#line 1001 "parser.tab.cc"
    break;

  case 36:
#line 247 "parser.yy"
                                                                     {
                                yylhs.value.as < Node * > () = new Node("IF", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1012 "parser.tab.cc"
    break;

  case 37:
#line 253 "parser.yy"
                                                         {
                                yylhs.value.as < Node * > () = new Node("While", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1022 "parser.tab.cc"
    break;

  case 38:
#line 258 "parser.yy"
                                                               {
                                yylhs.value.as < Node * > () = new Node("SYS_PRINTLN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            }
#line 1031 "parser.tab.cc"
    break;

  case 39:
#line 262 "parser.yy"
                                                                  { 
                                yylhs.value.as < Node * > () = new Node("Assign", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1041 "parser.tab.cc"
    break;

  case 40:
#line 267 "parser.yy"
                                                                                       {
                                yylhs.value.as < Node * > () = new Node("Assign[]", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1052 "parser.tab.cc"
    break;

  case 41:
#line 273 "parser.yy"
                        { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1058 "parser.tab.cc"
    break;

  case 42:
#line 276 "parser.yy"
                                                {
                                yylhs.value.as < Node * > () = new Node("AND", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1068 "parser.tab.cc"
    break;

  case 43:
#line 281 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("OR", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1078 "parser.tab.cc"
    break;

  case 44:
#line 286 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("LESS THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1088 "parser.tab.cc"
    break;

  case 45:
#line 291 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("GREATER THAN", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1098 "parser.tab.cc"
    break;

  case 46:
#line 296 "parser.yy"
                                               {
                                yylhs.value.as < Node * > () = new Node("EQUALS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1108 "parser.tab.cc"
    break;

  case 47:
#line 301 "parser.yy"
                                                   {
                                yylhs.value.as < Node * > () = new Node("PLUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1118 "parser.tab.cc"
    break;

  case 48:
#line 306 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MINUS", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1128 "parser.tab.cc"
    break;

  case 49:
#line 311 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("MULT", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1138 "parser.tab.cc"
    break;

  case 50:
#line 316 "parser.yy"
                                                  {
                                yylhs.value.as < Node * > () = new Node("DIV", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1148 "parser.tab.cc"
    break;

  case 51:
#line 321 "parser.yy"
                                                      {
                                yylhs.value.as < Node * > () = new Node("Indexing", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1158 "parser.tab.cc"
    break;

  case 52:
#line 326 "parser.yy"
                                            {
                                yylhs.value.as < Node * > () = new Node("Length Of", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            }
#line 1167 "parser.tab.cc"
    break;

  case 53:
#line 330 "parser.yy"
                                                                          {
                                yylhs.value.as < Node * > () = new Node("Function Call", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1178 "parser.tab.cc"
    break;

  case 54:
#line 336 "parser.yy"
                                                    {
                                yylhs.value.as < Node * > () = new Node("new[]", yystack_[3].value.as < std::string > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1187 "parser.tab.cc"
    break;

  case 55:
#line 340 "parser.yy"
                                          {
                                yylhs.value.as < Node * > () = new Node("new()", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            }
#line 1196 "parser.tab.cc"
    break;

  case 56:
#line 344 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Negate", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1205 "parser.tab.cc"
    break;

  case 57:
#line 348 "parser.yy"
                                      {
                                yylhs.value.as < Node * > () = new Node("Statement", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1214 "parser.tab.cc"
    break;

  case 58:
#line 352 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < Node * > ()->value);
                            }
#line 1222 "parser.tab.cc"
    break;

  case 59:
#line 355 "parser.yy"
                                     {
                                yylhs.value.as < Node * > () = new Node("Integer", yystack_[0].value.as < std::string > ());
                            }
#line 1230 "parser.tab.cc"
    break;

  case 60:
#line 358 "parser.yy"
                            {
                                yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > ());
                            }
#line 1238 "parser.tab.cc"
    break;

  case 61:
#line 361 "parser.yy"
                              {
                                yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > ());
                            }
#line 1246 "parser.tab.cc"
    break;

  case 62:
#line 364 "parser.yy"
                           {
                                yylhs.value.as < Node * > () = new Node("THIS", "");
                            }
#line 1254 "parser.tab.cc"
    break;

  case 63:
#line 369 "parser.yy"
                                                             {
                                yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                            }
#line 1263 "parser.tab.cc"
    break;

  case 64:
#line 373 "parser.yy"
                                    {
                                yylhs.value.as < Node * > () = new Node("Function Arguments", "");
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1272 "parser.tab.cc"
    break;

  case 65:
#line 377 "parser.yy"
                                   {
                                yylhs.value.as < Node * > () = new Node("Function Argument List", "Empty");
                            }
#line 1280 "parser.tab.cc"
    break;

  case 66:
#line 381 "parser.yy"
                                 {
                                yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > ());
                            }
#line 1288 "parser.tab.cc"
    break;


#line 1292 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -74;

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
       4,     0,    38,    46,   -74,    27,   -74,     0,    46,   -74,
      59,    -4,   -74,    63,     0,     3,    67,    44,    68,    50,
     -74,   -74,    49,    83,   -74,    85,   -74,     0,   -74,    91,
      57,     0,     0,    66,   -74,   -74,    85,   -74,    65,    71,
     -74,    69,    92,    94,   -74,   -74,   113,   -74,    33,    33,
      87,   -31,   -74,     0,    11,    96,    89,    33,   -74,    97,
       0,   157,   -74,   157,    95,   -74,   -74,   -74,   102,   103,
     105,   -74,     6,    20,    20,   184,   157,   107,   184,   -74,
     201,    21,   133,   110,    20,    20,    20,   115,   114,   117,
     -74,   261,   124,    -8,   184,   -74,   -74,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    23,    20,   -74,    20,
      20,    20,   184,   277,   293,   309,    20,   118,   -74,   -74,
     182,   182,   375,   375,   117,   117,   117,   117,   117,   -74,
     116,   325,   216,   339,   231,   122,   184,   184,   123,   353,
     -74,    20,   -74,   -74,   130,   126,   135,   155,   -74,   -74,
     -74,   367,    43,    20,   -74,   -74,   184,   -74,    20,   246,
     -74,   367,   -74
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,    66,     0,     1,     0,     2,     6,
       0,     0,     5,     0,     0,     0,     0,     0,     0,    29,
      31,     9,     0,    11,    15,    12,    18,     0,    32,     0,
       0,     0,     0,     0,     7,    14,    13,    17,     0,     0,
      10,     0,     0,     0,    30,    16,     0,     8,    27,    27,
       0,     0,    26,     0,     0,     0,     0,     0,    28,     0,
       0,    24,    25,    24,     0,    59,    60,    61,     0,     0,
       0,    62,     0,     0,     0,     0,    23,     0,    22,    34,
       0,    58,     0,     0,     0,     0,     0,     0,     0,    56,
      58,     0,     0,    58,    21,    19,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    35,
      47,    48,    49,    50,    42,    43,    46,    44,    45,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    65,    51,    39,     0,     0,     0,     0,    37,    38,
      54,    64,     0,     0,    20,     4,     0,    53,     0,     0,
      36,    63,    40
  };

  const short
  parser::yypgoto_[] =
  {
     -74,   -74,   -74,   -74,   173,   152,    41,   -22,   160,    40,
     121,   136,   129,   -16,    31,   -73,    15,   -74,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    22,    23,    24,    25,    26,
      77,    51,    52,    27,    78,    79,    80,   152,    90
  };

  const short
  parser::yytable_[] =
  {
       5,    35,    32,    14,     4,    96,    11,     4,    56,     1,
       4,    57,    18,    17,    28,    19,    20,    28,    87,    96,
     109,    96,    28,    65,     4,   -32,    38,     4,   110,    28,
      42,    43,    53,    53,    66,    67,    15,     4,     6,   135,
     129,    53,    71,    72,    21,    19,    20,    28,    28,   109,
      59,     7,    58,    57,    35,    73,    28,   110,    74,    64,
      81,     4,    81,   147,   148,    37,    18,    10,    13,    19,
      20,    88,     4,    16,    93,    81,    37,    93,    29,    31,
      19,    20,   157,   160,    30,   158,    33,     4,    89,    91,
      34,    93,    18,    93,    18,    19,    20,    39,    40,   113,
     114,   115,    76,    44,    76,   130,    92,    94,    45,    46,
      47,    93,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    50,   131,    55,   132,   133,   134,    65,     4,    61,
      48,   139,    49,    60,    83,    93,    93,    63,    66,    67,
      84,    85,    68,    86,    69,    70,    71,    72,    95,   111,
     112,   116,   117,   107,   141,    93,   151,   140,   153,    73,
      65,     4,    74,   146,    75,   119,   149,   154,   159,    19,
      20,    66,    67,   161,   156,    68,   155,    69,    70,    71,
      72,    12,    41,    36,    82,    54,    62,    65,     4,     0,
       0,     0,    73,     0,     0,    74,     0,    75,    66,    67,
       0,     0,    68,     0,    69,    70,    71,    72,    99,   100,
       0,   101,   102,   103,   104,   105,   106,     0,   107,    73,
       0,     0,    74,     0,    75,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,     0,   107,     0,     0,
      97,    98,    99,   100,   108,   101,   102,   103,   104,   105,
     106,     0,   107,     0,     0,    97,    98,    99,   100,   143,
     101,   102,   103,   104,   105,   106,     0,   107,     0,     0,
      97,    98,    99,   100,   145,   101,   102,   103,   104,   105,
     106,     0,   107,     0,     0,    97,    98,    99,   100,   162,
     101,   102,   103,   104,   105,   106,     0,   107,     0,     0,
     118,    97,    98,    99,   100,     0,   101,   102,   103,   104,
     105,   106,     0,   107,     0,     0,   136,    97,    98,    99,
     100,     0,   101,   102,   103,   104,   105,   106,     0,   107,
       0,     0,   137,    97,    98,    99,   100,     0,   101,   102,
     103,   104,   105,   106,     0,   107,     0,     0,   138,    97,
      98,    99,   100,     0,   101,   102,   103,   104,   105,   106,
       0,   107,   142,    97,    98,    99,   100,     0,   101,   102,
     103,   104,   105,   106,     0,   107,   144,    97,    98,    99,
     100,     0,   101,   102,   103,   104,   105,   106,     0,   107,
     150,    97,    98,    99,   100,     0,   101,   102,   103,   104,
     105,   106,     0,   107,   101,   102,   103,   104,   105,   106,
       0,   107
  };

  const short
  parser::yycheck_[] =
  {
       1,    23,    18,     7,     4,    78,     7,     4,    39,     5,
       4,    42,     9,    14,    15,    12,    13,    18,    12,    92,
      28,    94,    23,     3,     4,     4,    27,     4,    36,    30,
      31,    32,    48,    49,    14,    15,    40,     4,     0,   112,
      17,    57,    22,    23,    41,    12,    13,    48,    49,    28,
      39,     5,    53,    42,    76,    35,    57,    36,    38,    60,
      61,     4,    63,   136,   137,    25,     9,    40,     9,    12,
      13,    72,     4,    10,    75,    76,    36,    78,    11,    11,
      12,    13,    39,   156,    40,    42,    36,     4,    73,    74,
      41,    92,     9,    94,     9,    12,    13,     6,    41,    84,
      85,    86,    61,    37,    63,   106,    75,    76,    43,    38,
      41,   112,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     8,   107,    36,   109,   110,   111,     3,     4,    40,
      38,   116,    38,    37,    39,   136,   137,    40,    14,    15,
      38,    38,    18,    38,    20,    21,    22,    23,    41,    16,
      40,    36,    38,    36,    38,   156,   141,    39,    28,    35,
       3,     4,    38,    41,    40,    41,    43,    41,   153,    12,
      13,    14,    15,   158,    19,    18,    41,    20,    21,    22,
      23,     8,    30,    23,    63,    49,    57,     3,     4,    -1,
      -1,    -1,    35,    -1,    -1,    38,    -1,    40,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    35,
      -1,    -1,    38,    -1,    40,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      24,    25,    26,    27,    43,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    24,    25,    26,    27,    43,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      24,    25,    26,    27,    43,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    24,    25,    26,    27,    43,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      39,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    -1,    -1,    39,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    39,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    -1,    -1,    39,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    29,    30,    31,    32,    33,    34,
      -1,    36
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    45,    46,     4,    62,     0,     5,    47,    48,
      40,    62,    48,     9,     7,    40,    10,    62,     9,    12,
      13,    41,    49,    50,    51,    52,    53,    57,    62,    11,
      40,    11,    57,    36,    41,    51,    52,    53,    62,     6,
      41,    49,    62,    62,    37,    43,    38,    41,    38,    38,
       8,    55,    56,    57,    55,    36,    39,    42,    62,    39,
      37,    40,    56,    40,    62,     3,    14,    15,    18,    20,
      21,    22,    23,    35,    38,    40,    50,    54,    58,    59,
      60,    62,    54,    39,    38,    38,    38,    12,    62,    60,
      62,    60,    58,    62,    58,    41,    59,    24,    25,    26,
      27,    29,    30,    31,    32,    33,    34,    36,    43,    28,
      36,    16,    40,    60,    60,    60,    36,    38,    39,    41,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    17,
      62,    60,    60,    60,    60,    59,    39,    39,    39,    60,
      39,    38,    37,    43,    37,    43,    41,    59,    59,    43,
      37,    60,    61,    28,    41,    41,    19,    39,    42,    60,
      59,    60,    43
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    54,    54,    54,    55,    55,    55,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    62
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,    17,     2,     1,     5,     7,     4,
       6,     1,     1,     2,     2,     1,     3,     2,     1,     9,
      12,     2,     1,     1,     0,     3,     1,     0,     2,     1,
       3,     1,     1,     2,     1,     3,     7,     5,     5,     4,
       7,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     6,     5,     4,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     1
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
  "LP", "RP", "LMP", "RMP", "COMMA", "SEMICOLON", "$accept", "Goal",
  "MainClass", "OptionalClassList", "ClassDeclaration", "ClassBody",
  "VarList", "VarDeclaration", "MethodList", "MethodDeclaration",
  "MethodBodyDeclaration", "MethodParameterList", "MethodParameterDecl",
  "Type", "StatementList", "Statement", "Expression",
  "FunctionArgumentList", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    70,    70,    76,    83,    91,    98,   107,   111,   117,
     120,   126,   130,   134,   141,   145,   151,   158,   162,   168,
     173,   182,   187,   191,   195,   200,   204,   208,   213,   220,
     223,   226,   229,   234,   238,   244,   247,   253,   258,   262,
     267,   273,   276,   281,   286,   291,   296,   301,   306,   311,
     316,   321,   326,   330,   336,   340,   344,   348,   352,   355,
     358,   361,   364,   369,   373,   377,   381
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

