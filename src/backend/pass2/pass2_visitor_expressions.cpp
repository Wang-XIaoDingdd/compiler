#include "Pass2Visitor.hpp"



namespace backend
{

    void Pass2Visitor::visit_expression(CmmParser::ExpressionContext * context,
        const std::vector <CmmParser::ExpressionContext *> & expressions,
        const std::string & expr_operator)
    {
        for (uint8_t i = 0; i < 2; i++)
        {
            visit(expressions[i]);

            // Type mismatches need to be converted
            const std::string type_convert_instruction = convert_type_if_neccessary(expressions[i]->type, context->type);
            if (type_convert_instruction.size() > 0)
            {
                j_file << TAB << type_convert_instruction << endl;
            }
        }

        const std::string opcode = resolve_expression_instruction(context->type, expr_operator);
        j_file << "\t" << opcode << endl;
    }

    antlrcpp::Any Pass2Visitor::visitMulDivExpr(CmmParser::MulDivExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitAddminExpr(CmmParser::AddminExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitBitExpr(CmmParser::BitExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitPrimExpr(CmmParser::PrimExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  If variable : emit getstatic
         *  If integer  : emit ldc
         *  If float    : emit ldc
         */

        std::string instruction = "\t";

        if (context->primaryExpression()->Identifier())
        {
            instruction += create_get_variable_instruction(program_name, context->primaryExpression()->Identifier()->getText(), context->type_letter);
        }
        else if (context->primaryExpression()->IntegerConstant() ||
                (context->primaryExpression()->FloatConstant()))
        {
            cout << TAB << context->type << endl;
            // Doubles need to be treated differently
            if (backend::Type::t_double == context->type.get_type())
            {
                std::string double_value;

                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    double_value += context->primaryExpression()->IntegerConstant()->getText();
                    double_value += ".0";
                }
                else
                {
                    double_value += context->primaryExpression()->FloatConstant()->getText();
                }

                instruction += "ldc2_w " + double_value;
            }
            else if (backend::Type::t_float == context->type.get_type())
            {
                std::string float_value;

                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    float_value += context->primaryExpression()->IntegerConstant()->getText();
                    float_value += ".0";
                }
                else
                {
                    float_value += context->primaryExpression()->FloatConstant()->getText();
                }

                instruction += "ldc " + float_value;
            }
            else
            {
                instruction += "ldc " + context->primaryExpression()->IntegerConstant()->getText();
            }
        }

        if (instruction.length() > 2)
        {
            if (context->primaryExpression()->current_nesting_level == 1)
            {
                instruction_buffer.push_back(instruction);
            }
            else
            {
                j_file << instruction << endl;
            }
        }

        visitChildren(context);

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Children emit instructions first
         *  Emits branch instruction for exiting the current branch
         */

        const std::string lhs_name = context->expression(0)->getText();
        const std::string rhs_name = context->expression(1)->getText();

        // Emit an explanation comment for condition
        j_file << TAB
               << "; "
               << lhs_name
               << " "
               << context->opr
               << " "
               << rhs_name
               << endl;

        // Visit both operands
        for (uint8_t i = 0; i < 2; i++)
        {
            visit(context->expression(i));
            // Doubles and floats need to be converted before jump comparison instruction
            if (backend::Type::t_double == context->expression(i)->type.get_type())
            {
                j_file << TAB
                       << "d2i"
                       << endl;
            }
            else if (backend::Type::t_float  == context->expression(i)->type.get_type())
            {
                j_file << TAB
                       << "f2i"
                       << endl;
            }
        }

        // Emit an explanation comment for exit
        j_file << TAB
               << "; Exit ["
               << context->iteration_name
               << "] condition"
               << endl;

        // Emit the instruction
        j_file << TAB
               << context->opcode
               << " "
               << context->iteration_name + "_end"
               << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Top level conditional expression
         *  Responsible for only checking the top 2 values on the stack
         *  For an OR operation, if any of them are nonzero positive, jump
         *  For an AND operation, if both of them are nonzero positive, jump
         *  @note : Nothing needs to be done because for AND conditions both must be met,
         *          and both are checked previously in child nodes
         */

        // Visit children first
        visitChildren(context);

        // Left and right operands should have pushed values to the stack
        if ("or" == context->opr)
        {
            // If left condition is > 0, jump
            j_file << TAB
                   << "ifgt "
                   << context->iteration_name
                   << endl;
            // If right condition is > 0, jump
            j_file << TAB
                   << "ifgt "
                   << context->iteration_name
                   << endl;
        }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentExpression(CmmParser::AssignmentExpressionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  RHS expression will take care of emitting its own instructions
         *  This node will just load the value into the assigned variable
         */

        // Add a comment
        const std::string comment = "\t; " + context->getText();
        if (context->current_nesting_level == 1)
        {
            instruction_buffer.push_back(comment);
        }
        else
        {
            j_file << comment << endl;
        }

        if (context->expression())
        {
            // Visit right hand side expression first
            visit(context->expression());

            const backend::TypeSpecifier expression_type = context->expression()->type;
            const std::string type_convert_instruction = convert_type_if_neccessary(expression_type, context->type);
            if (type_convert_instruction.size() > 0)
            {
                j_file << TAB << type_convert_instruction << endl;
            }
        }
        else if (context->functionReturn())
        {
            visit(context->functionReturn());
        }

        const std::string instruction = create_put_variable_instruction(program_name, context->Identifier()->toString(), context->type_letter);

        if (context->current_nesting_level == 1)
        {
            instruction_buffer.push_back(instruction);
        }
        else
        {
            j_file << instruction << endl;
        }

        return nullptr;
    }

} /// backend
