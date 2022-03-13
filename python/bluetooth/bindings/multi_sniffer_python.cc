/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(multi_sniffer.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(e83b97ab8f6b4503a112a4944ab632b4)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <bluetooth/multi_sniffer.h>
// pydoc.h is automatically generated in the build directory
#include <multi_sniffer_pydoc.h>

void bind_multi_sniffer(py::module& m)
{

    using multi_sniffer    = ::gr::bluetooth::multi_sniffer;


    py::class_<multi_sniffer, gr::bluetooth::multi_block,
        std::shared_ptr<multi_sniffer>>(m, "multi_sniffer", D(multi_sniffer))

        .def(py::init(&multi_sniffer::make),
           py::arg("sample_rate"),
           py::arg("center_freq"),
           py::arg("squelch_threshold"),
           py::arg("tun"),
           D(multi_sniffer,make)
        )
        



        ;




}








