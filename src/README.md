<!--
    Copyright 2018-2020 Mercedes Catherine Salazar

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

Misc documentation about the source code.


## explanation of the directories names.

* `arn`: The **a**pplications **r**u**n**ner, currently separated from
  the tests system. It also takes care of state vision on `rtg` data
  structures, e.g. variable named references are resolved to the corresponding
  values or to references to them, or any otherwise non constant name
  reference. Everything inside must be under 100% coverage.

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

* `cmn`: **C**o**m**mo**n** boiler plates. Everything inside must be under 100%
  coverage.

* `ftr`: The **f**u**t**u**r**e system deals with providing the C99 `int
snprintf(char * str, size_t size, const char * format, ...)` without actually
being under C99.

* `log`: <strong>Log</strong>ging facilities.

* `prs`: The **p**e**rs**istence system deals with persistent IO, in a way
fully coverable by tests, abstracting uncoverable conditions by proxying them
  to source documents in
the `wrp/` directory. You could call this the IO port, thinking in terms of
  ports&amp;adapters (A.K.A. hexagonal). Everything inside must be under 100%
  coverage.

* `rtg`: Scripts **r**un **t**ime **g**raphs. These data structures correspond
  to the same data structures of `stt`, just that every possible constant name
  reference is resolved to the corresponding pointer, or to the corresponding
  otherwise non-pointer identifying reference.
  Everything inside must be under 100% coverage.

* `stt`: Scripts **s**yn**t**ax **t**rees. These data structures are faithful
  representations of the tree structure of the documents written in minia DSL.
  Everything inside must be under 100% coverage.

* `tst`: The **t**e**st**s system is currently separated from applications
running. But I have forgotten why. Everything inside must be under 100%
  coverage.

* `wrp`: External systems **wr**a**p**pers are provided in order to provide
mock versions of all external systems. You could call this the IO adapter,
  thinking in terms of ports&amp;adapters (A.K.A. hexagonal). By definition
  this directory can not reach full tests coverage.


## design decisions

### `simple_list`

Super simple linked list, with a single pointer to the head. No pointer to the
tail, no reverse direction.

Empty:

```
+-------+------+
| first | next |
+-------+------+
| NULL  | NULL |
+-------+------+
```

Not empty, one single element:

```
+-------+------+
| first | next |
+-------+------+
| o     | NULL |
+-+-----+------+
  |
  |   +---------+
  +-->| element |
      +---------+
```

Not empty, two different elements:

```
+-------+------+   +-------+------+
| first | next |   | first | next |
+-------+------+   +-------+------+
| o     | o----+-->| o     | NULL |
+-+-----+------+   +-+-----+------+
  |                  |
  |   +-----------+  |   +-----------+
  +-->| element 0 |  +-->| element 1 |
      +-----------+      +-----------+
```

### `fixed_list`

Almost like `simple_list`, just the pointer to the head is guaranteed to be
constant from construction till destruction.


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
    as it doesn't interfere with common external systems in use (or
    potentially), e.g. Doxygen. You don't know whether at some point the editor
    or pager might render richly **bold**, _italic_, `code`...

* When in doubt about something, look into what do other big projects (e.g.
Linux or Apache) do.
