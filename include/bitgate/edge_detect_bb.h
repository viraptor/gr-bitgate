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


#ifndef INCLUDED_BITGATE_EDGE_DETECT_BB_H
#define INCLUDED_BITGATE_EDGE_DETECT_BB_H

#include <bitgate/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace bitgate {

    /*!
     * \brief <+description of block+>
     * \ingroup bitgate
     *
     */
    class BITGATE_API edge_detect_bb : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<edge_detect_bb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of bitgate::edge_detect_bb.
       *
       * To avoid accidental use of raw pointers, bitgate::edge_detect_bb's
       * constructor is in a private implementation
       * class. bitgate::edge_detect_bb::make is the public interface for
       * creating new instances.
       */
      static sptr make(bool down, char initial);
    };

  } // namespace bitgate
} // namespace gr

#endif /* INCLUDED_BITGATE_EDGE_DETECT_BB_H */

