# Copyright(c) 2023-present, Ashkan Ebrahimi
# Distributed under the MIT License (http://opensource.org/licenses/MIT)

ROOT_DIR = meson.source_root()

dependencies = [ prologue_dep ]

sources = [
    'main.cpp'
]

executable('HelloWorld',
            sources,
            dependencies : dependencies,
            include_directories : include_dir,
            install_dir : ROOT_DIR / 'bin',
            install : true,
            pie: true)
