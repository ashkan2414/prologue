# Copyright(c) 2023-present, Ashkan Ebrahimi
# Distributed under the MIT License (http://opensource.org/licenses/MIT)

ROOT_DIR = meson.source_root()

prologue_lib = library('Prologue', 'prologue/prologue.cpp',
                       include_directories: include_dir,
                       install_dir : ROOT_DIR / 'bin',
                       install : true)

prologue_dep = declare_dependency(link_with : prologue_lib,
                                  include_directories : include_dir)
