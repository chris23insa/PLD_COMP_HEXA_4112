
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by exprParser.
 */
class  exprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by exprParser.
   */
    virtual antlrcpp::Any visitProg(exprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitTypefct(exprParser::TypefctContext *context) = 0;

    virtual antlrcpp::Any visitNomfct(exprParser::NomfctContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitNombre(exprParser::NombreContext *context) = 0;

    virtual antlrcpp::Any visitRet(exprParser::RetContext *context) = 0;


};

