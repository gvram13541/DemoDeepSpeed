# #!/bin/bash

# # Set the base directory
# BASE_DIR=$(pwd)

# # Compile Plugin1
# g++ -shared -o $BASE_DIR/csrc/plugins/plugin1/libplugin1_device.so -fPIC $BASE_DIR/csrc/plugins/plugin1/plugin1.cpp

# # Compile Plugin2
# g++ -shared -o $BASE_DIR/csrc/plugins/plugin2/libplugin2_device.so -fPIC $BASE_DIR/csrc/plugins/plugin2/plugin2.cpp

# # Compile Plugin3
# g++ -shared -o $BASE_DIR/csrc/plugins/plugin3/libplugin3_device.so -fPIC $BASE_DIR/csrc/plugins/plugin3/plugin3.cpp

# # Compile Trampoline and Pybind11 bindings
# g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` \
#     -I$BASE_DIR/csrc/plugins/plugin1 \
#     -I$BASE_DIR/csrc/plugins/plugin2 \
#     -I$BASE_DIR/csrc/plugins/plugin3 \
#     $BASE_DIR/csrc/plugins/trampoline.cpp \
#     $BASE_DIR/csrc/plugins/py_ds_trampoline.cpp \
#     -o $BASE_DIR/csrc/plugins/py_ds_trampoline`python3-config --extension-suffix`



# #!/bin/bash

# # Set the base directory
# BASE_DIR=$(pwd)

# # Compile someother.cpp into an object file
# g++ -c -fPIC $BASE_DIR/csrc/plugins/plugin1/someother.cpp -o $BASE_DIR/csrc/plugins/plugin1/someother.o

# # Compile Plugin1
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin1_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin1/plugin1.cpp \
#     $BASE_DIR/csrc/plugins/plugin1/someother.o

# # Compile Plugin2
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin2_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin2/plugin2.cpp 

# # Compile Plugin3
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin3_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin3/plugin3.cpp 

# # Compile Trampoline and Pybind11 bindings
# g++ -O3 -Wall -shared -std=c++14 -fPIC $(python3 -m pybind11 --includes) \
#     -I$BASE_DIR/csrc/plugins/object \
#     $BASE_DIR/csrc/plugins/trampoline.cpp \
#     $BASE_DIR/csrc/plugins/py_ds_trampoline.cpp \
#     -o $BASE_DIR/csrc/plugins/py_ds_trampoline$(python3-config --extension-suffix)



# #!/bin/bash
# # Set the base directory
# BASE_DIR=$(pwd)

# # Create the output directory if it doesn't exist
# mkdir -p $BASE_DIR/csrc/plugins/object

# # Compile someother.cpp into an object file
# g++ -c -fPIC $BASE_DIR/csrc/plugins/plugin1/someother.cpp -o $BASE_DIR/csrc/plugins/object/someother.o

# # Compile Plugin1
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin1_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin1/plugin1.cpp \
#     $BASE_DIR/csrc/plugins/object/someother.o

# # Compile Plugin2
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin2_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin2/plugin2.cpp

# # Compile Plugin3
# g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin3_device.so -fPIC \
#     $BASE_DIR/csrc/plugins/plugin3/plugin3.cpp

# # Compile Trampoline and Pybind11 bindings
# g++ -O3 -Wall -shared -std=c++14 -fPIC $(python3 -m pybind11 --includes) \
#     -I$BASE_DIR/csrc/plugins/plugin1 \
#     -I$BASE_DIR/csrc/plugins/plugin2 \
#     -I$BASE_DIR/csrc/plugins/plugin3 \
#     -I$BASE_DIR/csrc/plugins/object \
#     $BASE_DIR/csrc/plugins/trampoline.cpp \
#     $BASE_DIR/csrc/plugins/py_ds_trampoline.cpp \
#     -o $BASE_DIR/csrc/plugins/object/py_ds_trampoline$(python3-config --extension-suffix)

#!/bin/bash
# Set the base directory
BASE_DIR=$(pwd)

# Create the output directory if it doesn't exist
mkdir -p $BASE_DIR/csrc/plugins/object

# Compile someother.cpp into an object file
g++ -c -fPIC $BASE_DIR/csrc/plugins/plugin1/someother.cpp -o $BASE_DIR/csrc/plugins/object/someother.o

# Compile Plugin1
g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin1_device.so -fPIC \
    $BASE_DIR/csrc/plugins/plugin1/plugin1.cpp \
    $BASE_DIR/csrc/plugins/object/someother.o

# Compile Plugin2
g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin2_device.so -fPIC \
    $BASE_DIR/csrc/plugins/plugin2/plugin2.cpp

# Compile Plugin3
g++ -shared -o $BASE_DIR/csrc/plugins/object/libplugin3_device.so -fPIC \
    $BASE_DIR/csrc/plugins/plugin3/plugin3.cpp

# Compile Trampoline and Pybind11 bindings
g++ -O3 -Wall -shared -std=c++14 -fPIC $(python3 -m pybind11 --includes) \
    -I$BASE_DIR/csrc/plugins/object \
    $BASE_DIR/csrc/plugins/trampoline.cpp \
    $BASE_DIR/csrc/plugins/py_ds_trampoline.cpp \
    $BASE_DIR/csrc/plugins/object/someother.o \
    -o $BASE_DIR/csrc/plugins/object/py_ds_trampoline$(python3-config --extension-suffix)