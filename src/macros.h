/*
 * Copyright 2020 Mercedes Catherine Salazar
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * src/macros.h: TODO
 */

/*   https://stackoverflow.com/a/809465/1737973 */
#define _impl_PASTE(a, b) a##b

/*   https://stackoverflow.com/a/809465/1737973 */
#define _impl_PREPROCESSOR_ASSERT_LINE(predicate, line, file) \
	typedef char _impl_PASTE( \
			assertion_failed_at_doc_##file##_at_line_, line \
	)[ 2 * !!(predicate) - 1]

/*   https://stackoverflow.com/a/809465/1737973 */
#define PREPROCESSOR_ASSERT(predicate, file) \
	_impl_PREPROCESSOR_ASSERT_LINE(predicate, __LINE__, file)
