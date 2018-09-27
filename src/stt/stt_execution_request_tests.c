/*   For `void assertion(int expression)`. */
#include "../asr/assertion.h"

/*   For `stt_execution_request`. */
#include "stt_execution_request.h"

void
stt_execution_request_construct_and_destruct_test_0()
{
	stt_execution_request * execution_request_;
	execution_request_ = stt_execution_request_default_constructor();
	assertion(execution_request_ != NULL);
	assertion(execution_request_->type_ ==
			STT_EXECUTION_REQUEST_TYPE_INVALID);
	assertion(execution_request_->application_name_ == NULL);
	stt_execution_request_destructor(execution_request_);
}

void
stt_execution_request_construct_and_destruct_tests()
{
	stt_execution_request_construct_and_destruct_test_0();
}

void
stt_execution_request_tests()
{
	stt_execution_request_construct_and_destruct_tests();
}
