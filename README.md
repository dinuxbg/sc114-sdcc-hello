# SDCC C Example For SC114 Z80 Motherboard Kit

## Introduction
This is a simple [SDCC](http://sdcc.sourceforge.net/) example for SC114 and possibly others RC2014-like computers running the [Small Computer Monitor ROM](https://smallcomputercentral.wordpress.com/small-computer-monitor/).

The example is loaded into RAM so no ROM burning is required. SCMON is used to load our program.

Helpful C wrappers are provided for some of the SCMON API entry points (e.g. printing to console).

## Purpose
Z88DK is not packaged in Debian, and I could not find any other working examples for plain SDCC on RC2014-like single board computers.

## Building And Running
I have validated with SDCC version 3.8.0 using the following hardware configuration:

 * [SC114 Z80 Motherboard Kit for RC2014](https://smallcomputercentral.wordpress.com/sc114-documentation/)
 * [SC129 Digital I/O Module Kit for RC2014](https://smallcomputercentral.wordpress.com/sc129-digital-i-o-rc2014/)
 * [SC104 Z80 SIO/2 Module Kit for RC2014](https://smallcomputercentral.wordpress.com/sc114-documentation/)


To build:

	make

To run, simply send hex and SCMON will recognize and load it. Then issue "g 8000" to jump to the loaded address. Provided your FTDI cable is enumerated at /dev/ttyUSB0, there is a helpful target:

	make run
