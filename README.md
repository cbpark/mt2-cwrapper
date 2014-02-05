mt2_cwrapper
============

This package provides a C++ class object and its C wrapper, for binding in the other programming languages.

The C++ class is basically the same as that in the `Basic_Mt2_332` algorithm in [MT2 / Stransverse Mass / Oxbridge Kinetics Library](http://www.hep.phy.cam.ac.uk/~lester/mt2/), but with some modifications and simplifications. If you are going to use C++ for any study of the MT2 variable, the original library is recommended.

## Build and install

Generic installation inctructions are in the file INSTALL.

Before attempting to build, you'll need to get [ROOT](http://root.cern.ch/) with [Minuit2](http://root.cern.ch/root/html/ROOT__Minuit2__Minuit2Minimizer.html) enabled. Then, the installed directory of the ROOT should be specified in the configuration.

```shell
./configure --with-root=$ROOTSYS
make
make install
```
