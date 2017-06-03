# mt2-cwrapper

This package provides a C++ class object and its C wrapper, for binding in the other programming languages. The Haskell FFI can be found at [hs-mt2calculator](https://github.com/cbpark/hs-mt2calculator).

The C++ class is basically the same as that in the `Basic_Mt2_332` algorithm in [MT2 / Stransverse Mass / Oxbridge Kinetics Library](http://www.hep.phy.cam.ac.uk/~lester/mt2/), but with some modifications and simplifications. If you are going to use C++ for any study of the MT2 variable, it is recommended to use the original library.

## Build and install

Before attempting to build, you'll need to get [ROOT](http://root.cern.ch/) with [Minuit2](http://root.cern.ch/root/html/ROOT__Minuit2__Minuit2Minimizer.html) enabled.

```shell
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/some/where
make
make install
```

## Usage

See [`test_symm_mt2_minuit2.c`](src/test_symm_mt2_minuit2.c) and [`test_lester_mt2_bisect.c`](src/test_lester_mt2_bisect.c).
