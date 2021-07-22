/* ----------------------------------------------------------------------------
  Copyright (c) 2021, Daan Leijen
  This is free software; you can redistribute it and/or modify it
  under the terms of the MIT License. A copy of the license can be
  found in the "LICENSE" file at the root of this distribution.
-----------------------------------------------------------------------------*/
#pragma once
#ifndef RP_COMPLETIONS_H
#define RP_COMPLETIONS_H

#include "common.h"
#include "stringbuf.h"


//-------------------------------------------------------------
// Completions
//-------------------------------------------------------------
#define RP_MAX_COMPLETIONS_TO_SHOW  (1000)

struct rp_env_s;
typedef struct completions_s completions_t;

rp_private completions_t* completions_new(alloc_t* mem);
rp_private void        completions_free(completions_t* cms);
rp_private void        completions_clear(completions_t* cms);
rp_private bool        completions_add(completions_t* cms , const char* display, const char* replacement, ssize_t delete_before, ssize_t delete_after);
rp_private ssize_t     completions_count(completions_t* cms);
rp_private ssize_t     completions_generate(struct rp_env_s* env, completions_t* cms , const char* input, ssize_t pos, ssize_t max);
rp_private void        completions_set_completer(completions_t* cms, rp_completer_fun_t* completer, void* arg);

rp_private const char* completions_get_display(completions_t* cms , ssize_t index);
rp_private ssize_t     completions_apply(completions_t* cms, ssize_t index, stringbuf_t* sbuf, ssize_t pos);


#endif // RP_COMPLETIONS_H