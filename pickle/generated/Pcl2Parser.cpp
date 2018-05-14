
#include "wci/intermediate/symtab.h"
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7


#include "Pcl2Listener.h"
#include "Pcl2Visitor.h"

#include "Pcl2Parser.h"


using namespace antlrcpp;
using namespace antlr4;

Pcl2Parser::Pcl2Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Pcl2Parser::~Pcl2Parser() {
  delete _interpreter;
}

std::string Pcl2Parser::getGrammarFileName() const {
  return "Pcl2.g4";
}

const std::vector<std::string>& Pcl2Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Pcl2Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

Pcl2Parser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::CompilationUnitContext::EOF() {
  return getToken(Pcl2Parser::EOF, 0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::CompilationUnitContext::translationUnit() {
  return getRuleContext<Pcl2Parser::TranslationUnitContext>(0);
}


size_t Pcl2Parser::CompilationUnitContext::getRuleIndex() const {
  return Pcl2Parser::RuleCompilationUnit;
}

void Pcl2Parser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void Pcl2Parser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any Pcl2Parser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::CompilationUnitContext* Pcl2Parser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, Pcl2Parser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::Semi))) != 0)) {
      setState(50);
      translationUnit(0);
    }
    setState(53);
    match(Pcl2Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

Pcl2Parser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ExternalDeclarationContext* Pcl2Parser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<Pcl2Parser::ExternalDeclarationContext>(0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::TranslationUnitContext::translationUnit() {
  return getRuleContext<Pcl2Parser::TranslationUnitContext>(0);
}


size_t Pcl2Parser::TranslationUnitContext::getRuleIndex() const {
  return Pcl2Parser::RuleTranslationUnit;
}

void Pcl2Parser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void Pcl2Parser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any Pcl2Parser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::TranslationUnitContext* Pcl2Parser::translationUnit() {
   return translationUnit(0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  Pcl2Parser::TranslationUnitContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, Pcl2Parser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(56);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(62);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(58);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(59);
        externalDeclaration(); 
      }
      setState(64);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

Pcl2Parser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::FunctionDefinitionContext* Pcl2Parser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<Pcl2Parser::FunctionDefinitionContext>(0);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::ExternalDeclarationContext::declaration() {
  return getRuleContext<Pcl2Parser::DeclarationContext>(0);
}

tree::TerminalNode* Pcl2Parser::ExternalDeclarationContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}


size_t Pcl2Parser::ExternalDeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleExternalDeclaration;
}

void Pcl2Parser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void Pcl2Parser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any Pcl2Parser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExternalDeclarationContext* Pcl2Parser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, Pcl2Parser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(66);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(67);
      match(Pcl2Parser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

Pcl2Parser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::FunctionDefinitionContext::typeSpecifier() {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(0);
}

tree::TerminalNode* Pcl2Parser::FunctionDefinitionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

Pcl2Parser::ParameterTypeListContext* Pcl2Parser::FunctionDefinitionContext::parameterTypeList() {
  return getRuleContext<Pcl2Parser::ParameterTypeListContext>(0);
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<Pcl2Parser::CompoundStatementContext>(0);
}


size_t Pcl2Parser::FunctionDefinitionContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionDefinition;
}

void Pcl2Parser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void Pcl2Parser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any Pcl2Parser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionDefinitionContext* Pcl2Parser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 6, Pcl2Parser::RuleFunctionDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    typeSpecifier();
    setState(71);
    match(Pcl2Parser::Identifier);
    setState(72);
    parameterTypeList();
    setState(73);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

Pcl2Parser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Pcl2Parser::TypeSpecifierContext *> Pcl2Parser::FunctionDeclarationContext::typeSpecifier() {
  return getRuleContexts<Pcl2Parser::TypeSpecifierContext>();
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::FunctionDeclarationContext::typeSpecifier(size_t i) {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(i);
}

std::vector<tree::TerminalNode *> Pcl2Parser::FunctionDeclarationContext::Identifier() {
  return getTokens(Pcl2Parser::Identifier);
}

tree::TerminalNode* Pcl2Parser::FunctionDeclarationContext::Identifier(size_t i) {
  return getToken(Pcl2Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> Pcl2Parser::FunctionDeclarationContext::Comma() {
  return getTokens(Pcl2Parser::Comma);
}

tree::TerminalNode* Pcl2Parser::FunctionDeclarationContext::Comma(size_t i) {
  return getToken(Pcl2Parser::Comma, i);
}


size_t Pcl2Parser::FunctionDeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionDeclaration;
}

void Pcl2Parser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void Pcl2Parser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


antlrcpp::Any Pcl2Parser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionDeclarationContext* Pcl2Parser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, Pcl2Parser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    typeSpecifier();
    setState(76);
    match(Pcl2Parser::Identifier);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Pcl2Parser::Comma) {
      setState(77);
      match(Pcl2Parser::Comma);
      setState(78);
      typeSpecifier();
      setState(79);
      match(Pcl2Parser::Identifier);
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

Pcl2Parser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::DeclarationContext::typeSpecifier() {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(0);
}

std::vector<tree::TerminalNode *> Pcl2Parser::DeclarationContext::Identifier() {
  return getTokens(Pcl2Parser::Identifier);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Identifier(size_t i) {
  return getToken(Pcl2Parser::Identifier, i);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

std::vector<tree::TerminalNode *> Pcl2Parser::DeclarationContext::Comma() {
  return getTokens(Pcl2Parser::Comma);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Comma(size_t i) {
  return getToken(Pcl2Parser::Comma, i);
}

std::vector<Pcl2Parser::AssignmentExpressionContext *> Pcl2Parser::DeclarationContext::assignmentExpression() {
  return getRuleContexts<Pcl2Parser::AssignmentExpressionContext>();
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::DeclarationContext::assignmentExpression(size_t i) {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(i);
}


size_t Pcl2Parser::DeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleDeclaration;
}

void Pcl2Parser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void Pcl2Parser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any Pcl2Parser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, Pcl2Parser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(86);
      typeSpecifier();
      setState(87);
      match(Pcl2Parser::Identifier);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Pcl2Parser::Comma) {
        setState(88);
        match(Pcl2Parser::Comma);
        setState(89);
        match(Pcl2Parser::Identifier);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(95);
      match(Pcl2Parser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(97);
      typeSpecifier();
      setState(98);
      assignmentExpression();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Pcl2Parser::Comma) {
        setState(99);
        match(Pcl2Parser::Comma);
        setState(100);
        assignmentExpression();
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(106);
      match(Pcl2Parser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

Pcl2Parser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Void() {
  return getToken(Pcl2Parser::Void, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Bool() {
  return getToken(Pcl2Parser::Bool, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Char() {
  return getToken(Pcl2Parser::Char, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Int() {
  return getToken(Pcl2Parser::Int, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Float() {
  return getToken(Pcl2Parser::Float, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Double() {
  return getToken(Pcl2Parser::Double, 0);
}


size_t Pcl2Parser::TypeSpecifierContext::getRuleIndex() const {
  return Pcl2Parser::RuleTypeSpecifier;
}

void Pcl2Parser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void Pcl2Parser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any Pcl2Parser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 12, Pcl2Parser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

Pcl2Parser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::FunctionCallContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
}


size_t Pcl2Parser::FunctionCallContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionCall;
}

void Pcl2Parser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void Pcl2Parser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


antlrcpp::Any Pcl2Parser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionCallContext* Pcl2Parser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 14, Pcl2Parser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(Pcl2Parser::Identifier);
    setState(113);
    match(Pcl2Parser::LeftParen);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Pcl2Parser::Identifier) {
      setState(114);
      identifierList();
    }
    setState(117);
    match(Pcl2Parser::RightParen);
    setState(118);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionReturnContext ------------------------------------------------------------------

Pcl2Parser::FunctionReturnContext::FunctionReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::FunctionReturnContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
}


size_t Pcl2Parser::FunctionReturnContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionReturn;
}

void Pcl2Parser::FunctionReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionReturn(this);
}

void Pcl2Parser::FunctionReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionReturn(this);
}


antlrcpp::Any Pcl2Parser::FunctionReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionReturn(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionReturnContext* Pcl2Parser::functionReturn() {
  FunctionReturnContext *_localctx = _tracker.createInstance<FunctionReturnContext>(_ctx, getState());
  enterRule(_localctx, 16, Pcl2Parser::RuleFunctionReturn);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(Pcl2Parser::Identifier);
    setState(121);
    match(Pcl2Parser::LeftParen);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Pcl2Parser::Identifier) {
      setState(122);
      identifierList();
    }
    setState(125);
    match(Pcl2Parser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

Pcl2Parser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::JumpStatementContext::Return() {
  return getToken(Pcl2Parser::Return, 0);
}

tree::TerminalNode* Pcl2Parser::JumpStatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::JumpStatementContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}


size_t Pcl2Parser::JumpStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleJumpStatement;
}

void Pcl2Parser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void Pcl2Parser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any Pcl2Parser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::JumpStatementContext* Pcl2Parser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, Pcl2Parser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(Pcl2Parser::Return);
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (Pcl2Parser::LeftParen - 37))
      | (1ULL << (Pcl2Parser::IntegerConstant - 37))
      | (1ULL << (Pcl2Parser::FloatConstant - 37))
      | (1ULL << (Pcl2Parser::Identifier - 37)))) != 0)) {
      setState(128);
      expression(0);
    }
    setState(131);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

Pcl2Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Pcl2Parser::IdentifierListContext::Identifier() {
  return getTokens(Pcl2Parser::Identifier);
}

tree::TerminalNode* Pcl2Parser::IdentifierListContext::Identifier(size_t i) {
  return getToken(Pcl2Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> Pcl2Parser::IdentifierListContext::Comma() {
  return getTokens(Pcl2Parser::Comma);
}

tree::TerminalNode* Pcl2Parser::IdentifierListContext::Comma(size_t i) {
  return getToken(Pcl2Parser::Comma, i);
}


size_t Pcl2Parser::IdentifierListContext::getRuleIndex() const {
  return Pcl2Parser::RuleIdentifierList;
}

void Pcl2Parser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void Pcl2Parser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any Pcl2Parser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 20, Pcl2Parser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(Pcl2Parser::Identifier);
    setState(138);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Pcl2Parser::Comma) {
      setState(134);
      match(Pcl2Parser::Comma);
      setState(135);
      match(Pcl2Parser::Identifier);
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

Pcl2Parser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::CompoundStatementContext::LeftBrace() {
  return getToken(Pcl2Parser::LeftBrace, 0);
}

tree::TerminalNode* Pcl2Parser::CompoundStatementContext::RightBrace() {
  return getToken(Pcl2Parser::RightBrace, 0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::CompoundStatementContext::blockItemList() {
  return getRuleContext<Pcl2Parser::BlockItemListContext>(0);
}


size_t Pcl2Parser::CompoundStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleCompoundStatement;
}

void Pcl2Parser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void Pcl2Parser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any Pcl2Parser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, Pcl2Parser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(Pcl2Parser::LeftBrace);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::If)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Return)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::While)
      | (1ULL << Pcl2Parser::LeftParen)
      | (1ULL << Pcl2Parser::LeftBrace)
      | (1ULL << Pcl2Parser::PlusPlus)
      | (1ULL << Pcl2Parser::MinusMinus)
      | (1ULL << Pcl2Parser::Semi))) != 0) || ((((_la - 79) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 79)) & ((1ULL << (Pcl2Parser::IntegerConstant - 79))
      | (1ULL << (Pcl2Parser::FloatConstant - 79))
      | (1ULL << (Pcl2Parser::Identifier - 79)))) != 0)) {
      setState(142);
      blockItemList(0);
    }
    setState(145);
    match(Pcl2Parser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

Pcl2Parser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::BlockItemContext* Pcl2Parser::BlockItemListContext::blockItem() {
  return getRuleContext<Pcl2Parser::BlockItemContext>(0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::BlockItemListContext::blockItemList() {
  return getRuleContext<Pcl2Parser::BlockItemListContext>(0);
}


size_t Pcl2Parser::BlockItemListContext::getRuleIndex() const {
  return Pcl2Parser::RuleBlockItemList;
}

void Pcl2Parser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void Pcl2Parser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


antlrcpp::Any Pcl2Parser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::BlockItemListContext* Pcl2Parser::blockItemList() {
   return blockItemList(0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  Pcl2Parser::BlockItemListContext *previousContext = _localctx;
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, Pcl2Parser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(154);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(150);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(151);
        blockItem(); 
      }
      setState(156);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

Pcl2Parser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::StatementContext* Pcl2Parser::BlockItemContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::BlockItemContext::declaration() {
  return getRuleContext<Pcl2Parser::DeclarationContext>(0);
}


size_t Pcl2Parser::BlockItemContext::getRuleIndex() const {
  return Pcl2Parser::RuleBlockItem;
}

void Pcl2Parser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void Pcl2Parser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any Pcl2Parser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::BlockItemContext* Pcl2Parser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 26, Pcl2Parser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::If:
      case Pcl2Parser::Return:
      case Pcl2Parser::While:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::LeftBrace:
      case Pcl2Parser::PlusPlus:
      case Pcl2Parser::MinusMinus:
      case Pcl2Parser::Semi:
      case Pcl2Parser::IntegerConstant:
      case Pcl2Parser::FloatConstant:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(157);
        statement();
        break;
      }

      case Pcl2Parser::Char:
      case Pcl2Parser::Bool:
      case Pcl2Parser::Double:
      case Pcl2Parser::Float:
      case Pcl2Parser::Int:
      case Pcl2Parser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(158);
        declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

Pcl2Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::StatementContext::compoundStatement() {
  return getRuleContext<Pcl2Parser::CompoundStatementContext>(0);
}

Pcl2Parser::ExpressionStatementContext* Pcl2Parser::StatementContext::expressionStatement() {
  return getRuleContext<Pcl2Parser::ExpressionStatementContext>(0);
}

Pcl2Parser::SelectionStatementContext* Pcl2Parser::StatementContext::selectionStatement() {
  return getRuleContext<Pcl2Parser::SelectionStatementContext>(0);
}

Pcl2Parser::IterationStatementContext* Pcl2Parser::StatementContext::iterationStatement() {
  return getRuleContext<Pcl2Parser::IterationStatementContext>(0);
}

Pcl2Parser::AssignmentStatementContext* Pcl2Parser::StatementContext::assignmentStatement() {
  return getRuleContext<Pcl2Parser::AssignmentStatementContext>(0);
}

Pcl2Parser::JumpStatementContext* Pcl2Parser::StatementContext::jumpStatement() {
  return getRuleContext<Pcl2Parser::JumpStatementContext>(0);
}

Pcl2Parser::UnaryStatementContext* Pcl2Parser::StatementContext::unaryStatement() {
  return getRuleContext<Pcl2Parser::UnaryStatementContext>(0);
}

tree::TerminalNode* Pcl2Parser::StatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}


size_t Pcl2Parser::StatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleStatement;
}

void Pcl2Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void Pcl2Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any Pcl2Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::StatementContext* Pcl2Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 28, Pcl2Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(161);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      expressionStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(163);
      selectionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(164);
      iterationStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(165);
      assignmentStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(166);
      jumpStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(167);
      unaryStatement();
      setState(168);
      match(Pcl2Parser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryStatementContext ------------------------------------------------------------------

Pcl2Parser::UnaryStatementContext::UnaryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::UnaryStatementContext::PlusPlus() {
  return getToken(Pcl2Parser::PlusPlus, 0);
}

tree::TerminalNode* Pcl2Parser::UnaryStatementContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::UnaryStatementContext::MinusMinus() {
  return getToken(Pcl2Parser::MinusMinus, 0);
}


size_t Pcl2Parser::UnaryStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleUnaryStatement;
}

void Pcl2Parser::UnaryStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryStatement(this);
}

void Pcl2Parser::UnaryStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryStatement(this);
}


antlrcpp::Any Pcl2Parser::UnaryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitUnaryStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::UnaryStatementContext* Pcl2Parser::unaryStatement() {
  UnaryStatementContext *_localctx = _tracker.createInstance<UnaryStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, Pcl2Parser::RuleUnaryStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(172);
      match(Pcl2Parser::PlusPlus);
      setState(173);
      match(Pcl2Parser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(174);
      match(Pcl2Parser::MinusMinus);
      setState(175);
      match(Pcl2Parser::Identifier);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(176);
      match(Pcl2Parser::Identifier);
      setState(177);
      match(Pcl2Parser::PlusPlus);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(178);
      match(Pcl2Parser::Identifier);
      setState(179);
      match(Pcl2Parser::MinusMinus);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

Pcl2Parser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::AssignmentStatementContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::AssignmentStatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}


size_t Pcl2Parser::AssignmentStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleAssignmentStatement;
}

void Pcl2Parser::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}

void Pcl2Parser::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}


antlrcpp::Any Pcl2Parser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::AssignmentStatementContext* Pcl2Parser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, Pcl2Parser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    assignmentExpression();
    setState(183);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

Pcl2Parser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::ExpressionStatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ExpressionStatementContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}


size_t Pcl2Parser::ExpressionStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleExpressionStatement;
}

void Pcl2Parser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void Pcl2Parser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any Pcl2Parser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExpressionStatementContext* Pcl2Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, Pcl2Parser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (Pcl2Parser::LeftParen - 37))
      | (1ULL << (Pcl2Parser::IntegerConstant - 37))
      | (1ULL << (Pcl2Parser::FloatConstant - 37))
      | (1ULL << (Pcl2Parser::Identifier - 37)))) != 0)) {
      setState(185);
      expression(0);
    }
    setState(188);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

Pcl2Parser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::If() {
  return getToken(Pcl2Parser::If, 0);
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::SelectionStatementContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::StatementContext* Pcl2Parser::SelectionStatementContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}


size_t Pcl2Parser::SelectionStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleSelectionStatement;
}

void Pcl2Parser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void Pcl2Parser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any Pcl2Parser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::SelectionStatementContext* Pcl2Parser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, Pcl2Parser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(Pcl2Parser::If);
    setState(191);
    match(Pcl2Parser::LeftParen);
    setState(192);
    conditionalExpression(0);
    setState(193);
    match(Pcl2Parser::RightParen);
    setState(194);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

Pcl2Parser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::While() {
  return getToken(Pcl2Parser::While, 0);
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::IterationStatementContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::StatementContext* Pcl2Parser::IterationStatementContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}


size_t Pcl2Parser::IterationStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleIterationStatement;
}

void Pcl2Parser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void Pcl2Parser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any Pcl2Parser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::IterationStatementContext* Pcl2Parser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, Pcl2Parser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(Pcl2Parser::While);
    setState(197);
    match(Pcl2Parser::LeftParen);
    setState(198);
    conditionalExpression(0);
    setState(199);
    match(Pcl2Parser::RightParen);
    setState(200);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

Pcl2Parser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::IntegerConstant() {
  return getToken(Pcl2Parser::IntegerConstant, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::FloatConstant() {
  return getToken(Pcl2Parser::FloatConstant, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::PrimaryExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}


size_t Pcl2Parser::PrimaryExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RulePrimaryExpression;
}

void Pcl2Parser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void Pcl2Parser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any Pcl2Parser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::PrimaryExpressionContext* Pcl2Parser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, Pcl2Parser::RulePrimaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(202);
        match(Pcl2Parser::Identifier);
        break;
      }

      case Pcl2Parser::IntegerConstant: {
        enterOuterAlt(_localctx, 2);
        setState(203);
        match(Pcl2Parser::IntegerConstant);
        break;
      }

      case Pcl2Parser::FloatConstant: {
        enterOuterAlt(_localctx, 3);
        setState(204);
        match(Pcl2Parser::FloatConstant);
        break;
      }

      case Pcl2Parser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(205);
        match(Pcl2Parser::LeftParen);
        setState(206);
        expression(0);
        setState(207);
        match(Pcl2Parser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Pcl2Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Pcl2Parser::ExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleExpression;
}

void Pcl2Parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->expr_operator = ctx->expr_operator;
  this->type_letter = ctx->type_letter;
  this->expression_type = ctx->expression_type;
}

//----------------- PrimExprContext ------------------------------------------------------------------

Pcl2Parser::PrimaryExpressionContext* Pcl2Parser::PrimExprContext::primaryExpression() {
  return getRuleContext<Pcl2Parser::PrimaryExpressionContext>(0);
}

Pcl2Parser::PrimExprContext::PrimExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::PrimExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimExpr(this);
}
void Pcl2Parser::PrimExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimExpr(this);
}

antlrcpp::Any Pcl2Parser::PrimExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitPrimExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::MulDivExprContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::MulDivExprContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

Pcl2Parser::MulDivExprContext::MulDivExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::MulDivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivExpr(this);
}
void Pcl2Parser::MulDivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivExpr(this);
}

antlrcpp::Any Pcl2Parser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddminExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::AddminExprContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::AddminExprContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

Pcl2Parser::AddminExprContext::AddminExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::AddminExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddminExpr(this);
}
void Pcl2Parser::AddminExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddminExpr(this);
}

antlrcpp::Any Pcl2Parser::AddminExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAddminExpr(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::expression() {
   return expression(0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  Pcl2Parser::ExpressionContext *previousContext = _localctx;
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, Pcl2Parser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<PrimExprContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(212);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(222);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(220);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(215);
          dynamic_cast<MulDivExprContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << Pcl2Parser::Star)
            | (1ULL << Pcl2Parser::Div)
            | (1ULL << Pcl2Parser::Mod))) != 0))) {
            dynamic_cast<MulDivExprContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(216);
          expression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddminExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(218);
          dynamic_cast<AddminExprContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == Pcl2Parser::Plus

          || _la == Pcl2Parser::Minus)) {
            dynamic_cast<AddminExprContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(219);
          expression(3);
          break;
        }

        } 
      }
      setState(224);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

Pcl2Parser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Pcl2Parser::ConditionalExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleConditionalExpression;
}

void Pcl2Parser::ConditionalExpressionContext::copyFrom(ConditionalExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->iteration_name = ctx->iteration_name;
  this->opr = ctx->opr;
  this->opcode = ctx->opcode;
}

//----------------- BasicConditionalExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::BasicConditionalExprContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::BasicConditionalExprContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

tree::TerminalNode* Pcl2Parser::BasicConditionalExprContext::ConditionalOperator() {
  return getToken(Pcl2Parser::ConditionalOperator, 0);
}

Pcl2Parser::BasicConditionalExprContext::BasicConditionalExprContext(ConditionalExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::BasicConditionalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicConditionalExpr(this);
}
void Pcl2Parser::BasicConditionalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicConditionalExpr(this);
}

antlrcpp::Any Pcl2Parser::BasicConditionalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBasicConditionalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegatedConditionalExprContext ------------------------------------------------------------------

tree::TerminalNode* Pcl2Parser::NegatedConditionalExprContext::Not() {
  return getToken(Pcl2Parser::Not, 0);
}

tree::TerminalNode* Pcl2Parser::NegatedConditionalExprContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::NegatedConditionalExprContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::NegatedConditionalExprContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::NegatedConditionalExprContext::NegatedConditionalExprContext(ConditionalExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::NegatedConditionalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegatedConditionalExpr(this);
}
void Pcl2Parser::NegatedConditionalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegatedConditionalExpr(this);
}

antlrcpp::Any Pcl2Parser::NegatedConditionalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitNegatedConditionalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConnectedConditionalExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ConditionalExpressionContext *> Pcl2Parser::ConnectedConditionalExprContext::conditionalExpression() {
  return getRuleContexts<Pcl2Parser::ConditionalExpressionContext>();
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::ConnectedConditionalExprContext::conditionalExpression(size_t i) {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(i);
}

tree::TerminalNode* Pcl2Parser::ConnectedConditionalExprContext::ConditionalConnectOperator() {
  return getToken(Pcl2Parser::ConditionalConnectOperator, 0);
}

Pcl2Parser::ConnectedConditionalExprContext::ConnectedConditionalExprContext(ConditionalExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::ConnectedConditionalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnectedConditionalExpr(this);
}
void Pcl2Parser::ConnectedConditionalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnectedConditionalExpr(this);
}

antlrcpp::Any Pcl2Parser::ConnectedConditionalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitConnectedConditionalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedConditionalExprContext ------------------------------------------------------------------

tree::TerminalNode* Pcl2Parser::ParenthesizedConditionalExprContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::ParenthesizedConditionalExprContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::ParenthesizedConditionalExprContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::ParenthesizedConditionalExprContext::ParenthesizedConditionalExprContext(ConditionalExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::ParenthesizedConditionalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedConditionalExpr(this);
}
void Pcl2Parser::ParenthesizedConditionalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedConditionalExpr(this);
}

antlrcpp::Any Pcl2Parser::ParenthesizedConditionalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParenthesizedConditionalExpr(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::conditionalExpression() {
   return conditionalExpression(0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::conditionalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, parentState);
  Pcl2Parser::ConditionalExpressionContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, Pcl2Parser::RuleConditionalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BasicConditionalExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(226);
      expression(0);
      setState(227);
      match(Pcl2Parser::ConditionalOperator);
      setState(228);
      expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParenthesizedConditionalExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(230);
      match(Pcl2Parser::LeftParen);
      setState(231);
      conditionalExpression(0);
      setState(232);
      match(Pcl2Parser::RightParen);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NegatedConditionalExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(234);
      match(Pcl2Parser::Not);
      setState(235);
      match(Pcl2Parser::LeftParen);
      setState(236);
      conditionalExpression(0);
      setState(237);
      match(Pcl2Parser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ConnectedConditionalExprContext>(_tracker.createInstance<ConditionalExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleConditionalExpression);
        setState(241);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(242);
        match(Pcl2Parser::ConditionalConnectOperator);
        setState(243);
        conditionalExpression(4); 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

Pcl2Parser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::AssignmentExpressionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::AssignmentExpressionContext::Assign() {
  return getToken(Pcl2Parser::Assign, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::AssignmentExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

Pcl2Parser::FunctionReturnContext* Pcl2Parser::AssignmentExpressionContext::functionReturn() {
  return getRuleContext<Pcl2Parser::FunctionReturnContext>(0);
}


size_t Pcl2Parser::AssignmentExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleAssignmentExpression;
}

void Pcl2Parser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void Pcl2Parser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any Pcl2Parser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, Pcl2Parser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      match(Pcl2Parser::Identifier);
      setState(250);
      match(Pcl2Parser::Assign);
      setState(251);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(252);
      match(Pcl2Parser::Identifier);
      setState(253);
      match(Pcl2Parser::Assign);
      setState(254);
      functionReturn();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

Pcl2Parser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::ParameterTypeListContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::ParameterTypeListContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::FunctionDeclarationContext* Pcl2Parser::ParameterTypeListContext::functionDeclaration() {
  return getRuleContext<Pcl2Parser::FunctionDeclarationContext>(0);
}


size_t Pcl2Parser::ParameterTypeListContext::getRuleIndex() const {
  return Pcl2Parser::RuleParameterTypeList;
}

void Pcl2Parser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void Pcl2Parser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}


antlrcpp::Any Pcl2Parser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ParameterTypeListContext* Pcl2Parser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 48, Pcl2Parser::RuleParameterTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(Pcl2Parser::LeftParen);
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void))) != 0)) {
      setState(258);
      functionDeclaration();
    }
    setState(261);
    match(Pcl2Parser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Pcl2Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 12: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 21: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 22: return conditionalExpressionSempred(dynamic_cast<ConditionalExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::conditionalExpressionSempred(ConditionalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Pcl2Parser::_decisionToDFA;
atn::PredictionContextCache Pcl2Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Pcl2Parser::_atn;
std::vector<uint16_t> Pcl2Parser::_serializedATN;

std::vector<std::string> Pcl2Parser::_ruleNames = {
  "compilationUnit", "translationUnit", "externalDeclaration", "functionDefinition", 
  "functionDeclaration", "declaration", "typeSpecifier", "functionCall", 
  "functionReturn", "jumpStatement", "identifierList", "compoundStatement", 
  "blockItemList", "blockItem", "statement", "unaryStatement", "assignmentStatement", 
  "expressionStatement", "selectionStatement", "iterationStatement", "primaryExpression", 
  "expression", "conditionalExpression", "assignmentExpression", "parameterTypeList"
};

std::vector<std::string> Pcl2Parser::_literalNames = {
  "", "", "", "'??'", "'@'", "'**'", "'_'", "'namespace'", "'::'", "'string'", 
  "'break'", "'case'", "'char'", "'const'", "'continue'", "'bool'", "'default'", 
  "'double'", "'else'", "'extern'", "'float'", "'for'", "'if'", "'int'", 
  "'uint32_t'", "'int32_t'", "'long'", "'return'", "'short'", "'signed'", 
  "'sizeof'", "'static'", "'switch'", "'typedef'", "'unsigned'", "'void'", 
  "'while'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", 
  "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", 
  "'&'", "'|'", "'~'", "'^'", "'?'", "':'", "';'", "','", "'='", "'*='", 
  "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", 
  "'~='", "'->'", "'.'", "'...'"
};

std::vector<std::string> Pcl2Parser::_symbolicNames = {
  "", "ConditionalConnectOperator", "ConditionalOperator", "Coalescing", 
  "Bit", "Power", "IgnoreWildCard", "Namespace", "ScopeResolution", "String", 
  "Break", "Case", "Char", "Const", "Continue", "Bool", "Default", "Double", 
  "Else", "Extern", "Float", "For", "If", "Int", "Uint32", "Int32", "Long", 
  "Return", "Short", "Signed", "Sizeof", "Static", "Switch", "Typedef", 
  "Unsigned", "Void", "While", "LeftParen", "RightParen", "LeftBracket", 
  "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
  "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
  "MinusMinus", "Star", "Div", "Mod", "And", "Or", "Negate", "Caret", "Question", 
  "Colon", "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", 
  "PlusAssign", "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", 
  "XorAssign", "OrAssign", "NegateAssign", "Arrow", "Dot", "Ellipsis", "IntegerConstant", 
  "FloatConstant", "AndAnd", "OrOr", "Not", "Equal", "NotEqual", "Identifier", 
  "Whitespace", "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary Pcl2Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Pcl2Parser::_tokenNames;

Pcl2Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x5c, 0x10a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x3, 0x2, 0x5, 0x2, 
    0x36, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x3f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x42, 0xb, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x47, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x54, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x57, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x5d, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x60, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x68, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0x6b, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x6f, 0xa, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x76, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x7e, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x84, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0x8b, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x8e, 0xb, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0x92, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x9b, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x9e, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xa2, 0xa, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xad, 0xa, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0xb7, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x5, 0x13, 0xbd, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xd4, 0xa, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0xdf, 0xa, 0x17, 0xc, 0x17, 0xe, 
    0x17, 0xe2, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xf2, 0xa, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xf7, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0xfa, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x102, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0x106, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x2, 0x6, 0x4, 0x1a, 
    0x2c, 0x2e, 0x1b, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x2, 0x5, 0x8, 0x2, 0xe, 0xe, 0x11, 0x11, 0x13, 0x13, 
    0x16, 0x16, 0x19, 0x19, 0x25, 0x25, 0x3, 0x2, 0x37, 0x39, 0x4, 0x2, 
    0x33, 0x33, 0x35, 0x35, 0x2, 0x113, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x46, 0x3, 0x2, 0x2, 0x2, 0x8, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x70, 0x3, 0x2, 0x2, 0x2, 0x10, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x87, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x101, 0x3, 0x2, 0x2, 0x2, 0x32, 0x103, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x36, 0x5, 0x4, 0x3, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 
    0x2, 0x2, 0x3, 0x38, 0x3, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x8, 0x3, 
    0x1, 0x2, 0x3a, 0x3b, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x3d, 0xc, 0x3, 0x2, 0x2, 0x3d, 0x3f, 0x5, 0x6, 0x4, 0x2, 
    0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x47, 0x5, 
    0x8, 0x5, 0x2, 0x44, 0x47, 0x5, 0xc, 0x7, 0x2, 0x45, 0x47, 0x7, 0x40, 
    0x2, 0x2, 0x46, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x49, 0x5, 0xe, 0x8, 0x2, 0x49, 0x4a, 0x7, 0x58, 0x2, 0x2, 0x4a, 
    0x4b, 0x5, 0x32, 0x1a, 0x2, 0x4b, 0x4c, 0x5, 0x18, 0xd, 0x2, 0x4c, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x55, 0x7, 
    0x58, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x41, 0x2, 0x2, 0x50, 0x51, 0x5, 0xe, 
    0x8, 0x2, 0x51, 0x52, 0x7, 0x58, 0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x5, 0xe, 0x8, 0x2, 0x59, 0x5e, 0x7, 0x58, 0x2, 0x2, 0x5a, 0x5b, 0x7, 
    0x41, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0x58, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x40, 0x2, 0x2, 0x62, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x5, 0xe, 0x8, 0x2, 0x64, 0x69, 
    0x5, 0x30, 0x19, 0x2, 0x65, 0x66, 0x7, 0x41, 0x2, 0x2, 0x66, 0x68, 0x5, 
    0x30, 0x19, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6d, 0x7, 0x40, 0x2, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6f, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x9, 0x2, 0x2, 0x2, 0x71, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x58, 0x2, 0x2, 0x73, 0x75, 0x7, 0x27, 
    0x2, 0x2, 0x74, 0x76, 0x5, 0x16, 0xc, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x78, 0x7, 0x28, 0x2, 0x2, 0x78, 0x79, 0x7, 0x40, 0x2, 0x2, 0x79, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x58, 0x2, 0x2, 0x7b, 0x7d, 
    0x7, 0x27, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x16, 0xc, 0x2, 0x7d, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x80, 0x7, 0x28, 0x2, 0x2, 0x80, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x83, 0x7, 0x1d, 0x2, 0x2, 0x82, 0x84, 0x5, 0x2c, 0x17, 0x2, 
    0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x40, 0x2, 0x2, 0x86, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x8c, 0x7, 0x58, 0x2, 0x2, 0x88, 0x89, 0x7, 
    0x41, 0x2, 0x2, 0x89, 0x8b, 0x7, 0x58, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x7, 0x2b, 0x2, 0x2, 0x90, 
    0x92, 0x5, 0x1a, 0xe, 0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 
    0x2c, 0x2, 0x2, 0x94, 0x19, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x8, 0xe, 
    0x1, 0x2, 0x96, 0x97, 0x5, 0x1c, 0xf, 0x2, 0x97, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x99, 0xc, 0x3, 0x2, 0x2, 0x99, 0x9b, 0x5, 0x1c, 0xf, 0x2, 
    0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x5, 
    0x1e, 0x10, 0x2, 0xa0, 0xa2, 0x5, 0xc, 0x7, 0x2, 0xa1, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xad, 0x5, 0x18, 0xd, 0x2, 0xa4, 0xad, 0x5, 0x24, 0x13, 0x2, 
    0xa5, 0xad, 0x5, 0x26, 0x14, 0x2, 0xa6, 0xad, 0x5, 0x28, 0x15, 0x2, 
    0xa7, 0xad, 0x5, 0x22, 0x12, 0x2, 0xa8, 0xad, 0x5, 0x14, 0xb, 0x2, 0xa9, 
    0xaa, 0x5, 0x20, 0x11, 0x2, 0xaa, 0xab, 0x7, 0x40, 0x2, 0x2, 0xab, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xad, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x34, 0x2, 0x2, 0xaf, 0xb7, 0x7, 0x58, 0x2, 0x2, 0xb0, 
    0xb1, 0x7, 0x36, 0x2, 0x2, 0xb1, 0xb7, 0x7, 0x58, 0x2, 0x2, 0xb2, 0xb3, 
    0x7, 0x58, 0x2, 0x2, 0xb3, 0xb7, 0x7, 0x34, 0x2, 0x2, 0xb4, 0xb5, 0x7, 
    0x58, 0x2, 0x2, 0xb5, 0xb7, 0x7, 0x36, 0x2, 0x2, 0xb6, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb9, 0x5, 0x30, 0x19, 0x2, 0xb9, 0xba, 0x7, 0x40, 0x2, 0x2, 0xba, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x2c, 0x17, 0x2, 0xbc, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x40, 0x2, 0x2, 0xbf, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc1, 0x7, 0x18, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x27, 0x2, 
    0x2, 0xc2, 0xc3, 0x5, 0x2e, 0x18, 0x2, 0xc3, 0xc4, 0x7, 0x28, 0x2, 0x2, 
    0xc4, 0xc5, 0x5, 0x1e, 0x10, 0x2, 0xc5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc7, 0x7, 0x26, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x27, 0x2, 0x2, 0xc8, 0xc9, 
    0x5, 0x2e, 0x18, 0x2, 0xc9, 0xca, 0x7, 0x28, 0x2, 0x2, 0xca, 0xcb, 0x5, 
    0x1e, 0x10, 0x2, 0xcb, 0x29, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xd4, 0x7, 0x58, 
    0x2, 0x2, 0xcd, 0xd4, 0x7, 0x51, 0x2, 0x2, 0xce, 0xd4, 0x7, 0x52, 0x2, 
    0x2, 0xcf, 0xd0, 0x7, 0x27, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x2c, 0x17, 0x2, 
    0xd1, 0xd2, 0x7, 0x28, 0x2, 0x2, 0xd2, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x8, 0x17, 0x1, 0x2, 0xd6, 0xd7, 0x5, 0x2a, 
    0x16, 0x2, 0xd7, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0xc, 0x5, 0x2, 
    0x2, 0xd9, 0xda, 0x9, 0x3, 0x2, 0x2, 0xda, 0xdf, 0x5, 0x2c, 0x17, 0x6, 
    0xdb, 0xdc, 0xc, 0x4, 0x2, 0x2, 0xdc, 0xdd, 0x9, 0x4, 0x2, 0x2, 0xdd, 
    0xdf, 0x5, 0x2c, 0x17, 0x5, 0xde, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x8, 0x18, 0x1, 
    0x2, 0xe4, 0xe5, 0x5, 0x2c, 0x17, 0x2, 0xe5, 0xe6, 0x7, 0x4, 0x2, 0x2, 
    0xe6, 0xe7, 0x5, 0x2c, 0x17, 0x2, 0xe7, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x7, 0x27, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x2e, 0x18, 0x2, 0xea, 0xeb, 
    0x7, 0x28, 0x2, 0x2, 0xeb, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x55, 0x2, 0x2, 0xed, 0xee, 0x7, 0x27, 0x2, 0x2, 0xee, 0xef, 0x5, 0x2e, 
    0x18, 0x2, 0xef, 0xf0, 0x7, 0x28, 0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe8, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf3, 
    0xf4, 0xc, 0x5, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x3, 0x2, 0x2, 0xf5, 0xf7, 
    0x5, 0x2e, 0x18, 0x6, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xfb, 0xfc, 0x7, 0x58, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x42, 0x2, 0x2, 
    0xfd, 0x102, 0x5, 0x2c, 0x17, 0x2, 0xfe, 0xff, 0x7, 0x58, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0x42, 0x2, 0x2, 0x100, 0x102, 0x5, 0x12, 0xa, 0x2, 
    0x101, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x101, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x103, 0x105, 0x7, 0x27, 0x2, 0x2, 0x104, 
    0x106, 0x5, 0xa, 0x6, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x108, 0x7, 0x28, 0x2, 0x2, 0x108, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x35, 
    0x40, 0x46, 0x55, 0x5e, 0x69, 0x6e, 0x75, 0x7d, 0x83, 0x8c, 0x91, 0x9c, 
    0xa1, 0xac, 0xb6, 0xbc, 0xd3, 0xde, 0xe0, 0xf1, 0xf8, 0x101, 0x105, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Pcl2Parser::Initializer Pcl2Parser::_init;