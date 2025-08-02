# MoneRig-miner
[![Monero](https://img.shields.io/badge/Monero-F60?logo=monero&logoColor=fff)](#) [![Releases](https://img.shields.io/badge/Releases-blue)](https://github.com/Kraiakn/MoneRig-miner/releases) ![version](https://img.shields.io/badge/version-1.3.3-blue)


MoneRig is a highly efficient GPU miner with support of NVIDIA and AMD GPUs, tailored specifically for the Monero blockchain and compatible coins using the RandomX algorithm. Although originally architected for GPU acceleration, the miner's output code is also compatible with CPU execution mode.

# Features
- **Universal: Compatible with both GPU and CPU runtime modes**
- **Fully Open Source**
- **Multi GPU/CPU support**
- **Automatic Configuration**
- **Farm Failover**
- **XRandom algorithm**

Also, the software is completely free to use and modify under the terms of the GNU GPL v3 license.
# Usage
Monerig operates via command-line interface. To begin using the program, you need to move to the monerig directory:
```shell
cd monerig
```

### Command line options list:
```
-o / --url	                       Mining pool address
-u / --user	                     username for mining server
-p / --pass	                     Password for mining server
--threads=N	                    CPU threads (e.g. --threads=4)
--cpu-affinity=0xF	         Assign CPU threads to specific cores
--cuda-devices=N	           Choose CUDA GPU devices to mine on
--cuda-launch=TxB	       Tune GPU kernel launch config (T = threads, B = blocks)
--opencl-devices=N	        Select OpenCL devices (for AMD GPUs)
--gpu-platform=N	             Choose the GPU platform
--print-time=N	          Hashrate display interval (in seconds)
--donate-level                    Manage donation level
--help                 This is not a full list. To see the full list type --help.
```

# Install
Executables for Windows, Linux, and macOS are available in the [Releases](https://github.com/Kraiakn/MoneRig-miner/releases) section. Simply download the appropriate binary for your operating system to get started.

# Donations
Default donation is 2%. It can be reduced(not less than 1%)/increased using --donate-level
- Monero address: 47dGkz8uF8XHYBsFeoDkFYm8tPZJ5TCJFevK8sJNFtYjKJWTVu7vLgLKqMguYZadPvZNyCMztTpsNvcTPdT8H6MfK6EqvHD

# Contact me
- me@monerig.com
- discord: monerigdev
- telegram: @monerigdev

