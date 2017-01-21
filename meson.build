project('polysnake', 'c', 'cpp', 'rust',
  default_options : ['cpp_std=c++14'],
  license : 'GPL3+')

py3_mod = import('python3')
py3_dep = dependency('python3')

rustlib = static_library('func', 'func.rs')

executable('tmpbin', 'main.cpp',
  link_with : rustlib)
