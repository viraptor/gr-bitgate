/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "edge_detect_bb_impl.h"

namespace gr {
  namespace bitgate {

    edge_detect_bb::sptr
    edge_detect_bb::make(bool down, char initial)
    {
      return gnuradio::get_initial_sptr
        (new edge_detect_bb_impl(down, initial));
    }

    /*
     * The private constructor
     */
    edge_detect_bb_impl::edge_detect_bb_impl(bool down, char initial)
      : gr::block("edge_detect_bb",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)))
      , down(down)
      , previous(initial)
    {}

    /*
     * Our virtual destructor.
     */
    edge_detect_bb_impl::~edge_detect_bb_impl()
    {
    }

    void
    edge_detect_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    edge_detect_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];

      for (int i=0; i<noutput_items; i++) {
        if (down) {
          out[i] = previous > in[i];
        } else {
          out[i] = previous < in[i];
        }
        previous = in[i];
      }
      
      consume_each (noutput_items);
      return noutput_items;
    }

  } /* namespace bitgate */
} /* namespace gr */

