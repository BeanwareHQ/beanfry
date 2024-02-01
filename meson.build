project('beanfry', 'c',
  version : '0.1.0',
  default_options : ['warning_level=3'])

sources = [
  'src/main.c',
]

include_directories = [
  './',
  './src'
]

exe = executable('beanfry',
  include_directories: include_directories,
  sources : sources,
  install : true,)

test('basic', exe)
