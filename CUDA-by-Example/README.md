# CUDA-by-Example-source-code-for-the-book-s-examples-

![CUDA-by-Example](https://github.com/CodedK/CUDA-by-Example-source-code-for-the-book-s-examples-/blob/master/Pearson_CUDA_BookCover.jpg)


https://developer.nvidia.com/cuda-example

CUDA by Example, written by two senior members of the CUDA software platform team, shows programmers how to employ this new technology.  The authors introduce each area of CUDA development through working examples.  

## Table of Contents

- Why CUDA? Why Now?
- Getting Started
- Introduction to CUDA C
- Parallel Programming in CUDA C
- Thread Cooperation
- Constant Memory and Events
- Texture Memory
- Graphics Interoperability
- Atomics
- Streams
- CUDA C on Multiple GPUs
- The Final Countdown


## Authors

Jason Sanders is a senior software engineer in NVIDIA’s CUDA Platform Group, helped develop early releases of CUDA system software and contributed to the OpenCL 1.0 Specification, an industry standard for heterogeneous computing. He has held positions at ATI Technologies, Apple, and Novell.

Edward Kandrot is a senior software engineer on NVIDIA’s CUDA Algorithms team, has more than twenty years of industry experience optimizing code performance for firms including Adobe, Microsoft, Google, and Autodesk.

## Compile

```bash
make -j8
```

## Issues  

1) Cuda Unknown Error(ErrNo: 30) on cudaMalloc()   

"nvidia_uvm" kernel module is required for CUDA to work.

You need to install package with that kernel module, e.g. nvidia-331-uvm and enable it's autoloading by installing nvidia-modprobe package:  

```bash
sudo apt-get install nvidia-modprobe nvidia-331-uvm
sudo modprobe nvidia_uvm
```

If you don't want to reboot after installing nvidia-modprobe, you can try to run your program as root (e.g. sudo ./a.out) — module should be loaded during run as root.

CUDA 函数工作需要 "nvidia_uvm" 内核模块, 安装并加载 nvidia_uvm 之后就可以正常调用 cudaMalloc() 了.   