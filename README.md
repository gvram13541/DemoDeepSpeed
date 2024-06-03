# Project Build and Execution Instructions

## Changes need to made:
Before running the `compile.sh` script, ensure that the correct paths are set within the script to match your project structure.

## Step 1: Compile the C++ Implementations

The compile.sh file compiles all the cpp implementations of plugins and trampoline class and stroes them in common folder called object.

### Command:

```sh
./compile.sh
```

## Step 2: Export Shared Object Files to LD_LIBRARY_PATH

Export the created shared object files so that they can be dynamically linked. This step ensures that the shared object files are available in the library search path during runtime.

### Command:

```sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/csrc/plugins/object
```

## Step 3: Export the Trampoline Shared Object to PYTHONPATH

Export the created trampoline shared object to the Python path. This step ensures that the Python interpreter can locate the trampoline shared object files during execution.

### Command:

```sh
export PYTHONPATH=$PYTHONPATH:$PWD/csrc/plugins/object
```
