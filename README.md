# gr-bluetooth
Welcome to gr-bluetooth!

gr-bluetooth is an implementation of the Bluetooth baseband layer for GNU Radio for experimentation and teaching students about Software Defined Radio, it should not be used for Bluetooth communications as it is not a complete software stack.

The software consists of signal processing blocks written in C++ (in src/lib) and front-end command line tools written in Python (in src/python).

In order to get to know gr-bluetooth and to be able to run the examples below, see the files in the `samples` directory.

## Getting Help
For assistance with gr-bluetooth general use or development, please look at the [issues on the GitHub project](https://github.com/greatscottgadgets/gr-bluetooth/issues). This is the preferred place to ask questions or open issues so that others may locate the answer to your question in the future.

We invite you to join our community discussions on [Discord](https://discord.gg/rsfMw3rsU8). Note that while technical support requests are welcome here, we do not have support staff on duty at all times. Be sure to also submit an issue on GitHub if you’ve found a bug or if you want to ensure that your request will be tracked and not overlooked.

GitHub issues on this repository that are labelled "technical support" by Great Scott Gadgets employees can expect a response time of two weeks. We currently do not have expected response times for other GitHub issues or pull requests for this repository.

## Building
gr-bluetooth currently requires gnuradio 3.10.0 or later.

To build gr-bluetooth:
```
  mkdir build
  cd build
  cmake ..
  make
  sudo make install
```

## Examples:

1. Getting help:

`$ btrx -h`

2. Finding packets and displaying LAPs:

`$ btrx -f 2476M -i samples/headset3.cfile`

See samples/manifest.txt for similar examples using different sample rates and
selection of multiple channels.

3. UAP discovery by CRC:

`$ btrx -d 8 -f 2476.5M -i samples/keyboard1.cfile -l 4831dd`

4. UAP/CLK1-6 discovery by time intervals:

`$ btrx -d 8 -i samples/headset1.cfile -f 2476.5M -l 24d952`

5. Clock (CLK1-27) discovery followed by hopping:

`$ btrx -d 8 -i samples/headset1.cfile -f 2476.5M -l 24d952 -p`
`$ btrx -d 16 -i samples/headset2.cfile -f 2476M -l 24d952 -p`

6. Decoding all piconets on all available channels:

`$ btrx -d 16 -f 2476M -i samples/headset2.cfile -S`

## Aliasing
Some of the tools in gr-bluetooth support an "aliased" mode intended to be used only with a particular receiver implementation that produces intentional aliases.  This implementation requires a modified RFX2400 daughterboard and a USRP2 with modified FPGA.  The hardware is available from Ettus Research (http://www.ettus.com/).

For more information on the theory behind this approach, see our presentation, Building an All-Channel Bluetooth Monitor, at ShmooCon 2009.

RFX2400 modification:

These steps bypass the 20 MHz I & Q baseband filters by directly connecting IMXO to IAIN and QMXO to QAIN on the AD8347 (see the AD8347 datasheet for more details).

1. Remove R5, R6, R7, R8, R61, R87, C85, C87, C89, and C91.
2. Pull AD8347 pins 18 (VDT2) and 20 (VDT1) off the board.
3. Connect the R7 pad that is connected to AD8347 pin 6 (IAIN) to the the R61
   pad that is connected to AD8347 pin 8 (IMXO)
4. Connect the R8 pad that is connected to AD8347 pin 24 (QAIN) to the the R87
   pad that is connected to AD8347 pin 22 (QMXO)

USRP2 FPGA modification:

A modified version of u2_rev3.bin is located in ../bin/u2_rev3_alias.bin and can be installed on your USRP2's SD card in the usual way described here:

http://gnuradio.org/trac/wiki/USRP2UserFAQ

See the [patches](#patches) section if you would like to compile from source (requires non-free development tools).

## Bit Order
We refer to the order of bits in the Bluetooth air interface as "air order."  Data in this bit order are typically in the form of an
array of some integer type (normally char) with each integer representing one bit.  This is the form of the stream of input provided by GNU Radio.  Air order is LSB first.  Examples: input_items, d_stream
 
We call the order of bits in a typical integer (big-endian or little-endian depending on the host) "host order."  Data in this bit order are typically in the form of an integer type with several bits per integer.  Examples: UAP, LAP
  
If we need an array of one bit per integer that is MSB first, we append "_host" to the variable name for clarity.  Similarly, if we need an integer representing more than one bit with the bits reversed (with respect to host order), we append "_air" to the variable name.  When possible we try to avoid these situations.  

## Patches
`patches/usrp2_alias.patch`:

	This is a USRP2 FPGA patch to enable intentional aliasing.  It is a quick
	hack that probably only works as intended with a decimation rate of 4.  The
	patch is against svn revision 10194, a beta USRP2 release.  For FPGA
	development environment information see:
	http://gnuradio.org/trac/wiki/USRP2GenFAQ

`patches/wireshark-1.x.y-btbb.patch`:

	These patchs add the Bluetooth baseband dissector plugin to the appropriate
	Wireshark source tree.  In addition to the patch, you need to copy (or
	check out in place) gr-bluetooth/wireshark/plugins/btbb under the
	wireshark-1.x.y/plugins directory.  The patch doesn't work with
	Wireshark svn, but it isn't hard to manually edit an svn tree as
	required with this patch as your guide.
