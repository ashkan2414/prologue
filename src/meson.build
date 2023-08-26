# Copyright(c) 2023-present, Ashkan Ebrahimi
# Distributed under the MIT License (http://opensource.org/licenses/MIT)

ROOT_DIR = meson.source_root()
SRC_DIR = meson.current_source_dir()

sources = []

prologue_main_dir = SRC_DIR / 'prologue'
prologue_main_sources = [
    'prologue.cpp',
]

foreach source : prologue_main_sources
    sources += [prologue_main_dir / source]
endforeach

prologue_core_dir = prologue_main_dir / 'core'
prologue_core_sources = [
    'Windows/OSAdapterWindows.cpp',
    'Linux/OSAdapterLinux.cpp'
]

foreach source : prologue_core_sources
    sources += [prologue_core_dir / source]
endforeach

prologue_lib = library('Prologue', sources,
                       include_directories: include_dir,
                       install_dir : ROOT_DIR / 'bin',
                       install : true)

prologue_dep = declare_dependency(link_with : prologue_lib,
                                  include_directories : include_dir)
