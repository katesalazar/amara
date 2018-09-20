<!--
    Copyright 2018 Mercedes Catherine Salazar

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    src/README.md: Amara sources README doc.
-->

# sources

## explanation of the directories names.

* `arn`: The **a**pplications **r**u**n**ner, currently separated from
the tests system.

* `asr`: The **as**se**r**tions utilities are isolated because they tend to be
not fully coverable by tests, as the failure to assert something makes a debug
program exit without generating `gcov` data.

* `bsn`: **B**i**s**o**n** and Flex are external systems, so while ultimately
the amara
scope is responsible for the quality of any code it uses, many features of the
generated Bison parser fall primarily in the Bison scope, so the amara scope
would not be fixing them... unless for some reason the amara scope decided to
apply custom patches on top of upstream Bison (supposing legal stuff allows for
that).

* `cmn`: **C**o**m**mo**n** boiler plates.

* `ftr`: The **f**u**t**u**r**e system deals with providing the C99 `int
snprintf(char * str, size_t size, const char * format, ...)` without actually
being under C99.

* `prs`: The **p**e**rs**istence system deals with persistent IO, in a way
fully coverable by tests, abstracting uncoverable conditions proxied by docs of
the `wrp/` directory.

* `rtg`: Scripts **r**un **t**ime **g**raphs.

* `stt`: Scripts **s**yn**t**ax **t**rees.

* `tst`: The **t**e**st**s system is currently separated from applications
running. But I have forgotten why.

* `wrp`: External systems **wr**a**p**pers are provided in order to provide
mock versions of all external systems. So by definition this directory is not
fully coverable by tests.

## coding style

* `strdup` is a non standard extension. Won't be using it for the moment.

* Use a K&R variant.

  * Function body left brace left alone in new line of its own.

  * _If_ and _while_ constructions always with braces, and the body opening
    left brace normally in the same line.

* Use some Linux standards:

  * Indent using 8 space tabulators for now.

  * Code ending lines about column 80.

    * In general do not forcefully break string literals when it could cause
      the code to lose `grep`pability.

* Use some Python standards:

  * Comment ending lines about column 72.

* Other stuff.

  * Markdown syntax is simple and ubiquitous. Allow it inside comments as long
    as it doesn't interfere with common external systems in use (or potentially), e.g. Doxygen.

* When in doubt about something, look into what do other big projects (e.g.
Linux or Apache) do.
