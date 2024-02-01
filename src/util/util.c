/*
 * Beanfry: an overkill brainfuck implementation written in C99.
 *
 * Copyright (C) Eason Qin, 2024.
 *
 * NOTE: This source code form is licensed under the Mozilla Public License
 * version 2.0 and comes with absolutely NO WARRANTY. Refer to the LICENSE.md
 * file at the root of the project for more information.
 */

#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool BracketStack_init(BracketStack* stack) {
    Bracket* arena = malloc(STACK_INITIAL_SIZE * sizeof(Bracket));
    Bracket* top = arena + STACK_INITIAL_SIZE - 1;

    *stack =
        (BracketStack){.btm = arena, .top = top, .cap = STACK_INITIAL_SIZE};

    if (stack->btm == NULL) {
        perror("malloc: ");
        return true;
    }

    return false;
}
bool BracketStack_push(BracketStack* stack, Bracket bracket);
bool BracketStack_pop(BracketStack* stack);
bool BracketStack_top(BracketStack* stack);
