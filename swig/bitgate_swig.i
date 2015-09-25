/* -*- c++ -*- */

#define BITGATE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "bitgate_swig_doc.i"

%{
#include "bitgate/triggered_bits.h"
%}

%include "bitgate/triggered_bits.h"
GR_SWIG_BLOCK_MAGIC2(bitgate, triggered_bits);
