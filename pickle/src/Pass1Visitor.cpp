#include <iostream>
#include <string>
#include <vector>

#include "Pass1Visitor.hpp"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;



Pass1Visitor::~Pass1Visitor() = default;

Pass1Visitor::Pass1Visitor(const string fname, const bool debug) : PassVisitor(), program_name(fname), program_id(nullptr), j_file(nullptr), debug_flag(debug)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition) DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB, new EntryValue(symtab_stack->push()));
    symtab_stack->set_program_id(program_id);

    cout << "Pass1Visitor: symtab stack initialized" << endl;
}

ofstream & Pass1Visitor::get_assembly_file()
{ 
    return j_file; 
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   C O M P I L A T I O N                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context)
{
    print_debug_context(1, context, "visitCompilationUnit");

    // Open output stream file
    try
    {
        j_file.open(program_name + ".j");
        if (j_file.fail())
        {
            throw FileOpenError("Failed to open file");
        }
    }
    catch (FileOpenError const & error)
    {
        error.print_and_exit();
    }

    // Emit the program header
    j_file << ".class public " << program_name                      << endl;
    j_file << ".super java/lang/Object"                             << endl;

    // Emit the RunTimer and PascalTextIn fields
    j_file                                                          << endl;
    j_file << ".field private static _runTimer LRunTimer;"          << endl;
    j_file << ".field private static _standardIn LPascalTextIn;"    << endl;

    // Emit the class constructor.
    j_file                                                          << endl;
    j_file << ".method public <init>()V"                            << endl;
    j_file                                                          << endl;
    j_file << "\taload_0"                                           << endl;
    j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V"    << endl;
    j_file << "\treturn"                                            << endl;
    j_file                                                          << endl;
    j_file << ".limit locals 1"                                     << endl;
    j_file << ".limit stack 1"                                      << endl;
    j_file << ".end method"                                         << endl;
    j_file                                                          << endl;

    auto value = visitChildren(context);

    // Print the cross-reference table
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);
    
    return value;
}

antlrcpp::Any Pass1Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context)
{
    print_debug_context(1, context, "visitTranslationUnit");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *               T Y P E  S P E C I F I E R S                *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context)
{
    print_debug_context(1, context, "visitTypeSpecifier");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
{
    print_debug_context(1, context, "visitDeclaration"); 

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    try
    { 
        if (type_map.find(context->typeSpecifier()->getText()) != type_map.end())
        {
            cout << TAB << context->typeSpecifier()->getText() << endl;
            context->type = *(type_map.at(context->typeSpecifier()->getText()));
            context->type_letter = (char)toupper(context->typeSpecifier()->getText()[0]);
        }
        else
        {
            throw InvalidType("Type not supported : " + context->getText());
        }
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }

    string variable_name;
    string variable_initial_value;

    context->type_letter = toupper(context->typeSpecifier()->getText()[0]);
    
    if (context->assignmentExpression(0))
    {
        cout << TAB << "Has assignment\n";
        variable_name = context->assignmentExpression(0)->Identifier()->getText();

        // Save type letter inside assignmentExpression
        context->assignmentExpression(0)->type_letter = context->type_letter;
    
        if (context->assignmentExpression(0)->expression())
        {
            variable_initial_value = context->assignmentExpression(0)->expression()->getText();
        }
    }
    else
    {
        cout << TAB << "No assignment\n";
        variable_name = context->Identifier(0)->getText();
    }

    // Create a symbol table for a new declaration
    SymTabEntry * variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);
    variable_id->set_typespec(context->type);
    cout << TAB << "Symbol table created for : " << variable_name << endl;

    // Output the variable declaration leaving room for the initial value if there is one
    // @example : .field private static c D = 0
    j_file << ".field private static "
           << variable_name
           << " " 
           << context->type_letter;

    if (!variable_initial_value.empty())
    {
        j_file  << " = "
                << variable_initial_value;
    }

    j_file << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext *context)
{
    print_debug_context(1, context, "visitFunctionDeclaration");

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    for (int i = 0; i < context->typeSpecifier().size(); ++i) {

        try {
            if (type_map.find(context->typeSpecifier()[i]->getText()) != type_map.end()) {
                cout << TAB << context->typeSpecifier()[i]->getText() << endl;
                context->type = *(type_map.at(context->typeSpecifier()[i]->getText()));
                context->type_letter = (char) toupper(context->typeSpecifier()[i]->getText()[0]);
            } else {
                throw InvalidType("Type not supported : " + context->getText());
            }
        }
        catch (InvalidType const &error) {
            error.print_and_exit();
        }

        string variable_name;
        string variable_initial_value;

//        context->type_letter = (char)toupper(context->typeSpecifier()[i]->getText()[0]);

//        if (context->assignmentExpression(0)) {
//            cout << TAB << "Has assignment\n";
//            variable_name = context->assignmentExpression(0)->Identifier()->getText();
//
//            // Save type letter inside assignmentExpression
//            context->assignmentExpression(0)->type_letter = context->type_letter;
//
//            if (context->assignmentExpression(0)->expression()) {
//                variable_initial_value = context->assignmentExpression(0)->expression()->getText();
//            }
        variable_name = context->Identifier(i)->getText();

        // Create a symbol table for a new declaration
        SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
        variable_id->set_definition((Definition) DF_VARIABLE);
        variable_id->set_typespec(context->type);
        cout << TAB << "Symbol table created for : " << variable_name << endl;

        // Output the variable declaration leaving room for the initial value if there is one
        // @example : .field private static c D = 0
//        j_file << ".field private static "
//               << variable_name
//               << " "
//               << context->type_letter;
//
//        if (!variable_initial_value.empty()) {
//            j_file << " = "
//                   << variable_initial_value;
//        }
//
//        j_file << endl;
    }
    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context)
{
    print_debug_context(1, context, "visitFunctionDefinition");

    std::string function_name = context->Identifier()->toString();
    std::string function_return_type;
    function_return_type = (char)toupper(context->typeSpecifier()->getText()[0]);

    // Set the compound statement's scope name as the function name
    context->compoundStatement()->scope_name = context->Identifier()->getText();

    //create a header for pass2visitor to use when creating the method
    context->function_header = ".method public static " + context->Identifier()->toString() + "(";

    //add each function parameter to jasmin function header
    for(auto variable: context->parameterTypeList()->functionDeclaration()->typeSpecifier()) {
        string var_type = variable->getText();
        context->function_header += (char)toupper(var_type[0]);
    }

    //close parameter parenthesis and declare function return type
    context->function_header += ")" + function_return_type;

    //add comment of function signature for jasmin file
    context->function_header += "\n; " + context->getText() + "\n";

    //create a local symbal table for the function
    SymTab *local_symTab = symtab_stack->push();
    SymTabEntry *local_name_entry = local_symTab->enter(context->Identifier()->toString());
    local_name_entry->set_definition((Definition) DF_FUNCTION);
    cout << TAB << "Symbol table created for : " << context->Identifier()->toString() << endl;

    //allow parameterTypeList to add function parameters to symtab
    visit(context->parameterTypeList());
    std::cout << "***** size of local symtab" << symtab_stack->get_local_symtab()->sorted_entries().size() << std::endl;
    for(auto variable:symtab_stack->get_local_symtab()->sorted_entries()){std::cout << "***" << variable->get_name();}
    //use the created symtab as the symtab for compound statement {} scope
    //symtab will be pushed back on in compound statement
    context->compoundStatement()->local_symTab = symtab_stack->pop();

    return visit(context->compoundStatement());
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    print_debug_context(1, context, "visitPrimExpr");

    /**
     *  Determines the type + type letter of the identifier
     *  Stores it for Pass 2
     */

    context->expression_type = expr_primary;

    if (context->primaryExpression()->Identifier())
    {
        // Look up type of this expression in the symbol table stack
        try
        {
            const string variable = context->getText();

            const SymTabEntry * entry = symtab_stack->lookup(variable);

            if (!entry)
            {
                throw MissingSymbol(variable);
            }

            TypeSpec * type = entry->get_typespec();

            context->type_letter = letter_map_lookup(type);
            context->type = type;
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
    }
    else if (context->primaryExpression()->IntegerConstant())
    {
        context->type_letter = 'I';
        context->type = Predefined::integer_type;
    }
    else if (context->primaryExpression()->FloatConstant())
    {
        context->type_letter = 'F';
        context->type = Predefined::float_type;
    }

    visitChildren(context);

    return context->type;
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(1, context, "visitMulDivExpr");

    /**
     *  Determines the expression operator
     *  Determines the type of the resulting expression
     *  Stores it for pass 2
     */
    
    context->expression_type = expr_mul_div;

    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '*': /// No break
                case '/': /// No break
                case '%':
                    context->expr_operator = context->opr->getText()[0];
                    break;
                default:
                    throw InvalidOperator("MulDivExpr received impossible operator : " + context->opr->getText()[0]);
                    break;
            }
        }
        else
        {
            throw InvalidOperator("MulDivExpr missing operator");
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    TypeSpec * lhs_type = static_cast <TypeSpec *> (visit(context->expression(0)));
    TypeSpec * rhs_type = static_cast <TypeSpec *> (visit(context->expression(1)));

    cout << TAB
         << lhs_type 
         << " " 
         << rhs_type 
         << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(1, context, "visitAddminExpr");

    /**
     *  Determines the expression operator
     *  Determines the type of the resulting expression
     *  Stores it for pass 2
     */

    context->expression_type = expr_add_min;

    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '+': /// No break
                case '-':
                    context->expr_operator = context->opr->getText()[0];
                    break;
                default:
                    throw InvalidOperator("[visitAddminExpr] Received impossible operator : " + context->opr->getText()[0]);
                    break;
            }
        }
        else
        {
            throw InvalidOperator("[visitAddminExpr] Missing operator");
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    TypeSpec * lhs_type = static_cast <TypeSpec *> (visit(context->expression(0)));
    TypeSpec * rhs_type = static_cast <TypeSpec *> (visit(context->expression(1)));

    cout << TAB
         << lhs_type 
         << " " 
         << rhs_type 
         << endl;

    return nullptr;
}

antlrcpp::Any Pass1Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context)
{
    print_debug_context(1, context, "visitAssignmentExpression");

    /**
     *  Determines the type + type letter of the identifier
     *  Stores it for Pass 2
     */

    const string variable = context->Identifier()->getText();

    try
    {
        SymTabEntry * entry = symtab_stack->lookup(variable);

        if (!entry)
        {
            throw MissingSymbol("Missing symbol table : " + variable);
        }

        TypeSpec * type = entry->get_typespec();
    
        if (type)
        {
            context->type_letter = letter_map_lookup(type);
            context->type = type;
        }
        else
        {
            throw MissingSymbol("Symbol missing type : " + variable);
        }
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext * context)
{
    print_debug_context(1, context, "visitBasicConditionalExpr");

    /**
     *  Saves the operator characters
     *  Saves the opcode
     */

    const string opr = context->ConditionalOperator()->getText();

    string opcode;

    try
    {
             if (opr == "<")                     { opcode = "if_icmpge"; }  ///< (x <  y) branch if >=
        else if (opr == "<=")                    { opcode = "if_icmpgt"; }  ///< (x <= y) branch if >
        else if (opr == ">")                     { opcode = "if_icmple"; }  ///< (x >  y) branch if <=
        else if (opr == ">=")                    { opcode = "if_icmplt"; }  ///< (x >= y) branch if <
        else if (opr == "==" || opr == "is")     { opcode = "if_icmpne"; }  ///< (x == y) branch if !=
        else if (opr == "!=" || opr == "is not") { opcode = "if_icmpeq"; }  ///< (x != y) branch if ==
        else                                     { throw InvalidOperator(opr); }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    context->opr = opr;
    context->opcode = opcode;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext * context)
{
    print_debug_context(1, context, "visitConnectedConditionalExpr");

    /**
     *  Saves the operator characters
     */

    // Left and right operands should have pushed values to the stack
    if ("||" == context->ConditionalConnectOperator()->getText() ||
        "or" == context->ConditionalConnectOperator()->getText())
    {
        context->opr = "or";
    }
    else if ("&&"  == context->ConditionalConnectOperator()->getText() ||
             "and" == context->ConditionalConnectOperator()->getText())
    {
       context->opr = "and";
    }
    else
    {
        throw AntlrParsedIncorrectly("[visitConnectedConditionalExpr] Does not have proper operands");
    }

    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                     S T A T E M E N T S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitCompoundStatement(Pcl2Parser::CompoundStatementContext * context)
{
    print_debug_context(1, context, "visitCompoundStatement");

    if(context->local_symTab == nullptr) {
        context->local_symTab = symtab_stack->push();
        SymTabEntry *local_name_entry = context->local_symTab->enter(context->scope_name);
        local_name_entry->set_definition((Definition) DF_SCOPE);
    }else{
        symtab_stack->push(context->local_symTab);
        for(auto variable:context->local_symTab->sorted_entries()){std::cout << "***" << variable->get_name();}
    }
    cout << TAB << "Symbol table created for : " << context->scope_name << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext *context)
{
    print_debug_context(1, context, "visitIterationStatement");

    /**
     *  Sets the iteration name to while_N where N is the current scope number
     */

    context->conditionalExpression()->iteration_name = "while_" + std::to_string(scope_counter++);

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context)
{
    print_debug_context(1, context, "visitSelectionStatement");

    /**
     *  Sets the iteration name to if_N where N is the current scope number
     */

    context->conditionalExpression()->iteration_name = "if_" + std::to_string(scope_counter++);

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitJumpStatement(Pcl2Parser::JumpStatementContext *context){

    if(context->Return()){//jump is return statement
        visit(context->expression());

    }
    return visitChildren(context);
}