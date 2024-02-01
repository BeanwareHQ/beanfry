/*
 * Beanfry: an overkill brainfuck implementation written in C99.
 *
 * Copyright (C) Eason Qin, 2024.
 *
 * NOTE: This source code form is licensed under the Mozilla Public License
 * version 2.0 and comes with absolutely NO WARRANTY. Refer to the LICENSE.md
 * file at the root of the project for more information.
 */

#include <stdint.h>
#include <stdio.h>  // macro
#include <stdlib.h> // macro

#include "lexer/lexer.h"
#include "src/util/util.h"

int32_t tokenize(const char* program, Array_Token* tokens) {
    Array_init(Token, tokens);

    char ch;
    uint32_t count = 0;
    size_t pos = 0;

    while ((ch = program[pos++]) != '\0') {
    }

    return 0;
}
