/*
 * Beanfry: an overkill brainfuck implementation written in C99.
 *
 * Copyright (C) Eason Qin, 2024.
 *
 * NOTE: This source code form is licensed under the Mozilla Public License
 * version 2.0 and comes with absolutely NO WARRANTY. Refer to the LICENSE.md
 * file at the root of the project for more information.
 */

#pragma once

#include <stdint.h>

#include "lexer/lexer.h"
#include "util/util.h"

typedef enum {
    OPKIND_ADD = '+',
    OPKIND_SUB = '-',
    OPKIND_NEXT = '>',
    OPKIND_PREV = '<',
    OPKIND_OUTPUT = '.',
    OPKIND_INPUT = ',',
    OPKIND_JUMP_ZERO = '[',
    OPKIND_JUMP_NONZERO = ']',
} OpKind;

typedef struct {
    OpKind kind;
    uint32_t count;
    uint32_t pos;
} Token;

Array_define(Token);

int32_t tokenize(const char* program, Array_Token* tokens);
