# Example Project Install Directions

### Install `linalgcpp`
Follow the build instructions to install 
[linalgcpp](https://github.com/gelever/linalgcpp).
Run the tests for linalgcpp to make sure it has sucessfully built.

### Run CMake Setup
From the root directory of the project, run your setup script:

``` bash
sh config/my_setup.sh
```

It *should* configure everthing correctly without adjustments.

### Test build
Change directories into the build directory:

``` bash
cd build
```

Make the project by calling make:
```
make
```

Run the example file to make sure everything works

```
./examples/example_file
```

### Start Development!
Place source files in `src` and header files in `include`.
Any files that actually need to be run can be placed in examples.
Modify CMakeLists.txt to append any source/example files you may create.
Replace `MY_PROJECT` everywhere with your desired project name.
