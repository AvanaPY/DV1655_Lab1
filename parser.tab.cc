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
  

#line 54 "parser.tab.cc"


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
#line 126 "parser.tab.cc"


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
      case 4: // IDENTIFIER
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
      case 4: // IDENTIFIER
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
      case 4: // IDENTIFIER
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
      case 4: // IDENTIFIER
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
      case 4: // IDENTIFIER
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

#line 558 "parser.tab.cc"

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
      -4,    11,     3,    25,   -52,    34,   -52,    11,    41,    66,
      33,   -52,    61,    11,    13,    68,    44,    42,   -52,    13,
      11,   -52,    73,    13,    46,    -6,    11,    47,    63,    13,
     -52,    13,   -52,    51,   -52,    64,     9,    11,   -52,    65,
     -52,    87,    85,    13,    11,   -35,    11,    60,    90,    13,
     -52,    91,    13,    11,   127,    13,    86,   -52,    92,    98,
     101,   127,    97,    28,    13,   117,   -52,    28,     5,     5,
       5,    57,   100,     5,     5,     5,   -52,   -52,   -52,   -52,
     -52,    20,     5,     5,   139,   -52,   161,   183,   -52,   103,
     -52,   205,   227,   249,    89,   106,   271,   359,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,   127,    62,
     127,   107,   -52,    95,   -52,   109,     5,     5,   -52,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   293,   131,
     -52,   115,   -52,   -52,     5,   -52,   315,   359,    54,   -52,
     127,   113,   337,   -52,   -52,     5,   -52,   -52,   -52,   359
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    54,     0,     1,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,    21,    20,     9,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     9,
      19,     0,     4,     0,     7,     0,     0,     0,     6,     0,
       5,     0,     0,    12,     0,     0,     0,     0,     0,     0,
      10,     0,    15,     0,     0,    14,    18,    11,     0,     0,
       0,     0,     0,     0,    13,     0,    17,    22,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    42,    43,    44,
      46,     0,     0,     0,     0,    45,     0,     0,    24,     0,
       3,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,    28,     0,     0,    53,    50,    35,
      36,    37,    38,    30,    31,    34,    32,    33,     0,     0,
      40,     0,    26,    27,     0,     8,     0,    52,     0,    39,
       0,     0,     0,    47,    48,     0,    25,    41,    29,    51
  };

  const signed char
  parser::yypgoto_[] =
  {
     -52,   -52,   -52,   -52,     6,   124,   -52,   -52,   -52,    -8,
     -51,    12,   -52,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,    19,    25,    45,    56,    65,    20,
      62,    84,   138,    85
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    31,     1,     6,    48,    66,    10,    49,    77,     4,
      71,    26,    16,    21,    76,     4,    31,     4,    21,    27,
      89,    26,    21,    37,     4,    33,    78,    79,    21,    29,
      21,     7,    17,    18,    32,    46,    41,    80,    81,    94,
      82,    53,    21,    47,    13,    50,    11,    26,    21,    40,
      83,    21,    57,    63,    21,    67,    26,   129,    55,   132,
      63,     4,    64,    21,    63,    73,     4,    14,     9,    15,
      63,    74,    58,    12,    59,    60,   130,    22,    23,    24,
      95,    86,    87,    28,    30,    91,    92,    93,    34,   146,
       4,    61,    38,   144,    96,    97,   145,    88,    35,    51,
      39,    58,    42,    59,    60,    17,    18,    63,   131,    63,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      61,     4,    43,    44,    52,    54,   116,    68,   136,   137,
      75,     4,    58,    69,    59,    60,    70,    72,   134,    63,
      90,   117,    58,   112,    59,    60,   142,   140,   133,   135,
     141,    61,   147,    36,     0,     0,     0,   149,     0,     0,
       0,    61,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,   107,     0,   108,     0,
       0,     0,     0,   109,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,   107,     0,
     110,     0,     0,     0,     0,   109,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
     107,     0,   111,     0,     0,     0,     0,   109,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,   107,   113,     0,     0,     0,     0,     0,   109,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,   107,     0,     0,     0,   114,     0,
       0,   109,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,   107,     0,     0,     0,
     115,     0,     0,   109,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,   107,     0,
     118,     0,     0,     0,     0,   109,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
     107,   139,     0,     0,     0,     0,     0,   109,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,   107,   143,     0,     0,     0,     0,     0,   109,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,   107,     0,     0,     0,   148,     0,
       0,   109,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,   109
  };

  const short
  parser::yycheck_[] =
  {
       1,     7,     6,     0,    39,    56,     7,    42,     3,     4,
      61,    19,    13,    14,    65,     4,     7,     4,    19,    20,
      71,    29,    23,    31,     4,    26,    21,    22,    29,    23,
      31,     6,    19,    20,    40,    43,    37,    32,    33,    19,
      35,    49,    43,    44,    11,    46,     5,    55,    49,    40,
      45,    52,    53,    54,    55,    56,    64,   108,    52,   110,
      61,     4,    56,    64,    65,    37,     4,    34,    34,     8,
      71,    43,    15,     7,    17,    18,    14,     9,    34,    37,
      81,    69,    70,    10,    38,    73,    74,    75,    41,   140,
       4,    34,    41,    39,    82,    83,    42,    40,    35,    39,
      36,    15,    37,    17,    18,    19,    20,   108,   109,   110,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      34,     4,    35,    38,    34,    34,    37,    35,   116,   117,
      13,     4,    15,    35,    17,    18,    35,    40,    43,   140,
      40,    35,    15,    40,    17,    18,   134,    16,    41,    40,
      35,    34,    39,    29,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    34,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    44,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    44,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,    44,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    44,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,    47,    48,     4,    59,     0,     6,    49,    34,
      59,     5,     7,    11,    34,     8,    59,    19,    20,    50,
      55,    59,     9,    34,    37,    51,    55,    59,    10,    50,
      38,     7,    40,    59,    41,    35,    51,    55,    41,    36,
      40,    59,    37,    35,    38,    52,    55,    59,    39,    42,
      59,    39,    34,    55,    34,    50,    53,    59,    15,    17,
      18,    34,    56,    59,    50,    54,    56,    59,    35,    35,
      35,    56,    40,    37,    43,    13,    56,     3,    21,    22,
      32,    33,    35,    45,    57,    59,    57,    57,    40,    56,
      40,    57,    57,    57,    19,    59,    57,    57,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    37,    39,    44,
      39,    39,    40,    38,    41,    41,    37,    35,    39,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    56,
      14,    59,    56,    41,    43,    40,    57,    57,    58,    38,
      16,    35,    57,    38,    39,    42,    56,    39,    41,    57
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    59
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     6,     8,     4,     3,    14,     0,
       2,     4,     0,     2,     1,     0,     2,     1,     0,     3,
       1,     1,     1,     4,     3,     7,     5,     5,     4,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     5,     1,     1,     1,     1,     1,     5,     5,     2,
       3,     3,     1,     0,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "INTEGER_LITERAL", "IDENTIFIER", "END",
  "CLASS", "PUBLIC", "STATIC", "VOID", "MAIN", "EXTENDS", "STRING",
  "RETURN", "LENGTH", "IF", "ELSE", "WHILE", "SYS_PRINTLN", "T_Int",
  "T_Bool", "T_True", "T_False", "PLUSOP", "MINOP", "MULOP", "DIVOP",
  "AND", "OR", "EQ", "LT", "GT", "THIS", "NEW", "'{'", "'('", "\"String\"",
  "'['", "']'", "')'", "'}'", "';'", "','", "'='", "'.'", "'!'", "$accept",
  "Goal", "MainClass", "ClassDeclaration", "VarDeclaration",
  "MethodDeclaration", "MethodArgumentDeclaration", "MethodVarDeclaration",
  "MethodStatementDeclaration", "Type", "Statement", "Expression",
  "FunctionCallDeclaration", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    47,    47,    50,    53,    54,    57,    58,    61,    62,
      65,    66,    67,    70,    71,    72,    75,    76,    77,    80,
      81,    82,    83,    86,    87,    88,    89,    90,    91,    92,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   118,   119,   120,   123
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
#line 1079 "parser.tab.cc"

