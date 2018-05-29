#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitDeclaration(CmmParser::DeclarationContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::string type = context->typeSpecifier()->getText();
        cout << TAB << type << endl;
        context->type = backend::TypeSpecifier(type);
        context->type_letter = context->type.get_letter();

        std::string variable_name;
        std::string variable_initial_value = "0";

        if (context->assignmentExpression(0))
        {
            variable_name = context->assignmentExpression(0)->Identifier()->getText();
            cout << TAB << "Has assignment\n";
            cout << TAB << variable_name << endl;

            if (context->assignmentExpression(0)->expression() &&
                PassVisitor::is_digit(context->assignmentExpression(0)->expression()->getText()))
            {
                variable_initial_value = context->assignmentExpression(0)->expression()->getText();
                context->assignmentExpression(0)->expression()->type_letter = context->type_letter;
                context->assignmentExpression(0)->expression()->type = context->type;
            }
        }
        else
        {
            variable_name = context->Identifier(0)->getText();
        }

        cout << TAB << context->type << " " << context->type_letter << endl;

        symbol_table_stack.push_symbol_locally(variable_name, context->type);

        // Find function in map
        const std::string & current_function = symbol_table_stack.get_local_symbol_table()->get_table_name();

        if (PassVisitor::variable_id_map.find(current_function) == PassVisitor::variable_id_map.end())
        {
            THROW_EXCEPTION(MissingSymbol, "Function is not in variable_id_map : " + current_function);
        }
        else
        {
            PassVisitor::variable_id_map[current_function].emplace(
                variable_name,
                intermediate::Symbol(
                    symbol_table_stack.get_last_symbol_id_locally(),
                    context->type
                )
            );
        }

        cout << TAB << "Symbol created for : " << variable_name << endl;

        // Depending which scope this is in, emit declaration
        if (symbol_table_stack.get_current_nesting_level() == 1)
        {
            // Make a comment as to what the declaration is
            j_file << "; " << context->getText() << endl;

            // Output the variable declaration
            // @example : .field private static c D = 0
            j_file << ".field private static "
                   << variable_name
                   << " "
                   << context->type_letter
                   << endl;
        }

        return visitChildren(context);
    }

} /// backend
