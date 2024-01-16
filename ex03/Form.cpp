#include "Form.hpp"

Form::Form(AForm* _p) : p(_p) { }

Form::~Form() { delete (p); }

Form::operator AForm&() { return (*p); }
