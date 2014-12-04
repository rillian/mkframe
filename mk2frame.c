/* Copyright 2014 Mozilla Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
  uint8_t *data;
  int y_width, y_height, y_stride;
  int c_width, c_height, c_stride;
  uint8_t *y, *cr, *cb;
} y4m;

y4m *newframe(int width, int height) {
  y4m *frame = malloc(sizeof(*frame));
  if (!frame) {
    return NULL;
  }
  int stride = width;
  frame->data = malloc(stride * height * 3 / 2);
  if (!frame->data) {
    free(frame);
    return NULL;
  }
  frame->y = frame->data;
  frame->y_width = width;
  frame->y_height = height;
  frame->y_stride = stride;
  frame->cr = frame->data + stride * height;
  frame->cb = frame->data + stride * height * 5 / 4;
  frame->c_width = width / 2;
  frame->c_height = height / 2;
  frame->c_stride = stride / 2;

  return frame;
}

void freeframe(y4m *frame) {
  free(frame->data);
  free(frame);
}

void fillframe(y4m *frame, uint8_t y, uint8_t cr, uint8_t cb) {
  memset(frame->y, y, frame->y_stride * frame->y_height);
  memset(frame->cr, cr, frame->c_stride * frame->c_height);
  memset(frame->cb, cb, frame->c_stride * frame->c_height);
}

int main(int argc, char *argv[]) {
  return 0;
}
