/* $Id$ */
/*-
 * Copyright (c) 2003 Olivier Fourdan <fourdan@xfce.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <libxfce4util/utf8.h>

/* Around for compatibility. DEPRECATED! */
gchar *
utf8_string_remove_controls(gchar *str, gssize max_len, const gchar *end)
{
  return xfce_utf8_remove_controls (str, max_len, end);
}

/**
 * xfce_utf8_remove_controls:
 * @str: target string.
 * @max_len:
 * @end:
 *
 * Removes all control characters from @str.
 *
 * Return value: pointer to @str.
 *
 * Since: 4.1.3
 **/
gchar *
xfce_utf8_remove_controls (gchar *str, gssize max_len, const gchar *end)
{
    gchar *p;
    
    g_return_val_if_fail (str != NULL, NULL);
    
    p = (gchar *) str;
    while (p && *p && (!end || p < end) && (max_len < 0 || (p - str) < max_len))
    {
        if ((*p > 0) && (*p < 32))
            *p = ' ';
        p = g_utf8_find_next_char(p, end);
    }

    return (gchar *) str;
}

