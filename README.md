# FakeSQL
A Database...

## How to use

```bash
# Install dependence
sudo apt-get install bison flex libboost-dev
```
> It is best to compile and install `libbson'

__Now compile it..__

```bash
# git clone
cd FakeSQL
mkdir build && cd build
# For Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
# For release
cmake .. 
make -j2
```


