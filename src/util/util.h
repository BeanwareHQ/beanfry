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

#include <stdbool.h>
#include <stddef.h>

#define BRACKETS           "]["
#define VALID_OPCHARS      ",.-+][><"
#define STACK_INITIAL_SIZE 255
#define ARRAY_GROW_FAC     5

#define Array_defType(T)                                                       \
    typedef struct {                                                           \
        T* elems;                                                              \
        size_t len;                                                            \
        size_t cap;                                                            \
    } Array_##T;                                                               \
    _Bool Array_##T##_init(Array_##T*);                                        \
    void Array_##T##_deinit(Array_##T*);                                       \
    _Bool Array_##T##_expand(Array_##T*);                                      \
    _Bool Array_##T##_shrink(Array_##T*);                                      \
    _Bool Array_##T##_reserve(Array_##T*, size_t);                             \
    _Bool Array_##T##_append(Array_##T*);                                      \
    _Bool Array_##T##_pop(Array_##T*);                                         \
    _Bool Array_##T##_remove(Array_##T*, size_t);                              \
    _Bool Array_##T##_at(Array_##T*, size_t)

Array_defType(int);

typedef enum {
    BRACKET_OPEN = '[',
    BRACKET_CLOSE = ']',
} Bracket;

typedef struct {
    Bracket* top;
    Bracket* btm;
    size_t cap;
} BracketStack;

bool BracketStack_init(BracketStack* stack);
bool BracketStack_push(BracketStack* stack, Bracket bracket);
bool BracketStack_pop(BracketStack* stack);
bool BracketStack_top(BracketStack* stack);
