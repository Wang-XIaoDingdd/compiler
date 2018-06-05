#pragma once

#include "PassVisitor.hpp"



namespace backend
{

    class Pass2Visitor : public PassVisitor, public CmmBaseVisitor
    {

    public:

        /// Constructor
        Pass2Visitor(const std::string fname, std::ofstream & j_file, const bool debug=false);

        /// Destructor
        virtual ~Pass2Visitor();

        /// @ { Common
        antlrcpp::Any visitCompilationUnit(CmmParser::CompilationUnitContext *context) override;
        antlrcpp::Any visitTranslationUnit(CmmParser::TranslationUnitContext *context) override;
        antlrcpp::Any visitTypeSpecifier(CmmParser::TypeSpecifierContext *context) override;
        /// @ }

        /// @ { Declarations
        antlrcpp::Any visitDeclaration(CmmParser::DeclarationContext *context) override;
        /// @ }

        /// @ { Functions
        antlrcpp::Any visitFunctionParameterList(CmmParser::FunctionParameterListContext *context) override;
        antlrcpp::Any visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context) override;
        antlrcpp::Any visitFunctionCall(CmmParser::FunctionCallContext *context) override;
        antlrcpp::Any visitFunctionReturn(CmmParser::FunctionReturnContext *context) override;
        /// @ }

        /// @ { Statements
        antlrcpp::Any visitIfElseStatement(CmmParser::IfElseStatementContext *context) override;
        antlrcpp::Any visitIfStatement(CmmParser::IfStatementContext *context) override;
        antlrcpp::Any visitElseIfStatement(CmmParser::ElseIfStatementContext *context) override;
        antlrcpp::Any visitElseStatement(CmmParser::ElseStatementContext *context) override;
        antlrcpp::Any visitIterationStatement(CmmParser::IterationStatementContext *context) override;
        antlrcpp::Any visitAssignmentStatement(CmmParser::AssignmentStatementContext * context) override;
        antlrcpp::Any visitJumpStatement(CmmParser::JumpStatementContext *ctx) override;
        antlrcpp::Any visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context) override;
        antlrcpp::Any visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context) override;
        antlrcpp::Any visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context) override;
        /// @ }

        /// @ { Expressions
        antlrcpp::Any visitMulDivExpr(CmmParser::MulDivExprContext *context) override;
        antlrcpp::Any visitAddminExpr(CmmParser::AddminExprContext *context) override;
        antlrcpp::Any visitPrimExpr(CmmParser::PrimExprContext *context) override;
        antlrcpp::Any visitBitExpr(CmmParser::BitExprContext *context) override;
        antlrcpp::Any visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context) override;
        antlrcpp::Any visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context) override;
        antlrcpp::Any visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context) override;
        antlrcpp::Any visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context) override;
        antlrcpp::Any visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context) override;
        /// @ }

    private:

        std::string program_name;

        const bool debug_flag;

        /// Stores the current function name
        std::string current_function = "global";

        std::vector <std::string> instruction_buffer;

        std::string resolve_expression_instruction(const backend::TypeSpecifier & type, const std::string & opr);

        void emit_symbol_table();

        void visit_expression(CmmParser::ExpressionContext * context,
            const std::vector <CmmParser::ExpressionContext *> & expressions,
            const std::string & expr_operator);

        void visit_unary_statement(CmmParser::UnaryStatementContext * context,
            const std::string & identifier,
            const std::string & opr,
            const bool is_duplicate);

    };

} /// backend