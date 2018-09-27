/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_function`. */
#include "stt_function.h"

void
stt_function_construct_and_destruct_test_0()
{
	stt_function * function_;
	function_ = stt_function_default_constructor();
	assertion(function_ != NULL);
	assertion(function_->type_ == STT_FUNCTION_TYPE_INVALID);
	assertion(function_->name_ == NULL);
	assertion(function_->operations_ == NULL);
	stt_function_destructor(function_);
}

void
stt_function_construct_and_destruct_tests()
{
	stt_function_construct_and_destruct_test_0();
}

void
stt_function_tests()
{
	stt_function_construct_and_destruct_tests();
}
