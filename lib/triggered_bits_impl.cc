/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
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

#include <gnuradio/blocks/pdu.h>
#include <gnuradio/io_signature.h>
#include "triggered_bits_impl.h"

namespace gr {
  namespace bitgate {

    triggered_bits::sptr
    triggered_bits::make(int end_delay)
    {
      return gnuradio::get_initial_sptr
        (new triggered_bits_impl(end_delay));
    }

    /*
     * The private constructor
     */
    triggered_bits_impl::triggered_bits_impl(int end_delay)
      : gr::block("triggered_bits",
              gr::io_signature::make(2, 2, sizeof(char)),
              gr::io_signature::make(0, 0, 0))
      , got_bits(0)
      , current_byte(0)
      , since_last_trigger(end_delay)
      , end_delay(end_delay)
      , current_packet()
    {
        message_port_register_out(PDU_PORT_ID);
    }

    /*
     * Our virtual destructor.
     */
    triggered_bits_impl::~triggered_bits_impl()
    {
    }

    void
    triggered_bits_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
        ninput_items_required[0] = ninput_items_required[1] = noutput_items * end_delay;
    }

    int
    triggered_bits_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const char *data = (const char *) input_items[0];
        const char *trigger = (const char *) input_items[1];

        int pos = 0;

        int max_items = ninput_items[0] > ninput_items[1] ? ninput_items[1] : ninput_items[0];

        while(pos < max_items) {
            if(trigger[pos]) {
                since_last_trigger = 0;
                got_bits++;
                current_byte <<= 1;
                current_byte |= !data[pos];
                if (got_bits == 8) {
                    current_packet.push_back(current_byte);
                    got_bits = 0;
                    current_byte = 0;
                }
            } else {
                if (since_last_trigger < end_delay) {
                    since_last_trigger++;
                } else {
                    if (!current_packet.empty()) {
                        pmt::pmt_t data = gr::blocks::pdu::make_pdu_vector(gr::blocks::pdu::byte_t, current_packet.data(), current_packet.size());
                        pmt::pmt_t msg = pmt::cons(pmt::PMT_NIL, data);
                        message_port_pub(PDU_PORT_ID, msg);
                        current_packet.clear();
                        since_last_trigger = 0;
                    }
                    got_bits = 0;
                    current_byte = 0;
                }
            }
            pos++;
        }
        consume_each(pos);

        return 0;
    }

  } /* namespace bitgate */
} /* namespace gr */

