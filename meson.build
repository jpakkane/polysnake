project('polysnake', 'c', 'cpp', 'rust', 'fortran',
  default_options : ['cpp_std=c++14'],
  license : 'GPL3+')

py3_mod = import('python3')
py3_dep = dependency('python3')

rustlib = static_library('func', 'func.rs')

executable('tmpbin', 'main.cpp', 'ffunc.f90',
  link_with : rustlib)
