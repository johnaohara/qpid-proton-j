#ifndef PROTON_BITS_HPP
#define PROTON_BITS_HPP
/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <string>
#include <iosfwd>
#include <proton/error_condition.hpp>
#include <proton/error.h>

/**@file
 *
 * Assorted internal proton utilities.
 */

namespace proton {

class error_condition;

std::string error_str(long code);

/** Print the error string from pn_error_t, or from code if pn_error_t has no error. */
std::string error_str(pn_error_t*, long code=0);

/** Make a void* inspectable via operator <<. */
struct inspectable { void* value; inspectable(void* o) : value(o) {} };

/** Stream a proton object via pn_inspect. */
std::ostream& operator<<(std::ostream& o, const inspectable& object);

void set_error_condition(const error_condition&, pn_condition_t*);

/// Convert a const char* to std::string, convert NULL to the empty string.
inline std::string str(const char* s) { return s ? s : std::string(); }

}

#endif // PROTON_BITS_HPP
