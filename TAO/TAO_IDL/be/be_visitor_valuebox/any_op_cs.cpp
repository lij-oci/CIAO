// $id: any_op_cs.cpp Exp $

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    any_op_cs.cpp
//
// = DESCRIPTION
//    Visitor generating code for Any operators for valueboxes in the stubs
//    file.
//
// = AUTHOR
//    Gary Maxey
//
// ============================================================================

ACE_RCSID (be_visitor_valuebox,
           any_op_cs,
           "$Id$")


// ***************************************************************************
// Valuebox visitor for generating Any operator declarations in the client
// stubs file
// ***************************************************************************

be_visitor_valuebox_any_op_cs::be_visitor_valuebox_any_op_cs (
    be_visitor_context *ctx
  )
  : be_visitor_valuebox (ctx)
{
}

be_visitor_valuebox_any_op_cs::~be_visitor_valuebox_any_op_cs (void)
{
}

int
be_visitor_valuebox_any_op_cs::visit_valuebox (be_valuebox *node)
{
  if (node->cli_stub_any_op_gen ()
      || node->imported ()
      || node->is_local ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  // Generate the Any <<= and >>= operator declarations

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  // All template specializations must be generated before the instantiations
  // in the operators.
  *os << be_nl << be_nl
      << "namespace TAO" << be_nl
      << "{" << be_idt_nl
      << "template<>" << be_nl
      << "CORBA::Boolean" << be_nl
      << "Any_Impl_T<" << node->name () << ">::to_value ("
      << be_idt <<  be_idt_nl
      << "CORBA::ValueBase *&_tao_elem" << be_uidt_nl
      << ") const" << be_uidt_nl
      << "{" << be_idt_nl
      << "CORBA::add_ref (this->value_);" << be_nl
      << "_tao_elem = this->value_;" << be_nl
      << "return 1;" << be_uidt_nl
      << "}" << be_uidt_nl
      << "}" << be_nl << be_nl;


  be_module *module = 0;
 
  if (node->is_nested () &&
      node->defined_in ()->scope_node_type () == AST_Decl::NT_module)
    {
      module = be_module::narrow_from_scope (node->defined_in ());

      if (!module)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "be_visitor_valuebox_any_op_cs::"
                             "visit_valuebox - "
                             "Error parsing nested name\n"),
                            -1);
        }

      be_util::gen_nested_namespace_begin (os, module);
    }

  *os << "// Copying insertion." << be_nl
      << "void" << be_nl
      << "operator<<= (" << be_idt << be_idt_nl
      << "CORBA::Any &_tao_any," << be_nl
      << node->local_name () << " *_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "CORBA::add_ref (_tao_elem);" << be_nl
      << "_tao_any <<= &_tao_elem;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "// Non-copying insertion." << be_nl
      << "void" << be_nl
      << "operator<<= (" << be_idt << be_idt_nl
      << "CORBA::Any &_tao_any," << be_nl
      << node->local_name () << " **_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "TAO::Any_Impl_T<" << node->local_name () << ">::insert ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->local_name () << "::_tao_any_destructor," << be_nl
      << node->tc_name ()->last_component () << "," << be_nl
      << "*_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "CORBA::Boolean" << be_nl
      << "operator>>= (" << be_idt << be_idt_nl
      << "const CORBA::Any &_tao_any," << be_nl
      << node->local_name () << " *&_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return" << be_idt_nl
      << "TAO::Any_Impl_T<" << node->local_name () << ">::extract ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->local_name () << "::_tao_any_destructor," << be_nl
      << node->tc_name ()->last_component () << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  if (module != 0)
    {
      be_util::gen_nested_namespace_end (os, module);
    }

  node->cli_stub_any_op_gen (1);
  return 0;
}
