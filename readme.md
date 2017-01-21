# Python extension module with C, C++, Fortran and Rust

Exactly what it says on the tin.

All the specified languages are linked into a single Python extension module.

## Compiling

    meson build
    ninja -C build

## Running

    PYTHONPATH=build ./main.py
