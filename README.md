# LCIOInput

An algorithm wrapper of k4LCIOReader that can cooperate with k4FWCore.

## Dependencies

- [EDM4hep](https://github.com/key4hep/EDM4hep)
- [k4LCIOReader](https://github.com/ihep-sft-group/k4LCIOReader)
- [k4FWCore](https://github.com/key4hep/k4FWCore)

## Build

Now this package can be built as a sub-module of k4FWCore.

1. check out k4FWCore

```shell
git clone https://github.com/key4hep/k4FWCore
```

2. check out LCIOInput and build it together with k4FWCore

```shell
cd k4FWCore
source init.sh
git clone https://github.com/ihep-sft-group/LCIOInput
mkdir build; cd build
cmake ..
make
```

## Contributing

Contributions and bug reports are welcome!
