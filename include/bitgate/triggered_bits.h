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


#ifndef INCLUDED_BITGATE_TRIGGERED_BITS_H
#define INCLUDED_BITGATE_TRIGGERED_BITS_H

#include <bitgate/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace bitgate {

    /*!
     * \brief <+description of block+>
     * \ingroup bitgate
     *
     */
    class BITGATE_API triggered_bits : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<triggered_bits> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of bitgate::triggered_bits.
       *
       * To avoid accidental use of raw pointers, bitgate::triggered_bits's
       * constructor is in a private implementation
       * class. bitgate::triggered_bits::make is the public interface for
       * creating new instances.
       */
      static sptr make(int end_delay);
    };

  } // namespace bitgate
} // namespace gr

#endif /* INCLUDED_BITGATE_TRIGGERED_BITS_H */

