#!/usr/bin/env python3

#
# Copyright 2018-2019 Mercedes Catherine Salazar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# utils/grammar/bison_extractor.py: Extracts the grammar from a Bison
# doc.
#


#   The input Bison doc is required to be written in Bellard's canonical
# format.


from datetime import datetime as datetime_datetime

from os import getcwd as os_getcwd


def wipe_out_eol(line):
    """ wipe out EOL. """

    assert line[-1:] == '\n'
    if line[-2:-1] == '\r':
        return line[:-2]
    else:
        return line[:-1]


def modify(line):
    """ modify a line. """

    return line.replace('T_', '', 1).replace(' T_', ' ')


def dump_license(write_handle):
    """   TODO This embedded license **must** come from a shared
        resource document."""

    now_ = datetime_datetime.now()
    year_ = now_.year
    year_as_string_ = str(year_)
    write_handle.write('/*\n')
    write_handle.write(' * Copyright 2018-' + year_as_string_ + ' Mercedes Catherine Salazar\n')
    write_handle.write(' *\n')
    write_handle.write(' * Licensed under the Apache License, Version 2.0 (the "License");\n')
    write_handle.write(' * you may not use this file except in compliance with the License.\n')
    write_handle.write(' * You may obtain a copy of the License at\n')
    write_handle.write(' *\n')
    write_handle.write(' *     http://www.apache.org/licenses/LICENSE-2.0\n')
    write_handle.write(' *\n')
    write_handle.write(' * Unless required by applicable law or agreed to in writing, software\n')
    write_handle.write(' * distributed under the License is distributed on an "AS IS" BASIS,\n')
    write_handle.write(' * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n')
    write_handle.write(' * See the License for the specific language governing permissions and\n')
    write_handle.write(' * limitations under the License.\n')
    write_handle.write(' *\n')
    write_handle.write(' * res/minia.grammar: Minia grammar as extracted from a Bison document.\n')
    write_handle.write(' */\n')
    write_handle.write('\n')


def do():
    """ worker function. """

    with open('../../src/bsn/minia.y') as d:
        #   Never do this in your projects. ;)
        lines = d.readlines()

    assert lines is not None

    #   Remove the _definitions_ and _user code_ sections, retaining
    # only the _rules_ section.
    filtered_lines = []
    adding = False
    already_added = False
    print('processing ' + str(len(lines)) + ' lines...')
    print('looking for the _rules section_...')
    for line in lines:
        if not adding:
            if line.startswith('%%') and len(line) < 5 and not already_added:
                print('found the _rules section_...')
                adding = True
        else:
            already_added = True
            if line.startswith('%%') and len(line) < 5:
                adding = False
            else:
                filtered_lines.append(wipe_out_eol(line))

    print('processing ' + str(len(filtered_lines)) + ' remaining lines...')

    selected_lines = []
    discarding_c_block = False
    for filtered_line in filtered_lines:
        if filtered_line == '':
            print('discarding an empty line...')
            continue
        if filtered_line[0].islower() and filtered_line[-1:] == ':':
            #   Grammar rule root non terminal node.
            selected_lines.append(filtered_line)
        elif (filtered_line[0:2] == '  ' and (filtered_line[2].isupper()
                or filtered_line[2].islower())):
            #   First production rule for one non terminal node.
            if not discarding_c_block:
                selected_lines.append(filtered_line)
        elif filtered_line[0] == ';':
            #   End of a grammar rule.
            selected_lines.append(filtered_line)
        elif (filtered_line[0:2] == '| ' and (filtered_line[2].isupper()
                or filtered_line[2].islower())):
            #   Alternative production rule for a same non terminal node.
            selected_lines.append(filtered_line)
        elif filtered_line[0] == '{':
            discarding_c_block = True
        elif filtered_line[0] == '}':
            discarding_c_block = False
        else:
            if not discarding_c_block:
                selected_lines.append(filtered_line)


    print('selected ' + str(len(selected_lines)) + ' lines...')

    for selected_line in selected_lines:
        print(selected_line)

    print('dumping to output doc...')
    with open('../../res/minia.grammar', 'w') as d:
        dump_license(d)
        for selected_line in selected_lines:
            d.write(modify(selected_line) + '\n')
    print('done')


def run():
    """ main function. """

    #   Fetch current working directory.
    cwd = os_getcwd()

    #   Remove potential trailing slashes.
    while cwd[-1:] == '/':
        cwd = cwd[:-1]

    #   Add exactly one trailing slash.
    cwd = cwd + '/'

    #   Assert a known hardwired location for the runtime of this
    # script... (it's just for myself for now, so it's OK).
    try:
        assert cwd.endswith('/amara/utils/grammar/')
    except AssertionError as ae:
        print(cwd)
        raise ae

    do()


if __name__ == '__main__':
    run()
