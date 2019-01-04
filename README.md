<!--
    Copyright 2018-2019 Mercedes Catherine Salazar

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    README.md: README doc for Amara. Includes building instructions. Uses
    the GitHub friendly Markdown format.
-->

# amara

A bunch of WIP utilities aimed at applications custom fast prototyping.

## table of contents

* [dependencies][9]
* [how to run on...][10]
  * [debian stretch][11]
  * [macOS Mojave (the Xcode way)][33]
  * [macOS Mojave (the Homebrew way)][12]
  * [any other][13]
* [development tasks][14]
  * [active][15]
  * [stalled][16]
  * [to do][17]
* [roadmap][18]
  * [0.1.0][19]
  * [0.2.0][20]
  * [0.3.0][21]
  * [0.4.0][22]
* [development info][26]
* [compliance with 3rd parties' terms][27]
  * [current observance][28]
* [credits &amp; copying][30]

## dependencies

[Bison][31] and [Flex][32] are required dependencies.

Other third party libraries should be added soon as dependencies, e.g. libyaml,
Ncurses, or GMP, as long as there is no licensing clash.

## how to run on...

### debian stretch

1. Get yourself the best package manager ever:

```
$ su -
Password:
# apt-get install aptitude
[...]
# _
```

2. Select the `bison` and `flex` packages:

```
$ su -
Password:
# aptitude install bison flex
[...]
# _
```

3. Run `make`:

```
# exit
$ make
[...]
$ echo $?
0
$ _
```

4. Run `/PATH/TO/AMARA/build/release/amara`:

```
$ ./build/release/amara greet --no-banner
Wish you have a wonderful day!
$ _
```

### macOS Mojave (the Xcode way)

This was written for Xcode `9.0`.

1. Open `amara.xcodeproj/` from Xcode.

2. Edit the _Scheme_ -&gt; Run<sub>Debug</sub> -&gt; Arguments Passed On Launch -&gt; `+` -&gt; `greet --no-banner`.

3. Click the _play_ (build and run) button.

```
Wish you have a wonderful day!
Program ended with exit code: 0
```

### macOS Mojave (the Homebrew way)

1. **Optionally** [install Homebrew][8] (for updated `bison` and `flex`
   packages, not required):

```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

2. If you have Homebrew, **optionally** select the `bison` and `flex` packages
   (it should just work using the `default` bison and `flex` programs shipped
   in macOS):

```
$ brew install bison flex
[...]
$ _
```

3. Run `make`:

```
$ make
[...]
$ echo $?
0
$ _
```

4. Run `/PATH/TO/AMARA/build/release/amara`:

```
$ ./build/release/amara greet --no-banner
Wish you have a wonderful day!
$ _
```

### any other

Check out [`INSTALL_LEGACY.md`][5].

## development tasks

### active

* Unit tests framework.

* Valgrind and Gprof instrumentation.

* Initial scripting engine.

* YAML configuration docs management.

* CLI applications.

### stalled

(This list is empty).

### to do

* Valgrind and Gprof reporting.

* Unicode support.

* TUI and GUI applications.

* Grammar amendments.

  * Remove negative integers and negative rationals from the grammar (but not
    from the language engine), replacing them for positive integers and
    positive rationals after the occurrence of an unary operator minus.

    * Probably add an unary operator plus too.

* Modern Bison usage.

  * Parser reentrancy: see [this][34] and [this][35]. The recommended way by
    Bison 3.1 and 3.2 is to use `%define api.pure` (optionally
    `%define api.pure full`), but Bison 2.3 (present in macOS devices without
    Macports or Homebrew superpowers) doesn't know how to handle that. But
    both 2.3 and 3.1 can handle the previous recommendation `%pure-parser`.
    Also parser reentrancy of Bison 2.3 is now arcane technology, considering
    the 3.1 era online documentation.

    * Alternatively, access the parsing and tokens scanning facilities by means
      of a queue of jobs to be parsed by a single proxy thread. This should
      allow to stick in Yacc mode as a means to be Bison 2.3 compatible and
      Bison 3+ compatible, in case Bison choose to deprecate `%pure-parser`
      while choosing also to stay Yacc compatible. This is a scenario to
      specially consider, given the large amount of written books and other
      documentation materials about Yacc, in contrast to the relatively
      current obscurity about Bison 2.3 support.

  * Improved error reporting by the use of _the Bison locations tracking
  devices_.

  * Proper use of `yyerror(...)` and similar facilities?

## roadmap

This is completely tentative, and most probably goals will be moved around up
and down.

### 0.1.0

* CLI applications.

* Any contents in the [active development task][15] list.

### 0.2.0

* Unicode support.

### 0.3.0

* TUI applications.

### 0.4.0

* GUI applications.

## development info

<!--
[Stability policy][4].
-->
The stability policy is to hold 100% tests coverage. In case some conditions
can not be tested, 100% testable wrappers should be written for those
conditions, and those conditions shall be locked in specific namespaces.

## compliance with 3rd parties' terms

If you know of some terms this project might be in breach of, please open an
issue explaining. Thanks.

### current observance

These terms are in observance.

#### generated code

* While [GNU Bison][31]
itself is GPL
software, the parsers it generates are distributed under the terms of a custom
license such that if the parser is used without modification, then it
can be used in programs not distributed under the terms of the GPL. If GNU
changes such policy in the future, this project shall freeze its use of Bison,
and might explore different parsing strategies.

* While [Flex][32] itself is distributed under the terms of a custom variation
of the BSD-2-clause license; as its COPYING document states, the Flex scanner
skeleton is _freeware_.

## credits &amp; copying

Copyright (c)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Authored by:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2019 &lt;your name here&gt;:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&lt;your works here&gt;.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2018-2019 Mercedes Catherine Salazar (katesalazar):

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2019 - Documentation.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2018 - Lexicon, syntax, semantics, implementation, tests, documentation.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Contributions by:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2019 &lt;your name here&gt;:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&lt;your contributions here&gt;.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
2018 Mia (spreadLink):

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Syntax consulting.

Licensed to you under the terms of [the Apache License, version 2.0][29].


[2]: https://discord.gg/2XDzsuq

<!--
[4]: https://github.com/katesalazar/amara/blob/STABILITY-POLICY/STABILITY_POLICY.md
-->

[5]: http://github.com/katesalazar/amara/tree/master/INSTALL_LEGACY.md

[8]: https://brew.sh/

[9]: https://github.com/katesalazar/amara/tree/master#dependencies

[10]: https://github.com/katesalazar/amara/tree/master#how-to-run-on

[11]: https://github.com/katesalazar/amara/tree/master#debian-stretch

[12]: https://github.com/katesalazar/amara/tree/master#macos-high-sierra-the-homebrew-way

[13]: https://github.com/katesalazar/amara/tree/master#any-other

[14]: https://github.com/katesalazar/amara/tree/master#development-tasks

[15]: https://github.com/katesalazar/amara/tree/master#active

[16]: https://github.com/katesalazar/amara/tree/master#stalled

[17]: https://github.com/katesalazar/amara/tree/master#to-do

[18]: https://github.com/katesalazar/amara/tree/master#roadmap

[19]: https://github.com/katesalazar/amara/tree/master#010

[20]: https://github.com/katesalazar/amara/tree/master#020

[21]: https://github.com/katesalazar/amara/tree/master#030

[22]: https://github.com/katesalazar/amara/tree/master#040

[26]: https://github.com/katesalazar/amara/tree/master#development-info

[27]: https://github.com/katesalazar/amara/tree/master#compliance-with-3rd-parties-terms

[28]: https://github.com/katesalazar/amara/tree/master#current-observance

[29]: https://www.apache.org/licenses/LICENSE-2.0

[30]: https://github.com/katesalazar/amara/tree/master#credits--copying

[31]: https://www.gnu.org/software/bison/

[32]: https://github.com/westes/flex/

[33]: https://github.com/katesalazar/amara/tree/master#macos-high-sierra-the-xcode-way

[34]: https://www.gnu.org/software/bison/manual/html_node/Pure-Decl.html

[35]: https://www.gnu.org/software/bison/manual/html_node/Pure-Calling.html#Pure-Calling
